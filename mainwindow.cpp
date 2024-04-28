#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), MPlayer(new QMediaPlayer(this)), audioOutput(new QAudioOutput(this))
{
    ui->setupUi(this);

    MPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    MPlayer->setAudioOutput(audioOutput);

    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_SeekBack->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_SeekForward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_Volume->setValue(50);

    connect(MPlayer, &QMediaPlayer::durationChanged,this, &MainWindow::durationChanged);
    // connect(MPlayer, &QMediaPlayer::positionChanged,this, &MainWindow::positionChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete MPlayer;
    delete audioOutput;
}

void MainWindow::durationChanged(qint64 duration)
{
    QString timestr;
    if (duration || Mduration) {
        QTime CurrentTime((duration/3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
        QTime totalTime((Mduration/3600) % 60, (Mduration / 60) % 60, Mduration % 60, (Mduration * 1000) % 1000);
        QString format = "mm:ss";
        if (Mduration > 3600)
            format = "hh:mm:ss";
        ui->label_Elapsed_Duration->setText(CurrentTime.toString(format));
        ui->label_Total_Duration->setText(totalTime.toString(format));
    }
}

// void MainWindow::positionChanged(qint64 progress)
// {

// }

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


void MainWindow::on_pushButton_SeekForward_clicked()
{

}


void MainWindow::on_pushButton_Pause_clicked()
{
    MPlayer->pause();
}


void MainWindow::on_pushButton_Play_clicked()
{
    MPlayer->play();
}


void MainWindow::on_pushButton_Stop_clicked()
{
    MPlayer->stop();
}


void MainWindow::on_pushButton_SeekBack_clicked()
{

}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    // Normalize the slider value to 0.0 - 1.0 for volume control
    audioOutput->setVolume(value / 100.0);
}
