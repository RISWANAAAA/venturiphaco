#include "prime.h"
#include "ui_prime.h"
#include <QMessageBox>
#include<QTimer>
#include<QFile>
#include<QImage>
#include<QDebug>
#include<QIODevice>

prime::prime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prime)
{
    ui->setupUi(this);
    move(0,0);
    m=new MainWindow;
    sur=new doctor;
    set=new settings;
    hand=new hwhandler;
    tune=new tuning;
    ui->progressBar_2->setRange(0,100);
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    background-color: transparent;"
                         "    image: url(:/images/g3645.png);"
                         "    color: black;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";


    QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; border-radius:50px}";
    QString styleSheet3 =
                "QTabBar::tab {"
                "    font-size: 16px; /* Set the font size */"
                "    border-radius: 10px; /* Set the border radius */"
                "}";


     ui-> tabWidget->setStyleSheet(tabStyle);
    ui->tabWidget->setTabText(0 ,"     PRIME        ");
    ui->tabWidget->setTabText(1 ,"     TUNE         ");
    ui->tabWidget->setTabText(2 ,"     CLEAN        ");



    statusUpdateTimer = new QTimer(this);
    //connect(statusUpdateTimer, &QTimer::timeout, this, &prime::onUpdateStatusTimeout);
    statusUpdateTimer->start(500); // Update every second


   connect(ui->prime1_but,&QPushButton::clicked,this,&prime::Prime);

   connect(ui->Tune_but,&QPushButton::clicked,this,&prime::Tune);
  connect(ui->Start_tune_2,&QPushButton::clicked,this,&prime::Start_Tune);
   connect(ui->clean_but,&QPushButton::clicked,this,&prime::Clean);

   connect(ui->prime1_but, &QPushButton::clicked, [=](){
       ui->prime1_but->setStyleSheet(styleSheet);

   });
   connect(ui->Tune_but, &QPushButton::clicked, [=](){
       ui->Tune_but->setStyleSheet(styleSheet);

   });
  connect(ui->clean_but, &QPushButton::clicked, [=](){
      ui->clean_but->setStyleSheet(styleSheet);

  });
  //timerssss
    timer1=new QTimer;
     pretimer=new QTimer;
    connect(timer1, &QTimer::timeout, this, &prime::timer);
    connect(pretimer,&QTimer::timeout,this,&prime::primetimer);

      ui->progressBar_2->setRange(0, 100);
     current(ui->tabWidget->currentIndex());
     Tune();
     ui->tabWidget->insertTab(1,tune,"TUNE");


}

prime::~prime()
{
    delete ui;
}
void prime::click()
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/g3042.png);"
                         "    background-color: transparent;"
                         "    color: white;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";


   ui->prime1_but->setStyleSheet(styleSheet);
   ui->Tune_but->setStyleSheet(styleSheet);
   ui->clean_but->setStyleSheet(styleSheet);


}
void prime::current(int tab)
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/g3645.png);"
                         "    background-color: transparent;"
                         "    color: black;"
                         //"    border-radius: 20px;" // Uncomment if needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";

    QString styleSheet1 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 20pt;"
                          "    image: url(:/images/g3042.png);"
                          "    background-color: transparent;"
                          "    color: white;"
                          //"    border-radius: 20px;" // Uncomment if needed
                          "    font-weight: bold;"  // Corrected from 'font: bold;'
                          "}"
                          "QPushButton:focus {"
                          "    outline: none;"
                          "    border: none;"
                          "}";

    // Reset all buttons to the default style
    ui->prime1_but->setStyleSheet(styleSheet1);
    ui->Tune_but->setStyleSheet(styleSheet1);
    ui->clean_but->setStyleSheet(styleSheet1);

    // Set the style for the current tab
    if (tab == 0) {
        ui->prime1_but->setStyleSheet(styleSheet);
    } else if (tab == 1) {
        ui->Tune_but->setStyleSheet(styleSheet);
    } else if (tab == 2) {
        ui->clean_but->setStyleSheet(styleSheet);
    }
}



void prime::start_irrigation()
{
    hand->pinchvalve_on();
    hand->safetyvent_on();
    qDebug() << "Irrigation started";
    ui->start_check_2->setChecked(true);
     pretimer->start(290);
    QTimer::singleShot(15000, this, &prime::champer_Filled);
}
void prime::motoron()
{

    hand->write_motor(0x01,0x03,40);
    ui->motor_Check_2->setChecked(true);
    pretimer->start(290);
    QTimer::singleShot(15000, this, &prime::start_irrigation);
}

void prime::motoroff()
{
    hand->write_motor(0x00,0x00,0);
}
void prime::champer_Filled()
{
    ui->wait_Check_2->setChecked(true);
    pretimer->start(290);
    QTimer::singleShot(15000, this, &prime::done);
}

void prime::done()
{
    ui->done_Check_2->setChecked(true);
    pretimer->start(290);
    hand->safetyvent_off();
    hand->pinchvalve_off();
    motoroff();
    on_pushButton_5_clicked();

}
void prime::onUpdateStatusTimeout(){
}
void prime::timer(){
    int value = ui->progressBar->value();
       if (value < 100) {
           ui->progressBar->setValue(value + 1);
      }
       else {
            timer1->stop();

        }
}
void prime::primetimer()
{
    int value = ui->progressBar_2->value();
       if (value < 100) {
           ui->progressBar_2->setValue(value + 1);
    }
       else {
            pretimer->stop();
             }
}
void prime::Prime()
{

    ui->tabWidget->setCurrentIndex(0);
    ui->prime1_but->raise();
  click();
   timer1->stop();
}

void prime::Tune()
{

    ui->tabWidget->setCurrentIndex(1);
    ui->Tune_but->raise();

    click();
}
void prime::Clean()
{

    ui->tabWidget->setCurrentIndex(2);
 ui->clean_but->raise();
    click();
   timer1->stop();
}


void prime::Start_Tune()
{


}
void prime::on_start_prime_but_2_clicked()
{
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);
 ui->progressBar->setValue(0);

 motoron();
 start_irrigation();

}

void prime::on_begin_clean_but_2_clicked()
{
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);
    ui->progressBar->setValue(0);
    motoron();
    hand->pinchvalve_on();
    pretimer->stop();

}

void prime::on_pushButton_5_clicked()
{
    QString styleSheet = "QPushButton {"
                                 "    font-family: Ubuntu;"
                                 "    font-size: 20pt;"
                                 "    background-color: transparent;"
                                 "color:black;"
     "  image: url(:/images/g3645.png);"
                                 "    border-radius: 20px;" // Adjust the radius as needed
                                 "}";


   Tune();
    ui->Tune_but->setStyleSheet(styleSheet);
}

void prime::on_pushButton_6_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Info"); // Title of the message box
    msgBox.setText("Tune is not completed. Do you want to continue?");
    msgBox.setIcon(QMessageBox::Question); // Set icon to question mark
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No); // Yes and No buttons
    msgBox.setDefaultButton(QMessageBox::No); // Default button

    // Apply stylesheet to change background color to gray
    msgBox.setStyleSheet("QMessageBox { background-color: gray; color: white; }"
                         "QPushButton { background-color: #444; color: white; border: 1px solid #666;width:91;height:51 }"
                         "QPushButton:hover { background-color: #666; }");

    // Show the message box and get the user's response
    QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox.exec());

    // Check the user's response
    if (reply == QMessageBox::Yes) {
        m->show();
        m->setTuneMode(false);
        m->DIATHERMYBUT();
    }



}

void prime::on_pushButton_8_clicked()
{
    QString styleSheet = "QPushButton {"
                                 "    font-family: Ubuntu;"
                                 "    font-size: 20pt;"
                                 "    background-color: transparent;"
                                 "color:black;"
     "  image: url(:/images/g3645.png);"
                                 "    border-radius: 20px;" // Adjust the radius as needed
                                 "}";
  Prime();
    ui->prime1_but->setStyleSheet(styleSheet);

}
