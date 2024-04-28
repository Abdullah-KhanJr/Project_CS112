#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), MPlayer(new QMediaPlayer(this)), audioOutput(new QAudioOutput(this)), IS_Muted(false), Mduration(0), isPlaying(false)
{
    ui->setupUi(this);

    MPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    MPlayer->setAudioOutput(audioOutput);

    ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay)); // Set default icon to play
    ui->pushButton_SeekBack->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_SeekForward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    ui->horizontalSlider_Audio_File_Duration->setRange(0, 100);
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_Volume->setValue(50);

    // Connect signals for duration and position changes
    connect(MPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(MPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    connect(ui->horizontalSlider_Audio_File_Duration, &QSlider::valueChanged, this, &MainWindow::on_horizontalSlider_Audio_File_Duration_valueChanged);

    // Play music by default
    MPlayer->play();
    isPlaying = true;
    ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause)); // Set icon to pause since it's playing by default

}

MainWindow::~MainWindow()
{
    delete ui;
    delete MPlayer;
    delete audioOutput;
}

void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration;  // Update total duration
    QString format = (Mduration > 3600) ? "hh:mm:ss" : "mm:ss";  // Formatting

    QTime totalTime(0, 0);  // Initialize time with zero
    totalTime = totalTime.addSecs(duration / 1000);  // Convert milliseconds to seconds

    ui->label_Total_Duration->setText(totalTime.toString(format));  // Set total duration
}

void MainWindow::positionChanged(qint64 position)
{
    if (Mduration > 0) {
        int sliderValue = (position * 100) / Mduration;  // Convert position to percentage
        ui->horizontalSlider_Audio_File_Duration->blockSignals(true);  // Block signals to avoid recursion
        ui->horizontalSlider_Audio_File_Duration->setValue(sliderValue);
        ui->horizontalSlider_Audio_File_Duration->blockSignals(false);  // Unblock signals
    }

    QString format = (Mduration > 3600) ? "hh:mm:ss" : "mm:ss";
    QTime elapsedTime(0, 0);
    elapsedTime = elapsedTime.addSecs(position / 1000);  // Convert to seconds
    ui->label_Elapsed_Duration->setText(elapsedTime.toString(format));
}


void MainWindow::on_pushButton_Volume_clicked()
{
    if (!IS_Muted) {
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        IS_Muted = true;
        audioOutput->setMuted(true);  // This mutes the audio
    } else {
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        IS_Muted = false;
        audioOutput->setMuted(false);  // This unmutes the audio
    }
}

void MainWindow::on_actionOpen_Audio_File_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"",tr("Mp3 Files (*.mp3)"));
    MPlayer->setSource(QUrl(FileName));

    QFileInfo fileinfo(FileName);
    ui->label_File_Name->setText(fileinfo.fileName());


}


void MainWindow::on_pushButton_SeekForward_clicked() {
    int currentSliderValue = ui->horizontalSlider_Audio_File_Duration->value();  // Get current slider value
    int newSliderValue = currentSliderValue + 10;  // Shift forward by 10 percent

    // Ensure new value doesn't exceed 100 (max of slider)
    if (newSliderValue > 100) {
        newSliderValue = 100;
    }

    ui->horizontalSlider_Audio_File_Duration->setValue(newSliderValue);  // Set new slider value

    // Set the new position in the media player
    if (Mduration > 0) {
        qint64 newPosition = (newSliderValue * Mduration) / 100;  // Convert percentage to milliseconds
        MPlayer->setPosition(newPosition);
    }
}


void MainWindow::on_pushButton_Pause_clicked()
{
    MPlayer->pause();
}


void MainWindow::on_pushButton_PlayPause_clicked()
{
    if (isPlaying) {
        MPlayer->pause();  // Pause music
        ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));  // Change icon to play
        isPlaying = false;
    } else {
        MPlayer->play();  // Play music
        ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));  // Change icon to pause
        isPlaying = true;
    }
}


void MainWindow::on_pushButton_Stop_clicked()
{
    MPlayer->stop();
}


void MainWindow::on_pushButton_SeekBack_clicked() {
    int currentSliderValue = ui->horizontalSlider_Audio_File_Duration->value();  // Get current slider value
    int newSliderValue = currentSliderValue - 10;  // Shift backward by 10 percent

    // Ensure new value doesn't go below 0
    if (newSliderValue < 0) {
        newSliderValue = 0;
    }

    ui->horizontalSlider_Audio_File_Duration->setValue(newSliderValue);  // Set new slider value

    // Set the new position in the media player
    if (Mduration > 0) {
        qint64 newPosition = (newSliderValue * Mduration) / 100;  // Convert percentage to milliseconds
        MPlayer->setPosition(newPosition);
    }
}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    // Normalize the slider value to 0.0 - 1.0 for volume control
    audioOutput->setVolume(value / 100.0);
}

void MainWindow::on_horizontalSlider_Audio_File_Duration_valueChanged(int value)
{
    // Convert slider value to position within the media duration
    if (Mduration > 0) {
        qint64 newPosition = (value * Mduration) / 100;  // Convert to milliseconds based on the duration
        MPlayer->setPosition(newPosition);  // Set the new position
    }
}

