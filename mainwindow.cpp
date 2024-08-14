#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"footpedal.h"

#include <QTimer>
#include<cmath>
#include<QStyleFactory>
#include<QSqlError>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , elapsedTimeUS1(0)
    , elapsedTimeUS2(0)
    , elapsedTimeUS3(0)
    , elapsedTimeUS4(0)
    , butname(-1)
    ,isTuneEnabled(false)
      ,powerOn1(false)
   ,overallci(false)
{
    ui->setupUi(this);
   // resize(800,600);
    move(0,0);

    vac=new Vaccum;
    handler=new hwhandler;
   // de=new demo;
    db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbPath = "/home/amt-04/phacohigh.db";  // Ensure this path is correct
    db.setDatabaseName(PATH1);
  //initializeSurgeonSelection();
 connectToDatabase();
 populateSurgeonList();

    ui->CutMode_vit->hide();
    ui->CutMode_vitCom->hide();
    ui->tabWidget_2->hide();
     foot=new footpedal;
   in=new doctor;
   ui->dial_2->setStyleSheet("");
   ui->dial_2->setStyle(QStyleFactory::create("Fusion"));
   ui->dial_2->setStyleSheet("background-color: rgb(26, 95, 180);");
   ui->dial_2->setRange(0, 4096);
   // Initialize the buttons array
     buttons[1] = ui->ULTRASONICBUT1;
     buttons[2] = ui->ULTRASONICBUT2;
     buttons[3] = ui->ULTRASONICBUT3;
     buttons[4] = ui->ULTRASONICBUT4;
     buttons[5] = ui->IA1BUT;
     buttons[6] = ui->IA2BUT;
     buttons[7] = ui->VITRECTOMYBUT;
     buttons[0] = ui->DIABUT;

     // Initialize buttonforgpio to start from the first button
     buttonforgpio = 0;
     for (int i = 0; i < 7; ++i) {
           buttons[i] = new QPushButton(QString("Button %1").arg(i + 1), this);
           // Set button positions, etc.
       }
     // Set the initial button as selected
     buttons[buttonforgpio]->setChecked(true);
     QTimer *readgpio=new QTimer;
     connect(readgpio,&QTimer::timeout,this,&MainWindow::readGPIO);
     readgpio->start(100);
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateTimers);

  connect(ui->CI5_5,&QPushButton::clicked,this,&MainWindow::on_CI4_2_clicked);

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
       connect(in,&doctor::sendValues,this,&MainWindow::receiveValues);
       QTimer *timerdia=new QTimer;

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
    protimer=new QTimer;

        // Set the initial state of pushButton_9

    QTimer *timerfoot = new QTimer;
    timer43=new QTimer;
    QTimer *ftime=new QTimer;

  //  connect(ui->comboBox_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::push);

    connect(timerfoot, &QTimer::timeout, this, &MainWindow::updatesensor);
       timerfoot->start(100); // 100 milliseconds interval
       sensortimer = new QTimer(this);
       connect(sensortimer, SIGNAL(timeout()), this, SLOT(sensor2()));
       sensortimer->start(100); // Update labels every 1000 milliseconds (1 second)
    ui->lineEdit_57->setText("100");

    exportGPIO(960);
    setGPIODirection("in",960);
    exportGPIO(961);
      setGPIODirection("in",961);
      exportGPIO(962);
      setGPIODirection("in",962);
      exportGPIO(963);
      setGPIODirection("in",963);
      exportGPIO(964);
      setGPIODirection("in",964);

    // Update status initially
    updatehandpieceStatus();
  ui->us1powup_but->setEnabled(false);
  ui->us1powdown_but->setEnabled(false);
ui->us2powup_but->setEnabled(false);
ui->us2powdown_but->setEnabled(false);
ui->us3powup_but->setEnabled(false);
ui->us3powdown_but->setEnabled(false);
ui->us4powup_but->setEnabled(false);
ui->us4powdown_but->setEnabled(false);
ui->vitpowup_but->setEnabled(false);
ui->vitpowdown_but->setEnabled(false);

    // Setup a timer to periodically update the status
    statusUpdateTimer = new QTimer(this);
    connect(statusUpdateTimer, &QTimer::timeout, this, &MainWindow::onUpdateStatusTimeout);
    statusUpdateTimer->start(500); // Update every second
    //lineedit value givennnnn
//us1
   ui->lineEdit_57->setText("100");
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
    protimer->start(500);
    connect(foot, &footpedal::moveTopToBottom, this, &MainWindow::movePushButtonTopToBottom);
    connect(foot, &footpedal::moveBottomToTop, this, &MainWindow::movePushButtonBottomToTop);
   connect(foot,&footpedal::performReflux,this,&MainWindow::footreflux);
   connect(foot,&footpedal::togglePower,this,&MainWindow::poweronoff);
   connect(foot,&footpedal::continous_irrigation,this,&MainWindow::continousirrigation);
   connect(foot,&footpedal::powerdm,this,&MainWindow::onPdmModeSelected);
connect(foot,&footpedal::powerdm,this,&MainWindow::onPdmModeSelected1);
connect(foot,&footpedal::powerdm,this,&MainWindow::onPdmModeSelected2);
connect(foot,&footpedal::powerdm,this,&MainWindow::onPdmModeSelected3);
connect(this,&MainWindow::surgeonSelected,foot,&footpedal::updateFootpedalComboBoxes);
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
    //ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
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


     connect(ui->comboBox_4, &QComboBox::currentTextChanged, this, &MainWindow::onSurgeonSelectionChanged);
     connect(ui->comboBox,&QComboBox::currentTextChanged,this,&MainWindow::performpump);
     // Connect QComboBox signals to the slot
//     connect(ui->CutMode_vitCom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
//     connect(ui->CutMode_vitCom_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
//     connect(ui->CutMode_vitCom_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
//     connect(ui->CutMode_vitCom_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);

     connect(ui->CutMode_vitCom, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateTabsBasedOnComboBox);
      connect(ui->CutMode_vitCom_2, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateTabsBasedOnComboBox);
      connect(ui->CutMode_vitCom_3, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateTabsBasedOnComboBox);
    connect(ui->CutMode_vitCom_4, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateTabsBasedOnComboBox);
//   // connect(ui->CutMode_vitCom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
//     //  connect(ui->CutMode_vitCom_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged1);
//    //   connect(ui->CutMode_vitCom_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged2);
//    //   connect(ui->CutMode_vitCom_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCutMode_vitComChanged3);
   int currenttab=7;

     connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::current);

          current(currenttab);
       connect(ui->lineEdit_73,&QLineEdit::textChanged,this,[=](){
        int value3=ui->lineEdit_73->text().toInt();

    });
    connect(ui->lineEdit_72,&QLineEdit::textChanged,this,[=](){
        int value4=ui->lineEdit_72->text().toInt();

       });

    connect(ui->lineEdit_68,&QLineEdit::textChanged,this,[=](){
        int value5=ui->lineEdit_68->text().toInt();
             });
       connect(ui->lineEdit_67,&QLineEdit::textChanged,this,[=](){
        int value6=ui->lineEdit_67->text().toInt();

       });

    connect(ui->lineEdit_70,&QLineEdit::textChanged,this,[=](){
        int value7=ui->lineEdit_70->text().toInt();

       });

    connect(ui->lineEdit_69,&QLineEdit::textChanged,this,[=](){
        int value8=ui->lineEdit_69->text().toInt();

       });

    connect(ui->lineEdit_57,&QLineEdit::textChanged,this,[=](){
        int value9=ui->lineEdit_57->text().toInt();

       });

    connect(ui->lineEdit_55,&QLineEdit::textChanged,this,[=](){
        int value10=ui->lineEdit_55->text().toInt();
              });
     connect(ui->lineEdit_56,&QLineEdit::textChanged,this,[=](){
        int value11=ui->lineEdit_56->text().toInt();

       });

    connect(ui->lineEdit_58,&QLineEdit::textChanged,this,[=](){
        int value12=ui->lineEdit_58->text().toInt();

       });

    connect(ui->lineEdit_60,&QLineEdit::textChanged,this,[=](){
        int value13=ui->lineEdit_60->text().toInt();

       });

    connect(ui->lineEdit_59,&QLineEdit::textChanged,this,[=](){
        int value14=ui->lineEdit_59->text().toInt();

       });

    connect(ui->lineEdit_64,&QLineEdit::textChanged,this,[=](){
        int value15=ui->lineEdit_64->text().toInt();

       });

    connect(ui->lineEdit_66,&QLineEdit::textChanged,this,[=](){
        int value16=ui->lineEdit_66->text().toInt();

       });

    connect(ui->lineEdit_65,&QLineEdit::textChanged,this,[=](){
        int value17=ui->lineEdit_65->text().toInt();

       });

    connect(ui->lineEdit_61,&QLineEdit::textChanged,this,[=](){
        int value18=ui->lineEdit_61->text().toInt();

       });

    connect(ui->lineEdit_63,&QLineEdit::textChanged,this,[=](){
        int value19=ui->lineEdit_63->text().toInt();

       });

    connect(ui->lineEdit_62,&QLineEdit::textChanged,this,[=](){
        int value20=ui->lineEdit_62->text().toInt();

       });
        //   connect(&updateTimer, &QTimer::timeout, this, &MainWindow::update);
    QRegExp regex3("^(?:100|[1-9]\\d?|0)$");
    // QRegExpValidator* validator3 = new QRegExpValidator(regex3, ui->lineEdit);
   //  ui->lineEdit_57->setValidator(validator3);
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
       connect(ui->SETTINGS_BUT_4,&QPushButton::clicked,this,&MainWindow::SETTINGSBUT);
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

      //window
      //connect(ui->doctor,&QPushButton::clicked,this,&MainWindow::doctorwindow_show);
      connect(ui->SETTINGS_BUT_3,&QPushButton::clicked,this,&MainWindow::footpedalwindow_show);
      //pdm mode
      connect(ui->pulseup_but,&QPushButton::clicked,this,&MainWindow::pulseup_mode);
      connect(ui->pulsedown_but,&QPushButton::clicked,this,&MainWindow::pulsedown_mode);
      connect(ui->ocupulseup_but,&QPushButton::clicked,this,&MainWindow::ocupulseup_mode);
      connect(ui->ocupulsedown_but,&QPushButton::clicked,this,&MainWindow::ocupulsedown_mode);
      connect(ui->ocuburstup_but,&QPushButton::clicked,this,&MainWindow::ocuburstup_mode);
      connect(ui->ocuburstdown_but,&QPushButton::clicked,this,&MainWindow::ocuburstdown_mode);
      connect(ui->singleburstup_but,&QPushButton::clicked,this,&MainWindow::singleburstup_mode);
      connect(ui->singleburstdown_but,&QPushButton::clicked,this,&MainWindow::singleburstdown_mode);
      connect(ui->multiburstup_but,&QPushButton::clicked,this,&MainWindow::multiburstup_mode);
      connect(ui->multiburstdown_but,&QPushButton::clicked,this,&MainWindow::multiburstdown_mode);
      connect(ui->coldphacoup_but,&QPushButton::clicked,this,&MainWindow::coldphacoup_mode);
      connect(ui->coldphacodown_but,&QPushButton::clicked,this,&MainWindow::coldphacodown_mode);
      connect(ui->coldphaco1up_but,&QPushButton::clicked,this,&MainWindow::coldphaco1up_mode);
      connect(ui->coldphaco1up_but,&QPushButton::clicked,this,&MainWindow::coldphaco1down_mode);

      us1_linear_nonlinear();
      us2_linear_nonlinear();
      us3_linear_nonlinear();
      us4_linear_nonlinear();
      ia1_linear_nonlinear();
      ia2_linear_nonlinear();
      vit_linear_nonlinear();


//  push("Surgeon 1");
      onSurgeonSelectionChanged("Surgeon 1");
}
//pushbutton pushbutton
void MainWindow::click()
{

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
         timermsg->start(3000); // Start the timer for 3000ms
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
      if(object == ui->lineEdit_60&& event->type() == QEvent::MouseButtonPress) {
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
      if(object == ui->lineEdit_61&& event->type() == QEvent::MouseButtonPress) {
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
      if(value==0){
          ui->lineEdit_57->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_55->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_56->setText(QString::number(2));
          return;}
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
      if(value==0){
          ui->lineEdit_58->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_60->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_59->setText(QString::number(2));
          return;}
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
      if(value==0){
          ui->lineEdit_61->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_63->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_62->setText(QString::number(2));
          return;}
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
      if(value==0){
          ui->lineEdit_64->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_66->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_65->setText(QString::number(2));
          return;}
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
      if(value==0){
          ui->lineEdit_70->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_69->setText(QString::number(2));
          return;}
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
      if(value==0){
          ui->lineEdit_68->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_67->setText(QString::number(2));
          return;}
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
      if(value==0){
          ui->lineEdit_71->setText(QString::number(5));
          return;}
      setRange(ui->lineEdit_71, prevValue, value, 960);
       updateLineedit(ui->lineEdit_71, prevValue, value, 960);

  }
   if(ui->lineEdit_73->focusWidget()) {
      ui->lineEdit_71->clearFocus();
      ui->lineEdit_72->clearFocus();
      ui->lineEdit_73->setFocus();
      int prevValue = ui->lineEdit_73->text().toInt();
      int value = (ui->lineEdit_73->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_73->setText(QString::number(5));
          return;}
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
      if(value==0){
          ui->lineEdit_72->setText(QString::number(2));
          return;}
      setRange(ui->lineEdit_72, prevValue, value, 40);
       updateLineedit(ui->lineEdit_72, prevValue, value, 40);
       decreasebutton(ui->lineEdit_72);
    //  userMessage(value,2,40);

  }
  //DIATHERMY
  if (ui->lineEdit_74->focusWidget()) {
      ui->lineEdit_74->setFocus();
      int prevValue = ui->lineEdit_74->text().toInt();

      int value = (ui->lineEdit_74->text() + digit).toInt();
      if(value==0){
          ui->lineEdit_74->setText(QString::number(5));
          return;}
          setRange(ui->lineEdit_74, prevValue, value, 100);
          updateLineedit(ui->lineEdit_74, prevValue, value, 100);
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
    ui->CutMode_vit->show();
    ui->CutMode_vitCom->show();
    ui->tabWidget_2->show();
    butname=1;
    handler->buzz();
 }


void MainWindow::ULTRASONICBUT2()
{
    ui->tabWidget->setCurrentIndex(1);
    QString currentText = ui->CutMode_vitCom_2->currentText();
    updateTabsBasedOnComboBox(currentText);

    ui->CutMode_vit->show();
    ui->CutMode_vitCom->show();
    ui->tabWidget_2->show();
    butname=2;
  handler->buzz();
}
void MainWindow::ULTRASONICBUT4()
{

    ui->tabWidget->setCurrentIndex(3);
    QString currentText = ui->CutMode_vitCom_4->currentText();
     ui->CutMode_vit->show();
     ui->CutMode_vitCom->show();
     ui->tabWidget_2->show();
     butname=4;
     handler->buzz();
  }

void MainWindow::IRRIGATIONBUT1()
{
    ui->tabWidget->setCurrentIndex(4);
     ui->CutMode_vit->hide();
     ui->CutMode_vitCom->hide();
     ui->tabWidget_2->hide();
     butname=5;
     handler->buzz();
 }

void MainWindow::IRRIGATIONBUT2()
{
    ui->tabWidget->setCurrentIndex(5);
     ui->CutMode_vit->hide();
     ui->CutMode_vitCom->hide();
     ui->tabWidget_2->hide();
     butname=6;
     handler->buzz();
   }

void MainWindow::VITRECTOMYBUT()
{
    ui->tabWidget->setCurrentIndex(6);
   // ui->label_11->setText("VITRECTOMY");
   click();

    butname=7;
    handler->buzz();

}

void MainWindow::DIATHERMYBUT()
{
  ui->tabWidget->setCurrentIndex(7);
    ui->CutMode_vit->hide();
    ui->CutMode_vitCom->hide();
    ui->tabWidget_2->hide();
    butname=0;

    click();
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

    ui->lineEdit_57->setText(QString::number(value));
}

void MainWindow::US1VACUP()
{
  // int act=v->stabilize();
   //ui->progressBar_2->setValue(act);
  // ui->label_3->setNum(act);
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
      click();
      QString currentText = ui->CutMode_vitCom_3->currentText();

      updateTabsBasedOnComboBox(currentText);

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
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 13pt;"
                         "    background-color: transparent;"
            "image: url(:/images/glass.png);"
            "height:81;"
            "width:81;"
                         "    color: white;"
                         "    border-radius: 40px;"
                         "}";
    QString styleSheet1 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 13pt;"
                          "    background-color: transparent;"
            "image: url(:/images/glass.png);"
            "height:81;"
            "width:81;"
                          "    color: black;"
                          "    border-radius: 40px;"
                          "}";
    QString styleSheet3 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 13pt;"
                          "    background-color: transparent;"
            "height:81;"
            "width:81;"
                          "image: url(:/images/newbut.png);"
                          "    border-radius: 40px;"
                          "}";
    QString styleSheet4 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 13pt;"
                          "    background-color: transparent;"
            "height:81;"
            "width:81;"
            "image: url(:/images/irr.png);"
                          "    color: black;"
                          "    border-radius: 40px;"
                          "}";

    // Reset all buttons' styles to default (styleSheet1)
    ui->ULTRASONICBUT1->setStyleSheet(styleSheet1);
    ui->ULTRASONICBUT2->setStyleSheet(styleSheet1);
    ui->ULTRASONICBUT3->setStyleSheet(styleSheet1);
    ui->ULTRASONICBUT4->setStyleSheet(styleSheet1);
    ui->IA1BUT->setStyleSheet(styleSheet1);
    ui->IA2BUT->setStyleSheet(styleSheet1);
    ui->VITRECTOMYBUT->setStyleSheet(styleSheet1);
    ui->DIABUT->setStyleSheet(styleSheet1);
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_14->hide();
    ui->label_13->hide();
    ui->label_5->hide();
    ui->label_6->hide();
 ui->elapsed_time->hide();
 ui->label_32->hide();
    switch (tab) {
        case 0:
            ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
            ui->label_3->show();
 ui->elapsed_time->show();
 ui->label_32->show();
            break;
        case 1:
            ui->ULTRASONICBUT2->setStyleSheet(styleSheet);
            ui->label_4->show();
            ui->elapsed_time->show();
             ui->label_32->show();
            break;
        case 2:
            ui->ULTRASONICBUT3->setStyleSheet(styleSheet);
            ui->label_14->show();
            ui->elapsed_time->show();
             ui->label_32->show();
            break;
        case 3:
            ui->ULTRASONICBUT4->setStyleSheet(styleSheet);
               ui->elapsed_time->show();
               ui->label_12->show();
                ui->label_32->show();
            break;
        case 4:
            ui->IA1BUT->setStyleSheet(styleSheet4);

            ui->label_13->show();


            break;
        case 5:
            ui->IA2BUT->setStyleSheet(styleSheet4);
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
void MainWindow::setTuneMode(bool tuneEnabled) {
    QString styleSheet4 = "QLabel {"
               "image: url(:/images/unlocked.png);"

                "background-color:transparent;"

                                     "}";
    isTuneEnabled = tuneEnabled;  // Set the flag based on the argument

    // Enable or disable the US buttons based on the flag
    ui->ULTRASONICBUT1->setEnabled(isTuneEnabled);    // us1
    ui->label_16->setStyleSheet(styleSheet4);
    ui->label_17->setStyleSheet(styleSheet4);
    ui->label_18->setStyleSheet(styleSheet4);
    ui->label_27->setStyleSheet(styleSheet4);
    ui->ULTRASONICBUT2->setEnabled(isTuneEnabled);  // us2
    ui->ULTRASONICBUT3->setEnabled(isTuneEnabled);  // us3
    ui->ULTRASONICBUT4->setEnabled(isTuneEnabled);  // us4

    // These buttons are always enabled
    ui->IA1BUT->setEnabled(true);  // ia1
    ui->IA2BUT->setEnabled(true);  // ia2
    ui->VITRECTOMYBUT->setEnabled(true);  // vit
}

void MainWindow::enableButtons(bool powerOn)
{
    // Style sheets for ON and OFF states
    QString styleSheetOn = "QPushButton {"
                           " font:20pt Ubuntu;"
                           " background-color: green;"
                           " color: black;"
                           " border:5px solid black;"
                           " border-radius:30px; font-weight: bold;"
                           "}";
    QString styleSheetOff = "QPushButton {"
                            " font:20pt Ubuntu;"
                            " background-color: red;"
                            " color: black;"
                            " border:5px solid black;"
                            " border-radius:30px; font-weight: bold;"
                            "}";

    // Enable or disable buttons and update their styles
    if (powerOn) {
        ui->us1onoff->setStyleSheet(styleSheetOn);
        ui->us1onoff->setText("ON");
        ui->us1powup_but->setEnabled(true);
        ui->us1powdown_but->setEnabled(true);

        ui->us2onoff->setStyleSheet(styleSheetOn);
        ui->us2onoff->setText("ON");
        ui->us2powup_but->setEnabled(true);
        ui->us2powdown_but->setEnabled(true);

        ui->us3onoff->setStyleSheet(styleSheetOn);
        ui->us3onoff->setText("ON");
        ui->us3powup_but->setEnabled(true);
        ui->us3powdown_but->setEnabled(true);

        ui->us4onoff->setStyleSheet(styleSheetOn);
        ui->us4onoff->setText("ON");
        ui->us4powup_but->setEnabled(true);
        ui->us4powdown_but->setEnabled(true);

        ui->vitonoff->setStyleSheet(styleSheetOn);
        ui->vitonoff->setText("ON");
        ui->vitpowup_but->setEnabled(true);
        ui->vitpowdown_but->setEnabled(true);

        // Turn on the hardware features for all buttons
        int range = lfoot->convert(0x97);
        int pow1 = ui->lineEdit_57->text().toInt();
        handler->fs_count(range);
        handler->freq_count(2500);
        handler->phaco_on();
        handler->phaco_power(pow1);
        handler->pdm_mode(0);

    } else {
        ui->us1onoff->setStyleSheet(styleSheetOff);
        ui->us1onoff->setText("OFF");
        ui->us1powup_but->setEnabled(false);
        ui->us1powdown_but->setEnabled(false);

        ui->us2onoff->setStyleSheet(styleSheetOff);
        ui->us2onoff->setText("OFF");
        ui->us2powup_but->setEnabled(false);
        ui->us2powdown_but->setEnabled(false);

        ui->us3onoff->setStyleSheet(styleSheetOff);
        ui->us3onoff->setText("OFF");
        ui->us3powup_but->setEnabled(false);
        ui->us3powdown_but->setEnabled(false);

        ui->us4onoff->setStyleSheet(styleSheetOff);
        ui->us4onoff->setText("OFF");
        ui->us4powup_but->setEnabled(false);
        ui->us4powdown_but->setEnabled(false);

        ui->vitonoff->setStyleSheet(styleSheetOff);
        ui->vitonoff->setText("OFF");
        ui->vitpowup_but->setEnabled(false);
        ui->vitpowdown_but->setEnabled(false);

        // Turn off the hardware features
        handler->fs_count(0);
        handler->freq_count(0);
        handler->phaco_off();
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
    QString text=ui->comboBox->currentText();
  QString powerdelivered=ui->CutMode_vitCom->currentText();
  QString powerdelivered_1=ui->CutMode_vitCom_2->currentText();
  QString powerdelivered_2=ui->CutMode_vitCom_3->currentText();
  QString powerdeliverd_3=ui->CutMode_vitCom_4->currentText();
    switch(butname)
    {

    // dia
    case 0:
    {
        int pow = (ui->lineEdit_74->text().toInt()*255)/100;
        bool flag = true; // Ensure flag is correctly set

        if (flag) {
            if (range >= 0 && range < 800) {
                ui->pushButton_42->setText("0");
                ui->dial_2->setValue(range);
                 handler->dia_off();
                 if(!overallci){
                 ui->CI5_5->setStyleSheet(styleSheet4);

                     handler->pinchvalve_off();
                     handler->safetyvent_off();
                 }

            }
            else if (range >= 800 && range < 4094)
             {
                ui->pushButton_42->setText("1");
                ui->dial_2->setValue(range);
                handler->dia_on();
                //handler->diathermy(pow); // Assuming handler is correctly initialized
                handler->dia_count(pow);

                ui->CI5_5->setStyleSheet(styleSheet3);
                handler->pinchvalve_on();
                handler->safetyvent_on();
            }
        }
        break;
    }
  //us1
    case 1: {
        int pow1 = ui->lineEdit_57->text().toInt(); // Get the power value from the line edit
        bool flag1 = true;

        if (us1 == "PANEL" || vus1 == "PANEL") {
            if (range>0 && range <100) {
                ui->pushButton_42->setText("0");
                ui->dial_2->setValue(range);
if(!overallci){
   ui->CI5_5->setStyleSheet(styleSheet4);
    handler->pinchvalve_off();
    handler->safetyvent_off();
}
    motoroff();

                ui->label_7->setText("0");
                ui->label_8->setText("0");
                if (power.powerOn) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);

                   power.powerOn= false;
                }
                flag1 = true; // Reset flag
} else if (range >= 100 & range < 1332) {
ui->pushButton_42->setText("1");
ui->dial_2->setValue(range);

handler->pinchvalve_on();
handler->safetyvent_on();
ui->CI5_5->setStyleSheet(styleSheet3);

motoroff();
ui->label_7->setText("0");
ui->label_8->setText("0");
if (power.powerOn) {
handler->freq_count(0);
handler->phaco_off();
handler->fs_count(0);

power.powerOn = false;
}
flag1 = true; // Reset flag
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                   ui->dial_2->setValue(range);
                 ui->CI5_5->setStyleSheet(styleSheet3);
                handler->pinchvalve_on();
                   handler->safetyvent_on();


                if (text == "Peristatic") {
                                motoron(ui->lineEdit_56);
                                 sensor2();
                            } else {
                                motoroff();
                                 sensor2();
                            }

                ui->label_8->setText("0");
                if (power.powerOn) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);

                   power.powerOn = false;
                }
                flag1 = true; // Reset flag
            } else if (range >= 2664 && range < 4096) {
                ui->pushButton_42->setText("3");
                   updateTabsBasedOnComboBox(powerdelivered);
                   ui->dial_2->setValue(range);
                                 handler->pinchvalve_on();
                                    handler->safetyvent_on();
                                  ui->CI5_5->setStyleSheet(styleSheet3);


                if (text == "Peristatic") {
                                motoron(ui->lineEdit_56);
                                 sensor2();
                            } else {
                                motoroff();
                                sensor2();
                            }

                if (power.buttonState == "ON" && !power.powerOn) {

                   power.powerOn= true;
                   handler->fs_count(range);
                   handler->freq_count(2500);
                   handler->phaco_on();
                   handler->phaco_power(pow1);

                }
                if (power.powerOn) {
                    // Dynamically calculate power output based on range for PANEL mode
                    float progress4 = ((range - 2664.0) / (4096 - 2664.0)) * pow1;
                    ui->label_7->setText(QString::number(static_cast<int>(progress4)));
                }

            }
        } else if (us1 == "SURGEON" || vus1 == "SURGEON") {
            if (range >0 && range <100) {
                ui->pushButton_42->setText("0");
                   ui->dial_2->setValue(range);

if(!overallci){
    ui->CI5_5->setStyleSheet(styleSheet4);
   handler->pinchvalve_off();
   handler->safetyvent_off();}

                ui->label_7->setText("0");
                ui->label_8->setText("0");
                motoroff();

                if (power.powerOn) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);

                    power.powerOn = false;
                }
                flag1 = true; // Reset flag
            } else if (range >= 100 && range < 1332) {
                ui->pushButton_42->setText("1");
  ui->dial_2->setValue(range);
                handler->pinchvalve_on();
                   handler->safetyvent_on();
                 ui->CI5_5->setStyleSheet(styleSheet3);

                motoroff();
                ui->label_7->setText("0");
                ui->label_8->setText("0");
                if (power.powerOn) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);

                    power.powerOn = false;
                }
                flag1 = true; // Reset flag
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                 ui->dial_2->setValue(range);
                handler->pinchvalve_on();
                   handler->safetyvent_on();
                ui->CI5_5->setStyleSheet(styleSheet3);


                  if (text == "Peristatic") {
                                  motoron(ui->lineEdit_56);
                                   updatesensor();
                              } else {
                                  motoroff();
                                   updatesensor();
                              }
                ui->label_8->setText("0");
                if (power.powerOn) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);

                    power.powerOn = false;
                }
                flag1 = true; // Reset flag
            } else if (range >= 2664 && range <= 4096) {
                ui->pushButton_42->setText("3");
                 ui->dial_2->setValue(range);
                  handler->pinchvalve_on();
                     handler->safetyvent_on();
               ui->CI5_5->setStyleSheet(styleSheet3);
                updateTabsBasedOnComboBox(powerdelivered);
                if (text == "Peristatic") {
                                motoron(ui->lineEdit_56);
                                  updatesensor();
                            } else {
                                motoroff();
                                  updatesensor();
                            }


                if (power.buttonState == "ON" && !power.powerOn) {
                    power.powerOn = true;

                    handler->fs_count(range);
                 handler->freq_count(2500);
  handler->phaco_on();
                 handler->phaco_power(pow1);

                }
                if (power.powerOn) {

                    int powervalue = range*pow1/4096;
                    ui->label_7->setText(QString::number(powervalue));
                }

            }
        }

        elapsedTimeUS1 += elapsed;
        message = "Effective time for US1: " + QString::number(elapsedTimeUS1 / 1000.0, 'f', 2) + " s";
        break;
    }


        // us2
    case 2: {
        int pow2 = ui->lineEdit_58->text().toInt(); // Get the power value from the line edit
        bool flag2 = true;

        if (us2 == "PANEL" || vus2 == "PANEL") {
            if (range >= 0 && range<100) {
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
                     ui->CI5_5->setStyleSheet(styleSheet4);
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

                    power.powerOn1 = false;
                }
                flag2 = true; // Reset flag
            } else if (range >= 100 && range <1332) {
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);
    ui->CI5_5->setStyleSheet(styleSheet3);

  handler->pinchvalve_on();
  handler->safetyvent_on();
                motoroff();
                handler->phaco_off();
                ui->label_92->setText("0");
                ui->label_93->setText("0");

 if (power.powerOn1) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    power.powerOn1 = false;
                }
                flag2 = true; // Reset flag
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);
                  ui->CI5_5->setStyleSheet(styleSheet3);

                handler->pinchvalve_on();
                handler->safetyvent_on();


                if (text == "Peristatic") {
                                motoron(ui->lineEdit_59);
                                sensor2();
                            } else {
                                motoroff();
                                 sensor2();
                            }
                ui->label_92->setText("0");
                if (power.powerOn1) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    power.powerOn1 = false;
                }
                flag2 = true; // Reset flag
            } else if (range >= 2664 && range < 4096) {
                ui->pushButton_42->setText("3");
                  ui->dial_2->setValue(range);
         ui->CI5_5->setStyleSheet(styleSheet3);
                handler->pinchvalve_on();
                handler->safetyvent_on();
                if (power.buttonstate1 == "ON" && !power.powerOn1) {
                   updateTabsBasedOnComboBox(powerdelivered_1);
                    handler->freq_count(2500);
                    handler->phaco_on();
                    handler->fs_count(range);
                    handler->phaco_power(pow2);

                    power.powerOn1 = true;
                }
                if (power.powerOn1) {
                    // Dynamically calculate power output based on range for PANEL mode
                    float progress4 = ((range - 3072.0) / (4096 - 3072)) * pow2;
                    ui->label_92->setText(QString::number(static_cast<int>(progress4)));
                }


                if (text == "Peristatic") {
                                motoron(ui->lineEdit_59);
                                sensor2();
                            } else {
                                motoroff();
                                 sensor2();
                            }
            }
        } else if (us2 == "SURGEON" || vus2 == "SURGEON") {
            if (range >= 0 && range < 100) {
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
if(!overallci){
    ui->CI5_5->setStyleSheet(styleSheet4);
    handler->safetyvent_off();
    handler->pinchvalve_off();
}
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
            } else if (range >= 100 && range < 1332) {
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);
                 ui->CI5_5->setStyleSheet(styleSheet3);

                handler->pinchvalve_on();
                handler->safetyvent_on();
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
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);
                  ui->CI5_5->setStyleSheet(styleSheet3);

                handler->pinchvalve_on();
                handler->safetyvent_on();
                if (text == "Peristatic") {
                                motoron(ui->lineEdit_59);
                                updatesensor();
                            } else {
                                motoroff();
                             updatesensor();
                            }
                ui->label_92->setText("0");
                if (power.powerOn1) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn1 = false;
                }
                flag2 = true; // Reset flag
            } else if (range >= 2664 && range <= 4096) {
                ui->pushButton_42->setText("3");
                  ui->dial_2->setValue(range);
                ui->CI5_5->setStyleSheet(styleSheet3);

                handler->pinchvalve_on();
                handler->safetyvent_on();
                if (power.buttonstate1 == "ON" && !power.powerOn1) {
                   updateTabsBasedOnComboBox(powerdelivered_1);
                    handler->freq_count(2500);
                    handler->phaco_on();
                    handler->fs_count(range);
                    handler->phaco_power(pow2);

                    power.powerOn1 = true;

                }
                if (power.powerOn1) {
                    // Dynamically calculate power output based on range for SURGEON mode
                    int progress4 = pow2 * (range - 3072) / (4096 - 3072);
                    int progress5 = std::min(progress4, pow2);
                    ui->label_92->setText(QString::number(progress5));
                }

                if (text == "Peristatic") {
                                motoron(ui->lineEdit_59);
                                updatesensor();
                            } else {
                                motoroff();
                             updatesensor();
                            }
            }
        }

        elapsedTimeUS2 += elapsed;
        message = "Effective time for US2: " + QString::number(elapsedTimeUS2 / 1000.0, 'f', 2) + " s";
        break;
    }
        //us 3

    case 3: {
        int pow3 = ui->lineEdit_61->text().toInt(); // Get the power value from the line edit
        bool flag3 = true;

        if (us3 == "PANEL" || vus3 == "PANEL") {
            if (range >= 0 && range < 100) {
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
                     ui->CI5_5->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }
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
            } else if (range >= 100 && range < 1332) {
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);
                   ui->CI5_5->setStyleSheet(styleSheet3);
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
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);

                  ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();

                if (text == "Peristatic") {
                                motoron(ui->lineEdit_62);
                              sensor2();
                            } else {
                                motoroff();
                               sensor2();
                            }

                ui->label_98->setText("0");
                if (power.powerOn2) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);

                    power.powerOn2 = false;
                }
                flag3 = true; // Reset flag
            } else if (range >= 2664 && range < 4096) {
                ui->pushButton_42->setText("3");
                  ui->dial_2->setValue(range);
                ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();

                if (power.buttonstate2 == "ON" && !power.powerOn2) {
                    handler->freq_count(2500);
                    handler->phaco_on();
                    handler->fs_count(range);
                    handler->phaco_power(pow3);
                    updateTabsBasedOnComboBox(powerdelivered_2);
                    power.powerOn2 = true;
                }
                if (power.powerOn2) {
                    // Dynamically calculate power output based on range for PANEL mode
                    float progress8 = ((range - 3072.0) / (4096 - 3072)) * pow3;
                    ui->label_98->setText(QString::number(static_cast<int>(progress8)));
                }


                motoron(ui->lineEdit_62);
                sensor2();

            }
        } else if (us3 == "SURGEON" || vus3 == "SURGEON") {
            if (range >= 0 && range < 100) {
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
                   ui->CI5_5->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }
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
            } else if (range >= 100 && range < 1332) {
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);
                 ui->CI5_5->setStyleSheet(styleSheet3);
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
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);
        ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
               handler->pinchvalve_on();
               if (text == "Peristatic") {
                               motoron(ui->lineEdit_62);
                      updatesensor();
                           } else {
                               motoroff();
                     updatesensor();
                           }

                ui->label_98->setText("0");
                if (power.powerOn2) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn2 = false;
                }
                flag3 = true; // Reset flag
            } else if (range >= 2664 && range <= 4096) {
                ui->pushButton_42->setText("3");
                  ui->dial_2->setValue(range);
                 ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();
                if (power.buttonstate2 == "ON" && !power.powerOn2) {
                    handler->freq_count(2500);
                    handler->phaco_on();
                    handler->fs_count(range);
                    handler->phaco_power(pow3);
                    updateTabsBasedOnComboBox(powerdelivered_2);
                    power.powerOn2 = true;
                    updateline();
                }
                if (power.powerOn2) {
               ui->CI5_5->setStyleSheet(styleSheet3);         // Dynamically calculate power output based on range for SURGEON mode
                    int progress8 = pow3 * (range - 3072) / (4096 - 3072);
                    int progress9 = std::min(progress8, pow3);
                    ui->label_98->setText(QString::number(progress9));
                }

                if (text == "Peristatic") {
                                motoron(ui->lineEdit_62);
                            updatesensor();
                            } else {
                                motoroff();
                           updatesensor();
                            }


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
            if (range >= 0 && range < 100) {
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
                 ui->CI5_5->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }
                //handler->pinchvalve_off();
                motoroff();
                handler->phaco_off();
               // ui->CI4->setStyleSheet(styleSheet4);
                ui->label_105->setText("0");
                ui->label_104->setText("0");
                if (power.powerOn3) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn3 = false;
                }
            } else if (range >= 100 && range < 1332) {
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);
                ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();


                motoroff();
                handler->phaco_off();
                ui->label_104->setText("0");
                ui->label_105->setText("0");
                if (power.powerOn3) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn3 = false;
                }
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);
             ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();

                handler->phaco_off();
                ui->label_105->setText("0");
                if (text == "Peristatic") {
                                motoron(ui->lineEdit_65);
                              sensor2();
                            } else {
                                motoroff();
                               sensor2();
                            }

                if (power.powerOn3) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn3 = false;
                }
            } else if (range >= 2664 && range < 4096) {
                ui->pushButton_42->setText("3");
                  ui->dial_2->setValue(range);
                ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();
 ui->CI5_5->setStyleSheet(styleSheet3);

                if (power.buttonstate3 == "ON" && !power.powerOn3) {
                    handler->freq_count(2500);
                    handler->phaco_on();
                    handler->fs_count(range);
                    handler->phaco_power(pow4);
                    handler->pdm_mode(1);
              updateTabsBasedOnComboBox(powerdeliverd_3);
                    power.powerOn3 = true;
                }
                if (power.powerOn3) {
                    // Dynamically calculate power output based on range for PANEL mode
                    float progress14 = ((range - 3072.0) / (4096 - 3072)) * pow4;
                    ui->label_105->setText(QString::number(static_cast<int>(progress14)));
                }

                if (text == "Peristatic") {
                                motoron(ui->lineEdit_65);
                              sensor2();
                            } else {
                                motoroff();
                               sensor2();
                            }


            }
        } else if (us4 == "SURGEON" || vus4 == "SURGEON") {
            if (range >= 0 && range < 100) {
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
                   ui->CI5_5->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
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
            } else if (range >= 100 && range < 1332) {
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);

                 ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();


                motoroff();
                handler->phaco_off();
                ui->label_105->setText("0");
                ui->label_104->setText("0");
                if (power.powerOn3) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn3 = false;
                }
            } else if (range >= 1332 && range < 2664) {
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);

                handler->safetyvent_on();
                handler->pinchvalve_on();
 ui->CI5_5->setStyleSheet(styleSheet3);


                handler->phaco_off();
                ui->label_105->setText("0");
                if (text == "Peristatic") {
                                motoron(ui->lineEdit_65);
                        updatesensor();
                            } else {
                                motoroff();
                   updatesensor();
                            }

                if (power.powerOn3) {
                    handler->freq_count(0);
                    handler->phaco_off();
                    handler->fs_count(0);
                    handler->pdm_mode(0);
                    power.powerOn3 = false;
                }
            } else if (range >= 2664 && range <= 4096) {
                ui->pushButton_42->setText("3");
                  ui->dial_2->setValue(range);

                handler->safetyvent_on();
                handler->pinchvalve_on();
 ui->CI5_5->setStyleSheet(styleSheet3);

                if (power.buttonstate3 == "ON" && !power.powerOn3) {
                    handler->freq_count(2500);
                    handler->phaco_on();
                    handler->fs_count(range);
                    handler->phaco_power(pow4);
                   updateTabsBasedOnComboBox(powerdeliverd_3);
                    updateline();
                    power.powerOn3 = true;
                }
                if (power.powerOn3) {
                    // Dynamically calculate power output based on range for SURGEON mode
                    int progress11 = pow4 * (range - 3072) / (4096 - 3072);
                    int progress12 = std::min(progress11, pow4);
                    ui->label_105->setText(QString::number(progress12));
                }
                if (text == "Peristatic") {
                                motoron(ui->lineEdit_62);
                              updatesensor();
                            } else {
                                motoroff();
                        updatesensor();
                            }


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
            if(range>=0 && range<100){
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
               ui->CI5_5->setStyleSheet(styleSheet3);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }

            }
            if(range>=100 && range<1332){
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);

  handler->safetyvent_on();
  handler->pinchvalve_on();
                  motoroff();


            }
             if(range>=1332 && range <4096){
            //    qDebug()<<"fs"<<range;
                  ui->pushButton_42->setText("2");
                    ui->dial_2->setValue(range);
      ui->CI5_5->setStyleSheet(styleSheet3);
                  handler->safetyvent_on();
                  handler->pinchvalve_on();
                 if(text == "Peristatic"){
                     motoron(ui->lineEdit_69);
                     sensor2();
                 }else{
                     motoroff();
                     sensor2();
                 }

        }

           }
             else{
                 if(ia1 == "SURGEON"){
                 if(range>=0 && range<100){
                     ui->pushButton_42->setText("0");
                       ui->dial_2->setValue(range);
                     if(!overallci){
                     ui->CI5_5->setStyleSheet(styleSheet4);
                         handler->pinchvalve_off();
                         handler->safetyvent_off();
                     }
                        motoroff();
                 }
                 if(range>=100 && range<1332){
                     ui->pushButton_42->setText("1");
                       ui->dial_2->setValue(range);
                     ui->CI5_5->setStyleSheet(styleSheet3);
                     handler->safetyvent_on();
                     handler->pinchvalve_on();
                    motoroff();
                 }
                 else if(range>=2664 && range <4096){
                    // qDebug()<<"fs"<<range;
                       ui->pushButton_42->setText("2");
                         ui->dial_2->setValue(range);
      ui->CI5_5->setStyleSheet(styleSheet3);
                       handler->safetyvent_on();
                       handler->pinchvalve_on();
                       if(text == "Peristatic"){
                           motoron(ui->lineEdit_69);
                           updatesensor();
                       }else{
                           motoroff();
                          updatesensor();
                       }
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
            if(range>=0 && range<100){
                ui->pushButton_42->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
            ui->CI5_5->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }
               //   motoron(ui->lineEdit_10);
 motoroff();
            }
            if(range>=100 && range<1332){
                ui->pushButton_42->setText("1");
                  ui->dial_2->setValue(range);
         ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();
                 motoroff();
            }
            else if(range>=1332 && range <4096){
                ui->pushButton_42->setText("2");
                  ui->dial_2->setValue(range);
       ui->CI5_5->setStyleSheet(styleSheet3);
                handler->safetyvent_on();
                handler->pinchvalve_on();
                if(text == "Peristatic"){
                    motoron(ui->lineEdit_67);
                    sensor2();
                }else{
                    motoroff();
                  sensor2();
                }
            }

            }
            else{
                if(ia2 == "SURGEON"){
                if(range>=0 && range<100){
                    ui->pushButton_42->setText("0");
                      ui->dial_2->setValue(range);
                    if(!overallci){
                 ui->CI5_5->setStyleSheet(styleSheet4);
                        handler->pinchvalve_off();
                        handler->safetyvent_off();
                    }
                      motoroff();
                   // label43();
                }
                if(range>=100 && range<1332){
                    ui->pushButton_42->setText("1");
                      ui->dial_2->setValue(range);
                 ui->CI5_5->setStyleSheet(styleSheet3);
                    handler->safetyvent_on();
                    handler->pinchvalve_on();
                     // motoroff();
                }
                else if(range>=1332 && range <4096){
                    ui->pushButton_42->setText("2");
                      ui->dial_2->setValue(range);
                  ui->CI5_5->setStyleSheet(styleSheet3);
                    handler->safetyvent_on();
                    handler->pinchvalve_on();
                    if(text == "Peristatic"){
                        motoron(ui->lineEdit_67);
                        updatesensor();
                    }else{
                        motoroff();
                       updatesensor();
                    }   }

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
                if (range >= 0 && range < 100) {
                    ui->pushButton_42->setText("0");
                      ui->dial_2->setValue(range);
if(!overallci){
  ui->CI5_5->setStyleSheet(styleSheet4);
    handler->pinchvalve_off();
    handler->safetyvent_off();
}

                    motoroff();
                    handler->vit_off();

                    ui->label_119->setText("0");
                    ui->label_118->setText("0");
                    if (power.powerOn4) {
                        handler->vit_off();
                        power.powerOn4 = false;
                    }
                } else if (range >= 100 && range < 1332) {
                    ui->pushButton_42->setText("1");
                      ui->dial_2->setValue(range);
  ui->CI5_5->setStyleSheet(styleSheet3);
handler->safetyvent_on();
handler->pinchvalve_on();
                    motoroff();
                    handler->vit_off();
                    ui->label_119->setText("0");
                    ui->label_118->setText("0");
                    if (power.powerOn4) {
                       handler->vit_off();
                        power.powerOn4 = false;
                    }
                } else if (range >= 1332 && range < 2664) {
                    ui->pushButton_42->setText("2");
                      ui->dial_2->setValue(range);
           ui->CI5_5->setStyleSheet(styleSheet3);
                    handler->safetyvent_on();
                    handler->pinchvalve_on();

                    handler->vit_off();
                    ui->label_119->setText("0");
                    if(text == "Peristatic"){
                        motoron(ui->lineEdit_72);
                       sensor2();
                    }else{
                        motoroff();
                       sensor2();
                    }
                    if (power.powerOn4) {
                       handler->vit_off();
                        power.powerOn4 = false;
                    }
                } else if (range >= 2664 && range < 4096) {
                    ui->pushButton_42->setText("3");
                      ui->dial_2->setValue(range);
                 ui->CI5_5->setStyleSheet(styleSheet3);
                    handler->safetyvent_on();
                    handler->pinchvalve_on();
                    if (power.buttonstate4 == "ON" && !power.powerOn4) {
                       handler->vit_on(pow7);
                       handler->vit_ontime(30);

                        power.powerOn4 = true;
                    }
                    if (power.powerOn4) {
                        float progress24 = ((range - 3072.0) / (4096 - 3072)) * pow7;
                        ui->label_119->setText(QString::number(static_cast<int>(progress24)));
                    }


                    if(text == "Peristatic"){
                        motoron(ui->lineEdit_72);
                       sensor2();
                    }else{
                        motoroff();
                       sensor2();
                    }

                }
            } else if (vit == "SURGEON" || vvit == "SURGEON") {
                if (range >= 0 && range < 100) {
                    ui->pushButton_42->setText("0");
                      ui->dial_2->setValue(range);
                    if(!overallci){
                          ui->CI5_5->setStyleSheet(styleSheet4);
                        handler->pinchvalve_off();
                        handler->safetyvent_off();
                    }

                    handler->vit_off();
                    motoroff();
                    ui->label_119->setText("0");
                    ui->label_118->setText("0");
                    if (power.powerOn4) {
                       handler->vit_off();
                        power.powerOn4 = false;
                    }
                } else if (range >= 100 && range < 1332) {
                    ui->pushButton_42->setText("1");
                      ui->dial_2->setValue(range);
                  ui->CI5_5->setStyleSheet(styleSheet3);
                    handler->safetyvent_on();
                    handler->pinchvalve_on();
                    motoroff();
                    handler->vit_off();
                    ui->label_119->setText("0");
                    if (power.powerOn4) {
                     handler->vit_off();
                        power.powerOn4 = false;
                    }
                } else if (range >= 1332 && range < 2664) {
                    ui->pushButton_42->setText("2");
                      ui->dial_2->setValue(range);
                    ui->CI5_5->setStyleSheet(styleSheet3);
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
                } else if (range >= 2664 && range < 4096) {
                    ui->pushButton_42->setText("3");
                      ui->dial_2->setValue(range);
                     ui->CI5_5->setStyleSheet(styleSheet3);
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

                    if(text == "Peristatic"){
                        motoron(ui->lineEdit_72);
                    updatesensor();
                    }else{
                        motoroff();
                      updatesensor();
                    }
                  }

            }
        }
    }
        break;
    }


    currentTimer.restart();
    updateLabel();

}

void MainWindow::us1_linear_nonlinear()
{
     // ui->us1mode->setText("SURGEON");
     us1=ui->us1mode->text();

       if(us1 == "SURGEON" )
       {
           ui->us1mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
            ui->us1mode->setText("PANEL");

             footpedalcheck();

       }
       else if(us1 == "PANEL" )
       {
           ui->us1mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           ui->us1mode->setText("SURGEON");


     footpedalcheck();

}
}
void MainWindow::on_us1vacmode_clicked()
{
    vus1 = ui->us1vacmode->text();
       if(vus1== "SURGEON")
       {

            ui->us1vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
            ui->us1vacmode->setText("PANEL");

             footpedalcheck();
       }
       else if(vus1=="PANEL")
       {

           ui->us1vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           ui->us1vacmode->setText("SURGEON");
         //  int pow2=ui->lineEdit_58->text().toInt();
     footpedalcheck();
}

}


void MainWindow::us2_linear_nonlinear()
{
    us2 = ui->us2mode->text();


       if(us2 == "SURGEON" )
       {

            ui->us2mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
             ui->us2mode->setText("PANEL");


              footpedalcheck();
               }
       else if(us2 == "PANEL")
       {
            ui->us2mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           ui->us2mode->setText("SURGEON");

         footpedalcheck();
       }

}
void MainWindow::on_us2vacmode_clicked()
{
    vus2=ui->us2vacmode->text();
    if(vus2 == "SURGEON")
    {

      ui->us2vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
          ui->us2vacmode->setText("PANEL");

           footpedalcheck();
            }
    else if(vus2 == "PANEL")
    {

        ui->us2vacmode->setText("SURGEON");
         ui->us2vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
      footpedalcheck();
    }

}

void MainWindow::us3_linear_nonlinear()
{
    us3 = ui->us3mode->text();


       if(us3 == "SURGEON")
       {
            ui->us3mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
             ui->us3mode->setText("PANEL");

              footpedalcheck();
       }
       else if(us3 == "PANEL")
       {
             ui->us3mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           ui->us3mode->setText("SURGEON");

           footpedalcheck();
       }

}
void MainWindow::on_us3vacmode_clicked()
{
     vus3=ui->us3vacmode->text();
     if(vus3 =="SURGEON")
     {

           ui->us3vacmode->setText("PANEL");
            ui->us3vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
            footpedalcheck();
     }
     else if(vus3 == "PANEL")
     {

         ui->us3vacmode->setText("SURGEON");
         ui->us3vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
         footpedalcheck();
     }

}

void MainWindow::us4_linear_nonlinear()
{
    us4 = ui->us4mode->text();

       if(us4 == "SURGEON")
       {

            ui->us4mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
             ui->us4mode->setText("PANEL");

             footpedalcheck();
                }
       else if(us4 == "PANEL")
       {
           ui->us4mode->setText("SURGEON");
              ui->us4mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");


               footpedalcheck();
       }

}

void MainWindow::on_us4vacmode_clicked()
{
    vus4=ui->us4vacmode->text();
    if(vus4 == "SURGEON")
    {


          ui->us4vacmode->setText("PANEL");
           ui->us4vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
          footpedalcheck();
             }
    else if(vus4 == "PANEL")
    {

           ui->us4vacmode->setText("SURGEON");
            ui->us4vacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
            footpedalcheck();
    }

}



void MainWindow::ia1_linear_nonlinear()
{
    ia1= ui->ia1mode->text();

       if(ia1== "SURGEON")
       {

            ui->ia1mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
             ui->ia1mode->setText("PANEL");
            footpedalcheck();
               }
       else if(ia1 == "PANEL")
       {
            ui->ia1mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           ui->ia1mode->setText("SURGEON");
           footpedalcheck();
               }
   }
void MainWindow::ia2_linear_nonlinear()
{
    ia2 = ui->ia2mode->text();

       if(ia2 == "SURGEON")
       {
           ui->ia2mode->setText("PANEL");
            ui->ia2mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
             footpedalcheck();
                }
       else if(ia2 == "PANEL")
       {
           ui->ia2mode->setText("SURGEON");
            ui->ia2mode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
 footpedalcheck();
       }

}
void MainWindow::vit_linear_nonlinear()
{
    vit = ui->vitmode->text();


       if(vit == "SURGEON" )
       {

           ui->vitmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
            ui->vitmode->setText("PANEL");

            footpedalcheck();
               }
       else if(vit == "PANEL")
       {
              ui->vitmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           ui->vitmode->setText("SURGEON");

           footpedalcheck();
              }
      }
void MainWindow::on_vitvacmode_clicked()
{
      vvit=ui->vitvacmode->text();

      if(vvit =="SURGEON")
      {


           ui->vitvacmode->setText("PANEL");
           ui->vitvacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
           footpedalcheck();
              }
      else if(vvit == "PANEL")
      {

          ui->vitvacmode->setText("SURGEON");
          ui->vitvacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
          footpedalcheck();
             }

}

//pulse
void MainWindow::pulseup_mode()
{

    pulse = ui->lineEdit_75->text().toInt();
    pulse += 1;
    if (pulse > 15) {
        pulse = 15;
    }
    ui->lineEdit_75->setText(QString::number(pulse));
    handler->freq_count(2500);
    handler->fs_count(3000);
    handler->pulse_count(pulse);
  handler->pdm_mode(PULSE_MODE);
}

void MainWindow::pulsedown_mode()
{

    pulse = ui->lineEdit_75->text().toInt();
   pulse -= 1;
    if (pulse < 1) {
        pulse = 1;
    }
    ui->lineEdit_75->setText(QString::number(pulse));
    handler->freq_count(2500);
    handler->fs_count(3000);
    handler->pulse_count(pulse);
handler->pdm_mode(PULSE_MODE);
}
//ocuburst
void MainWindow::ocuburstup_mode()
{

    ocuburst = ui->lineEdit_76->text().toInt();
    ocuburst += 10;
    if (ocuburst > 170) {
        ocuburst = 170;
    }
    ui->lineEdit_76->setText(QString::number(ocuburst));
    handler->freq_count(2500);
    handler->fs_count(3000);
    handler->burst_length(ocuburst);
    handler->burst_off_length(ocuburst);
    handler->pdm_mode(CONTINOUS);
}

void MainWindow::ocuburstdown_mode()
{

    ocuburst = ui->lineEdit_76->text().toInt();
    ocuburst -= 10;
    if (ocuburst < 10) {
        ocuburst = 10;
    }
    ui->lineEdit_76->setText(QString::number(ocuburst));
    handler->freq_count(2500);
    handler->fs_count(3000);
    handler->burst_length(ocuburst);
    handler->burst_off_length(ocuburst);
     handler->pdm_mode(CONTINOUS);
}
//singleburst
void MainWindow::singleburstup_mode()
{

    singleburst = ui->lineEdit_77->text().toInt();
    singleburst += 10;
    if (singleburst > 400) {
        singleburst = 400;
    }
    ui->lineEdit_77->setText(QString::number(singleburst));
    handler->freq_count(2500);
    handler->fs_count(3000);
     handler->pdm_mode(SINGLE_BURST);
    handler->burst_length(singleburst);
    handler->burst_off_length(singleburst);
}

void MainWindow::singleburstdown_mode()
{

    singleburst = ui->lineEdit_77->text().toInt();
    singleburst -= 10;
    if (singleburst < 10) {
        singleburst = 10;
    }
    ui->lineEdit_77->setText(QString::number(singleburst));
    handler->freq_count(2500);
    handler->fs_count(3000);
     handler->pdm_mode(SINGLE_BURST);
    handler->burst_length(singleburst);
    handler->burst_off_length(singleburst);
}
//multiburst
void MainWindow::multiburstup_mode()
{

    multiburst = ui->lineEdit_78->text().toInt();
    multiburst += 10;
    if (multiburst > 400) {
        multiburst = 400;
    }
    ui->lineEdit_78->setText(QString::number(multiburst));
    handler->fs_count(3000);
    handler->freq_count(2500);
    handler->pdm_mode(MULTI_BURST);
    handler->burst_length(multiburst);
    handler->burst_off_length(multiburst);
}

void MainWindow::multiburstdown_mode()
{

    multiburst = ui->lineEdit_78->text().toInt();
    multiburst -= 10;
    if (multiburst < 10) {
        multiburst = 10;
    }
    ui->lineEdit_78->setText(QString::number(multiburst));
    handler->fs_count(3000);
    handler->freq_count(2500);
    handler->pdm_mode(MULTI_BURST);
    handler->burst_length(multiburst);
    handler->burst_off_length(multiburst);
}
//ocupulse
void MainWindow::ocupulseup_mode()
{

    ocupulse = ui->lineEdit_79->text().toInt();
    ocupulse += 1;
    if (ocupulse > 15) {
        ocupulse = 15;
    }
    ui->lineEdit_79->setText(QString::number(ocupulse));

    handler->freq_count(2500);
    handler->fs_count(3000);
    handler->pdm_mode(CONTINOUS);
    handler->pulse_count(ocupulse);


}

void MainWindow::ocupulsedown_mode()
{
    ocupulse = ui->lineEdit_79->text().toInt();
    ocupulse -= 1;
    if (ocupulse < 1) {
        ocupulse = 1;
    }
    ui->lineEdit_79->setText(QString::number(ocupulse));
    handler->freq_count(2500);
    handler->fs_count(3000);
    handler->pdm_mode(CONTINOUS);
    handler->pulse_count(ocupulse);
}
//coldphaco
void MainWindow::coldphacoup_mode()
{

    coldphaco = ui->lineEdit_80->text().toInt();
    coldphaco += 1;
    if (coldphaco > 15) {
        coldphaco = 15;
    }
    ui->lineEdit_80->setText(QString::number(coldphaco));
    handler->cold_pulse(coldphaco);
}

void MainWindow::coldphacodown_mode()
{
    coldphaco = ui->lineEdit_80->text().toInt();
    coldphaco -= 1;
    if (coldphaco < 1) {
        coldphaco = 1;
    }
    ui->lineEdit_80->setText(QString::number(coldphaco));
    handler->cold_pulse(coldphaco);
}

void MainWindow::coldphaco1up_mode()
{
    coldphaco1 = ui->lineEdit_81->text().toInt();
    coldphaco1 += 5;
    if (coldphaco1 > 40) {
        coldphaco1 = 40;
    }
    ui->lineEdit_81->setText(QString::number(coldphaco1));
    handler->cold_pulse(coldphaco1);
}

void MainWindow::coldphaco1down_mode()
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
      }
}

void MainWindow::setGPIODirection(const QString &direction,int pin)
{
    QFile file(QString("/sys/class/gpio/gpio%1/direction").arg(pin));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << direction;
        file.close();
   }
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
    }
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
    }
}




void MainWindow::updatehandpieceStatus()
{
    int status = readGPIOValue(960);


    QString styleSheet4 = "QLabel {"
                "image: url(:/hand.png);"
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
                "image: url(:/hand.png);"

             "background-color: rgb(192, 28, 40);"
                "border: 4px solid black;"
                "border-radius: 20px;"
                                     "}";
    QString styleSheet6 = "QLabel {"
               "image: url(:/images/locked.png);"
 "background-color:transparent;"

                                     "}";
    QString styleSheet7 = "QLabel {"
               "image: url(:/images/unlocked.png);"

                "background-color:transparent;"

                                     "}";
   if(status==0)
   {
   ui->label_28->setStyleSheet(styleSheet4);
   }
   else
   {
      ui->label_28->setStyleSheet(styleSheet5);
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
           QString mode=ui->CutMode_vitCom->currentText();
           QString mode1=ui->CutMode_vitCom_2->currentText();
           QString mode2=ui->CutMode_vitCom_3->currentText();
           QString mode3=ui->CutMode_vitCom_4->currentText();
           //ia1
    if (sensor > 0 && sensor < 4096) {
      //  int pro = sensor * vac5 / 4096+50;
        int pro=sensor*580/4096;
        int pro1=std::min(vac5,pro);
        ui->label_113->setNum(pro1);
        //motoron(ui->lineEdit_4);
        if(vac5==pro1){
         motoroff();
         handler->speaker_on(pro1,0,0,1);
   }
    }
    //ia2
    if (sensor > 0 && sensor < 4096) {
        int pro1 = sensor * 580 / 4096;
       int pro2=std::min(vac6,pro1);
        ui->label_109->setNum(pro2);
        if(vac6 == pro2){
            motoroff();
             handler->speaker_on(pro2,0,0,1);
        }
    }
    //vit
    if (sensor > 0 && sensor < 4096) {
        int pro3 = sensor * 580 / 4096;
       int pro4=std::min(vac7,pro3);
        ui->label_118->setNum(pro4);
        if(vac7 == pro3){
            motoroff();
             handler->speaker_on(pro3,0,0,1);
        }
    }
    //us4
    if (sensor > 0 && sensor < 4096) {
        int pro4 = sensor * 580 / 4096;
       int pro5=std::min(vac4,pro4);
        ui->label_104->setNum(pro5);
        if(vac4 ==pro5){

          if(mode3 == "Ocupulse"){
              handler->fs_count(3000);
              handler->freq_count(2500);
            handler->pdm_mode(PULSE_MODE);

          }
          else if(mode3=="Ocuburst"){
              handler->pdm_mode(OCUBURST);
              handler->fs_count(3000);
              handler->freq_count(2500);
          }
          else if(mode3 == "Multi burst"){
              handler->pdm_mode(MULTI_BURST);
              handler->fs_count(3000);
              handler->freq_count(2500);

          }
           motoroff();
           handler->speaker_on(pro5,0,0,1);
     }
    }
    //us3
    if (sensor > 0 && sensor < 4096) {
        int pro5 = sensor * 580 / 4096;
        int pro6=std::min(vac3,pro5);
        ui->label_99->setNum(pro6);
        if(vac3 == pro6){

//            if(mode2 == "Ocupulse"){
//              handler->pdm_mode(OCUPULSE);
//              ocupulseup_mode();
//              ocupulsedown_mode();
//            }
//            else if(mode2=="Ocuburst"){
//                handler->pdm_mode(OCUBURST);
//                ocuburstup_mode();
//                ocuburstdown_mode();
//            }
//            else if(mode2 == "Multi burst"){
//                handler->pdm_mode(MULTI_BURST);
//                multiburstup_mode();
//                multiburstdown_mode();

//            }
             motoroff();
               handler->speaker_on(pro5,0,0,1);
        }
    }
    //us2
    if (sensor > 0 && sensor < 4096) {
        int pro6 = sensor * 580 / 4096;
       int pro7=std::min(vac2,pro6);
        ui->label_93->setNum(pro7);
        if(vac2 == pro7){

//            if(mode2 == "Ocupulse"){
//              handler->pdm_mode(OCUPULSE);
//              ocupulseup_mode();
//              ocupulsedown_mode();
//            }
//            else if(mode2=="Ocuburst"){
//                handler->pdm_mode(OCUBURST);
//                ocuburstup_mode();
//                ocuburstdown_mode();
//            }
//            else if(mode2 == "Multi burst"){
//                handler->pdm_mode(MULTI_BURST);
//                multiburstup_mode();
//                multiburstdown_mode();

//            }
             motoroff();
               handler->speaker_on(pro7,0,0,1);
        }
    }
    //us1
    if (sensor > 0 && sensor < 4096) {
        int pro7 = sensor * 580 / 4096;
        int pro8=std::min(vac1,pro7);
        ui->label_8->setNum(pro8);
        if(vac1 ==  pro8){

            if(mode3 == "Ocupulse"){
                handler->freq_count(2500);
                handler->fs_count(3000);
            handler->pdm_mode(PULSE_MODE);
              ocupulseup_mode();
              ocupulsedown_mode();
            }
            else if(mode3=="Ocuburst"){
                handler->freq_count(2500);
                handler->fs_count(3000);
                handler->pdm_mode(PULSE_MODE);
                ocuburstup_mode();
                ocuburstdown_mode();
            }
            else if(mode3 == "Multi burst"){
                handler->freq_count(2500);
                handler->fs_count(3000);
                handler->pdm_mode(PULSE_MODE);
                multiburstup_mode();
                multiburstdown_mode();

            }
             motoroff();
               handler->speaker_on(pro8,0,0,1);
        }
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
           QString mode=ui->CutMode_vitCom->currentText();
           QString mode1=ui->CutMode_vitCom_2->currentText();
           QString mode2=ui->CutMode_vitCom_3->currentText();
           QString mode3=ui->CutMode_vitCom_4->currentText();
    if (sensor > 0 && sensor < 4096) {
      //  int pro = sensor * vac5 / 4096+50;
        float pro=sensor*580/4096;
       ui->label_113->setText(QString::number(static_cast<int>(pro)));

        if(vac5==pro){
        motoroff();
          handler->speaker_on(pro,0,0,1);
    }
    }
    if (sensor > 0 && sensor < 4096) {
        int pro1 = sensor * 580 / 4096;
        pro1=std::min(vac6,pro1);
        ui->label_109->setText(QString::number(pro1));
        if(vac6 == pro1){
            motoroff();
              handler->speaker_on(pro1,0,0,1);
        }
    }
    if (sensor > 0 && sensor < 4096) {
        int pro3 = sensor * 580 / 4096;
        pro3=std::min(vac7,pro3);
        ui->label_118->setText(QString::number(pro3));
        if(vac7 == pro3){
            motoroff();
              handler->speaker_on(pro3,0,0,1);
        }
    }
    //us4
    if (sensor > 0 && sensor < 4096) {
        int pro4 = sensor * 580 / 4096;
        pro4=std::min(vac4,pro4);
        ui->label_104->setText(QString::number(pro4));
        if(vac4 == pro4){

//            if(mode3 == "Ocupulse"){
//              handler->pdm_mode(OCUPULSE);
//              ocupulseup_mode();
//              ocupulsedown_mode();
//            }
//            else if(mode3=="Ocuburst"){
//                handler->pdm_mode(OCUBURST);
//                ocuburstup_mode();
//                ocuburstdown_mode();
//            }
//            else if(mode3 == "Multi burst"){
//                handler->pdm_mode(MULTI_BURST);
//                multiburstup_mode();
//                multiburstdown_mode();

//            }
             motoroff();
               handler->speaker_on(pro4,0,0,1);
        }
    }
    //us3
    if (sensor > 0 && sensor < 4096) {
        int pro5 = sensor * 580 / 4096;
        pro5=std::min(vac3,pro5);
        ui->label_99->setText(QString::number(pro5));
        if(vac3 == pro5){

//            if(mode3 == "Ocupulse"){
//              handler->pdm_mode(OCUPULSE);
//              ocupulseup_mode();
//              ocupulsedown_mode();
//            }
//            else if(mode3=="Ocuburst"){
//                handler->pdm_mode(OCUBURST);
//                ocuburstup_mode();
//                ocuburstdown_mode();
//            }
//            else if(mode3 == "Multi burst"){
//                handler->pdm_mode(MULTI_BURST);
//                multiburstup_mode();
//                multiburstdown_mode();

//            }
             motoroff();
               handler->speaker_on(pro5,0,0,1);
        }
    }
    //us2
    if (sensor > 0 && sensor < 4096) {
        int pro6 = sensor * 580 / 4096;
        pro6=std::min(vac2,pro6);
        ui->label_93->setText(QString::number(pro6));
        if(vac2==pro6){

//            if(mode3 == "Ocupulse"){
//              handler->pdm_mode(OCUPULSE);
//              ocupulseup_mode();
//              ocupulsedown_mode();
//            }
//            else if(mode3=="Ocuburst"){
//                handler->pdm_mode(OCUBURST);
//                ocuburstup_mode()  handler->speaker_on(pro5,0,0,1);;
//                ocuburstdown_mode();
//            }
//            else if(mode3 == "Multi burst"){
//                handler->pdm_mode(MULTI_BURST);
//                multiburstup_mode();
//                multiburstdown_mode();

//            }  handler->speaker_on(pro5,0,0,1);
             motoroff();
             handler->speaker_on(pro6,0,0,1);

        }
    }
    //us1
    if (sensor > 0 && sensor < 4096) {
        int pro7 = sensor * 580 / 4096;
        pro7=std::min(vac1,pro7);
        ui->label_8->setText(QString::number(pro7));
        if(vac1 == pro7){

            if(mode3 == "Ocupulse"){
                handler->freq_count(2500);
                handler->fs_count(3000);
            handler->pdm_mode(PULSE_MODE);
              ocupulseup_mode();
              ocupulsedown_mode();
            }
            else if(mode3=="Ocuburst"){
                handler->freq_count(2500);
                handler->fs_count(3000);
                handler->pdm_mode(PULSE_MODE);
                ocuburstup_mode();
                ocuburstdown_mode();
            }
            else if(mode3 == "Multi burst"){
                handler->freq_count(2500);
                handler->fs_count(3000);
                 handler->pdm_mode(PULSE_MODE);
                multiburstup_mode();
                multiburstdown_mode();

            }
             motoroff();
             handler->speaker_on(pro7,0,0,1);

        }
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
//    currentButtonIndex = index;

//    // Deselect all buttons
//    ui->DIABUT->setChecked(false);
//    ui->ULTRASONICBUT1->setChecked(false);
//    ui->ULTRASONICBUT2->setChecked(false);
//    ui->ULTRASONICBUT3->setChecked(false);
//    ui->ULTRASONICBUT4->setChecked(false);
//    ui->IA1BUT->setChecked(false);
//    ui->IA2BUT->setChecked(false);
//    ui->VITRECTOMYBUT->setChecked(false);

//    // Select the current button
//    switch (index)
//    {
//        case 0: ui->DIABUT->setChecked(true); break;
//        case 1: ui->ULTRASONICBUT1->setChecked(true); break;
//        case 2: ui->ULTRASONICBUT2->setChecked(true); break;
//        case 3: ui->ULTRASONICBUT3->setChecked(true); break;
//        case 4: ui->ULTRASONICBUT4->setChecked(true); break;
//          case 5: ui->IA1BUT->setChecked(true); break;
//          case 6: ui->IA2BUT->setChecked(true); break;
//          case 7: ui->VITRECTOMYBUT->setChecked(true); break;
//        default: return; // Guard against invalid indices
//    }

//    // Change the tab in the tab widget
//    ui->tabWidget->setCurrentIndex(index);
}
int MainWindow::readGPIO(int gpio,int gpio1,int gpio2,int gpio3) {
    // Define file paths for GPIO 961 and 962
    QString gpio961Path = "/sys/class/gpio/gpio961/value";
    QString gpio962Path = "/sys/class/gpio/gpio962/value";

    // Read GPIO 961
    QFile gpioFile961(gpio961Path);
    if (!gpioFile961.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to read GPIO 961 value";
        return -1; // Return an error value
    }

    QTextStream in961(&gpioFile961);
    QString gpioValueStr961 = in961.readLine().trimmed();
    gpioFile961.close();

    bool ok961;
    int gpioValue961 = gpioValueStr961.toInt(&ok961);
    if (!ok961) {
        qDebug() << "Error: Invalid GPIO 961 value" << gpioValueStr961;
        return -1; // Return an error value
    }

    // Read GPIO 962
    QFile gpioFile962(gpio962Path);
    if (!gpioFile962.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to read GPIO 962 value";
        return -1; // Return an error value
    }

    QTextStream in962(&gpioFile962);
    QString gpioValueStr962 = in962.readLine().trimmed();
    gpioFile962.close();

    bool ok962;
    int gpioValue962 = gpioValueStr962.toInt(&ok962);
    if (!ok962) {
        qDebug() << "Error: Invalid GPIO 962 value" << gpioValueStr962;
        return -1; // Return an error value
    }

    // Combine or return the GPIO values as needed
    // Example: Return combined value (bitwise OR), or handle each separately.
    return (gpioValue961 << 1) | gpioValue962;
}


void MainWindow::movePushButtonTopToBottom()
{
    // Check if the current button index is valid
    if (buttonforgpio < 0 || buttonforgpio >= 8) {
        qDebug() << "Error: Invalid button index" << buttonforgpio;
        return; // Return early if the index is invalid
    }

    // Deselect the current button
    if (buttons[buttonforgpio] != nullptr) {
        buttons[buttonforgpio]->setChecked(false);
    } else {
        qDebug() << "Error: Null pointer for button at index" << buttonforgpio;
        return; // Return early if the button is null
    }

    // Move to the next button in sequence
    buttonforgpio = (buttonforgpio + 1) % 8;

    // If the index reaches 7 (last button), check the GPIO pin
    if (buttonforgpio == 7) {
        int gpioValue = readGPIO(961,962,963,964); // Replace with your GPIO reading function

        if (gpioValue == 0) {
            // If GPIO pin is 0, reset to the 0th index
            buttonforgpio = 0;
        }
    }

    // Select the next button
    if (buttons[buttonforgpio] != nullptr) {
        buttons[buttonforgpio]->setChecked(true);
    } else {
        qDebug() << "Error: Null pointer for button at index" << buttonforgpio;
        return; // Return early if the button is null
    }

    // Optionally switch the tab if buttons are linked to tabs
    ui->tabWidget->setCurrentIndex(buttonforgpio);

    qDebug() << "Moved to button:" << buttonforgpio + 1;
}

void MainWindow::movePushButtonBottomToTop()
{
    if (currentButtonIndex > 0) {
            --currentButtonIndex;
        } else {
            currentButtonIndex = 6;
        }
        buttons[currentButtonIndex]->setFocus();
        ui->tabWidget->setCurrentIndex(currentButtonIndex);
}


void MainWindow::onPdmModeSelected() {
    // Example logic for handling mode selection
    int usIndex = 1; // Default index for Continuous
    moveTab(usIndex);
}
void MainWindow::onPdmModeSelected1(){
    int index=2;
    moveTab1(index);
}
void MainWindow::onPdmModeSelected2(){
    int indec=3;
    moveTab2(indec);
}
void MainWindow::onPdmModeSelected3(){
        int index=4;
        moveTab3(index);
}


void MainWindow::moveTab(int usIndex) {
    if (!ui->tabWidget_2) {
        qDebug() << "tabWidget_2 is null!";
        return;
    }

    int currentIndex = ui->tabWidget_2->currentIndex();
    int tabCount = ui->tabWidget_2->count();

    if (tabCount == 0) {
        qDebug() << "No tabs available!";
        return;
    }

    // Update tab index based on usIndex
    if (usIndex == 1 || usIndex == 2) {
        currentIndex = (currentIndex + 1) % tabCount;
    } else if (usIndex == 3 || usIndex == 4) {
        currentIndex = (currentIndex - 1 + tabCount) % tabCount;
    } else {
        qDebug() << "Invalid usIndex value:" << usIndex;
        return;
    }

    ui->tabWidget_2->setCurrentIndex(currentIndex);

    // Update combo boxes based on usIndex
    if (usIndex == 1) {
        if (ui->CutMode_vitCom) {
            ui->CutMode_vitCom->setCurrentIndex(currentIndex);
        }

    }

    qDebug() << "Moved to tab index:" << currentIndex << " and updated combo box for usIndex:" << usIndex;
}
void MainWindow::moveTab1(int usIndex) {
    if (!ui->tabWidget_2) {
        qDebug() << "tabWidget_2 is null!";
        return;
    }

    int currentIndex = ui->tabWidget_2->currentIndex();
    int tabCount = ui->tabWidget_2->count();

    if (tabCount == 0) {
        qDebug() << "No tabs available!";
        return;
    }

    // Update tab index based on usIndex
    if (usIndex == 1 || usIndex == 2) {
        currentIndex = (currentIndex + 1) % tabCount;
    } else if (usIndex == 3 || usIndex == 4) {
        currentIndex = (currentIndex - 1 + tabCount) % tabCount;
    } else {
        qDebug() << "Invalid usIndex value:" << usIndex;
        return;
    }

    ui->tabWidget_2->setCurrentIndex(currentIndex);

    // Update combo boxes based on usIndex
   if (usIndex == 2) {
        if (ui->CutMode_vitCom_2) {
            ui->CutMode_vitCom_2->setCurrentIndex(currentIndex);
        }
    }

    qDebug() << "Moved to tab index:" << currentIndex << " and updated combo box for usIndex:" << usIndex;
}
void MainWindow::moveTab2(int usIndex) {
    if (!ui->tabWidget_2) {
        qDebug() << "tabWidget_2 is null!";
        return;
    }

    int currentIndex = ui->tabWidget_2->currentIndex();
    int tabCount = ui->tabWidget_2->count();

    if (tabCount == 0) {
        qDebug() << "No tabs available!";
        return;
    }

    // Update tab index based on usIndex
    if (usIndex == 1 || usIndex == 2) {
        currentIndex = (currentIndex + 1) % tabCount;
    } else if (usIndex == 3 || usIndex == 4) {
        currentIndex = (currentIndex - 1 + tabCount) % tabCount;
    } else {
        qDebug() << "Invalid usIndex value:" << usIndex;
        return;
    }

    ui->tabWidget_2->setCurrentIndex(currentIndex);

    // Update combo boxes based on usIndex
   if (usIndex == 3) {
        if (ui->CutMode_vitCom_3) {
            ui->CutMode_vitCom_3->setCurrentIndex(currentIndex);
        }
    }

    qDebug() << "Moved to tab index:" << currentIndex << " and updated combo box for usIndex:" << usIndex;
}
void MainWindow::moveTab3(int usIndex) {
    if (!ui->tabWidget_2) {
        qDebug() << "tabWidget_2 is null!";
        return;
    }

    int currentIndex = ui->tabWidget_2->currentIndex();
    int tabCount = ui->tabWidget_2->count();

    if (tabCount == 0) {
        qDebug() << "No tabs available!";
        return;
    }

    // Update tab index based on usIndex
    if (usIndex == 1 || usIndex == 2) {
        currentIndex = (currentIndex + 1) % tabCount;
    } else if (usIndex == 3 || usIndex == 4) {
        currentIndex = (currentIndex - 1 + tabCount) % tabCount;
    } else {
        qDebug() << "Invalid usIndex value:" << usIndex;
        return;
    }

    ui->tabWidget_2->setCurrentIndex(currentIndex);

    // Update combo boxes based on usIndex
   if (usIndex == 4) {
        if (ui->CutMode_vitCom_4) {
            ui->CutMode_vitCom_4->setCurrentIndex(currentIndex);
        }
    }

    qDebug() << "Moved to tab index:" << currentIndex << " and updated combo box for usIndex:" << usIndex;
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

}

void MainWindow::continousirrigation(int gpioValue)
{ qDebug() << "connected to MainWindow, continuous irrigation function called, GPIO value:" << gpioValue;

    QString styleSheetOn = "QPushButton {"
                           "font: 20pt Ubuntu;"
                           "background-color: green;"
                           "color: black;"
                           "image: url(:/images/ci.png);"
                           "border: 5px solid black;"
                           "border-radius: 30px;"
                           "font-weight: bold;"
                           "}";

    QString styleSheetOff = "QPushButton {"
                            "font: 20pt Ubuntu;"
                            "background-color: red;"
                            "image: url(:/images/ci.png);"
                            "border: 5px solid black;"
                            "border-radius: 30px;"
                            "font-weight: bold;"
                            "}";

    if (gpioValue == 0) {
        if (!overallci) {
            // Turn on Continuous Irrigation
            ui->CI5_5->setStyleSheet(styleSheetOn);
            ui->CI5_5->update(); // Force UI update
            overallci = true;
            handler->pinchvalve_on();
            handler->safetyvent_on();
            handler->speaker_on(0, 0, 1, 0);
            qDebug() << "Continuous irrigation turned ON.";
        } else {
            // Turn off Continuous Irrigation
            ui->CI5_5->setStyleSheet(styleSheetOff);
            ui->CI5_5->update(); // Force UI update
            overallci = false;
            handler->safetyvent_off();
            handler->pinchvalve_off();
            handler->speaker_off();
            qDebug() << "Continuous irrigation turned OFF.";
        }
    } else {
        qDebug() << "GPIO value is not 0; no action taken.";
    }
}

void MainWindow::poweronoff(int gpio)
{

    if (gpio == 0) {
           // Toggle the power state
           powerOn1 = !powerOn1;

           // Enable or disable the buttons based on the power state
           enableButtons(powerOn1);
       }

}

void MainWindow::poweron()
{

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
                             " background-color: red;"
                             " color: black;"
                             " border:5px solid black;"
                             " border-radius:30px; font-weight: bold;"
                             "}";

    // Update button state
    power.buttonState = buttonText;
     int pow1=ui->lineEdit_57->text().toInt();

    if (power.buttonState == "OFF" && (range > 0)) {

        ui->us1onoff->setStyleSheet(styleSheetOn);
        ui->us1onoff->setText("ON");
        power.buttonState = "ON";
        handler->fs_count(range);
        handler->freq_count(2500);
        handler->phaco_on();
        handler->phaco_power(pow1);
        handler->pdm_mode(0);
power.powerOn1 = true;
ui->us1powup_but->setEnabled(true);
ui->us1powdown_but->setEnabled(true);

    } else {
        ui->us1onoff->setStyleSheet(styleSheetOff);
        ui->us1onoff->setText("OFF");
        power.buttonstate1 = "OFF";
        power.powerOn1 = false;
        ui->us1powup_but->setEnabled(false);
        ui->us1powdown_but->setEnabled(false);

        handler->fs_count(0);
        handler->freq_count(0);
        handler->phaco_off();
        handler->phaco_power(pow1);

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
        ui->us2powup_but->setEnabled(true);
        ui->us2powdown_but->setEnabled(true);

    } else {
        qDebug() << "Condition met to turn OFF power";

        ui->us2onoff->setStyleSheet(styleSheet2);
        ui->us2onoff->setText("OFF");
        power.buttonstate1 = "OFF";
        power.powerOn1 = false;  // Update power state
        qDebug() << "Power is turned OFF";
        ui->us2powup_but->setEnabled(false);
        ui->us2powdown_but->setEnabled(false);

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
        ui->us3powup_but->setEnabled(true);
        ui->us3powdown_but->setEnabled(true);

    }
    else{
        ui->us3onoff->setStyleSheet(styleSheet2);
        ui->us3onoff->setText("OFF");
        power.buttonstate2 = "OFF";

        ui->us3powup_but->setEnabled(false);
        ui->us3powdown_but->setEnabled(false);


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
        ui->us4powup_but->setEnabled(true);
        ui->us4powdown_but->setEnabled(true);

    }
    else{
        ui->us4onoff->setStyleSheet(styleSheet2);
        ui->us4onoff->setText("OFF");
        power.buttonstate3 = "OFF";
        power.powerOn3 = false;  // Update power state
        ui->us4powup_but->setEnabled(false);
        ui->us4powdown_but->setEnabled(false);

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
ui->vitpowup_but->setEnabled(true);
ui->vitpowdown_but->setEnabled(true);

        power.powerOn4 = true;  // Update power state
    }
    else{
        ui->vitonoff->setStyleSheet(styleSheet2);
        ui->vitonoff->setText("OFF");
        power.buttonstate4 = "OFF";

        power.powerOn4 = false;  // Update power state
        ui->vitpowup_but->setEnabled(false);
        ui->vitpowdown_but->setEnabled(false);
    }

}
//connect doctor window to mainwindow
void MainWindow::doctorwindow_show()
{


}


void MainWindow::footpedalwindow_show()
{
    foot->show();
}




void MainWindow::updateComboBox1(const QString &text) {

}

void MainWindow::updateComboBox2(const QString &text) {

}

void MainWindow::updateComboBox3(const QString &text) {

}

void MainWindow::updateComboBox4(const QString &text) {

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
int us1mode=1;

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
        ui->tabWidget_2->setCurrentIndex(0);
        modeFound = true;
        qDebug() << "Continuous mode selected";

    } else if (selected == "Pulse") {
           ui->tabWidget_2->setCurrentIndex(1);
handler->pdm_mode(PULSE_MODE);
        pulseup_mode();
        pulsedown_mode();

        modeFound = true;
        qDebug() << "Pulse mode selected";


    } else if (selected == "Ocupulse") {
handler->pdm_mode(CONTINOUS);
        ocupulseup_mode();
        ocupulsedown_mode();
        ui->tabWidget_2->setCurrentIndex(2);
        modeFound = true;
        qDebug() << "Ocupulse mode selected";


    } else if (selected == "Ocuburst") {
                ui->tabWidget_2->setCurrentIndex(3);
handler->pdm_mode(CONTINOUS);
        ocuburstup_mode();
        ocuburstdown_mode();

        modeFound = true;
        qDebug() << "Ocuburst mode selected";


    } else if (selected == "Single burst") {
         ui->tabWidget_2->setCurrentIndex(4);
handler->pdm_mode(SINGLE_BURST);
        singleburstup_mode();
        singleburstdown_mode();

        modeFound = true;
        qDebug() << "Single burst mode selected";


    } else if (selected == "Multi burst") {
           ui->tabWidget_2->setCurrentIndex(5);
handler->pdm_mode(CONTINOUS);
        multiburstup_mode();
        multiburstdown_mode();

        modeFound = true;
        qDebug() << "Multi burst mode selected";

        // Set specific values for Multi burst mode

    } else if (selected == "Cold phaco") {
          ui->tabWidget_2->setCurrentIndex(6);
handler->pdm_mode(6);
        coldphacoup_mode();
        coldphacodown_mode();
        coldphaco1up_mode();
        coldphaco1down_mode();

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
   ui->lineEdit_77->setText("400");
   ui->lineEdit_78->setText("400");
   ui->lineEdit_79->setText("400");
   ui->lineEdit_80->setText("40");
   ui->lineEdit_81->setText("15");
}


int MainWindow::getvalue(int input)
{
    if(input<=60){
        return 60;
    }else{
        return ((input-1)/60+1)*60;
    }
}



void MainWindow::on_CI4_2_clicked()
{
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
      "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;"
            "font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"

            "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;"
            "font-weight: bold;"
                                 "}";
    if(!overallci){
        ui->CI5_5->setStyleSheet(styleSheet3);

            handler->pinchvalve_on();
        handler->safetyvent_on();
        handler->speaker_on(0,0,1,0);
    }
    else{
    ui->CI5_5->setStyleSheet(styleSheet4);

        handler->safetyvent_off();
        handler->pinchvalve_off();
        handler->speaker_off();
    }
    overallci=!overallci;
}

void MainWindow::receivecombo(const QString &text)
{
ui->comboBox->setCurrentText(text);
}

void MainWindow::performpump(const QString &text)
{
  QString value=ui->comboBox->currentText();
    if(value == "Peristatic"){
// ui->pushButton->setStyleSheet("background-color:green;");
        //us1
        ui->label_87->show();
        ui->lineEdit_56->show();
        ui->us1flowup_but->show();
        ui->us1flowdown_but->show();

        ui->textEdit_41->show();

        //us2
        ui->label_91->show();
        ui->lineEdit_59->show();
        ui->us2flowup_but->show();
        ui->us2flowdown_but->show();

        ui->textEdit_44->show();
          motoroff();
        //us3
         ui->label_96->show();
        ui->lineEdit_62->show();
        ui->us3flowup_but->show();
        ui->us3flowdown_but->show();

        ui->textEdit_48->show();

        //us4
        ui->label_103->show();
        ui->lineEdit_65->show();
        ui->us4flowup_but->show();
        ui->us4flowdown_but->show();

        ui->textEdit_50->show();

        //ia 1
        ui->label_112->show();
        ui->lineEdit_69->show();
        ui->ia1flowup_but->show();
        ui->ia1flowdown_but->show();

        ui->textEdit_55->show();

        //ia2
        ui->label_108->show();
        ui->lineEdit_67->show();
        ui->ia2flowup_but->show();
        ui->ia2flowdown_but->show();

        ui->textEdit_53->show();

        //vit
        ui->label_122->show();
        ui->lineEdit_72->show();
        ui->vitflowup_but->show();
        ui->vitflowdown_but->show();

        ui->textEdit_58->show();

    }
    else{
       // ui->pushButton_2->setStyleSheet("background-color:green;");
        //us1
        ui->label_87->hide();
        ui->lineEdit_56->hide();
        ui->us1flowup_but->hide();
        ui->us1flowdown_but->hide();

        ui->textEdit_41->hide();
        //us2
        ui->label_91->hide();
        ui->lineEdit_59->hide();
        ui->us2flowup_but->hide();
        ui->us2flowdown_but->hide();

        ui->textEdit_44->hide();
        //us3
         ui->label_96->hide();
        ui->lineEdit_62->hide();
        ui->us3flowup_but->hide();
        ui->us3flowdown_but->hide();

        ui->textEdit_48->hide();
        //us4
        ui->label_103->hide();
        ui->lineEdit_65->hide();
        ui->us4flowup_but->hide();
        ui->us4flowdown_but->hide();

        ui->textEdit_50->hide();
        //ia 1
        ui->label_112->hide();
        ui->lineEdit_69->hide();
        ui->ia1flowup_but->hide();
        ui->ia1flowdown_but->hide();

        ui->textEdit_55->hide();
        //ia2
        ui->label_108->hide();
        ui->lineEdit_67->hide();
        ui->ia2flowup_but->hide();
        ui->ia2flowdown_but->hide();

        ui->textEdit_53->hide();
        //vit
        ui->label_122->hide();
        ui->lineEdit_72->hide();
        ui->vitflowup_but->hide();
        ui->vitflowdown_but->hide();

        ui->textEdit_58->hide();
    }

}

void MainWindow::receiveValues(const QString &comboBoxValue,const QString &combo, int dia, int us1pow, int us1vac, int us1asp, int us2pow, int us2vac, int us2asp, int us3pow, int us3vac, int us3asp, int us4pow, int us4vac, int us4asp, int ia1vac, int ia1asp, int ia2vac, int ia2asp, int vitcut, int vitvac, int vitasp, const QString &powmode, const QString &vacmode, const QString &powmethod, const QString &us2powmode, const QString &us2vacmode, const QString &us2powermethod, const QString &us3powmode, const QString &us3vacmode, const QString &us3powermethod, const QString &us4powmode, const QString &us4vacmode, const QString &us4powermethod, const QString &ia1mode, const QString &ia2mode, const QString &vitmode, const QString &vitvacmode)
{
    surgicalData.comboBoxValue = comboBoxValue;
    surgicalData.combo =combo;
        surgicalData.dia = dia;
        surgicalData.us1pow = us1pow;
        surgicalData.us1vac = us1vac;
        surgicalData.us1asp = us1asp;
        surgicalData.us2pow = us2pow;
        surgicalData.us2vac = us2vac;
        surgicalData.us2asp = us2asp;
        surgicalData.us3pow = us3pow;
        surgicalData.us3vac = us3vac;
        surgicalData.us3asp = us3asp;
        surgicalData.us4pow = us4pow;
        surgicalData.us4vac = us4vac;
        surgicalData.us4asp = us4asp;
        surgicalData.ia1vac = ia1vac;
        surgicalData.ia1asp = ia1asp;
        surgicalData.ia2vac = ia2vac;
        surgicalData.ia2asp = ia2asp;
        surgicalData.vitcut = vitcut;
        surgicalData.vitvac = vitvac;
        surgicalData.vitasp = vitasp;
        surgicalData.powmode = powmode;
        surgicalData.vacmode = vacmode;
        surgicalData.powmethod = powmethod;
        surgicalData.us2powmode = us2powmode;
        surgicalData.us2vacmode = us2vacmode;
        surgicalData.us2powermethod = us2powermethod;
        surgicalData.us3powmode = us3powmode;
        surgicalData.us3vacmode = us3vacmode;
        surgicalData.us3powermethod = us3powermethod;
        surgicalData.us4powmode = us4powmode;
        surgicalData.us4vacmode = us4vacmode;
        surgicalData.us4powermethod = us4powermethod;
        surgicalData.ia1mode = ia1mode;
        surgicalData.ia2mode = ia2mode;
        surgicalData.vitmode = vitmode;
        surgicalData.vitvacmode = vitvacmode;
        ui->comboBox_4->setCurrentText(surgicalData.combo);
        ui->comboBox->setCurrentText(surgicalData.comboBoxValue);
      ui->lineEdit_74->setText(QString::number(surgicalData.dia));
      //us1
      ui->lineEdit_57->setText(QString::number(surgicalData.us1pow));
      ui->lineEdit_55->setText(QString::number(surgicalData.us1vac));
      ui->lineEdit_56->setText(QString::number(surgicalData.us1asp));
      ui->us1mode->setText(surgicalData.powmode);
      ui->us1vacmode->setText(surgicalData.vacmode);
      ui->CutMode_vitCom->setCurrentText(surgicalData.powmethod);
      //us2
      ui->lineEdit_58->setText(QString::number(surgicalData.us2pow));
      ui->lineEdit_60->setText(QString::number(surgicalData.us2vac));
      ui->lineEdit_59->setText(QString::number(surgicalData.us2asp));
      ui->us2mode->setText(surgicalData.us2powmode);
      ui->us2vacmode->setText(surgicalData.us2vacmode);
      ui->CutMode_vitCom_2->setCurrentText(surgicalData.us2powermethod);
      //us3
      ui->lineEdit_61->setText(QString::number(surgicalData.us3pow));
      ui->lineEdit_63->setText(QString::number(surgicalData.us3vac));
      ui->lineEdit_62->setText(QString::number(surgicalData.us3asp));
      ui->us3mode->setText(surgicalData.us3powmode);
      ui->us3vacmode->setText(surgicalData.us3vacmode);
      ui->CutMode_vitCom_3->setCurrentText(surgicalData.us3powermethod);
      //us4
      ui->lineEdit_64->setText(QString::number(surgicalData.us4pow));
      ui->lineEdit_66->setText(QString::number(surgicalData.us4vac));
      ui->lineEdit_65->setText(QString::number(surgicalData.us4asp));
      ui->us4mode->setText(surgicalData.us4powmode);
      ui->us4vacmode->setText(surgicalData.us4vacmode);
      ui->CutMode_vitCom_4->setCurrentText(surgicalData.us4powermethod);
      //ia1
      ui->lineEdit_70->setText(QString::number(surgicalData.ia1vac));
      ui->lineEdit_69->setText(QString::number(surgicalData.ia1asp));
      ui->lineEdit_68->setText(QString::number(surgicalData.ia2vac));
      ui->lineEdit_67->setText(QString::number(surgicalData.ia2asp));
      ui->lineEdit_71->setText(QString::number(surgicalData.vitcut));
      ui->lineEdit_73->setText(QString::number(surgicalData.vitvac));
      ui->lineEdit_72->setText(QString::number(surgicalData.vitasp));


}


void MainWindow::on_SETTINGS_BUT_2_clicked()
{
    in->show();

    connect(in, &doctor::sendleftfootvalues, foot, &footpedal::combobox1);

    connect(in, &doctor::sendrightfootvalues, foot, &footpedal::combobox2);

    connect(in, &doctor::sendbleftfootvalues, foot, &footpedal::combobox3);

    connect(in, &doctor::sendbrightfootvalues, foot, &footpedal::combobox4);

    in->exec(); // Open as a modal dialog to wait for user input
}
void MainWindow::handleDataSaved()
{
    QString currentSurgeon = ui->comboBox_4->currentText();
    if (!currentSurgeon.isEmpty()) {
        onSurgeonSelectionChanged(currentSurgeon); // Refresh data for the currently selected surgeon
    }
}

void MainWindow::connectToDatabase()
{


       QString connectionName = PATH1;

       if (QSqlDatabase::contains(connectionName)) {
           db = QSqlDatabase::database(connectionName);
       } else {
           db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
           db.setDatabaseName("phacohigh.db");
       }

       if (!db.open()) {
           qDebug() << "Database connection failed:" << db.lastError().text();
       } else {
           qDebug() << "Database connected successfully.";
       }

}
void MainWindow::populateSurgeonList()
{
    qDebug() << "Attempting to populate surgeon list.";
    if (!db.isOpen()) {
        qDebug() << "Database is not open. State:" << db.isOpenError();
        return;
    }

    QSqlQuery query(db);

    // Query to get the list of distinct surgeons
    query.prepare("SELECT DISTINCT surgeon FROM phacohigh");
    if (!query.exec()) {
        qDebug() << "Failed to fetch surgeons:" << query.lastError().text();
        return;
    }

    // Clear the combo box before populating
    ui->comboBox_4->clear();

    // Populate the combo box with surgeons
    while (query.next()) {
        QString surgeon = query.value(0).toString();
        ui->comboBox_4->addItem(surgeon);
    }

    // Query to get the last updated surgeon
    query.prepare("SELECT lastupdate FROM phacohigh LIMIT 1");
    if (!query.exec()) {
        qDebug() << "Failed to fetch last updated surgeon:" << query.lastError().text();
        return;
    }

    // Retrieve the last updated surgeon
    QString lastUpdatedSurgeon;
    if (query.next()) {
        lastUpdatedSurgeon = query.value(0).toString();
    } else {
        qDebug() << "No last updated surgeon found.";
    }

    // Find the index of the last updated surgeon
    int index = ui->comboBox_4->findText(lastUpdatedSurgeon);

    if (index != -1) {
        ui->comboBox_4->setCurrentIndex(index);
    } else if (ui->comboBox_4->count() > 0) {
        // Default to the first item if the last updated surgeon is not found
        ui->comboBox_4->setCurrentIndex(0);
    }

    qDebug() << "Surgeon list populated and last updated surgeon set.";
}


void MainWindow::onSurgeonSelectionChanged(const QString &surgeonName)
{
    qDebug() << "Attempting to fetch data for surgeon:" << surgeonName;

    // Check if the database is open
    if (!db.isOpen()) {
        qDebug() << "Database is not open. Error state:" << db.isOpenError();
        return;
    }

    // Prepare a single query to fetch all required data
    QSqlQuery query(db);
    query.prepare(
        "SELECT diapowmax, pump, Epinaspmax, Epinvacmax, Epinpowmax, "
        "quadpowmax, quadvacmax, quadaspmax, Quadvacmode, Quadpowermethod, Quadpowmode, "
        "caspmax, cvacmax, cpowmax, Chopvacmode, Choppowermethod, Choppowmode, "
        "saspmax, svacmax, spowmax, Sculptvacmode, Sculptpowermethod, Sculptpowmode, "
        "cortexaspmode, cortexvacmode, polishaspmode, polishvacmode, "
        "ia1aspmax, ia1vacmax, ia2aspmax, ia2vacmax, "
        "vitcutmax, vitvacmax, vitaspmax, vitcutmode, vitvacmode, "
        "Epinpowermethod, Epinpowmode, Epinvacmode "
        "FROM phacohigh "
        "WHERE surgeon = :surgeon"
    );
    query.bindValue(":surgeon", surgeonName);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to fetch data for surgeon:" << query.lastError().text();
        return;
    }

    // Check if data is available and update the UI
    if (query.next()) {
        // Retrieve the values from the query result
        int phacoPowerMax = query.value("diapowmax").toInt();
        QString pump = query.value("pump").toString();

        // US1 (Epinucleus) parameters
        int us1power = query.value("Epinpowmax").toInt();
        int us1vacmax = query.value("Epinvacmax").toInt();
        int us1flowmax = query.value("Epinaspmax").toInt();
        QString us1mode = query.value("Epinpowmode").toString();
        QString us1vacmode = query.value("Epinvacmode").toString();
        QString us1powermethod = query.value("Epinpowermethod").toString();

        // US2 (Quadrant) parameters
        int us2power = query.value("quadpowmax").toInt();
        int us2vacmax = query.value("quadvacmax").toInt();
        int us2aspmax = query.value("quadaspmax").toInt();
        QString us2mode = query.value("Quadpowmode").toString();
        QString us2vacmode = query.value("Quadvacmode").toString();
        QString us2powermethod = query.value("Quadpowermethod").toString();

        // US3 (Chop) parameters
        int us3power = query.value("cpowmax").toInt();
        int us3vacmax = query.value("cvacmax").toInt();
        int us3aspmax = query.value("caspmax").toInt();
        QString us3mode = query.value("Choppowmode").toString();
        QString us3vacmode = query.value("Chopvacmode").toString();
        QString us3powermethod = query.value("Choppowermethod").toString();

        // US4 (Sculpt) parameters
        int us4power = query.value("spowmax").toInt();
        int us4vacmax = query.value("svacmax").toInt();
        int us4aspmax = query.value("saspmax").toInt();
        QString us4mode = query.value("Sculptpowmode").toString();
        QString us4vacmode = query.value("Sculptvacmode").toString();
        QString us4powermethod = query.value("Sculptpowermethod").toString();

        // IA (Irrigation/Aspiration) parameters
        int ia1vacmax = query.value("ia1vacmax").toInt();
        int ia1aspmax = query.value("ia1aspmax").toInt();
        int ia2vacmax = query.value("ia2vacmax").toInt();
        int ia2aspmax = query.value("ia2aspmax").toInt();
        QString ia1mode = query.value("cortexvacmode").toString();
        QString ia2mode = query.value("polishvacmode").toString();

        // Vitrectomy parameters
        int vitcutmax = query.value("vitcutmax").toInt();
        int vitvacmax = query.value("vitvacmax").toInt();
        int vitaspmax = query.value("vitaspmax").toInt();
        QString vitcutmode = query.value("vitcutmode").toString();
        QString vitvacmode = query.value("vitvacmode").toString();

        // Debugging output to verify fetched values
        qDebug() << "Pump value retrieved:" << pump;
        qDebug() << "US1 Epinucleus - Power:" << us1power << "Vacuum:" << us1vacmax << "Flow:" << us1flowmax;
        qDebug() << "US2 Quadrant - Power:" << us2power << "Vacuum:" << us2vacmax << "Aspiration:" << us2aspmax;
        qDebug() << "US3 Chop - Power:" << us3power << "Vacuum:" << us3vacmax << "Aspiration:" << us3aspmax;
        qDebug() << "US4 Sculpt - Power:" << us4power << "Vacuum:" << us4vacmax << "Aspiration:" << us4aspmax;

        // Update UI components with the retrieved values
        ui->lineEdit_74->setText(QString::number(phacoPowerMax));
        ui->comboBox->setCurrentText(pump);
        // Update US1 UI components
        ui->lineEdit_57->setText(QString::number(us1power));  // Power
        ui->lineEdit_55->setText(QString::number(us1vacmax)); // Vacuum
        ui->lineEdit_56->setText(QString::number(us1flowmax)); // Flow
        ui->us1mode->setText(us1mode);
        ui->us1vacmode->setText(us1vacmode);
        ui->CutMode_vitCom->setCurrentText(us1powermethod);

        // Update US2 UI components
        ui->lineEdit_58->setText(QString::number(us2power)); // Power
        ui->lineEdit_60->setText(QString::number(us2vacmax)); // Vacuum
        ui->lineEdit_59->setText(QString::number(us2aspmax)); // Aspiration
        ui->us2mode->setText(us2mode);
        ui->us2vacmode->setText(us2vacmode);
        ui->CutMode_vitCom_2->setCurrentText(us2powermethod);

        // Update US3 UI components
        ui->lineEdit_61->setText(QString::number(us3power)); // Power
        ui->lineEdit_63->setText(QString::number(us3vacmax)); // Vacuum
        ui->lineEdit_62->setText(QString::number(us3aspmax)); // Aspiration
        ui->us3mode->setText(us3mode);
        ui->us3vacmode->setText(us3vacmode);
        ui->CutMode_vitCom_3->setCurrentText(us3powermethod);

        // Update US4 UI components
        ui->lineEdit_64->setText(QString::number(us4power)); // Power
        ui->lineEdit_66->setText(QString::number(us4vacmax)); // Vacuum
        ui->lineEdit_65->setText(QString::number(us4aspmax)); // Aspiration
        ui->us4mode->setText(us4mode);   // Changed from us1mode to us4mode
        ui->us4vacmode->setText(us4vacmode);   // Changed from us1vacmode to us4vacmode
        ui->CutMode_vitCom_4->setCurrentText(us4powermethod);

        // Update IA1 and IA2 UI components
        ui->lineEdit_70->setText(QString::number(ia1vacmax));
        ui->lineEdit_69->setText(QString::number(ia1aspmax));
        ui->lineEdit_68->setText(QString::number(ia2vacmax));
        ui->lineEdit_67->setText(QString::number(ia2aspmax));
        ui->ia1mode->setText(ia1mode);
        ui->ia2mode->setText(ia2mode);

        // Update Vitrectomy UI components
        ui->lineEdit_71->setText(QString::number(vitcutmax));
        ui->lineEdit_72->setText(QString::number(vitvacmax));
        ui->lineEdit_73->setText(QString::number(vitaspmax));
        ui->vitmode->setText(vitcutmode);
        ui->vitvacmode->setText(vitvacmode);
    } else {
        qDebug() << "No data found for surgeon:" << surgeonName;
    }
}
int MainWindow::pull() {
    QSqlQuery query("SELECT lastselected FROM database ORDER BY surgeon DESC LIMIT 1");
    if (query.next()) {
        qDebug()<<"pull"<<query.value(0).toInt();
        return query.value(0).toInt();
    }
    return -1; // Return a default value if no entry is found
}

void MainWindow::push(const QString &surgeonName) {
    qDebug() << "Attempting to fetch data for surgeon:" << surgeonName;

    // Check if the database is open
    if (!db.isOpen()) {
        qDebug() << "Database is not open. Error state:" << db.isOpenError();
        return;
    }

    // Prepare a single query to fetch all required data
    QSqlQuery query(db);
    query.prepare(
        "SELECT diapowmax, pump, Epinaspmax, Epinvacmax, Epinpowmax, "
        "quadpowmax, quadvacmax, quadaspmax, Quadvacmode, Quadpowermethod, Quadpowmode, "
        "caspmax, cvacmax, cpowmax, Chopvacmode, Choppowermethod, Choppowmode, "
        "saspmax, svacmax, spowmax, Sculptvacmode, Sculptpowermethod, Sculptpowmode, "
        "cortexaspmode, cortexvacmode, polishaspmode, polishvacmode, "
        "ia1aspmax, ia1vacmax, ia2aspmax, ia2vacmax, "
        "vitcutmax, vitvacmax, vitaspmax, vitcutmode, vitvacmode, "
        "Epinpowermethod, Epinpowmode, Epinvacmode "
        "FROM phacohigh "
        "WHERE surgeon = :surgeon"
    );
    query.bindValue(":surgeon", surgeonName);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to fetch data for surgeon:" << query.lastError().text();
        return;
    }
    if (query.next()) {
            // Process the data as needed...
            // Emit the signal to update the footpedal class
            emit surgeonSelected(surgeonName);
          foot->setSurgeonName(surgeonName);
        }
    // Check if data is available and update the UI
    if (query.next()) {
        // Retrieve the values from the query result
        int phacoPowerMax = query.value("diapowmax").toInt();
        QString pump = query.value("pump").toString();

        // US1 (Epinucleus) parameters
        int us1power = query.value("Epinpowmax").toInt();
        int us1vacmax = query.value("Epinvacmax").toInt();
        int us1flowmax = query.value("Epinaspmax").toInt();
        QString us1mode = query.value("Epinpowmode").toString();
        QString us1vacmode = query.value("Epinvacmode").toString();
        QString us1powermethod = query.value("Epinpowermethod").toString();

        // US2 (Quadrant) parameters
        int us2power = query.value("quadpowmax").toInt();
        int us2vacmax = query.value("quadvacmax").toInt();
        int us2aspmax = query.value("quadaspmax").toInt();
        QString us2mode = query.value("Quadpowmode").toString();
        QString us2vacmode = query.value("Quadvacmode").toString();
        QString us2powermethod = query.value("Quadpowermethod").toString();

        // US3 (Chop) parameters
        int us3power = query.value("cpowmax").toInt();
        int us3vacmax = query.value("cvacmax").toInt();
        int us3aspmax = query.value("caspmax").toInt();
        QString us3mode = query.value("Choppowmode").toString();
        QString us3vacmode = query.value("Chopvacmode").toString();
        QString us3powermethod = query.value("Choppowermethod").toString();

        // US4 (Sculpt) parameters
        int us4power = query.value("spowmax").toInt();
        int us4vacmax = query.value("svacmax").toInt();
        int us4aspmax = query.value("saspmax").toInt();
        QString us4mode = query.value("Sculptpowmode").toString();
        QString us4vacmode = query.value("Sculptvacmode").toString();
        QString us4powermethod = query.value("Sculptpowermethod").toString();

        // IA (Irrigation/Aspiration) parameters
        int ia1vacmax = query.value("ia1vacmax").toInt();
        int ia1aspmax = query.value("ia1aspmax").toInt();
        int ia2vacmax = query.value("ia2vacmax").toInt();
        int ia2aspmax = query.value("ia2aspmax").toInt();
        QString ia1mode = query.value("cortexvacmode").toString();
        QString ia2mode = query.value("polishvacmode").toString();

        // Vitrectomy parameters
        int vitcutmax = query.value("vitcutmax").toInt();
        int vitvacmax = query.value("vitvacmax").toInt();
        int vitaspmax = query.value("vitaspmax").toInt();
        QString vitcutmode = query.value("vitcutmode").toString();
        QString vitvacmode = query.value("vitvacmode").toString();

        // Debugging output to verify fetched values
        qDebug() << "Pump value retrieved:" << pump;
        qDebug() << "US1 Epinucleus - Power:" << us1power << "Vacuum:" << us1vacmax << "Flow:" << us1flowmax;
        qDebug() << "US2 Quadrant - Power:" << us2power << "Vacuum:" << us2vacmax << "Aspiration:" << us2aspmax;
        qDebug() << "US3 Chop - Power:" << us3power << "Vacuum:" << us3vacmax << "Aspiration:" << us3aspmax;
        qDebug() << "US4 Sculpt - Power:" << us4power << "Vacuum:" << us4vacmax << "Aspiration:" << us4aspmax;

        // Update UI components with the retrieved values
        ui->lineEdit_74->setText(QString::number(phacoPowerMax));
        ui->comboBox->setCurrentText(pump);
        // Update US1 UI components
        ui->lineEdit_57->setText(QString::number(us1power));  // Power
        ui->lineEdit_55->setText(QString::number(us1vacmax)); // Vacuum
        ui->lineEdit_56->setText(QString::number(us1flowmax)); // Flow
        ui->us1mode->setText(us1mode);
        ui->us1vacmode->setText(us1vacmode);
        ui->CutMode_vitCom->setCurrentText(us1powermethod);

        // Update US2 UI components
        ui->lineEdit_58->setText(QString::number(us2power)); // Power
        ui->lineEdit_60->setText(QString::number(us2vacmax)); // Vacuum
        ui->lineEdit_59->setText(QString::number(us2aspmax)); // Aspiration
        ui->us2mode->setText(us2mode);
        ui->us2vacmode->setText(us2vacmode);
        ui->CutMode_vitCom_2->setCurrentText(us2powermethod);

        // Update US3 UI components
        ui->lineEdit_61->setText(QString::number(us3power)); // Power
        ui->lineEdit_63->setText(QString::number(us3vacmax)); // Vacuum
        ui->lineEdit_62->setText(QString::number(us3aspmax)); // Aspiration
        ui->us3mode->setText(us3mode);
        ui->us3vacmode->setText(us3vacmode);
        ui->CutMode_vitCom_3->setCurrentText(us3powermethod);

        // Update US4 UI components
        ui->lineEdit_64->setText(QString::number(us4power)); // Power
        ui->lineEdit_66->setText(QString::number(us4vacmax)); // Vacuum
        ui->lineEdit_65->setText(QString::number(us4aspmax)); // Aspiration
        ui->us4mode->setText(us4mode);   // Changed from us1mode to us4mode
        ui->us4vacmode->setText(us4vacmode);   // Changed from us1vacmode to us4vacmode
        ui->CutMode_vitCom_4->setCurrentText(us4powermethod);

        // Update IA1 and IA2 UI components
        ui->lineEdit_70->setText(QString::number(ia1vacmax));
        ui->lineEdit_69->setText(QString::number(ia1aspmax));
        ui->lineEdit_68->setText(QString::number(ia2vacmax));
        ui->lineEdit_67->setText(QString::number(ia2aspmax));
        ui->ia1mode->setText(ia1mode);
        ui->ia2mode->setText(ia2mode);

        // Update Vitrectomy UI components
        ui->lineEdit_71->setText(QString::number(vitcutmax));
        ui->lineEdit_72->setText(QString::number(vitvacmax));
        ui->lineEdit_73->setText(QString::number(vitaspmax));
        ui->vitmode->setText(vitcutmode);
        ui->vitvacmode->setText(vitvacmode);
    } else {
        qDebug() << "No data found for surgeon:" << surgeonName;
    }

}
