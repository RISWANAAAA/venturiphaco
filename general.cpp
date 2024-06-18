#include "general.h"
#include "ui_general.h"
#include<QDateTime>
#include<QTimer>

general::general(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::general)
{
    ui->setupUi(this);
    move(0,0);
    QTimer *timer=new QTimer;
    ui->progressBar->setMaximum(3599.00);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(602);
    ui->lineEdit->setText("no-105-PHA92");
    ui->lineEdit_2->setText("v1.0.4");
    connect(ui->about_but,&QPushButton::clicked,this,&general::About);
    connect(ui->storagebut,&QPushButton::clicked,this,&general::Storage);


    connect(ui->clockbut,&QPushButton::clicked,this,&general::Clock);


    connect(ui->networkingbut,&QPushButton::clicked,this,&general::Network);


    connect(ui->backbut,&QPushButton::clicked,this,&general::Back);





    connect(timer,&QTimer::timeout,this,&general::Update_time_date);
    timer->start(1000);
}

general::~general()
{
    delete ui;
}

void general::About()
{
    ui->tabWidget->setCurrentIndex(0);

}

void general::Storage()
{
    ui->tabWidget->setCurrentIndex(1);

}

void general::Clock()
{
    ui->tabWidget->setCurrentIndex(2);

}

void general::Update_time_date()
{
    QDateTime currentDateTime=QDateTime::currentDateTime();
    QString dateString=currentDateTime.toString("yyyy-MM-dd");
    QString timeString=currentDateTime.toString("hh:mm:ss");
    ui->label_3->setText(dateString);
    ui->label_4->setText(timeString);
}

void general::Network()
{
    ui->tabWidget->setCurrentIndex(3);
}

void general::Back()
{
    this->close();
}

