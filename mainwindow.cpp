#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"footpedal.h"

#include <QTimer>
#include<cmath>
#include<QStyleFactory>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
   , elapsedTimeUS1(0)
   , elapsedTimeUS2(0)
   , elapsedTimeUS3(0)
   , elapsedTimeUS4(0)
   , butname(-1)
   ,cius1(false)
   ,cius2(false)
   ,cius3(false)
   ,cius4(false)
   ,ci_ia1(false)
   ,ci_ia2(false)
   ,civit(false)
   ,cidia(false)
{
   ui->setupUi(this);
  // resize(800,600);
   move(0,0);
   vac=new Vaccum;
   handler=new hwhandler;
  // de=new demo;


   ui->CutMode_vit->hide();
   ui->CutMode_vitCom->hide();
   ui->tabWidget_2->hide();
    foot=new footpedal;
  in=new doctor;


   updateTimer = new QTimer(this);
   connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateTimers);
   // Populate the combobox with surgeon names and IDs

   ui->dial_2->setStyleSheet("");
   ui->dial_2->setStyle(QStyleFactory::create("Fusion"));
   //ui->dial_2->setStyleSheet("background-color: rgb(255, 255, 255);");
   ui->dial_2->setRange(0,4096);

   // Connect the combobox signal to the slot

   updateTimer->start(1000); // Update every 100 milliseconds
 ui->tabWidget->setCurrentIndex(7);

 power.powerOn=false;
// power.buttonState="OFF";
 power.powerOn1=false;
// power.buttonstate1="OFF";
 power.powerOn2=false;
 power.buttonstate2="OFF";
 power.powerOn3=false;
 power.buttonstate3="OFF";
 power.powerOn4=false;
 power.buttonstate4="OFF";

      QTimer *timerdia=new QTimer;
     // connect(timerdia,&QTimer::timeout,this,&MainWindow::updatedialine);
     // timerdia->start(100);
      // Initialize the selection to the first button/tab
      //updateButtonSelection(ButtonIndex);
      connect(ui->SETTINGS_BUT_2,&QPushButton::clicked,this,&MainWindow::on_pushButton_4_clicked);

 messageline=new QMessageBox;
 for (int i = 0; i < 7; ++i) {
      previousValue[i] = -1;
  }


   s=new settings;
   //r=new Reset;
 //  p=new prime;
   key=new keypad;
   timer = new QTimer;
   timermsg=new QTimer;
   message = new QMessageBox;
   footsensor=new QTimer;
   lfoot=new footlib;
//   hard=new hhandler;
   protimer=new QTimer;

       // Set the initial state of pushButton_9

   QTimer *timerfoot = new QTimer;
   timer43=new QTimer;
   QTimer *ftime=new QTimer;

  footpedalcheck();

   connect(timerfoot, &QTimer::timeout, this, &MainWindow::updatesensor);
      timerfoot->start(100); // 100 milliseconds interval
      sensortimer = new QTimer(this);
      connect(sensortimer, SIGNAL(timeout()), this, SLOT(sensor2()));
      sensortimer->start(100); // Update labels every 1000 milliseconds (1 second)
   ui->lineEdit_57->setText("100");
   QString styleSheet = "QPushButton {"
                                "    font-family: Ubuntu;"
                                "    font-size: 20pt;"
                                "    background-color: white;"
           "width:81;"
           "height:81;"
                                "color:black;"
                                "    border-radius: 20px;" // Adjust the radius as needed
                                "}";

   exportGPIO(960);
   setGPIODirection("in",960);
   exportGPIO(961);
     setGPIODirection("in",961);

   // Update status initially
   updatehandpieceStatus();



   // Setup a timer to periodically update the status
   statusUpdateTimer = new QTimer(this);
   connect(statusUpdateTimer, &QTimer::timeout, this, &MainWindow::onUpdateStatusTimeout);
   statusUpdateTimer->start(500); // Update every second
   //lineedit value givennnnn
//us1
  ui->lineEdit_58->setText("100");
  ui->lineEdit_55->setText("500");
  ui->lineEdit_56->setText("40");
  //us2
  ui->lineEdit_58->setText("100");
  ui->lineEdit_60->setText("500");
  ui->lineEdit_59->setText("40");
  //us3
  ui->lineEdit_61->setText("100");
  ui->lineEdit_63->setText("500");
  ui->lineEdit_62->setText("40");
  //us4
  ui->lineEdit_64->setText("100");
  ui->lineEdit_66->setText("500");
  ui->lineEdit_65->setText("40");
  //ia1
 // ui->lineEdit_58->setText("100");
  ui->lineEdit_70->setText("500");
  ui->lineEdit_69->setText("40");
  //ia2
  //ui->lineEdit_58->setText("100");
  ui->lineEdit_68->setText("500");
  ui->lineEdit_67->setText("40");
  //vit
  ui->lineEdit_71->setText("960");
  ui->lineEdit_73->setText("500");
  ui->lineEdit_72->setText("40");
  //dia
 ui->lineEdit_74->setText("100");
//timmer for usermessage
   connect(timer,&QTimer::timeout,[=]()
   {
       message->close();

       timer->stop();

   });
   //itmer for updateline edit
   connect(timermsg, &QTimer::timeout, [=]()
   {
       messageline->hide(); // Initially hide the message line
        timermsg->stop();

   });


 // keypad connetion
   connect(key,&keypad::textsignal,this,&MainWindow::on_clicked);
   connect(key,&keypad::entersignal,this,&MainWindow::on_clickedenter);
   connect(protimer,&QTimer::timeout,this,&MainWindow::footpedalcheck);
   protimer->start(50);
   connect(foot, &footpedal::moveTopToBottom, this, &MainWindow::movePushButtonTopToBottom);
   connect(foot, &footpedal::moveBottomToTop, this, &MainWindow::movePushButtonBottomToTop);
  connect(foot,&footpedal::performReflux,this,&MainWindow::footreflux);
  connect(foot,&footpedal::togglePower,this,&MainWindow::poweron);
  connect(foot,&footpedal::continous_irrigation,this,&MainWindow::continousirrigation);
  connect(foot,&footpedal::powerdm,this,&MainWindow::powerdeliverymethod);



//tabwidget current index selected
   ui->tabWidget->setTabText(6, "VITRECTOMY");
   QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; }";
//tab name
    ui-> tabWidget->setStyleSheet(tabStyle);
   ui->tabWidget->setTabText(0, "ULTRASONIC 1");
   ui->tabWidget->setTabText(1, "ULTRASONIC 2");
   ui->tabWidget->setTabText(2, "ULTRASONIC 3");
   ui->tabWidget->setTabText(3, "ULTRASONIC 4");
   ui->tabWidget->setTabText(4, "IRRIGATION ASPIRATION 1");
   ui->tabWidget->setTabText(5, "IRRIGATION ASPIRATION 2");

   ui->tabWidget->setTabText(7, "DIATHERMY");
   ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
          QFont font("Ubuntu", 20, QFont::Bold);

              // Set the font for the QPushButton
    ui->ULTRASONICBUT1->setFont(font);
    ui->ULTRASONICBUT2->setFont(font);
    ui->ULTRASONICBUT3->setFont(font);
    ui->ULTRASONICBUT4->setFont(font);
    ui->IA1BUT->setFont(font);
    ui->IA2BUT->setFont(font);
    ui->VITRECTOMYBUT->setFont(font);
    ui->DIABUT->setFont(font);

   //US1
   ui->lineEdit_57->installEventFilter(this);
   ui->lineEdit_55->installEventFilter(this);
   ui->lineEdit_56->installEventFilter(this);
   //US 2
    ui->lineEdit_58->installEventFilter(this);
    ui->lineEdit_60->installEventFilter(this);
    ui->lineEdit_59->installEventFilter(this);
    //US 3
    ui->lineEdit_61->installEventFilter(this);
    ui->lineEdit_63->installEventFilter(this);
    ui->lineEdit_62->installEventFilter(this);
    //US 4
    ui->lineEdit_64->installEventFilter(this);
    ui->lineEdit_66->installEventFilter(this);
    ui->lineEdit_65->installEventFilter(this);
    //IA1
    ui->lineEdit_70->installEventFilter(this);
    ui->lineEdit_69->installEventFilter(this);
    //IA 2
    ui->lineEdit_68->installEventFilter(this);
    ui->lineEdit_67->installEventFilter(this);
    //VIT
    ui->lineEdit_71->installEventFilter(this);
    ui->lineEdit_73->installEventFilter(this);
    ui->lineEdit_72->installEventFilter(this);
    //DIA
    ui->lineEdit_74->installEventFilter(this);
    ui->lineEdit_57->setMaxLength(3);







    connect(in, &doctor::comboBox1Changed, this, &MainWindow::updateComboBox1);
    connect(in, &doctor::comboBox2Changed, this, &MainWindow::updateComboBox2);
    connect(in, &doctor::comboBox3Changed, this, &MainWindow::updateComboBox3);
      connect(in, &doctor::comboBox4Changed, this, &MainWindow::updateComboBox4);

    connect(ui->comboBox_4, &QComboBox::currentTextChanged, this, &MainWindow::onSurgeonChanged);
    connect(in, &doctor::valuesUpdated, this, &MainWindow::updateValues);





//ui->lineEdit_27->setText("40");
 //connect(ui->lineEdit_6,&QLineEdit::editingFinished,this,&MainWindow::powervit);
 // connect(ui->lineEdit_6,&QLineEdit::editingFinished,this,&MainWindow::powervit);
  connect(ui->CutMode_vitCom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged);
  connect(ui->CutMode_vitCom_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged1);
connect(ui->CutMode_vitCom_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged2);
connect(ui->CutMode_vitCom_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged3);
  int currenttab=7;
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::current);
    //ui->DIABUT->setFocus();
    //ui->tabWidget->setCurrentIndex(7);
    //ui->tabWidget->setCurrentWidget(ui->tab_7);
  //  ui->DIABUT->installEventFilter(this);
   // QTimer::singleShot(0, ui->DIABUT, &QPushButton::setFocus);
         current(currenttab);
         //lineedit value change connection
      // connect(ui->lineEdit_7,&QLineEdit::textChanged,this,&MainWindow::onMainLineEditTextChanged);

       //   connect(&updateTimer, &QTimer::timeout, this, &MainWindow::update);
   QRegExp regex3("^(?:100|[1-9]\\d?|0)$");
   // QRegExpValidator* validator3 = new QRegExpValidator(regex3, ui->lineEdit);
   // ui->lineEdit_57->setValidator(validator3);
    ui->lineEdit_57->setMaxLength(3);
    //name chnage connection
      connect(ui->ULTRASONICBUT1,&QPushButton::clicked,this,&MainWindow::ULTRASONICBUT1);
      connect(ui->ULTRASONICBUT2,&QPushButton::clicked,this,&MainWindow::ULTRASONICBUT2);
      connect(ui->ULTRASONICBUT3,&QPushButton::clicked,this,&MainWindow::ULTRASONICBUT3);
      connect(ui->ULTRASONICBUT4,&QPushButton::clicked,this,&MainWindow::ULTRASONICBUT4);
      connect(ui->IA1BUT,&QPushButton::clicked,this,&MainWindow::IRRIGATIONBUT1);
      connect(ui->IA2BUT,&QPushButton::clicked,this,&MainWindow::IRRIGATIONBUT2);
      connect(ui->VITRECTOMYBUT,&QPushButton::clicked,this,&MainWindow::VITRECTOMYBUT);
      connect(ui->DIABUT,&QPushButton::clicked,this,&MainWindow::DIATHERMYBUT);
      connect(ui->us1powup_but,&QPushButton::clicked,this,&MainWindow::US1POWUP);
      connect(ui->us1powdown_but,&QPushButton::clicked,this,&MainWindow::US1POWDOWN);
      connect(ui->us1vacdow_but,&QPushButton::clicked,this,&MainWindow::US1VACDOWN);
      connect(ui->us1vacup_but,&QPushButton::clicked,this,&MainWindow::US1VACUP);
      connect(ui->us1flowdown_but,&QPushButton::clicked,this,&MainWindow::US1FLOWDOWN);
      connect(ui->us1flowup_but,&QPushButton::clicked,this,&MainWindow::US1FLOWUP);
      connect(ui->BACKBUT,&QPushButton::clicked,this,&MainWindow::BACKBUT);
  //  connect(ui->SETTINGS_BUT,&QPushButton::clicked,this,&MainWindow::SETTINGSBUT);
      //us2
      connect(ui->us2powup_but,&QPushButton::clicked,this,&MainWindow::us2powup);
      connect(ui->us2powdown_but,&QPushButton::clicked,this,&MainWindow::us2powdown);
      connect(ui->us2vacdown_but,&QPushButton::clicked,this,&MainWindow::us2vacdown);
      connect(ui->us2vacup_but,&QPushButton::clicked,this,&MainWindow::us2vacup);
      connect(ui->us2flowdown_but,&QPushButton::clicked,this,&MainWindow::us2flowdown);
      connect(ui->us2flowup_but,&QPushButton::clicked,this,&MainWindow::us2flowup);
      //us3
      connect(ui->us3powup_but,&QPushButton::clicked,this,&MainWindow::us3powup);
      connect(ui->us3powdown_but,&QPushButton::clicked,this,&MainWindow::us3powdown);
      connect(ui->us3vacdown_but,&QPushButton::clicked,this,&MainWindow::us3vacdown);
      connect(ui->us3vacup_but,&QPushButton::clicked,this,&MainWindow::us3vacup);
      connect(ui->us3flowdown_but,&QPushButton::clicked,this,&MainWindow::us3flowdown);
      connect(ui->us3flowup_but,&QPushButton::clicked,this,&MainWindow::us3flowup);
      //us4
      connect(ui->us4powup_but,&QPushButton::clicked,this,&MainWindow::us4powup);
      connect(ui->us4powdown_but,&QPushButton::clicked,this,&MainWindow::us4powdown);
      connect(ui->us4vacup_but,&QPushButton::clicked,this,&MainWindow::us4vacup);
      connect(ui->us4vacdown_but,&QPushButton::clicked,this,&MainWindow::us4vacdown);
      connect(ui->us4flowup_but,&QPushButton::clicked,this,&MainWindow::us4flowup);
      connect(ui->us4flowdown_but,&QPushButton::clicked,this,&MainWindow::us4flowdown);
      //ia
      connect(ui->ia1vacup_but,&QPushButton::clicked,this,&MainWindow::ia1vacup);
      connect(ui->ia1vacdown_but,&QPushButton::clicked,this,&MainWindow::ia1vacdown);
      connect(ui->ia1flowup_but,&QPushButton::clicked,this,&MainWindow::ia1flowup);
      connect(ui->ia1flowdown_but,&QPushButton::clicked,this,&MainWindow::ia1flowdown);
      //ia2
      connect(ui->ia2vacup_but,&QPushButton::clicked,this,&MainWindow::ia2vacup);
      connect(ui->ia2vacdown_but,&QPushButton::clicked,this,&MainWindow::ia2vacdown);
      connect(ui->ia2flowup_but,&QPushButton::clicked,this,&MainWindow::ia2flowup);
      connect(ui->ia2flowdown_but,&QPushButton::clicked,this,&MainWindow::ia2flowdown);
      //vit
      connect(ui->vitpowup_but,&QPushButton::clicked,this,&MainWindow::vitcutup);
      connect(ui->vitpowdown_but,&QPushButton::clicked,this,&MainWindow::vitcutdown);
      connect(ui->vitvacup_but,&QPushButton::clicked,this,&MainWindow::vitvacup);
      connect(ui->vitvacdown_but,&QPushButton::clicked,this,&MainWindow::vitvacdown);
      connect(ui->vitflowup_but,&QPushButton::clicked,this,&MainWindow::vitflowup);
      connect(ui->vitflowdown_but,&QPushButton::clicked,this,&MainWindow::vitflowdown);
//dia
      connect(ui->diapowup_but,&QPushButton::clicked,this,&MainWindow::diapowup);
      connect(ui->diapowdown_but,&QPushButton::clicked,this,&MainWindow::diapowdown);



     //mode
     connect(ui->us1mode,&QPushButton::clicked,this,&MainWindow::us1_linear_nonlinear);
     connect(ui->us2mode,&QPushButton::clicked,this,&MainWindow::us2_linear_nonlinear);
     connect(ui->us3mode,&QPushButton::clicked,this,&MainWindow::us3_linear_nonlinear);
     connect(ui->us4mode,&QPushButton::clicked,this,&MainWindow::us4_linear_nonlinear);
     connect(ui->ia1mode,&QPushButton::clicked,this,&MainWindow::ia1_linear_nonlinear);
     connect(ui->ia2mode,&QPushButton::clicked,this,&MainWindow::ia2_linear_nonlinear);
     connect(ui->vitmode,&QPushButton::clicked,this,&MainWindow::vit_linear_nonlinear);

//      connect(ui->ULTRASONICBUT1, &QPushButton::clicked, [=](){
//          ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
//                });
//      connect(ui->ULTRASONICBUT2, &QPushButton::clicked, [=](){
//          ui->ULTRASONICBUT2->setStyleSheet(styleSheet);
//      });
//      connect(ui->ULTRASONICBUT4, &QPushButton::clicked, [=](){
//          ui->ULTRASONICBUT4->setStyleSheet(styleSheet);
//      });
//      connect(ui->ULTRASONICBUT3, &QPushButton::clicked, [=](){
//          ui->ULTRASONICBUT3->setStyleSheet(styleSheet);
//      });
//      connect(ui->IA1BUT, &QPushButton::clicked, [=](){
//          ui->IA1BUT->setStyleSheet(styleSheet);
//      });
//      connect(ui->IA2BUT, &QPushButton::clicked, [=](){
//          ui->IA2BUT->setStyleSheet(styleSheet);
//      });
//      connect(ui->VITRECTOMYBUT, &QPushButton::clicked, [=](){
//          ui->VITRECTOMYBUT->setStyleSheet(styleSheet);
//      });
//     connect(ui->DIABUT, &QPushButton::clicked, [=](){
//         ui->DIABUT->setStyleSheet(styleSheet);
//     });
     connect(ui->tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(changeButtonColor(int)));
     us1_linear_nonlinear();
     us2_linear_nonlinear();
     us3_linear_nonlinear();
     us4_linear_nonlinear();
     ia1_linear_nonlinear();
     ia2_linear_nonlinear();
     vit_linear_nonlinear();

    // connect(foot, &footpedal::cs, this, &MainWindow::settings_action);
}
//pushbutton pushbutton
void MainWindow::click()
{
   QString styleSheet = "QPushButton {"
                                "    font-family: Ubuntu;"
                                "    font-size: 20pt;"
           "width:81;"
           "height:81;"
           "color: rgb(255, 255, 255);"
           "background-color: rgb(0, 0, 0);"
                                "    border-radius: 40px;" // Adjust the radius as needed
                                "}";
  ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
   ui->ULTRASONICBUT2->setStyleSheet(styleSheet);
   ui->ULTRASONICBUT3->setStyleSheet(styleSheet);
   ui->ULTRASONICBUT4->setStyleSheet(styleSheet);
   ui->IA2BUT->setStyleSheet(styleSheet);
   ui->IA2BUT->setStyleSheet(styleSheet);
   ui->VITRECTOMYBUT->setStyleSheet(styleSheet);
   ui->DIABUT->setStyleSheet(styleSheet);
}
//elapsed time

void MainWindow::updateElapsedTime()
{
   if (timer5.isValid()) {
       qint64 elapsed = timer5.elapsed();
       QString elapsedTimeStr = QString::number(elapsed) + " ms";
       ui->elapsed_time->setText(elapsedTimeStr);
   }
}
//button color unwanted
void MainWindow::changeButtonColor(int tabIndex) {

   if (tabIndex!=0) {
       ui->ULTRASONICBUT1->setStyleSheet("");
 ui->ULTRASONICBUT1->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }
   if(tabIndex!=1)
   {
       ui->ULTRASONICBUT2->setStyleSheet("");
         ui->ULTRASONICBUT2->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }
   if(tabIndex!=2){
       ui->ULTRASONICBUT3->setStyleSheet("");
         ui->ULTRASONICBUT3->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }
   if(tabIndex!=3){
   ui->ULTRASONICBUT4->setStyleSheet("");
     ui->ULTRASONICBUT4->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }
   if(tabIndex!=4){
   ui->IA1BUT->setStyleSheet("");
     ui->IA1BUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }           //empty color
   if(tabIndex!=5){
   ui->IA2BUT->setStyleSheet("");
     ui->IA2BUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }
   if(tabIndex!=6){
   ui->VITRECTOMYBUT->setStyleSheet("");
     ui->VITRECTOMYBUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }
   if(tabIndex!=7){
   ui->DIABUT->setStyleSheet("");
     ui->DIABUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
   }


       if (tabIndex == 0) {
       ui->ULTRASONICBUT1->setStyleSheet("border-radius: 20px;background-color: green;");
       } else if (tabIndex == 1) {
        ui->ULTRASONICBUT2 ->setStyleSheet("border-radius: 20px;background-color: green;");
       }                                                                      //set color
       else if(tabIndex==2){
            ui->ULTRASONICBUT3->setStyleSheet("border-radius: 20px;background-color: green;");
       }
       else if(tabIndex==3){
            ui->ULTRASONICBUT4->setStyleSheet("border-radius: 20px;background-color: green;");
       }
       else if(tabIndex==4){
            ui->IA1BUT->setStyleSheet("border-radius: 20px;background-color: green;");
       }
       else if(tabIndex==5){
            ui->IA2BUT->setStyleSheet("border-radius: 20px;background-color: green;");
       }
       else if(tabIndex==6){
            ui->VITRECTOMYBUT->setStyleSheet("border-radius: 20px;background-color: green;");
       }
       else if(tabIndex==7){
            ui->DIABUT->setStyleSheet("border-radius: 20px;background-color: green;");
       }

         //ui->DIABUT->click();
        // emit ui->DIABUT->clicked();
   }
MainWindow::~MainWindow()
{
   delete ui;
}
void MainWindow::userMessage(int value, int minValue, int maxValue)
{
   QString msg( "Value must be between " + QString::number(minValue) + " and " + QString::number(maxValue));
   if(value > maxValue)
   {
       message->setText(msg);
       message->show();

   }
timer->start(3000);
}
void MainWindow::updateLineedit(QLineEdit *lineEdit, int prevValue, int value, int maxValue) {
   if (value > maxValue) {
        lineEdit->setText(QString::number(prevValue));
        messageline->setText(QString("Value must be between 0 and %1.").arg(maxValue));
        messageline->show();
        timermsg->start(1000); // Start the timer for 3000ms
    } else {
        lineEdit->setText(QString::number(value));
        if (messageline->isVisible()) {
            messageline->close();  // Close the message if it is open
                // Stop the timer if it is running
        }
    }
}

//keypad settings
bool MainWindow::eventFilter(QObject* object, QEvent* event)
{
     if(object == ui->lineEdit_57 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_57->setFocus();
           ui->lineEdit_55->clearFocus();
           ui->lineEdit_56->clearFocus();
           ui->lineEdit_57->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }
     if(object == ui->lineEdit_55 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_55->setFocus();
           ui->lineEdit_57->clearFocus();
           ui->lineEdit_56->clearFocus();
           ui->lineEdit_55->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }

     if(object == ui->lineEdit_56 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_56->setFocus();
           ui->lineEdit_57->clearFocus();
           ui->lineEdit_55->clearFocus();
           ui->lineEdit_56->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }//ULTRASONIC 2
     if(object == ui->lineEdit_58 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_58->setFocus();
           ui->lineEdit_60->clearFocus();
           ui->lineEdit_59->clearFocus();
           ui->lineEdit_58->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }
     if(object == ui->lineEdit_60 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_60->setFocus();
           ui->lineEdit_58->clearFocus();
           ui->lineEdit_59->clearFocus();
           ui->lineEdit_60->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }

     if(object == ui->lineEdit_59 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_59->setFocus();
           ui->lineEdit_58->clearFocus();
           ui->lineEdit_60->clearFocus();
           ui->lineEdit_59->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }
     //ULTRASONIC 3
     if(object == ui->lineEdit_61 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_61->setFocus();
           ui->lineEdit_63->clearFocus();
           ui->lineEdit_62->clearFocus();
           ui->lineEdit_61->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }
     if(object == ui->lineEdit_63 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_63->setFocus();
           ui->lineEdit_61->clearFocus();
           ui->lineEdit_62->clearFocus();
           ui->lineEdit_63->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
 }

     if(object == ui->lineEdit_62 && event->type() == QEvent::MouseButtonPress) {
       QMouseEvent *k = static_cast<QMouseEvent *> (event);
       if( k->button() == Qt::LeftButton ) {
           key->resize(481,301);
           key->move(280,320);
           key->show();
           ui->lineEdit_62->setFocus();
           ui->lineEdit_61->clearFocus();
           ui->lineEdit_63->clearFocus();
           ui->lineEdit_62->setText("");

       } else if ( k->button() == Qt::RightButton ) {
       }
     }
       //ULTRASONIC 4
       if(object == ui->lineEdit_64 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_64->setFocus();
             ui->lineEdit_66->clearFocus();
             ui->lineEdit_65->clearFocus();
             ui->lineEdit_64->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       if(object == ui->lineEdit_66 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_66->setFocus();
             ui->lineEdit_64->clearFocus();
             ui->lineEdit_65->clearFocus();
             ui->lineEdit_66->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }

       if(object == ui->lineEdit_65 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_65->setFocus();
             ui->lineEdit_64->clearFocus();
             ui->lineEdit_66->clearFocus();
             ui->lineEdit_65->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
       }
         //IRRIGATION/ASPIRATION 1
       if(object == ui->lineEdit_70 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_70->setFocus();
             ui->lineEdit_69->clearFocus();
            // ui->lineEdit_56->clearFocus();
             ui->lineEdit_70->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       if(object == ui->lineEdit_69 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_69->setFocus();
             ui->lineEdit_70->clearFocus();
             //ui->lineEdit_56->clearFocus();
             ui->lineEdit_69->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       //IRRIGATION/ASPIRATION 2
       if(object == ui->lineEdit_68 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_68->setFocus();
             ui->lineEdit_67->clearFocus();
             //ui->lineEdit_56->clearFocus();
             ui->lineEdit_68->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       if(object == ui->lineEdit_67 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_67->setFocus();
             ui->lineEdit_68->clearFocus();
             //ui->lineEdit_56->clearFocus();
             ui->lineEdit_67->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       //VITRECTOMY

       if(object == ui->lineEdit_71 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->close();
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_71->setFocus();
             ui->lineEdit_73->clearFocus();
             ui->lineEdit_72->clearFocus();
             ui->lineEdit_71->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       if(object == ui->lineEdit_73 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
              key->close();
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_73->setFocus();
             ui->lineEdit_72->clearFocus();
             ui->lineEdit_71->clearFocus();
             ui->lineEdit_73->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
       if(object == ui->lineEdit_72 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
              key->close();
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_72->setFocus();
             ui->lineEdit_73->clearFocus();
             ui->lineEdit_71->clearFocus();
             ui->lineEdit_72->setText("");

         } else if ( k->button() == Qt::RightButton ) {
         }
   }
 //DIATHERMY
       if(object == ui->lineEdit_74 && event->type() == QEvent::MouseButtonPress) {
         QMouseEvent *k = static_cast<QMouseEvent *> (event);
         if( k->button() == Qt::LeftButton ) {
             key->close();
             key->resize(481,301);
             key->move(280,320);
             key->show();
             ui->lineEdit_74->setFocus();
//              ui->lineEdit_57->clearFocus();
//              ui->lineEdit_55->clearFocus();
             ui->lineEdit_74->setText("");


         } else if ( k->button() == Qt::RightButton ) {
         }
   }
 return false;
}
//keypad entered value
void MainWindow::on_clicked(const QString& digit)
{//ULTRASONIC 1

 if(ui->lineEdit_57->focusWidget()) {
     ui->lineEdit_55->clearFocus();
     ui->lineEdit_56->clearFocus();
     ui->lineEdit_57->setFocus();
     int prevValue = ui->lineEdit_57->text().toInt();
     int value = (ui->lineEdit_57->text()+digit).toInt();
     setRange(ui->lineEdit_57, prevValue, value, 100);
    updateLineedit(ui->lineEdit_57, prevValue, value, 100);
    increasebutton(ui->lineEdit_57);
 }
 if(ui->lineEdit_55->focusWidget()) {
     ui->lineEdit_56->clearFocus();
     ui->lineEdit_57->clearFocus();
     ui->lineEdit_55->setFocus();
     int prevValue = ui->lineEdit_55->text().toInt();
     int value = (ui->lineEdit_55->text()+digit).toInt();
     setRange(ui->lineEdit_55, prevValue, value, 500);
     updateLineedit(ui->lineEdit_55, prevValue, value, 500);
     vacbutton(ui->lineEdit_55);
 }
 if(ui->lineEdit_56->focusWidget()) {
     ui->lineEdit_55->clearFocus();
     ui->lineEdit_57->clearFocus();
     ui->lineEdit_56->setFocus();
     int prevValue = ui->lineEdit_56->text().toInt();
     int value = (ui->lineEdit_56->text()+digit).toInt();
     setRange(ui->lineEdit_56, prevValue, value, 40);
  updateLineedit(ui->lineEdit_56, prevValue, value, 40);
  decreasebutton(ui->lineEdit_56);
 }
 //ULTRASONIC 2
  if(ui->lineEdit_58->focusWidget()) {
     ui->lineEdit_60->clearFocus();
     ui->lineEdit_59->clearFocus();
     ui->lineEdit_58->setFocus();
     int prevValue = ui->lineEdit_58->text().toInt();
     int value = (ui->lineEdit_58->text()+digit).toInt();

     setRange(ui->lineEdit_58, prevValue, value, 100);
    updateLineedit(ui->lineEdit_58, prevValue, value, 100);
    increasebutton(ui->lineEdit_58);
 }
  if(ui->lineEdit_60->focusWidget()) {
     ui->lineEdit_58->clearFocus();
     ui->lineEdit_59->clearFocus();
     ui->lineEdit_60->setFocus();
     int prevValue = ui->lineEdit_60->text().toInt();
     int value =( ui->lineEdit_60->text()+digit).toInt();

     setRange(ui->lineEdit_60, prevValue, value, 500);
     updateLineedit(ui->lineEdit_60, prevValue, value, 500);
     vacbutton(ui->lineEdit_60);
 }
  if(ui->lineEdit_59->focusWidget()) {
     ui->lineEdit_58->clearFocus();
     ui->lineEdit_60->clearFocus();
     ui->lineEdit_59->setFocus();
     int prevValue = ui->lineEdit_59->text().toInt();
     int value = (ui->lineEdit_59->text()+digit).toInt();
     setRange(ui->lineEdit_59, prevValue, value, 40);
     updateLineedit(ui->lineEdit_59, prevValue, value, 40);
     decreasebutton(ui->lineEdit_59);
 }
 //ULTRASONIC 3
  if(ui->lineEdit_61->focusWidget()) {
     ui->lineEdit_63->clearFocus();
     ui->lineEdit_62->clearFocus();
     ui->lineEdit_61->setFocus();
     int prevValue= ui->lineEdit_61->text().toInt();
     int value = (ui->lineEdit_61->text()+digit).toInt();
     setRange(ui->lineEdit_61, prevValue, value, 100);
     updateLineedit(ui->lineEdit_61, prevValue, value, 100);
    // userMessage(value2,5,100);
     increasebutton(ui->lineEdit_61);

 }
 if(ui->lineEdit_63->focusWidget()) {
     ui->lineEdit_61->clearFocus();
     ui->lineEdit_62->clearFocus();
     ui->lineEdit_63->setFocus();
     int prevValue = ui->lineEdit_63->text().toInt();
     int value = (ui->lineEdit_63->text()+digit).toInt();
     setRange(ui->lineEdit_63, prevValue, value, 500);
      updateLineedit(ui->lineEdit_63, prevValue, value, 500);
   //  userMessage(value2,5,500);
      vacbutton(ui->lineEdit_63);

 }
else if(ui->lineEdit_62->focusWidget()) {
     ui->lineEdit_61->clearFocus();
     ui->lineEdit_63->clearFocus();
     ui->lineEdit_62->setFocus();
     int prevValue = ui->lineEdit_62->text().toInt();
     int value = (ui->lineEdit_62->text()+digit).toInt();
     setRange(ui->lineEdit_62, prevValue, value, 40);
      updateLineedit(ui->lineEdit_62, prevValue, value, 40);
    // userMessage(value,2,40);
      decreasebutton(ui->lineEdit_62);
 }
 //ULTRASONIC 4
  if(ui->lineEdit_64->focusWidget()) {
     ui->lineEdit_66->clearFocus();
     ui->lineEdit_65->clearFocus();
     ui->lineEdit_64->setFocus();
     int prevValue = ui->lineEdit_64->text().toInt();
     int value = (ui->lineEdit_64->text()+digit).toInt();
     setRange(ui->lineEdit_64, prevValue, value, 100);
      updateLineedit(ui->lineEdit_64, prevValue, value, 100);
    // userMessage(value,5,100);
      increasebutton(ui->lineEdit_64);

 }
 if(ui->lineEdit_66->focusWidget()) {
     ui->lineEdit_65->clearFocus();
     ui->lineEdit_64->clearFocus();
     ui->lineEdit_66->setFocus();
     int prevValue = ui->lineEdit_66->text().toInt();
     int value = (ui->lineEdit_66->text()+digit).toInt();
     setRange(ui->lineEdit_66, prevValue, value, 500);
      updateLineedit(ui->lineEdit_66, prevValue, value, 500);
    // userMessage(value,5,500);
      vacbutton(ui->lineEdit_66);
 }
 if(ui->lineEdit_65->focusWidget()) {
     ui->lineEdit_64->clearFocus();
     ui->lineEdit_66->clearFocus();
     ui->lineEdit_65->setFocus();
     int prevValue = ui->lineEdit_65->text().toInt();
     int value = (ui->lineEdit_65->text()+digit).toInt();
     setRange(ui->lineEdit_65, prevValue, value, 40);
      updateLineedit(ui->lineEdit_65, prevValue, value, 40);
    // userMessage(value,2,40);
      decreasebutton(ui->lineEdit_65);
  }
 //IRRIGATION/ASPIRATION 1
 if(ui->lineEdit_70->focusWidget()) {
     ui->lineEdit_69->clearFocus();
     //ui->lineEdit_56->clearFocus();
     ui->lineEdit_70->setFocus();
     int prevValue = ui->lineEdit_70->text().toInt();
     int value = (ui->lineEdit_70->text()+digit).toInt();
     setRange(ui->lineEdit_70, prevValue, value, 500);
      updateLineedit(ui->lineEdit_70, prevValue, value, 500);
  //   userMessage(value,5,500);
      vacbutton(ui->lineEdit_70);
 }
 if(ui->lineEdit_69->focusWidget()) {
     ui->lineEdit_70->clearFocus();
     //ui->lineEdit_57->clearFocus();
     ui->lineEdit_69->setFocus();
     int prevValue = ui->lineEdit_69->text().toInt();
     int value = (ui->lineEdit_69->text()+digit).toInt();
     setRange(ui->lineEdit_69, prevValue, value, 40);
      updateLineedit(ui->lineEdit_69, prevValue, value, 40);
    // userMessage(value,2,40);
      decreasebutton(ui->lineEdit_69);
 }
 //IRRIGATION/ASPIRATION 2
  if(ui->lineEdit_68->focusWidget()) {
     ui->lineEdit_67->clearFocus();
     //ui->lineEdit_56->clearFocus();
     ui->lineEdit_68->setFocus();
     int prevValue = ui->lineEdit_68->text().toInt();
     int value = (ui->lineEdit_68->text()+digit).toInt();
     setRange(ui->lineEdit_68, prevValue, value, 500);
      updateLineedit(ui->lineEdit_68, prevValue, value, 500);
   //  userMessage(value,5,500);
      vacbutton(ui->lineEdit_68);

 }
  if(ui->lineEdit_67->focusWidget()) {
     ui->lineEdit_68->clearFocus();
     //ui->lineEdit_57->clearFocus();
     ui->lineEdit_67->setFocus();
     int prevValue = ui->lineEdit_67->text().toInt();
     int value = (ui->lineEdit_67->text()+digit).toInt();
     setRange(ui->lineEdit_67, prevValue, value, 40);
      updateLineedit(ui->lineEdit_67, prevValue, value, 40);
  //   userMessage(value,2,40);
         decreasebutton(ui->lineEdit_67);
 }
 //VITRECTOMY
  if(ui->lineEdit_71->focusWidget()) {
     ui->lineEdit_73->clearFocus();
     ui->lineEdit_72->clearFocus();
     ui->lineEdit_71->setFocus();
     int prevValue = ui->lineEdit_71->text().toInt();
     int value = (ui->lineEdit_71->text()+digit).toInt();
     setRange(ui->lineEdit_71, prevValue, value, 960);
      updateLineedit(ui->lineEdit_71, prevValue, value, 960);
// powervit();
  //   userMessage(value,60,960);

 }
  if(ui->lineEdit_73->focusWidget()) {
     ui->lineEdit_71->clearFocus();
     ui->lineEdit_72->clearFocus();
     ui->lineEdit_73->setFocus();
     int prevValue = ui->lineEdit_73->text().toInt();
     int value = (ui->lineEdit_73->text()+digit).toInt();
     setRange(ui->lineEdit_73, prevValue, value, 500);
      updateLineedit(ui->lineEdit_73, prevValue, value, 500);
      vacbutton(ui->lineEdit_73);
   //  userMessage(value,5,500);

 }
 if(ui->lineEdit_72->focusWidget()) {
     ui->lineEdit_71->clearFocus();
     ui->lineEdit_73->clearFocus();
     ui->lineEdit_72->setFocus();
     int prevValue = ui->lineEdit_72->text().toInt();
     int value = (ui->lineEdit_72->text()+digit).toInt();
     setRange(ui->lineEdit_72, prevValue, value, 40);
      updateLineedit(ui->lineEdit_72, prevValue, value, 40);
      decreasebutton(ui->lineEdit_72);
   //  userMessage(value,2,40);

 }
 //DIATHERMY
  if(ui->lineEdit_74->focusWidget()) {
//      ui->lineEdit_55->clearFocus();
//      ui->lineEdit_57->clearFocus();
     ui->lineEdit_74->setFocus();
     int prevValue = ui->lineEdit_74->text().toInt();
     int value = (ui->lineEdit_74->text()+digit).toInt();
     setRange(ui->lineEdit_74, prevValue, value, 100);
      updateLineedit(ui->lineEdit_74, prevValue, value, 100);
    // userMessage(value,5,100);
      increasebutton(ui->lineEdit_74);
 }
}

void MainWindow::on_clickedenter()
{
  key->hide();
  int  input=ui->lineEdit_71->text().toInt();
  int output=getvalue(input);
  ui->lineEdit_71->setText(QString::number(output));
}
void MainWindow::ULTRASONICBUT1()
{
   ui->tabWidget->setCurrentIndex(0);
   QString currentText = ui->CutMode_vitCom->currentText();

   updateTabsBasedOnComboBox(currentText);


   //
//   click();
//ui->label_6->setStyleSheet("image: url(:/connected.png);");
  // ui->ULTRASONICBUT1->setStyleSheet("");
//   changeButtonColor(0);
   ui->CutMode_vit->show();
   ui->CutMode_vitCom->show();
   ui->tabWidget_2->show();
   butname=1;
}


void MainWindow::ULTRASONICBUT2()
{
   ui->tabWidget->setCurrentIndex(1);
  // ui->label_11->setText("ULTRASONIC 2");
 // click();
   QString currentText = ui->CutMode_vitCom_2->currentText();

   updateTabsBasedOnComboBox(currentText);

  // ui->ULTRASONICBUT2->setStyleSheet("");
  // changeButtonColor(1);
//

   ui->CutMode_vit->show();
   ui->CutMode_vitCom->show();
   ui->tabWidget_2->show();
   butname=2;
// footpedal();
}
void MainWindow::ULTRASONICBUT4()
{

   ui->tabWidget->setCurrentIndex(3);
   QString currentText = ui->CutMode_vitCom_4->currentText();

   updateTabsBasedOnComboBox(currentText);
   //click();

   // changeButtonColor(3);
    ui->CutMode_vit->show();
    ui->CutMode_vitCom->show();
    ui->tabWidget_2->show();
    butname=4;
 }

void MainWindow::IRRIGATIONBUT1()
{
   ui->tabWidget->setCurrentIndex(4);
  // ui->label_11->setText("IRRIGATION/ASPIRATION 1");
  // click();
   // changeButtonColor(4);
    ui->CutMode_vit->hide();
    ui->CutMode_vitCom->hide();
    ui->tabWidget_2->hide();
    butname=5;
}

void MainWindow::IRRIGATIONBUT2()
{
   ui->tabWidget->setCurrentIndex(5);
   //ui->label_11->setText("IRRIGATION/ASPIRATION 2");
//   click();
    //changeButtonColor(5);
    ui->CutMode_vit->hide();
    ui->CutMode_vitCom->hide();
    ui->tabWidget_2->hide();
    butname=6;
  }

void MainWindow::VITRECTOMYBUT()
{
   ui->tabWidget->setCurrentIndex(6);
  // ui->label_11->setText("VITRECTOMY");
  //click();
   //changeButtonColor(6);
   butname=7;

}

void MainWindow::DIATHERMYBUT()
{
 ui->tabWidget->setCurrentIndex(7);
   ui->CutMode_vit->hide();
   ui->CutMode_vitCom->hide();
   ui->tabWidget_2->hide();
   butname=0;

 //  click();
   current(7);
//changeButtonColor(7);
//dia();
}
void MainWindow::diapowup()
{
   int value=ui->lineEdit_74->text().toInt();
   value=value+5;
  //  userMessage(value,5,100);
   if(value > 100)
   {
       value=100;

   }
  // ui->progressBar_21->setValue(value);
  //  int roundedValue = std::round(lvalue / 5.0) * 5;
   ui->lineEdit_74->setText(QString::number(value));

}

void MainWindow::diapowdown()
{
   int value=ui->lineEdit_74->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
  // ui->progressBar_21->setValue(value);
 //   int roundedValue1 = std::round(lvalue / 5.0) * 5;
   ui->lineEdit_74->setText(QString::number(value));

}

void MainWindow::vitcutup()
{
  int value=ui->lineEdit_71->text().toInt();
   value=value+60;
    // userMessage(value,60,960);
   if(value > 960)
   {
       value=960;
   }
  // ui->progressBar_19->setValue(value);
   ui->lineEdit_71->setText(QString::number(value));
   //(value,60,960);

}

void MainWindow::vitcutdown()
{
   int value=ui->lineEdit_71->text().toInt();
   value=value-60;
   if(value < 60)
   {
       value=60;
   }
  // ui->progressBar_19->setValue(value);
   ui->lineEdit_71->setText(QString::number(value));

}

void MainWindow::vitvacup()
{
   int value=ui->lineEdit_73->text().toInt();
   value=value+5;
    // userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
  // ui->progressBar_18->setValue(value);
   ui->lineEdit_73->setText(QString::number(value));

}

void MainWindow::vitvacdown()
{
   int value=ui->lineEdit_73->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
  // ui->progressBar_18->setValue(value);
   ui->lineEdit_73->setText(QString::number(value));
}

void MainWindow::vitflowup()
{
  int value=ui->lineEdit_72->text().toInt();
   value=value+2;
     //userMessage(value,2,40);
   if(value > 40)
   {
       value=40;
   }
  // ui->progressBar_13->setValue(value);
   ui->lineEdit_72->setText(QString::number(value));


}

void MainWindow::vitflowdown()
{
  int value=ui->lineEdit_72->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }
 //  ui->progressBar_13->setValue(value);
   ui->lineEdit_72->setText(QString::number(value));

}

void MainWindow::ia2vacup()
{
  int  value=ui->lineEdit_68->text().toInt();
   value=value+5;
  // userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
 //  ui->progressBar_17->setValue(value);
   ui->lineEdit_68->setText(QString::number(value));


}

void MainWindow::ia2vacdown()
{
  int  value=ui->lineEdit_68->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
   //ui->progressBar_17->setValue(value);
   ui->lineEdit_68->setText(QString::number(value));

}

void MainWindow::ia2flowup()
{
 int value=ui->lineEdit_67->text().toInt();
   value=value+2;
  //userMessage(value,2,40);

   if(value > 40)
   {
       value=40;
   }
   //ui->progressBar_16->setValue(value);
   ui->lineEdit_67->setText(QString::number(value));

}

void MainWindow::ia2flowdown()
{
   int value=ui->lineEdit_67->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }
  // ui->progressBar_16->setValue(value);
   ui->lineEdit_67->setText(QString::number(value));
}

void MainWindow::ia1vacup()
{
  int value=ui->lineEdit_70->text().toInt();
   value=value+5;
    // userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
   //ui->progressBar_15->setValue(value);
   ui->lineEdit_70->setText(QString::number(value));
}

void MainWindow::ia1vacdown()
{
  int value=ui->lineEdit_70->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
   //ui->progressBar_15->setValue(value);
   ui->lineEdit_70->setText(QString::number(value));
}

void MainWindow::ia1flowup()
{
  int value=ui->lineEdit_69->text().toInt();
   value=value+2;
  // userMessage(value,2,40);
   if(value > 40)
   {
       value=40;
   }
  // ui->progressBar_14->setValue(value);
   ui->lineEdit_69->setText(QString::number(value));
}

void MainWindow::ia1flowdown()
{
  int value=ui->lineEdit_69->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }
  // ui->progressBar_14->setValue(value);
   ui->lineEdit_69->setText(QString::number(value));
}

void MainWindow::US1POWUP()
{
  int value=ui->lineEdit_57->text().toInt();
   value=value+5;
 //  userMessage(value,5,100);

   if(value > 100)
   {
       value=100;
   }
  // ui->progressBar->setValue(value);
   ui->label_7->setNum(value);

   ui->lineEdit_57->setText(QString::number(value));
}

void MainWindow::US1POWDOWN()
{
 int  value=ui->lineEdit_57->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
 //   ui->progressBar->setValue(value);
    ui->label_7->setNum(value);

   ui->lineEdit_57->setText(QString::number(value));
}

void MainWindow::US1VACUP()
{
 // int act=v->stabilize();
  //ui->progressBar_2->setValue(act);
 // ui->label_7->setNum(act);
   int value=ui->lineEdit_55->text().toInt();
   value=value+5;
   // userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
   // ui->progressBar_2->setValue(value);
   ui->lineEdit_55->setText(QString::number(value));
  // userMessage(value, 5, 500);
}

void MainWindow::US1VACDOWN()
{
   int value=ui->lineEdit_55->text().toInt();
   value=value-5;

   if(value < 5)
   {
       value=5;
   }
    //ui->progressBar_2->setValue(value);
   ui->lineEdit_55->setText(QString::number(value));
}

void MainWindow::US1FLOWUP()
{
  int value=ui->lineEdit_56->text().toInt();
   value=value+2;
   // userMessage(value,2,40);
   if(value > 40)
   {
       value=40;
   }
   // ui->progressBar_3->setValue(value);
   ui->lineEdit_56->setText(QString::number(value));
   //userMessage(value,2,40);
}

void MainWindow::US1FLOWDOWN()
{
  int value=ui->lineEdit_56->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }

   ui->lineEdit_56->setText(QString::number(value));
}


void MainWindow::us2powup()
{
  int value=ui->lineEdit_58->text().toInt();
   value=value+5;
    //userMessage(value,5,100);
   if(value > 100)
   {
       value=100;
   }
   // ui->progressBar_6->setValue(value);
   ui->lineEdit_58->setText(QString::number(value));
 //  userMessage(value,5,100);

}

void MainWindow::us2powdown()
{
 int  value=ui->lineEdit_58->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
   // ui->progressBar_6->setValue(value);
   ui->lineEdit_58->setText(QString::number(value));


}

void MainWindow::us2vacup()
{
  int value=ui->lineEdit_60->text().toInt();
   value=value+5;
   // userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
   // ui->progressBar_5->setValue(value);
   ui->lineEdit_60->setText(QString::number(value));
   //(value,5,500);

}

void MainWindow::us2vacdown()
{
  int value=ui->lineEdit_60->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
   // ui->progressBar_5->setValue(value);
   ui->lineEdit_60->setText(QString::number(value));

}

void MainWindow::us2flowup()
{
 int  value=ui->lineEdit_59->text().toInt();
   value=value+2;
  //  (value,2,40);
   if(value > 40)
   {
       value=40;
   }
  //  ui->progressBar_4->setValue(value);
   ui->lineEdit_59->setText(QString::number(value));

}

void MainWindow::us2flowdown()
{
  int value=ui->lineEdit_59->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }
   // ui->progressBar_4->setValue(value);
   ui->lineEdit_59->setText(QString::number(value));
}

void MainWindow::ULTRASONICBUT3()
{
   ui->tabWidget->setCurrentIndex(2);
   //  click();
     QString currentText = ui->CutMode_vitCom_3->currentText();

     updateTabsBasedOnComboBox(currentText);
   //changeButtonColor(2);
   ui->CutMode_vit->show();
   ui->CutMode_vitCom->show();
   ui->tabWidget_2->show();
   butname=3;
}

void MainWindow::us3powup()
{
  int value=ui->lineEdit_61->text().toInt();
   value=value+5;
    //(value,5,100);
   if(value > 100)
   {
       value=100;
   }
   // ui->progressBar_9->setValue(value);
   ui->lineEdit_61->setText(QString::number(value));
  // userMessage(value,5,100);
}

void MainWindow::us3powdown()
{
  int value=ui->lineEdit_61->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
  // ui->progressBar_9->setValue(value);
   ui->lineEdit_61->setText(QString::number(value));
}

void MainWindow::us3vacup()
{
  int value=ui->lineEdit_63->text().toInt();
   value=value+5;
  //  userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
  // ui->progressBar_8->setValue(value);
   ui->lineEdit_63->setText(QString::number(value));
   }

void MainWindow::us3vacdown()
{
  int value=ui->lineEdit_63->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
  // ui->progressBar_8->setValue(value);
   ui->lineEdit_63->setText(QString::number(value));
}

void MainWindow::us3flowup()
{
  int value=ui->lineEdit_62->text().toInt();
   value=value+2;
 //   userMessage(value,2,40);
   if(value > 40)
   {
       value=40;
   }
  // ui->progressBar_7->setValue(value);
   ui->lineEdit_62->setText(QString::number(value));
  // userMessage(value,2,40);
}

void MainWindow::us3flowdown()
{
  int value=ui->lineEdit_62->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }
  // ui->progressBar_7->setValue(value);
   ui->lineEdit_62->setText(QString::number(value));
}

void MainWindow::us4powup()
{
  int value=ui->lineEdit_64->text().toInt();
   value=value+5;
   // userMessage(value,5,100);
   if(value > 100)
   {
       value=100;
   }
  // ui->progressBar_12->setValue(value);
   ui->lineEdit_64->setText(QString::number(value));
  // userMessage(value,5,100);
}

void MainWindow::us4powdown()
{
  int value=ui->lineEdit_64->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_64->setText(QString::number(value));
}

void MainWindow::us4vacup()
{
  int value=ui->lineEdit_66->text().toInt();
   value=value+5;
   // userMessage(value,5,500);
   if(value > 500)
   {
       value=500;
   }
//   ui->progressBar_11->setValue(value);
   ui->lineEdit_66->setText(QString::number(value));

}

void MainWindow::us4vacdown()
{
  int value=ui->lineEdit_66->text().toInt();
   value=value-5;
   if(value < 5)
   {
       value=5;
   }
 //  ui->progressBar_11->setValue(value);
   ui->lineEdit_66->setText(QString::number(value));
}

void MainWindow::us4flowup()
{
  int value=ui->lineEdit_65->text().toInt();
   value=value+2;
  //  userMessage(value,2,40);
   if(value > 40)
   {
       value=40;
   }
 //  ui->progressBar_10->setValue(value);
   ui->lineEdit_65->setText(QString::number(value));

}

void MainWindow::us4flowdown()
{
 int  value=ui->lineEdit_65->text().toInt();
   value=value-2;
   if(value < 2)
   {
       value=2;
   }
  // ui->progressBar_10->setValue(value);
   ui->lineEdit_65->setText(QString::number(value));
}
void MainWindow::SETTINGSBUT()
{
   //this->close();
   s->show();
}
void MainWindow::setRange(QLineEdit* lineEdit, int prevValue, int value, int maxValue)
{
  if(value > maxValue)
  {
      lineEdit->setText(QString::number(prevValue));
  }
  else
  {
      lineEdit->setText(QString::number(value));
  }
}
void MainWindow::BACKBUT()
{

   this->close();
}
void MainWindow::current(int tab)
{

     QString styleSheet =
    "QPushButton {"
                        "    font-family: Ubuntu;"
                        "    font-size: 15pt;"

              "image: url(:/images/glass.png);"
                        //"    background-color: white;"
                        "    color: white;"
                        "    border-radius: 40px;"

                        "}";
   QString styleSheet1 = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 15pt;"
                       //  "width :81;"
                        // "height:81;"
                         "image: url(:/images/glass.png);"
                         "    color: black;"
          // "border:2px solid black;"
                         "    border-radius: 40px;"
                         "}";
   QString styleSheet2 = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 15pt;"
                         "width :81;"
                         "height:81;"
                         "image: url(:/images/us1.png);"
                         "    color: black;"
          // "border:2px solid black;"
                         "    border-radius: 40px;"
                         "}";
   QString styleSheet3 = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 15pt;"
                         "width :81;"
                         "height:81;"
                         "image: url(:/images/irr.png);"
                         "    color: black;"
          // "border:2px solid black;"
                         "    border-radius: 40px;"
                         "}";


   // Reset all buttons' styles to default (styleSheet1)
   ui->ULTRASONICBUT1->setStyleSheet(styleSheet1);
   ui->label_3->hide();
   ui->ULTRASONICBUT2->setStyleSheet(styleSheet1);
    ui->label_4->hide();
   ui->ULTRASONICBUT3->setStyleSheet(styleSheet1);
    ui->label_14->hide();
   ui->ULTRASONICBUT4->setStyleSheet(styleSheet1);
    ui->label_12->hide();
   ui->IA1BUT->setStyleSheet(styleSheet1);
    ui->label_13->hide();
   ui->IA2BUT->setStyleSheet(styleSheet1);
    ui->label_5->hide();
   ui->VITRECTOMYBUT->setStyleSheet(styleSheet1);
    ui->label_6->hide();
   ui->DIABUT->setStyleSheet(styleSheet1);
 ui->label_11->hide();
 //  ui->tabWidget->setCurrentIndex(7);
   //ui->DIABUT->click();

   // Set the styleSheet for the button corresponding to the current tab
   switch (tab) {
       case 0:
           ui->ULTRASONICBUT1->setStyleSheet(styleSheet2);
           ui->label_3->show();
           break;
       case 1:
           ui->ULTRASONICBUT2->setStyleSheet(styleSheet2);
           ui->label_4->show();
           break;
       case 2:
           ui->ULTRASONICBUT3->setStyleSheet(styleSheet2);
           ui->label_14->show();
           break;
       case 3:
           ui->ULTRASONICBUT4->setStyleSheet(styleSheet2);
           ui->label_12->show();
           break;
       case 4:
           ui->IA1BUT->setStyleSheet(styleSheet3);
           ui->label_13->show();
           break;
       case 5:
           ui->IA2BUT->setStyleSheet(styleSheet3);
           ui->label_5->show();
           break;
       case 6:
           ui->VITRECTOMYBUT->setStyleSheet(styleSheet);
           ui->label_6->show();
           break;
       case 7:
           ui->DIABUT->setStyleSheet(styleSheet);
           ui->label_11->show();
          // footpedalcheck();
           break;
       default:
           break;
   }


}

void MainWindow::updateline() {
   // Get the selected mode as a QString
   QString selected = ui->CutMode_vitCom->currentText();
    QString selected1 = ui->CutMode_vitCom_2->currentText();
     QString selected2 = ui->CutMode_vitCom_3->currentText();
      QString selected3 = ui->CutMode_vitCom_4->currentText();
      qDebug() << "Selected Mode as Text:" << selected;


         qDebug() << "CutMode_vitCom selected: " << selected;
         qDebug() << "CutMode_vitCom_2 selected: " << selected1;
         qDebug() << "CutMode_vitCom_3 selected: " << selected2;
         qDebug() << "CutMode_vitCom_4 selected: " << selected3;

         // Ensure all combo boxes have the same selected mode
         if (selected == selected1 && selected1 == selected2 && selected2 == selected3) {
             updateTabsBasedOnComboBox(selected);
         } else {
             qDebug() << "Selected modes do not match!";
         }
}

void MainWindow::tabupdate(int index)
{
   ui->tabWidget_2->setCurrentIndex(index);
}
// LINEAR
//footpedallllllllllllllllllllllllllll
void MainWindow::footpedalcheck()
{

       qint64 elapsed = currentTimer.elapsed();
       QString message;
   QString styleSheet3 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: green;"
           "color: black;"
             "image: url(:/images/ci.png);"
          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";
   QString styleSheet4 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: red;"
           "color: black;"
             "image: url(:/images/ci.png);"
          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";
   QString styleSheet1 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: green;"
           "color: black;"

          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";

   QString styleSheet2 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: rgb(224, 27, 36);"
           "color: black;"
           //"image: url(:/ci.png);"
          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";
   int range = lfoot->convert(0x97);
   switch(butname)
   {

   // dia
   case 0:
   {
       int pow = (ui->lineEdit_74->text().toInt()*256)/100;
       bool flag = true; // Ensure flag is correctly set

       if (flag) {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
                handler->dia_off();
                if(!cidia){
               handler->pinchvalve_off();
               handler->safetyvent_off();
           }
           }
           else if (range >= 1024 && range < 4094)
            {
               ui->pushButton_42->setText("1");
               handler->safetyvent_on();
               handler->pinchvalve_on();
               handler->dia_on();
               //handler->diathermy(pow); // Assuming handler is correctly initialized
               handler->dia_count(pow);
               handler->pinchvalve_on();
           }
       }
       break;
   }
 //us1
   case 1: {
       int pow1 = ui->lineEdit_57->text().toInt(); // Get the power value from the line edit
       bool flag1 = true;

       if (us1 == "PANEL" || vus1 == "PANEL") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
                //ui->dial_2->setStyleSheet("");
               ui->dial_2->setValue(range);
               motoroff();
               if(!cius1){
                   ui->CI1->setStyleSheet(styleSheet4);
                   handler->pinchvalve_off();
                   handler->safetyvent_off();
               }

               ui->label_7->setText("0");
               ui->label_8->setText("0");
               if (power.powerOn) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                  power.powerOn= false;
               }
               flag1 = true; // Reset flag
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
                ui->dial_2->setValue(range);
               handler->pinchvalve_on();
               handler->safetyvent_on();
                 ui->CI1->setStyleSheet(styleSheet3);
               motoroff();
               ui->label_7->setText("0");
               ui->label_8->setText("0");
               if (power.powerOn) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn = false;
               }
               flag1 = true; // Reset flag
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
                ui->dial_2->setValue(range);
               ui->CI1->setStyleSheet(styleSheet3);
               handler->pinchvalve_on();
               handler->safetyvent_on();
               motoron(ui->lineEdit_56);
               sensor2();
               ui->label_7->setText("0");
               if (power.powerOn) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                  power.powerOn = false;
               }
               flag1 = true; // Reset flag
           } else if (range >= 3072 && range < 4096) {
               ui->pushButton_42->setText("3");
                ui->dial_2->setValue(range);
               ui->CI1->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
                 handler->fs_count(range);
               handler->freq_count(2500);
               handler->phaco_on();
               handler->phaco_power(pow1);
               handler->pdm_mode(1);
               if (power.buttonState == "ON" && !power.powerOn) {
                   updateline();
                  power.powerOn= true;

               }
               if (power.powerOn) {
                   // Dynamically calculate power output based on range for PANEL mode
                   float progress4 = ((range - 3072.0) / (4096 - 3072)) * pow1;
                   ui->label_7->setText(QString::number(static_cast<int>(progress4)));
               }
               motoron(ui->lineEdit_56);
               sensor2();
           }
       } else if (us1 == "SURGEON" || vus1 == "SURGEON") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
 ui->dial_2->setValue(range);
               motoroff();
               if(!cius1){
                   ui->CI1->setStyleSheet(styleSheet4);
                   handler->safetyvent_off();
                   handler->pinchvalve_off();
               }

               ui->label_7->setText("0");
               ui->label_8->setText("0");
               if (power.powerOn) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn = false;
               }
               flag1 = true; // Reset flag
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
                ui->dial_2->setValue(range);
               handler->pinchvalve_on();
               handler->safetyvent_on();
               ui->CI1->setStyleSheet(styleSheet3);
               motoroff();
               ui->label_7->setText("0");
               ui->label_8->setText("0");
               if (power.powerOn) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn = false;
               }
               flag1 = true; // Reset flag
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
                ui->dial_2->setValue(range);
               handler->pinchvalve_on();
               handler->safetyvent_on();
               ui->CI1->setStyleSheet(styleSheet3);
               motoron(ui->lineEdit_59);
               updatesensor();
               ui->label_7->setText("0");
               if (power.powerOn) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn = false;
               }
               flag1 = true; // Reset flag
           } else if (range >= 3072 && range <= 4096) {
               ui->pushButton_42->setText("3");
                ui->dial_2->setValue(range);
               ui->CI1->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
                  handler->fs_count(range);
               handler->freq_count(2500);
handler->phaco_on();
               handler->phaco_power(pow1);
               handler->pdm_mode(1);

               motoron(ui->lineEdit_59);
               if (power.buttonState == "ON" && !power.powerOn) {
                   power.powerOn = true;
                   updateline();

               }
               if (power.powerOn) {

                   int powervalue = range*pow1/4096;
                   ui->label_7->setText(QString::number(powervalue));
               }

               elapsedTimeUS1 += elapsed;
               message = "Effective time for US1: " + QString::number(elapsedTimeUS1 / 1000.0, 'f', 2) + " s";
               break;
           }

               updatesensor();
           }
       }

       // us2
   case 2: {
       int pow2 = ui->lineEdit_58->text().toInt(); // Get the power value from the line edit
       bool flag2 = true;

       if (us2 == "PANEL" || vus2 == "PANEL") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
              // ui->CI2->setStyleSheet(styleSheet4);
               if(!cius2){
                   ui->CI2->setStyleSheet(styleSheet4);
                   handler->pinchvalve_off();
                   handler->safetyvent_off();
               }

               motoroff();
               ui->label_92->setText("0");
               ui->label_93->setText("0");
               if (power.powerOn1) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn1 = false;
               }
               flag2 = true; // Reset flag
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
ui->CI2->setStyleSheet(styleSheet3);
handler->safetyvent_on();
handler->pinchvalve_on();
               motoroff();
               handler->phaco_off();
               ui->label_92->setText("0");
               ui->label_93->setText("0");

if (power.powerOn1) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn1 = false;
               }
               flag2 = true; // Reset flag
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
               ui->CI2->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               motoron(ui->lineEdit_62);
               sensor2();
               ui->label_92->setText("0");
               if (power.powerOn1) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn1 = false;
               }
               flag2 = true; // Reset flag
           } else if (range >= 3072 && range < 4096) {
               ui->pushButton_42->setText("3");
               ui->CI2->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               if (power.buttonstate1 == "ON" && !power.powerOn1) {
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->fs_count(range);
                   handler->phaco_power(pow2);
                   handler->pdm_mode(1);
                   updateline();
                   power.powerOn1 = true;
               }
               if (power.powerOn1) {
                   // Dynamically calculate power output based on range for PANEL mode
                   float progress4 = ((range - 3072.0) / (4096 - 3072)) * pow2;
                   ui->label_92->setText(QString::number(static_cast<int>(progress4)));
               }

               motoron(ui->lineEdit_62);
               sensor2();
           }
       } else if (us2 == "SURGEON" || vus2 == "SURGEON") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");

               motoroff();
               if(!cius2){
                   ui->CI2->setStyleSheet(styleSheet4);
                   handler->pinchvalve_off();
                   handler->safetyvent_off();
               }
               handler->phaco_off();
               ui->label_92->setText("0");
               ui->label_93->setText("0");
               if (power.powerOn1) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn1 = false;
               }
               flag2 = true; // Reset flag
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
               ui->CI2->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               motoroff();
               handler->phaco_off();
               ui->label_92->setText("0");
               ui->label_93->setText("0");
               if (power.powerOn1) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn1 = false;
               }
               flag2 = true; // Reset flag
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
               ui->CI2->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               motoron(ui->lineEdit_62);
               updatesensor();
               ui->label_92->setText("0");
               if (power.powerOn1) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn1 = false;
               }
               flag2 = true; // Reset flag
           } else if (range >= 3072 && range <= 4096) {
               ui->pushButton_42->setText("3");
               ui->CI2->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               if (power.buttonstate1 == "ON" && !power.powerOn1) {
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->fs_count(range);
                   handler->phaco_power(pow2);
                   handler->pdm_mode(1);
                   power.powerOn1 = true;
                   updateline();
               }
               if (power.powerOn1) {
                   // Dynamically calculate power output based on range for SURGEON mode
                   int progress4 = pow2 * (range - 3072) / (4096 - 3072);
                   int progress5 = std::min(progress4, pow2);
                   ui->label_92->setText(QString::number(progress5));
               }

               motoron(ui->lineEdit_62);
               updatesensor();
           }
       }

       elapsedTimeUS2 += elapsed;
       message = "Effective time for US2: " + QString::number(elapsedTimeUS2 / 1000.0, 'f', 2) + " s";
       break;
   }

   case 3: {
       int pow3 = ui->lineEdit_61->text().toInt(); // Get the power value from the line edit
       bool flag3 = true;

       if (us3 == "PANEL" || vus3 == "PANEL") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");

               motoroff();
               if(!cius3){
                   ui->CI3->setStyleSheet(styleSheet4);
                   handler->safetyvent_off();
                   handler->pinchvalve_off();
               }
               handler->phaco_off();
               ui->label_98->setText("0");
               ui->label_99->setText("0");
               if (power.powerOn2) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn2 = false;
               }
               flag3 = true; // Reset flag
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
ui->CI3->setStyleSheet(styleSheet3);
handler->safetyvent_on();
handler->pinchvalve_on();
               motoroff();
               handler->phaco_off();
               ui->label_98->setText("0");
               ui->label_99->setText("0");
               if (power.powerOn2) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn2 = false;
               }
               flag3 = true; // Reset flag
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
               ui->CI3->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               motoron(ui->lineEdit_65);
               sensor2();
               ui->label_98->setText("0");
               if (power.powerOn2) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn2 = false;
               }
               flag3 = true; // Reset flag
           } else if (range >= 3072 && range < 4096) {
               ui->pushButton_42->setText("3");
               ui->CI3->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               if (power.buttonstate2 == "ON" && !power.powerOn2) {
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->fs_count(range);
                   handler->phaco_power(pow3);
                   handler->pdm_mode(1);
                   updateline();
                   power.powerOn2 = true;
               }
               if (power.powerOn2) {
                   // Dynamically calculate power output based on range for PANEL mode
                   float progress8 = ((range - 3072.0) / (4096 - 3072)) * pow3;
                   ui->label_98->setText(QString::number(static_cast<int>(progress8)));
               }


               motoron(ui->lineEdit_65);
               sensor2();

           }
       } else if (us3 == "SURGEON" || vus3 == "SURGEON") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
               // ui->CI3->setStyleSheet(styleSheet3);

               motoroff();
               if(!cius3){
                   ui->CI3->setStyleSheet(styleSheet4);
                   handler->safetyvent_off();
                   handler->pinchvalve_off();
               }
               handler->phaco_off();
               ui->label_98->setText("0");
               ui->label_99->setText("0");
               if (power.powerOn2) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn2 = false;
               }
               flag3 = true; // Reset flag
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
               ui->CI3->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               motoroff();
               handler->phaco_off();
               ui->label_98->setText("0");
               ui->label_99->setText("0");
               if (power.powerOn2) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn2 = false;
               }
               flag3 = true; // Reset flag
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
               ui->CI3->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               motoron(ui->lineEdit_65);
               updatesensor();
               ui->label_98->setText("0");
               if (power.powerOn2) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn2 = false;
               }
               flag3 = true; // Reset flag
           } else if (range >= 3072 && range <= 4096) {
               ui->pushButton_42->setText("3");
               ui->CI3->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();
               if (power.buttonstate2 == "ON" && !power.powerOn2) {
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->fs_count(range);
                   handler->phaco_power(pow3);
                   handler->pdm_mode(1);
                   power.powerOn2 = true;
                   updateline();
               }
               if (power.powerOn2) {
                   // Dynamically calculate power output based on range for SURGEON mode
                   int progress8 = pow3 * (range - 3072) / (4096 - 3072);
                   int progress9 = std::min(progress8, pow3);
                   ui->label_98->setText(QString::number(progress9));
               }

               motoron(ui->lineEdit_65);
               updatesensor();

           }
       }

       elapsedTimeUS3 += elapsed;
       message = "Effective time for US3: " + QString::number(elapsedTimeUS3 / 1000.0, 'f', 2) + " s";
       break;
   }

       // us4
   case 4: {
       int pow4 = ui->lineEdit_64->text().toInt(); // Get the power value from the line edit

       if (us4 == "PANEL" || vus4 == "PANEL") { // surgeon
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
               if(!cius4){
                   ui->CI4->setStyleSheet(styleSheet4);
                   handler->safetyvent_off();
                   handler->pinchvalve_off();
               }

               motoroff();
               handler->phaco_off();
              // ui->CI4->setStyleSheet(styleSheet4);
               ui->label_105->setText("0");
            //   ui->label_42->setText("0");
               if (power.powerOn3) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn3 = false;
               }
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
               ui->CI4->setStyleSheet(styleSheet3);
             handler->pinchvalve_on();
             handler->safetyvent_on();
               motoroff();
               handler->phaco_off();
               ui->label_105->setText("0");
               //ui->label_42->setText("0");
               if (power.powerOn3) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn3 = false;
               }
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
               ui->CI4->setStyleSheet(styleSheet3);
handler->safetyvent_on();
handler->pinchvalve_on();
               motoron(ui->lineEdit_65);
               handler->phaco_off();
               ui->label_105->setText("0");
               sensor2();
               if (power.powerOn3) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn3 = false;
               }
           } else if (range >= 3072 && range < 4096) {
               ui->pushButton_42->setText("3");
               ui->CI4->setStyleSheet(styleSheet3);
               handler->safetyvent_on();
               handler->pinchvalve_on();

               if (power.buttonstate3 == "ON" && !power.powerOn3) {
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->fs_count(range);
                   handler->phaco_power(pow4);
                   handler->pdm_mode(1);
                   updateline();
                   power.powerOn3 = true;
               }
               if (power.powerOn3) {
                   // Dynamically calculate power output based on range for PANEL mode
                   float progress14 = ((range - 3072.0) / (4096 - 3072)) * pow4;
                   ui->label_105->setText(QString::number(static_cast<int>(progress14)));
               }

               motoron(ui->lineEdit_65);
               sensor2();

           } else {
               ui->label_105->setText("0");
           }
       } else if (us4 == "SURGEON" || vus4 == "SURGEON") {
           if (range >= 0 && range < 1024) {
               ui->pushButton_42->setText("0");
               if(!cius4){
                   ui->CI4->setStyleSheet(styleSheet4);
                   handler->safetyvent_off();
                   handler->pinchvalve_off();
               }

               motoroff();
               handler->phaco_off();
               if (power.powerOn3) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn3 = false;
               }
           } else if (range >= 1024 && range < 2048) {
               ui->pushButton_42->setText("1");
               ui->CI4->setStyleSheet(styleSheet3);
              handler->safetyvent_on();
              handler->pinchvalve_on();
               motoroff();
               handler->phaco_off();
               ui->label_105->setText("0");
             //  ui->label_42->setText("0");
               if (power.powerOn3) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn3 = false;
               }
           } else if (range >= 2048 && range < 3072) {
               ui->pushButton_42->setText("2");
               ui->CI4->setStyleSheet(styleSheet3);
handler->pinchvalve_on();
handler->safetyvent_on();
               motoron(ui->lineEdit_65);
               handler->phaco_off();
               ui->label_105->setText("0");
               sensor2();
               if (power.powerOn3) {
                   handler->freq_count(0);
                   handler->phaco_off();
                   handler->fs_count(0);
                   handler->pdm_mode(0);
                   power.powerOn3 = false;
               }
           } else if (range >= 3072 && range <= 4096) {
               ui->pushButton_42->setText("3");
               ui->CI4->setStyleSheet(styleSheet3);
handler->safetyvent_on();
handler->pinchvalve_on();
               if (power.buttonstate3 == "ON" && !power.powerOn3) {
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->fs_count(range);
                   handler->phaco_power(pow4);
                   handler->pdm_mode(1);
                   updateline();
                   power.powerOn3 = true;
               }
               if (power.powerOn3) {
                   // Dynamically calculate power output based on range for SURGEON mode
                   int progress11 = pow4 * (range - 3072) / (4096 - 3072);
                   int progress12 = std::min(progress11, pow4);
                   ui->label_105->setText(QString::number(progress12));
               }

               motoron(ui->lineEdit_65);
               updatesensor();

           } else {
               ui->label_105->setText("0");
           }
       }

       elapsedTimeUS4 += elapsed;
       message = "Effective time for US4: " + QString::number(elapsedTimeUS4 / 1000.0, 'f', 2) + " s";
       break;
   }

       // ia1
       case 5:
       {

       //int val=v->convert(0xD7);
      // int value6=ui->lineEdit_71->text().toInt();
 bool flag5=true;
       if(flag5){
            if(ia1==" PANEL"){//surgeon
           if(range>=0 && range<1024){
               ui->pushButton_42->setText("0");
               if(!ci_ia1){
                   ui->CI5_3->setStyleSheet(styleSheet4);

handler->pinchvalve_off();
handler->safetyvent_off();
               }
           }
           if(range>=1024 && range<2048){
               ui->pushButton_42->setText("1");
               ui->CI5_3->setStyleSheet(styleSheet3);
                  handler->pinchvalve_on();
                  handler->safetyvent_on();
                 motoroff();


           }
            if(range>=2048 && range <4096){
           //    qDebug()<<"fs"<<range;
                 ui->pushButton_42->setText("2");
                 ui->CI5_3->setStyleSheet(styleSheet3);
                    handler->pinchvalve_on();
                    handler->safetyvent_on();
                    motoron(ui->lineEdit_69);
             sensor2();

       }
            else{
                motoroff();
            }
          }
            else{
                if(ia1 == "SURGEON"){
                if(range>=0 && range<1024){
                    ui->pushButton_42->setText("0");
                    if(!ci_ia1){
                        ui->CI5_3->setStyleSheet(styleSheet4);

     handler->pinchvalve_off();
     handler->safetyvent_off();
                    }
                       motoroff();
                }
                if(range>=1024 && range<2048){
                    ui->pushButton_42->setText("1");
                       handler->pinchvalve_on();
                       handler->safetyvent_on();
                   motoroff();
                }
                else if(range>=2048 && range <4096){
                   // qDebug()<<"fs"<<range;
                      ui->pushButton_42->setText("2");
                         handler->pinchvalve_on();
                         handler->safetyvent_on();
                         motoron(ui->lineEdit_69);
                  updatesensor();
            }
                else{
                    motoroff();
                }
                }

}
   }
        break;
   }
       // ia2
       case 6:
       {

       //int value6=ui->lineEdit_71->text().toInt();
 bool flag6=true;

       if(flag6){
           if(ia2 == "PANEL"){//surgeon
           if(range>=0 && range<1024){
               ui->pushButton_42->setText("0");
               if(!ci_ia2){
                   ui->CI5_4->setStyleSheet(styleSheet4);

               handler->pinchvalve_off();
               handler->safetyvent_off();
               }
              //   motoron(ui->lineEdit_10);
motoroff();
           }
           if(range>=1024 && range<2048){
               ui->pushButton_42->setText("1");
               // motoron(ui->lineEdit_10);
               ui->CI5_4->setStyleSheet(styleSheet3);
                  handler->pinchvalve_on();
                  handler->safetyvent_on();
                motoroff();
           }
           else if(range>=2048 && range <4096){
               ui->pushButton_42->setText("2");
               ui->CI5_4->setStyleSheet(styleSheet3);
                  handler->pinchvalve_on();
                  handler->safetyvent_on();
               sensor2();
              motoron(ui->lineEdit_67);
           }
           else{
              motoroff();
           }
           }
           else{
               if(ia2 == "SURGEON"){
               if(range>=0 && range<1024){
                   ui->pushButton_42->setText("0");
                   if(!ci_ia2){
                       ui->CI5_4->setStyleSheet(styleSheet4);

                   handler->pinchvalve_off();
                   handler->safetyvent_off();
                   }
                     motoroff();
                  // label43();
               }
               if(range>=1024 && range<2048){
                   ui->pushButton_42->setText("1");
                   ui->CI5_4->setStyleSheet(styleSheet4);
                      handler->pinchvalve_on();
                      handler->safetyvent_on();
                    // motoroff();
               }
               else if(range>=2048 && range <4096){
                   ui->pushButton_42->setText("2");
                       ui->CI5_4->setStyleSheet(styleSheet4);
                      handler->pinchvalve_on();
                      handler->safetyvent_on();
                      motoron(ui->lineEdit_67);
                   updatesensor();      }
               else{
                   motoroff();
               }
               }
      }
      } break;
       }
       // vit
   case 7: {
       int pow7 = ui->lineEdit_71->text().toInt();


       bool flag7 = true;
       if (flag7) {
           if (vit == "PANEL" || vvit == "PANEL") {
               if (range >= 0 && range < 1024) {
                   ui->pushButton_42->setText("0");
                   if(!civit){
                       ui->CI5->setStyleSheet(styleSheet4);
                       handler->safetyvent_off();
                       handler->pinchvalve_off();
                   }

                   motoroff();
                   handler->vit_off();

                   ui->label_119->setText("0");
                   if (power.powerOn4) {
                       handler->vit_off();
                       power.powerOn4 = false;
                   }
               } else if (range >= 1024 && range < 2048) {
                   ui->pushButton_42->setText("1");
 ui->CI5->setStyleSheet(styleSheet3);
 handler->safetyvent_on();
 handler->pinchvalve_on();
                   motoroff();
                   handler->vit_off();
                   ui->label_119->setText("0");
                   if (power.powerOn4) {
                      handler->vit_off();
                       power.powerOn4 = false;
                   }
               } else if (range >= 2048 && range < 3072) {
                   ui->pushButton_42->setText("2");
                   ui->CI5->setStyleSheet(styleSheet3);
                   handler->safetyvent_on();
                   handler->pinchvalve_on();
                   motoron(ui->lineEdit_72);
                   handler->vit_off();
                   ui->label_119->setText("0");
                   sensor2();
                   if (power.powerOn4) {
                      handler->vit_off();
                       power.powerOn4 = false;
                   }
               } else if (range >= 3072 && range < 4096) {
                   ui->pushButton_42->setText("3");
                   ui->CI5->setStyleSheet(styleSheet3);
                   handler->safetyvent_on();
                   handler->pinchvalve_on();
                   if (power.buttonstate4 == "ON" && !power.powerOn4) {
                      handler->vit_on(pow7);
                      handler->vit_ontime(30);
                       updateline();
                       power.powerOn4 = true;
                   }
                   if (power.powerOn4) {
                       float progress24 = ((range - 3072.0) / (4096 - 3072)) * pow7;
                       ui->label_119->setText(QString::number(static_cast<int>(progress24)));
                   }


                   motoron(ui->lineEdit_72);

                   sensor2();

               }
           } else if (vit == "SURGEON" || vvit == "SURGEON") {
               if (range >= 0 && range < 1024) {
                   ui->pushButton_42->setText("0");
                   if(!civit){
                       ui->CI5->setStyleSheet(styleSheet4);
                       handler->safetyvent_off();
                       handler->pinchvalve_off();
                   }
                   handler->vit_off();
                   motoroff();
                   ui->label_119->setText("0");
                   if (power.powerOn4) {
                      handler->vit_off();
                       power.powerOn4 = false;
                   }
               } else if (range >= 1024 && range < 2048) {
                   ui->pushButton_42->setText("1");
                   ui->CI5->setStyleSheet(styleSheet3);
                   handler->safetyvent_on();
                   handler->pinchvalve_on();
                   motoroff();
                   handler->vit_off();
                   ui->label_119->setText("0");
                   if (power.powerOn4) {
                    handler->vit_off();
                       power.powerOn4 = false;
                   }
               } else if (range >= 2048 && range < 3072) {
                   ui->pushButton_42->setText("2");
                   ui->CI5->setStyleSheet(styleSheet3);
                   handler->safetyvent_on();
                   handler->pinchvalve_on();

                   motoron(ui->lineEdit_72);
                   handler->vit_off();
                   ui->label_119->setText("0");
                   sensor2();
                   if (power.powerOn4) {
                       handler->vit_off();
                       power.powerOn4 = false;
                   }
               } else if (range >= 3072 && range < 4096) {
                   ui->pushButton_42->setText("3");
                   ui->CI5->setStyleSheet(styleSheet3);
                   handler->safetyvent_on();
                   handler->pinchvalve_on();
                   if (power.buttonstate4 == "ON" && !power.powerOn4) {
                       handler->vit_on(pow7);
                       handler->vit_ontime(30);
                       updateline();
                       power.powerOn4 = true;
                   }
                   if (power.powerOn4) {
                       int progress24 = pow7 * (range - 3072) / (4096 - 3072);
                       int progress25 = std::min(progress24, pow7);
                       ui->label_119->setText(QString::number(progress25));
                   }


                   motoron(ui->lineEdit_72);

                   updatesensor();
                 }

           }
       }
   }
       break;
   }


   currentTimer.restart();
   updateLabel();

}
void MainWindow::on_DIABUT_clicked()
{
   //hard->dia_on();
   //hard->dia_count(ui->lineEdit_74->text().toInt()*256/100);
   //qDebug()<<"dia";
}
void MainWindow::us1_linear_nonlinear()
{
    // ui->us1mode->setText("SURGEON");
    us1=ui->us1mode->text();

      if(us1 == "SURGEON" )
      {
          ui->us1mode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
           ui->us1mode->setText("PANEL");

            footpedalcheck();

      }
      else if(us1 == "PANEL" )
      {
          ui->us1mode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
          ui->us1mode->setText("SURGEON");


    footpedalcheck();

}//promptForUpdate("PowMethodCom_phaco", us1);
}
void MainWindow::on_us1vacmode_clicked()
{
   vus1 = ui->us1vacmode->text();
      if(vus1== "SURGEON")
      {

           ui->us1vacmode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
           ui->us1vacmode->setText("PANEL");

            footpedalcheck();
      }
      else if(vus1=="PANEL")
      {

          ui->us1vacmode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
          ui->us1vacmode->setText("SURGEON");
        //  int pow2=ui->lineEdit_58->text().toInt();
    footpedalcheck();
}
//promptForUpdate("PowMethodCom_phaco", us1);
}


void MainWindow::us2_linear_nonlinear()
{
   us2 = ui->us2mode->text();


      if(us2 == "SURGEON" )
      {
           ui->us2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
            ui->us2mode->setText("PANEL");


             footpedalcheck();
              }
      else if(us2 == "PANEL")
      {
           ui->us2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
          ui->us2mode->setText("SURGEON");

        footpedalcheck();
      }
    //  promptForUpdate("PowMethodCom_phaco", us2);
}
void MainWindow::on_us2vacmode_clicked()
{
   vus2=ui->us2vacmode->text();
   if(vus2 == "SURGEON")
   {

     ui->us2vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
         ui->us2vacmode->setText("PANEL");

          footpedalcheck();
           }
   else if(vus2 == "PANEL")
   {

       ui->us2vacmode->setText("SURGEON");
        ui->us2vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
     footpedalcheck();
   }
//promptForUpdate("PowMethodCom_phaco", us2);
}

void MainWindow::us3_linear_nonlinear()
{
   us3 = ui->us3mode->text();


      if(us3 == "SURGEON")
      {
           ui->us3mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
            ui->us3mode->setText("PANEL");

             footpedalcheck();
      }
      else if(us3 == "PANEL")
      {
            ui->us3mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
          ui->us3mode->setText("SURGEON");

          footpedalcheck();
      }
     // promptForUpdate("PowMethodCom_phaco", us3);
}
void MainWindow::on_us3vacmode_clicked()
{
    vus3=ui->us3vacmode->text();
    if(vus3 =="SURGEON")
    {

          ui->us3vacmode->setText("PANEL");
           ui->us3vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           footpedalcheck();
    }
    else if(vus3 == "PANEL")
    {

        ui->us3vacmode->setText("SURGEON");
        ui->us3vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
        footpedalcheck();
    }
    //promptForUpdate("PowMethodCom_phaco", us3);
}

void MainWindow::us4_linear_nonlinear()
{
   us4 = ui->us4mode->text();

      if(us4 == "SURGEON")
      {

           ui->us4mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
            ui->us4mode->setText("PANEL");

            footpedalcheck();
               }
      else if(us4 == "PANEL")
      {
          ui->us4mode->setText("SURGEON");
             ui->us4mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");


              footpedalcheck();
      }
     // promptForUpdate("PowMethodCom_phaco", us4);
}

void MainWindow::on_us4vacmode_clicked()
{
   vus4=ui->us4vacmode->text();
   if(vus4 == "SURGEON")
   {


         ui->us4vacmode->setText("PANEL");
          ui->us4vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
         footpedalcheck();
            }
   else if(vus4 == "PANEL")
   {

          ui->us4vacmode->setText("SURGEON");
           ui->us4vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           footpedalcheck();
   }
   // promptForUpdate("PowMethodCom_phaco", us4);
}



void MainWindow::ia1_linear_nonlinear()
{
   ia1= ui->ia1mode->text();

      if(ia1== "SURGEON")
      {

           ui->ia1mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
            ui->ia1mode->setText("PANEL");
           footpedalcheck();
              }
      else if(ia1 == "PANEL")
      {
           ui->ia1mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
          ui->ia1mode->setText("SURGEON");
          footpedalcheck();
              }
    //  promptForUpdate("PowMethodCom_phaco", ia1);
}
void MainWindow::ia2_linear_nonlinear()
{
   ia2 = ui->ia2mode->text();

      if(ia2 == "SURGEON")
      {
          ui->ia2mode->setText("PANEL");
           ui->ia2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
            footpedalcheck();
               }
      else if(ia2 == "PANEL")
      {
          ui->ia2mode->setText("SURGEON");
           ui->ia2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
footpedalcheck();
      }
    //  promptForUpdate("PowMethodCom_phaco", ia2);
}
void MainWindow::vit_linear_nonlinear()
{
   vit = ui->vitmode->text();


      if(vit == "SURGEON" )
      {

          ui->vitmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           ui->vitmode->setText("PANEL");

           footpedalcheck();
              }
      else if(vit == "PANEL")
      {
             ui->vitmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
          ui->vitmode->setText("SURGEON");

          footpedalcheck();
             }
     // promptForUpdate("PowMethodCom_phaco", vit);
}
void MainWindow::on_vitvacmode_clicked()
{
     vvit=ui->vitvacmode->text();

     if(vvit =="SURGEON")
     {


          ui->vitvacmode->setText("PANEL");
          ui->vitvacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
          footpedalcheck();
             }
     else if(vvit == "PANEL")
     {

         ui->vitvacmode->setText("SURGEON");
         ui->vitvacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
         footpedalcheck();
            }

}
//pulse
void MainWindow::on_pushButton_5_clicked()
{
    pulse = ui->lineEdit_75->text().toInt();
    pulse += 1;
    if (pulse > 15) {
        pulse = 15;
    }
    ui->lineEdit_75->setText(QString::number(pulse));
    handler->pulse_count(pulse);
   // handler->freq_count(pulse);
   // qDebug()<<"increase";
}

void MainWindow::on_pushButton_6_clicked()
{
    pulse = ui->lineEdit_75->text().toInt();
   pulse -= 1;
    if (pulse < 1) {
        pulse = 1;
    }
    ui->lineEdit_75->setText(QString::number(pulse));
    handler->pulse_count(pulse);
  //  handler->freq_count(pulse);
            //  qDebug()<<"decraese";
}
//ocupulse
void MainWindow::on_pushButton_44_clicked()
{
    ocupulse = ui->lineEdit_76->text().toInt();
    ocupulse -= 1;
    if (ocupulse <1) {
        ocupulse = 1;
    }
    ui->lineEdit_76->setText(QString::number(ocupulse));
    handler->pulse_count(ocupulse);
}

void MainWindow::on_pushButton_45_clicked()
{
    ocupulse = ui->lineEdit_76->text().toInt();
    ocupulse += 1;
    if (ocupulse >15) {
        ocupulse = 15;
    }
    ui->lineEdit_76->setText(QString::number(ocupulse));
    handler->pulse_count(ocupulse);
}
//ocuburst
void MainWindow::on_pushButton_46_clicked()
{
    ocuburst = ui->lineEdit_77->text().toInt();
    ocuburst += 10;
    if (ocuburst > 170) {
        ocuburst = 170;
    }
    ui->lineEdit_77->setText(QString::number(ocuburst));
    handler->burst_length(ocuburst);
    handler->burst_off_length(ocuburst);
}

void MainWindow::on_pushButton_47_clicked()
{
    ocuburst = ui->lineEdit_77->text().toInt();
    ocuburst -= 10;
    if (ocuburst < 10) {
        ocuburst = 10;
    }
    ui->lineEdit_77->setText(QString::number(ocuburst));
    handler->burst_length(ocuburst);
    handler->burst_off_length(ocuburst);
}
//single burst
void MainWindow::on_pushButton_48_clicked()
{
    singleburst = ui->lineEdit_78->text().toInt();
    singleburst -= 10;
    if (singleburst < 10) {
        singleburst = 10;
    }
    ui->lineEdit_78->setText(QString::number(singleburst));
    handler->burst_length(singleburst);
    handler->burst_off_length(singleburst);

}

void MainWindow::on_pushButton_49_clicked()
{

    singleburst = ui->lineEdit_78->text().toInt();
    singleburst += 10;
    if (singleburst > 400) {
        singleburst = 400;
    }
    ui->lineEdit_78->setText(QString::number(singleburst));
    handler->burst_length(singleburst);
    handler->burst_off_length(singleburst);

}
//multi burst

void MainWindow::on_pushButton_50_clicked()
{
    multiburst = ui->lineEdit_79->text().toInt();
    multiburst += 10;
    if (multiburst > 400) {
        multiburst = 400;
    }
    ui->lineEdit_79->setText(QString::number(multiburst));
    handler->burst_length(multiburst);
    handler->burst_off_length(multiburst);
}

void MainWindow::on_pushButton_51_clicked()
{
    multiburst = ui->lineEdit_79->text().toInt();
    multiburst -= 10;
    if (multiburst < 10) {
        multiburst = 10;
    }
    ui->lineEdit_79->setText(QString::number(multiburst));
    handler->burst_length(multiburst);
    handler->burst_off_length(multiburst);
}
//cold phaco
void MainWindow::on_pushButton_52_clicked()
{
    coldphaco = ui->lineEdit_80->text().toInt();
    coldphaco += 1;
    if (coldphaco > 15) {
        coldphaco = 15;
    }
    ui->lineEdit_80->setText(QString::number(coldphaco));
    handler->cold_pulse(coldphaco);
}

void MainWindow::on_pushButton_53_clicked()
{
    coldphaco = ui->lineEdit_80->text().toInt();
    coldphaco -= 1;
    if (coldphaco < 1) {
        coldphaco = 1;
    }
    ui->lineEdit_80->setText(QString::number(coldphaco));
    handler->cold_pulse(coldphaco);
}

void MainWindow::on_pushButton_54_clicked()
{
    coldphaco1 = ui->lineEdit_81->text().toInt();
    coldphaco1 += 5;
    if (coldphaco1 > 40) {
        coldphaco1 = 40;
    }
    ui->lineEdit_81->setText(QString::number(coldphaco1));
    handler->cold_pulse(coldphaco1);
}

void MainWindow::on_pushButton_55_clicked()
{
    coldphaco1 = ui->lineEdit_81->text().toInt();
    coldphaco1 -= 5;
    if (coldphaco1 < 5) {
        coldphaco1 = 5;
    }
    ui->lineEdit_81->setText(QString::number(coldphaco1));
    handler->cold_pulse(coldphaco1);
}




//handpiece connected or not
void MainWindow::exportGPIO(int pin)
{
   QFile file("/sys/class/gpio/export");
   if (file.open(QIODevice::WriteOnly)) {
       QTextStream stream(&file);
       stream << pin;
       file.close();
     //  qDebug() << "GPIO" << gpioNumber << "exported.";
   }/* else {
     //  qDebug() << "Failed to export GPIO" << gpioNumber;
   }*/
}

void MainWindow::setGPIODirection(const QString &direction,int pin)
{
   QFile file(QString("/sys/class/gpio/gpio%1/direction").arg(pin));
   if (file.open(QIODevice::WriteOnly)) {
       QTextStream stream(&file);
       stream << direction;
       file.close();
      // qDebug() << "GPIO" << gpioNumber << "set to" << direction;
   } /*else {
       qDebug() << "Failed to set direction for GPIO" << gpioNumber;
   }*/
}

int MainWindow::readGPIOValue(int pin)
{
   QFile file(QString("/sys/class/gpio/gpio%1/value").arg(pin));
   if (file.open(QIODevice::ReadOnly)) {
       QTextStream stream(&file);
       int value;
       stream >> value;
       file.close();
       //qDebug() << "Read value from GPIO" << gpioNumber << ":" << value;
       return value;
   } /*else {
       qDebug() << "Failed to read value from GPIO" << gpioNumber;
       return -1;
   }*/
}


int MainWindow::readGPIOValue1()
{
   QFile file(QString("/sys/class/gpio/gpio%1/value").arg(gpioNumber1));
   if (file.open(QIODevice::ReadOnly)) {
       QTextStream stream(&file);
       int value;
       stream >> value;
       file.close();
       //qDebug() << "Read value from GPIO" << gpioNumber << ":" << value;
       return value;
   } /*else {
       qDebug() << "Failed to read value from GPIO" << gpioNumber;
       return -1;
   }*/
}




void MainWindow::updatehandpieceStatus()
{
   int status = readGPIOValue(960);


   QString styleSheet4 = "QLabel {"
              "image: url(:/images/handpiece1.png);"
           "background-color:green;"

               "border: 4px solid black;"
               "border-radius: 20px;"
                                    "}";
   QString styleSheet2 = "QLabel {"
               "image: url(:/tickimg.png);"
           "background-color:transparent;"
      "width:41;"
           "height:41;"
           "border-radius:20px;"
           "border:2px solid black;"
                                    "}";

   QString styleSheet5 = "QLabel {"
              "image: url(:/images/handpiece1.png);"

            "background-color: rgb(192, 28, 40);"
               "border: 4px solid black;"
               "border-radius: 20px;"
                                    "}";
   QString styleSheet6 = "QLabel {"
              "image: url(:/locked.png);"

               "border: 2px solid black;"
               "border-radius: 10px;"
                                    "}";
   QString styleSheet7 = "QLabel {"
              "image: url(:/unlocked.png);"

               "border: 2px solid black;"
               "border-radius: 10px;"
                                    "}";
  if(status==0)
  {
      ui->label_15->setStyleSheet(styleSheet4);
    //  ui->label_7->setStyleSheet(styleSheet2);
   //   qDebug()<<"handpiece on"<<status;
      ui->ULTRASONICBUT1->setEnabled(true);
      ui->ULTRASONICBUT2->setEnabled(true);
      ui->ULTRASONICBUT3->setEnabled(true);
      ui->ULTRASONICBUT4->setEnabled(true);
//      ui->label_8->setStyleSheet(styleSheet7);
//      ui->label_9->setStyleSheet(styleSheet7);
//      ui->label_39->setStyleSheet(styleSheet7);
//      ui->label_38->setStyleSheet(styleSheet7);

  }
  else
  {
      ui->label_15->setStyleSheet(styleSheet5);
      // ui->label_7->setStyleSheet("");
      // qDebug()<<"handpiece off"<<status;
       ui->ULTRASONICBUT1->setEnabled(false);
       ui->ULTRASONICBUT2->setEnabled(false);
       ui->ULTRASONICBUT3->setEnabled(false);
       ui->ULTRASONICBUT4->setEnabled(false);
//       ui->label_8->setStyleSheet(styleSheet6);
//       ui->label_9->setStyleSheet(styleSheet6);
//       ui->label_39->setStyleSheet(styleSheet6);
//       ui->label_38->setStyleSheet(styleSheet6);
    //flag1=false;
  }
}
void MainWindow::onUpdateStatusTimeout(){
   updatehandpieceStatus();
}

void MainWindow::updatesensor()
{
   //footpedal();
   label43();
}
void MainWindow::updateProgressBar() {

}

void MainWindow::motoron(QLineEdit *lineEdit)
{
   int linevalue=lineEdit->text().toInt();
   handler->write_motor(0x01,0x03,linevalue);
   qDebug()<<"motor working";
}

void MainWindow::motoroff()
{
   handler->write_motor(0x00,0x00,0);
}

void MainWindow::motorccwon()
{
   handler->write_motor(0x01,0x02,40);
}
//roundoff value
void MainWindow::increasebutton(QLineEdit *increaseline)
{

     int value =increaseline->text().toInt();
     if(value>=10){
     if (value % 2 == 0) {
              // If the number is even, round it up to the next multiple of 5
              value = (value + 4) / 5 * 5;
          } else {
              // If the number is odd, increment it to make it even
               value = ((value + 4) / 5) * 5;
          }
     }
         increaseline->setText(QString::number(value));
}

void MainWindow::decreasebutton(QLineEdit *decreaseline)
{

     int value1 = decreaseline->text().toInt();
     if(value1>=10){
     if (value1 % 2 != 0) {

              value1++;
          }
     }
     decreaseline->setText(QString::number(value1));
}

void MainWindow::vacbutton(QLineEdit *vacline)
{
   int val =vacline->text().toInt();
   if(val>=99){
   if (val % 2 == 0) {
            // If the number is even, round it up to the next multiple of 5
            val = (val + 3) / 5 * 5;
        } else {
            // If the number is odd, increment it to make it even
             val = ((val + 3) / 5) * 5;
        }}

       vacline->setText(QString::number(val));

}




//NON LINEAR

void MainWindow::label43()
{
   int sensor = vac->convert(0xD7);
    int vac1=ui->lineEdit_55->text().toInt();
     int vac2=ui->lineEdit_60->text().toInt();
      int vac3=ui->lineEdit_63->text().toInt();
       int vac4=ui->lineEdit_66->text().toInt();
        int vac5=ui->lineEdit_70->text().toInt();
         int vac6=ui->lineEdit_68->text().toInt();
          int vac7=ui->lineEdit_73->text().toInt();
   if (sensor > 0 && sensor < 4096) {
     //  int pro = sensor * vac5 / 4096+50;
       int pro=sensor*580/4096;
       int pro1=std::min(vac5,pro);
       ui->label_113->setNum(pro1);
   }
   if (sensor > 0 && sensor < 4096) {
       int pro1 = sensor * 580 / 4096;
      int pro2=std::min(vac6,pro1);
       ui->label_109->setNum(pro2);
   }
   if (sensor > 0 && sensor < 4096) {
       int pro3 = sensor * 580 / 4096;
      int pro4=std::min(vac7,pro3);
       ui->label_118->setNum(pro4);
   }
   if (sensor > 0 && sensor < 4096) {
       int pro4 = sensor * 580 / 4096;
      int pro5=std::min(vac4,pro4);
       ui->label_104->setNum(pro5);
   }
   if (sensor > 0 && sensor < 4096) {
       int pro5 = sensor * 580 / 4096;
       int pro6=std::min(vac3,pro5);
       ui->label_99->setNum(pro6);
   }
   if (sensor > 0 && sensor < 4096) {
       int pro6 = sensor * 580 / 4096;
      int pro7=std::min(vac2,pro6);
       ui->label_93->setNum(pro7);
   }
   if (sensor > 0 && sensor < 4096) {
       int pro7 = sensor * 580 / 4096;
       int pro8=std::min(vac1,pro7);
       ui->label_8->setNum(pro8);
   }


}

void MainWindow::sensor2()
{

   int sensor = vac->convert(0xD7);
    int vac1=ui->lineEdit_55->text().toInt();
     int vac2=ui->lineEdit_60->text().toInt();
      int vac3=ui->lineEdit_63->text().toInt();
       int vac4=ui->lineEdit_66->text().toInt();
        int vac5=ui->lineEdit_70->text().toInt();
         int vac6=ui->lineEdit_68->text().toInt();
          int vac7=ui->lineEdit_73->text().toInt();
   if (sensor > 0 && sensor < 4096) {
     //  int pro = sensor * vac5 / 4096+50;
       int pro=sensor*580/4096;
       pro=std::min(vac5,pro);
       ui->label_113->setText(QString::number(pro));
   }
   if (sensor > 0 && sensor < 4096) {
       int pro1 = sensor * 580 / 4096;
       pro1=std::min(vac6,pro1);
       ui->label_109->setText(QString::number(pro1));
   }
   if (sensor > 0 && sensor < 4096) {
       int pro3 = sensor * 580 / 4096;
       pro3=std::min(vac7,pro3);
       ui->label_118->setText(QString::number(pro3));
   }
   if (sensor > 0 && sensor < 4096) {
       int pro4 = sensor * 580 / 4096;
       pro4=std::min(vac4,pro4);
       ui->label_104->setText(QString::number(pro4));
   }
   if (sensor > 0 && sensor < 4096) {
       int pro5 = sensor * 580 / 4096;
       pro5=std::min(vac3,pro5);
       ui->label_99->setText(QString::number(pro5));
   }
   if (sensor > 0 && sensor < 4096) {
       int pro6 = sensor * 580 / 4096;
       pro6=std::min(vac2,pro6);
       ui->label_93->setText(QString::number(pro6));
   }
   if (sensor > 0 && sensor < 4096) {
       int pro7 = sensor * 580 / 4096;
       pro7=std::min(vac1,pro7);
       ui->label_8->setText(QString::number(pro7));
   }



   }





void MainWindow::powervit()
{

}

void MainWindow::powercheck()
{

       qDebug()<<"its working";

}
void MainWindow::updateTimers()
{
   if (currentButton != -1) {
       qint64 elapsed = currentTimer.elapsed();
       qint64 totalTime = elapsedTimeUS1 + elapsedTimeUS2 + elapsedTimeUS3 + elapsedTimeUS4;

       switch (currentButton) {
           case 1:
               totalTime += elapsed;
               break;
           case 2:
               totalTime += elapsed;
               break;
           case 3:
               totalTime += elapsed;
               break;
           case 4:
               totalTime += elapsed;
               break;
       }

       ui->elapsed_time->setText(QString::number(totalTime / 1000.0, 'f', 2) + " s");
   }
}
void MainWindow::updateLabel()
{
   qint64 totalTime = elapsedTimeUS1 + elapsedTimeUS2 + elapsedTimeUS3 + elapsedTimeUS4;
   ui->elapsed_time->setText(QString::number(totalTime / 1000.0, 'f', 2) + " s");
}

void MainWindow::savesettings()
{
     QMessageBox::information(this, "Settings", "Foot pedal settings have been updated.");
}


void MainWindow::settings_action(int index)
{
   //decrement
   if(index ==1)
   {
       //counter = 0;
        switch (counter % 8) {
            case 0:
                ui->DIABUT->setFocus();
                break;
            case 1:
                ui->ULTRASONICBUT1->setFocus();
                break;
            case 2:
                ui->ULTRASONICBUT2->setFocus();
                break;
            case 3:
                ui->ULTRASONICBUT3->setFocus();
                break;
            case 4:
                ui->ULTRASONICBUT4->setFocus();
                break;
            case 5:
                ui->IA1BUT->setFocus();
                break;
            case 6:
                ui->IA2BUT->setFocus();
                break;
            case 7:
                ui->VITRECTOMYBUT->setFocus();
                break;
        }
        counter++;
   }
}
void MainWindow::updateButtonSelection(int index)
{
   currentButtonIndex = index;

   // Deselect all buttons
   ui->DIABUT->setChecked(false);
   ui->ULTRASONICBUT1->setChecked(false);
   ui->ULTRASONICBUT2->setChecked(false);
   ui->ULTRASONICBUT3->setChecked(false);
   ui->ULTRASONICBUT4->setChecked(false);
   ui->IA1BUT->setChecked(false);
   ui->IA2BUT->setChecked(false);
   ui->VITRECTOMYBUT->setChecked(false);

   // Select the current button
   switch (index)
   {
       case 0: ui->DIABUT->setChecked(true); break;
       case 1: ui->ULTRASONICBUT1->setChecked(true); break;
       case 2: ui->ULTRASONICBUT2->setChecked(true); break;
       case 3: ui->ULTRASONICBUT3->setChecked(true); break;
       case 4: ui->ULTRASONICBUT4->setChecked(true); break;
         case 5: ui->IA1BUT->setChecked(true); break;
         case 6: ui->IA2BUT->setChecked(true); break;
         case 7: ui->VITRECTOMYBUT->setChecked(true); break;
       default: return; // Guard against invalid indices
   }

   // Change the tab in the tab widget
   ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::movePushButtonTopToBottom()
{

   if (currentButtonIndex < 6)
   {
       updateButtonSelection(++currentButtonIndex);
   }
   qDebug()<<"increment opration is working";
}

void MainWindow::movePushButtonBottomToTop()
{
   if (currentButtonIndex > 0)
   {
       updateButtonSelection(--currentButtonIndex);
   }
   qDebug()<<"decrement operation is working";
}

void MainWindow::footreflux()
{
   bool flag=!flag;
   if(flag==true){
 motorccwon();
 qDebug()<<"footreflux";}
   else{
       motoroff();
   }
}

void MainWindow::powerdeliverymethod()
{
  updateline();
  qDebug()<<"pdm mode";
}

void MainWindow::continousirrigation()
{
   handler->pinchvalve_on();
   handler->safetyvent_on();
   qDebug()<<"continous irrigation";
}

void MainWindow::poweronoff()
{
  poweron();
}

void MainWindow::poweron()
{
  on_us1onoff_clicked();
  on_us2onoff_clicked();
  on_us3onoff_clicked();
  on_us4onoff_clicked();
}
void MainWindow::onMainLineEditTextChanged(const QString &dpowmax) {

//ui->lineEdit_74->setText(dpowmax);
}


void MainWindow::on_us1onoff_clicked()
{

   QString buttonText = ui->us1onoff->text();
int range = lfoot->convert(0x97);
   // Style for ON state
   QString styleSheetOn = "QPushButton {"
                           " font:20pt Ubuntu;"
                           " background-color: green;"
                           " color: black;"
                           " border:5px solid black;"
                           " border-radius:30px; font-weight: bold;"
                           "}";

   // Style for OFF state
   QString styleSheetOff = "QPushButton {"
                            " font:20pt Ubuntu;"
                            " background-color: rgb(224, 27, 36);"
                            " color: black;"
                            " border:5px solid black;"
                            " border-radius:30px; font-weight: bold;"
                            "}";

   // Update button state
   power.buttonState = buttonText;

   if (power.buttonState == "OFF" && (range > 0)) {
       ui->us1onoff->setStyleSheet(styleSheetOn);
       ui->us1onoff->setText("ON");
       power.buttonState = "ON";

power.powerOn1 = true;
   } else {
       ui->us1onoff->setStyleSheet(styleSheetOff);
       ui->us1onoff->setText("OFF");
       power.buttonstate1 = "OFF";
       power.powerOn1 = false;

   }
}


void MainWindow::on_us2onoff_clicked()
{
   QString text = ui->us2onoff->text();

   int range = lfoot->convert(0x97);

   // Debugging statements
   qDebug() << "Button text: " << text;

   qDebug() << "Foot pedal range value: " << range;

   QString styleSheet1 = "QPushButton {"
                         " font:20pt Ubuntu;"
                         " background-color: green;"
                         " color: black;"
                         " border:5px solid black;"
                         " border-radius:30px;font-weight: bold;"
                         "}";

   QString styleSheet2 = "QPushButton {"
                         " font:20pt Ubuntu;"
                         " background-color: rgb(224, 27, 36);"
                         " color: black;"
                         " border:5px solid black;"
                         " border-radius:30px;font-weight: bold;"
                         "}";

   power.buttonstate1 = text;
   qDebug() << "Initial button state: " << power.buttonstate1;

   // Simplify condition for testing
   if (power.buttonstate1 == "OFF" && (range > 0)) {
       qDebug() << "Condition met to turn ON power (Simplified)";

       ui->us2onoff->setStyleSheet(styleSheet1);
       ui->us2onoff->setText("ON");
       power.buttonstate1 = "ON";

       power.powerOn1=true;
       qDebug() << "Power is turned ON";
   } else {
       qDebug() << "Condition met to turn OFF power";

       ui->us2onoff->setStyleSheet(styleSheet2);
       ui->us2onoff->setText("OFF");
       power.buttonstate1 = "OFF";
       power.powerOn1 = false;  // Update power state
       qDebug() << "Power is turned OFF";
   }

   qDebug() << "Updated button state: " << power.buttonstate1;
   qDebug() << "Updated power state: " << power.powerOn1;
}


void MainWindow::on_us3onoff_clicked()
{
   int range = lfoot->convert(0x97);
   QString text=ui->us3onoff->text();

   QString styleSheet1 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: green;"
           "color: black;"

          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";

   QString styleSheet2 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: rgb(224, 27, 36);"
           "color: black;"
           //"image: url(:/ci.png);"
          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"

          "}";
   power.buttonstate2=text;
   if(power.buttonstate2=="OFF" && (range>0)){
       ui->us3onoff->setStyleSheet(styleSheet1);
       ui->us3onoff->setText("ON");
       power.buttonstate2 = "ON";

       power.powerOn2 = true;  // Update power state
   }
   else{
       ui->us3onoff->setStyleSheet(styleSheet2);
       ui->us3onoff->setText("OFF");
       power.buttonstate2 = "OFF";



       power.powerOn2 = false;  // Update power state
   }
}

void MainWindow::on_us4onoff_clicked()
{
   int range = lfoot->convert(0x97);
   QString text=ui->us4onoff->text();

   QString styleSheet1 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: green;"
           "color: black;"

          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";

   QString styleSheet2 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: rgb(224, 27, 36);"
           "color: black;"
           //"image: url(:/ci.png);"
          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"

          "}";
   power.buttonstate3=text;
   if(power.buttonstate3=="OFF" && (range>0)){
       ui->us4onoff->setStyleSheet(styleSheet1);
       ui->us4onoff->setText("ON");
       power.buttonstate3 = "ON";

       power.powerOn3 = true;  // Update power state
   }
   else{
       ui->us4onoff->setStyleSheet(styleSheet2);
       ui->us4onoff->setText("OFF");
       power.buttonstate2 = "OFF";


       power.powerOn3 = false;  // Update power state
   }
}

void MainWindow::on_vitonoff_clicked()
{
   QString text=ui->vitonoff->text();

   int range = lfoot->convert(0x97);
   QString styleSheet1 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: green;"
           "color: black;"

          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"
                                "}";

   QString styleSheet2 = "QPushButton {"
          " font:20pt Ubuntu;"
         " background-color: rgb(224, 27, 36);"
           "color: black;"
           //"image: url(:/ci.png);"
          " border:5px solid black;"
          " border-radius:30px;font-weight: bold;"

          "}";
   power.buttonstate4=text;
   if(power.buttonstate4=="OFF" && (range>0)){
       ui->vitonoff->setStyleSheet(styleSheet1);
       ui->vitonoff->setText("ON");
       power.buttonstate4= "ON";


       power.powerOn4 = true;  // Update power state
   }
   else{
       ui->vitonoff->setStyleSheet(styleSheet2);
       ui->vitonoff->setText("OFF");
       power.buttonstate4 = "OFF";

       power.powerOn4 = false;  // Update power state
   }

}

void MainWindow::on_pushButton_4_clicked()
{

   in->show();

   connect(in, &doctor::leftfoot, foot, &footpedal::combobox1);

   connect(in, &doctor::rightfoot, foot, &footpedal::combobox2);

   connect(in, &doctor::bottomleft, foot, &footpedal::combobox3);

   connect(in, &doctor::bottomright, foot, &footpedal::combobox4);

   in->exec(); // Open as a modal dialog to wait for user input

}



//value update doctor window to mainwindow

void MainWindow::updateValues(const QString &surgeon, int tabIndex, const QStringList &values) {
   surgeonData[surgeon][tabIndex] = values;
   if (ui->comboBox_4->currentText() == surgeon) {
       onSurgeonChanged();
   }
}

void MainWindow::onSurgeonChanged() {
   QString surgeon = ui->comboBox_4->currentText();

   if (surgeonData.contains(surgeon)) {
       if (surgeonData[surgeon].contains(0)) {
           QStringList values = surgeonData[surgeon][0];
           ui->lineEdit_57->setText(values.at(0));
           ui->lineEdit_55->setText(values.at(1));
           ui->lineEdit_56->setText(values.at(2));
           ui->CutMode_vitCom->setCurrentText(values.at(3));
           ui->us1mode->setText(values.at(4));
           ui->us1vacmode->setText(values.at(5));
       }

       if (surgeonData[surgeon].contains(1)) {
           QStringList values = surgeonData[surgeon][1];
           ui->lineEdit_58->setText(values.at(0));
           ui->lineEdit_60->setText(values.at(1));
           ui->lineEdit_59->setText(values.at(2));
           ui->CutMode_vitCom_2->setCurrentText(values.at(3));
           ui->us2mode->setText(values.at(4));
           ui->us2vacmode->setText(values.at(5));
       }

       if (surgeonData[surgeon].contains(2)) {
           QStringList values = surgeonData[surgeon][2];
           ui->lineEdit_61->setText(values.at(0));
           ui->lineEdit_63->setText(values.at(1));
           ui->lineEdit_62->setText(values.at(2));
           ui->CutMode_vitCom_3->setCurrentText(values.at(3));
           ui->us3mode->setText(values.at(4));
           ui->us3vacmode->setText(values.at(5));
       }

       if (surgeonData[surgeon].contains(3)) {
           QStringList values = surgeonData[surgeon][3];
           ui->lineEdit_64->setText(values.at(0));
           ui->lineEdit_66->setText(values.at(1));
           ui->lineEdit_65->setText(values.at(2));
           ui->CutMode_vitCom_4->setCurrentText(values.at(3));
           ui->us4mode->setText(values.at(4));
           ui->us4vacmode->setText(values.at(5));
       }
       if (surgeonData[surgeon].contains(4)) {
           QStringList values = surgeonData[surgeon][4];
           ui->lineEdit_74->setText(values.at(0));
       }
       if(surgeonData[surgeon].contains(5)){
           QStringList values =surgeonData[surgeon][5];
           ui->lineEdit_70->setText(values.at(0));
           ui->lineEdit_69->setText(values.at(1));
           ui->ia1mode->setText(values.at(2));
           ui->lineEdit_68->setText(values.at(3));
           ui->lineEdit_67->setText(values.at(4));
           ui->ia2mode->setText(values.at(5));
       }
       if (surgeonData[surgeon].contains(6)) {
           QStringList values = surgeonData[surgeon][6];
           ui->lineEdit_71->setText(values.at(0));
           ui->vitmode->setText(values.at(1));
           ui->lineEdit_73->setText(values.at(2));
           ui->vitvacmode->setText(values.at(3));
        ui->lineEdit_72->setText(values.at(4));

       }
   } else {
       ui->lineEdit_57->clear();
       ui->lineEdit_55->clear();
       ui->lineEdit_56->clear();
       ui->CutMode_vitCom->setCurrentIndex(-1);
       ui->us1vacmode->setText("");

       ui->lineEdit_58->clear();
       ui->lineEdit_60->clear();
       ui->lineEdit_59->clear();
       ui->CutMode_vitCom_2->setCurrentIndex(-1);
       ui->us2vacmode->setText("");

       ui->lineEdit_61->clear();
       ui->lineEdit_63->clear();
       ui->lineEdit_62->clear();
       ui->CutMode_vitCom_3->setCurrentIndex(-1);
       ui->us3vacmode->setText("");

       ui->lineEdit_64->clear();
       ui->lineEdit_66->clear();
       ui->lineEdit_65->clear();
       ui->CutMode_vitCom_4->setCurrentIndex(-1);
       ui->us4vacmode->setText("");
       ui->lineEdit_74->clear();
       ui->lineEdit_70->clear();
       ui->lineEdit_69->clear();
       ui->lineEdit_68->clear();
       ui->lineEdit_67->clear();
       ui->ia1mode->setText("");
       ui->ia2mode->setText("");
       ui->lineEdit_71->clear();
       ui->lineEdit_73->clear();
         ui->lineEdit_72->clear();
       ui->vitmode->setText("");
       ui->vitvacmode->setText("");
   }
}

void MainWindow::updateComboBox1(const QString &text) {
   ui->CutMode_vitCom->setCurrentText(text);
   updateTabsBasedOnComboBox(text);
}

void MainWindow::updateComboBox2(const QString &text) {
   ui->CutMode_vitCom_2->setCurrentText(text);
   updateTabsBasedOnComboBox(text);
}

void MainWindow::updateComboBox3(const QString &text) {
   ui->CutMode_vitCom_3->setCurrentText(text);
   updateTabsBasedOnComboBox(text);
}

void MainWindow::updateComboBox4(const QString &text) {
   ui->CutMode_vitCom_4->setCurrentText(text);
   updateTabsBasedOnComboBox(text);
}
void MainWindow::onCutMode_vitComChanged(int index) {
   QString modeText = ui->CutMode_vitCom->currentText();
   qDebug() << "Selected Mode as Text:" << modeText;

   // Print current index and all items for further inspection
   qDebug() << "Current Index:" << index;
   QStringList allItems;
   for (int i = 0; i < ui->CutMode_vitCom->count(); ++i) {
       allItems << ui->CutMode_vitCom->itemText(i);
   }
   qDebug() << "All ComboBox Items:" << allItems;

   updateTabsBasedOnComboBox(modeText);
}

void MainWindow::onCutMode_vitComChanged1(int index) {
   QString currentText = ui->CutMode_vitCom_2->currentText();
   updateTabsBasedOnComboBox(currentText);
}

void MainWindow::onCutMode_vitComChanged2(int index) {
   QString currentText = ui->CutMode_vitCom_3->currentText();
   updateTabsBasedOnComboBox(currentText);
}

void MainWindow::onCutMode_vitComChanged3(int index) {
   QString currentText = ui->CutMode_vitCom_4->currentText();
   updateTabsBasedOnComboBox(currentText);
}

void MainWindow::updateTabsBasedOnComboBox(const QString &selected) {
   qDebug() << "Selected Mode as Text:" << selected;

   // Default action: Log unknown mode
   bool modeFound = false;

   // Call the appropriate function based on the selected mode
   if (selected == "Continuous") {
       handler->pdm_mode(CONTINOUS);
       ui->tabWidget_2->setCurrentIndex(0); // Adjust the tab index for Continuous mode
       modeFound = true;
       qDebug() << "Continuous mode selected";
   } else if (selected == "Pulse") {
       handler->pdm_mode(PULSE_MODE);
       on_pushButton_5_clicked();
       on_pushButton_6_clicked();
       ui->tabWidget_2->setCurrentIndex(1); // Tab index for Pulse
       modeFound = true;
       qDebug() << "Pulse mode selected";
   } else if (selected == "Ocupulse") {
       handler->pdm_mode(OCUPULSE);
       on_pushButton_44_clicked();
       on_pushButton_45_clicked();
       ui->tabWidget_2->setCurrentIndex(2); // Tab index for Ocupulse
       modeFound = true;
       qDebug() << "Ocupulse mode selected";
   } else if (selected == "Ocuburst") {
       handler->pdm_mode(OCUBURST);
       on_pushButton_46_clicked();
       on_pushButton_47_clicked();
       ui->tabWidget_2->setCurrentIndex(3); // Tab index for Ocuburst
       modeFound = true;
       qDebug() << "Ocuburst mode selected";
   } else if (selected == "Single burst") {
       handler->pdm_mode(SINGLE_BURST);
       on_pushButton_48_clicked();
       on_pushButton_49_clicked();
       ui->tabWidget_2->setCurrentIndex(4); // Tab index for Single burst
       modeFound = true;
       qDebug() << "Single burst mode selected";
   } else if (selected == "Multi burst") {
       handler->pdm_mode(MULTI_BURST);
       on_pushButton_50_clicked();
       on_pushButton_51_clicked();
       ui->tabWidget_2->setCurrentIndex(5); // Tab index for Multi burst
       modeFound = true;
       qDebug() << "Multi burst mode selected";
   } else if (selected == "Cold phaco") {
       handler->pdm_mode(COLD_PHACO);
       on_pushButton_52_clicked();
       on_pushButton_53_clicked();
       on_pushButton_54_clicked();
       on_pushButton_55_clicked();
       ui->tabWidget_2->setCurrentIndex(6); // Tab index for Cold phaco

       modeFound = true;
       qDebug() << "Cold phaco mode selected";
   }

   if (!modeFound) {
       qDebug() << "Unknown mode selected!";
   }

   // Print to the debug output
   qDebug() << "Mode is working: " << selected;

   // Update multiple line edits with the selected value
   ui->lineEdit_75->setText("15");
   ui->lineEdit_76->setText("15");
   ui->lineEdit_77->setText("170");
   ui->lineEdit_78->setText("400");
   ui->lineEdit_79->setText("400");
   ui->lineEdit_80->setText("15");
   ui->lineEdit_81->setText("40");
}



int MainWindow::getvalue(int input)
{
   if(input<=60){
       return 60;
   }else{
       return ((input-1)/60+1)*60;
   }
}

void MainWindow::on_SETTINGS_BUT_3_clicked()
{
    foot->show();
}

void MainWindow::on_CI5_2_clicked()
{

    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

              "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!cidia ){
      ui->CI5_2->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI5_2->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
cidia=!cidia;
}

void MainWindow::on_CI1_clicked()
{

    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!cius1){
      ui->CI1->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI1->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
cius1=!cius1;
}

void MainWindow::on_CI2_clicked()
{

    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!cius2 ){
      ui->CI2->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI2->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
cius2=!cius2;
}

void MainWindow::on_CI3_clicked()
{
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!cius3 ){
      ui->CI3->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI3->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
cius3=!cius3;
}

void MainWindow::on_CI4_clicked()
{
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!cius4 ){
      ui->CI4->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI4->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
cius4=!cius4;
}

void MainWindow::on_CI5_3_clicked()
{
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!ci_ia1 ){
      ui->CI5_3->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI5_3->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
ci_ia1=!ci_ia1;
}

void MainWindow::on_CI5_4_clicked()
{
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!ci_ia2 ){
      ui->CI5_4->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI5_4->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
ci_ia2=!ci_ia2;
}

void MainWindow::on_CI5_clicked()
{
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(!civit ){
      ui->CI5->setStyleSheet(styleSheet3);
      handler->pinchvalve_on();
      handler->safetyvent_on();

       // qDebug()<<"gpio pin for ci:"<<gpio;
    }
    else{

        ui->CI5->setStyleSheet(styleSheet4);
        handler->pinchvalve_off();
        handler->safetyvent_off();

    }
civit=!civit;
}
