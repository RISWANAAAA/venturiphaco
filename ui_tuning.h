/********************************************************************************
** Form generated from reading UI file 'tuning.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUNING_H
#define UI_TUNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_tuning
{
public:
    QPushButton *But_Tune;
    QLabel *Value_lab;
    QLabel *Handpiece_lab;
    QPushButton *But_Next;

    void setupUi(QDialog *tuning)
    {
        if (tuning->objectName().isEmpty())
            tuning->setObjectName(QString::fromUtf8("tuning"));
        tuning->resize(861, 711);
        But_Tune = new QPushButton(tuning);
        But_Tune->setObjectName(QString::fromUtf8("But_Tune"));
        But_Tune->setGeometry(QRect(170, 280, 561, 141));
        But_Tune->setStyleSheet(QString::fromUtf8("QPushButton{background-color:transparent;\n"
"image: url(:/images/handpiece1.png);\n"
"border:none;}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}"));
        Value_lab = new QLabel(tuning);
        Value_lab->setObjectName(QString::fromUtf8("Value_lab"));
        Value_lab->setGeometry(QRect(400, 270, 131, 141));
        Value_lab->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 114, 130);"));
        Handpiece_lab = new QLabel(tuning);
        Handpiece_lab->setObjectName(QString::fromUtf8("Handpiece_lab"));
        Handpiece_lab->setGeometry(QRect(150, 340, 141, 131));
        Handpiece_lab->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));
        But_Next = new QPushButton(tuning);
        But_Next->setObjectName(QString::fromUtf8("But_Next"));
        But_Next->setGeometry(QRect(690, 570, 151, 121));
        But_Next->setStyleSheet(QString::fromUtf8("image: url(:/images/nextarrow.png);\n"
"background-color:transparent;\n"
"border:none;"));

        retranslateUi(tuning);

        QMetaObject::connectSlotsByName(tuning);
    } // setupUi

    void retranslateUi(QDialog *tuning)
    {
        tuning->setWindowTitle(QCoreApplication::translate("tuning", "Dialog", nullptr));
        But_Tune->setText(QString());
        Value_lab->setText(QString());
        Handpiece_lab->setText(QString());
        But_Next->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tuning: public Ui_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUNING_H
