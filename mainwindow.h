#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtCore>
#include <QtWidgets>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QSlider>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);

    void on_pushButton_Volume_clicked();
    void on_actionOpen_Audio_File_triggered();

    void on_pushButton_SeekForward_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_PlayPause_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_SeekBack_clicked();

    void on_horizontalSlider_Volume_valueChanged(int Vvalue);

    void on_horizontalSlider_Audio_File_Duration_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    bool IS_Muted = false;
    QMediaPlayer *MPlayer;
    QAudioOutput *audioOutput;
    qint64 Mduration;

    bool isPlaying = false;
};
#endif
