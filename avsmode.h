#ifndef AVSMODE_H
#define AVSMODE_H

#include <QDialog>
#include "keypad.h"
#include <QMainWindow>
#include<QSlider>
#include<QPushButton>
#include<QLabel>
#include<QTableWidget>
#include<QMessageBox>
#include <QTimer>
#include<QIntValidator>
#include "footlib.h"
#include "vaccum.h"
#include<QElapsedTimer>
#include"hwhandler.h"
#include <QDir>
#include <QFileInfo>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QMap>
#include<QComboBox>
#define SQLPATH "/home/amt-04/phacohigh.db"
#define PATH "/home/phacohigh.db"

class settings;
class prime;
 class doctor;
 class footpedal;
 class demo;
namespace Ui {
class avsmode;
}

class avsmode : public QDialog
{
    Q_OBJECT

public:
    explicit avsmode(QWidget *parent = nullptr);
    ~avsmode();
    bool eventFilter(QObject* object, QEvent* event);
    int increasebutton(int input);
    int decreasebutton(int  input);
    int getvalue(int value);
    void setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue);
    int butname=0;
    void current(int tab);
    void beepsound();
    void motoron(QLineEdit *lineEdit);
    void motoroff();
    void motorccwon();
    void setLastSelectedValue();
    void push(const QString &surgeonName);
    void footpedalvalues(int &value1, int &value2, int &value3, int &value4);
   void disablefunction();
    struct SurgicalData {
        QString comboBoxValue;
        QString combo;
        int dia;
        int ia1vac, ia1asp;
        int ia2vac, ia2asp;
        int vitcut, vitvac, vitasp;
        QString ia1mode, ia2mode;
        QString vitmode, vitvacmode;
    }surgicalData;
public slots:
    void on_clicked(const QString& digit);
    void on_clickedenter();
    void footpedalcheck();
    int readsensorvalue();
    void onComboBoxIndexChanged(int index);
    void receiveAvsValues(
           const QString &comboBoxValue,
           const QString &combo,
           int dia,
           int ia1vac, int ia1asp,
           int ia2vac, int ia2asp,
           int vitcut, int vitvac, int vitasp,
           const QString &ia1mode, const QString &ia2mode,
          const QString &vitvacmode
       );
    void on_DIABUT_clicked();
    void avsmodechanging(const QString &value);
    void moved(int gpio);
    void movePushButtonBottomToTop(int gpio);
    void footreflux(int gpio);
    void continousirrigation(int value);
private slots:
    void on_butdiaup_clicked();

    void on_butdiadown_clicked();



    void on_butia1up_clicked();

    void on_butia1down_clicked();

    void on_butia1flowup_clicked();

    void on_butia1flowdown_clicked();

    void on_butia2vacup_clicked();

    void on_butia2vacdown_clicked();

    void on_butia2flowup_clicked();

    void on_butia2flowdown_clicked();

    void on_butvitup_clicked();

    void on_butvitdown_clicked();

    void on_butvitvacup_clicked();

    void on_butvitvacdown_clicked();

    void on_butvitflowup_clicked();

    void on_butvitflowdown_clicked();


    void on_IA1BUT_clicked();

    void on_IA2BUT_clicked();

    void on_VITRECTOMYBUT_clicked();
    void on_butCI_clicked();

    void on_SETTINGS_BUT_2_clicked();

    void on_butposition_clicked();

    void on_butia1mode_clicked();

    void on_butia2mode_clicked();

    void on_vitvacmode_clicked();


    void on_butvitonoff_clicked();

signals:
     void sensorValueChanged(int value);
     void surgeonSelected(const QString &surgeonName);
     void left_foot(const QString &value);
     void right_foot(const QString &value);
     void bottom_left(const QString &value);
     void bottom_right(const QString &value);
     void con_irrigation(bool on); // Signal to handle Continuous Irrigation state
     void sendsurgeon(const QString &value);
private:
    Ui::avsmode *ui;
    settings *s;
    keypad *key;
    footpedal *foot;
    doctor *in;
    footlib *lfoot;
    hwhandler *handler;
    Vaccum *vac;





int currentButtonIndex;
int currentButtonIndex1;

int maxValue;
int currentButton;
int counter=0;
int currentbut;

int gpioNumber = 960;
int nfpzero;
int nfpone;
int nfptwo;
int nfpthree;
int diacount=0;

int ia1count=0;
int ia2count=0;
int vitcount=0;
int nFreqCount=0;
int nOnTime=0;
int nHandPiece=1;
int nHandPiece1=1;

QMessageBox *message;
QMessageBox *messageline;

QTimer  *statusUpdateTimer;
QElapsedTimer timer5;
QTimer *sensortimer;
QTimer *footime;
QTimer *protimer;
QTimer *footsensor;
QTimer *timermsg;
QTime currentTimer;
QTimer *updateTimer;
QTimer *Tacutalsensor;
  QTimer *timerfoot;
QTimer *burstTimer;
QElapsedTimer *elapsedTimer;  // Elapsed time (in milliseconds)
int cumulativeElapsedTimeSec;
    int cumulativeEffectiveTimeSec;

bool flag1=false;
bool on;

bool civit;
bool ci_ia1;
bool ci_ia2;
bool cidia;
bool overallci;
bool con=1;
bool reflux=1;

bool powerOn1;
bool isTuneEnabled;
bool us1linear=false;
bool ia1vaclinear=false;
bool ia2vaclinear=false;

bool ventonia1=false;
bool ventonia2=false;
bool ventonvit=false;
bool ventondia=false;
bool overallpower=false;

bool vitonoff=false;
bool motoria1 = false;
bool motoria2=false;
bool motorus1=false;
bool motorus2=false;
bool motorus3=false;
bool motorus4=false;
bool motorvit = false;
bool isProgrammaticClick = false; // To track if the click is programmatic
bool poweronoff1;



QString ia1;
QString ia2;
QString vit;
QString vus1;
QString vus2;
QString vus3;
QString vus4;
QString vvit;
QString vibon;
QString speakeronoff;
QString switchmode;





QMap<QString, QMap<int, QStringList>> surgeonData;
QMap<QLineEdit*, int> lastValidValues;
QMap<QLineEdit*, int> lastValidValues1;

QSqlDatabase db;

};

#endif // AVSWINDOW_H
