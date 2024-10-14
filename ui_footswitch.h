/********************************************************************************
** Form generated from reading UI file 'footswitch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOOTSWITCH_H
#define UI_FOOTSWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_footswitch
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *But_zero;
    QPushButton *But_zerodown;
    QPushButton *But_onedown;
    QPushButton *But_oneup;
    QPushButton *But_twodown;
    QPushButton *But_twoup;
    QPushButton *But_threedown;
    QPushButton *But_threeup;
    QLabel *label_2;
    QPushButton *But_save;
    QPushButton *But_topleft;
    QPushButton *But_topright;
    QPushButton *But_bottomleft;
    QPushButton *But_bottomright;
    QPushButton *But_footswitch;
    QComboBox *LeftFoot_com;
    QComboBox *Right_footcom;
    QComboBox *Bottom_leftcom;
    QComboBox *Bottom_rightcom;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;

    void setupUi(QDialog *footswitch)
    {
        if (footswitch->objectName().isEmpty())
            footswitch->setObjectName(QString::fromUtf8("footswitch"));
        footswitch->resize(1280, 720);
        footswitch->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(18, 78, 102);\n"
"\n"
"\n"
""));
        label = new QLabel(footswitch);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 50, 471, 571));
        label->setStyleSheet(QString::fromUtf8("image: url(:/images/footimg.png);\n"
"background-color:transparent;\n"
"border:none;"));
        lineEdit = new QLineEdit(footswitch);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(960, 90, 211, 61));
        lineEdit->setStyleSheet(QString::fromUtf8("\n"
"font:25pt \"Ubuntu\";\n"
"background-color:#FFB521;\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(footswitch);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(960, 230, 211, 61));
        lineEdit_2->setStyleSheet(QString::fromUtf8("\n"
"font:25pt \"Ubuntu\";\n"
"background-color: #FF8103;\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(footswitch);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(960, 360, 211, 61));
        lineEdit_3->setStyleSheet(QString::fromUtf8("\n"
"font:25pt \"Ubuntu\";\n"
"background-color: #a3842c;\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(footswitch);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(960, 500, 211, 61));
        lineEdit_4->setStyleSheet(QString::fromUtf8("\n"
"font:25pt \"Ubuntu\";\n"
"background-color: #ffb8b1;\n"
"border-radius:20px;border:2px solid black;"));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        But_zero = new QPushButton(footswitch);
        But_zero->setObjectName(QString::fromUtf8("But_zero"));
        But_zero->setGeometry(QRect(860, 80, 81, 81));
        But_zero->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/images/up1.png);\n"
"background-color:transparent;"));
        But_zerodown = new QPushButton(footswitch);
        But_zerodown->setObjectName(QString::fromUtf8("But_zerodown"));
        But_zerodown->setGeometry(QRect(1190, 80, 81, 81));
        But_zerodown->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/images/down1.png);"));
        But_onedown = new QPushButton(footswitch);
        But_onedown->setObjectName(QString::fromUtf8("But_onedown"));
        But_onedown->setGeometry(QRect(1190, 220, 81, 81));
        But_onedown->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/images/down1.png);\n"
"background-color:transparent;"));
        But_oneup = new QPushButton(footswitch);
        But_oneup->setObjectName(QString::fromUtf8("But_oneup"));
        But_oneup->setGeometry(QRect(860, 220, 81, 81));
        But_oneup->setStyleSheet(QString::fromUtf8("image: url(:/images/up1.png);\n"
"border:none;\n"
"background-color:transparent;"));
        But_twodown = new QPushButton(footswitch);
        But_twodown->setObjectName(QString::fromUtf8("But_twodown"));
        But_twodown->setGeometry(QRect(1190, 350, 81, 81));
        But_twodown->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/images/down1.png);\n"
"background-color:transparent;"));
        But_twoup = new QPushButton(footswitch);
        But_twoup->setObjectName(QString::fromUtf8("But_twoup"));
        But_twoup->setGeometry(QRect(860, 350, 81, 81));
        But_twoup->setStyleSheet(QString::fromUtf8("image: url(:/images/up1.png);\n"
"border:none;\n"
"background-color:transparent;"));
        But_threedown = new QPushButton(footswitch);
        But_threedown->setObjectName(QString::fromUtf8("But_threedown"));
        But_threedown->setGeometry(QRect(1190, 490, 81, 81));
        But_threedown->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/images/down1.png);\n"
"background-color:transparent;"));
        But_threeup = new QPushButton(footswitch);
        But_threeup->setObjectName(QString::fromUtf8("But_threeup"));
        But_threeup->setGeometry(QRect(860, 490, 81, 81));
        But_threeup->setStyleSheet(QString::fromUtf8("image: url(:/images/up1.png);\n"
"border:none;\n"
"background-color:transparent;"));
        label_2 = new QLabel(footswitch);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(830, 610, 71, 61));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/circle.png);\n"
"background-color:transparent;\n"
"border:none;"));
        But_save = new QPushButton(footswitch);
        But_save->setObjectName(QString::fromUtf8("But_save"));
        But_save->setGeometry(QRect(1020, 570, 211, 151));
        But_save->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/images/savebuttonimg.png);\n"
"background-color:transparent;"));
        But_topleft = new QPushButton(footswitch);
        But_topleft->setObjectName(QString::fromUtf8("But_topleft"));
        But_topleft->setGeometry(QRect(328, 164, 81, 101));
        But_topleft->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent;"));
        But_topright = new QPushButton(footswitch);
        But_topright->setObjectName(QString::fromUtf8("But_topright"));
        But_topright->setGeometry(QRect(540, 170, 61, 101));
        But_topright->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent;"));
        But_bottomleft = new QPushButton(footswitch);
        But_bottomleft->setObjectName(QString::fromUtf8("But_bottomleft"));
        But_bottomleft->setGeometry(QRect(340, 300, 61, 91));
        But_bottomleft->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent;"));
        But_bottomright = new QPushButton(footswitch);
        But_bottomright->setObjectName(QString::fromUtf8("But_bottomright"));
        But_bottomright->setGeometry(QRect(540, 300, 61, 91));
        But_bottomright->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent;"));
        But_footswitch = new QPushButton(footswitch);
        But_footswitch->setObjectName(QString::fromUtf8("But_footswitch"));
        But_footswitch->setGeometry(QRect(420, 180, 111, 231));
        But_footswitch->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent;"));
        LeftFoot_com = new QComboBox(footswitch);
        LeftFoot_com->addItem(QString());
        LeftFoot_com->addItem(QString());
        LeftFoot_com->addItem(QString());
        LeftFoot_com->addItem(QString());
        LeftFoot_com->addItem(QString());
        LeftFoot_com->addItem(QString());
        LeftFoot_com->setObjectName(QString::fromUtf8("LeftFoot_com"));
        LeftFoot_com->setGeometry(QRect(50, 170, 261, 81));
        LeftFoot_com->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"color: rgb(255, 255, 255);\n"
"font:20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);"));
        Right_footcom = new QComboBox(footswitch);
        Right_footcom->addItem(QString());
        Right_footcom->addItem(QString());
        Right_footcom->addItem(QString());
        Right_footcom->addItem(QString());
        Right_footcom->addItem(QString());
        Right_footcom->addItem(QString());
        Right_footcom->setObjectName(QString::fromUtf8("Right_footcom"));
        Right_footcom->setGeometry(QRect(610, 170, 261, 81));
        Right_footcom->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"color: rgb(255, 255, 255);\n"
"font:20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);"));
        Bottom_leftcom = new QComboBox(footswitch);
        Bottom_leftcom->addItem(QString());
        Bottom_leftcom->addItem(QString());
        Bottom_leftcom->addItem(QString());
        Bottom_leftcom->addItem(QString());
        Bottom_leftcom->addItem(QString());
        Bottom_leftcom->addItem(QString());
        Bottom_leftcom->setObjectName(QString::fromUtf8("Bottom_leftcom"));
        Bottom_leftcom->setGeometry(QRect(50, 300, 261, 81));
        Bottom_leftcom->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"color: rgb(255, 255, 255);\n"
"font:20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);"));
        Bottom_rightcom = new QComboBox(footswitch);
        Bottom_rightcom->addItem(QString());
        Bottom_rightcom->addItem(QString());
        Bottom_rightcom->addItem(QString());
        Bottom_rightcom->addItem(QString());
        Bottom_rightcom->addItem(QString());
        Bottom_rightcom->addItem(QString());
        Bottom_rightcom->setObjectName(QString::fromUtf8("Bottom_rightcom"));
        Bottom_rightcom->setGeometry(QRect(610, 300, 271, 81));
        Bottom_rightcom->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"color: rgb(255, 255, 255);\n"
"font:20pt \"Ubuntu\";\n"
"background-color: rgb(0, 0, 0);"));
        label_3 = new QLabel(footswitch);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 490, 41, 41));
        label_4 = new QLabel(footswitch);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(950, 40, 241, 41));
        label_4->setStyleSheet(QString::fromUtf8("font:30px;background-color:transparent;\n"
"color:white;\n"
"border-radius:10px;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(footswitch);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(950, 170, 241, 41));
        label_5->setStyleSheet(QString::fromUtf8("font:30px;background-color:transparent;\n"
"color:white;\n"
"border-radius:10px;"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(footswitch);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(950, 310, 241, 41));
        label_6->setStyleSheet(QString::fromUtf8("font:30px;background-color:transparent;\n"
"color:white;\n"
"border-radius:10px;"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(footswitch);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(950, 440, 241, 41));
        label_7->setStyleSheet(QString::fromUtf8("font:30px;background-color:transparent;\n"
"color:white;\n"
"border-radius:10px;"));
        label_7->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(footswitch);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 10, 141, 101));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/images/backbuttonarrow.png);\n"
"border:none;\n"
"background-color:transparent;"));
        label_2->raise();
        label->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        But_zero->raise();
        But_zerodown->raise();
        But_onedown->raise();
        But_oneup->raise();
        But_twodown->raise();
        But_twoup->raise();
        But_threedown->raise();
        But_threeup->raise();
        But_save->raise();
        But_topleft->raise();
        But_topright->raise();
        But_bottomleft->raise();
        But_bottomright->raise();
        But_footswitch->raise();
        LeftFoot_com->raise();
        Right_footcom->raise();
        Bottom_leftcom->raise();
        Bottom_rightcom->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        pushButton->raise();

        retranslateUi(footswitch);

        QMetaObject::connectSlotsByName(footswitch);
    } // setupUi

    void retranslateUi(QDialog *footswitch)
    {
        footswitch->setWindowTitle(QCoreApplication::translate("footswitch", "Dialog", nullptr));
        label->setText(QString());
        But_zero->setText(QString());
        But_zerodown->setText(QString());
        But_onedown->setText(QString());
        But_oneup->setText(QString());
        But_twodown->setText(QString());
        But_twoup->setText(QString());
        But_threedown->setText(QString());
        But_threeup->setText(QString());
        label_2->setText(QString());
        But_save->setText(QString());
        But_topleft->setText(QString());
        But_topright->setText(QString());
        But_bottomleft->setText(QString());
        But_bottomright->setText(QString());
        But_footswitch->setText(QString());
        LeftFoot_com->setItemText(0, QCoreApplication::translate("footswitch", "Increment", nullptr));
        LeftFoot_com->setItemText(1, QCoreApplication::translate("footswitch", "Decrement", nullptr));
        LeftFoot_com->setItemText(2, QCoreApplication::translate("footswitch", "Reflux", nullptr));
        LeftFoot_com->setItemText(3, QCoreApplication::translate("footswitch", "Continuous Irrigation", nullptr));
        LeftFoot_com->setItemText(4, QCoreApplication::translate("footswitch", "Power ON/OFF", nullptr));
        LeftFoot_com->setItemText(5, QCoreApplication::translate("footswitch", "PDM", nullptr));

        Right_footcom->setItemText(0, QCoreApplication::translate("footswitch", "Increment", nullptr));
        Right_footcom->setItemText(1, QCoreApplication::translate("footswitch", "Decrement", nullptr));
        Right_footcom->setItemText(2, QCoreApplication::translate("footswitch", "Reflux", nullptr));
        Right_footcom->setItemText(3, QCoreApplication::translate("footswitch", "Continuous Irrigation", nullptr));
        Right_footcom->setItemText(4, QCoreApplication::translate("footswitch", "Power ON/OFF", nullptr));
        Right_footcom->setItemText(5, QCoreApplication::translate("footswitch", "PDM", nullptr));

        Bottom_leftcom->setItemText(0, QCoreApplication::translate("footswitch", "Increment", nullptr));
        Bottom_leftcom->setItemText(1, QCoreApplication::translate("footswitch", "Decrement", nullptr));
        Bottom_leftcom->setItemText(2, QCoreApplication::translate("footswitch", "Reflux", nullptr));
        Bottom_leftcom->setItemText(3, QCoreApplication::translate("footswitch", "Continuous Irrigation", nullptr));
        Bottom_leftcom->setItemText(4, QCoreApplication::translate("footswitch", "Power ON/OFF", nullptr));
        Bottom_leftcom->setItemText(5, QCoreApplication::translate("footswitch", "PDM", nullptr));

        Bottom_rightcom->setItemText(0, QCoreApplication::translate("footswitch", "Increment", nullptr));
        Bottom_rightcom->setItemText(1, QCoreApplication::translate("footswitch", "Decrement", nullptr));
        Bottom_rightcom->setItemText(2, QCoreApplication::translate("footswitch", "Reflux", nullptr));
        Bottom_rightcom->setItemText(3, QCoreApplication::translate("footswitch", "Continuous Irrigation", nullptr));
        Bottom_rightcom->setItemText(4, QCoreApplication::translate("footswitch", "Power ON/OFF", nullptr));
        Bottom_rightcom->setItemText(5, QCoreApplication::translate("footswitch", "PDM", nullptr));

        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("footswitch", "0 Position", nullptr));
        label_5->setText(QCoreApplication::translate("footswitch", "1 Position", nullptr));
        label_6->setText(QCoreApplication::translate("footswitch", "2 Position", nullptr));
        label_7->setText(QCoreApplication::translate("footswitch", "3 Position", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class footswitch: public Ui_footswitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOOTSWITCH_H
