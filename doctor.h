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
    void powervit();
    void dialine(const QString text);
    void currentcombobox1(const QString &text);
    void currentcombobox2(const QString &text);
    void currentcombobox3(const QString &text);
    void currentcombobox4(const QString &text);
    void trasmitcomboBox(const QString &text);
    void current(int index);



private slots:
    void DiathermyBut();
void DiaSaveBut();
    void PhacoBut();

    void IrrigationAspirationBut();

    void VitrectomyBut();

    void BackBut();

    void savesettings();



    //void on_pushButton_5_clicked();


    void on_SavePhacoBut_phaco_2_clicked();



    void on_QuadBut_phaco_clicked();

    void on_ChopBut_phaco_clicked();

    void on_ScupltBut_phaco_clicked();

    void on_SavePhacoBut_phaco_clicked();

    void on_SavePhacoBut_phaco_3_clicked();

    void on_SavePhacoBut_phaco_4_clicked();
    void onComboBox1Changed();
    void onComboBox2Changed();
    void onComboBox3Changed();
    void onComboBox4Changed();
  void onSaveButtonClicked(int tabIndex);


  void on_EpinBut_phaco_clicked();



signals:

    void comboBox1Changed(const QString &text);
    void comboBox2Changed(const QString &text);
    void comboBox3Changed(const QString &text);
     void comboBox4Changed(const QString &text);
    void valuesUpdated(const QString &surgeon, int tabIndex, const QStringList &values);
  void transmitcombo(const QString &text);

              //footpedal combo box;
              void leftfoot(const QString &value);
              void rightfoot(const QString &value);
              void bottomleft(const QString &value);
              void bottomright(const QString &value);


private:
    Ui::doctor *ui;
    //prime *p;
    int value =0;
    keypad *key;
    int getvalue(int input);


    QMessageBox *message;
    QTimer *timer;
    QMap<QString, QMap<int, QStringList>> surgeonData;



};

#endif // DOCTOR_H
