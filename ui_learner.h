/********************************************************************************
** Form generated from reading UI file 'learner.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNER_H
#define UI_LEARNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_learner
{
public:

    void setupUi(QDialog *learner)
    {
        if (learner->objectName().isEmpty())
            learner->setObjectName(QString::fromUtf8("learner"));
        learner->resize(1280, 720);

        retranslateUi(learner);

        QMetaObject::connectSlotsByName(learner);
    } // setupUi

    void retranslateUi(QDialog *learner)
    {
        learner->setWindowTitle(QCoreApplication::translate("learner", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class learner: public Ui_learner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNER_H
