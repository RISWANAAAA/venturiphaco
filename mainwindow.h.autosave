#ifndef MAINWINDOW_H
#define MAINWINDOW_H


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
#include "footlib.h"
#include "vaccum.h"
#include<QElapsedTimer>
#include"hwhandler.h"
#include"doctor.h"
#include <QDir>
#include <QFileInfo>
#include<QSqlQuery>
#include<QSqlRecord>

#define PATH1 "/home/phacohigh.db"

class settings;
class prime;
 class footpedal;
 class doctor;
 class demo;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;

             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void push(const QString &surgeonName);
    void startPoint();
    bool eventFilter(QObject* object, QEvent* event);
   // void push(const QString &surgeonName);

    void setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue);

    void click();
    void exportGPIO(int pin);
    void setGPIODirection(const QString &direction,int pin);
    int readGPIOValue(int pin);
    int readGPIOValue1();
    void updateStatus();
    void printAllRows();
    void handlePowerOnOff();
    void handlePDM();
    void savesettings();
    int range=0;
    int rec;
    int butname=0;
    int readGPIO(int gpio,int gpio1,int gpio2,int gpio3);
    void moveTab(int usIndex);
      void moveTab1(int usIndex);
      void moveTab2(int usIndex);
      void moveTab3(int usIndex);

    struct SystemState {
           bool powerOn;
           bool powerOn1;
           bool powerOn2;
           bool powerOn3;// Flag to track power state
           bool powerOn4;// Flag to track power state
           QString buttonState;    // To track button state
           QString button;
           //us2
           QString buttonstate1;
           QString button1;
           //us3
           QString buttonstate2;
           QString button2;
           //us4
           QString buttonstate3;
           QString button3;
           //vit
           QString buttonstate4;
           QString button4;

       }power;
    struct SurgeonData {
        QString surgeonName;
        int lineEdit1Value;
        int lineEdit2Value;
         int lineEdit3Value;
         QString powerDelivery;
         QString pdmMode;
         QString vacmode;
    };
      int pull();
    struct SurgicalData {
        QString comboBoxValue;
        QString combo;
        int dia;
        int us1pow, us1vac, us1asp;
        int us2pow, us2vac, us2asp;
        int us3pow, us3vac, us3asp;
        int us4pow, us4vac, us4asp;
        int ia1vac, ia1asp;
        int ia2vac, ia2asp;
        int vitcut, vitvac, vitasp;
        QString powmode, vacmode, powmethod;
        QString us2powmode, us2vacmode, us2powermethod;
        QString us3powmode, us3vacmode, us3powermethod;
        QString us4powmode, us4vacmode, us4powermethod;
        QString ia1mode, ia2mode;
        QString vitmode, vitvacmode;
    }surgicalData;

    int Flow_LUT[42]={95,95,  //0
                    110,110,  //2
                    112,112,  //4
                    115,115,  //6
                    122,122,  //8
                    130,130, //10
                    145,145, //12
                    155,150, //14
                    165,155, //16
                    175,160, //18
                    185,170, //20
                    195,195, //22
                    205,205, //24
                    215,215, //26
                    225,225, //28
                    245,245, //30
                    255,255, //32
                    265,265, //34
                    275,275, //36
                    290,290, //38
                    299,299  //40
                    };
void setTuneMode(bool isTuneEnabled);
void enableButtons(bool powerOn);

public slots:
   void onPdmModeSelected();
   void onPdmModeSelected1();
   void onPdmModeSelected2();
   void onPdmModeSelected3();

 void userMessage(int value, int minValue, int maxValue);
 void updateLineedit(QLineEdit *lineEdit, int prevValue, int value, int maxValue);
 void on_clicked(const QString& digit);
 void on_clickedenter();

 void current(int tab);
 void updateline();
 void tabupdate(int index);
void footpedalcheck();

void updateElapsedTime();
void updateProgressBar();
void motoron(QLineEdit *lineEdit);
void motoroff();
void motorccwon();

void increasebutton(QLineEdit *increaseline);
void decreasebutton(QLineEdit *decreaseline);
void vacbutton(QLineEdit *vacline);

void powervit();
void powercheck();
void DIATHERMYBUT();
void onMainLineEditTextChanged(const QString &dpowmax);
void movePushButtonTopToBottom();
void movePushButtonBottomToTop();
void footreflux();
void powerdeliverymethod();
void continousirrigation(int gpioValue);
void poweronoff(int gpio);
void poweron();
//void updateValues(const QString &surgeon, int tabIndex, const QStringList &values);
void onCutMode_vitComChanged(int index);
void onCutMode_vitComChanged1(int index);
void onCutMode_vitComChanged2(int index);
void onCutMode_vitComChanged3(int index);
void receivecombo(const QString &text);
void performpump(const QString &text);
void receiveValues(
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
        const QString &powmode, const QString &vacmode, const QString &powmethod,
        const QString &us2powmode, const QString &us2vacmode, const QString &us2powermethod,
        const QString &us3powmode, const QString &us3vacmode, const QString &us3powermethod,
        const QString &us4powmode, const QString &us4vacmode, const QString &us4powermethod,
        const QString &ia1mode, const QString &ia2mode,
        const QString &vitmode, const QString &vitvacmode
    );


//
private slots:
// void onComboBoxChanged(int index);
void label43();
void sensor2();
void ULTRASONICBUT1();

void ULTRASONICBUT2();

void ULTRASONICBUT4();

void IRRIGATIONBUT1();

void IRRIGATIONBUT2();

void VITRECTOMYBUT();


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


void us1_linear_nonlinear();

void us2_linear_nonlinear();


void us3_linear_nonlinear();

void us4_linear_nonlinear();


void ia1_linear_nonlinear();

void ia2_linear_nonlinear();

void vit_linear_nonlinear();

void pulseup_mode();

void pulsedown_mode();

void ocuburstup_mode();

void ocuburstdown_mode();

void singleburstup_mode();

void singleburstdown_mode();

void multiburstup_mode();

void multiburstdown_mode();

void ocupulseup_mode();

void ocupulsedown_mode();

void coldphacoup_mode();

void coldphacodown_mode();

void coldphaco1up_mode();

void coldphaco1down_mode();


void updatehandpieceStatus();

void updatesensor();



void onUpdateStatusTimeout(); // Slot to handle timer timeout

void updateTimers();

void settings_action(int index);

void on_us1onoff_clicked();

void on_us2onoff_clicked();

void on_us3onoff_clicked();

void on_us4onoff_clicked();

void on_vitonoff_clicked();

void doctorwindow_show();

void footpedalwindow_show();

void on_us1vacmode_clicked();

void on_us2vacmode_clicked();

void on_us3vacmode_clicked();

void on_vitvacmode_clicked();

void on_us4vacmode_clicked();

void updateComboBox1(const QString &text);

void updateComboBox2(const QString &text);

void updateComboBox3(const QString &text);

void updateComboBox4(const QString &text);

//void onSurgeonChanged();

void updateButtonSelection(int index);


void on_CI4_2_clicked();

void on_SETTINGS_BUT_2_clicked();
void onSurgeonSelectionChanged(const QString &surgeonName);


signals:
    void sensorValueChanged(int value);
     void surgeonSelected(const QString &surgeonName);

private:
    Ui::MainWindow *ui;
    int gpioNumber = 960; // Change this to your actual GPIO number
    int gpioNumber1=961;
     QTimer  *statusUpdateTimer;
       footpedal *foot;
       doctor *in;
    int value1=0;
    int value2=0;
    int pulse=0;
    int ocupulse;
    int ocuburst;
    int singleburst=0;
    int multiburst=0;
    int coldphaco=0;
    int coldphaco1=0;
   int previousValue[7];
    settings *s;

    keypad *key;
    QMessageBox *message;
  QTimer timer2;
    QTimer *timer;
    footlib *lfoot;

    hwhandler *handler;

   QIntValidator *valid;
   QMessageBox *messageline;
    bool flag1=false;
    bool on;
int getvalue(int input);
int currentButtonIndex;

       // QElapsedTimer *timer8;
      //  Reset *r;
        qint64 elap=0;
        QElapsedTimer timer5;

           float effectiveTime ;

             QTime startTime;
             QTimer *sensortimer;
             //QTimer updateTimer;
             QTimer *footime;
             QTimer *protimer;
             QTimer *timer43;
             QTimer *footsensor;
             QTimer *timermsg;
             bool cius1;
             bool cius2;
             bool cius3;
             bool cius4;
             bool civit;
             bool ci_ia1;
             bool ci_ia2;
             bool cidia;
             bool overallci;


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
              QTimer *powtimer;
              QTimer *surtimer;
              int currentValue;
              int maxValue;
              //int lvalue;
              Vaccum *vac;
              int roundToNearest60(int value);
              QElapsedTimer currentTimer;
              QTimer *updateTimer;
              qint64 elapsedTimeUS1, elapsedTimeUS2, elapsedTimeUS3, elapsedTimeUS4;
              int currentButton;
          void updateLabel();
          void switchTimer(int button);
           int counter=0;
bool powerOn1;
QMap<QString, QMap<int, QStringList>> surgeonData;
void updateTabsBasedOnComboBox(const QString &text);
QSqlDatabase db;

 void connectToDatabase();

 void populateSurgeonList();
 void handleDataSaved();
 //void initializeSurgeonSelection();
 QString getLastUpdatedSurgeon();
  bool isTuneEnabled;
  int buttonforgpio;  // Track the current active button
  QPushButton* buttons[7];  // Array to store the 7 buttons
    int currentbut;   // Track the current button index
};
#endif // MAINWINDOW_H
