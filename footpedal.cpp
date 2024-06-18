#include "footpedal.h"
#include "ui_footpedal.h"
#include<QMessageBox>

footpedal::footpedal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::footpedal)
{
    ui->setupUi(this);
    move(0,0);
    d1=new doctor;
    connect(ui->backbut,&QPushButton::clicked,this,&footpedal::Back);
    connect(ui->savebut,&QPushButton::clicked,this,&footpedal::SaveForAll);

}

footpedal::~footpedal()
{
    delete ui;
}

void footpedal::Back()
{
    this->close();
}

//void footpedal::on_pushButton_2_clicked()
//{
//    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
//       mydb.setDatabaseName(PATH);
//       if (!mydb.open()) {
//           qDebug() << "Error: Unable to open database";
//           return;
//       }

//       QSqlQuery query;
//       QString surgeonid;
//       surgeonid=d->surgeonid;

//    left=ui->comboBox->currentText();
//    right=ui->comboBox_2->currentText();
//    bleft=ui->comboBox_3->currentText();
//    bright=ui->comboBox_4->currentText();

//    query.prepare("update phacodb set footleft='"+left+"', footright='"+right+"',footbleft='"+bleft+"',footbright='"+bright+"'where surgeon='"+surgeonid+"'");

//    if (!query.exec()) {
//        qDebug() << "Error: Unable to insert data";
//        return;
//    }
//    query.bindValue(left, "footleft");
//    query.bindValue(right, "footright");
//    query.bindValue(bleft,"footbleft");
//    query.bindValue(bright,"footbright");

//    mydb.close();
//    QSqlDatabase::removeDatabase("QSQLITE");


//

//}

void footpedal::SaveForAll()
{
   // d->on_pushButton_10_clicked();
    d1->IASaveBut();
    //d->on_pushButton_13_clicked();
    //d->on_pushButton_18_clicked();


    QMessageBox::information(nullptr,"Info","Saved Successfully");

}
