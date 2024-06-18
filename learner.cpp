#include "learner.h"
#include "ui_learner.h"

learner::learner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::learner)
{
    ui->setupUi(this);
}

learner::~learner()
{
    delete ui;
}
