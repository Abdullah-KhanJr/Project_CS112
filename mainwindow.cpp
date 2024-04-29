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

    ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->pushButton_SeekBack->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_SeekForward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    ui->horizontalSlider_Audio_File_Duration->setRange(0, 100);
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_Volume->setValue(50);

    connect(MPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(MPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    connect(ui->horizontalSlider_Audio_File_Duration, &QSlider::valueChanged, this, &MainWindow::on_horizontalSlider_Audio_File_Duration_valueChanged);

    MPlayer->play();
    ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete MPlayer;
    delete audioOutput;
}

void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration;
    QString format = (Mduration > 3600) ? "hh:mm:ss" : "mm:ss";

    QTime totalTime(0, 0);
    totalTime = totalTime.addSecs(duration / 1000);

    ui->label_Total_Duration->setText(totalTime.toString(format));
}

void MainWindow::positionChanged(qint64 position)
{
    if (Mduration > 0) {
        int sliderValue = (position * 100) / Mduration;
        ui->horizontalSlider_Audio_File_Duration->blockSignals(true);
        ui->horizontalSlider_Audio_File_Duration->setValue(sliderValue);
        ui->horizontalSlider_Audio_File_Duration->blockSignals(false);
    }

    QString format = (Mduration > 3600) ? "hh:mm:ss" : "mm:ss";
    QTime elapsedTime(0, 0);
    elapsedTime = elapsedTime.addSecs(position / 1000);
    ui->label_Elapsed_Duration->setText(elapsedTime.toString(format));
}


void MainWindow::on_pushButton_Volume_clicked()
{
    if (!IS_Muted) {
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        IS_Muted = true;
        audioOutput->setMuted(true);
    } else {
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        IS_Muted = false;
        audioOutput->setMuted(false);
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
    int currentSliderValue = ui->horizontalSlider_Audio_File_Duration->value();
    int newSliderValue = currentSliderValue + 10;

    if (newSliderValue > 100) {
        newSliderValue = 100;
    }

    ui->horizontalSlider_Audio_File_Duration->setValue(newSliderValue);

    if (Mduration > 0) {
        qint64 newPosition = (newSliderValue * Mduration) / 100;
        MPlayer->setPosition(newPosition);
    }
}


void MainWindow::on_pushButton_Pause_clicked()
{
    MPlayer->pause();
}


void MainWindow::on_pushButton_PlayPause_clicked()
{
    if (!isPlaying) {
        MPlayer->play();
        ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        isPlaying = true;
    } else {
        MPlayer->pause();
        ui->pushButton_PlayPause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        isPlaying = false;
    }
}


void MainWindow::on_pushButton_Stop_clicked()
{
    MPlayer->stop();
}


void MainWindow::on_pushButton_SeekBack_clicked() {
    int currentSliderValue = ui->horizontalSlider_Audio_File_Duration->value();
    int newSliderValue = currentSliderValue - 10;

    if (newSliderValue < 0) {
        newSliderValue = 0;
    }

    ui->horizontalSlider_Audio_File_Duration->setValue(newSliderValue);

    if (Mduration > 0) {
        qint64 newPosition = (newSliderValue * Mduration) / 100;
        MPlayer->setPosition(newPosition);
    }
}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0);
}

void MainWindow::on_horizontalSlider_Audio_File_Duration_valueChanged(int value)
{

    if (Mduration > 0) {
        qint64 newPosition = (value * Mduration) / 100;
        MPlayer->setPosition(newPosition);
    }
}

