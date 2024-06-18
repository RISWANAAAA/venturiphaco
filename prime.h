#ifndef PRIME_H
#define PRIME_H

#include <QWidget>
#include "mainwindow.h"
#include<QTimer>
#include "doctor.h"
#include "settings.h"
class MainWindow;
class doctor;
class settings;
namespace Ui {
class prime;

}

class prime : public QWidget
{
    Q_OBJECT

public:
    explicit prime(QWidget *parent = nullptr);
    ~prime();
    void click();

public slots:
    void timer();
    void current(int tab);
    void update();
   void hp(int connected);
private slots:
    void Prime();

    void Tune();

    void Clean();

    void Start_Tune();




    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::prime *ui;
//    int hp=0;
    MainWindow *m;
    QTimer *timer1;
    int value=0;
    int val1=0;
    doctor *sur;
    settings *set;
};

#endif // PRIME_H
