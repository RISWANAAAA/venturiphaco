/********************************************************************************
** Form generated from reading UI file 'doctor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOR_H
#define UI_DOCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctor
{
public:
    QLabel *Mode;
    QComboBox *BottomRFoot;
    QLabel *BottomRight;
    QPushButton *BackBut;
    QLabel *BottomLeft;
    QComboBox *LeftFoot;
    QLabel *Right;
    QPushButton *VitBut;
    QLabel *circle;
    QLabel *FootPedalSettings;
    QPushButton *IABut;
    QLabel *Select;
    QComboBox *RightFoot;
    QComboBox *BottomLFoot;
    QPushButton *PhacoBut;
    QLabel *Surgeon;
    QLabel *Left;
    QComboBox *SelectSurgeon;
    QTabWidget *tabWidget;
    QWidget *Diathermy;
    QLineEdit *lineEdit_6;
    QLabel *DiaPowMax;
    QPushButton *SaveDiaBut;
    QWidget *tab;
    QWidget *tab_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QComboBox *VacModeCom_phaco;
    QLabel *AspMax_phaco;
    QComboBox *PowMethodCom_phaco;
    QComboBox *PowModeCom_phaco;
    QLabel *VacMax_phaco;
    QLabel *PowMax_phaco;
    QLabel *PowMode_phaco;
    QLabel *PowMethod_phaco;
    QLabel *VacMode_phaco;
    QPushButton *EpinBut_phaco;
    QPushButton *QuadBut_phaco;
    QPushButton *ChopBut_phaco;
    QPushButton *ScupltBut_phaco;
    QPushButton *SavePhacoBut_phaco;
    QLabel *AspMax_phaco_2;
    QLabel *AspMax_phaco_3;
    QLabel *AspMax_phaco_4;
    QWidget *tab_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLabel *AspMax_ia;
    QLabel *VacMax_ia;
    QLabel *AspMode1_ia;
    QLabel *VacMode2_ia;
    QLabel *AspMax2_ia;
    QLabel *VacMax_ia_2;
    QLabel *AspMode3_ia;
    QLabel *VacMode3_ia;
    QComboBox *AspMode_iacom;
    QComboBox *VacMode1_iacom;
    QComboBox *VacMode2_iacom;
    QLabel *Cortex;
    QComboBox *AspMode2_iacom;
    QLabel *Piolish;
    QPushButton *IASaveBut;
    QLabel *AspMax_phaco_5;
    QLabel *AspMax_phaco_6;
    QLabel *AspMax_phaco_7;
    QLabel *AspMax_phaco_8;
    QWidget *tab_4;
    QLineEdit *lineEdit;
    QLabel *CutMax_vit;
    QComboBox *CutMode_vitCom;
    QLabel *CutMode_vit;
    QLineEdit *lineEdit_19;
    QLabel *VacMax_vit;
    QComboBox *VacMode_VitCom;
    QLabel *VacMode_vit;
    QLabel *AspMax_vit;
    QLineEdit *lineEdit_20;
    QLabel *CutRate;
    QLabel *Vaccum;
    QPushButton *savevitbut;
    QWidget *tab_5;
    QPushButton *DiaBut;

    void setupUi(QDialog *doctor)
    {
        if (doctor->objectName().isEmpty())
            doctor->setObjectName(QString::fromUtf8("doctor"));
        doctor->resize(1280, 720);
        doctor->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        Mode = new QLabel(doctor);
        Mode->setObjectName(QString::fromUtf8("Mode"));
        Mode->setGeometry(QRect(160, 250, 81, 41));
        Mode->setStyleSheet(QString::fromUtf8("font:bold;\n"
"background-color:transparent;"));
        BottomRFoot = new QComboBox(doctor);
        BottomRFoot->addItem(QString());
        BottomRFoot->addItem(QString());
        BottomRFoot->addItem(QString());
        BottomRFoot->addItem(QString());
        BottomRFoot->addItem(QString());
        BottomRFoot->addItem(QString());
        BottomRFoot->setObjectName(QString::fromUtf8("BottomRFoot"));
        BottomRFoot->setGeometry(QRect(250, 650, 191, 41));
        BottomRFoot->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        BottomRight = new QLabel(doctor);
        BottomRight->setObjectName(QString::fromUtf8("BottomRight"));
        BottomRight->setGeometry(QRect(20, 650, 281, 31));
        BottomRight->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"background-color:transparent;"));
        BackBut = new QPushButton(doctor);
        BackBut->setObjectName(QString::fromUtf8("BackBut"));
        BackBut->setGeometry(QRect(-10, 0, 141, 91));
        BackBut->setStyleSheet(QString::fromUtf8("image: url(:/images/backbutton.png);\n"
"border:none;\n"
"background-color:transparent;"));
        BottomLeft = new QLabel(doctor);
        BottomLeft->setObjectName(QString::fromUtf8("BottomLeft"));
        BottomLeft->setGeometry(QRect(20, 590, 291, 31));
        BottomLeft->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"background-color:transparent;"));
        LeftFoot = new QComboBox(doctor);
        LeftFoot->addItem(QString());
        LeftFoot->addItem(QString());
        LeftFoot->addItem(QString());
        LeftFoot->addItem(QString());
        LeftFoot->addItem(QString());
        LeftFoot->addItem(QString());
        LeftFoot->setObjectName(QString::fromUtf8("LeftFoot"));
        LeftFoot->setGeometry(QRect(250, 470, 191, 41));
        LeftFoot->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font:20pt \"Ubuntu\";\n"
"border-radius:20px;\n"
""));
        Right = new QLabel(doctor);
        Right->setObjectName(QString::fromUtf8("Right"));
        Right->setGeometry(QRect(20, 530, 141, 31));
        Right->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"background-color:transparent;"));
        VitBut = new QPushButton(doctor);
        VitBut->setObjectName(QString::fromUtf8("VitBut"));
        VitBut->setGeometry(QRect(140, 320, 101, 81));
        VitBut->setStyleSheet(QString::fromUtf8("border-radius: 40px;\n"
"width:10px;\n"
"height:10px;\n"
"background-color:transparent;\n"
"border:none;\n"
"font:bold;\n"
"border:3px solid black;"));
        circle = new QLabel(doctor);
        circle->setObjectName(QString::fromUtf8("circle"));
        circle->setGeometry(QRect(50, 150, 271, 251));
        circle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:3px solid black;\n"
"border-radius:120px;"));
        FootPedalSettings = new QLabel(doctor);
        FootPedalSettings->setObjectName(QString::fromUtf8("FootPedalSettings"));
        FootPedalSettings->setGeometry(QRect(70, 410, 281, 41));
        FootPedalSettings->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"background-color:transparent;\n"
"font:bold;"));
        IABut = new QPushButton(doctor);
        IABut->setObjectName(QString::fromUtf8("IABut"));
        IABut->setGeometry(QRect(50, 230, 91, 81));
        IABut->setStyleSheet(QString::fromUtf8("border-radius: 40px;\n"
"width:10px;\n"
"height:10px;\n"
"background-color:transparent;\n"
"border:none;\n"
"font:bold;border:3px solid black;"));
        Select = new QLabel(doctor);
        Select->setObjectName(QString::fromUtf8("Select"));
        Select->setGeometry(QRect(200, 40, 191, 17));
        Select->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu Condensed\";"));
        RightFoot = new QComboBox(doctor);
        RightFoot->addItem(QString());
        RightFoot->addItem(QString());
        RightFoot->addItem(QString());
        RightFoot->addItem(QString());
        RightFoot->addItem(QString());
        RightFoot->addItem(QString());
        RightFoot->setObjectName(QString::fromUtf8("RightFoot"));
        RightFoot->setGeometry(QRect(250, 530, 191, 41));
        RightFoot->setStyleSheet(QString::fromUtf8("border-radius:20px;font:20pt \"Ubuntu\";\n"
"background-color: rgb(222, 221, 218);"));
        BottomLFoot = new QComboBox(doctor);
        BottomLFoot->addItem(QString());
        BottomLFoot->addItem(QString());
        BottomLFoot->addItem(QString());
        BottomLFoot->addItem(QString());
        BottomLFoot->addItem(QString());
        BottomLFoot->addItem(QString());
        BottomLFoot->setObjectName(QString::fromUtf8("BottomLFoot"));
        BottomLFoot->setGeometry(QRect(250, 590, 191, 41));
        BottomLFoot->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);color: rgb(0, 0, 0);border-radius:20px;\n"
"font:20pt \"Ubuntu\";"));
        PhacoBut = new QPushButton(doctor);
        PhacoBut->setObjectName(QString::fromUtf8("PhacoBut"));
        PhacoBut->setGeometry(QRect(230, 230, 91, 81));
        PhacoBut->setStyleSheet(QString::fromUtf8("border-radius: 40px;\n"
"width:10px;\n"
"height:10px;\n"
"background-color:transparent;\n"
"border:none;\n"
"font:bold;border:3px solid black;"));
        Surgeon = new QLabel(doctor);
        Surgeon->setObjectName(QString::fromUtf8("Surgeon"));
        Surgeon->setGeometry(QRect(110, 50, 81, 91));
        Surgeon->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/images/doctor.png);\n"
"background-color:transparent;\n"
"border-radius:20px;\n"
"border:2px solid black;"));
        Left = new QLabel(doctor);
        Left->setObjectName(QString::fromUtf8("Left"));
        Left->setGeometry(QRect(20, 470, 71, 31));
        Left->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"background-color:transparent;"));
        SelectSurgeon = new QComboBox(doctor);
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->addItem(QString());
        SelectSurgeon->setObjectName(QString::fromUtf8("SelectSurgeon"));
        SelectSurgeon->setGeometry(QRect(190, 70, 191, 51));
        SelectSurgeon->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"\n"
"font:20pt \"Ubuntu\";\n"
"font:bold;"));
        tabWidget = new QTabWidget(doctor);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(470, 10, 811, 711));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        Diathermy = new QWidget();
        Diathermy->setObjectName(QString::fromUtf8("Diathermy"));
        Diathermy->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        lineEdit_6 = new QLineEdit(Diathermy);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(410, 180, 241, 71));
        lineEdit_6->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        DiaPowMax = new QLabel(Diathermy);
        DiaPowMax->setObjectName(QString::fromUtf8("DiaPowMax"));
        DiaPowMax->setGeometry(QRect(70, 190, 281, 51));
        DiaPowMax->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        SaveDiaBut = new QPushButton(Diathermy);
        SaveDiaBut->setObjectName(QString::fromUtf8("SaveDiaBut"));
        SaveDiaBut->setGeometry(QRect(330, 360, 101, 41));
        SaveDiaBut->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(222, 221, 218);\n"
"border-radius:20px;"));
        tabWidget->addTab(Diathermy, QString());
        DiaPowMax->raise();
        lineEdit_6->raise();
        SaveDiaBut->raise();
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(440, 110, 141, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(440, 190, 141, 51));
        lineEdit_3->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(440, 280, 141, 51));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        VacModeCom_phaco = new QComboBox(tab_2);
        VacModeCom_phaco->addItem(QString());
        VacModeCom_phaco->addItem(QString());
        VacModeCom_phaco->setObjectName(QString::fromUtf8("VacModeCom_phaco"));
        VacModeCom_phaco->setGeometry(QRect(430, 380, 231, 41));
        VacModeCom_phaco->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);color: rgb(0, 0, 0);border-radius:20px;\n"
"font:20pt \"Ubuntu\";"));
        AspMax_phaco = new QLabel(tab_2);
        AspMax_phaco->setObjectName(QString::fromUtf8("AspMax_phaco"));
        AspMax_phaco->setGeometry(QRect(140, 120, 251, 31));
        AspMax_phaco->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        PowMethodCom_phaco = new QComboBox(tab_2);
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->addItem(QString());
        PowMethodCom_phaco->setObjectName(QString::fromUtf8("PowMethodCom_phaco"));
        PowMethodCom_phaco->setGeometry(QRect(430, 440, 231, 41));
        PowMethodCom_phaco->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        PowModeCom_phaco = new QComboBox(tab_2);
        PowModeCom_phaco->addItem(QString());
        PowModeCom_phaco->addItem(QString());
        PowModeCom_phaco->setObjectName(QString::fromUtf8("PowModeCom_phaco"));
        PowModeCom_phaco->setGeometry(QRect(430, 500, 231, 41));
        PowModeCom_phaco->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        VacMax_phaco = new QLabel(tab_2);
        VacMax_phaco->setObjectName(QString::fromUtf8("VacMax_phaco"));
        VacMax_phaco->setGeometry(QRect(150, 200, 291, 31));
        VacMax_phaco->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        PowMax_phaco = new QLabel(tab_2);
        PowMax_phaco->setObjectName(QString::fromUtf8("PowMax_phaco"));
        PowMax_phaco->setGeometry(QRect(150, 290, 251, 31));
        PowMax_phaco->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        PowMode_phaco = new QLabel(tab_2);
        PowMode_phaco->setObjectName(QString::fromUtf8("PowMode_phaco"));
        PowMode_phaco->setGeometry(QRect(150, 500, 671, 31));
        PowMode_phaco->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        PowMethod_phaco = new QLabel(tab_2);
        PowMethod_phaco->setObjectName(QString::fromUtf8("PowMethod_phaco"));
        PowMethod_phaco->setGeometry(QRect(150, 440, 351, 31));
        PowMethod_phaco->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        VacMode_phaco = new QLabel(tab_2);
        VacMode_phaco->setObjectName(QString::fromUtf8("VacMode_phaco"));
        VacMode_phaco->setGeometry(QRect(150, 380, 391, 31));
        VacMode_phaco->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        EpinBut_phaco = new QPushButton(tab_2);
        EpinBut_phaco->setObjectName(QString::fromUtf8("EpinBut_phaco"));
        EpinBut_phaco->setGeometry(QRect(0, 40, 211, 25));
        EpinBut_phaco->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 171, 191);"));
        QuadBut_phaco = new QPushButton(tab_2);
        QuadBut_phaco->setObjectName(QString::fromUtf8("QuadBut_phaco"));
        QuadBut_phaco->setGeometry(QRect(210, 40, 221, 25));
        QuadBut_phaco->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 171, 191);"));
        ChopBut_phaco = new QPushButton(tab_2);
        ChopBut_phaco->setObjectName(QString::fromUtf8("ChopBut_phaco"));
        ChopBut_phaco->setGeometry(QRect(430, 40, 171, 25));
        ChopBut_phaco->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 171, 191);"));
        ScupltBut_phaco = new QPushButton(tab_2);
        ScupltBut_phaco->setObjectName(QString::fromUtf8("ScupltBut_phaco"));
        ScupltBut_phaco->setGeometry(QRect(600, 40, 211, 25));
        ScupltBut_phaco->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 171, 191);"));
        SavePhacoBut_phaco = new QPushButton(tab_2);
        SavePhacoBut_phaco->setObjectName(QString::fromUtf8("SavePhacoBut_phaco"));
        SavePhacoBut_phaco->setGeometry(QRect(370, 610, 111, 41));
        SavePhacoBut_phaco->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        AspMax_phaco_2 = new QLabel(tab_2);
        AspMax_phaco_2->setObjectName(QString::fromUtf8("AspMax_phaco_2"));
        AspMax_phaco_2->setGeometry(QRect(640, 120, 251, 31));
        AspMax_phaco_2->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax_phaco_3 = new QLabel(tab_2);
        AspMax_phaco_3->setObjectName(QString::fromUtf8("AspMax_phaco_3"));
        AspMax_phaco_3->setGeometry(QRect(630, 200, 251, 31));
        AspMax_phaco_3->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax_phaco_4 = new QLabel(tab_2);
        AspMax_phaco_4->setObjectName(QString::fromUtf8("AspMax_phaco_4"));
        AspMax_phaco_4->setGeometry(QRect(630, 290, 251, 31));
        AspMax_phaco_4->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        tabWidget->addTab(tab_2, QString());
        EpinBut_phaco->raise();
        QuadBut_phaco->raise();
        ChopBut_phaco->raise();
        ScupltBut_phaco->raise();
        AspMax_phaco->raise();
        SavePhacoBut_phaco->raise();
        VacMax_phaco->raise();
        PowModeCom_phaco->raise();
        PowMethodCom_phaco->raise();
        PowMethod_phaco->raise();
        VacModeCom_phaco->raise();
        PowMax_phaco->raise();
        PowMode_phaco->raise();
        VacMode_phaco->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        AspMax_phaco_2->raise();
        AspMax_phaco_3->raise();
        AspMax_phaco_4->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(460, 40, 151, 41));
        lineEdit_5->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        lineEdit_7 = new QLineEdit(tab_3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(460, 100, 151, 41));
        lineEdit_7->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(480, 360, 151, 41));
        lineEdit_11->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        lineEdit_12 = new QLineEdit(tab_3);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(480, 300, 151, 41));
        lineEdit_12->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        AspMax_ia = new QLabel(tab_3);
        AspMax_ia->setObjectName(QString::fromUtf8("AspMax_ia"));
        AspMax_ia->setGeometry(QRect(80, 50, 281, 31));
        AspMax_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        VacMax_ia = new QLabel(tab_3);
        VacMax_ia->setObjectName(QString::fromUtf8("VacMax_ia"));
        VacMax_ia->setGeometry(QRect(80, 110, 371, 31));
        VacMax_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMode1_ia = new QLabel(tab_3);
        AspMode1_ia->setObjectName(QString::fromUtf8("AspMode1_ia"));
        AspMode1_ia->setGeometry(QRect(80, 170, 371, 51));
        AspMode1_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        VacMode2_ia = new QLabel(tab_3);
        VacMode2_ia->setObjectName(QString::fromUtf8("VacMode2_ia"));
        VacMode2_ia->setGeometry(QRect(80, 230, 361, 41));
        VacMode2_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax2_ia = new QLabel(tab_3);
        AspMax2_ia->setObjectName(QString::fromUtf8("AspMax2_ia"));
        AspMax2_ia->setGeometry(QRect(80, 300, 411, 51));
        AspMax2_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        VacMax_ia_2 = new QLabel(tab_3);
        VacMax_ia_2->setObjectName(QString::fromUtf8("VacMax_ia_2"));
        VacMax_ia_2->setGeometry(QRect(80, 360, 381, 41));
        VacMax_ia_2->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMode3_ia = new QLabel(tab_3);
        AspMode3_ia->setObjectName(QString::fromUtf8("AspMode3_ia"));
        AspMode3_ia->setGeometry(QRect(80, 440, 361, 31));
        AspMode3_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        VacMode3_ia = new QLabel(tab_3);
        VacMode3_ia->setObjectName(QString::fromUtf8("VacMode3_ia"));
        VacMode3_ia->setGeometry(QRect(80, 510, 381, 31));
        VacMode3_ia->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMode_iacom = new QComboBox(tab_3);
        AspMode_iacom->addItem(QString());
        AspMode_iacom->addItem(QString());
        AspMode_iacom->setObjectName(QString::fromUtf8("AspMode_iacom"));
        AspMode_iacom->setGeometry(QRect(460, 170, 171, 41));
        AspMode_iacom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        VacMode1_iacom = new QComboBox(tab_3);
        VacMode1_iacom->addItem(QString());
        VacMode1_iacom->addItem(QString());
        VacMode1_iacom->setObjectName(QString::fromUtf8("VacMode1_iacom"));
        VacMode1_iacom->setGeometry(QRect(460, 230, 171, 41));
        VacMode1_iacom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        VacMode2_iacom = new QComboBox(tab_3);
        VacMode2_iacom->addItem(QString());
        VacMode2_iacom->addItem(QString());
        VacMode2_iacom->setObjectName(QString::fromUtf8("VacMode2_iacom"));
        VacMode2_iacom->setGeometry(QRect(480, 500, 171, 41));
        VacMode2_iacom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        Cortex = new QLabel(tab_3);
        Cortex->setObjectName(QString::fromUtf8("Cortex"));
        Cortex->setGeometry(QRect(10, 10, 161, 31));
        Cortex->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"background-color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:15px;"));
        AspMode2_iacom = new QComboBox(tab_3);
        AspMode2_iacom->addItem(QString());
        AspMode2_iacom->addItem(QString());
        AspMode2_iacom->setObjectName(QString::fromUtf8("AspMode2_iacom"));
        AspMode2_iacom->setGeometry(QRect(480, 430, 171, 41));
        AspMode2_iacom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        Piolish = new QLabel(tab_3);
        Piolish->setObjectName(QString::fromUtf8("Piolish"));
        Piolish->setGeometry(QRect(10, 270, 121, 31));
        Piolish->setStyleSheet(QString::fromUtf8("border-radius:15px;font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"background-color: rgb(255, 255, 255);"));
        IASaveBut = new QPushButton(tab_3);
        IASaveBut->setObjectName(QString::fromUtf8("IASaveBut"));
        IASaveBut->setGeometry(QRect(340, 580, 101, 41));
        IASaveBut->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        AspMax_phaco_5 = new QLabel(tab_3);
        AspMax_phaco_5->setObjectName(QString::fromUtf8("AspMax_phaco_5"));
        AspMax_phaco_5->setGeometry(QRect(660, 100, 251, 31));
        AspMax_phaco_5->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax_phaco_6 = new QLabel(tab_3);
        AspMax_phaco_6->setObjectName(QString::fromUtf8("AspMax_phaco_6"));
        AspMax_phaco_6->setGeometry(QRect(660, 40, 251, 31));
        AspMax_phaco_6->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax_phaco_7 = new QLabel(tab_3);
        AspMax_phaco_7->setObjectName(QString::fromUtf8("AspMax_phaco_7"));
        AspMax_phaco_7->setGeometry(QRect(660, 290, 251, 31));
        AspMax_phaco_7->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax_phaco_8 = new QLabel(tab_3);
        AspMax_phaco_8->setObjectName(QString::fromUtf8("AspMax_phaco_8"));
        AspMax_phaco_8->setGeometry(QRect(660, 350, 251, 31));
        AspMax_phaco_8->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        tabWidget->addTab(tab_3, QString());
        AspMax_ia->raise();
        VacMax_ia->raise();
        Cortex->raise();
        Piolish->raise();
        IASaveBut->raise();
        VacMax_ia_2->raise();
        VacMode3_ia->raise();
        AspMode3_ia->raise();
        AspMode1_ia->raise();
        AspMax2_ia->raise();
        VacMode2_ia->raise();
        lineEdit_11->raise();
        lineEdit_12->raise();
        lineEdit_5->raise();
        lineEdit_7->raise();
        VacMode1_iacom->raise();
        AspMode2_iacom->raise();
        VacMode2_iacom->raise();
        AspMode_iacom->raise();
        AspMax_phaco_5->raise();
        AspMax_phaco_6->raise();
        AspMax_phaco_7->raise();
        AspMax_phaco_8->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tab_4->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        lineEdit = new QLineEdit(tab_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(500, 80, 151, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        CutMax_vit = new QLabel(tab_4);
        CutMax_vit->setObjectName(QString::fromUtf8("CutMax_vit"));
        CutMax_vit->setGeometry(QRect(170, 100, 281, 31));
        CutMax_vit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        CutMode_vitCom = new QComboBox(tab_4);
        CutMode_vitCom->addItem(QString());
        CutMode_vitCom->addItem(QString());
        CutMode_vitCom->setObjectName(QString::fromUtf8("CutMode_vitCom"));
        CutMode_vitCom->setGeometry(QRect(490, 180, 191, 41));
        CutMode_vitCom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        CutMode_vit = new QLabel(tab_4);
        CutMode_vit->setObjectName(QString::fromUtf8("CutMode_vit"));
        CutMode_vit->setGeometry(QRect(170, 170, 251, 31));
        CutMode_vit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        lineEdit_19 = new QLineEdit(tab_4);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(490, 280, 151, 51));
        lineEdit_19->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        VacMax_vit = new QLabel(tab_4);
        VacMax_vit->setObjectName(QString::fromUtf8("VacMax_vit"));
        VacMax_vit->setGeometry(QRect(160, 290, 271, 31));
        VacMax_vit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        VacMode_VitCom = new QComboBox(tab_4);
        VacMode_VitCom->addItem(QString());
        VacMode_VitCom->addItem(QString());
        VacMode_VitCom->setObjectName(QString::fromUtf8("VacMode_VitCom"));
        VacMode_VitCom->setGeometry(QRect(490, 400, 191, 41));
        VacMode_VitCom->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border-radius:20px;\n"
"background-color: rgb(222, 221, 218);font:20pt \"Ubuntu\";"));
        VacMode_vit = new QLabel(tab_4);
        VacMode_vit->setObjectName(QString::fromUtf8("VacMode_vit"));
        VacMode_vit->setGeometry(QRect(160, 390, 271, 31));
        VacMode_vit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        AspMax_vit = new QLabel(tab_4);
        AspMax_vit->setObjectName(QString::fromUtf8("AspMax_vit"));
        AspMax_vit->setGeometry(QRect(150, 490, 361, 31));
        AspMax_vit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 15pt \"Ubuntu Condensed\";\n"
"font:bold;"));
        lineEdit_20 = new QLineEdit(tab_4);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(500, 480, 151, 51));
        lineEdit_20->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        CutRate = new QLabel(tab_4);
        CutRate->setObjectName(QString::fromUtf8("CutRate"));
        CutRate->setGeometry(QRect(10, 20, 171, 41));
        CutRate->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";border-radius:15px;font:bold;\n"
"background-color: rgb(255, 255, 255);"));
        Vaccum = new QLabel(tab_4);
        Vaccum->setObjectName(QString::fromUtf8("Vaccum"));
        Vaccum->setGeometry(QRect(10, 220, 171, 41));
        Vaccum->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu Condensed\";\n"
"font:bold;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:20px;"));
        savevitbut = new QPushButton(tab_4);
        savevitbut->setObjectName(QString::fromUtf8("savevitbut"));
        savevitbut->setGeometry(QRect(300, 600, 111, 41));
        savevitbut->setStyleSheet(QString::fromUtf8("font:20pt \"Ubuntu\";\n"
"background-color: rgb(255,255,255);\n"
"border-radius:20px;"));
        tabWidget->addTab(tab_4, QString());
        CutMode_vit->raise();
        VacMode_VitCom->raise();
        CutMax_vit->raise();
        VacMax_vit->raise();
        CutRate->raise();
        AspMax_vit->raise();
        VacMode_vit->raise();
        Vaccum->raise();
        CutMode_vitCom->raise();
        lineEdit->raise();
        lineEdit_19->raise();
        lineEdit_20->raise();
        savevitbut->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        DiaBut = new QPushButton(doctor);
        DiaBut->setObjectName(QString::fromUtf8("DiaBut"));
        DiaBut->setGeometry(QRect(140, 150, 91, 81));
        DiaBut->setStyleSheet(QString::fromUtf8("border-radius: 40px;\n"
"width:10px;\n"
"height:10px;\n"
"background-color:transparent;\n"
"border:none;\n"
"font:bold;\n"
"border:3px solid black;"));
        circle->raise();
        Mode->raise();
        BottomRFoot->raise();
        BottomRight->raise();
        BackBut->raise();
        BottomLeft->raise();
        LeftFoot->raise();
        Right->raise();
        VitBut->raise();
        FootPedalSettings->raise();
        IABut->raise();
        Select->raise();
        RightFoot->raise();
        BottomLFoot->raise();
        PhacoBut->raise();
        Surgeon->raise();
        Left->raise();
        SelectSurgeon->raise();
        tabWidget->raise();
        DiaBut->raise();

        retranslateUi(doctor);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(doctor);
    } // setupUi

    void retranslateUi(QDialog *doctor)
    {
        doctor->setWindowTitle(QCoreApplication::translate("doctor", "Dialog", nullptr));
        Mode->setText(QCoreApplication::translate("doctor", "MODE", nullptr));
        BottomRFoot->setItemText(0, QCoreApplication::translate("doctor", "Increment", nullptr));
        BottomRFoot->setItemText(1, QCoreApplication::translate("doctor", "Decrement", nullptr));
        BottomRFoot->setItemText(2, QCoreApplication::translate("doctor", "Reflux", nullptr));
        BottomRFoot->setItemText(3, QCoreApplication::translate("doctor", "Continuous Irrigation", nullptr));
        BottomRFoot->setItemText(4, QCoreApplication::translate("doctor", "Power ON/OFF", nullptr));
        BottomRFoot->setItemText(5, QCoreApplication::translate("doctor", "PDM", nullptr));

        BottomRight->setText(QCoreApplication::translate("doctor", "Bottom Right", nullptr));
        BackBut->setText(QString());
        BottomLeft->setText(QCoreApplication::translate("doctor", "Bottom Left", nullptr));
        LeftFoot->setItemText(0, QCoreApplication::translate("doctor", "Increment", nullptr));
        LeftFoot->setItemText(1, QCoreApplication::translate("doctor", "Decrement", nullptr));
        LeftFoot->setItemText(2, QCoreApplication::translate("doctor", "Reflux", nullptr));
        LeftFoot->setItemText(3, QCoreApplication::translate("doctor", "Continuous Irrigation", nullptr));
        LeftFoot->setItemText(4, QCoreApplication::translate("doctor", "Power ON/OFF", nullptr));
        LeftFoot->setItemText(5, QCoreApplication::translate("doctor", "PDM", nullptr));

        Right->setText(QCoreApplication::translate("doctor", "Right", nullptr));
        VitBut->setText(QCoreApplication::translate("doctor", "VIT", nullptr));
        circle->setText(QString());
        FootPedalSettings->setText(QCoreApplication::translate("doctor", "FOOTPEDAL SETTINGS", nullptr));
        IABut->setText(QCoreApplication::translate("doctor", "I/A", nullptr));
        Select->setText(QCoreApplication::translate("doctor", "SELECT SURGEON", nullptr));
        RightFoot->setItemText(0, QCoreApplication::translate("doctor", "Increment", nullptr));
        RightFoot->setItemText(1, QCoreApplication::translate("doctor", "Decrement", nullptr));
        RightFoot->setItemText(2, QCoreApplication::translate("doctor", "Reflux", nullptr));
        RightFoot->setItemText(3, QCoreApplication::translate("doctor", "Continuous Irrigation", nullptr));
        RightFoot->setItemText(4, QCoreApplication::translate("doctor", "Power ON/OFF", nullptr));
        RightFoot->setItemText(5, QCoreApplication::translate("doctor", "PDM", nullptr));

        BottomLFoot->setItemText(0, QCoreApplication::translate("doctor", "Increment", nullptr));
        BottomLFoot->setItemText(1, QCoreApplication::translate("doctor", "Decrement", nullptr));
        BottomLFoot->setItemText(2, QCoreApplication::translate("doctor", "Reflux", nullptr));
        BottomLFoot->setItemText(3, QCoreApplication::translate("doctor", "Continuous Irrigation", nullptr));
        BottomLFoot->setItemText(4, QCoreApplication::translate("doctor", "Power ON/OFF", nullptr));
        BottomLFoot->setItemText(5, QCoreApplication::translate("doctor", "PDM", nullptr));

        PhacoBut->setText(QCoreApplication::translate("doctor", "PHACO", nullptr));
        Surgeon->setText(QString());
        Left->setText(QCoreApplication::translate("doctor", "Left", nullptr));
        SelectSurgeon->setItemText(0, QCoreApplication::translate("doctor", "Surgeon 1", nullptr));
        SelectSurgeon->setItemText(1, QCoreApplication::translate("doctor", "Surgeon 2", nullptr));
        SelectSurgeon->setItemText(2, QCoreApplication::translate("doctor", "Surgeon 3", nullptr));
        SelectSurgeon->setItemText(3, QCoreApplication::translate("doctor", "Surgeon 4", nullptr));
        SelectSurgeon->setItemText(4, QCoreApplication::translate("doctor", "Surgeon 5", nullptr));
        SelectSurgeon->setItemText(5, QCoreApplication::translate("doctor", "Surgeon 6", nullptr));
        SelectSurgeon->setItemText(6, QCoreApplication::translate("doctor", "Surgeon 7", nullptr));
        SelectSurgeon->setItemText(7, QCoreApplication::translate("doctor", "Surgeon 8", nullptr));
        SelectSurgeon->setItemText(8, QCoreApplication::translate("doctor", "Surgeon 9", nullptr));
        SelectSurgeon->setItemText(9, QCoreApplication::translate("doctor", "Surgeon 10", nullptr));

        DiaPowMax->setText(QCoreApplication::translate("doctor", "POWER MAXIMUM", nullptr));
        SaveDiaBut->setText(QCoreApplication::translate("doctor", "save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Diathermy), QCoreApplication::translate("doctor", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("doctor", "Tab 1", nullptr));
        VacModeCom_phaco->setItemText(0, QCoreApplication::translate("doctor", "Vaccum", nullptr));
        VacModeCom_phaco->setItemText(1, QCoreApplication::translate("doctor", "Panel", nullptr));

        AspMax_phaco->setText(QCoreApplication::translate("doctor", "Aspiration (Max)", nullptr));
        PowMethodCom_phaco->setItemText(0, QCoreApplication::translate("doctor", "Continuous", nullptr));
        PowMethodCom_phaco->setItemText(1, QCoreApplication::translate("doctor", "Pulse", nullptr));
        PowMethodCom_phaco->setItemText(2, QCoreApplication::translate("doctor", "OcuPulse", nullptr));
        PowMethodCom_phaco->setItemText(3, QCoreApplication::translate("doctor", "OcuBurst", nullptr));
        PowMethodCom_phaco->setItemText(4, QCoreApplication::translate("doctor", "Single Burst", nullptr));
        PowMethodCom_phaco->setItemText(5, QCoreApplication::translate("doctor", "Multi Burst", nullptr));
        PowMethodCom_phaco->setItemText(6, QCoreApplication::translate("doctor", "Hyper Burst", nullptr));

        PowModeCom_phaco->setItemText(0, QCoreApplication::translate("doctor", "Surgeon", nullptr));
        PowModeCom_phaco->setItemText(1, QCoreApplication::translate("doctor", "Panel", nullptr));

        VacMax_phaco->setText(QCoreApplication::translate("doctor", "Vaccum (Max)", nullptr));
        PowMax_phaco->setText(QCoreApplication::translate("doctor", "Power (Max)", nullptr));
        PowMode_phaco->setText(QCoreApplication::translate("doctor", "Power Mode", nullptr));
        PowMethod_phaco->setText(QCoreApplication::translate("doctor", "Power Method", nullptr));
        VacMode_phaco->setText(QCoreApplication::translate("doctor", "Vaccum Mode", nullptr));
        EpinBut_phaco->setText(QCoreApplication::translate("doctor", "Epinucleus", nullptr));
        QuadBut_phaco->setText(QCoreApplication::translate("doctor", "Quad", nullptr));
        ChopBut_phaco->setText(QCoreApplication::translate("doctor", "Chop", nullptr));
        ScupltBut_phaco->setText(QCoreApplication::translate("doctor", "Sculpt", nullptr));
        SavePhacoBut_phaco->setText(QCoreApplication::translate("doctor", "SAVE", nullptr));
        AspMax_phaco_2->setText(QCoreApplication::translate("doctor", "(ml/min)", nullptr));
        AspMax_phaco_3->setText(QCoreApplication::translate("doctor", "(mmHg)", nullptr));
        AspMax_phaco_4->setText(QCoreApplication::translate("doctor", "(%)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("doctor", "Tab 2", nullptr));
        AspMax_ia->setText(QCoreApplication::translate("doctor", "Aspiration Max                               :", nullptr));
        VacMax_ia->setText(QCoreApplication::translate("doctor", "Vaccum Max                                    :", nullptr));
        AspMode1_ia->setText(QCoreApplication::translate("doctor", "Aspiration Mode                            :", nullptr));
        VacMode2_ia->setText(QCoreApplication::translate("doctor", "Vaccum Mode                                  :", nullptr));
        AspMax2_ia->setText(QCoreApplication::translate("doctor", "Aspiration Max                               :", nullptr));
        VacMax_ia_2->setText(QCoreApplication::translate("doctor", "Vaccum Max                                     :", nullptr));
        AspMode3_ia->setText(QCoreApplication::translate("doctor", "Aspiration Mode                             :", nullptr));
        VacMode3_ia->setText(QCoreApplication::translate("doctor", "Vaccum Mode                                   :", nullptr));
        AspMode_iacom->setItemText(0, QCoreApplication::translate("doctor", "Linear", nullptr));
        AspMode_iacom->setItemText(1, QCoreApplication::translate("doctor", "Non Linear", nullptr));

        VacMode1_iacom->setItemText(0, QCoreApplication::translate("doctor", "Linear", nullptr));
        VacMode1_iacom->setItemText(1, QCoreApplication::translate("doctor", "Non Linear", nullptr));

        VacMode2_iacom->setItemText(0, QCoreApplication::translate("doctor", "Linear", nullptr));
        VacMode2_iacom->setItemText(1, QCoreApplication::translate("doctor", "Non Linear", nullptr));

        Cortex->setText(QCoreApplication::translate("doctor", "Cortex", nullptr));
        AspMode2_iacom->setItemText(0, QCoreApplication::translate("doctor", "Linear", nullptr));
        AspMode2_iacom->setItemText(1, QCoreApplication::translate("doctor", "Non  Linear", nullptr));

        Piolish->setText(QCoreApplication::translate("doctor", "Polish", nullptr));
        IASaveBut->setText(QCoreApplication::translate("doctor", "SAVE", nullptr));
        AspMax_phaco_5->setText(QCoreApplication::translate("doctor", "(mmHg)", nullptr));
        AspMax_phaco_6->setText(QCoreApplication::translate("doctor", "(ml/min)", nullptr));
        AspMax_phaco_7->setText(QCoreApplication::translate("doctor", "(ml/min)", nullptr));
        AspMax_phaco_8->setText(QCoreApplication::translate("doctor", "(mmHg)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("doctor", "Page", nullptr));
        CutMax_vit->setText(QCoreApplication::translate("doctor", "Maximum                                         :", nullptr));
        CutMode_vitCom->setItemText(0, QCoreApplication::translate("doctor", "Linear", nullptr));
        CutMode_vitCom->setItemText(1, QCoreApplication::translate("doctor", "Non Linear", nullptr));

        CutMode_vit->setText(QCoreApplication::translate("doctor", "Mode                                                 :", nullptr));
        VacMax_vit->setText(QCoreApplication::translate("doctor", "Maximum                                           :", nullptr));
        VacMode_VitCom->setItemText(0, QCoreApplication::translate("doctor", "Linear", nullptr));
        VacMode_VitCom->setItemText(1, QCoreApplication::translate("doctor", "Non Linear", nullptr));

        VacMode_vit->setText(QCoreApplication::translate("doctor", "Mode                                                    :", nullptr));
        AspMax_vit->setText(QCoreApplication::translate("doctor", "Aspiration Max                                    :", nullptr));
        CutRate->setText(QCoreApplication::translate("doctor", "Cut Rate", nullptr));
        Vaccum->setText(QCoreApplication::translate("doctor", "Vaccum", nullptr));
        savevitbut->setText(QCoreApplication::translate("doctor", "SAVE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("doctor", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("doctor", "Page", nullptr));
        DiaBut->setText(QCoreApplication::translate("doctor", "DIA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctor: public Ui_doctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_H
