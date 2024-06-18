#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "footpedal.h"
#include "settings.h"

#include "keypad.h"

#include <QMainWindow>
#include<QSlider>
#include<QPushButton>
#include<QLabel>
#include<QTableWidget>
#include<QMessageBox>
#include <QTimer>
#include<QIntValidator>

//#include "footlibup.h"
//#include "hhandlerup.h"
//#include "vaccumup.h"
//#include"reset.h"
#include<QElapsedTimer>
//#include "motorup.h"

class settings;
class prime;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // int valuemain=0;

    bool eventFilter(QObject* object, QEvent* event);
    void setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue);
   // void highlightButton(QPushButton* button);
    void click();
    int range=0;


    int butname=0;





public slots:
     void userMessage(int value, int minValue, int maxValue);
     void updateLineedit(QLineEdit *lineEdit, int prevValue, int value, int maxValue);
    void on_clicked(const QString& digit);
    void on_clickedenter();
     void changeButtonColor(int tabIndex);
   //  void buttons();
     void current(int tab);
   //  void handpiece();
     void updateline(int index);
 void tabupdate(int index);
 //void footpedal();
   void startphaco();
 void updateElapsedTime();
 //void updateProgressBar();
// void motoron();
// void motordirection(bool forward);
// void motorpwm(QLineEdit *lineEdit, int index);
// int getPWMDutyCycle(int flowrate);
private slots:
 //void label43();
//void sensor2();
    void ULTRASONICBUT1();

    void ULTRASONICBUT2();


    void ULTRASONICBUT4();

    void IRRIGATIONBUT1();

    void IRRIGATIONBUT2();

    void VITRECTOMYBUT();

    void DIATHERMYBUT();

    void diapowup();

    void diapowdown();

    void vitcutup();

    void vitcutdown();

    void vitvacup();

    void vitvacdown();

    void vitflowup();

    void vitflowdown();

    void ia2vacup();

    void ia2vacdown();

    void ia2flowup();

    void ia2flowdown();

    void ia1vacup();

    void ia1vacdown();

    void ia1flowup();

    void ia1flowdown();

    void US1POWUP();

    void US1POWDOWN();

    void US1VACDOWN();

    void US1VACUP();

    void US1FLOWDOWN();

    void US1FLOWUP();

    //void on_pushButton_32_clicked();

    void us2powup();

    void us2powdown();

    void us2vacup();

    void us2vacdown();

    void us2flowup();

    void us2flowdown();

    void ULTRASONICBUT3();

    void us3powup();

    void us3powdown();

    void us3vacup();

    void us3vacdown();

    void us3flowup();

    void us3flowdown();

    void us4powup();

    void us4powdown();

    void us4vacup();

    void us4vacdown();

    void us4flowup();

    void us4flowdown();

    void SETTINGSBUT();

    void BACKBUT();

    void on_DIABUT_clicked();

    void us1_linear_nonlinear();

    void us2_linear_nonlinear();


    void us3_linear_nonlinear();

    void us4_linear_nonlinear();


    void ia1_linear_nonlinear();

    void ia2_linear_nonlinear();

    void vit_linear_nonlinear();



    void on_off_vit();

  //  void on_off_us1();

    void on_off_us2();

    void on_off_us3();

    void on_off_us4();
    void HANDPIECE();
    void updatesensor();
    void continous_irrigation1();

    void continous_irrigation2();

    void continous_irrigation3();

    void continous_irrigation4();

    void continous_irrigation5();
//    void on_lineEdit_24_returnPressed();

//    void on_lineEdit_12_returnPressed();

//    void on_lineEdit_20_returnPressed();

//    void on_lineEdit_15_returnPressed();

//    void on_lineEdit_21_returnPressed();



//    void on_lineEdit_10_returnPressed();

//    void on_lineEdit_9_returnPressed();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

signals:
    void sensorValueChanged(int value);
private:
    Ui::MainWindow *ui;
    int value1=0;
    int value2=0;
    int ocupulse=0;
    int ocuburst=0;
    int singleburst=0;
    int multiburst=0;
    int coldphaco=0;
   int previousValue[7];
    settings *s;
    //prime *p;
    keypad *key;
    QMessageBox *message;
    QMessageBox *currentMsgBox;
  QTimer timer2;
    QTimer *timer;
 //   footlibup *lfoot;
  //  hhandlerup *hard;
   QIntValidator *valid;
   QMessageBox *messageline;
    bool flag1=false;
    bool on;

       // QElapsedTimer *timer8;
      //  Reset *r;
        qint64 elap=0;
        QElapsedTimer timer5;

           float effectiveTime ;

       //  Vaccumup *v;
          //Motorup *m;
//             QTime startTime;
             QTimer *sensortimer;
             QTimer updateTimer;
             QTimer *footime;
             QTimer *protimer;
             QTimer *timer43;
             QTimer *footsensor;
             QTimer *timermsg;
             bool cs;
             bool cs1;
             bool cs2;
             bool cs3;
             bool cs4;
             QString us1;
             QString us2;
             QString us3;
             QString us4;
             QString ia1;
             QString ia2;
             QString vit;
             QString vus1;
             QString vus2;
             QString vus3;
             QString vus4;
             QString vvit;
             QTimer *footpedaltimer;
              int currentProgressBar=1;
              bool us1powon=false;
              bool us2powon;
              bool us3powon;
              bool us4powon;
              bool vitpowon;
              int dir;




};
#endif // MAINWINDOW_H
