/********************************************************************************
** Form generated from reading UI file 'avswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVSWINDOW_H
#define UI_AVSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_avswindow
{
public:
    QDial *dial_2;
    QPushButton *VITRECTOMYBUT;
    QPushButton *IA2BUT;
    QPushButton *IA1BUT;
    QPushButton *DIABUT;
    QLabel *label_2;
    QComboBox *comboBox_4;
    QLabel *lab_date;
    QFrame *line;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *SETTINGS_BUT_4;
    QPushButton *SETTINGS_BUT_2;
    QLabel *lab_time;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *lbloutline;
    QPushButton *butdiaup;
    QPushButton *butdiadown;
    QLineEdit *lineEdit;
    QLabel *lbldiapowtext;
    QLabel *lbldiathermy;
    QWidget *tab_5;
    QLabel *lblia1vacout;
    QLabel *lblia1flowout;
    QPushButton *butia1up;
    QPushButton *butia1down;
    QPushButton *butia1flowup;
    QPushButton *butia1flowdown;
    QLabel *lblvactext;
    QLabel *lblflowtext;
    QLabel *lblcortext;
    QLabel *lblia1vacactual;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QPushButton *butia1mode;
    QWidget *tab_6;
    QLabel *lblia2vacout;
    QLabel *lblia2flowout;
    QPushButton *butia2vacup;
    QPushButton *butia2vacdown;
    QPushButton *butia2flowup;
    QPushButton *butia2flowdown;
    QLabel *lblia2vactext;
    QLabel *lblpolishtext;
    QLabel *lblia2flowtext;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *butia2mode;
    QLabel *lblia2actual;
    QWidget *tab_4;
    QLabel *lblvitvacout;
    QLabel *lblvitflowout;
    QPushButton *butvitvacdown;
    QPushButton *butvitvacup;
    QPushButton *butvitflowup;
    QPushButton *butvitflowdown;
    QLabel *lblvitvactext;
    QLabel *lblvitflow;
    QLabel *lblvitout;
    QPushButton *butvitup;
    QPushButton *butvitdown;
    QLabel *lblvittext;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *vitvacmode;
    QLabel *lblvitvacactual;
    QLabel *lblvitacutal;
    QLabel *label;
    QPushButton *butposition;
    QPushButton *butCI;

    void setupUi(QDialog *avswindow)
    {
        if (avswindow->objectName().isEmpty())
            avswindow->setObjectName(QString::fromUtf8("avswindow"));
        avswindow->resize(1280, 720);
        avswindow->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 78, 102);"));
        dial_2 = new QDial(avswindow);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setEnabled(false);
        dial_2->setGeometry(QRect(520, 300, 221, 161));
        dial_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"image: url(:/images/4img.png);\n"
""));
        dial_2->setSliderPosition(0);
        dial_2->setInvertedAppearance(false);
        dial_2->setInvertedControls(false);
        dial_2->setWrapping(false);
        dial_2->setNotchTarget(0.000000000000000);
        dial_2->setNotchesVisible(true);
        VITRECTOMYBUT = new QPushButton(avswindow);
        VITRECTOMYBUT->setObjectName(QString::fromUtf8("VITRECTOMYBUT"));
        VITRECTOMYBUT->setGeometry(QRect(430, 340, 101, 91));
        VITRECTOMYBUT->setStyleSheet(QString::fromUtf8("QPushButton{font:15pt \"Ubuntu\";\n"
"background-color:transparent;\n"
"	image: url(:/images/glass.png);\n"
"\n"
"\n"
"border:none;font-weight: bold;\n"
"}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}"));
        IA2BUT = new QPushButton(avswindow);
        IA2BUT->setObjectName(QString::fromUtf8("IA2BUT"));
        IA2BUT->setGeometry(QRect(580, 490, 101, 91));
        IA2BUT->setStyleSheet(QString::fromUtf8("QPushButton{font:15pt \"Ubuntu\";\n"
"background-color:transparent;\n"
"	image: url(:/images/glass.png);\n"
"\n"
"\n"
"border:none;font-weight: bold;\n"
"}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}"));
        IA1BUT = new QPushButton(avswindow);
        IA1BUT->setObjectName(QString::fromUtf8("IA1BUT"));
        IA1BUT->setGeometry(QRect(730, 340, 101, 91));
        IA1BUT->setStyleSheet(QString::fromUtf8("QPushButton{font:15pt \"Ubuntu\";\n"
"background-color:transparent;\n"
"	image: url(:/images/glass.png);\n"
"\n"
"\n"
"border:none;font-weight: bold;\n"
"}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}"));
        DIABUT = new QPushButton(avswindow);
        DIABUT->setObjectName(QString::fromUtf8("DIABUT"));
        DIABUT->setGeometry(QRect(580, 180, 101, 91));
        DIABUT->setStyleSheet(QString::fromUtf8("QPushButton{font:15pt \"Ubuntu\";\n"
"background-color:transparent;\n"
"	image: url(:/images/glass.png);\n"
"\n"
"\n"
"border:none;font-weight: bold;\n"
"}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        label_2 = new QLabel(avswindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 160, 451, 451));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:170px;\n"
"image: url(:/images/EYE.png);\n"
"background-color:transparent;\n"
""));
        comboBox_4 = new QComboBox(avswindow);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(60, 10, 331, 51));
        comboBox_4->setStyleSheet(QString::fromUtf8("\n"
"background-color: transparent;\n"
"border:1px solid white;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"\n"
"font:20pt \"Ubuntu\";\n"
"font-weight: bold;"));
        lab_date = new QLabel(avswindow);
        lab_date->setObjectName(QString::fromUtf8("lab_date"));
        lab_date->setGeometry(QRect(390, 10, 271, 51));
        lab_date->setStyleSheet(QString::fromUtf8("\n"
"background-color: transparent;\n"
"border:1px solid white;\n"
"border-radius:10px;\n"
"color: rgb(255, 255, 255);\n"
"font:20pt \"Ubuntu\";\n"
"font-weight: bold;"));
        lab_date->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(avswindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 1280, 3));
        line->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_21 = new QLabel(avswindow);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(380, -10, 81, 91));
        label_21->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"image: url(:/images/calendor.png);\n"
"background-color: transparent;"));
        label_22 = new QLabel(avswindow);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(660, 10, 51, 51));
        label_22->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"image: url(:/images/clock.png);\n"
"background-color: transparent;"));
        SETTINGS_BUT_4 = new QPushButton(avswindow);
        SETTINGS_BUT_4->setObjectName(QString::fromUtf8("SETTINGS_BUT_4"));
        SETTINGS_BUT_4->setGeometry(QRect(10, 10, 51, 51));
        SETTINGS_BUT_4->setStyleSheet(QString::fromUtf8("image: url(:/images/doctor.png);\n"
"background-color: transparent;\n"
"border:none;border-radius:30px;"));
        SETTINGS_BUT_2 = new QPushButton(avswindow);
        SETTINGS_BUT_2->setObjectName(QString::fromUtf8("SETTINGS_BUT_2"));
        SETTINGS_BUT_2->setGeometry(QRect(1200, 4, 61, 61));
        SETTINGS_BUT_2->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/images/settings1.png);\n"
"background-color: rgb(222, 221, 218);\n"
"border:4px solid black;\n"
"border-radius:30px;"));
        lab_time = new QLabel(avswindow);
        lab_time->setObjectName(QString::fromUtf8("lab_time"));
        lab_time->setGeometry(QRect(660, 10, 291, 51));
        lab_time->setStyleSheet(QString::fromUtf8("\n"
"background-color: transparent;\n"
"border:1px solid white;\n"
"border-radius:10px;\n"
"color: rgb(255, 255, 255);\n"
"font:20pt \"Ubuntu\";\n"
"font-weight: bold;"));
        lab_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget = new QTabWidget(avswindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-10, -30, 1291, 771));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 78, 102);"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lbloutline = new QLabel(tab_3);
        lbloutline->setObjectName(QString::fromUtf8("lbloutline"));
        lbloutline->setGeometry(QRect(720, 70, 531, 181));
        lbloutline->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        butdiaup = new QPushButton(tab_3);
        butdiaup->setObjectName(QString::fromUtf8("butdiaup"));
        butdiaup->setGeometry(QRect(880, 140, 91, 61));
        butdiaup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butdiadown = new QPushButton(tab_3);
        butdiadown->setObjectName(QString::fromUtf8("butdiadown"));
        butdiadown->setGeometry(QRect(1080, 140, 91, 61));
        butdiadown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(980, 140, 101, 61));
        lineEdit->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lbldiapowtext = new QLabel(tab_3);
        lbldiapowtext->setObjectName(QString::fromUtf8("lbldiapowtext"));
        lbldiapowtext->setGeometry(QRect(790, 100, 171, 41));
        lbldiapowtext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lbldiathermy = new QLabel(tab_3);
        lbldiathermy->setObjectName(QString::fromUtf8("lbldiathermy"));
        lbldiathermy->setGeometry(QRect(980, 10, 231, 51));
        lbldiathermy->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"border-radius:15px;\n"
"font:20pt;\n"
"font:bold;\n"
"\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        lblia1vacout = new QLabel(tab_5);
        lblia1vacout->setObjectName(QString::fromUtf8("lblia1vacout"));
        lblia1vacout->setGeometry(QRect(30, 70, 531, 181));
        lblia1vacout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        lblia1flowout = new QLabel(tab_5);
        lblia1flowout->setObjectName(QString::fromUtf8("lblia1flowout"));
        lblia1flowout->setGeometry(QRect(30, 510, 531, 181));
        lblia1flowout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        butia1up = new QPushButton(tab_5);
        butia1up->setObjectName(QString::fromUtf8("butia1up"));
        butia1up->setGeometry(QRect(60, 150, 91, 61));
        butia1up->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butia1down = new QPushButton(tab_5);
        butia1down->setObjectName(QString::fromUtf8("butia1down"));
        butia1down->setGeometry(QRect(300, 150, 91, 61));
        butia1down->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butia1flowup = new QPushButton(tab_5);
        butia1flowup->setObjectName(QString::fromUtf8("butia1flowup"));
        butia1flowup->setGeometry(QRect(70, 590, 91, 61));
        butia1flowup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butia1flowdown = new QPushButton(tab_5);
        butia1flowdown->setObjectName(QString::fromUtf8("butia1flowdown"));
        butia1flowdown->setGeometry(QRect(380, 590, 91, 61));
        butia1flowdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        lblvactext = new QLabel(tab_5);
        lblvactext->setObjectName(QString::fromUtf8("lblvactext"));
        lblvactext->setGeometry(QRect(70, 100, 241, 31));
        lblvactext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lblflowtext = new QLabel(tab_5);
        lblflowtext->setObjectName(QString::fromUtf8("lblflowtext"));
        lblflowtext->setGeometry(QRect(80, 540, 401, 31));
        lblflowtext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lblcortext = new QLabel(tab_5);
        lblcortext->setObjectName(QString::fromUtf8("lblcortext"));
        lblcortext->setGeometry(QRect(970, 10, 231, 51));
        lblcortext->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"border-radius:15px;\n"
"font:20pt;\n"
"font:bold;\n"
""));
        lblia1vacactual = new QLabel(tab_5);
        lblia1vacactual->setObjectName(QString::fromUtf8("lblia1vacactual"));
        lblia1vacactual->setGeometry(QRect(420, 120, 91, 91));
        lblia1vacactual->setStyleSheet(QString::fromUtf8("font:30pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border:5px solid black;\n"
"border-radius:40px;font-weight: bold;\n"
"\n"
"\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        lblia1vacactual->setAlignment(Qt::AlignCenter);
        lineEdit_9 = new QLineEdit(tab_5);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(180, 150, 101, 61));
        lineEdit_9->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_9->setAlignment(Qt::AlignCenter);
        lineEdit_10 = new QLineEdit(tab_5);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(220, 590, 101, 61));
        lineEdit_10->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_10->setAlignment(Qt::AlignCenter);
        butia1mode = new QPushButton(tab_5);
        butia1mode->setObjectName(QString::fromUtf8("butia1mode"));
        butia1mode->setGeometry(QRect(290, 60, 161, 81));
        butia1mode->setStyleSheet(QString::fromUtf8("font:15pt \"Ubuntu\";\n"
"\n"
"image: url(:/images/panelbutton.png);\n"
"background-color:transparent;\n"
"border:none;"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        lblia2vacout = new QLabel(tab_6);
        lblia2vacout->setObjectName(QString::fromUtf8("lblia2vacout"));
        lblia2vacout->setGeometry(QRect(30, 70, 531, 181));
        lblia2vacout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        lblia2flowout = new QLabel(tab_6);
        lblia2flowout->setObjectName(QString::fromUtf8("lblia2flowout"));
        lblia2flowout->setGeometry(QRect(30, 510, 531, 181));
        lblia2flowout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        butia2vacup = new QPushButton(tab_6);
        butia2vacup->setObjectName(QString::fromUtf8("butia2vacup"));
        butia2vacup->setGeometry(QRect(60, 150, 91, 61));
        butia2vacup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butia2vacdown = new QPushButton(tab_6);
        butia2vacdown->setObjectName(QString::fromUtf8("butia2vacdown"));
        butia2vacdown->setGeometry(QRect(300, 150, 91, 61));
        butia2vacdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butia2flowup = new QPushButton(tab_6);
        butia2flowup->setObjectName(QString::fromUtf8("butia2flowup"));
        butia2flowup->setGeometry(QRect(70, 590, 91, 61));
        butia2flowup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butia2flowdown = new QPushButton(tab_6);
        butia2flowdown->setObjectName(QString::fromUtf8("butia2flowdown"));
        butia2flowdown->setGeometry(QRect(380, 590, 91, 61));
        butia2flowdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        lblia2vactext = new QLabel(tab_6);
        lblia2vactext->setObjectName(QString::fromUtf8("lblia2vactext"));
        lblia2vactext->setGeometry(QRect(70, 100, 241, 31));
        lblia2vactext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lblpolishtext = new QLabel(tab_6);
        lblpolishtext->setObjectName(QString::fromUtf8("lblpolishtext"));
        lblpolishtext->setGeometry(QRect(970, 10, 231, 51));
        lblpolishtext->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"border-radius:15px;\n"
"font:20pt;\n"
"font:bold;\n"
""));
        lblia2flowtext = new QLabel(tab_6);
        lblia2flowtext->setObjectName(QString::fromUtf8("lblia2flowtext"));
        lblia2flowtext->setGeometry(QRect(80, 540, 401, 31));
        lblia2flowtext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lineEdit_7 = new QLineEdit(tab_6);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(180, 150, 101, 61));
        lineEdit_7->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_7->setAlignment(Qt::AlignCenter);
        lineEdit_8 = new QLineEdit(tab_6);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(220, 590, 101, 61));
        lineEdit_8->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_8->setAlignment(Qt::AlignCenter);
        butia2mode = new QPushButton(tab_6);
        butia2mode->setObjectName(QString::fromUtf8("butia2mode"));
        butia2mode->setGeometry(QRect(290, 60, 161, 81));
        butia2mode->setStyleSheet(QString::fromUtf8("font:15pt \"Ubuntu\";\n"
"\n"
"image: url(:/images/panelbutton.png);\n"
"background-color:transparent;\n"
"border:none;"));
        lblia2actual = new QLabel(tab_6);
        lblia2actual->setObjectName(QString::fromUtf8("lblia2actual"));
        lblia2actual->setGeometry(QRect(420, 120, 91, 91));
        lblia2actual->setStyleSheet(QString::fromUtf8("font:30pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border:5px solid black;\n"
"border-radius:40px;font-weight: bold;\n"
"\n"
"\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        tabWidget->addTab(tab_6, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        lblvitvacout = new QLabel(tab_4);
        lblvitvacout->setObjectName(QString::fromUtf8("lblvitvacout"));
        lblvitvacout->setGeometry(QRect(30, 70, 531, 181));
        lblvitvacout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        lblvitflowout = new QLabel(tab_4);
        lblvitflowout->setObjectName(QString::fromUtf8("lblvitflowout"));
        lblvitflowout->setGeometry(QRect(30, 510, 531, 181));
        lblvitflowout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        butvitvacdown = new QPushButton(tab_4);
        butvitvacdown->setObjectName(QString::fromUtf8("butvitvacdown"));
        butvitvacdown->setGeometry(QRect(300, 150, 91, 61));
        butvitvacdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butvitvacup = new QPushButton(tab_4);
        butvitvacup->setObjectName(QString::fromUtf8("butvitvacup"));
        butvitvacup->setGeometry(QRect(60, 150, 91, 61));
        butvitvacup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butvitflowup = new QPushButton(tab_4);
        butvitflowup->setObjectName(QString::fromUtf8("butvitflowup"));
        butvitflowup->setGeometry(QRect(70, 590, 91, 61));
        butvitflowup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butvitflowdown = new QPushButton(tab_4);
        butvitflowdown->setObjectName(QString::fromUtf8("butvitflowdown"));
        butvitflowdown->setGeometry(QRect(380, 590, 91, 61));
        butvitflowdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        lblvitvactext = new QLabel(tab_4);
        lblvitvactext->setObjectName(QString::fromUtf8("lblvitvactext"));
        lblvitvactext->setGeometry(QRect(70, 100, 241, 31));
        lblvitvactext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lblvitflow = new QLabel(tab_4);
        lblvitflow->setObjectName(QString::fromUtf8("lblvitflow"));
        lblvitflow->setGeometry(QRect(80, 540, 381, 31));
        lblvitflow->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lblvitout = new QLabel(tab_4);
        lblvitout->setObjectName(QString::fromUtf8("lblvitout"));
        lblvitout->setGeometry(QRect(720, 70, 531, 181));
        lblvitout->setStyleSheet(QString::fromUtf8("border-radius:90px;\n"
"\n"
"\n"
"border:4px solid black;\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        butvitup = new QPushButton(tab_4);
        butvitup->setObjectName(QString::fromUtf8("butvitup"));
        butvitup->setGeometry(QRect(880, 140, 91, 61));
        butvitup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/uarrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        butvitdown = new QPushButton(tab_4);
        butvitdown->setObjectName(QString::fromUtf8("butvitdown"));
        butvitdown->setGeometry(QRect(1080, 140, 91, 61));
        butvitdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    image: url(:/images/darrow.png);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        lblvittext = new QLabel(tab_4);
        lblvittext->setObjectName(QString::fromUtf8("lblvittext"));
        lblvittext->setGeometry(QRect(780, 90, 381, 31));
        lblvittext->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"border:none;\n"
""));
        lineEdit_4 = new QLineEdit(tab_4);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 150, 101, 61));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(tab_4);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(980, 140, 101, 61));
        lineEdit_5->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_6 = new QLineEdit(tab_4);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(220, 590, 101, 61));
        lineEdit_6->setStyleSheet(QString::fromUtf8("font:25pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_6->setAlignment(Qt::AlignCenter);
        vitvacmode = new QPushButton(tab_4);
        vitvacmode->setObjectName(QString::fromUtf8("vitvacmode"));
        vitvacmode->setGeometry(QRect(290, 60, 161, 81));
        vitvacmode->setStyleSheet(QString::fromUtf8("font:15pt \"Ubuntu\";\n"
"\n"
"image: url(:/images/panelbutton.png);\n"
"background-color:transparent;\n"
"border:none;"));
        lblvitvacactual = new QLabel(tab_4);
        lblvitvacactual->setObjectName(QString::fromUtf8("lblvitvacactual"));
        lblvitvacactual->setGeometry(QRect(420, 120, 91, 91));
        lblvitvacactual->setStyleSheet(QString::fromUtf8("font:30pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border:5px solid black;\n"
"border-radius:40px;font-weight: bold;\n"
"\n"
"\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        lblvitvacactual->setAlignment(Qt::AlignCenter);
        lblvitacutal = new QLabel(tab_4);
        lblvitacutal->setObjectName(QString::fromUtf8("lblvitacutal"));
        lblvitacutal->setGeometry(QRect(770, 130, 91, 91));
        lblvitacutal->setStyleSheet(QString::fromUtf8("font:30pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border:5px solid black;\n"
"border-radius:40px;font-weight: bold;\n"
"\n"
"\n"
"\n"
"border-left: 10px solid black;\n"
"border-right: 10px solid black;\n"
"border-top: 10px solid black;\n"
"border-bottom: 10px solid black;\n"
"\n"
"border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-right-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"border-bottom-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(12, 29, 54));\n"
"\n"
"\n"
"\n"
""));
        lblvitacutal->setAlignment(Qt::AlignCenter);
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(970, 10, 231, 51));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"border-radius:15px;\n"
"font:20pt;\n"
"font:bold;\n"
""));
        tabWidget->addTab(tab_4, QString());
        lblvitvacout->raise();
        lblvitflowout->raise();
        butvitvacdown->raise();
        butvitvacup->raise();
        butvitflowup->raise();
        lblvitvactext->raise();
        lblvitflow->raise();
        lblvitout->raise();
        butvitup->raise();
        butvitdown->raise();
        lblvittext->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        lineEdit_6->raise();
        vitvacmode->raise();
        lblvitvacactual->raise();
        lblvitacutal->raise();
        label->raise();
        butvitflowdown->raise();
        butposition = new QPushButton(avswindow);
        butposition->setObjectName(QString::fromUtf8("butposition"));
        butposition->setGeometry(QRect(596, 323, 71, 101));
        butposition->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"font:50pt;"));
        butCI = new QPushButton(avswindow);
        butCI->setObjectName(QString::fromUtf8("butCI"));
        butCI->setGeometry(QRect(600, 620, 91, 81));
        butCI->setStyleSheet(QString::fromUtf8("QPushButton{font:20pt \"Ubuntu\";\n"
"color: rgb(224, 27, 36);\n"
"	background-color: rgb(224, 27, 36);\n"
"image: url(:/images/ci.png);\n"
"border:5px solid black;\n"
"border-radius:30px;font-weight: bold;\n"
"}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
""));
        tabWidget->raise();
        label_2->raise();
        SETTINGS_BUT_4->raise();
        label_21->raise();
        IA2BUT->raise();
        line->raise();
        dial_2->raise();
        comboBox_4->raise();
        lab_time->raise();
        label_22->raise();
        lab_date->raise();
        SETTINGS_BUT_2->raise();
        DIABUT->raise();
        IA1BUT->raise();
        VITRECTOMYBUT->raise();
        butposition->raise();
        butCI->raise();

        retranslateUi(avswindow);

        QMetaObject::connectSlotsByName(avswindow);
    } // setupUi

    void retranslateUi(QDialog *avswindow)
    {
        avswindow->setWindowTitle(QCoreApplication::translate("avswindow", "Dialog", nullptr));
        VITRECTOMYBUT->setText(QCoreApplication::translate("avswindow", "VIT", nullptr));
        IA2BUT->setText(QCoreApplication::translate("avswindow", "I/A 2", nullptr));
        IA1BUT->setText(QCoreApplication::translate("avswindow", "I/A 1", nullptr));
        DIABUT->setText(QCoreApplication::translate("avswindow", "DIA", nullptr));
        label_2->setText(QString());
        comboBox_4->setItemText(0, QCoreApplication::translate("avswindow", "Surgeon 1", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("avswindow", "Surgeon 2", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("avswindow", "Surgeon 3", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("avswindow", "Surgeon 4", nullptr));
        comboBox_4->setItemText(4, QCoreApplication::translate("avswindow", "Surgeon 5", nullptr));

        lab_date->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        SETTINGS_BUT_4->setText(QString());
        SETTINGS_BUT_2->setText(QString());
        lab_time->setText(QString());
        lbloutline->setText(QString());
        butdiaup->setText(QString());
        butdiadown->setText(QString());
        lineEdit->setText(QCoreApplication::translate("avswindow", "100", nullptr));
        lbldiapowtext->setText(QCoreApplication::translate("avswindow", "Power(%)", nullptr));
        lbldiathermy->setText(QCoreApplication::translate("avswindow", "Diathermy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("avswindow", "Tab 1", nullptr));
        lblia1vacout->setText(QString());
        lblia1flowout->setText(QString());
        butia1up->setText(QString());
        butia1down->setText(QString());
        butia1flowup->setText(QString());
        butia1flowdown->setText(QString());
        lblvactext->setText(QCoreApplication::translate("avswindow", "Vaccum(mmHg)", nullptr));
        lblflowtext->setText(QCoreApplication::translate("avswindow", "Flow Rate", nullptr));
        lblcortext->setText(QCoreApplication::translate("avswindow", "Cortex", nullptr));
        lblia1vacactual->setText(QCoreApplication::translate("avswindow", "0", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("avswindow", "500", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("avswindow", "40", nullptr));
        butia1mode->setText(QCoreApplication::translate("avswindow", "SURGEON", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("avswindow", "Page", nullptr));
        lblia2vacout->setText(QString());
        lblia2flowout->setText(QString());
        butia2vacup->setText(QString());
        butia2vacdown->setText(QString());
        butia2flowup->setText(QString());
        butia2flowdown->setText(QString());
        lblia2vactext->setText(QCoreApplication::translate("avswindow", "Vaccum(mmHg)", nullptr));
        lblpolishtext->setText(QCoreApplication::translate("avswindow", "Polish", nullptr));
        lblia2flowtext->setText(QCoreApplication::translate("avswindow", "Flow Rate", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("avswindow", "500", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("avswindow", "40", nullptr));
        butia2mode->setText(QCoreApplication::translate("avswindow", "SURGEON", nullptr));
        lblia2actual->setText(QCoreApplication::translate("avswindow", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("avswindow", "Page", nullptr));
        lblvitvacout->setText(QString());
        lblvitflowout->setText(QString());
        butvitvacdown->setText(QString());
        butvitvacup->setText(QString());
        butvitflowup->setText(QString());
        butvitflowdown->setText(QString());
        lblvitvactext->setText(QCoreApplication::translate("avswindow", "Vaccum(mmHg)", nullptr));
        lblvitflow->setText(QCoreApplication::translate("avswindow", "FlowRate", nullptr));
        lblvitout->setText(QString());
        butvitup->setText(QString());
        butvitdown->setText(QString());
        lblvittext->setText(QCoreApplication::translate("avswindow", "Cut Rate(CPM)", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("avswindow", "500", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("avswindow", "2500", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("avswindow", "40", nullptr));
        vitvacmode->setText(QCoreApplication::translate("avswindow", "SURGEON", nullptr));
        lblvitvacactual->setText(QCoreApplication::translate("avswindow", "0", nullptr));
        lblvitacutal->setText(QCoreApplication::translate("avswindow", "0", nullptr));
        label->setText(QCoreApplication::translate("avswindow", "Vitrectomy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("avswindow", "Tab 2", nullptr));
        butposition->setText(QCoreApplication::translate("avswindow", "0", nullptr));
        butCI->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class avswindow: public Ui_avswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVSWINDOW_H
