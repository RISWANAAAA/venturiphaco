#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include<QDebug>
//check on off
//check elapsed time  //these work are pending
//check continous irrigation

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // resize(800,600);
    move(0,0);
  //  v=new Vaccumup;
 //  m=new Motorup;
    ui->CutMode_vit->hide();
    ui->CutMode_vitCom->hide();
    ui->tabWidget_2->hide();
  cs=true;
  cs1=true;
  cs2=true;
  cs3=true;
  cs4=true;
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
   // lfoot=new footlibup;
  //  hard=new hhandlerup;
    protimer=new QTimer;

        // Set the initial state of pushButton_9


    QTimer *timerfoot = new QTimer;
    timer43=new QTimer;
    QTimer *ftime=new QTimer;
    messageline->hide(); // Initially hide the message line
     //  timermsg = new QTimer(this);

       // Connect the timer's timeout signal to the slot that hides messageline
     //  connect(timermsg, &QTimer::timeout,this,&QMessageBox::hide);

    connect(timerfoot, &QTimer::timeout, this, &MainWindow::updatesensor);
       timerfoot->start(100); // 100 milliseconds interval
       sensortimer = new QTimer(this);
       connect(sensortimer, SIGNAL(timeout()), this, SLOT(sensor2()));
       sensortimer->start(100); // Update labels every 1000 milliseconds (1 second)
 //   ui->lineEdit_57->setText("100");
//       QString styleSheet = "QPushButton {"
//                            "    height: 101px;" // Height must match width for a circle
//                            "    width: 81px;" // Width must match height for a circle
//                            "    font-family: Ubuntu;"
//                            "    font-size: 20pt;"
//                            "    background-color: white;"
//                            "    color: black;"
//                            "    border-radius: 40px;" // Half of the width/height

//                            "}";

 //  ui->us1onoff->setCheckable(true);


    connect(timer,&QTimer::timeout,[=]()
    {
        message->close();

        timer->stop();

    });
//    connect(timermsg, &QTimer::timeout, [=]()
//    {
//        messageline->close();
//        timermsg->stop();
//    });
     us1_linear_nonlinear();
     us2_linear_nonlinear();
     us3_linear_nonlinear();
     us4_linear_nonlinear();
     ia1_linear_nonlinear();
     ia2_linear_nonlinear();
     vit_linear_nonlinear();
//     on_off_us1();
//     on_off_us2();
//     on_off_us3();
//     on_off_us4();
//     on_off_vit();
     //keypadd

    connect(key,&keypad::textsignal,this,&MainWindow::on_clicked);
    connect(key,&keypad::entersignal,this,&MainWindow::on_clickedenter);
//    connect(protimer,&QTimer::timeout,this,&MainWindow::footpedal);
//    protimer->start(1);

    ui->tabWidget->setTabText(6, "VITRECTOMY");
    QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; }";

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
  ui->CutMode_vitCom->addItem("continuous");
  ui->CutMode_vitCom->addItem("Pulse","15");
  ui->CutMode_vitCom->addItem("Ocupulse","15");
  ui->CutMode_vitCom->addItem("Ocuburst","170");
  ui->CutMode_vitCom->addItem("Single burst","400");
   ui->CutMode_vitCom->addItem("Multi burst","400");
    ui->CutMode_vitCom->addItem("Cold phaco","15");
//  ui->lineEdit_27->setText("40");
  connect(ui->CutMode_vitCom,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&MainWindow::updateline);
   connect(ui->CutMode_vitCom, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::tabupdate);
     connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::current);
          current(ui->tabWidget->currentIndex());
        connect(ui->lineEdit_74,&QLineEdit::textChanged,this,[=](){
        int value1=ui->lineEdit_74->text().toInt();
           });
    connect(ui->lineEdit_71,&QLineEdit::textChanged,this,[=](){
        int value2=ui->lineEdit_71->text().toInt();

    });

    connect(ui->lineEdit_73,&QLineEdit::textChanged,this,[=](){
        int value3=ui->lineEdit_73->text().toInt();

    });
    connect(ui->lineEdit_74,&QLineEdit::textChanged,this,[=](){
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
//             connect(ui->ULTRASONICBUT1, &QPushButton::clicked, this, &MainWindow::startphaco);
//           connect(ui->ULTRASONICBUT2, &QPushButton::clicked, this, &MainWindow::startphaco);
//           connect(ui->ULTRASONICBUT3, &QPushButton::clicked, this, &MainWindow::startphaco);
//           connect(ui->ULTRASONICBUT4, &QPushButton::clicked, this, &MainWindow::startphaco);

           // Set up the update timer
        //   connect(&updateTimer, &QTimer::timeout, this, &MainWindow::update);
    QRegExp regex3("^(?:100|[1-9]\\d?|0)$");
     QRegExpValidator* validator3 = new QRegExpValidator(regex3, ui->lineEdit_57);
     ui->lineEdit_57->setValidator(validator3);
     ui->lineEdit_57->setMaxLength(3);
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
      connect(ui->SETTINGS_BUT,&QPushButton::clicked,this,&MainWindow::SETTINGSBUT);
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
      //handpiece
       connect(ui->handpiece,&QPushButton::clicked,this,&MainWindow::HANDPIECE);
       //continous irrigation
       connect(ui->CI1,&QPushButton::clicked,this,&MainWindow::continous_irrigation1);
       connect(ui->CI2,&QPushButton::clicked,this,&MainWindow::continous_irrigation2);
       connect(ui->CI3,&QPushButton::clicked,this,&MainWindow::continous_irrigation3);
       connect(ui->CI4,&QPushButton::clicked,this,&MainWindow::continous_irrigation4);
       connect(ui->CI5,&QPushButton::clicked,this,&MainWindow::continous_irrigation5);

       //on off
   //  connect(ui->us1onoff,&QPushButton::clicked,this,&MainWindow::on_off_us1);
      connect(ui->us2onoff,&QPushButton::clicked,this,&MainWindow::on_off_us2);
      connect(ui->us3onoff,&QPushButton::clicked,this,&MainWindow::on_off_us3);
      connect(ui->us4onoff,&QPushButton::clicked,this,&MainWindow::on_off_us4);
      connect(ui->vitonoff,&QPushButton::clicked,this,&MainWindow::on_off_vit);

      //mode
      connect(ui->us1mode,&QPushButton::clicked,this,&MainWindow::us1_linear_nonlinear);
      connect(ui->us2mode,&QPushButton::clicked,this,&MainWindow::us2_linear_nonlinear);
      connect(ui->us3mode,&QPushButton::clicked,this,&MainWindow::us3_linear_nonlinear);
      connect(ui->us4mode,&QPushButton::clicked,this,&MainWindow::us4_linear_nonlinear);
      connect(ui->ia1mode,&QPushButton::clicked,this,&MainWindow::ia1_linear_nonlinear);
      connect(ui->ia2mode,&QPushButton::clicked,this,&MainWindow::ia2_linear_nonlinear);
      connect(ui->vitmode,&QPushButton::clicked,this,&MainWindow::vit_linear_nonlinear);

//       connect(ui->ULTRASONICBUT1, &QPushButton::clicked, [=](){
//           ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
//                 });
//       connect(ui->ULTRASONICBUT2, &QPushButton::clicked, [=](){
//           ui->ULTRASONICBUT2->setStyleSheet(styleSheet);
//       });
//       connect(ui->ULTRASONICBUT4, &QPushButton::clicked, [=](){
//           ui->ULTRASONICBUT4->setStyleSheet(styleSheet);
//       });
//       connect(ui->ULTRASONICBUT3, &QPushButton::clicked, [=](){
//           ui->ULTRASONICBUT3->setStyleSheet(styleSheet);
//       });
//       connect(ui->IA1BUT, &QPushButton::clicked, [=](){
//           ui->IA1BUT->setStyleSheet(styleSheet);
//       });
//       connect(ui->IA2BUT, &QPushButton::clicked, [=](){
//           ui->IA2BUT->setStyleSheet(styleSheet);
//       });
//       connect(ui->VITRECTOMYBUT, &QPushButton::clicked, [=](){
//           ui->VITRECTOMYBUT->setStyleSheet(styleSheet);
//       });
//      connect(ui->DIABUT, &QPushButton::clicked, [=](){
//          ui->DIABUT->setStyleSheet(styleSheet);
//      });
      connect(ui->tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(changeButtonColor(int)));
}
void MainWindow::click()
{
    QString styleSheet = "QPushButton {"

                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    background-color: white;"
                         "    color: black;"


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
void MainWindow::startphaco()
{
    if (!timer5.isValid()) {
        timer5.start();
        qDebug() << "Timer started by" << ui->elapsed_time->text();
        ui->elapsed_time->setText("Timer started");

        // Start the update timer to update every 100 milliseconds
        updateTimer.start(100);
    } else {
        qint64 elapsed = timer5.elapsed();
        qDebug() << "Elapsed time:" << elapsed << " milliseconds";
        timer5.invalidate();
        qDebug() << "Timer stopped by" << ui->elapsed_time->text();

        // Stop the update timer
        updateTimer.stop();

        // Update the button text one last time with the final elapsed time
        QString elapsedTimeStr = " ET: " +QString::number(elapsed) + " ms";
        ui->elapsed_time->setText(elapsedTimeStr);
    }
    }
void MainWindow::updateElapsedTime()
{
    if (timer5.isValid()) {
        qint64 elapsed = timer5.elapsed();
        QString elapsedTimeStr = QString::number(elapsed) + " ms";
        ui->elapsed_time->setText(elapsedTimeStr);
    }
}

void MainWindow::increaseline(QLineEdit *incrline)
{
    //bool ok;
      int value = incrline->text().toInt();
      if (value % 2 == 0) {
               // If the number is even, round it up to the next multiple of 5
               value = (value + 4) / 5 * 5;
           }

      incrline->setText(QString::number(value));
}

void MainWindow::decreaseline(QLineEdit *decreline)
{
    int value1 = decreline->text().toInt();
        if (value1 % 2 != 0) {

                 value1++;
             }
        decreline->setText(QString::number(value1));
}

void MainWindow::vaccumline(QLineEdit *vacline)
{
    int val = vacline->text().toInt();
    if (val % 2 == 0) {
             // If the number is even, round it up to the next multiple of 5
             val = (val + 4) / 5 * 5;
         }
    vacline->setText(QString::number(val));

}
//void MainWindow::changeButtonColor(int tabIndex) {

//    if (tabIndex!=0) {
//        ui->ULTRASONICBUT1->setStyleSheet("");
//  ui->ULTRASONICBUT1->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }
//    if(tabIndex!=1)
//    {
//        ui->ULTRASONICBUT2->setStyleSheet("");
//          ui->ULTRASONICBUT2->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }
//    if(tabIndex!=2){
//        ui->ULTRASONICBUT3->setStyleSheet("");
//          ui->ULTRASONICBUT3->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }
//    if(tabIndex!=3){
//    ui->ULTRASONICBUT4->setStyleSheet("");
//      ui->ULTRASONICBUT4->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }
//    if(tabIndex!=4){
//    ui->IA1BUT->setStyleSheet("");
//      ui->IA1BUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }           //empty color
//    if(tabIndex!=5){
//    ui->IA2BUT->setStyleSheet("");
//      ui->IA2BUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }
//    if(tabIndex!=6){
//    ui->VITRECTOMYBUT->setStyleSheet("");
//      ui->VITRECTOMYBUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }
//    if(tabIndex!=7){
//    ui->DIABUT->setStyleSheet("");
//      ui->DIABUT->setStyleSheet("border-radius: 20px;background-color:black;color:white;");
//    }


//        if (tabIndex == 0) {
//        ui->ULTRASONICBUT1->setStyleSheet("border-radius: 20px;background-color: green;");
//        } else if (tabIndex == 1) {
//         ui->ULTRASONICBUT2 ->setStyleSheet("border-radius: 20px;background-color: green;");
//        }                                                                      //set color
//        else if(tabIndex==2){
//             ui->ULTRASONICBUT3->setStyleSheet("border-radius: 20px;background-color: green;");
//        }
//        else if(tabIndex==3){
//             ui->ULTRASONICBUT4->setStyleSheet("border-radius: 20px;background-color: green;");
//        }
//        else if(tabIndex==4){
//             ui->IA1BUT->setStyleSheet("border-radius: 20px;background-color: green;");
//        }
//        else if(tabIndex==5){
//             ui->IA2BUT->setStyleSheet("border-radius: 20px;background-color: green;");
//        }
//        else if(tabIndex==6){
//             ui->VITRECTOMYBUT->setStyleSheet("border-radius: 20px;background-color: green;");
//        }
//        else if(tabIndex==7){
//             ui->DIABUT->setStyleSheet("border-radius: 20px;background-color: green;");
//        }
//    }
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
             timermsg->stop();      // Stop the timer if it is running
         }
     }
}


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
     increaseline(ui->lineEdit_57);
  }
  if(ui->lineEdit_55->focusWidget()) {
      ui->lineEdit_56->clearFocus();
      ui->lineEdit_57->clearFocus();
      ui->lineEdit_55->setFocus();
      int prevValue = ui->lineEdit_55->text().toInt();
      int value = (ui->lineEdit_55->text()+digit).toInt();
      setRange(ui->lineEdit_55, prevValue, value, 500);
      updateLineedit(ui->lineEdit_55, prevValue, value, 500);
      vaccumline(ui->lineEdit_55);

  }
  if(ui->lineEdit_56->focusWidget()) {
      ui->lineEdit_55->clearFocus();
      ui->lineEdit_57->clearFocus();
      ui->lineEdit_56->setFocus();
      int prevValue = ui->lineEdit_56->text().toInt();
      int value = (ui->lineEdit_56->text()+digit).toInt();
      setRange(ui->lineEdit_56, prevValue, value, 40);
   updateLineedit(ui->lineEdit_56, prevValue, value, 40);
   decreaseline(ui->lineEdit_56);
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
  }
   if(ui->lineEdit_60->focusWidget()) {
      ui->lineEdit_58->clearFocus();
      ui->lineEdit_59->clearFocus();
      ui->lineEdit_60->setFocus();
      int prevValue = ui->lineEdit_60->text().toInt();
      int value =( ui->lineEdit_60->text()+digit).toInt();

      setRange(ui->lineEdit_60, prevValue, value, 500);
      updateLineedit(ui->lineEdit_60, prevValue, value, 500);
  }
   if(ui->lineEdit_59->focusWidget()) {
      ui->lineEdit_58->clearFocus();
      ui->lineEdit_60->clearFocus();
      ui->lineEdit_59->setFocus();
      int prevValue = ui->lineEdit_59->text().toInt();
      int value = (ui->lineEdit_59->text()+digit).toInt();
      setRange(ui->lineEdit_59, prevValue, value, 40);
      updateLineedit(ui->lineEdit_59, prevValue, value, 40);
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
  }
}

void MainWindow::on_clickedenter()
{
   key->hide();
}
void MainWindow::ULTRASONICBUT1()
{
    ui->tabWidget->setCurrentIndex(0);
 //  click();
//ui->label_6->setStyleSheet("image: url(:/connected.png);");
   // ui->ULTRASONICBUT1->setStyleSheet("");
  //  changeButtonColor(0);
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

   // ui->ULTRASONICBUT2->setStyleSheet("");
   // changeButtonColor(1);


    ui->CutMode_vit->show();
    ui->CutMode_vitCom->show();
    ui->tabWidget_2->show();
    butname=2;
// footpedal();
}
void MainWindow::ULTRASONICBUT4()
{

    ui->tabWidget->setCurrentIndex(3);

  //  click();

     //changeButtonColor(3);
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
   // click();
    // changeButtonColor(5);
     ui->CutMode_vit->hide();
     ui->CutMode_vitCom->hide();
     ui->tabWidget_2->hide();
     butname=6;
   }

void MainWindow::VITRECTOMYBUT()
{
    ui->tabWidget->setCurrentIndex(6);
   // ui->label_11->setText("VITRECTOMY");
  // click();
 //   changeButtonColor(6);
    butname=7;
}

void MainWindow::DIATHERMYBUT()
{

    ui->CutMode_vit->hide();
    ui->CutMode_vitCom->hide();
    ui->tabWidget_2->hide();
    butname=0;
    ui->tabWidget->setCurrentIndex(7);
 //   click();
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
   // ui->label_3->setNum(value);

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
 //    ui->label_3->setNum(value);

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
    //  click();

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
    QString styleSheet = "QPushButton {"
                         "    height: 81px;" // Height must match width for a circle
                         "    width: 81px;" // Width must match height for a circle
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    background-color: white;"
                         "    color: black;"
                         "    border-radius: 40px;" // Half of the width/height

                         "}";

    QString styleSheet1 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 20pt;"
                          "    background-color: black;"
                          "    color: white;"
                          "    border-radius: 40px;" // Half of the width/height
                          "    height: 81px;" // Height must match width for a circle
                          "    width: 81px;" // Width must match height for a circle
                          "}";

    if (tab!=0) {
        ui->ULTRASONICBUT1->setStyleSheet("");
  ui->ULTRASONICBUT1->setStyleSheet(styleSheet1);
    }
    if(tab!=1)
    {
        ui->ULTRASONICBUT2->setStyleSheet("");
          ui->ULTRASONICBUT2->setStyleSheet(styleSheet1);
    }
    if(tab!=2){
        ui->ULTRASONICBUT3->setStyleSheet("");
          ui->ULTRASONICBUT3->setStyleSheet(styleSheet1);
    }
    if(tab!=3){
    ui->ULTRASONICBUT4->setStyleSheet("");
      ui->ULTRASONICBUT4->setStyleSheet(styleSheet1);
    }
    if(tab!=4){
    ui->IA1BUT->setStyleSheet("");
      ui->IA1BUT->setStyleSheet(styleSheet1);
    }           //empty color
    if(tab!=5){
    ui->IA2BUT->setStyleSheet("");
      ui->IA2BUT->setStyleSheet(styleSheet1);
    }
    if(tab!=6){
    ui->VITRECTOMYBUT->setStyleSheet("");
      ui->VITRECTOMYBUT->setStyleSheet(styleSheet1);
    }
    if(tab!=7){
    ui->DIABUT->setStyleSheet("");
      ui->DIABUT->setStyleSheet(styleSheet1);}

    if (tab == 0) {
    ui->ULTRASONICBUT1->setStyleSheet(styleSheet);
    } else if (tab == 1) {
     ui->ULTRASONICBUT2 ->setStyleSheet(styleSheet);
    }                                                                      //set color
    else if(tab==2){
         ui->ULTRASONICBUT3->setStyleSheet(styleSheet);
    }
    else if(tab==3){
         ui->ULTRASONICBUT4->setStyleSheet(styleSheet);
    }
    else if(tab==4){
         ui->IA1BUT->setStyleSheet(styleSheet);
    }
    else if(tab==5){
         ui->IA2BUT->setStyleSheet(styleSheet);
    }
    else if(tab==6){
         ui->VITRECTOMYBUT->setStyleSheet(styleSheet);
    }
    else if(tab==7){
         ui->DIABUT->setStyleSheet(styleSheet);
    }

}

void MainWindow::updateline(int index)
{
    QString selected=ui->CutMode_vitCom->currentData().toString();

    ui->lineEdit_75->setText(selected);
    ui->lineEdit_76->setText(selected);
    ui->lineEdit_77->setText(selected);
    ui->lineEdit_78->setText(selected);
    ui->lineEdit_79->setText(selected);
    ui->lineEdit_80->setText(selected);
}


void MainWindow::tabupdate(int index)
{
    ui->tabWidget_2->setCurrentIndex(index);
}
// LINEAR
//void MainWindow::footpedal()
//{
//    QString styleSheet3 = "QPushButton {"
//           " font:20pt Ubuntu;"
//          " background-color: green;"
//            "color: black;"
//            "image: url(:/ci.png);"
//           " border:5px solid black;"
//           " border-radius:30px;font-weight: bold;"
//                                 "}";
//    QString styleSheet4 = "QPushButton {"
//           " font:20pt Ubuntu;"
//          " background-color: red;"
//            "color: black;"
//            "image: url(:/ci.png);"
//           " border:5px solid black;"
//           " border-radius:30px;font-weight: bold;"
//                                 "}";
//    QString styleSheet1 = "QPushButton {"
//           " font:20pt Ubuntu;"
//          " background-color: green;"
//            "color: black;"

//           " border:5px solid black;"
//           " border-radius:30px;font-weight: bold;"
//                                 "}";

//    QString styleSheet2 = "QPushButton {"
//           " font:20pt Ubuntu;"
//          " background-color: rgb(224, 27, 36);"
//            "color: black;"
//            //"image: url(:/ci.png);"
//           " border:5px solid black;"
//           " border-radius:30px;font-weight: bold;"
//                                 "}";
//    int range = lfoot->convert(0x97);
//   // int val=v->convert(0xD7);
//    QString onoff=ui->us1onoff->text();
//    int progress;
//    int EPT=0;
//    switch(butname)
//    {

//    // dia
//        case 0:
//    {
//       int pow=ui->lineEdit_74->text().toInt();
// bool flag=true;
//       if(flag){
//           if(range>=0 && range<1024){
//               ui->pushButton_42->setText("0");
//              // label43();
//           }
//                 if (range >= 1024 && range < 4096)
//           {
//                      ui->pushButton_42->setText("1");
//             int progress21 = range*100/4096;
//              // int progress21 = (range - 1024) * 100 / (2048 - 1024);


//                          // Ensure progress21 does not exceed value
//                          progress21 = std::min(progress21, pow);

//                                           // Display progress value in label_49
//                          ui->label_121->setText(QString("%1").arg(progress21));
//             }}
//       else{
//           ui->label_121->setText("0");
//       }
//             break;
//   }
//        //us1
//    case 1:
//    {
//        int pow1=ui->lineEdit_57->text().toInt();
//       int flow1=ui->lineEdit_56->text().toInt();
//      //  int act1=ui->label_3->text().toInt();
//         bool flag1=true;
//        if(flag1){


//      if(us1 == "PANEL" && vus1=="PANEL"){//surgeon

//        if(range>=0 && range<1024){
//             qDebug()<<range;
//            ui->pushButton_42->setText("0");
//            ui->CI1->setStyleSheet(styleSheet4);
//            ui->us1onoff->setStyleSheet(styleSheet2);
//            ui->us1onoff->setText("OFF");

//             progress=100*range/4096;
//            progress = std::min(progress, pow1);
//            ui->label_7->setText(QString::number(progress));

//            }
//           // label43();

//        if(range>=1024 && range<2048){
//            ui->pushButton_42->setText("1");
//            motoron();
//            on_lineEdit_9_returnPressed();

//           ui->CI1->setStyleSheet(styleSheet3);
//           ui->us1onoff->setStyleSheet(styleSheet2);
//           ui->us1onoff->setText("OFF");
//             progress=100*range/4096;
//            progress = std::min(progress, pow1);
//            ui->label_7->setText(QString::number(progress));

//          //  ui->progressBar->setValue(progress);
//             }

//        else if(range>=2048 && range <3072){
//            ui->pushButton_42->setText("2");

//            int progress=100*range/4096;
//            progress = std::min(progress, pow1);
//            ui->label_7->setText(QString::number(progress));
//             //ui->progressBar_2->setValue(progress);
//             sensor2();}

//     if (range >= 3072 && range < 4096)
//        {
//            ui->pushButton_42->setText("3");
//            int progress=100*range/4096;
//            progress = std::min(progress, pow1);

//            ui->label_7->setText(QString::number(progress));
//            ui->us1onoff->setText("ON");
//            ui->us1onoff->setStyleSheet(styleSheet1);
//            qDebug()<<"Progress"<<progress;

//           qDebug()<<range;
//          sensor2();


//          //ui->elapsed_time->setText("ET:"+QString::number(ET)+"ms");
//     }
//     else{
//       //ui->label_3->setText("0");
//         ui->us1onoff->setStyleSheet(styleSheet2);
//         ui->us1onoff->setText("OFF");
//     }

//        }
//      if(us1 == "SURGEON" && vus1 == "SURGEON") {//panel
//          if(range>=0 && range <1024){
//              ui->pushButton_42->setText("0");
//               ui->CI1->setStyleSheet(styleSheet4);
//               ui->us1onoff->setStyleSheet(styleSheet2);
//               ui->us1onoff->setText("OFF");

//          }
//          else if(range>=1024 && range<2048){
//              ui->pushButton_42->setText("1");
//              motoron();
//              on_lineEdit_9_returnPressed();
//              ui->CI1->setStyleSheet(styleSheet3);
//              ui->us1onoff->setStyleSheet(styleSheet2);
//              ui->us1onoff->setText("OFF");

//          }
//          else if(range >=2048 && range<3072){
//              ui->pushButton_42->setText("2");
//              ui->us1onoff->setStyleSheet(styleSheet2);
//              ui->us1onoff->setText("OFF");
//              updatesensor();
//          }

//              if (range >= 3072 && range <= 4096) {
//                  // Power on
//                  ui->pushButton_42->setText("3");
//                  int progress1 = range*100 / 4096;
//                  int progress2 = std::min(progress, pow1);
//                  ui->label_7->setNum(progress2);
//                  updatesensor();
//                   if(progress2==pow1){
//                  ui->us1onoff->setText("ON");
//                  ui->us1onoff->setStyleSheet(styleSheet1);
//                  }
//      }

//      else {
//                         ui->label_7->setText("0");
//                         ui->us1onoff->setText("OFF");
//                         ui->us1onoff->setStyleSheet(styleSheet2);
//                     }
//}
//}

//       break;
//    }
//        // us2
//    case 2:
//    {
//        int pow2=ui->lineEdit_58->text().toInt();

//        int flow2=ui->lineEdit_59->text().toInt();
//  bool flag2=true;
//        if(flag2){
//            if(us2 == "PANEL" && vus2 == "PANEL"){//surgeon
//            if(range>=0 && range<1024){
//                ui->pushButton_42->setText("0");
//               // label43();
//                ui->CI2->setStyleSheet(styleSheet4);
//                int progress4 =range*100/4096;
//                progress4 = std::min(progress4, pow2);
//                // Display progress value in label_49
//                ui->label_92->setText(QString::number(progress4));
//                 ;
//            }
//            if(range>=1024 && range<2048){
//                ui->pushButton_42->setText("1");
//                 ui->CI2->setStyleSheet(styleSheet3);
//                int progress4 =range*100/4096;
//                progress4 = std::min(progress4, pow2);
//                // Display progress value in label_49
//                ui->label_92->setText(QString::number(progress4));
//               ;
//            }
//            else if(range>=2048 && range <3072){
//                ui->pushButton_42->setText("2");
//                int progress4 =range*100/4096;
//                progress4 = std::min(progress4, pow2);
//                // Display progress value in label_49
//                ui->label_92->setText(QString::number(progress4));
//                 sensor2();
//            }
//        if (range >= 3072 && range < 4096)
//           {

//            int progress4 =range*100/4096;
//            progress4 = std::min(progress4, pow2);
//            // Display progress value in label_49
//            ui->label_92->setText(QString::number(progress4));
//            ui->pushButton_42->setText("3");
//           sensor2();
//           if(progress4>=pow2){
//           ui->us2onoff->setText("ON");
//           ui->us2onoff->setStyleSheet(styleSheet1);
//              int ET2 = progress4 * pow2/10000;//effective time for us2
//              EPT+=ET2;
//           }
//}
//else {
//                  ui->label_92->setText("0");
//                  ui->us2onoff->setText("OFF");
//                  ui->us2onoff->setStyleSheet(styleSheet2);
//              }
//           }



//        else{
//                if(us2 == "SURGEON" && vus2 == "SURGEON") {
//                    if(range>=0 && range <1024){
//                        ui->pushButton_42->setText("0");
//                         ui->CI2->setStyleSheet(styleSheet4);
//                    }
//                    else if(range>=1024 && range<2048){
//                        ui->pushButton_42->setText("1");
//                         ui->CI2->setStyleSheet(styleSheet3);
//                    }
//                    else if(range >=2048 && range<3072){
//                        ui->pushButton_42->setText("2");
//                    }
//                if(range >=3072 && range < 4096) {
//                    ui->pushButton_42->setText("3");
//                    int progress4 =range*100/4096;
//                    ui->us2onoff->setText("ON");
//                    ui->us2onoff->setStyleSheet(styleSheet1);
//                    int progress5 = std::min(progress4, pow2);
//                    // Display progress value in label_49
//                    ui->label_92->setNum(progress5);
//                    updatesensor();
//                }

//                    else{
//                        ui->label_92->setText("0");
//                        ui->us2onoff->setStyleSheet(styleSheet2);
//                        ui->us2onoff->setText("OFF");
//                    }

//                }
//        }
//        }
//        break;
//}
//    // us3
//    case 3:
//    {
//        int pow3=ui->lineEdit_61->text().toInt();
//        int vac3=ui->lineEdit_63->text().toInt();  //not changed
//        int flow3=ui->lineEdit_62->text().toInt();
//  bool flag3=true;
//        if(flag3){
//            if(us3 == "PANEL" && vus3 == "PANEL"){//surgeon
//            if(range>=0 && range<1024){
//                ui->pushButton_42->setText("0");
//                 ui->CI3->setStyleSheet(styleSheet4);
//                int progress8 =range* 100 /4096;
//                 progress8 = std::min(progress8, pow3);
//                ui->label_98->setText(QString::number(progress8) );
//               ;
//               // label43();
//            }
//            if(range>=1024 && range<2048){
//                ui->pushButton_42->setText("1");
//                 ui->CI3->setStyleSheet(styleSheet3);
//                int progress8 =range* 100 /4096;
//                 progress8 = std::min(progress8, pow3);
//                ui->label_98->setText(QString::number(progress8) );
//               ;
//            }
//            else if(range>=2048 && range <3072){
//                ui->pushButton_42->setText("2");
//                int progress8 =range* 100 /4096;
//                 progress8 = std::min(progress8, pow3);
//                ui->label_98->setText(QString::number(progress8) );
//                 sensor2();
//            }
//            if (range >= 3072 && range < 4096)
//               {
//               ui->pushButton_42->setText("3");
//               int progress8 =range* 100 /4096;
//                progress8 = std::min(progress8, pow3);
//               ui->label_98->setText(QString::number(progress8) );
//               sensor2();// U
//               if(progress8>=pow3){
//               ui->us3onoff->setText("ON");
//               ui->us3onoff->setStyleSheet(styleSheet1);
//                  int ET3 = progress8 * pow3/10000;//effective time for us3
//                  EPT+=ET3;
//               }
//    }
//    else {
//                      ui->label_98->setText("0");
//                      ui->us3onoff->setText("OFF");
//                      ui->us3onoff->setStyleSheet(styleSheet2);
//                  }
//            }

//            else{
//                    if(us3 == "SURGEON" && vus3 == "SURGEON") {
//                        if(range>=0 && range <1024){
//                            ui->pushButton_42->setText("0");
//                             ui->CI3->setStyleSheet(styleSheet4);
//                        }
//                        else if(range>=1024 && range<2048){
//                            ui->pushButton_42->setText("1");
//                             ui->CI3->setStyleSheet(styleSheet3);
//                        }
//                        else if(range >=2048 && range<3072){
//                            ui->pushButton_42->setText("2");
//                        }
//                    if(range >=3072 && range < 4096) {
//                        ui->pushButton_42->setText("3");
//                        int progress8 =range* 100 /4096;
//                        ui->us3onoff->setText("ON");
//                        ui->us3onoff->setStyleSheet(styleSheet1);
//                         int progress9 = std::min(progress8, pow3);
//                        ui->label_98->setNum(progress9);
//                        updatesensor();
//                    }
//                    else {
//                        ui->label_98->setText("0");
//                        ui->us3onoff->setText("OFF");
//                        ui->us3onoff->setStyleSheet(styleSheet2);
//                    }
//                    }
//            }
//        }
//            break;
//    }
//        // us4
//        case 4:
//        {
//        int pow4=ui->lineEdit_64->text().toInt();
//        int vac4=ui->lineEdit_66->text().toInt();
//        int flow4=ui->lineEdit_65->text().toInt();
//  bool flag4=true;
//        if(flag4){
//            if(us4 == "PANEL" && vus4 == "PANEL"){//surgeon
//            if(range>=0 && range<1024){
//                ui->pushButton_42->setText("0");
//                 ui->CI4->setStyleSheet(styleSheet4);
//                int progress11 = range*100/4096;
//                progress11=std::min(progress11,pow4);
//            ui->label_105->setText(QString::number(progress11) ); // U

//               // label43();
//            }
//            if(range>=1024 && range<2048){
//                ui->pushButton_42->setText("1");
//                 ui->CI4->setStyleSheet(styleSheet3);
//                int progress11 = range*100/4096;
//                progress11=std::min(progress11,pow4);
//            ui->label_105->setText(QString::number(progress11) ); // U

//            }
//            else if(range>=2048 && range <3072){
//                ui->pushButton_42->setText("2");
//                int progress11 =range*100/4096;
//                progress11=std::min(progress11,pow4);
//            ui->label_105->setText(QString::number(progress11) ); // U
//             sensor2();
//            }                                                      //not changed
//            if (range >= 3072 && range < 4096)
//               {
//                   ui->pushButton_42->setText("3");
//                   int progress11 =range*100/4096;
//                   progress11=std::min(progress11,pow4);
//               ui->label_105->setText(QString::number(progress11) ); // U
//             sensor2();
//             if(progress11>=pow4){
//             ui->us4onoff->setText("ON");
//             ui->us4onoff->setStyleSheet(styleSheet1);
//                int ET4 = progress11 * pow4/10000;//effective time for us4
//                EPT+=ET4;
//             }
//  }
//  else {
//                    ui->label_105->setText("0");
//                    ui->us4onoff->setText("OFF");
//                    ui->us4onoff->setStyleSheet(styleSheet2);
//                }
//            }

//            else{
//                    if(us4 == "SURGEON" && vus4 =="SURGEON") {
//                        if(range>=0 && range <1024){
//                            ui->pushButton_42->setText("0");
//                             ui->CI4->setStyleSheet(styleSheet4);
//                        }
//                        else if(range>=1024 && range<2048){
//                            ui->pushButton_42->setText("1");
//                             ui->CI4->setStyleSheet(styleSheet3);
//                        }
//                        else if(range >=2048 && range<3072){
//                            ui->pushButton_42->setText("2");
//                        }
//                    if(range >=3072 && range < 4096) {
//                        ui->pushButton_42->setText("3");
//                        int progress11 =range*100/4096;
//                        ui->us4onoff->setText("ON");
//                        ui->us4onoff->setStyleSheet(styleSheet1);
//                       int progress12=std::min(progress11,pow4);
//                    ui->label_105->setNum(progress12); // U
//                    updatesensor();
//                    }
//                    else {
//                        ui->label_105->setText("0");
//                        ui->us4onoff->setText("OFF");
//                        ui->us4onoff->setStyleSheet(styleSheet2);
//                    }
//                    }
//            }
//        }break;
//        }
//        // ia1
//        case 5:
//        {

//        //int val=v->convert(0xD7);
//       // int value6=ui->lineEdit_71->text().toInt();
//  bool flag5=true;
//        if(flag5){
//             if(ia1==" PANEL"){//surgeon
//            if(range>=0 && range<1024){
//                ui->pushButton_42->setText("0");


//            }
//            if(range>=1024 && range<2048){
//                ui->pushButton_42->setText("1");


//            }
//            else if(range>=2048 && range <4096){
//                qDebug()<<"fs"<<range;
//                  ui->pushButton_42->setText("2");
//              sensor2();

//        }}
//             else{
//                 if(ia1 == "SURGEON"){
//                 if(range>=0 && range<1024){
//                     ui->pushButton_42->setText("0");
//                 }
//                 if(range>=1024 && range<2048){
//                     ui->pushButton_42->setText("1");}
//                 else if(range>=2048 && range <4096){
//                     qDebug()<<"fs"<<range;
//                       ui->pushButton_42->setText("2");
//                   updatesensor();
//             }
//                 }

//}
//    }
//         break;
//    }
//        // ia2
//        case 6:
//        {

//        //int value6=ui->lineEdit_71->text().toInt();
//  bool flag6=true;

//        if(flag6){
//            if(ia2 == "PANEL"){//surgeon
//            if(range>=0 && range<1024){
//                ui->pushButton_42->setText("0");

//            }
//            if(range>=1024 && range<2048){
//                ui->pushButton_42->setText("1");

//            }
//            else if(range>=2048 && range <4096){
//                ui->pushButton_42->setText("2");
//                sensor2();       }
//            }
//            else{
//                if(ia2 == "SURGEON"){
//                if(range>=0 && range<1024){
//                    ui->pushButton_42->setText("0");
//                   // label43();
//                }
//                if(range>=1024 && range<2048){
//                    ui->pushButton_42->setText("1");
//                }
//                else if(range>=2048 && range <4096){
//                    ui->pushButton_42->setText("2");
//                    updatesensor();      }
//                }
//       }
//       } break;
//        }
//        // vit
//        case 7:
//        {
//        int pow7=ui->lineEdit_63->text().toInt();

//  bool flag7=true;
//        if(flag7){
//            if(vit== "PANEL" && vvit == "PANEL"){
//            if(range>=0 && range<1024){
//                ui->pushButton_42->setText("0");
//                 ui->CI5->setStyleSheet(styleSheet4);
//                int progress18 = range*960/4096;
//                progress18=std::min(progress18,pow7);
//            ui->label_121->setText(QString::number(progress18) );

//            }
//            if(range>=1024 && range<2048){
//                ui->pushButton_42->setText("1");
//                 ui->CI5->setStyleSheet(styleSheet3);
//                int progress18 = range*960/4096;
//                progress18=std::min(progress18,pow7);
//            ui->label_121->setText(QString::number(progress18) );

//            }
//            else if(range>=2048 && range <3072){
//                ui->pushButton_42->setText("2");
//                int progress18 = range*960/4096;
//                progress18=std::min(progress18,pow7);
//            ui->label_121->setText(QString::number(progress18) );
//             sensor2();
//            }
//            if (range >= 3072 && range < 4096)
//               {
//                  ui->pushButton_42->setText("3");
//                   int progress18 = range*960/4096;
//                   progress18=std::min(progress18,pow7);
//               ui->label_121->setText(QString::number(progress18) );
//               sensor2();
//               if(progress18>=pow7){
//               ui->vitonoff->setText("ON");
//               ui->vitonoff->setStyleSheet(styleSheet1);
//               }
//    }
//    else {
//                      ui->label_121->setText("0");
//                      ui->vitonoff->setText("OFF");
//                      ui->vitonoff->setStyleSheet(styleSheet2);
//                  }
//             }

//            else{
//                    if(vit == "SURGEON" && vvit == "SURGEON") {
//                        if(range>=0 && range <1024){
//                            ui->pushButton_42->setText("0");
//                             ui->CI5->setStyleSheet(styleSheet4);
//                        }
//                        else if(range>=1024 && range<2048){
//                            ui->pushButton_42->setText("1");
//                             ui->CI5->setStyleSheet(styleSheet3);
//                        }
//                        else if(range >=2048 && range<3072){
//                            ui->pushButton_42->setText("2");
//                        }
//                    if(range >=3072 && range < 4096) {
//                        ui->pushButton_42->setText("3");
//                        int progress18 = range*960/4096;
//                        ui->vitonoff->setText("ON");
//                        ui->vitonoff->setStyleSheet(styleSheet1);
//                        int progress19=std::min(progress18,pow7);
//                    ui->label_121->setNum(progress19) ;
//                    updatesensor();
//                    }
//                    else {
//                        ui->label_121->setText("0");
//                        ui->vitonoff->setText("OFF");
//                        ui->vitonoff->setStyleSheet(styleSheet2);
//                    }
//                    }


//        }
//        }
//        break;
//        }
//    }
//   ui->elapsed_time->setText("EPT:"+QString::number(EPT)+"ms");//update effective time

//}
void MainWindow::on_DIABUT_clicked()
{
//    hard->dia_on();
//    hard->dia_count(ui->lineEdit_74->text().toInt()*256/100);
    qDebug()<<"dia";
}
void MainWindow::us1_linear_nonlinear()
{

     us1=ui->us1mode->text();
    vus1 = ui->us1vacmode->text();
       if(us1 == "SURGEON" && vus1== "SURGEON")
       {
           ui->us1mode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
            ui->us1mode->setText("PANEL");
            ui->us1vacmode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
            ui->us1vacmode->setText("PANEL");
          //   footpedal();
       }
       else if(us1 == "PANEL" && vus1=="PANEL")
       {
           ui->us1mode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
           ui->us1mode->setText("SURGEON");
           ui->us1vacmode->setStyleSheet("color:black;border-radius:20px;font:bold;background-color:white");
           ui->us1vacmode->setText("SURGEON");
         //  int pow2=ui->lineEdit_58->text().toInt();
          // footpedal();

}
}

void MainWindow::us2_linear_nonlinear()
{
    us2 = ui->us2mode->text();
    vus2=ui->us2vacmode->text();

       if(us2 == "SURGEON" && vus2 == "SURGEON")
       {
            ui->us2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
             ui->us2mode->setText("PANEL");
         ui->us2vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
             ui->us2vacmode->setText("PANEL");

          //    footpedal();
               }
       else if(us2 == "PANEL" && vus2 == "PANEL")
       {
            ui->us2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           ui->us2mode->setText("SURGEON");
           ui->us2vacmode->setText("SURGEON");
            ui->us2vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
          //  footpedal();
       }
}
void MainWindow::us3_linear_nonlinear()
{
    us3 = ui->us3mode->text();
    vus3=ui->us3vacmode->text();

       if(us3 == "SURGEON" && vus3 =="SURGEON")
       {
            ui->us3mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
             ui->us3mode->setText("PANEL");
             ui->us3vacmode->setText("PANEL");
              ui->us3vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
              // footpedal();
       }
       else if(us3 == "PANEL" && vus3 == "PANEL")
       {
             ui->us3mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           ui->us3mode->setText("SURGEON");
           ui->us3vacmode->setText("SURGEON");
           ui->us3vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           // footpedal();
       }
}
void MainWindow::us4_linear_nonlinear()
{
    us4 = ui->us4mode->text();
    vus4=ui->us4vacmode->text();

       if(us4 == "SURGEON")
       {

            ui->us4mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
             ui->us4mode->setText("PANEL");
             ui->us4vacmode->setText("PANEL");
              ui->us4vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
              // footpedal();
                }
       else if(us4 == "PANEL")
       {
           ui->us4mode->setText("SURGEON");
              ui->us4mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
              ui->us4vacmode->setText("SURGEON");
               ui->us4vacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
              //  footpedal();
       }
}

void MainWindow::ia1_linear_nonlinear()
{
    ia1= ui->ia1mode->text();

       if(ia1== "SURGEON")
       {

            ui->ia1mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
             ui->ia1mode->setText("PANEL");
             // footpedal();
               }
       else if(ia1 == "PANEL")
       {
            ui->ia1mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           ui->ia1mode->setText("SURGEON");
          //  footpedal();
               }
}
void MainWindow::ia2_linear_nonlinear()
{
    ia2 = ui->ia2mode->text();

       if(ia2 == "SURGEON")
       {
           ui->ia2mode->setText("PANEL");
            ui->ia2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           //  footpedal();
                }
       else if(ia2 == "PANEL")
       {
           ui->ia2mode->setText("SURGEON");
            ui->ia2mode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
 //footpedal();
       }
}
void MainWindow::vit_linear_nonlinear()
{
    vit = ui->vitmode->text();
    vvit=ui->vitvacmode->text();

       if(vit == "SURGEON" && vvit =="SURGEON")
       {

           ui->vitmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
            ui->vitmode->setText("PANEL");
            ui->vitvacmode->setText("PANEL");
            ui->vitvacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
        //    footpedal();
               }
       else if(vit == "PANEL" && vvit == "PANEL")
       {
              ui->vitmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           ui->vitmode->setText("SURGEON");
           ui->vitvacmode->setText("SURGEON");
           ui->vitvacmode->setStyleSheet("border-radius:20px;font:bold;background-color:white");
           //footpedal();
              }
}


void MainWindow::on_off_vit()
{
     QString lnl2 = ui->vitonoff->text();
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

    if(lnl2 == "OFF")
    {
        ui->vitonoff->setText("ON");
        ui->vitonoff->setStyleSheet(styleSheet1);

        //flag2=1;
    }

    else{ if(lnl2 == "ON")
    {
        ui->vitonoff->setText("OFF");
        ui->vitonoff->setStyleSheet(styleSheet2);

    }

}
}
//on off mode for us1
//void MainWindow::on_off_us1()
//{

//    QString lnl3 = ui->us1onoff->text();
//   // us1powon=!us1powon;
//    QString styleSheet1 = "QPushButton {"
//           " font:20pt Ubuntu;"
//          " background-color: green;"
//            "color: black;"

//           " border:5px solid black;"
//           " border-radius:30px;font-weight: bold;"
//                                 "}";

//    QString styleSheet2 = "QPushButton {"
//           " font:20pt Ubuntu;"
//          " background-color: rgb(224, 27, 36);"
//            "color: black;"
//            //"image: url(:/ci.png);"
//           " border:5px solid black;"
//           " border-radius:30px;font-weight: bold;"
//                                 "}";
//if(us1powon){
//   if(lnl3 == "OFF"  )
//   {

//       ui->us1onoff->setText("ON");
//       ui->us1onoff->setStyleSheet(styleSheet1);
//       footpedal();



//   }}
//  else{
//    if(lnl3 == "ON")
//   {
//       ui->us1onoff->setText("OFF");
//       ui->us1onoff->setStyleSheet(styleSheet2);

//   }}
//  }

void MainWindow::on_off_us2()
{
    QString lnl4 = ui->us2onoff->text();
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

   if(lnl4 == "OFF")
   {
       ui->us2onoff->setText("ON");
       ui->us2onoff->setStyleSheet(styleSheet1);
       //footpedal();

       //flag2=1;
   }
 else{
   if(lnl4 == "ON")
   {
       ui->us2onoff->setText("OFF");
       ui->us2onoff->setStyleSheet(styleSheet2);

       //flag2=0;
   }
 }
}

void MainWindow::on_off_us4()
{
    QString lnl5 = ui->us4onoff->text();
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

   if(lnl5 == "OFF")
   {
       ui->us4onoff->setText("ON");
       ui->us4onoff->setStyleSheet(styleSheet1);
       //footpedal();

       //flag2=1;
   }
  else{
   if(lnl5 == "ON")
   {
       ui->us4onoff->setText("OFF");
       ui->us4onoff->setStyleSheet(styleSheet2);

       //flag2=0;

   }
}
}
void MainWindow::on_off_us3()
{
    QString lnl6 = ui->us3onoff->text();
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

   if(lnl6 == "OFF")
   {
       ui->us3onoff->setText("ON");
       ui->us3onoff->setStyleSheet(styleSheet1);
        //ui->pushButton_31->setStyleSheet("image: url(:/ci.png);background-color:green;");

       //flag2=1;

   }

   else
  {if(lnl6 == "ON")
   {
       ui->us3onoff->setText("OFF");
        ui->us3onoff->setStyleSheet(styleSheet2);
   //    ui->pushButton_39->setStyleSheet("font:bold;background-color:red;border-radius:30px");
      // ui->pushButton_31->setStyleSheet("image: url(:/ci.png);background-color:red;");

       //flag2=0;
   }
  }
}
//handpiece connected or not
void MainWindow::HANDPIECE()
{
    flag1=!flag1;
    QString lnl6 = ui->handpiece->text();
    QString styleSheet4 = "QPushButton {"
"image: url(:/images/handpiece1.png);"
           "background-color:green;"
            "border:4px solid black;"
            "border-radius:20px;"
                                 "}";
    QString styleSheet5 = "QPushButton {"
            "image: url(:/images/handpiece1.png);"
           "background-color: rgb(192, 28, 40);"
            "border:4px solid black;"
            "border-radius:20px;"
                                 "}";
   if(flag1)
   {
       ui->handpiece->setStyleSheet(styleSheet4);
   }
   else
   {
       ui->handpiece->setStyleSheet(styleSheet5);
     //flag1=false;
   }
}

void MainWindow::updatesensor()
{
    //footpedal();
   // label43();
}
//void MainWindow::updateProgressBar() {
//    { if (currentProgressBar == 1) {
//            int value = ui->progressBar->value();
//            if (value < 100) {
//                ui->progressBar->setValue(value + 1);
//            } else {
//                currentProgressBar = 2; // Move to the second progress bar
//            }
//        } else if (currentProgressBar == 2) {
//            int value = ui->progressBar_2->value();
//            if (value < 100) {
//                ui->progressBar_2->setValue(value + 1);
//            } else {
//                currentProgressBar = 3; // Move to the third progress bar
//            }
//        } else if (currentProgressBar == 3) {
//            int value = ui->progressBar_3->value();
//            if (value < 100) {
//                ui->progressBar_3->setValue(value + 1);
//            } else {
//                timer->stop(); // Stop the timer when the third progress bar is full
//            }
//        }
    //    }
//}

//void MainWindow::motoron()
//{
//  if(on){
//      m->motor_on();
//      on=false;
//  }
//  else{
//          m->motor_off();
//          on=true;
//  }
//}

//void MainWindow::motordirection(bool forward)
//{

//    if (forward) {
//        m->motor_cw();
//    } else {
//        m->motor_ccw();
//    }
//}
//int MainWindow::getPWMDutyCycle(int flowrate)
//{
    // Dummy implementation for the example
    // Replace with your actual logic to get the PWM duty cycle based on the flowrate
    //return Flow_LUT[flowrate];
//}

//void MainWindow::motorpwm(QLineEdit *lineEdit, int index)
//{
//    int enteredValue = lineEdit->text().toInt();
//        int pwmDutyCycle = getPWMDutyCycle(enteredValue);

//        // Calculate corresponding flow rate
//        int flowRate = 1;
//        for (int i = 0; i <= 40; i++) {
//            if (Flow_LUT[i] == pwmDutyCycle) {
//                flowRate = i;
//                break;
//            }
//        }

//        if (previousValue[index] == -1) {
//            previousValue[index] = enteredValue;
//        } else {
//            if (enteredValue > previousValue[index]) {
//                motordirection(true); // Set motor direction to forward
//            } else if (enteredValue < previousValue[index]) {
//                motordirection(false); // Set motor direction to reverse
//            }
//            // Update the previous value
//            previousValue[index] = enteredValue;
//        }

//        m->motor_value(flowRate);
//    }



//NON LINEAR

//void MainWindow::label43()
//{
//    int sensor = v->convert(0xD7);
//     int vac1=ui->lineEdit_55->text().toInt();
//      int vac2=ui->lineEdit_60->text().toInt();
//       int vac3=ui->lineEdit_63->text().toInt();
//        int vac4=ui->lineEdit_66->text().toInt();
//         int vac5=ui->lineEdit_70->text().toInt();
//          int vac6=ui->lineEdit_68->text().toInt();
//           int vac7=ui->lineEdit_73->text().toInt();
//    if (sensor > 0 && sensor < 4096) {
//      //  int pro = sensor * vac5 / 4096+50;
//        int pro=sensor*580/4096;
//        int pro1=std::min(vac5,pro);
//        ui->label_113->setNum(pro1);
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro1 = sensor * 580 / 4096;
//       int pro2=std::min(vac6,pro1);
//        ui->label_109->setNum(pro2);
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro3 = sensor * 580 / 4096;
//       int pro4=std::min(vac7,pro3);
//        ui->label_118->setNum(pro4);
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro4 = sensor * 580 / 4096;
//       int pro5=std::min(vac4,pro4);
//        ui->label_104->setNum(pro5);
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro5 = sensor * 580 / 4096;
//        int pro6=std::min(vac3,pro5);
//        ui->label_99->setNum(pro6);
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro6 = sensor * 580 / 4096;
//       int pro7=std::min(vac2,pro6);
//        ui->label_93->setNum(pro7);
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro7 = sensor * 580 / 4096;
//        int pro8=std::min(vac1,pro7);
//        ui->label_8->setNum(pro8);
//    }


//}

//void MainWindow::sensor2()
//{

//    int sensor = v->convert(0xD7);
//     int vac1=ui->lineEdit_55->text().toInt();
//      int vac2=ui->lineEdit_60->text().toInt();
//       int vac3=ui->lineEdit_63->text().toInt();
//        int vac4=ui->lineEdit_66->text().toInt();
//         int vac5=ui->lineEdit_70->text().toInt();
//          int vac6=ui->lineEdit_68->text().toInt();
//           int vac7=ui->lineEdit_73->text().toInt();
//    if (sensor > 0 && sensor < 4096) {
//      //  int pro = sensor * vac5 / 4096+50;
//        int pro=sensor*580/4096;
//        pro=std::min(vac5,pro);
//        ui->label_113->setText(QString::number(pro));
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro1 = sensor * 580 / 4096;
//        pro1=std::min(vac6,pro1);
//        ui->label_109->setText(QString::number(pro1));
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro3 = sensor * 580 / 4096;
//        pro3=std::min(vac7,pro3);
//        ui->label_118->setText(QString::number(pro3));
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro4 = sensor * 580 / 4096;
//        pro4=std::min(vac4,pro4);
//        ui->label_104->setText(QString::number(pro4));
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro5 = sensor * 580 / 4096;
//        pro5=std::min(vac3,pro5);
//        ui->label_99->setText(QString::number(pro5));
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro6 = sensor * 580 / 4096;
//        pro6=std::min(vac2,pro6);
//        ui->label_93->setText(QString::number(pro6));
//    }
//    if (sensor > 0 && sensor < 4096) {
//        int pro7 = sensor * 580 / 4096;
//        pro7=std::min(vac1,pro7);
//        ui->label_8->setText(QString::number(pro7));
//    }



//    }



//continuous irrigation us1
void MainWindow::continous_irrigation1()
{
    cs=!cs;

    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"
           // "color: rgb(224, 27, 36);"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(cs){
        ui->CI1->setStyleSheet(styleSheet3);
    }
    else {
         ui->CI1->setStyleSheet(styleSheet4);
    }

        }

void MainWindow::continous_irrigation2()
{
    cs1=!cs1;
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"
           // "color: rgb(224, 27, 36);"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(cs1){
      ui->CI2->setStyleSheet(styleSheet3);
    }
    else{
        ui->CI2->setStyleSheet(styleSheet4);
    }
}

void MainWindow::continous_irrigation3()
{
    cs2=!cs2;
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"
           // "color: rgb(224, 27, 36);"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(cs2){
      ui->CI3->setStyleSheet(styleSheet3);
    }else{
       ui->CI3->setStyleSheet(styleSheet4);}
}

void MainWindow::continous_irrigation4()
{
    cs3=!cs3;
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"
           // "color: rgb(224, 27, 36);"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(cs3){
     ui->CI4->setStyleSheet(styleSheet3);
    }else{
      ui->CI4->setStyleSheet(styleSheet4);}
}
void MainWindow::continous_irrigation5()
{
    cs4=!cs4;
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"
           // "color: rgb(224, 27, 36);"
            "image: url(:/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    if(cs4){
     ui->CI5->setStyleSheet(styleSheet3);
    }else{
       ui->CI5->setStyleSheet(styleSheet4);}
}




//void MainWindow::on_lineEdit_24_returnPressed()
//{
//     motorpwm(ui->lineEdit_56, 0);
//}

//void MainWindow::on_lineEdit_12_returnPressed()
//{
//    motorpwm(ui->lineEdit_59,1);
//}

//void MainWindow::on_lineEdit_20_returnPressed()
//{
//    motorpwm(ui->lineEdit_62,2);
//}

//void MainWindow::on_lineEdit_15_returnPressed()
//{
//    motorpwm(ui->lineEdit_65,3);
//}

//void MainWindow::on_lineEdit_21_returnPressed()
//{
//    motorpwm(ui->lineEdit_69,4);
//}

//void MainWindow::on_lineEdit_10_returnPressed()
//{
//    motorpwm(ui->lineEdit_67,5);
//}

//void MainWindow::on_lineEdit_9_returnPressed()
//{
//    motorpwm(ui->lineEdit_72,6);
//}
//pulse
void MainWindow::on_pushButton_5_clicked()
{
    value1=ui->lineEdit_75->text().toInt();
   value1=value1+1;
   // userMessage(value,5,100);
   if(value1 > 15)
   {
       value1=15;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_75->setText(QString::number(value1));

}

void MainWindow::on_pushButton_6_clicked()
{
    value1=ui->lineEdit_75->text().toInt();
   value1=value1-1;
   // userMessage(value,5,100);
   if(value1<1)
   {
       value1=1;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_75->setText(QString::number(value1));


}
//ocupulse

void MainWindow::on_pushButton_44_clicked()
{//down
    ocupulse=ui->lineEdit_76->text().toInt();
     ocupulse=ocupulse-1;
     // userMessage(value,5,100);
     if(ocupulse < 1)
     {
         ocupulse=1;
     }
   //  ui->progressBar_12->setValue(value);
     ui->lineEdit_76->setText(QString::number(ocupulse));
}

void MainWindow::on_pushButton_45_clicked()
{
    ocupulse=ui->lineEdit_76->text().toInt();
     ocupulse=ocupulse+1;
     // userMessage(value,5,100);
     if(ocupulse > 15)
     {
         ocupulse=15;
     }
   //  ui->progressBar_12->setValue(value);
     ui->lineEdit_76->setText(QString::number(ocupulse));
}
//ocuburst
void MainWindow::on_pushButton_46_clicked()
{
    ocuburst=ui->lineEdit_79->text().toInt();
    ocuburst=ocuburst+10;
    // userMessage(value,5,100);
    if(ocuburst > 170)
    {
        ocuburst=170;
    }
  //  ui->progressBar_12->setValue(value);
    ui->lineEdit_79->setText(QString::number(ocuburst));

}

void MainWindow::on_pushButton_47_clicked()
{
    ocuburst=ui->lineEdit_79->text().toInt();
    ocuburst=ocuburst-10;
    // userMessage(value,5,100);
    if(ocuburst<10)
    {
        ocuburst=10;
    }
  //  ui->progressBar_12->setValue(value);
    ui->lineEdit_79->setText(QString::number(ocuburst));
}
//single burst
void MainWindow::on_pushButton_49_clicked()
{
    singleburst=ui->lineEdit_77->text().toInt();
   singleburst=singleburst+10;
   // userMessage(value,5,100);
   if(singleburst > 400)
   {
       singleburst=400;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_77->setText(QString::number(singleburst));

}

void MainWindow::on_pushButton_48_clicked()
{
    singleburst=ui->lineEdit_77->text().toInt();
     singleburst=singleburst-10;
     // userMessage(value,5,100);
     if(singleburst < 10)
     {
         singleburst=10;
     }
   //  ui->progressBar_12->setValue(value);
     ui->lineEdit_77->setText(QString::number(singleburst));
}
//multiburst

void MainWindow::on_pushButton_50_clicked()
{
    multiburst=ui->lineEdit_78->text().toInt();
    multiburst=multiburst+10;
    // userMessage(value,5,100);
    if(multiburst > 400)
    {
        multiburst=400;
    }
  //  ui->progressBar_12->setValue(value);
    ui->lineEdit_78->setText(QString::number(multiburst));
}

void MainWindow::on_pushButton_51_clicked()
{
    multiburst=ui->lineEdit_78->text().toInt();
   multiburst=multiburst-10;
   // userMessage(value,5,100);
   if(multiburst < 10)
   {
       multiburst=10;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_78->setText(QString::number(multiburst));

}
//coldphaco
void MainWindow::on_pushButton_52_clicked()
{
    coldphaco=ui->lineEdit_80->text().toInt();
      coldphaco=coldphaco+1;
      // userMessage(value,5,100);
      if(coldphaco > 15)
      {
          coldphaco=15;
      }
    //  ui->progressBar_12->setValue(value);
      ui->lineEdit_80->setText(QString::number(coldphaco));
}

void MainWindow::on_pushButton_53_clicked()
{
    coldphaco=ui->lineEdit_81->text().toInt();
   coldphaco=coldphaco-1;
   // userMessage(value,5,100);
   if(coldphaco <1)
   {
       coldphaco=1;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_81->setText(QString::number(coldphaco));

}

void MainWindow::on_pushButton_54_clicked()
{
    coldphaco=ui->lineEdit_81->text().toInt();
   coldphaco=coldphaco+5;
   // userMessage(value,5,100);
   if(coldphaco > 40)
   {
       coldphaco=40;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_81->setText(QString::number(coldphaco));
}

void MainWindow::on_pushButton_55_clicked()
{
    coldphaco=ui->lineEdit_81->text().toInt();
   coldphaco=coldphaco-5;
   // (value,5,100);
   if(coldphaco <5)
   {
       coldphaco=5;
   }
 //  ui->progressBar_12->setValue(value);
   ui->lineEdit_81->setText(QString::number(coldphaco));

}
