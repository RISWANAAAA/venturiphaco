#include "doctor.h"
#include "ui_doctor.h"
#include<QMessageBox>
#include<QTimer>
#include<QSqlError>
#include<QMap>
doctor::doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doctor)
{
    ui->setupUi(this);
    ui->lineEdit_20->setVisible(true);  // Ensure it is visible
    ui->lineEdit_20->setEnabled(true);  // Ensure it is enabled
    ui->lineEdit_20->setText("40");
    ui->lineEdit_20->raise();

    move(0,0);
    timer=new QTimer;
    messagebox=new QMessageBox(this);
    QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; }";
    ui->tabWidget_2->setStyleSheet(tabStyle);
         connect(ui->tabWidget_2, &QTabWidget::currentChanged, this, &doctor::clickedtab);
          clickedtab(ui->tabWidget_2->currentIndex());


    message=new QMessageBox(this);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName(PATH1);
       mydb.open();
    surgeonid=ui->SelectSurgeon->currentText();

                        connect(timer,&QTimer::timeout,[=]()
                        {
                            timer->stop();
                            message->close();

                        });
                        QString tabStyle1 = "QTabBar::tab:selected { background-color: black; color: #ffffff; }";
                         ui-> tabWidget->setStyleSheet(tabStyle1);

    //p=new prime;
    //p=new prime;
    key=new keypad;
    connect(key,&keypad::textsignal,this,&doctor::on_clicked);
    connect(key,&keypad::entersignal,this,&doctor::on_clickedenter);
    //connect(ui->pushButton,&QPushButton::clicked,this,&doctor::savesettings);
     //connect(ui->SelectSurgeon, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &doctor::current);
    connect(ui->comboBox,&QComboBox::currentTextChanged, this, &doctor::pumpvalue);
     ui->lineEdit_6->setText("100");
  ui->lineEdit_2->setText("40");
  ui->lineEdit_3->setText("500");
  ui->lineEdit_4->setText("100");
  ui->lineEdit_7->setText("500");
  ui->lineEdit_5->setText("40");
  ui->lineEdit_11->setText("500");
  ui->lineEdit_12->setText("40");
  ui->lineEdit->setText("100");
  ui->lineEdit_19->setText("500");

  ui->lineEdit_2->setText("22");
  ui->lineEdit_3->setText("200");
  ui->lineEdit_4->setText("60");

  // Set default values to UI elements
  ui->lineEdit_8->setText("22");
  ui->lineEdit_9->setText("200");
  ui->lineEdit_10->setText("50");

  ui->lineEdit_13->setText("26");
    ui->lineEdit_14->setText("200");
    ui->lineEdit_15->setText("60");

  ui->lineEdit_16->setText("16");
     ui->lineEdit_17->setText("150");
     ui->lineEdit_18->setText("70");

    ui->lineEdit_6->installEventFilter(this);
    //phaco
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    //quad

    ui->lineEdit_10->installEventFilter(this);
    ui->lineEdit_9->installEventFilter(this);
    ui->lineEdit_8->installEventFilter(this);

    //chop
    ui->lineEdit_13->installEventFilter(this);
    ui->lineEdit_14->installEventFilter(this);
    ui->lineEdit_15->installEventFilter(this);

    //sculpt

    ui->lineEdit_16->installEventFilter(this);
    ui->lineEdit_17->installEventFilter(this);
    ui->lineEdit_18->installEventFilter(this);



    //ia
    ui->lineEdit_5->installEventFilter(this);
    ui->lineEdit_7->installEventFilter(this);
    ui->lineEdit_11->installEventFilter(this);
    ui->lineEdit_12->installEventFilter(this);
    //vit
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_19->installEventFilter(this);
    ui->lineEdit_20->installEventFilter(this);

  ui->progressBar->setRange(5,100);
  ui->progressBar_5->setRange(2,40);
  ui->progressBar_6->setRange(5,500);
  ui->progressBar_7->setRange(5,100);
  ui->progressBar_10->setRange(5,100);
  ui->progressBar_8->setRange(2,40);
  ui->progressBar_9->setRange(5,500);
  ui->progressBar_11->setRange(2,40);
  ui->progressBar_12->setRange(5,500);
  ui->progressBar_13->setRange(5,100);
  ui->progressBar_2->setRange(2,40);
  ui->progressBar_3->setRange(5,500);
  ui->progressBar_4->setRange(5,100);
  ui->progressBar_14->setRange(5,500);
  ui->progressBar_15->setRange(2,40);
  ui->progressBar_16->setRange(5,500);
  ui->progressBar_17->setRange(2,40);
  ui->progressBar_19->setRange(5,500);
  ui->progressBar_20->setRange(2,40);
  ui->progressBar_21->setRange(60,960);

  connect(ui->DiaBut,&QPushButton::clicked,this,&doctor::DiathermyBut);
  connect(ui->PhacoBut,&QPushButton::clicked,this,&doctor::PhacoBut);
  connect(ui->IABut,&QPushButton::clicked,this,&doctor::IrrigationAspirationBut);
  connect(ui->VitBut,&QPushButton::clicked,this,&doctor::VitrectomyBut);


      connect(ui->BackBut,&QPushButton::clicked,this,&doctor::BackBut);

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
          key->resize(481,301);
          key->move(280,320);
          key->show();

          ui->lineEdit_6->setFocus();
          ui->lineEdit_6->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
      //phaco
}
    if(object == ui->lineEdit_2 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(481,301);
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
          key->resize(481,301);
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
          key->resize(481,301);
          key->move(280,320);
          key->show();
          ui->lineEdit_4->setFocus();
          ui->lineEdit_3->clearFocus();
          ui->lineEdit_2->clearFocus();
          ui->lineEdit_4->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
    }
      //quad
      if(object == ui->lineEdit_10 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_10->setFocus();
            ui->lineEdit_8->clearFocus();
            ui->lineEdit_9->clearFocus();
            ui->lineEdit_10->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_8 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_8->setFocus();
            ui->lineEdit_10->clearFocus();
            ui->lineEdit_9->clearFocus();
            ui->lineEdit_8->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_9 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_9->setFocus();
            ui->lineEdit_10->clearFocus();
            ui->lineEdit_8->clearFocus();
            ui->lineEdit_9->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }

}
      //chop
      if(object == ui->lineEdit_13 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_13->setFocus();
            ui->lineEdit_14->clearFocus();
            ui->lineEdit_15->clearFocus();
            ui->lineEdit_13->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_14 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_14->setFocus();
            ui->lineEdit_13->clearFocus();
            ui->lineEdit_15->clearFocus();
            ui->lineEdit_14->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_15 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_15->setFocus();
            ui->lineEdit_14->clearFocus();
            ui->lineEdit_13->clearFocus();
            ui->lineEdit_15->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }

}
      //sculpt
      if(object == ui->lineEdit_16 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_16->setFocus();
            ui->lineEdit_17->clearFocus();
            ui->lineEdit_18->clearFocus();
            ui->lineEdit_16->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_17 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_17->setFocus();
            ui->lineEdit_18->clearFocus();
            ui->lineEdit_16->clearFocus();
            ui->lineEdit_17->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
  }
      if(object == ui->lineEdit_18 && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
            key->close();
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit_18->setFocus();
            ui->lineEdit_17->clearFocus();
            ui->lineEdit_16->clearFocus();
            ui->lineEdit_18->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }

}

//irrigation
    if(object == ui->lineEdit_5 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->close();
          key->resize(481,301);
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
          key->resize(481,301);
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
            key->resize(481,301);
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
            key->resize(481,301);
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
            key->resize(481,301);
            key->move(280,320);
            key->show();
            ui->lineEdit->setFocus();
            ui->lineEdit_19->clearFocus();
            ui->lineEdit_20->clearFocus();
            ui->lineEdit->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
      }
        if(object == ui->lineEdit_19 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->close();
              key->resize(481,301);
              key->move(280,320);
              key->show();
              ui->lineEdit_19->setFocus();
              ui->lineEdit_20->clearFocus();
              ui->lineEdit->clearFocus();
              ui->lineEdit_19->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }

        if(object == ui->lineEdit_20 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->close();
              key->resize(481,301);
              key->move(280,320);
              key->show();
              ui->lineEdit_20->setFocus();
              ui->lineEdit->clearFocus();
              ui->lineEdit_19->clearFocus();
              ui->lineEdit_20->setText("");


          } else if ( k->button() == Qt::RightButton ) {
              ui->lineEdit_20->setText("40");
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
        ui->lineEdit_6->setFocus();

        int prevValue = ui->lineEdit_6->text().toInt();
        int value = (ui->lineEdit_6->text()+digit).toInt();
if(value ==0){
    ui->lineEdit_6->setText(QString::number(5));
    ui->progressBar->setValue(5);
    return;
}
        setRange(ui->lineEdit_6, prevValue, value, 100);
        ui->progressBar->setValue(value);
       // increasebutton(ui->lineEdit_6);



    }
    //phaco
     if(ui->lineEdit_2->focusWidget()) {
        ui->lineEdit_3->clearFocus();
        ui->lineEdit_4->clearFocus();
        ui->lineEdit_2->setFocus();
        int prevValue = ui->lineEdit_2->text().toInt();
        int value1 = (ui->lineEdit_2->text()+digit).toInt();
        if(value1 == 0){
            ui->lineEdit_2->setText(QString::number(2));
            return;
        }
        setRange(ui->lineEdit_2, prevValue, value1, 40);

        ui->progressBar_5->setValue(value1);
    }
    if(ui->lineEdit_3->focusWidget()) {
        ui->lineEdit_2->clearFocus();
        ui->lineEdit_4->clearFocus();
        ui->lineEdit_3->setFocus();
        int prevValue = ui->lineEdit_3->text().toInt();
        int value2 = (ui->lineEdit_3->text()+digit).toInt();
        if(value2 == 0){
            ui->lineEdit_3->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_3, prevValue, value2, 500);

        ui->progressBar_6->setValue(value2);
    }
     if(ui->lineEdit_4->focusWidget()) {
        ui->lineEdit_2->clearFocus();
        ui->lineEdit_3->clearFocus();
        ui->lineEdit_4->setFocus();
        int prevValue = ui->lineEdit_4->text().toInt();
        int value3 = (ui->lineEdit_4->text()+digit).toInt();
        if(value3 == 0){
            ui->lineEdit_4->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_4, prevValue, value3, 100);

        ui->progressBar_7->setValue(value3);
    }
     //quad
     if(ui->lineEdit_8->focusWidget()) {
        ui->lineEdit_9->clearFocus();
        ui->lineEdit_10->clearFocus();
        ui->lineEdit_8->setFocus();
        int prevValue = ui->lineEdit_8->text().toInt();
        int value1 = (ui->lineEdit_8->text()+digit).toInt();
        if(value1 == 0){
            ui->lineEdit_8->setText(QString::number(2));
            ui->progressBar_8->setValue(5);
            return;

        }
        setRange(ui->lineEdit_8, prevValue, value1, 40);

        ui->progressBar_8->setValue(value1);
    }
    if(ui->lineEdit_10->focusWidget()) {
        ui->lineEdit_9->clearFocus();
        ui->lineEdit_8->clearFocus();
        ui->lineEdit_10->setFocus();
        int prevValue = ui->lineEdit_10->text().toInt();
        int value2 = (ui->lineEdit_10->text()+digit).toInt();
        if(value2 ==0){
            ui->lineEdit_10->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_10, prevValue, value2, 100);

        ui->progressBar_10->setValue(value2);
    }
     if(ui->lineEdit_9->focusWidget()) {
        ui->lineEdit_10->clearFocus();
        ui->lineEdit_8->clearFocus();
        ui->lineEdit_9->setFocus();
        int prevValue = ui->lineEdit_9->text().toInt();
        int value3 = (ui->lineEdit_9->text()+digit).toInt();
        if(value3 == 0){
            ui->lineEdit_9->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_9, prevValue, value3, 500);

        ui->progressBar_9->setValue(value3);
    }
     //chop

     if(ui->lineEdit_13->focusWidget()) {
        ui->lineEdit_15->clearFocus();
        ui->lineEdit_14->clearFocus();
        ui->lineEdit_13->setFocus();
        int prevValue = ui->lineEdit_13->text().toInt();
        int value1 = (ui->lineEdit_13->text()+digit).toInt();
        if(value1 == 0){
            ui->lineEdit_13->setText(QString::number(2));
            return;
        }
        setRange(ui->lineEdit_13, prevValue, value1, 40);

        ui->progressBar_11->setValue(value1);
    }
    if(ui->lineEdit_14->focusWidget()) {
        ui->lineEdit_13->clearFocus();
        ui->lineEdit_15->clearFocus();
        ui->lineEdit_14->setFocus();
        int prevValue = ui->lineEdit_14->text().toInt();
        int value2 = (ui->lineEdit_14->text()+digit).toInt();
        if(value2 == 0){
            ui->lineEdit_14->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_14, prevValue, value2, 500);

        ui->progressBar_12->setValue(value2);
    }
     if(ui->lineEdit_15->focusWidget()) {
        ui->lineEdit_13->clearFocus();
        ui->lineEdit_14->clearFocus();
        ui->lineEdit_15->setFocus();
        int prevValue = ui->lineEdit_15->text().toInt();
        int value3 = (ui->lineEdit_15->text()+digit).toInt();
        if(value3 == 0){
            ui->lineEdit_15->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_15, prevValue, value3, 100);

        ui->progressBar_13->setValue(value3);
    }
     //sculpt
     if(ui->lineEdit_16->focusWidget()) {
        ui->lineEdit_17->clearFocus();
        ui->lineEdit_18->clearFocus();
        ui->lineEdit_16->setFocus();
        int prevValue = ui->lineEdit_16->text().toInt();
        int value1 = (ui->lineEdit_16->text()+digit).toInt();
        if(value1 == 0){
            ui->lineEdit_16->setText(QString::number(2));
            return;
        }
        setRange(ui->lineEdit_16, prevValue, value1, 40);

        ui->progressBar_2->setValue(value1);
    }
    if(ui->lineEdit_18->focusWidget()) {
        ui->lineEdit_16->clearFocus();
        ui->lineEdit_17->clearFocus();
        ui->lineEdit_18->setFocus();
        int prevValue = ui->lineEdit_18->text().toInt();
        int value2 = (ui->lineEdit_18->text()+digit).toInt();
        if(value2 == 0){
            ui->lineEdit_2->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_18, prevValue, value2, 100);

        ui->progressBar_4->setValue(value2);
    }
     if(ui->lineEdit_17->focusWidget()) {
        ui->lineEdit_16->clearFocus();
        ui->lineEdit_18->clearFocus();
        ui->lineEdit_17->setFocus();
        int prevValue = ui->lineEdit_17->text().toInt();
        int value3 = (ui->lineEdit_17->text()+digit).toInt();
        if(value3 == 0){
            ui->lineEdit_17->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_17, prevValue, value3, 500);

        ui->progressBar_3->setValue(value3);

      }



    //irrigation
   if(ui->lineEdit_5->focusWidget()) {
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_5->setFocus();
        int prevValue = ui->lineEdit_5->text().toInt();
        int value4 = (ui->lineEdit_5->text()+digit).toInt();
        if(value4 == 0){
            ui->lineEdit_5->setText(QString::number(2));
            return;
        }
        setRange(ui->lineEdit_5, prevValue, value4, 40);

        ui->progressBar_17->setValue(value4);
    }
   if(ui->lineEdit_7->focusWidget()) {
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_7->setFocus();
        int prevValue = ui->lineEdit_7->text().toInt();
        int value5 = (ui->lineEdit_7->text()+digit).toInt();
        if(value5 == 0){
            ui->lineEdit_7->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_7, prevValue, value5, 500);

        ui->progressBar_16->setValue(value5);
    }
     if(ui->lineEdit_12->focusWidget()) {
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_12->setFocus();
        int prevValue = ui->lineEdit_12->text().toInt();
        int value6 = (ui->lineEdit_12->text()+digit).toInt();
        if(value6 == 0){
            ui->lineEdit_12->setText(QString::number(2));
            return;
        }
        setRange(ui->lineEdit_12, prevValue, value6, 40);

        ui->progressBar_15->setValue(value6);
    }
    if(ui->lineEdit_11->focusWidget()) {
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->setFocus();
        int prevValue = ui->lineEdit_11->text().toInt();
        int value7 = (ui->lineEdit_11->text()+digit).toInt();
        if(value7 == 0){
            ui->lineEdit_11->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_11, prevValue, value7, 500);
        //userMessage(value,5,500);
       // vacbutton(ui->lineEdit_11);
        ui->progressBar_14->setValue(value7);
    }
    //vitrectomy
    if(ui->lineEdit->focusWidget()) {
        ui->lineEdit_19->clearFocus();
        ui->lineEdit_20->clearFocus();

        ui->lineEdit->setFocus();
        int prevValue = ui->lineEdit->text().toInt();
        int value8 = (ui->lineEdit->text()+digit).toInt();
        if(value8 == 0){
            ui->lineEdit->setText(QString::number(60));
            return;
        }
        setRange(ui->lineEdit, prevValue, value8, 960);
        ui->progressBar_21->setValue(value8);
        //userMessage(value,60,960);
        //powervit();
    }
     if(ui->lineEdit_19->focusWidget()) {
        ui->lineEdit->clearFocus();
        ui->lineEdit_20->clearFocus();
        ui->lineEdit_19->setFocus();
        int prevValue = ui->lineEdit_19->text().toInt();
        int value9 = (ui->lineEdit_19->text()+digit).toInt();
        if(value9 == 0){
            ui->lineEdit_19->setText(QString::number(5));
            return;
        }
        setRange(ui->lineEdit_19, prevValue, value9, 500);
        ui->progressBar_19->setValue(value9);
    }
    if(ui->lineEdit_20->focusWidget()) {
        ui->lineEdit->clearFocus();
        ui->lineEdit_19->clearFocus();
      ui->lineEdit_20->setFocus();
        int prevValue = ui->lineEdit_20->text().toInt();
        int value = (ui->lineEdit_20->text()+digit).toInt();
        if(value == 0){
            ui->lineEdit_20->setText(QString::number(2));
            return;
        }

        setRange(ui->lineEdit_20, prevValue, value, 40);
        ui->progressBar_20->setValue(value);

    }
}

void doctor::on_clickedenter()
{
    key->hide();

    // Maintain previous value for lineEdit
    QString text = ui->lineEdit->text().trimmed();
    if (!text.isEmpty()) {
        int input = text.toInt();
        int output = getvalue(input);  // Process the input to get the desired output
        ui->lineEdit->setText(QString::number(output));
        lastValidValues[ui->lineEdit] = output;  // Store the processed output as the last valid value
    } else {
        // Restore the last valid value if input is empty
        if (lastValidValues.contains(ui->lineEdit)) {
            ui->lineEdit->setText(QString::number(lastValidValues[ui->lineEdit]));
        }
    }

    // Process other QLineEdits for power and vacuum
    QList<QLineEdit*> lineEdits = {
        ui->lineEdit_3, ui->lineEdit_4, ui->lineEdit_10, ui->lineEdit_9,
        ui->lineEdit_14, ui->lineEdit_15, ui->lineEdit_17, ui->lineEdit_18,
        ui->lineEdit_11, ui->lineEdit_7, ui->lineEdit_19
    };

    for (QLineEdit* lineEdit : lineEdits) {
        QString currentText = lineEdit->text().trimmed();

        if (!currentText.isEmpty()) {
            int input = currentText.toInt();
            int output = increasebutton(input);  // Process the input to get the desired output
            lineEdit->setText(QString::number(output));
            lastValidValues[lineEdit] = output;  // Update the last valid value
        } else {
            // Restore the last valid value if input is empty
            if (lastValidValues.contains(lineEdit)) {
                lineEdit->setText(QString::number(lastValidValues[lineEdit]));
            }
        }
    }

    // Process other QLineEdits for flow rate
    QList<QLineEdit*> lineEdits1 = {
        ui->lineEdit_2, ui->lineEdit_8, ui->lineEdit_13,
        ui->lineEdit_16, ui->lineEdit_5, ui->lineEdit_12, ui->lineEdit_20
    };

    for (QLineEdit* lineEdit1 : lineEdits1) {
        QString currentText1 = lineEdit1->text().trimmed();

        if (!currentText1.isEmpty()) {
            int input1 = currentText1.toInt();
            int output1 = decreasebutton(input1);  // Process the input to get the desired output
            lineEdit1->setText(QString::number(output1));
            lastValidValues1[lineEdit1] = output1;  // Update the last valid value
        } else {
            // Restore the last valid value if input is empty
            if (lastValidValues1.contains(lineEdit1)) {
                lineEdit1->setText(QString::number(lastValidValues1[lineEdit1]));
            }
        }
    }
}


int doctor::increasebutton(int input)
{
    if (input < 10) {
          // For single-digit values, set it to 5
          return 5;
      } else {
          int remainder = input % 5; // Calculate the remainder when dividing by 5

          if (remainder == 0 || remainder == 1) {
              // Round down to the nearest multiple of 5
              return (input / 5) * 5;
          } else {
              // Round up to the next multiple of 5
              return ((input / 5) + 1) * 5;
          }
      }
  }


int doctor::decreasebutton(int input)
{
    if (input % 2 != 0) {
          input++;  // Increment if odd to make it even
      }
      return input;
}


void doctor::currentcombobox2(const QString &text)
{
    QString right = text;
       QString surgeonid = ui->SelectSurgeon->currentText();
       QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName(PATH1);
       if (!mydb.open()) {
           qDebug() << "Error: Unable to open database";
           return;
       }

       QSqlQuery query;
       query.prepare("UPDATE phacohigh SET footright = :right WHERE surgeon = :surgeon");
       query.bindValue(":right", right);
       query.bindValue(":surgeon", surgeonid);

       if (!query.exec()) {
         //  qDebug() << "Error: Unable to update database -" << query.lastError();
           return;
       }else{
           qDebug()<<"saved successfully";
           emit rightfoot(right);

       }

       mydb.close();
       qDebug() << "RightFoot value updated:" << right;
}

void doctor::currentcombobox3(const QString &text)
{
    QString bleft = text;
        QString surgeonid = ui->SelectSurgeon->currentText();
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(PATH1);
        if (!mydb.open()) {
            qDebug() << "Error: Unable to open database";
            return;
        }

        QSqlQuery query;
        query.prepare("UPDATE phacohigh SET footbleft = :bleft WHERE surgeon = :surgeon");
        query.bindValue(":bleft", bleft);
        query.bindValue(":surgeon", surgeonid);

        if (!query.exec()) {
          //  qDebug() << "Error: Unable to update database -" << query.lastError();
            return;
        }else{
            qDebug()<<"saved";
            emit bottomleft(bleft);

        }

        mydb.close();
        qDebug() << "BottomLFoot value updated:" << bleft;
}

void doctor::currentcombobox4(const QString &text)
{
    QString bright = text;
        QString surgeonid = ui->SelectSurgeon->currentText();
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(PATH1);
        if (!mydb.open()) {
            qDebug() << "Error: Unable to open database";
            return;
        }

        QSqlQuery query;
        query.prepare("UPDATE phacohigh SET footbright = :bright WHERE surgeon = :surgeon");
        query.bindValue(":bright", bright);
        query.bindValue(":surgeon", surgeonid);

        if (!query.exec()) {
           // qDebug() << "Error: Unable to update database -" << query.lastError();
            return;
        }else{
            qDebug()<<"saved";
            emit bottomright(bright);
        }

        mydb.close();
        qDebug() << "BottomRFoot value updated:" << bright;
}


void doctor::currentcombobox1(const QString &text)
{
    QString left = text;
       QString surgeonid = ui->SelectSurgeon->currentText();
       QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName(PATH1);
       if (!mydb.open()) {
           qDebug() << "Error: Unable to open database";
           return;
       }

       QSqlQuery query;
       query.prepare("UPDATE phacohigh SET footleft = :left WHERE surgeon = :surgeon");
       query.bindValue(":left", left);
       query.bindValue(":surgeon", surgeonid);

       if (!query.exec()) {
           //qDebug() << "Error: Unable to update database -" << query.lastError();
           return;
       }else{
           qDebug()<<"saved successfully";
           emit leftfoot(left);
       }

       mydb.close();
       qDebug() << "LeftFoot value updated:" << left;
}


void doctor::DiathermyBut()
{
    int powmax = ui->lineEdit_6->text().toInt(); // Get power max value from lineEdit
    QString surgeonid = ui->SelectSurgeon->currentText(); // Get selected surgeon
    ui->tabWidget->setCurrentIndex(0);
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
void doctor::savesettings()
{
    emit currentcombobox1(ui->LeftFoot->currentText());
    emit currentcombobox2(ui->RightFoot->currentText());
    emit currentcombobox3(ui->BottomLFoot->currentText());
    emit currentcombobox4(ui->BottomRFoot->currentText());

}
void doctor::BackBut()
{
    this->close();
}

void doctor::PhacoSaveBut()
{
}



void doctor::IASaveBut()
{
    // Open a SQLite database connection
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1); // Use the correct path for your database

    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        QMessageBox::warning(nullptr, "Error", "Unable to open database");
        return;
    }

    // Retrieve input values from the UI
    QString ia1aspmax = ui->lineEdit_5->text();
    QString ia1vacmax = ui->lineEdit_7->text();
    QString ia2aspmax = ui->lineEdit_12->text();
    QString ia2vacmax = ui->lineEdit_11->text();
    //QString coraspmode = ui->AspMode_iacom->currentText();
    QString corvacmode = ui->VacMode1_iacom->currentText();
    //QString polaspmode = ui->AspMode2_iacom->currentText();
    QString polvacmode = ui->VacMode2_iacom->currentText();
    QString surgeonid = ui->SelectSurgeon->currentText();

    // Prepare and execute the first query
//    QSqlQuery query;
//    query.prepare("UPDATE phacohigh SET ia1aspmax = :ia1aspmax, ia1vacmax = :ia1vacmax, ia2aspmax = :ia2aspmax, ia2vacmax = :ia2vacmax WHERE surgeon = :surgeonid");
//    query.bindValue(":ia1aspmax", ia1aspmax);
//    query.bindValue(":ia1vacmax", ia1vacmax);
//    query.bindValue(":ia2aspmax", ia2aspmax);
//    query.bindValue(":ia2vacmax", ia2vacmax);
//    query.bindValue(":surgeonid", surgeonid);

//    if (!query.exec()) {
//        qDebug() << "Error: Unable to update phacohigh (aspiration/vacuum) -" << query.lastError().text();
//        QMessageBox::warning(nullptr, "Error", "Failed to save aspiration and vacuum data");
//        mydb.close();
//        return;
//    }

    // Prepare and execute the second query
    QSqlQuery query2;
//    query2.prepare("UPDATE phacohigh SET cortexaspmode = :coraspmode, cortextvacmode = :corvacmode, polishaspmode = :polaspmode, polishvacmode = :polvacmode WHERE surgeon = :surgeonid");
//    query2.bindValue(":coraspmode", coraspmode);
//    query2.bindValue(":corvacmode", corvacmode);
//    query2.bindValue(":polaspmode", polaspmode);
//    query2.bindValue(":polvacmode", polvacmode);
//    query2.bindValue(":surgeonid", surgeonid);

    if (!query2.exec()) {
        qDebug() << "Error: Unable to update phacohigh (modes) -" << query2.lastError().text();
        QMessageBox::warning(nullptr, "Error", "Failed to save mode data");
        mydb.close();
        return;
    }

    // Notify the user of a successful save
    QMessageBox::information(nullptr, "Info", "Saved Successfully");
    mydb.close();
}


void doctor::VitSaveBut()
{
    // Open a SQLite database connection
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1); // Use the correct path for your database

    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database -" << mydb.lastError().text();
        QMessageBox::warning(nullptr, "Error", "Unable to open database");
        return;
    }

    // Retrieve input values from the UI
    QString surgeonid = ui->SelectSurgeon->currentText();
    QString vcutmax = ui->lineEdit->text();
    QString vvacmax = ui->lineEdit_19->text();
    QString vcutmode = ui->CutMode_vitCom->currentText();
    QString vvacmode = ui->VacMode_VitCom->currentText();


    // Prepare the SQL query
    QSqlQuery query;
//    query.prepare("UPDATE phacohigh SET vitcutmax = :vcutmax, vitvacmax = :vvacmax, vitcutmode = :vcutmode, vitvacmode = :vvacmode, vitaspmax = :vitaspmax WHERE surgeon = :surgeonid");
//    query.bindValue(":vcutmax", vcutmax);
//    query.bindValue(":vvacmax", vvacmax);
//    query.bindValue(":vcutmode", vcutmode);
//    query.bindValue(":vvacmode", vvacmode);
//    query.bindValue(":vitaspmax", vitaspmax);
//    query.bindValue(":surgeonid", surgeonid);

    // Execute the query and handle errors
    if (!query.exec()) {
        qDebug() << "Error: Unable to update data -" << query.lastError().text();
        QMessageBox::warning(nullptr, "Error", "Failed to save vitreous data");
        mydb.close(); // Ensure the database is closed before returning
        return;
    }

    // Notify the user of a successful save
    QMessageBox::information(nullptr, "Info", "Saved Successfully");
    mydb.close();
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
void doctor::clickedtab(int tab1)
{
    QString styleSheet = "QPushButton {"

            "background-color:black;"
            "color:white;"
            "border:2px solid black;"
            "font:bold;"// Adjust the radius as needed
                                 "}";
    QString styleSheet1 = "QPushButton {"

            "background-color:white;"
            "color:black;"
            "border:2px solid black;"
            "font:bold;"// Adjust the radius as needed
                                 "}";
    if (tab1!=0) {
        ui->EpinBut_phaco->setStyleSheet("");
   ui->EpinBut_phaco->setStyleSheet(styleSheet1);
    }
    if(tab1!=1)
    {
        ui->QuadBut_phaco->setStyleSheet("");
          ui->QuadBut_phaco->setStyleSheet(styleSheet1);
    }
    if(tab1!=2){
        ui->ChopBut_phaco->setStyleSheet("");
          ui->ChopBut_phaco->setStyleSheet(styleSheet1);
    }
    if(tab1!=3){
    ui->ScupltBut_phaco->setStyleSheet("");
     ui->ScupltBut_phaco->setStyleSheet(styleSheet1);
    }

    if (tab1 == 0) {
    ui->EpinBut_phaco->setStyleSheet(styleSheet);
    } else if (tab1 == 1) {
     ui->QuadBut_phaco->setStyleSheet(styleSheet);
    }                                                                      //set color
    else if(tab1==2){
         ui->ChopBut_phaco->setStyleSheet(styleSheet);
    }
    else if(tab1==3){
         ui->ScupltBut_phaco->setStyleSheet(styleSheet);
    }

}





void doctor::on_EpinBut_phaco_clicked()
{
     ui->tabWidget_2->setCurrentIndex(0);
}

void doctor::on_QuadBut_phaco_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);
}

void doctor::on_ChopBut_phaco_clicked()
{
    ui->tabWidget_2->setCurrentIndex(2);
}

void doctor::on_ScupltBut_phaco_clicked()
{
    ui->tabWidget_2->setCurrentIndex(3);
}

int doctor::getvalue(int input)
{
    if (input <= 60) {
        return 60;
    } else {
        int remainder = input % 60; // Calculate the remainder when dividing by 60

        if (remainder < 30) {
            // Round down to the nearest multiple of 60
            return (input / 60) * 60;
        } else {
            // Round up to the next multiple of 60
            return ((input / 60) + 1) * 60;
        }
    }
}

void doctor::on_pushButton_clicked()
{
   QString value=ui->comboBox->currentText();
   QString value1=ui->SelectSurgeon->currentText();
   int dia=ui->lineEdit_6->text().toInt();
   int us1pow=ui->lineEdit_4->text().toInt();
   int us1vac=ui->lineEdit_3->text().toInt();
int us1asp=ui->lineEdit_2->text().toInt();
int us2pow=ui->lineEdit_10->text().toInt();
int us2vac=ui->lineEdit_9->text().toInt();
int us2asp=ui->lineEdit_8->text().toInt();
int us3pow=ui->lineEdit_15->text().toInt();
int us3vac=ui->lineEdit_14->text().toInt();
int us3asp=ui->lineEdit_13->text().toInt();
int us4pow=ui->lineEdit_18->text().toInt();
int us4vac=ui->lineEdit_17->text().toInt();
int us4asp=ui->lineEdit_16->text().toInt();
int ia1vac=ui->lineEdit_7->text().toInt();
int ia1asp=ui->lineEdit_5->text().toInt();
int ia2vac=ui->lineEdit_11->text().toInt();
int ia2asp=ui->lineEdit_12->text().toInt();
int vitcut=ui->lineEdit->text().toInt();
int vitvac=ui->lineEdit_19->text().toInt();
int vitasp=ui->lineEdit_20->text().toInt();
 QString powmode=ui->PowModeCom_phaco->currentText();
 QString vacmode=ui->VacModeCom_phaco->currentText();
 QString powmethod=ui->PowMethodCom_phaco->currentText();
 QString us2powmode=ui->PowModeCom_phaco_2->currentText();
 QString us2vacmode=ui->VacModeCom_phaco_2->currentText();
 QString us2powermethod=ui->PowMethodCom_phaco_2->currentText();
 QString us3powmode=ui->PowModeCom_phaco_3->currentText();
 QString us3vacmode=ui->VacModeCom_phaco_3->currentText();
 QString us3powermethod=ui->PowMethodCom_phaco_3->currentText();
 QString us4powmode=ui->PowModeCom_phaco_4->currentText();
 QString us4vacmode=ui->VacModeCom_phaco_4->currentText();
 QString us4powermethod=ui->PowMethodCom_phaco_4->currentText();
 QString ia1mode=ui->VacMode1_iacom->currentText();
QString ia2mode=ui->VacMode2_iacom->currentText();
QString vitmode=ui->CutMode_vitCom->currentText();
QString vitvacmode=ui->VacMode_VitCom->currentText();
QString footleft=ui->LeftFoot->currentText();
QString footright=ui->RightFoot->currentText();
QString b_left=ui->BottomLFoot->currentText();
QString b_right=ui->BottomRFoot->currentText();
// Check and clear existing default connection
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

    // Open database connection with a unique name
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE", "unique_connection_name");
    mydb.setDatabaseName(PATH1);

    // Check if the QSQLITE driver is available
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << "Available drivers:" << drivers;

    if (!drivers.contains("QSQLITE")) {
        qDebug() << "Error: QSQLITE driver not available!";
        return;
    }

    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database with path:" << PATH1;
        return;
    }

    // Prepare SQL query with placeholders
    QSqlQuery query(mydb);  // Use the specific connection
    query.prepare("SELECT * FROM phacohigh WHERE surgeon = :surgeon");

    // Bind values to the placeholders
    QString surgeon = ui->SelectSurgeon->currentText();
    query.bindValue(":surgeon", surgeon);

    // Debug: Log the query and bound values
    qDebug() << "Executing query: SELECT * FROM phacohigh WHERE surgeon =" << surgeon;

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error executing SELECT query: " << query.lastError().text();
        return;
    }

    // Check if any rows are fetched
    if (!query.next()) {
        qDebug() << "No rows fetched for surgeon:" << surgeon;
        return;
    }

    query.prepare("UPDATE phacohigh SET "
                  "diapowmax = :diapowmax, pump = :pump, Epinaspmax = :Epinaspmax, Epinvacmax = :Epinvacmax, "
                  "Epinpowmax = :Epinpowmax, quadpowmax = :quadpowmax, quadvacmax = :quadvacmax, "
                  "quadaspmax = :quadaspmax, Quadvacmode = :Quadvacmode, Quadpowermethod = :Quadpowermethod, "
                  "Quadpowmode = :Quadpowmode, caspmax = :caspmax, cvacmax = :cvacmax, cpowmax = :cpowmax, "
                  "Chopvacmode = :Chopvacmode, Choppowermethod = :Choppowermethod, Choppowmode = :Choppowmode, "
                  "saspmax = :saspmax, svacmax = :svacmax, spowmax = :spowmax, Sculptvacmode = :Sculptvacmode, "
                  "Sculptpowermethod = :Sculptpowermethod, Sculptpowmode = :Sculptpowmode, "
                  "cortexaspmode = :cortexaspmode, cortexvacmode = :cortexvacmode, polishaspmode = :polishaspmode, "
                  "polishvacmode = :polishvacmode, ia1aspmax = :ia1aspmax, ia1vacmax = :ia1vacmax, "
                  "ia2aspmax = :ia2aspmax, ia2vacmax = :ia2vacmax, vitcutmax = :vitcutmax, vitvacmax = :vitvacmax, "
                  "vitaspmax = :vitaspmax, vitcutmode = :vitcutmode, vitvacmode = :vitvacmode, "
                  "footleft = :footleft, footright = :footright, footbottomleft = :footbottomleft, footbottomright = :footbottomright, "
                  "Epinpowermethod = :Epinpowermethod, Epinpowmode = :Epinpowmode, Epinvacmode = :Epinvacmode "
                  "WHERE surgeon = :surgeon");

    // Bind values to the placeholders
    query.bindValue(":diapowmax", ui->lineEdit_6->text().toInt());
    query.bindValue(":pump", ui->comboBox->currentText());
    query.bindValue(":Epinaspmax", ui->lineEdit_2->text().toInt());
    query.bindValue(":Epinvacmax", ui->lineEdit_3->text().toInt());
    query.bindValue(":Epinpowmax", ui->lineEdit_4->text().toInt());
    query.bindValue(":quadpowmax", ui->lineEdit_10->text().toInt());
    query.bindValue(":quadvacmax", ui->lineEdit_9->text().toInt());
    query.bindValue(":quadaspmax", ui->lineEdit_8->text().toInt());
    query.bindValue(":Quadvacmode", ui->VacModeCom_phaco_2->currentText());
    query.bindValue(":Quadpowermethod", ui->PowMethodCom_phaco_2->currentText());
    query.bindValue(":Quadpowmode", ui->PowModeCom_phaco_2->currentText());
    query.bindValue(":caspmax", ui->lineEdit_13->text().toInt());
    query.bindValue(":cvacmax", ui->lineEdit_14->text().toInt());
    query.bindValue(":cpowmax", ui->lineEdit_15->text().toInt());
    query.bindValue(":Chopvacmode", ui->VacModeCom_phaco_3->currentText());
    query.bindValue(":Choppowermethod", ui->PowMethodCom_phaco_3->currentText());
    query.bindValue(":Choppowmode", ui->PowModeCom_phaco_3->currentText());
    query.bindValue(":saspmax", ui->lineEdit_16->text().toInt());
    query.bindValue(":svacmax", ui->lineEdit_17->text().toInt());
    query.bindValue(":spowmax", ui->lineEdit_18->text().toInt());
    query.bindValue(":Sculptvacmode", ui->VacModeCom_phaco_4->currentText());
    query.bindValue(":Sculptpowermethod", ui->PowMethodCom_phaco_4->currentText());
    query.bindValue(":Sculptpowmode", ui->PowModeCom_phaco_4->currentText());
    query.bindValue(":cortexaspmode", ui->VacModeCom_phaco_4->currentText());
    query.bindValue(":cortexvacmode", ui->VacModeCom_phaco_4->currentText());
    query.bindValue(":polishaspmode", ui->PowMethodCom_phaco_4->currentText());
    query.bindValue(":polishvacmode", ui->VacModeCom_phaco_4->currentText());
    query.bindValue(":ia1aspmax", ui->lineEdit_7->text().toInt());
    query.bindValue(":ia1vacmax", ui->lineEdit_5->text().toInt());
    query.bindValue(":ia2aspmax", ui->lineEdit_12->text().toInt());
    query.bindValue(":ia2vacmax", ui->lineEdit_11->text().toInt());
    query.bindValue(":vitcutmax", ui->lineEdit->text().toInt());
    query.bindValue(":vitvacmax", ui->lineEdit_19->text().toInt());
    query.bindValue(":vitaspmax", ui->lineEdit_20->text().toInt());
    query.bindValue(":vitcutmode", ui->CutMode_vitCom->currentText());
    query.bindValue(":vitvacmode", ui->VacMode_VitCom->currentText());
    query.bindValue(":Epinpowermethod", ui->PowMethodCom_phaco->currentText());
    query.bindValue(":Epinpowmode", ui->PowModeCom_phaco->currentText());
    query.bindValue(":Epinvacmode", ui->VacModeCom_phaco->currentText());
    query.bindValue(":footleft", ui->LeftFoot->currentText());
    query.bindValue(":footright", ui->RightFoot->currentText());
    query.bindValue(":footbottomleft", ui->BottomLFoot->currentText());
    query.bindValue(":footbottomright", ui->BottomRFoot->currentText());
    query.bindValue(":surgeon", surgeon);

    // Debug: Log the update query and bound values
    qDebug() << "Executing update query for surgeon:" << surgeon;

    // Execute the update query
    if (!query.exec()) {
        qDebug() << "Error executing UPDATE query: " << query.lastError().text();
    } else {
        qDebug() << "Data updated successfully.";
        QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Info", "Surgeon is updated");

        // Set the message box to show
        msgBox->show();

        // Create a QTimer to close the message box after 500 ms
        QTimer::singleShot(700, msgBox, [msgBox]() {
            msgBox->hide();  // Hide the message box
            delete msgBox;   // Delete the message box to free memory

    });
    }


emit sendValues(
    value,value1, dia, us1pow, us1vac, us1asp,
    us2pow, us2vac, us2asp, us3pow, us3vac, us3asp,
    us4pow, us4vac, us4asp, ia1vac, ia1asp,
    ia2vac, ia2asp, vitcut, vitvac, vitasp,
    powmode, vacmode, powmethod,
    us2powmode, us2vacmode, us2powermethod,
    us3powmode, us3vacmode, us3powermethod,
    us4powmode, us4vacmode, us4powermethod,
    ia1mode, ia2mode, vitmode, vitvacmode
);
emit sendleftfootvalues(ui->LeftFoot->currentText());
    qDebug()<<"footleft is"<<footleft;
    emit sendrightfootvalues(ui->RightFoot->currentText());
      qDebug()<<"footright is"<<footright;
    emit sendbleftfootvalues(ui->BottomLFoot->currentText());
    qDebug()<<"footbottom left is"<<b_left;
    emit sendbrightfootvalues(ui->BottomRFoot->currentText());
    qDebug()<<"footbottom right is"<<b_right;
    this->close();
}

void doctor::pumpvalue()
{
    QString value=ui->comboBox->currentText();


}

void doctor::on_SaveDiaBut_clicked()
{
    QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, "Info", "Values are updated");

    // Set the message box to show
    msgBox->show();

    // Create a QTimer to close the message box after 500 ms
    QTimer::singleShot(1000, msgBox, [msgBox]() {
        msgBox->hide();  // Hide the message box
        delete msgBox;   // Delete the message box to free memory

});
   on_pushButton_clicked();
   this->close();
}

void doctor::on_savefootpedal_clicked()
{

}
