#include "settings.h"
#include "ui_settings.h"
#include<QMessageBox>

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    move(0,0);
    g=new general;
    d2=new display;
    s=new doctor;
    p=new footpedal;
    connect(ui->general_but,&QPushButton::clicked,this,&settings::General);
    connect(ui->back_but,&QPushButton::clicked,this,&settings::Back);
    //connect(ui->logs_but,&QPushButton::clicked,this,&settings::Logs);
    connect(ui->display_but,&QPushButton::clicked,this,&settings::Display);
    connect(ui->surgeon_but,&QPushButton::clicked,this,&settings::Surgeon);
    connect(ui->footpedal_but,&QPushButton::clicked,this,&settings::Footpedal);
}

settings::~settings()
{
    delete ui;
}

void settings::Back()
{
    this->close();
}

//void settings::Logs()
//{
//     QMessageBox::information(nullptr,"info","No Surgery Logs detected");
//}

void settings::General()
{
    g->show();
}

void settings::Display()
{
    d2->show();
}

void settings::Surgeon()
{
    s->show();
}

void settings::Footpedal()
{
    p->show();
}
