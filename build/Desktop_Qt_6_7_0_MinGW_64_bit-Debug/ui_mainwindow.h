/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Audio_File;
    QWidget *centralwidget;
    QLabel *label_File_Name;
    QSlider *horizontalSlider_Audio_File_Duration;
    QSlider *horizontalSlider_Volume;
    QPushButton *pushButton_Volume;
    QLabel *label_Elapsed_Duration;
    QLabel *label_Total_Duration;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_SeekBack;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Pause;
    QPushButton *pushButton_SeekForward;
    QMenuBar *menubar;
    QMenu *menuOpen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(492, 356);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(52,51,64);"));
        actionOpen_Audio_File = new QAction(MainWindow);
        actionOpen_Audio_File->setObjectName("actionOpen_Audio_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_File_Name = new QLabel(centralwidget);
        label_File_Name->setObjectName("label_File_Name");
        label_File_Name->setGeometry(QRect(0, 0, 491, 51));
        label_File_Name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color:rgb(255,255,255);\n"
"	border:2px solid rgb(255,255,255);\n"
"}"));
        label_File_Name->setFrameShape(QFrame::Panel);
        label_File_Name->setLineWidth(2);
        horizontalSlider_Audio_File_Duration = new QSlider(centralwidget);
        horizontalSlider_Audio_File_Duration->setObjectName("horizontalSlider_Audio_File_Duration");
        horizontalSlider_Audio_File_Duration->setGeometry(QRect(10, 70, 481, 31));
        horizontalSlider_Audio_File_Duration->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	height:10px;\n"
"	width:460px;\n"
"	background:white;\n"
"	border-radius:5px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"	background:rgb(52,60,64);\n"
"	width:20px;\n"
"	height:20px;\n"
"	margin:-7px -7px;\n"
"	border-radius:10px;\n"
"}"));
        horizontalSlider_Audio_File_Duration->setOrientation(Qt::Horizontal);
        horizontalSlider_Volume = new QSlider(centralwidget);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setGeometry(QRect(90, 250, 401, 31));
        horizontalSlider_Volume->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	height:10px;\n"
"	width:350px;\n"
"	background:white;\n"
"	border-radius:5px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"	background:rgb(52,60,64);\n"
"	width:20px;\n"
"	height:20px;\n"
"	margin:-7px -7px;\n"
"	border-radius:10px;\n"
"}"));
        horizontalSlider_Volume->setOrientation(Qt::Horizontal);
        pushButton_Volume = new QPushButton(centralwidget);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setGeometry(QRect(30, 240, 50, 50));
        pushButton_Volume->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius:16px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover {\n"
"	background-color:rgb(140,140,140);\n"
"}"));
        pushButton_Volume->setIconSize(QSize(30, 30));
        label_Elapsed_Duration = new QLabel(centralwidget);
        label_Elapsed_Duration->setObjectName("label_Elapsed_Duration");
        label_Elapsed_Duration->setGeometry(QRect(20, 110, 51, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        label_Elapsed_Duration->setFont(font);
        label_Elapsed_Duration->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border:rgb(255,255,255);\n"
"}"));
        label_Total_Duration = new QLabel(centralwidget);
        label_Total_Duration->setObjectName("label_Total_Duration");
        label_Total_Duration->setGeometry(QRect(425, 110, 51, 20));
        label_Total_Duration->setFont(font);
        label_Total_Duration->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border:rgb(255,255,255);\n"
"}"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 140, 461, 82));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_SeekBack = new QPushButton(layoutWidget);
        pushButton_SeekBack->setObjectName("pushButton_SeekBack");
        pushButton_SeekBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"	border-radius:24px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:80px;\n"
"	max-width:80px;\n"
"	min-height:80px;\n"
"	max-height:80px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover {\n"
"	background-color:rgb(140,140,140);\n"
"}"));
        pushButton_SeekBack->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_SeekBack);

        pushButton_Stop = new QPushButton(layoutWidget);
        pushButton_Stop->setObjectName("pushButton_Stop");
        pushButton_Stop->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"	border-radius:24px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:80px;\n"
"	max-width:80px;\n"
"	min-height:80px;\n"
"	max-height:80px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover {\n"
"	background-color:rgb(140,140,140);\n"
"}"));
        pushButton_Stop->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_Stop);

        pushButton_Play = new QPushButton(layoutWidget);
        pushButton_Play->setObjectName("pushButton_Play");
        pushButton_Play->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"	border-radius:24px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:80px;\n"
"	max-width:80px;\n"
"	min-height:80px;\n"
"	max-height:80px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover {\n"
"	background-color:rgb(140,140,140);\n"
"}"));
        pushButton_Play->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_Play);

        pushButton_Pause = new QPushButton(layoutWidget);
        pushButton_Pause->setObjectName("pushButton_Pause");
        pushButton_Pause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"	border-radius:24px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:80px;\n"
"	max-width:80px;\n"
"	min-height:80px;\n"
"	max-height:80px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover {\n"
"	background-color:rgb(140,140,140);\n"
"}"));
        pushButton_Pause->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_Pause);

        pushButton_SeekForward = new QPushButton(layoutWidget);
        pushButton_SeekForward->setObjectName("pushButton_SeekForward");
        pushButton_SeekForward->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"	border-radius:24px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:80px;\n"
"	max-width:80px;\n"
"	min-height:80px;\n"
"	max-height:80px;\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover {\n"
"	background-color:rgb(140,140,140);\n"
"}"));
        pushButton_SeekForward->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_SeekForward);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 492, 21));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionOpen_Audio_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_Audio_File->setText(QCoreApplication::translate("MainWindow", "Open Audio File", nullptr));
        label_File_Name->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        pushButton_Volume->setText(QString());
        label_Elapsed_Duration->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_Total_Duration->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pushButton_SeekBack->setText(QString());
        pushButton_Stop->setText(QString());
        pushButton_Play->setText(QString());
        pushButton_Pause->setText(QString());
        pushButton_SeekForward->setText(QString());
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
