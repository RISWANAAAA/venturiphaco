#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
    move(0,0);
    connect(ui->BackBut,&QPushButton::clicked,this,&display::BackBut);
}

display::~display()
{
    delete ui;
}

void display::BackBut()//this button is back to settings
{
    this->close();
}
