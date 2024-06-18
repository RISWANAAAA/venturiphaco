#include "doctor.h"
#include "ui_doctor.h"
#include<QMessageBox>
#include<QTimer>
doctor::doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doctor)
{
    ui->setupUi(this);
    move(0,0);
    timer=new QTimer;
    message=new QMessageBox(this);

                        connect(timer,&QTimer::timeout,[=]()
                        {
                            timer->stop();
                            message->close();

                        });
                        QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; }";
                         ui-> tabWidget->setStyleSheet(tabStyle);
//    QString styleSheet = "QPushButton {"
//                                 "    font-family: Ubuntu;"
//                                 "    font-size: 20pt;"
//                                 "    background-color: red;"
//                                 "    border-radius: 20px;" // Adjust the radius as needed
//                                 "}";

    QSqlDatabase mydatabase = QSqlDatabase::addDatabase("QSQLITE");
       mydatabase.setDatabaseName(PATH1);
       mydatabase.open();
    surgeonid=ui->SelectSurgeon->currentText();

    //p=new prime;
    key=new keypad;
    connect(key,&keypad::textsignal,this,&doctor::on_clicked);
    connect(key,&keypad::entersignal,this,&doctor::on_clickedenter);

    left=ui->LeftFoot->currentText();
    right=ui->RightFoot->currentText();
    bleft=ui->BottomLFoot->currentText();
    bright=ui->BottomRFoot->currentText();

    ui->lineEdit_6->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);
    ui->lineEdit_7->installEventFilter(this);
    ui->lineEdit_11->installEventFilter(this);
    ui->lineEdit_12->installEventFilter(this);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_19->installEventFilter(this);
    ui->lineEdit_20->installEventFilter(this);
  connect(ui->DiaBut,&QPushButton::clicked,this,&doctor::DiathermyBut);
  connect(ui->PhacoBut,&QPushButton::clicked,this,&doctor::PhacoBut);
  connect(ui->IABut,&QPushButton::clicked,this,&doctor::IrrigationAspirationBut);
  connect(ui->VitBut,&QPushButton::clicked,this,&doctor::VitrectomyBut);
  connect(ui->SaveDiaBut,&QPushButton::clicked,this,&doctor::DiaSaveBut);
  connect(ui->SavePhacoBut_phaco,&QPushButton::clicked,this,&doctor::PhacoSaveBut);
  connect(ui->IABut,&QPushButton::clicked,this,&doctor::IASaveBut);
  connect(ui->savevitbut,&QPushButton::clicked,this,&doctor::VitSaveBut);
   connect(ui->EpinBut_phaco,&QPushButton::clicked,this,&doctor::Epinucleus);
    connect(ui->QuadBut_phaco,&QPushButton::clicked,this,&doctor::Quad);
     connect(ui->ChopBut_phaco,&QPushButton::clicked,this,&doctor::Chop);
      connect(ui->ScupltBut_phaco,&QPushButton::clicked,this,&doctor::Sculpt);
      connect(ui->BackBut,&QPushButton::clicked,this,&doctor::BackBut);

    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(5);



      //  DIATHERMY

    connect(ui->lineEdit_6,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_6->text().toInt();

    });
//PHACO
    connect(ui->lineEdit_2,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_2->text().toInt();

    });
    ui->lineEdit_2->setText(QString::number(500));

    connect(ui->lineEdit_3,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_3->text().toInt();

    });
    ui->lineEdit_3->setText(QString::number(500));

    connect(ui->lineEdit_4,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_4->text().toInt();

    });
    ui->lineEdit_4->setText(QString::number(100));
//IA

    connect(ui->lineEdit_5,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_5->text().toInt();

    });
    ui->lineEdit_5->setText(QString::number(500));

    connect(ui->lineEdit_7,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_7->text().toInt();

    });
    ui->lineEdit_7->setText(QString::number(500));

    connect(ui->lineEdit_12,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_12->text().toInt();

    });
    ui->lineEdit_12->setText(QString::number(500));

    connect(ui->lineEdit_11,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_11->text().toInt();

    });
    ui->lineEdit_11->setText(QString::number(500));
    //VIT
    connect(ui->lineEdit,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit->text().toInt();

    });
    ui->lineEdit->setText(QString::number(960));

    connect(ui->lineEdit_19,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_19->text().toInt();

    });
    ui->lineEdit_19->setText(QString::number(500));

    connect(ui->lineEdit_20,&QLineEdit::textChanged,this,[=](){
        int value=ui->lineEdit_20->text().toInt();

    });
    ui->lineEdit_20->setText(QString::number(500));



    ui->tabWidget->setTabText(0,"    DIA");
    ui->tabWidget->setTabText(1,"    PHACO");
    ui->tabWidget->setTabText(2,"    IA");
    ui->tabWidget->setTabText(3,"    VIT    ");

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &doctor::click);
     click(ui->tabWidget->currentIndex());



}

doctor::~doctor()
{
    delete ui;
}

void doctor::userMessage(int value, int minValue, int maxValue)
{

        QString msg( "Value must be between " + QString::number(minValue) + " and " + QString::number(maxValue));
    if(value>=maxValue){
        message->setText(msg);
        message->show();
        timer->start(1000);


    }

}

bool doctor::eventFilter(QObject *object, QEvent *event)
{
    //diathermy
    if(object == ui->lineEdit_6 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(273,149);
          key->move(280,320);
          key->show();

          ui->lineEdit_6->setFocus();
//          ui->lineEdit_23->clearFocus();
//          ui->lineEdit_24->clearFocus();
          ui->lineEdit_6->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
      //phaco
}
    if(object == ui->lineEdit_2 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(273,149);
          key->move(280,320);
          key->show();
          ui->lineEdit_2->setFocus();
          ui->lineEdit_3->clearFocus();
          ui->lineEdit_4->clearFocus();
          ui->lineEdit_2->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineEdit_3 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(273,149);
          key->move(280,320);
          key->show();
          ui->lineEdit_3->setFocus();
          ui->lineEdit_2->clearFocus();
          ui->lineEdit_4->clearFocus();
          ui->lineEdit_3->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineEdit_4 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(273,149);
          key->move(280,320);
          key->show();
          ui->lineEdit_4->setFocus();
          ui->lineEdit_3->clearFocus();
          ui->lineEdit_2->clearFocus();
          ui->lineEdit_4->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
//irrigation
    if(object == ui->lineEdit_5 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(273,149);
          key->move(280,320);
          key->show();
          ui->lineEdit_5->setFocus();
          ui->lineEdit_7->clearFocus();
          ui->lineEdit_11->clearFocus();
          ui->lineEdit_12->clearFocus();
          ui->lineEdit_5->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineEdit_7 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(273,149);
          key->move(280,320);
          key->show();
          ui->lineEdit_7->setFocus();
          ui->lineEdit_11->clearFocus();
          ui->lineEdit_5->clearFocus();
          ui->lineEdit_12->clearFocus();
          ui->lineEdit_7->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
    }
      if(object == ui->lineEdit_12 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(273,149);
            key->move(280,320);
            key->show();
            ui->lineEdit_12->setFocus();
            ui->lineEdit_5->clearFocus();
            ui->lineEdit_11->clearFocus();
            ui->lineEdit_7->clearFocus();
            ui->lineEdit_12->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_11 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(273,149);
            key->move(280,320);
            key->show();
            ui->lineEdit_11->setFocus();
            ui->lineEdit_5->clearFocus();
            ui->lineEdit_12->clearFocus();
            ui->lineEdit_7->clearFocus();
            ui->lineEdit_11->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
//vitrectomy
      if(object == ui->lineEdit && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(273,149);
            key->move(280,320);
            key->show();
            ui->lineEdit->setFocus();
            ui->lineEdit_19->clearFocus();
            ui->lineEdit_20->clearFocus();
            ui->lineEdit->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
        if(object == ui->lineEdit_19 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->close();
              key->resize(273,149);
              key->move(280,320);
              key->show();
              ui->lineEdit_19->setFocus();
              ui->lineEdit_20->clearFocus();
              ui->lineEdit->clearFocus();
              ui->lineEdit_19->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
      }
        if(object == ui->lineEdit_20 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->close();
              key->resize(273,149);
              key->move(280,320);
              key->show();
              ui->lineEdit_20->setFocus();
              ui->lineEdit->clearFocus();
              ui->lineEdit_19->clearFocus();
              ui->lineEdit_20->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
    return false;


}

void doctor::setRange(QLineEdit *lineEdit, int prevValue, int value, int maxValue)
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

void doctor::on_clicked(const QString& digit)
{
    //diathermy
    if(ui->lineEdit_6->focusWidget()) {
//        ui->lineEdit_23->clearFocus();
//        ui->lineEdit_24->clearFocus();
        ui->lineEdit_6->setFocus();


        int prevValue = ui->lineEdit_6->text().toInt();
        int value = (ui->lineEdit_6->text()+digit).toInt();

        setRange(ui->lineEdit_6, prevValue, value, 100);
         userMessage(value,5,100);


    }
    //phaco
    else if(ui->lineEdit_2->focusWidget()) {
        ui->lineEdit_3->clearFocus();
        ui->lineEdit_4->clearFocus();
        ui->lineEdit_2->setFocus();
        int prevValue = ui->lineEdit_2->text().toInt();
        int value = (ui->lineEdit_2->text()+digit).toInt();
        setRange(ui->lineEdit_2, prevValue, value, 500);
        userMessage(value,5,500);
    }
    else if(ui->lineEdit_3->focusWidget()) {
        ui->lineEdit_2->clearFocus();
        ui->lineEdit_4->clearFocus();
        ui->lineEdit_3->setFocus();
        int prevValue = ui->lineEdit_3->text().toInt();
        int value = (ui->lineEdit_3->text()+digit).toInt();
        setRange(ui->lineEdit_3, prevValue, value, 500);
        userMessage(value,5,500);}
    else if(ui->lineEdit_4->focusWidget()) {
        ui->lineEdit_2->clearFocus();
        ui->lineEdit_3->clearFocus();
        ui->lineEdit_4->setFocus();
        int prevValue = ui->lineEdit_4->text().toInt();
        int value = (ui->lineEdit_4->text()+digit).toInt();
        setRange(ui->lineEdit_4, prevValue, value, 100);
        userMessage(value,5,100);}
    //irrigation
   else if(ui->lineEdit_5->focusWidget()) {
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_5->setFocus();
        int prevValue = ui->lineEdit_5->text().toInt();
        int value = (ui->lineEdit_5->text()+digit).toInt();
        setRange(ui->lineEdit_5, prevValue, value, 500);
        userMessage(value,5,500);}
   else if(ui->lineEdit_7->focusWidget()) {
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_7->setFocus();
        int prevValue = ui->lineEdit_7->text().toInt();
        int value = (ui->lineEdit_7->text()+digit).toInt();
        setRange(ui->lineEdit_7, prevValue, value, 500);
        userMessage(value,5,500);}
    else if(ui->lineEdit_12->focusWidget()) {
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_12->setFocus();
        int prevValue = ui->lineEdit_12->text().toInt();
        int value = (ui->lineEdit_12->text()+digit).toInt();
        setRange(ui->lineEdit_12, prevValue, value, 500);
        userMessage(value,5,500);}
   else  if(ui->lineEdit_11->focusWidget()) {
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->setFocus();
        int prevValue = ui->lineEdit_11->text().toInt();
        int value = (ui->lineEdit_11->text()+digit).toInt();
        setRange(ui->lineEdit_11, prevValue, value, 500);
        userMessage(value,5,500);}
    //vitrectomy
  else  if(ui->lineEdit->focusWidget()) {
        ui->lineEdit_19->clearFocus();
        ui->lineEdit_20->clearFocus();
        //ui->lineEdit_12->clearFocus();
        ui->lineEdit->setFocus();
        int prevValue = ui->lineEdit->text().toInt();
        int value = (ui->lineEdit->text()+digit).toInt();
        setRange(ui->lineEdit, prevValue, value, 960);
        userMessage(value,60,960);}
    else if(ui->lineEdit_19->focusWidget()) {
        ui->lineEdit->clearFocus();
        ui->lineEdit_20->clearFocus();
        //ui->lineEdit_12->clearFocus();
        ui->lineEdit_19->setFocus();
        int prevValue = ui->lineEdit_19->text().toInt();
        int value = (ui->lineEdit_19->text()+digit).toInt();
        setRange(ui->lineEdit_19, prevValue, value, 500);
        userMessage(value,5,500);}
    if(ui->lineEdit_20->focusWidget()) {
        ui->lineEdit->clearFocus();
        ui->lineEdit_19->clearFocus();
        //ui->lineEdit_12->clearFocus();
        ui->lineEdit_20->setFocus();
        int prevValue = ui->lineEdit_20->text().toInt();
        int value = (ui->lineEdit_20->text()+digit).toInt();
        setRange(ui->lineEdit_20, prevValue, value, 500);
        userMessage(value,5,500);
    }
}

void doctor::on_clickedenter()
{
    key->hide();
}

void doctor::DiathermyBut()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->lineEdit_6->setText(QString::number(100));

}

void doctor::PhacoBut()
{
    ui->tabWidget->setCurrentIndex(1);
}

void doctor::IrrigationAspirationBut()
{
    ui->tabWidget->setCurrentIndex(2);
}

void doctor::VitrectomyBut()
{
    ui->tabWidget->setCurrentIndex(3);
}

void doctor::BackBut()
{
    this->close();
    //parentWidget()->show();
}
void doctor::Epinucleus()
{
    ui->lineEdit_2->setText("22");
    ui->lineEdit_3->setText("200");
    ui->lineEdit_4->setText("60");

}

void doctor::Quad()
{
    ui->lineEdit_2->setText("22");
    ui->lineEdit_3->setText("200");
    ui->lineEdit_4->setText("50");
}

void doctor::Chop()
{
    ui->lineEdit_2->setText("26");
    ui->lineEdit_3->setText("200");
    ui->lineEdit_4->setText("60");

}

void doctor::Sculpt()
{
    ui->lineEdit_2->setText("16");
    ui->lineEdit_3->setText("150");
    ui->lineEdit_4->setText("70");
}
void doctor::PhacoSaveBut()
{
    QSqlDatabase mydatabase = QSqlDatabase::addDatabase("QSQLITE");
       mydatabase.setDatabaseName(PATH1);
       if (!mydatabase.open()) {
           qDebug() << "Error: Unable to open database";
           return;
       }


       //QSqlQuery query;
       QString aspmax;
       QString vacmax;
       QString powmax;
       QString Epin;
       QString Quad;
       QString Chop;
       QString Sculpt;
       QString epinaspmax;
       QString epinvacmax;
       QString epinpowmax;
       QString qaspmax;
       QString qvacmax;
       QString qpowmax;
       QString caspmax;
       QString cvacmax;
       QString cpowmax;
       QString saspmax;
       QString svacmax;
       QString spowmax;


       surgeonid=ui->SelectSurgeon->currentText();
       aspmax=ui->lineEdit_2->text();
       vacmax=ui->lineEdit_3->text();
       powmax=ui->lineEdit_4->text();
       epinaspmax=ui->lineEdit_2->text();
       epinvacmax=ui->lineEdit_3->text();
       epinpowmax=ui->lineEdit_4->text();
        qaspmax=ui->lineEdit_2->text();
        qvacmax=ui->lineEdit_3->text();
        qpowmax=ui->lineEdit_4->text();
        caspmax=ui->lineEdit_2->text();
        cvacmax=ui->lineEdit_3->text();
        cpowmax=ui->lineEdit_4->text();
        saspmax=ui->lineEdit_2->text();
        svacmax=ui->lineEdit_3->text();
        spowmax=ui->lineEdit_4->text();

       QSqlQuery query,query2;

       query.prepare("update phacoupdate.db set phacoaspmax='"+aspmax+"', phacovacmax='"+vacmax+"',phacopowmax='"+powmax+"',epin='"+Epin+"',quad='"+Quad+"',chop='"+Chop+"',sculpt='"+Sculpt+"',where surgeon='"+surgeonid+"'");
      QMessageBox::information(nullptr,"Info","Saved Successfully");
      query2.prepare("update phacoupdate.db set Epinaspmax='"+epinaspmax+"', Epinvacmax='"+epinvacmax+"',Epinpowmax='"+epinpowmax+"',quadaspmax='"+qaspmax+"',quadvacmax='"+qvacmax+"',quadpowmax='"+qpowmax+"',chopaspmax='"+caspmax+"',chopvacmax='"+cvacmax+"',choppowmax='"+cpowmax+"',sculptaspmax='"+saspmax+"',sculptvacmax='"+svacmax+"',sculptpowmax='"+spowmax+"'where surgeon='"+surgeonid+"'");
      qDebug()<<"hello";
       qDebug()<<aspmax<<vacmax<<powmax;
       qDebug()<<epinaspmax<<epinpowmax<<epinvacmax<<qaspmax<<qvacmax<<qpowmax<<caspmax<<cvacmax<<cpowmax<<saspmax<<svacmax<<spowmax;

       if (!query.exec()) {
           qDebug() << "Error: Unable to insert data";
           return;
       }

       mydatabase.close();
}





void doctor::DiaSaveBut()
{
    QSqlDatabase mydatabase = QSqlDatabase::addDatabase("QSQLITE");
       mydatabase.setDatabaseName(PATH1);
       if (!mydatabase.open()) {
           qDebug() << "Error: Unable to open database";
           return;
       }


       //QSqlQuery query;
      // QString aspmax;
       //QString vacmax;
       QString powmax;

       surgeonid=ui->SelectSurgeon->currentText();
     //  di=ui->lineEdit_6->text();
     //  vacmax=ui->lineEdit_3->text();
       powmax=ui->lineEdit_6->text();




       QSqlQuery query;
       query.prepare("update phacoupdate.db set diapowmax='"+powmax+"'where surgeon='"+surgeonid+"'");
       QMessageBox::information(nullptr,"Info","Saved Successfully");
       if (!query.exec()) {
           qDebug() << "Error: Unable to insert data";
           return;
       }

       mydatabase.close();
}

void doctor::IASaveBut()
{
    QSqlDatabase mydatabase = QSqlDatabase::addDatabase("QSQLITE");
       mydatabase.setDatabaseName(PATH1);
       if (!mydatabase.open()) {
           qDebug() << "Error: Unable to open database";
           return;
       }


       //QSqlQuery query;
       QString ia1aspmax;
       QString ia1vacmax;
       QString ia2aspmax;
       QString ia2vacmax;

       //QString powmax;
       QString cortexaspmode;
       QString cortexvacmode;
       QString polishaspmode;
       QString polishvacmode;


       surgeonid=ui->SelectSurgeon->currentText();
        cortexaspmode=ui->AspMode_iacom->currentText();
        cortexvacmode=ui->VacMode1_iacom->currentText();
        polishaspmode=ui->AspMode2_iacom->currentText();
        polishvacmode=ui->VacMode2_iacom->currentText();

        ia1aspmax=ui->lineEdit_5->text();
        ia1vacmax=ui->lineEdit_7->text();
        ia2aspmax=ui->lineEdit_12->text();
        ia2vacmax=ui->lineEdit_11->text();
      // powmax=ui->lineEdit_6->text();




       QSqlQuery query;
       QSqlQuery query2;

       query.prepare("update phacoupdate.db set ia1aspmax='"+ia1aspmax+"', ia1vacmax='"+ia1vacmax+"',ia2aspmax='"+ia2aspmax+"',ia2vacmax='"+ia2aspmax+"'where surgeon='"+surgeonid+"'");
       qDebug()<<"hi";
    //   QSqlQuery query1;
       query2.prepare("update phacoupdate.db set cortexaspmode='"+cortexaspmode+"', cortextvacmode='"+cortexvacmode+"',polishaspmode='"+polishaspmode+"',polishvacmode='"+polishvacmode+"'where surgeon='"+surgeonid+"'");
       qDebug()<<"hello";
 QMessageBox::information(nullptr,"Info","Saved Successfully");


      // qDebug()<<aspmax<<vacmax<<powmax;

       if (!query.exec()) {
           qDebug() << "Error: Unable to insert data";
           return;
       }
       if (!query2.exec()) {
           qDebug() << "Error: Unable to insert data";
           return;
       }

       mydatabase.close();

}

void doctor::VitSaveBut()
{
    QSqlDatabase mydatabase = QSqlDatabase::addDatabase("QSQLITE");
       mydatabase.setDatabaseName(PATH1);
       if (!mydatabase.open()) {
           qDebug() << "Error: Unable to open database";
           return;
       }

    surgeonid=ui->SelectSurgeon->currentText();
    vcutmax=ui->lineEdit->text();
    vvacmax=ui->lineEdit_19->text();
    vcutmode=ui->CutMode_vitCom->currentText();
    vvacmode=ui->VacMode_VitCom->currentText();
    vitaspmax=ui->lineEdit_20->text();


    QSqlQuery query;
    QSqlQuery query2;
 //   query.prepare("update phacodb set ia1aspmax='"+ia1aspmax+"', ia1vacmax='"+ia1vacmax+"',ia2aspmax='"+ia2aspmax+"',ia2vacmax='"+ia2aspmax+"'where
    query.prepare("update phacoupdate.db set vitcutmax='"+vcutmax+"', vitvacmax='"+vvacmax+"',vitcutmode='"+vcutmode+"',vitvacmode='"+vvacmode+"',vitaspmax='"+vitaspmax+"'where surgeon='"+surgeonid+"'");
    qDebug()<<"hi";
    query2.prepare("update phacoupate.db set footleft='"+left+"', footright='"+right+"',footbleft='"+bleft+"',footbright='"+bright+"'where surgeon='"+surgeonid+"'");
    qDebug()<<"hello";
     QMessageBox::information(nullptr,"Info","Saved Successfully");
    if (!query.exec()) {
        qDebug() << "Error: Unable to insert data";
        return;
    }


    mydatabase.close();

}

void doctor::click(int tab)
{
    QString styleSheet = "QPushButton {"
            "border-radius: 40px;"
            "width:10px;"
            "height:10px;"
            "background-color:black;"
            "color:white;"
            "border:none;"
            "font:bold;"// Adjust the radius as needed
                                 "}";
    QString styleSheet1 = "QPushButton {"
            "border-radius: 40px;"
            "width:10px;"
            "height:10px;"
            "background-color:transparent;"
            "border:none;"
            "font:bold;"// Adjust the radius as needed
                                 "}";
    if (tab!=0) {
        ui->DiaBut->setStyleSheet("");
   ui->DiaBut->setStyleSheet(styleSheet1);
    }
    if(tab!=1)
    {
        ui->PhacoBut->setStyleSheet("");
          ui->PhacoBut->setStyleSheet(styleSheet1);
    }
    if(tab!=2){
        ui->IABut->setStyleSheet("");
          ui->IABut->setStyleSheet(styleSheet1);
    }
    if(tab!=3){
    ui->VitBut->setStyleSheet("");
     ui->VitBut->setStyleSheet(styleSheet1);
    }
    if (tab == 0) {
    ui->DiaBut->setStyleSheet(styleSheet);
    } else if (tab == 1) {
     ui->PhacoBut->setStyleSheet(styleSheet);
    }                                                                      //set color
    else if(tab==2){
         ui->IABut->setStyleSheet(styleSheet);
    }
    else if(tab==3){
         ui->VitBut->setStyleSheet(styleSheet);
    }

}



