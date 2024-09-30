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
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *tuning)
    {
        if (tuning->objectName().isEmpty())
            tuning->setObjectName(QString::fromUtf8("tuning"));
        tuning->resize(861, 711);
        pushButton = new QPushButton(tuning);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 280, 561, 141));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:transparent;\n"
"image: url(:/images/handpiece1.png);\n"
"border:none;}\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}"));
        label = new QLabel(tuning);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 270, 131, 141));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 114, 130);"));
        label_2 = new QLabel(tuning);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 340, 141, 131));
        label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));
        pushButton_2 = new QPushButton(tuning);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(690, 570, 151, 121));
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/images/nextarrow.png);\n"
"background-color:transparent;\n"
"border:none;"));

        retranslateUi(tuning);

        QMetaObject::connectSlotsByName(tuning);
    } // setupUi

    void retranslateUi(QDialog *tuning)
    {
        tuning->setWindowTitle(QCoreApplication::translate("tuning", "Dialog", nullptr));
        pushButton->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tuning: public Ui_tuning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUNING_H
