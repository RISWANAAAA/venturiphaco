#ifndef DOCTOR_H
#define DOCTOR_H

#include <QDialog>
#include <QtDebug>
#include "prime.h"
#include"keypad.h"
#include"mainwindow.h"
#include<QMessageBox>

class QLineEdit;


#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
//#define PATH "/home/phaco.db"
#define PATH1 "/home/phacohigh.db"

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
    void clickedtab(int tab1);
    void PhacoSaveBut();



    void IASaveBut();

    void VitSaveBut();
    void click(int tab);
    void increasebutton(QLineEdit *increaseline);
    void decreasebutton(QLineEdit *decreaseline);
    void vacbutton(QLineEdit *vacline);


    void currentcombobox1(const QString &text);
    void currentcombobox2(const QString &text);
    void currentcombobox3(const QString &text);
    void currentcombobox4(const QString &text);



private slots:
    void DiathermyBut();

    void PhacoBut();

    void IrrigationAspirationBut();

    void VitrectomyBut();

    void BackBut();

    void savesettings();



    //void on_pushButton_5_clicked();





    void on_QuadBut_phaco_clicked();

    void on_ChopBut_phaco_clicked();

    void on_ScupltBut_phaco_clicked();




  void on_EpinBut_phaco_clicked();



  void on_pushButton_clicked();
  void pumpvalue();

  void on_SaveDiaBut_clicked();



  void on_savefootpedal_clicked();

signals:

  void sendleftfootvalues(const QString &text1);
  void sendrightfootvalues(const QString &text2);
  void sendbleftfootvalues(const QString &text3);
  void sendbrightfootvalues(const QString &text4);
              //footpedal combo box;
              void leftfoot(const QString &value);
              void rightfoot(const QString &value);
              void bottomleft(const QString &value);
              void bottomright(const QString &value);
              void pumpsignal(const QString &value);
              void sendValues(
                     const QString &comboBoxValue,
                      const QString &combo,
                     int dia,
                     int us1pow, int us1vac, int us1asp,
                     int us2pow, int us2vac, int us2asp,
                     int us3pow, int us3vac, int us3asp,
                     int us4pow, int us4vac, int us4asp,
                     int ia1vac, int ia1asp,
                     int ia2vac, int ia2asp,
                     int vitcut, int vitvac, int vitasp,
                     const QString &powmode,
                     const QString &vacmode,
                     const QString &powmethod,
                     const QString &us2powmode,
                     const QString &us2vacmode,
                     const QString &us2powermethod,
                     const QString &us3powmode,
                     const QString &us3vacmode,
                     const QString &us3powermethod,
                     const QString &us4powmode,
                     const QString &us4vacmode,
                     const QString &us4powermethod,
                     const QString &ia1mode,
                     const QString &ia2mode,
                     const QString &vitmode,
                     const QString &vitvacmode
                 );


private:
    Ui::doctor *ui;
    //prime *p;
    int value =0;
    keypad *key;
    int getvalue(int input);


    QMessageBox *message;
    QMessageBox *messagebox;
    QTimer *timer;
    QMap<QString, QMap<int, QStringList>> surgeonData;



};

#endif // DOCTOR_H
