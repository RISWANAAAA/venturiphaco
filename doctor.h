#ifndef DOCTOR_H
#define DOCTOR_H

#include <QDialog>
#include <QtDebug>
#include "prime.h"
#include"keypad.h"
#include<QMessageBox>
#include <mainwindow.h>

class QLineEdit;

#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
//#define PATH "/home/phaco.db"
#define PATH1 "phacoupdate.db"

namespace Ui {
class doctor;
}

class doctor : public QDialog
{
    Q_OBJECT

public:
    explicit doctor(QWidget *parent = nullptr);
    ~doctor();
    bool eventFilter(QObject* object, QEvent* event);
    QString surgeonid;
    void setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue);
    void userMessage(int value, int minValue, int maxValue);
   // void click();


public slots:
    void on_clicked(const QString& digit);
    void on_clickedenter();
    void PhacoSaveBut();

    void DiaSaveBut();

    void IASaveBut();

    void VitSaveBut();
    void click(int tab);




private slots:
    void DiathermyBut();

    void PhacoBut();

    void IrrigationAspirationBut();

    void VitrectomyBut();

    void BackBut();



    void Epinucleus();

    void Quad();

    void Chop();

    void Sculpt();



    //void on_pushButton_5_clicked();


private:
    Ui::doctor *ui;
    //prime *p;
    int value =0;
    keypad *key;
    QString footpedal;
    QString left;
    QString right;
    QString bleft;
    QString bright;
    QString vcutmax;
    QString vvacmax;
    QString vcutmode;
    QString vvacmode;
    QString vitaspmax;
    QMessageBox *message;
    QTimer *timer;
   // QWindow *m;

};

#endif // DOCTOR_H
