#include "doctor.h"
#include "ui_doctor.h"
#include<QMessageBox>
#include<QTimer>
doctor::doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doctor)
{
    ui->setupUi(this);
      connect(ui->SaveDiaBut,&QPushButton::clicked,this,&doctor::DiaSaveBut);
      connect(ui->IASaveBut,&QPushButton::clicked,this,&doctor::IASaveBut);
      connect(ui->savevitbut,&QPushButton::clicked,this,&doctor::VitSaveBut);
      //connect(ui->SavePhacoBut_phaco,&QPushButton::clicked,this,&doctor::PhacoSaveBut);
    move(0,0);
    timer=new QTimer;
    QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; }";
    ui->tabWidget_2->setStyleSheet(tabStyle);
         connect(ui->tabWidget_2, &QTabWidget::currentChanged, this, &doctor::clickedtab);
          clickedtab(ui->tabWidget_2->currentIndex());


    message=new QMessageBox(this);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName(PATH1);
       mydb.open();
    surgeonid=ui->SelectSurgeon->currentText();

  //  connect(this,&doctor::valueSaved,m,&MainWindow::onMainLineEditTextChanged);
   //connect(ui->lineEdit_4,&QLineEdit::textChanged,this,&doctor::dialine);

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
     connect(ui->SelectSurgeon, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &doctor::current);
    connect(ui->comboBox,&QComboBox::currentTextChanged, this, &doctor::trasmitcomboBox);
     ui->lineEdit_6->setText("100");
  ui->lineEdit_2->setText("40");
  ui->lineEdit_3->setText("500");
  ui->lineEdit_4->setText("100");
  ui->lineEdit_5->setText("500");
  ui->lineEdit_7->setText("40");
  ui->lineEdit_11->setText("500");
  ui->lineEdit_12->setText("40");
  ui->lineEdit->setText("100");
  ui->lineEdit_19->setText("500");
  ui->lineEdit_20->setText("40");
  ui->lineEdit_2->setText("22");
  ui->lineEdit_3->setText("200");
  ui->lineEdit_4->setText("60");

  // Set default values to UI elements
  ui->lineEdit_8->setText("22");
  ui->lineEdit_10->setText("200");
  ui->lineEdit_9->setText("50");

  ui->lineEdit_14->setText("26");
    ui->lineEdit_15->setText("200");
    ui->lineEdit_13->setText("60");

  ui->lineEdit_17->setText("16");
     ui->lineEdit_16->setText("150");
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


  connect(ui->DiaBut,&QPushButton::clicked,this,&doctor::DiathermyBut);
  connect(ui->PhacoBut,&QPushButton::clicked,this,&doctor::PhacoBut);
  connect(ui->IABut,&QPushButton::clicked,this,&doctor::IrrigationAspirationBut);
  connect(ui->VitBut,&QPushButton::clicked,this,&doctor::VitrectomyBut);
  //connect(ui->SaveDiaBut,&QPushButton::clicked,this,&doctor::DiaSaveBut);
  connect(ui->SavePhacoBut_phaco,&QPushButton::clicked,this,&doctor::PhacoSaveBut);
//  connect(ui->IABut,&QPushButton::clicked,this,&doctor::IASaveBut);
  connect(ui->savevitbut,&QPushButton::clicked,this,&doctor::VitSaveBut);

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
        // userMessage(value,5,100);
        increasebutton(ui->lineEdit_6);



    }
    //phaco
     if(ui->lineEdit_2->focusWidget()) {
        ui->lineEdit_3->clearFocus();
        ui->lineEdit_4->clearFocus();
        ui->lineEdit_2->setFocus();
        int prevValue = ui->lineEdit_2->text().toInt();
        int value1 = (ui->lineEdit_2->text()+digit).toInt();
        setRange(ui->lineEdit_2, prevValue, value1, 40);
        //userMessage(value,5,500);
        decreasebutton(ui->lineEdit_2);
    }
    if(ui->lineEdit_3->focusWidget()) {
        ui->lineEdit_2->clearFocus();
        ui->lineEdit_4->clearFocus();
        ui->lineEdit_3->setFocus();
        int prevValue = ui->lineEdit_3->text().toInt();
        int value2 = (ui->lineEdit_3->text()+digit).toInt();
        setRange(ui->lineEdit_3, prevValue, value2, 500);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_3);
    }
     if(ui->lineEdit_4->focusWidget()) {
        ui->lineEdit_2->clearFocus();
        ui->lineEdit_3->clearFocus();
        ui->lineEdit_4->setFocus();
        int prevValue = ui->lineEdit_4->text().toInt();
        int value3 = (ui->lineEdit_4->text()+digit).toInt();
        setRange(ui->lineEdit_4, prevValue, value3, 100);
        //userMessage(value,5,100);
        increasebutton(ui->lineEdit_4);
    }
     //quad
     if(ui->lineEdit_8->focusWidget()) {
        ui->lineEdit_9->clearFocus();
        ui->lineEdit_10->clearFocus();
        ui->lineEdit_8->setFocus();
        int prevValue = ui->lineEdit_8->text().toInt();
        int value1 = (ui->lineEdit_8->text()+digit).toInt();
        setRange(ui->lineEdit_8, prevValue, value1, 40);
        //userMessage(value,5,500);
        decreasebutton(ui->lineEdit_8);
    }
    if(ui->lineEdit_10->focusWidget()) {
        ui->lineEdit_9->clearFocus();
        ui->lineEdit_8->clearFocus();
        ui->lineEdit_10->setFocus();
        int prevValue = ui->lineEdit_10->text().toInt();
        int value2 = (ui->lineEdit_10->text()+digit).toInt();
        setRange(ui->lineEdit_10, prevValue, value2, 500);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_10);
    }
     if(ui->lineEdit_9->focusWidget()) {
        ui->lineEdit_10->clearFocus();
        ui->lineEdit_8->clearFocus();
        ui->lineEdit_9->setFocus();
        int prevValue = ui->lineEdit_9->text().toInt();
        int value3 = (ui->lineEdit_9->text()+digit).toInt();
        setRange(ui->lineEdit_9, prevValue, value3, 100);
        //userMessage(value,5,100);
        increasebutton(ui->lineEdit_9);
    }
     //chop

     if(ui->lineEdit_13->focusWidget()) {
        ui->lineEdit_15->clearFocus();
        ui->lineEdit_14->clearFocus();
        ui->lineEdit_13->setFocus();
        int prevValue = ui->lineEdit_13->text().toInt();
        int value1 = (ui->lineEdit_13->text()+digit).toInt();
        setRange(ui->lineEdit_13, prevValue, value1, 40);
        //userMessage(value,5,500);
        decreasebutton(ui->lineEdit_13);
    }
    if(ui->lineEdit_14->focusWidget()) {
        ui->lineEdit_13->clearFocus();
        ui->lineEdit_15->clearFocus();
        ui->lineEdit_14->setFocus();
        int prevValue = ui->lineEdit_14->text().toInt();
        int value2 = (ui->lineEdit_14->text()+digit).toInt();
        setRange(ui->lineEdit_14, prevValue, value2, 100);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_14);
    }
     if(ui->lineEdit_15->focusWidget()) {
        ui->lineEdit_13->clearFocus();
        ui->lineEdit_14->clearFocus();
        ui->lineEdit_15->setFocus();
        int prevValue = ui->lineEdit_15->text().toInt();
        int value3 = (ui->lineEdit_15->text()+digit).toInt();
        setRange(ui->lineEdit_15, prevValue, value3, 500);
        //userMessage(value,5,100);
        increasebutton(ui->lineEdit_15);
    }
     //sculpt
     if(ui->lineEdit_16->focusWidget()) {
        ui->lineEdit_17->clearFocus();
        ui->lineEdit_18->clearFocus();
        ui->lineEdit_16->setFocus();
        int prevValue = ui->lineEdit_16->text().toInt();
        int value1 = (ui->lineEdit_16->text()+digit).toInt();
        setRange(ui->lineEdit_16, prevValue, value1, 40);
        //userMessage(value,5,500);
        decreasebutton(ui->lineEdit_16);
    }
    if(ui->lineEdit_18->focusWidget()) {
        ui->lineEdit_16->clearFocus();
        ui->lineEdit_17->clearFocus();
        ui->lineEdit_18->setFocus();
        int prevValue = ui->lineEdit_18->text().toInt();
        int value2 = (ui->lineEdit_18->text()+digit).toInt();
        setRange(ui->lineEdit_18, prevValue, value2, 500);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_18);
    }
     if(ui->lineEdit_17->focusWidget()) {
        ui->lineEdit_16->clearFocus();
        ui->lineEdit_18->clearFocus();
        ui->lineEdit_17->setFocus();
        int prevValue = ui->lineEdit_17->text().toInt();
        int value3 = (ui->lineEdit_17->text()+digit).toInt();
        setRange(ui->lineEdit_17, prevValue, value3, 100);
        //userMessage(value,5,100);
        increasebutton(ui->lineEdit_17);

      }



    //irrigation
   if(ui->lineEdit_5->focusWidget()) {
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_5->setFocus();
        int prevValue = ui->lineEdit_5->text().toInt();
        int value4 = (ui->lineEdit_5->text()+digit).toInt();
        setRange(ui->lineEdit_5, prevValue, value4, 40);
      //  userMessage(value,5,500);
        decreasebutton(ui->lineEdit_5);
    }
   if(ui->lineEdit_7->focusWidget()) {
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_7->setFocus();
        int prevValue = ui->lineEdit_7->text().toInt();
        int value5 = (ui->lineEdit_7->text()+digit).toInt();
        setRange(ui->lineEdit_7, prevValue, value5, 500);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_7);
    }
     if(ui->lineEdit_12->focusWidget()) {
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->clearFocus();
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_12->setFocus();
        int prevValue = ui->lineEdit_12->text().toInt();
        int value6 = (ui->lineEdit_12->text()+digit).toInt();
        setRange(ui->lineEdit_12, prevValue, value6, 40);
       // userMessage(value,5,500);
        decreasebutton(ui->lineEdit_12);
    }
    if(ui->lineEdit_11->focusWidget()) {
        ui->lineEdit_7->clearFocus();
        ui->lineEdit_12->clearFocus();
        ui->lineEdit_5->clearFocus();
        ui->lineEdit_11->setFocus();
        int prevValue = ui->lineEdit_11->text().toInt();
        int value7 = (ui->lineEdit_11->text()+digit).toInt();
        setRange(ui->lineEdit_11, prevValue, value7, 500);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_11);
    }
    //vitrectomy
    if(ui->lineEdit->focusWidget()) {
        ui->lineEdit_19->clearFocus();
        ui->lineEdit_20->clearFocus();
        //ui->lineEdit_12->clearFocus();
        ui->lineEdit->setFocus();
        int prevValue = ui->lineEdit->text().toInt();
        int value8 = (ui->lineEdit->text()+digit).toInt();
        setRange(ui->lineEdit, prevValue, value8, 960);
        //userMessage(value,60,960);
        //powervit();
    }
     if(ui->lineEdit_19->focusWidget()) {
        ui->lineEdit->clearFocus();
        ui->lineEdit_20->clearFocus();
        //ui->lineEdit_12->clearFocus();
        ui->lineEdit_19->setFocus();
        int prevValue = ui->lineEdit_19->text().toInt();
        int value9 = (ui->lineEdit_19->text()+digit).toInt();
        setRange(ui->lineEdit_19, prevValue, value9, 500);
        //userMessage(value,5,500);
        vacbutton(ui->lineEdit_19);
    }
    if(ui->lineEdit_20->focusWidget()) {
        ui->lineEdit->clearFocus();
        ui->lineEdit_19->clearFocus();
        //ui->lineEdit_12->clearFocus();
        ui->lineEdit_20->setFocus();
        int prevValue = ui->lineEdit_20->text().toInt();
        int value10 = (ui->lineEdit_20->text()+digit).toInt();
        setRange(ui->lineEdit_20, prevValue, value10, 40);
        decreasebutton(ui->lineEdit_20);
        //userMessage(value,5,500);
    }
}

void doctor::on_clickedenter()
{
    key->hide();
    int  input=ui->lineEdit->text().toInt();
    int output=getvalue(input);
    ui->lineEdit->setText(QString::number(output));
}


void doctor::increasebutton(QLineEdit *increaseline)
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

void doctor::decreasebutton(QLineEdit *decreaseline)
{

      int value1 = decreaseline->text().toInt();
      if(value1>=10){
      if (value1 % 2 != 0) {

               value1++;
           }
      }
      decreaseline->setText(QString::number(value1));
}

void doctor::vacbutton(QLineEdit *vacline)
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
void doctor::powervit()
{
//    int value = ui->lineEdit->text().toInt();

//     // Adjust the value based on the specified conditions
//     if (value >= 10) {
//         if (value % 2 == 0) {
//             // Round up even numbers to the next multiple of 60
//             value = ((value + 59) / 60) * 60;
//         }
//         else{
//             value = ((value + 59) / 60) * 60;
//         }
//     }

//     ui->lineEdit->setText(QString::number(value));
}

void doctor::dialine(const QString text)
{

    //emit valueSaved(ui->lineEdit_4->text());
}
void doctor::current(int index){

//    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
//    if (comboBox) {
//        QString action = comboBox->currentText();
//        emit selectioncom(action); // Emit the selected action
//    }
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

void doctor::trasmitcomboBox(const QString &text)
{

   emit transmitcombo(ui->comboBox->currentText());
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
    ui->tabWidget->setCurrentIndex(0);
   // ui->lineEdit_6->setText(QString::number(100));
   // QString value=ui->lineEdit_6->text();


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

    //parentWidget()->show();
}

void doctor::PhacoSaveBut()
{
}


void doctor::DiaSaveBut()
{
    int powmax = ui->lineEdit_6->text().toInt();
    //transmitter = powmax;

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QString surgeonid = ui->SelectSurgeon->currentText();

    QSqlQuery query;
    query.prepare("UPDATE phacohigh SET diapowmax = :diapowmax WHERE surgeon = :surgeon");
    query.bindValue(":diapowmax", powmax);
    query.bindValue(":surgeon", surgeonid);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Info", "Saved Successfully");
         //emit dia(surgeonid,powmax);
onSaveButtonClicked(4);
        qDebug()<<surgeonid<<powmax;

        //  emit selection(surgeonid);
    } else {
       // qDebug() << "Error: Failed to update database -" << query.lastError();
        QMessageBox::warning(nullptr, "Error", "Failed to save data");

   }

    mydb.close();
}

void doctor::IASaveBut()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QString ia1aspmax = ui->lineEdit_5->text();
    QString ia1vacmax = ui->lineEdit_7->text();
    QString ia2aspmax = ui->lineEdit_12->text();
    QString ia2vacmax = ui->lineEdit_11->text();
    QString coraspmode = ui->AspMode_iacom->currentText();
    QString corvacmode = ui->VacMode1_iacom->currentText();
    QString polaspmode = ui->AspMode2_iacom->currentText();
    QString polvacmode = ui->VacMode2_iacom->currentText();
    QString surgeonid = ui->SelectSurgeon->currentText();

    QSqlQuery query;
    query.prepare("UPDATE phacohigh SET ia1aspmax = :ia1aspmax, ia1vacmax = :ia1vacmax, ia2aspmax = :ia2aspmax, ia2vacmax = :ia2vacmax WHERE surgeon = :surgeonid");
    query.bindValue(":ia1aspmax", ia1aspmax);
    query.bindValue(":ia1vacmax", ia1vacmax);
    query.bindValue(":ia2aspmax", ia2aspmax);
    query.bindValue(":ia2vacmax", ia2vacmax);
    query.bindValue(":surgeonid", surgeonid);

    QSqlQuery query2;
    query2.prepare("UPDATE phacohigh SET cortexaspmode = :coraspmode, cortextvacmode = :corvacmode, polishaspmode = :polaspmode, polishvacmode = :polvacmode WHERE surgeon = :surgeonid");
    query2.bindValue(":coraspmode", coraspmode);
    query2.bindValue(":corvacmode", corvacmode);
    query2.bindValue(":polaspmode", polaspmode);
    query2.bindValue(":polvacmode", polvacmode);
    query2.bindValue(":surgeonid", surgeonid);

    if (!query.exec()) {
       // qDebug() << "Error: Unable to update data - " << query.lastError();
        return;
    }

    if (!query2.exec()) {
        //qDebug() << "Error: Unable to update data - " << query2.lastError();
        return;
    }

    QMessageBox::information(nullptr, "Info", "Saved Successfully");
    onSaveButtonClicked(5);

  //  emit selection(surgeonid);

    mydb.close();
}

void doctor::VitSaveBut()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QString surgeonid = ui->SelectSurgeon->currentText();
    QString vcutmax = ui->lineEdit->text();
    QString vvacmax = ui->lineEdit_19->text();
    QString vcutmode = ui->CutMode_vitCom->currentText();
    QString vvacmode = ui->VacMode_VitCom->currentText();
    QString vitaspmax = ui->lineEdit_20->text();

    QSqlQuery query;
    query.prepare("UPDATE phacohigh SET vitcutmax = :vcutmax, vitvacmax = :vvacmax, vitcutmode = :vcutmode, vitvacmode = :vvacmode, vitaspmax = :vitaspmax WHERE surgeon = :surgeonid");
    query.bindValue(":vcutmax", vcutmax);
    query.bindValue(":vvacmax", vvacmax);
    query.bindValue(":vcutmode", vcutmode);
    query.bindValue(":vvacmode", vvacmode);
    query.bindValue(":vitaspmax", vitaspmax);
    query.bindValue(":surgeonid", surgeonid);

    if (!query.exec()) {
     //   qDebug() << "Error: Unable to update data - " << query.lastError();
        return;
    }

    QMessageBox::information(nullptr, "Info", "Saved Successfully");
    onSaveButtonClicked(6);

    //emit selection(surgeonid);
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




void doctor::on_SavePhacoBut_phaco_2_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }



    // Retrieve values from UI elements
    QString surgeonid = ui->SelectSurgeon->currentText();
    int qaspmax = ui->lineEdit_8->text().toInt();
    int qvacmax = ui->lineEdit_10->text().toInt();
    int qpowmax = ui->lineEdit_9->text().toInt();
    QString qvac = ui->VacModeCom_phaco_2->currentText();
    QString qpowmethod = ui->PowMethodCom_phaco_2->currentText();
    QString qpowmod = ui->PowModeCom_phaco_2->currentText();

    // Validate input values (example validation, adjust as needed)


    // Prepare SQL query to update the database
    QSqlQuery query;
    query.prepare("UPDATE phacohigh SET quadaspmax = :quadaspmax, quadvacmax = :quadvacmax, quadpowmax = :quadpowmax, Quadvacmode = :qvac, Quadpowermethod = :qpowmethod, Quadpowmode = :qpowmode WHERE surgeon = :surgeon");
    query.bindValue(":quadaspmax", qaspmax);
    query.bindValue(":quadvacmax", qvacmax);
    query.bindValue(":quadpowmax", qpowmax);
    query.bindValue(":Quadvacmode", qvac);
    query.bindValue(":Quadpowermethod", qpowmethod);
    query.bindValue(":Quadpowmode", qpowmod);
    query.bindValue(":surgeon", surgeonid);

    // Debug log the parameters
    qDebug() << "Quad parameters:" << qaspmax << qvacmax << qpowmax;
    qDebug() << qvac << qpowmethod << qpowmod;

    // Execute the query and check for errors
    if (!query.exec()) {
      //  qDebug() << "Error: Unable to update database -" << query.lastError();
    } else {
        qDebug() << "Quad data saved successfully";
        onSaveButtonClicked(1);



        // Emit signals with updated values

    }

    // Close the database connection
    mydb.close();

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


void doctor::on_SavePhacoBut_phaco_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }


    QString surgeonid = ui->SelectSurgeon->currentText();
 int epinaspmax = ui->lineEdit_2->text().toInt();
    int epinvacmax = ui->lineEdit_3->text().toInt();
    int epinpowmax = ui->lineEdit_4->text().toInt();
    QString epinvac = ui->VacModeCom_phaco->currentText();
    QString epinpowmethod = ui->PowMethodCom_phaco->currentText();
    QString epinpowmod = ui->PowModeCom_phaco->currentText();

   QSqlQuery query;

    query.prepare("UPDATE phacohigh SET Epinaspmax = :epinaspmax, Epinvacmax = :epinvacmax, Epinpowmax = :epinpowmax, Epinvacmode = :epinvac, Epinpowermethod = :epinpowmethod, Epinpowmode = :epinpowmod WHERE surgeon = :surgeon");
    query.bindValue(":epinaspmax", epinaspmax);
    query.bindValue(":epinvacmax", epinvacmax);
    query.bindValue(":epinpowmax", epinpowmax);
    query.bindValue(":epinvac", epinvac);
    query.bindValue(":epinpowmethod", epinpowmethod);
    query.bindValue(":epinpowmod", epinpowmod);
    query.bindValue(":surgeon", surgeonid);

    qDebug() << "Epinucleus parameters:" << epinaspmax << epinvacmax << epinpowmax;
    qDebug()<<epinvac<<epinpowmod<<epinpowmethod;

    if (!query.exec()) {
        //qDebug() << "Error: Unable to update database -" << query.lastError();
    } else {
        qDebug() << "Epinucleus data saved successfully";
        onSaveButtonClicked(0);


        qDebug()<<surgeonid<<epinpowmax<<epinvacmax<<epinaspmax;

    }

    mydb.close();
}

void doctor::on_SavePhacoBut_phaco_3_clicked()
{
    int caspmax = ui->lineEdit_14->text().toInt();
    int cvacmax = ui->lineEdit_13->text().toInt();
    int cpowmax = ui->lineEdit_15->text().toInt();
    QString cvacmode = ui->VacModeCom_phaco_3->currentText();
    QString cpowmethod = ui->PowMethodCom_phaco_3->currentText();
    QString cpowmod = ui->PowModeCom_phaco_3->currentText();
    QString surgeonid = ui->SelectSurgeon->currentText();

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE phacohigh SET caspmax = :caspmax, cvacmax = :cvacmax, cpowmax = :cpowmax, Chopvacmode = :cvacmode, Choppowermethod = :cpowmethod, Choppowmode = :cpowmode WHERE surgeon = :surgeon");
    query.bindValue(":caspmax", caspmax);
    query.bindValue(":cvacmax", cvacmax);
    query.bindValue(":cpowmax", cpowmax);
    query.bindValue(":Chopvacmode", cvacmode);
    query.bindValue(":Choppowermethod", cpowmethod);
    query.bindValue(":Choppowmdoe", cpowmod);
    query.bindValue(":surgeon", surgeonid);

    if (!query.exec()) {
        //qDebug() << "Error: Unable to update database -" << query.lastError();
        return;
    }else{
        qDebug()<<"saved successfully";
        onSaveButtonClicked(2);
   }

    mydb.close();
    qDebug() << "Chop values saved:" << caspmax << cvacmax << cpowmax;
    qDebug()<<cvacmode<<cpowmethod<<cpowmod;


}

void doctor::on_SavePhacoBut_phaco_4_clicked()
{

   int saspmax = ui->lineEdit_17->text().toInt();
    int svacmax = ui->lineEdit_16->text().toInt();
    int spowmax = ui->lineEdit_18->text().toInt();
    QString svacmode = ui->VacModeCom_phaco_4->currentText();
    QString spowmethod = ui->PowMethodCom_phaco_4->currentText();
    QString spowmod = ui->PowModeCom_phaco_4->currentText();
    QString surgeonid = ui->SelectSurgeon->currentText();

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(PATH1);
    if (!mydb.open()) {
        qDebug() << "Error: Unable to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE phacohigh SET saspmax = :saspmax, svacmax = :svacmax, spowmax = :spowmax, Sculptvacmode = :svacmode, Sculptpowermethod = :spowmethod, Sculptpowmode = :spowmode WHERE surgeon = :surgeon");
    query.bindValue(":saspmax", saspmax);
    query.bindValue(":svacmax", svacmax);
    query.bindValue(":spowmax", spowmax);
    query.bindValue(":Sculptvacmode", svacmode);
    query.bindValue(":Sculptpowermethod", spowmethod);
    query.bindValue(":Sculptpowmode", spowmod);
    query.bindValue(":surgeon", surgeonid);

    if (!query.exec()) {
     //   qDebug() << "Error: Unable to update database -" << query.lastError();
        return;
    }else{
        qDebug()<<"saved successfully";
        onSaveButtonClicked(3);

    }

    mydb.close();
    qDebug() << "Sculpt values saved:" << saspmax << svacmax << spowmax;
    qDebug()<<svacmode<<spowmethod<<spowmod;
}
void doctor::onSaveButtonClicked(int tabIndex)
{
    QString surgeon = ui->SelectSurgeon->currentText();
    QStringList values;
//phaco
    if (tabIndex == 0)
    {
        values << ui->lineEdit_4->text() << ui->lineEdit_3->text() << ui->lineEdit_2->text()
               << ui->PowMethodCom_phaco->currentText()<<ui->PowModeCom_phaco->currentText() << ui->VacModeCom_phaco->currentText();
    }
    else if (tabIndex == 1)
    {
        values << ui->lineEdit_9->text() << ui->lineEdit_10->text() << ui->lineEdit_8->text()
               << ui->PowMethodCom_phaco_2->currentText() <<ui->PowModeCom_phaco_2->currentText()<< ui->VacModeCom_phaco_2->currentText();
    }
    else if (tabIndex == 2)
    {
        values << ui->lineEdit_14->text() << ui->lineEdit_15->text() << ui->lineEdit_13->text()
               << ui->PowMethodCom_phaco_3->currentText() << ui->PowModeCom_phaco_3->currentText()<<ui->VacModeCom_phaco_3->currentText();
    }
    else if (tabIndex == 3)
    {
        values << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_16->text()
               << ui->PowMethodCom_phaco_4->currentText() <<ui->PowModeCom_phaco_4->currentText()<< ui->VacModeCom_phaco_4->currentText();
    }
    //diathermy
    else if(tabIndex ==4 )
    {
       values << ui->lineEdit_6->text();
    }
    //irrigaiton 1 and 2
    else if(tabIndex == 5){
       values <<ui->lineEdit_7->text()<<ui->lineEdit_5->text()<<ui->VacMode1_iacom->currentText()
             <<ui->lineEdit_11->text()<<ui->lineEdit_12->text()<<ui->VacMode2_iacom->currentText();
    }
    else if(tabIndex == 6){
        values <<ui->lineEdit->text()<<ui->CutMode_vitCom->currentText()
              <<ui->lineEdit_19->text()<<ui->VacMode_VitCom->currentText()<<ui->lineEdit_20->text();
    }

    surgeonData[surgeon][tabIndex] = values;
    emit valuesUpdated(surgeon, tabIndex, values);

}

void doctor::onComboBox1Changed() {
    emit comboBox1Changed(ui->PowMethodCom_phaco->currentText());
}

void doctor::onComboBox2Changed() {
    emit comboBox2Changed(ui->PowMethodCom_phaco_2->currentText());
}

void doctor::onComboBox3Changed() {
    emit comboBox3Changed(ui->PowMethodCom_phaco_3->currentText());
}
void doctor::onComboBox4Changed() {
    emit comboBox4Changed(ui->PowMethodCom_phaco_4->currentText());
}
int doctor::getvalue(int input)
{
    if(input<=60){
        return 60;
    }else{
        return ((input-1)/60+1)*60;
    }
}
