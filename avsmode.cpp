#include "avsmode.h"
#include "ui_avsmode.h"
#include<QStyleFactory>
#include<cmath>
#include "footpedal.h"  // Full definition of footpedal class
#include "doctor.h"
avsmode::avsmode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::avsmode)
  ,isTuneEnabled(false)
  ,powerOn1(false)
  ,overallci(false)
  ,vitonoff(false)
{
    ui->setupUi(this);
    vac=new Vaccum;
    handler=new hwhandler;
    foot = new footpedal; // Now the compiler knows the full structure of footpedal
      in = new doctor;
    //s=new settings;
      lfoot=new footlib;
    key=new keypad;
    // keypad connetion
      connect(key,&keypad::textsignal,this,&avsmode::on_clicked);
      connect(key,&keypad::entersignal,this,&avsmode::on_clickedenter);
      connect(ui->comboBox_4, &QComboBox::currentTextChanged, this, &avsmode::push);
      connect(in,&doctor::sendavsvalues,this,&avsmode::receiveAvsValues);
      connect(in,&doctor::transmitval,this,&avsmode::footpedalvalues);
     // connect(this,&MainWindow::sendfootvalues,foot,&footpedal::receivedval);
    connect(foot,&footpedal::activatemain,this,&avsmode::disablefunction);

//      connect(in,&doctor::tx_speakeronoff,this,&MainWindow::rx_speakeronoff);
    connect(foot, &footpedal::moveTopToBottom, this, &avsmode::moved);
    connect(foot, &footpedal::moveBottomToTop, this, &avsmode::movePushButtonBottomToTop);
   connect(foot,&footpedal::performReflux,this,&avsmode::footreflux);
  // connect(foot,&footpedal::togglePower,this,&avsmode::poweronoff);
   connect(foot,&footpedal::continous_irrigation,this,&avsmode::continousirrigation);
      connect(in,&doctor::activatemainwindow,this,&avsmode::disablefunction);
      connect(in,&doctor::avsSwitchingmode,this,&avsmode::avsmodechanging);

      QString styleSheet5 = "QLabel {"
                 "image: url(:/images/not_Tuned.png);"
                  "background-color:transparent;"
                                       "}";
      // keypad connetion
        connect(key,&keypad::textsignal,this,&avsmode::on_clicked);
        connect(key,&keypad::entersignal,this,&avsmode::on_clickedenter);
      connect(foot,&footpedal::sendleftfootdoc,in,&doctor::receivetopleft);
      connect(foot,&footpedal::sendrightfootdoc,in,&doctor::receivetopright);
      connect(foot,&footpedal::sendbottomleftddoc,in,&doctor::receivebottomleft);
      connect(foot,&footpedal::sendbottomrightdoc,in,&doctor::receivebottomright);
//update footpedal value from doctor window to mainwindow and mainwindow to footpedal screen
      connect(in,&doctor::sendleftfootvalues,foot,&footpedal::combobox1);
      connect(in,&doctor::sendrightfootvalues,foot,&footpedal::combobox2);
      connect(in,&doctor::sendbleftfootvalues,foot,&footpedal::combobox3);
      connect(in,&doctor::sendbrightfootvalues,foot,&footpedal::combobox4);
     connect(this,&avsmode::left_foot,foot,&footpedal::combobox1);
     connect(this,&avsmode::right_foot,foot,&footpedal::combobox2);
     connect(this,&avsmode::bottom_left,foot,&footpedal::combobox3);
     connect(this,&avsmode::bottom_right,foot,&footpedal::combobox4);
      //dial update
       ui->dial_2->setStyleSheet("");
       ui->dial_2->setStyle(QStyleFactory::create("Fusion"));
       ui->dial_2->setStyleSheet("background-color: rgb(26, 95, 180);");
       ui->dial_2->setRange(0, 4096);
       int currenttab=4;
         connect(ui->tabWidget, &QTabWidget::currentChanged, this, &avsmode::current);
         current(currenttab);
         push(ui->comboBox_4->currentText());
         ui->comboBox->hide();
         //footpedal congiguration
         protimer=new QTimer;
         connect(protimer,&QTimer::timeout,this,&avsmode::footpedalcheck);
         protimer->start(1);
         Tacutalsensor=new QTimer;
         connect(Tacutalsensor,&QTimer::timeout,this,&avsmode::readsensorvalue);
         Tacutalsensor->start(1);
         on_butia1mode_clicked();
         on_butia2mode_clicked();
         on_vitvacmode_clicked();
         setLastSelectedValue();
         push(ui->comboBox_4->currentText());
         QDateTime date = QDateTime::currentDateTime();
         QString formatteddate = date.toString("dd.MM.yyyy");
         ui->lab_date->setText(formatteddate);

         QTime time = QTime::currentTime();
         QString formatTime = time.toString("hh:mm:ss");
         ui->lab_time->setText(formatTime);
}

avsmode::~avsmode()
{
    delete ui;
    delete foot;
        delete in;
}
bool avsmode::eventFilter(QObject* object, QEvent* event)
{

          //IRRIGATION/ASPIRATION 1
        if(object == ui->lineEdit_9 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->resize(401,291);
              key->move(100,260);
              key->show();
              ui->lineEdit_9->setFocus();
              ui->lineEdit_10->clearFocus();
             // ui->lineEdit_56->clearFocus();
              ui->lineEdit_9->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
        if(object == ui->lineEdit_10 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->resize(401,291);
              key->move(280,320);
              key->show();
              ui->lineEdit_10->setFocus();
              ui->lineEdit_9->clearFocus();
              //ui->lineEdit_56->clearFocus();
              ui->lineEdit_10->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
        //IRRIGATION/ASPIRATION 2
        if(object == ui->lineEdit_7 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->resize(401,291);
              key->move(100,260);
              key->show();
              ui->lineEdit_7->setFocus();
              ui->lineEdit_8->clearFocus();
              //ui->lineEdit_56->clearFocus();
              ui->lineEdit_7->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
        if(object == ui->lineEdit_8 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->resize(401,291);
              key->move(280,320);
              key->show();
              ui->lineEdit_8->setFocus();
              ui->lineEdit_7->clearFocus();
              //ui->lineEdit_56->clearFocus();
              ui->lineEdit_8->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
        //VITRECTOMY

        if(object == ui->lineEdit_5 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->close();
              key->resize(401,291);
             key->move(850,260);
              key->show();
              ui->lineEdit_5->setFocus();
              ui->lineEdit_4->clearFocus();
              ui->lineEdit_6->clearFocus();
              ui->lineEdit_5->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
        if(object == ui->lineEdit_4 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
               key->close();
              key->resize(401,291);
              key->move(100,260);
              key->show();
              ui->lineEdit_4->setFocus();
              ui->lineEdit_6->clearFocus();
              ui->lineEdit_5->clearFocus();
              ui->lineEdit_4->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
        if(object == ui->lineEdit_6 && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
               key->close();
              key->resize(401,291);
              key->move(280,320);
              key->show();
              ui->lineEdit_6->setFocus();
              ui->lineEdit_4->clearFocus();
              ui->lineEdit_5->clearFocus();
              ui->lineEdit_6->setText("");

          } else if ( k->button() == Qt::RightButton ) {
          }
    }
  //DIATHERMY
        if(object == ui->lineEdit && event->type() == QEvent::MouseButtonPress) {
          QMouseEvent *k = static_cast<QMouseEvent *> (event);
          if( k->button() == Qt::LeftButton ) {
              key->close();
              key->resize(401,291);
              key->move(280,320);
              key->show();
              ui->lineEdit->setFocus();
              ui->lineEdit->setText("");
          } else if ( k->button() == Qt::RightButton ) {
          }
    }
  return false;
}
void avsmode::on_clicked(const QString& digit)
{//ULTRASONIC 1


  //IRRIGATION/ASPIRATION 1
  if(ui->lineEdit_9->focusWidget()) {
      ui->lineEdit_10->clearFocus();
      //ui->lineEdit_56->clearFocus();
      ui->lineEdit_9->setFocus();
      int prevValue = ui->lineEdit_9->text().toInt();
      int value = (ui->lineEdit_9->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_9->setText(QString::number(5));
          return;}
      setRange(ui->lineEdit_9, prevValue, value, 500);

  }
  if(ui->lineEdit_10->focusWidget()) {
      ui->lineEdit_9->clearFocus();
      //ui->lineEdit_57->clearFocus();
      ui->lineEdit_10->setFocus();
      int prevValue = ui->lineEdit_10->text().toInt();
      int value = (ui->lineEdit_10->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_10->setText(QString::number(2));
          return;}
      setRange(ui->lineEdit_10, prevValue, value, 40);

  }
  //IRRIGATION/ASPIRATION 2
   if(ui->lineEdit_7->focusWidget()) {
      ui->lineEdit_8->clearFocus();
      //ui->lineEdit_56->clearFocus();
      ui->lineEdit_7->setFocus();
      int prevValue = ui->lineEdit_7->text().toInt();
      int value = (ui->lineEdit_7->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_7->setText(QString::number(5));
          return;}
      setRange(ui->lineEdit_7, prevValue, value, 500);


  }
   if(ui->lineEdit_8->focusWidget()) {
      ui->lineEdit_7->clearFocus();
      //ui->lineEdit_57->clearFocus();
      ui->lineEdit_8->setFocus();
      int prevValue = ui->lineEdit_8->text().toInt();
      int value = (ui->lineEdit_8->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_8->setText(QString::number(2));
          return;}
      setRange(ui->lineEdit_8, prevValue, value, 40);


  }
  //VITRECTOMY
   if(ui->lineEdit_5->focusWidget()) {
      ui->lineEdit_4->clearFocus();
      ui->lineEdit_6->clearFocus();
      ui->lineEdit_5->setFocus();
      int prevValue = ui->lineEdit_5->text().toInt();
      int value = (ui->lineEdit_5->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_5->setText(QString::number(5));
          return;}
      setRange(ui->lineEdit_5, prevValue, value, 2500);

  }
   if(ui->lineEdit_4->focusWidget()) {
      ui->lineEdit_5->clearFocus();
      ui->lineEdit_6->clearFocus();
      ui->lineEdit_4->setFocus();
      int prevValue = ui->lineEdit_4->text().toInt();
      int value = (ui->lineEdit_4->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_4->setText(QString::number(5));
          return;}
      setRange(ui->lineEdit_4, prevValue, value, 500);


  }
  if(ui->lineEdit_6->focusWidget()) {
      ui->lineEdit_5->clearFocus();
      ui->lineEdit_4->clearFocus();
      ui->lineEdit_6->setFocus();
      int prevValue = ui->lineEdit_6->text().toInt();
      int value = (ui->lineEdit_6->text()+digit).toInt();
      if(value==0){
          ui->lineEdit_6->setText(QString::number(2));
          return;}
      setRange(ui->lineEdit_6, prevValue, value, 40);

  }
  //DIATHERMY
  if (ui->lineEdit->focusWidget()) {
      ui->lineEdit->setFocus();
      int prevValue = ui->lineEdit->text().toInt();

      int value = (ui->lineEdit->text() + digit).toInt();
      if(value==0){
          ui->lineEdit->setText(QString::number(5));
          return;}
          setRange(ui->lineEdit, prevValue, value, 100);

      }

}
//when enter button is clicked they value is modified
void avsmode::on_clickedenter()
{
   key->hide();
   // Maintain previous value for lineEdit
   QString text = ui->lineEdit_5->text().trimmed();
   if (!text.isEmpty()) {
       int input = text.toInt();
       int output = getvalue(input);  // Process the input to get the desired output
       ui->lineEdit_5->setText(QString::number(output));
       lastValidValues[ui->lineEdit_5] = output;  // Store the processed output as the last valid value
   } else {
       // Restore the last valid value if input is empty
       if (lastValidValues.contains(ui->lineEdit_5)) {
           ui->lineEdit_5->setText(QString::number(lastValidValues[ui->lineEdit_5]));
       }
   }

   // Process other QLineEdits for power and vacuum
   QList<QLineEdit*> lineEdits = {
       ui->lineEdit_7, ui->lineEdit_4, ui->lineEdit_9

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
       ui->lineEdit_10, ui->lineEdit_8, ui->lineEdit_6
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

}void avsmode::beepsound()
{
    if(vibon == "Vibration ON"){
    system("beep");
    }else{
        system(0);
    }

}
void avsmode::footpedalvalues(int &value1, int &value2, int &value3, int &value4)
{
//qDebug()<<"values are received from the doctor window is"<<value1<<value2<<value3<<value4;
    nfpzero = static_cast<int>(value1*40.90);
    nfpone =  static_cast<int>(value2*40.90);
    nfptwo =  static_cast<int>(value3*40.90);
    nfpthree =  static_cast<int>(value4*40.90);


    //qDebug()<<"that is the range"<<nfpzero<<nfpone<<nfptwo<<nfpthree;
footpedalcheck();

}
void avsmode::motoron(QLineEdit *lineEdit)
{
    int linevalue=lineEdit->text().toInt();
    handler->write_motor(0x01,0x03,linevalue);
    ////qDebug()<<"motor working";
}

void avsmode::motoroff()
{
    handler->write_motor(0x00,0x00,0);
}

void avsmode::motorccwon()
{
    handler->write_motor(0x01,0x01,40);
}
void avsmode::footpedalcheck()
{

        qint64 elapsed = currentTimer.elapsed();
        QString message;
    QString styleSheet3 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: green;"
            "color: black;"
          "image: url(:/images/ci.png);"
           " border-radius:30px;font-weight: bold;"
                                 "}";
    QString styleSheet4 = "QPushButton {"
           " font:20pt Ubuntu;"
          " background-color: red;"
            "color: black;"
           "image: url(:/images/ci.png);"
           " border:5px solid black;"
           " border-radius:30px;font-weight: bold;"
                                 "}";
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
    int range = lfoot->convert(0x97);
   // qDebug()<<"the range is"<<range;
    int val=readsensorvalue();

    QString text=ui->comboBox_4->currentText();


  QString ia1=ui->butia1mode->text();
  QString ia2=ui->butia2mode->text();
  QString vvac=ui->vitvacmode->text();
  //QString us2on=ui->us2onoff->text();

    switch(butname)
    {
qDebug()<<"the butt name is"<<butname;
    // dia
    case 0:
    {
        int pow = (ui->lineEdit->text().toInt() * 255) / 100;
        bool flag = true;
        static int currentCount = -1;
        handler->phaco_off();
        handler->fs_count(0);
        handler->phaco_power(0);
        handler->pinchvalve_off();
   if(flag){
            if (range > 0 && range < nfpzero) {
                ui->butposition->setText("0");
                currentCount = 0;
                ui->dial_2->setValue(range);
                handler->dia_off();

                if (!overallci ) {
                    ui->butCI->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }

//                if (!ventondia) {
//                    handler->safetyvent_on();
//                    QThread::msleep(100);
//                    handler->safetyvent_off();
//                    ventondia = true;
//                }
                flag=true;
                handler->speaker_off();
            }
            else if (range >= nfpzero && range < (nfpzero + nfpone + nfptwo + nfpthree)) {
                ui->butposition->setText("1");
                currentCount = 1;
                ui->dial_2->setValue(range);
                handler->dia_on();
                handler->dia_count(pow);

                if (!overallci) {
                    ui->butCI->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                    handler->safetyvent_off();
                }

//                if (!ventondia) {
//                    handler->safetyvent_on();
//                    QThread::msleep(100);
//                    handler->safetyvent_off();
//                    ventondia = true;
//                }
                if(speakeronoff == "Speaker ON"){
                    handler->speaker_on(0,0,1,0);
                }else{
                      handler->speaker_off();
                }
            }
            if (currentCount > diacount) {
                beepsound();
            }
            if (currentCount != -1) {
                diacount = currentCount;
            }
   }
        break;
    }
       // ia1
    case 1:
    {
bool flag6=false;
double ia1preset=ui->lineEdit_9->text().toDouble();
QString ia1=ui->butia1mode->text();
 int ia1currentcount=-1;
 handler->phaco_off();
 handler->fs_count(0);
 handler->phaco_power(0);
        if (ia1 == "Panel") { // surgeon
            if (range >= 0 && range < nfpzero) {
                ui->butposition->setText("0");
                ui->dial_2->setValue(range);

                if (!overallci) {
                    ui->butCI->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                }
//                if(ventonia1 == false) {
//                    handler->safetyvent_on();
//                    QThread::msleep(200);
//                    handler->safetyvent_off();
//                    ventonia1 = true;
//                }
               handler->speaker_off();
                motoroff();
                ui->lblia1vacactual->setText(QString::number(0));
                ia1currentcount=0;
                flag6=true;
            }

            else if (range >= nfpzero && range < (nfpone + nfpzero)) {
                ui->butposition->setText("1");
                if(speakeronoff == "Speaker ON"){
                handler->speaker_on(0,0,1,0);
                }else{
                    handler->speaker_off();
                }

                ui->dial_2->setValue(range);
                handler->pinchvalve_on();
                ui->butCI->setStyleSheet(styleSheet3);
                if(ventonia1 == false) {
                    handler->safetyvent_on();
                    QThread::msleep(200);
                    handler->safetyvent_off();
                    ventonia1 = true;
                }
                motoroff();
                int pro = readsensorvalue();
                ui->lblia1vacactual->setText(QString::number(pro));
ia1currentcount=1;
                 flag6=true;
            }

            else if (range >= (nfpzero + nfpone) && range < (nfpzero + nfpone + nfptwo + nfpthree)) {
               ui->butposition->setText("2");
                ventonia1 = false;
                handler->safetyvent_off();
                ui->dial_2->setValue(range);
                ui->butCI->setStyleSheet(styleSheet3);
                handler->pinchvalve_on();
                if(switchmode == "AVSPeristaltic"){
               int nonlinear_prevac = readsensorvalue(); // Assuming this function reads the current sensor value
               int nonlinear_vac = std::min(nonlinear_prevac, static_cast<int>(ia1preset));
               ui->lblia1vacactual->setText(QString::number(nonlinear_vac));
               motoron(ui->lineEdit_10);
               if(speakeronoff == "Speaker ON"){
               handler->speaker_on(nonlinear_prevac,1,0,0);
               }else{
                   handler->speaker_off();
               }
               if (nonlinear_prevac >= ia1preset) {
                         motoroff(); // Turn off the motor
                       //  speedofthelabe(ui->label_113);
                         if(speakeronoff == "Speaker ON"){
                         handler->speaker_on(0,0,0,1);
                         }else{
                             handler->speaker_off();
                         }

                    }
                }
               ia1currentcount=2;
           }
        }

        else if(ia1 == "Surgeon"){
            if(range>=0 && range<nfpzero){
                ui->butposition->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
             ui->butCI->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                }
//                if(ventonia1 == false) {
//                    handler->safetyvent_on();
//                    QThread::msleep(200);
//                    handler->safetyvent_off();
//                    ventonia1 = true;
//                }

                  motoroff();
                    //int pro = readsensorvalue();
                 ui->lblia1vacactual->setText(QString::number(0));
                 handler->speaker_off();
                 ia1currentcount=0;
                  flag6=true;


            }
            else if(range>=(nfpzero) && range<(nfpone+nfpzero)){
                ui->butposition->setText("1");
                if(speakeronoff == "Speaker ON"){
                handler->speaker_on(0,0,1,0);
                }else{
                    handler->speaker_off();
                }
                  ui->dial_2->setValue(range);
             ui->butCI->setStyleSheet(styleSheet3);
                handler->pinchvalve_on();
                  motoroff();
                  int pro = readsensorvalue();
               ui->lblia1vacactual->setText(QString::number(pro));


               if(ventonia1 == false) {
                   handler->safetyvent_on();
                   QThread::msleep(200);
                   handler->safetyvent_off();
                   ventonia1 = true;
               }
               ia1currentcount=1;
             flag6=true;
}
            if (range >= (nfpzero + nfpone) && range < (nfpzero + nfpone + nfptwo + nfpthree)) {
                ui->butposition->setText("2");
                ventonia1=false;
                beepsound();
                ui->dial_2->setValue(range);
                ui->butCI->setStyleSheet(styleSheet3);
handler->safetyvent_off();
handler->pinchvalve_on();
if(switchmode == "AVSPeristaltic"){
                const int MIN_RANGE = nfpzero + nfpone;
                const int MAX_RANGE =nfpzero + nfpone + nfptwo + nfpthree;
                int divi =  MAX_RANGE-MIN_RANGE ; // Divider
                int calibration = range - MIN_RANGE; // Calibration value

                if (divi != 0) {
                    double final =ia1preset / divi;
                    int presetvac = static_cast<int>(std::round(calibration * final));
                    int pro =readsensorvalue();
                    ui->lblia1vacactual->setText(QString::number(pro));
                    const int tolerance = 5; // Example tolerance

                    if (pro < (presetvac - tolerance)) {
                        motoron(ui->lineEdit_10);
                        if(speakeronoff == "Speaker ON"){
                        handler->speaker_on(pro,1,0,0);
                        }else{
                            handler->speaker_off();
                        }
                        if (!motoria1) {
                            motoron(ui->lineEdit_10);
                            motoria1 = true;
                        }
                    } else if (pro >= presetvac || motoria1) {
                        motoroff();
                        motoria1 = false;
                    } // If pro exceeds vitpreset, cap it
                    if (pro >= ia1preset) {
                        pro = static_cast<int>(ia1preset);
                        ui->lblia1vacactual->setText(QString::number(pro));
                      //  speedofthelabe(ui->label_113);
                        motoroff();

                        if(speakeronoff == "Speaker ON"){
                        handler->speaker_on(0,0,0,1);
                        }else{
                            handler->speaker_off();
                        }
                    }

            }
}
                ia1currentcount=2;

}
        }
        if (ia1currentcount>ia1count) {
            beepsound();
        }
        if (ia1currentcount != -1) {
            ia1count = ia1currentcount;
        }
    break;
    }
        // ia2
    case 2:
        {
  bool flag6=true;
  ia2=ui->butia2mode->text();
  double ia2vacline=ui->lineEdit_7->text().toInt();
  int ia2currentcount=-1;

  handler->phaco_off();
  handler->fs_count(0);
  handler->phaco_power(0);
            if(ia2 == "Panel"){
            if(range>=0 && range<nfpzero){
               ui->butposition->setText("0");
                  ui->dial_2->setValue(range);
                if(!overallci){
            ui->butCI->setStyleSheet(styleSheet4);
                    handler->pinchvalve_off();
                }
//                if(ventonia2==false){
//                    handler->safetyvent_on();
//                    QThread::msleep(100);
//                    handler->safetyvent_off();
//                   ventonia2=true;
//                }
             //   int ia2pro=readsensorvalue();
                ui->lblia2actual->setText(QString::number(0));
 motoroff();
  handler->speaker_off();
  ia2currentcount=0;
 flag6=true;
            }
            if(range>=nfpzero && range<(nfpzero+nfpone)){
                ui->butposition->setText("1");
                if(speakeronoff == "Speaker ON"){
                handler->speaker_on(0,0,1,0);
                }else{
                    handler->speaker_off();
                }
                //footpedalbeep();
                ui->dial_2->setValue(range);
                ui->butCI->setStyleSheet(styleSheet3);
                handler->pinchvalve_on();
                 motoroff();
            if(ventonia2==false){
                handler->safetyvent_on();
                QThread::msleep(100);
                handler->safetyvent_off();
                ventonia2=true;
            }
            ia2currentcount=1;
}
            else if(range>=(nfpzero+nfpone) && range <(nfpzero+nfpone+nfptwo+nfpthree)){
                ui->butposition->setText("2");
                ventonia2=false;
                //footpedalbeep();
                ui->dial_2->setValue(range);
                ui->butCI->setStyleSheet(styleSheet3);
                handler->safetyvent_off();
                handler->pinchvalve_on();
                if(switchmode == "AVSPeristaltic"){
            int nonlinear_prevac = readsensorvalue(); // Assuming this function reads the current sensor value
                              int nonlinear_vac = std::min(nonlinear_prevac, static_cast<int>(ia2vacline));
                              ui->lblia2actual->setText(QString::number(nonlinear_vac));
                              motoron(ui->lineEdit_8);
                              if(speakeronoff == "Speaker ON"){
                              handler->speaker_on(nonlinear_prevac,1,0,0);
                              }else{
                                  handler->speaker_off();
                              }
                              if (nonlinear_prevac >= ia2vacline) {
                                  motoroff(); // Turn off the motor
                                  if(speakeronoff == "Speaker ON"){
                                  handler->speaker_on(0,0,0,1);
                                  }else{
                                      handler->speaker_off();
                                  }
                              }
                }
ia2currentcount=2;

            }

            }
            else if(ia2 == "Surgeon"){
                if(range>=0 && range<nfpzero){
                    ui->butposition->setText("0");
                      ui->dial_2->setValue(range);
                    if(!overallci){
                 ui->butCI->setStyleSheet(styleSheet4);
                        handler->pinchvalve_off();
                    }
                    handler->speaker_off();
                      motoroff();
//                      if(ventonia2==false){
//                        handler->safetyvent_on();
//                        QThread::msleep(100);
//                        handler->safetyvent_off();
//                        ventonia2=true;
//                      }
                      //int ia2pro=readsensorvalue();
                      ui->lblia2actual->setText(QString::number(0));
                      ia2currentcount=0;
                }
                if(range>=nfpzero && range<(nfpone+nfpzero)){
                    ui->butposition->setText("1");
                    if(speakeronoff == "Speaker ON"){
                    handler->speaker_on(0,0,1,0);
                    }else{
                        handler->speaker_off();
                    }
                    //footpedalbeep();
                      ui->dial_2->setValue(range);
                  ui->butCI->setStyleSheet(styleSheet3);
                    handler->pinchvalve_on();
                      motoroff();
                      if(ventonia2==false){
                          handler->safetyvent_on();
                                           QThread::msleep(100);
                                           handler->safetyvent_off();
                                           ventonia2=true;
                      }
                      int ia2pro=readsensorvalue();
                      ui->lblia2actual->setText(QString::number(ia2pro));
                      ia2currentcount=1;
                }
                else if(range>=(nfpzero+nfpone) && range <(nfpone+nfpzero+nfptwo+nfpthree)){
                    ui->butposition->setText("2");
                    ventonia2=false;
                    //footpedalbeep();
                      ui->dial_2->setValue(range);
              ui->butCI->setStyleSheet(styleSheet3);
                    handler->safetyvent_off();
                    handler->pinchvalve_on();
                    if(switchmode == "AVSPeristaltic"){
                    const int MIN_RANGE = nfpzero + nfpone;
                    const int MAX_RANGE =nfpzero + nfpone + nfptwo + nfpthree;
                    int divi =  MAX_RANGE-MIN_RANGE ; // Divider
                    int calibration = range - MIN_RANGE; // Calibration value

                    if (divi != 0) {
                        double final =ia2vacline / divi;
                        int presetvac = static_cast<int>(std::round(calibration * final));
                        int pro =readsensorvalue();
                        if(speakeronoff == "Speaker ON"){
                        handler->speaker_on(pro,1,0,0);
                        }else{
                            handler->speaker_off();
                        }
                        ui->lblia2actual->setText(QString::number(pro));
                        if (pro < presetvac) {
                            motoron(ui->lineEdit_8);
                            if (!motoria2) {
                                motoron(ui->lineEdit_8);
                                motoria2 = true;
                            }
                        } else if (motoria2) {
                            motoroff();
                            motoria2 = false;
                        }
                        // If pro exceeds vitpreset, cap it
                        if (pro >= ia2vacline) {
                            pro = static_cast<int>(ia2vacline);
                            ui->lblia2actual->setText(QString::number(pro));
                            motoroff();
                  if(speakeronoff == "Speaker ON"){
                            handler->speaker_on(0,0,0,1);
                        }else{
                      handler->speaker_off();
                  }
                }
                    }
                    ia2currentcount=2;
                      }
                }



       }
            if (ia2currentcount>ia2count) {
                beepsound();
            }
            if (ia2currentcount != -1) {
                ia2count = ia2currentcount;
            }
            break;
        }
        // vit
    case 3: {
        int pow7 = ui->lineEdit_5->text().toInt();
       QString vvac = ui->vitvacmode->text();  // "Surgeon" or "Panel"
        double vitpreset = ui->lineEdit_4->text().toDouble();  // vitpreset should be double for better precision
   int vitcurrentcount=-1;
   handler->phaco_off();
   handler->fs_count(0);
   handler->phaco_power(0);
        if (range > 0 && range < nfpzero) {
            // State 0
            ui->butposition->setText("0");
            ui->dial_2->setValue(range);

            if (!overallci) {
                ui->butCI->setStyleSheet(styleSheet4);
                handler->pinchvalve_off();
            }
//            if (!ventonvit) {
//                handler->safetyvent_on();
//                QThread::msleep(100);
//                handler->safetyvent_off();
//                ventonvit = true;
//            }

            motoroff();
            ui->lblvitvacactual->setText("0");
            int vitpro = readsensorvalue();
            ui->lblvitacutal->setText(QString::number(0));
 handler->speaker_off();
 vitcurrentcount=0;
            handler->vit_off();
        } else if (range >= nfpzero && range < (nfpzero + nfpone)) {
            // State 1
            ui->butposition->setText("1");
            if(speakeronoff == "Speaker ON"){
            handler->speaker_on(0,0,1,0);
            }else{
                handler->speaker_off();
            }            //footpedalbeep();
            ui->dial_2->setValue(range);
            ui->butCI->setStyleSheet(styleSheet3);

            if (!ventonvit) {
                handler->safetyvent_on();
                QThread::msleep(100);
                handler->safetyvent_off();
                ventonvit = true;
            }

            handler->pinchvalve_on();
            motoroff();
            int vitpro = readsensorvalue();
            ui->lblvitvacactual->setText(QString::number(vitpro));
            ui->lblvitacutal->setText("0");
            handler->vit_off();
            vitcurrentcount=1;
        } else if (range >= (nfpzero + nfpone) && range < (nfpzero + nfpone + nfptwo)) {
            // State 2
            ui->butposition->setText("2");
            ventonvit = false;
            //footpedalbeep();
            ui->dial_2->setValue(range);
           ui->butCI->setStyleSheet(styleSheet3);
            handler->safetyvent_off();
            handler->pinchvalve_on();
if(switchmode == "AVSPeristaltic"){
            if (vvac == "Surgeon") {
                const int MIN_RANGE = nfpzero + nfpone;
                const int MAX_RANGE = nfpzero + nfpone + nfptwo;
                int divi = MAX_RANGE - MIN_RANGE;  // Divider
                int calibration = range - MIN_RANGE;  // Calibration value

                if (divi != 0) {
                    double final = static_cast<double>(vitpreset) / static_cast<double>(divi);
                    int presetvac = static_cast<int>(std::round(calibration * final));
                    int pro = readsensorvalue();
                    ui->lblvitvacactual->setText(QString::number(pro));
                    if(speakeronoff == "Speaker ON"){
                    handler->speaker_on(pro,1,0,0);
                    }else{
                        handler->speaker_off();
                    }

                    // Motor control based on preset value
                    if (pro < presetvac) {
                        motoron(ui->lineEdit_6);

                        if (!motorvit) {
                            motorvit = true;
                        }
                    } else if (motorvit) {
                        motoroff();
                        motorvit = false;
                    }

                    // If pro exceeds vitpreset, cap it
                    if (pro >= vitpreset) {
                        pro = static_cast<int>(vitpreset);
                        ui->lblvitacutal->setText(QString::number(pro));
                        motoroff();
                        if(speakeronoff == "Speaker ON"){
                        handler->speaker_on(0,0,0,1);
                        }else{
                            handler->speaker_off();
                        }
                    }
                }
            }

             else if (vvac == "Panel") {
                int nonlinear_prevac = readsensorvalue();  // Current sensor value
                int nonlinear_vac = std::min(nonlinear_prevac, static_cast<int>(vitpreset));
                ui->lblvitvacactual->setText(QString::number(nonlinear_vac));
                if(speakeronoff=="Speaker ON"){
                handler->speaker_on(nonlinear_prevac,1,0,0);
}else{
                    handler->speaker_off();
                }
                // Motor control for Panel
                motoron(ui->lineEdit_6);
                if (nonlinear_prevac >= vitpreset) {
                    motoroff();
                    if(speakeronoff == "Speaker ON"){
                    handler->speaker_on(0,0,0,1);
                    }else{
                        handler->speaker_off();
                    }

                }
            }
}

            ui->lblvitacutal->setText("0");
            handler->vit_off();
             vitcurrentcount=2;
        } else if (range >= (nfpzero + nfpone + nfptwo) && range < (nfpzero + nfpone + nfptwo + nfpthree)) {
            // State 3
            ui->butposition->setText("3");
            ventonvit = false;
            //footpedalbeep();
            ui->dial_2->setValue(range);
            ui->butCI->setStyleSheet(styleSheet3);
            handler->safetyvent_off();
            handler->pinchvalve_on();

            if (vitonoff) {  // vitonoff check for vit actions
                float progress4 = static_cast<float>(range - (nfpzero + nfpone + nfptwo)) /
                                  static_cast<float>(4096 - (nfpzero + nfpone + nfptwo)) * static_cast<float>(pow7);
                ui->lblvitacutal->setText(QString::number(static_cast<int>(progress4)));

                handler->vit_on(static_cast<float>(pow7));
                handler->vit_ontime(30);
            }
            if(switchmode == "AVSPeristaltic"){

            if (vvac == "Surgeon") {
                const int MIN_RANGE = nfpzero + nfpone + nfptwo;
                const int MAX_RANGE = nfpzero + nfpone + nfptwo + nfpthree;
                int divi = MAX_RANGE - MIN_RANGE;
                int calibration = range - MIN_RANGE;

                if (divi != 0) {
                    double final = static_cast<double>(vitpreset) / static_cast<double>(divi);
                    int presetvac = static_cast<int>(std::round(calibration * final));
                    int pro = readsensorvalue();
                    ui->lblvitvacactual->setText(QString::number(pro));
                    if(speakeronoff == "Speaker ON"){
                    handler->speaker_on(presetvac,1,0,0);
                    }else{
                        handler->speaker_off();
                    }
                    if (pro < presetvac) {
                        motoron(ui->lineEdit_6);
                        if (!motorvit) {
                            motorvit = true;
                        }
                    } else if (motorvit) {
                        motoroff();
                        motorvit = false;
                    }

                    if (pro >= vitpreset) {
                        pro = static_cast<int>(vitpreset);
                        ui->lblvitvacactual->setText(QString::number(pro));
                        if(speakeronoff == "Speaker ON"){
                        handler->speaker_on(pro,0,0,1);
                        }else{
                            handler->speaker_off();
                        }
                        motoroff();
                    }
                }
            } else if (vvac == "Panel") {
                int nonlinear_prevac = readsensorvalue();
                int nonlinear_vac = std::min(nonlinear_prevac, static_cast<int>(vitpreset));
                ui->lblvitvacactual->setText(QString::number(nonlinear_vac));
                if(speakeronoff == "Speaker ON"){
                handler->speaker_on(nonlinear_prevac,1,0,0);
                }else{
                    handler->speaker_off();
                }
                motoron(ui->lineEdit_6);
                if (nonlinear_prevac >= vitpreset) {
                    motoroff();
                    if(speakeronoff == "Speaker ON"){
                    handler->speaker_on(nonlinear_prevac,0,0,1);
                    }else{
                        handler->speaker_off();
                    }
                }
            }
            }
             vitcurrentcount=3;
        }
        if (vitcurrentcount>vitcount) {
            beepsound();
        }
        if (vitcurrentcount != -1) {
            vitcount = vitcurrentcount;
        }
        break;
    }


    }

}

int avsmode::readsensorvalue()
{
        int sensorvalue=vac->convert(0XD7);
        int actualsensor=sensorvalue*0.17;
        return actualsensor;
        //qDebug()<<actualsensor;


}

int avsmode::increasebutton(int input)
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


int avsmode::decreasebutton(int input)
{
    if (input % 2 != 0) {
          input++;  // Increment if odd to make it even
      }
      return input;
}
int avsmode::getvalue(int input)
{
    if(input<=60){
        return 60;
    }else{
        return ((input-1)/60+1)*60;
    }
}

void avsmode::setRange(QLineEdit *lineEdit, int prevValue, int value, int maxValue)
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

void avsmode::current(int tab)
{

        QString styleSheet = "QPushButton {"
                             "    font-family: Ubuntu;"
                             "    font-size: 15pt;"
                             "    background-color: transparent;"
                             "    image: url(:/images/pushbutton.png);"
                             "    height: 91px;"
                             "    width: 91px;"
                             "    color: white;"
                             "    border-radius: 40px;"
                             "    outline: none;"  // Removes focus outline
                             "}";

        QString styleSheet1 = "QPushButton {"
                              "    font-family: Ubuntu;"
                              "    font-size: 15pt;"
                              "    background-color: transparent;"
                              "    image: url(:/images/glass.png);"
                              "    height: 81px;"
                              "    width: 81px;"
                              "    color: black;"
                              "    border-radius: 40px;"
                              "    outline: none;"  // Removes focus outline
                              "}";

        QString styleSheet3 = "QPushButton {"
                              "    font-family: Ubuntu;"
                              "    font-size: 13pt;"
                              "    background-color: transparent;"
                              "    height: 81px;"
                              "    width: 81px;"
                              "    image: url(:/images/newbut.png);"
                              "    border-radius: 40px;"
                              "    outline: none;"  // Removes focus outline
                              "}";

        QString styleSheet4 = "QPushButton {"
                              "    font-family: Ubuntu;"
                              "    font-size: 13pt;"
                              "    background-color: transparent;"
                              "    height: 81px;"
                              "    width: 81px;"
                              "    image: url(:/images/irr.png);"
                              "    color: black;"
                              "    border-radius: 40px;"
                              "    outline: none;"  // Removes focus outline
                              "}";



        ui->IA1BUT->setStyleSheet(styleSheet1);
        ui->IA2BUT->setStyleSheet(styleSheet1);
        ui->VITRECTOMYBUT->setStyleSheet(styleSheet1);
        ui->DIABUT->setStyleSheet(styleSheet1);
        ui->lblup->hide();
        ui->lblrightside->hide();
        ui->lbldownside->hide();
        ui->lblleftside->hide();

        switch (tab) {
        case 0:
            ui->DIABUT->setStyleSheet(styleSheet);
            ui->lblup->show();
            break;
            case 1:
                ui->IA1BUT->setStyleSheet(styleSheet);
                ui->lblrightside->show();
                break;
            case 2:
                ui->IA2BUT->setStyleSheet(styleSheet);
                ui->lbldownside->show();
                break;
            case 3:
                ui->VITRECTOMYBUT->setStyleSheet(styleSheet);
                ui->lblleftside->show();
                break;

            default:
                break;
        }




}
void avsmode::on_butdiaup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit->text().toInt();
    value=value+5;

    if(value > 100)
    {
        value=100;

    }
    ui->lineEdit->setText(QString::number(value));

}

void avsmode::on_butdiadown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit->text().toInt();
    value=value-5;

    if(value > 5)
    {
        value=5;

    }
    ui->lineEdit->setText(QString::number(value));

}


void avsmode::on_butia1up_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_9->text().toInt();
    value=value+5;

    if(value > 500)
    {
        value=500;

    }
    ui->lineEdit_9->setText(QString::number(value));

}

void avsmode::on_butia1down_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_9->text().toInt();
    value=value-5;

    if(value < 5)
    {
        value=5;

    }
    ui->lineEdit_9->setText(QString::number(value));

}

void avsmode::on_butia1flowup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_10->text().toInt();
    value=value+2;

    if(value > 40)
    {
        value=40;

    }
    ui->lineEdit_10->setText(QString::number(value));

}

void avsmode::on_butia1flowdown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_10->text().toInt();
    value=value-2;

    if(value < 2)
    {
        value=2;

    }
    ui->lineEdit_10->setText(QString::number(value));

}

void avsmode::on_butia2vacup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_7->text().toInt();
    value=value+5;

    if(value > 500)
    {
        value=500;

    }
    ui->lineEdit_7->setText(QString::number(value));

}

void avsmode::on_butia2vacdown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_7->text().toInt();
    value=value-5;

    if(value < 5)
    {
        value=5;

    }
    ui->lineEdit_7->setText(QString::number(value));

}

void avsmode::on_butia2flowup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_8->text().toInt();
    value=value+2;

    if(value > 40)
    {
        value=40;

    }
    ui->lineEdit_8->setText(QString::number(value));

}

void avsmode::on_butia2flowdown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_8->text().toInt();
    value=value-2;

    if(value < 2)
    {
        value=2;

    }
    ui->lineEdit_8->setText(QString::number(value));

}

void avsmode::on_butvitup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_5->text().toInt();
    value=value+60;

    if(value > 2500)
    {
        value=2500;

    }
    ui->lineEdit_5->setText(QString::number(value));

}

void avsmode::on_butvitdown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_5->text().toInt();
    value=value-60;

    if(value < 60)
    {
        value=60;

    }
    ui->lineEdit_5->setText(QString::number(value));

}

void avsmode::on_butvitvacup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_4->text().toInt();
    value=value+5;

    if(value > 500)
    {
        value=500;

    }
    ui->lineEdit_4->setText(QString::number(value));

}

void avsmode::on_butvitvacdown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_4->text().toInt();
    value=value-5;

    if(value > 5)
    {
        value=5;

    }
    ui->lineEdit_4->setText(QString::number(value));

}

void avsmode::on_butvitflowup_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_6->text().toInt();
    value=value+2;

    if(value > 40)
    {
        value=40;

    }
    ui->lineEdit_6->setText(QString::number(value));

}

void avsmode::on_butvitflowdown_clicked()
{
    handler->buzz();
    int value=ui->lineEdit_6->text().toInt();
    value=value-2;

    if(value < 100)
    {
        value=2;

    }
    ui->lineEdit_6->setText(QString::number(value));

}

void avsmode::on_DIABUT_clicked()
{
    // Emit buzz sound
    handler->buzz();

    // Disable safety vent and motor
    handler->safetyvent_off();

    // Switch to Diathermy tab
    ui->tabWidget->setCurrentIndex(0);



    // Reset button name
    butname = 0;

    // Trigger current tab setup
    current(0);
}

void avsmode::avsmodechanging(const QString &value)
{
    switchmode=value;
    if(switchmode == "AVSPeristaltic"){
        //ia1
        ui->lblflowtext->show();
        ui->butia1flowup->show();
        ui->butia1flowdown->show();
        ui->lineEdit_10->show();
        ui->lblia1flowout->show();
        //ia2
        ui->lblia2flowtext->show();
        ui->butia2flowup->show();
        ui->butia2flowdown->show();
        ui->lineEdit_8->show();
        ui->lblia2flowout->show();
        //vit
        ui->lblvitflow->show();
        ui->butvitflowup->show();
        ui->butvitflowdown->show();
        ui->lineEdit_6->show();
        ui->lblvitflowout->show();

    }else if(switchmode == "AVSVenturi"){
        ui->lblflowtext->hide();
        ui->butia1flowup->hide();
        ui->butia1flowdown->hide();
        ui->lineEdit_10->hide();
        ui->lblia1flowout->hide();
        //ia2
        ui->lblia2flowtext->hide();
        ui->butia2flowup->hide();
        ui->butia2flowdown->hide();
        ui->lineEdit_8->hide();
        ui->lblia2flowout->hide();
        //vit
        ui->lblvitflow->hide();
        ui->butvitflowup->hide();
        ui->butvitflowdown->hide();
        ui->lineEdit_6->hide();
        ui->lblvitflowout->hide();

    }
}

void avsmode::on_IA1BUT_clicked()
{
    handler->buzz();
    ui->tabWidget->setCurrentIndex(1);
    // Disable safety vent and motor
    handler->safetyvent_off();
butname=1;


}

void avsmode::on_IA2BUT_clicked()
{
    handler->buzz();
    ui->tabWidget->setCurrentIndex(2);
butname=2;
}

void avsmode::on_VITRECTOMYBUT_clicked()
{
    handler->buzz();
    ui->tabWidget->setCurrentIndex(3);
    butname=3;

}
void avsmode::onComboBoxIndexChanged(int index)
{


    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(PATH);

        if (!db.open()) {
            //qDebug() << "Error: connection with database failed:";
            return;
        }
    }

    QSqlQuery query(db);

    // Step 1: Update the last selected index
    query.prepare("UPDATE phacohigh SET lastupdate = :index");
    query.bindValue(":index", index);

    if (!query.exec()) {
//        //qDebug() << "Error updating last selected index:";
        return;
    } else {
//        qDebug() << "Last selected index updated to" << index;
    }


    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}


void avsmode::receiveAvsValues(const QString &comboBoxValue, const QString &combo, int dia, int ia1vac, int ia1asp, int ia2vac, int ia2asp, int vitcut, int vitvac, int vitasp, const QString &ia1mode, const QString &ia2mode, const QString &vitvacmode)
{
    surgicalData.comboBoxValue = comboBoxValue;
    surgicalData.combo =combo;
        surgicalData.dia = dia;

        surgicalData.ia1vac = ia1vac;
        surgicalData.ia1asp = ia1asp;
        surgicalData.ia2vac = ia2vac;
        surgicalData.ia2asp = ia2asp;
        surgicalData.vitcut = vitcut;
        surgicalData.vitvac = vitvac;
        surgicalData.vitasp = vitasp;

        surgicalData.ia1mode = ia1mode;
        surgicalData.ia2mode = ia2mode;
        surgicalData.vitvacmode = vitvacmode;
        ui->comboBox_4->setCurrentText(surgicalData.combo);
        switchmode=surgicalData.comboBoxValue;
        qDebug()<<"the mode is"<<switchmode;
      ui->lineEdit->setText(QString::number(surgicalData.dia));
          //ia1
      ui->lineEdit_9->setText(QString::number(surgicalData.ia1vac));
      ui->lineEdit_10->setText(QString::number(surgicalData.ia1asp));
      ui->lineEdit_7->setText(QString::number(surgicalData.ia2vac));
      ui->lineEdit_8->setText(QString::number(surgicalData.ia2asp));
      ui->lineEdit_5->setText(QString::number(surgicalData.vitcut));
      ui->lineEdit_4->setText(QString::number(surgicalData.vitvac));
      ui->lineEdit_6->setText(QString::number(surgicalData.vitasp));
      ui->vitvacmode->setText(surgicalData.vitvacmode);
      ui->butia2mode->setText(surgicalData.ia1mode);
      ui->butia1mode->setText(surgicalData.ia2mode);
      qDebug()<<surgicalData.ia1asp<<surgicalData.ia2asp<<surgicalData.ia1vac<<surgicalData.ia2vac<<"these are sended from the doctor windiow";


}
void avsmode::setLastSelectedValue()
{

    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(PATH);

        if (!db.open()) {
//            qDebug() << "Error: connection with database failed:";
            return;
        }
    }

    // Prepare and execute the query
    QSqlQuery query(db);
    query.prepare("SELECT lastupdate FROM phacohigh LIMIT 1");
    if (!query.exec()) {
//        qDebug() << "Error retrieving last index:";
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        return;
    }

    if (query.next()) {
           int lastIndex = query.value(0).toInt();

           if (lastIndex >= 0 && lastIndex <= 4) {  // Ensure index is within valid range
               ui->comboBox_4->setCurrentIndex(lastIndex);
               QString surgeonName = ui->comboBox_4->currentText();
  // foot->updateFootpedalComboBoxes(surgeonName);
//               qDebug() << "Last selected surgeon index set to" << lastIndex << "corresponding to surgeon:" << surgeonName;

                // push(ui->comboBox_4->currentText());
           }else {
//        qDebug() << "No index found in the database. Verify the data in the table.";
    }

    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }
}
void avsmode::push(const QString &surgeonName) {

   //qDebug() << "Attempting to fetch data for surgeon:" << surgeonName;
emit sendsurgeon(surgeonName);
    // Check and display available drivers
//    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();

    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE","PATH");
        db.setDatabaseName(PATH); // Ensure PATH is correctly set
    }

    if (!db.isOpen()) {
        if (!db.open()) {
//            //qDebug() << "Failed to open database. Error:" << db.lastError().text();
            return;
        } else {
//            qDebug() << "Database connection opened successfully.";
        }
    } else {
//        qDebug() << "Database is already open.";
    }

    // Prepare a single query to fetch all required data
    QSqlQuery query(db);
    query.prepare(
          "SELECT diapowmax, pump, viberationoff, speakeronoff, "

          "cortexaspmode, cortexvacmode, polishaspmode, polishvacmode, "
          "ia1aspmax, ia1vacmax, ia2aspmax, ia2vacmax, "
          "vitcutmax, vitvacmax, vitaspmax, vitcutmode, vitvacmode, "
          "footleft, footright, footbottomleft, footbottomright, "
          "fzero, fone, ftwo, fthree "
          "FROM phacohigh "
          "WHERE surgeon = :surgeon"
      );
    query.bindValue(":surgeon", surgeonName);

    // Execute the query
    if (!query.exec()) {
//        qDebug() << "Failed to execute query. Error:" << query.lastError().text();
        return;
    }

    // Process the results
    if (query.next()) {



        // Retrieve the values from the query result
        int phacoPowerMax = query.value("diapowmax").toInt();
        QString pump = query.value("pump").toString();
        QString vibeonoff = query.value("viberationoff").toString();
        QString speaker_onoff = query.value("speakeronoff").toString();



        // IA (Irrigation/Aspiration) parameters
        int ia1vacmax = query.value("ia1aspmax").toInt();
        int ia1aspmax = query.value("ia1vacmax").toInt();
        int ia2vacmax = query.value("ia2aspmax").toInt();
        int ia2aspmax = query.value("ia2vacmax").toInt();
        QString ia1mode = query.value("cortexvacmode").toString();
        QString ia2mode = query.value("polishvacmode").toString();

 // qDebug()<<ia1mode<<ia2mode;
        // Vitrectomy parameters
        int vitcutmax = query.value("vitcutmax").toInt();
        int vitvacmax = query.value("vitvacmax").toInt();
        int vitaspmax = query.value("vitaspmax").toInt();
        QString vitcutmode = query.value("vitcutmode").toString();
        QString vitvacmode = query.value("vitvacmode").toString();
        QString footleft = query.value("footleft").toString();
        QString footright = query.value("footright").toString();
        QString footbleft = query.value("footbottomleft").toString();
        QString footbright = query.value("footbottomright").toString();


        int nfpo = query.value("fzero").toInt();
        int nfp1 = query.value("fone").toInt();
        int nfp2 = query.value("ftwo").toInt();
        int nfp3 = query.value("fthree").toInt();
       // qDebug()<<nfpo<<nfp1<<nfp2<<nfp3<<"that is the sql value before calibration";
        nfpzero = static_cast<int>((nfpo / 100.0) * 4090);
        nfpone = static_cast<int>((nfp1 / 100.0) * 4090);
        nfptwo = static_cast<int>((nfp2 / 100.0) * 4090);
        nfpthree = static_cast<int>((nfp3 / 100.0) * 4090);
        vibon=vibeonoff;
        speakeronoff=speaker_onoff;
        avsmodechanging(pump);

        qDebug()<<"the footpedal values are"<<nfpzero<<nfpone<<nfptwo<<nfpthree;

        ui->lineEdit->setText(QString::number(phacoPowerMax));
        ui->lineEdit_9->setText(QString::number(ia1vacmax));
        ui->lineEdit_10->setText(QString::number(ia1aspmax));
        ui->lineEdit_7->setText(QString::number(ia2vacmax));
        ui->lineEdit_8->setText(QString::number(ia2aspmax));
        ui->lineEdit_4->setText(QString::number(vitvacmax));
        ui->lineEdit_5->setText(QString::number(vitcutmax));
        ui->lineEdit_6->setText(QString::number(vitaspmax));
        ui->butia1mode->setText(ia1mode);
        ui->butia2mode->setText(ia2mode);
        ui->vitvacmode->setText(vitvacmode);



        qDebug()<<nfpzero<<nfpone<<nfptwo<<nfpthree<<"that is sql value";
          emit left_foot(footleft);
        emit right_foot(footright);
        emit bottom_left(footbleft);
        emit bottom_right(footbright);
        //qDebug()<<"pump is reterived from the sql"<<pump;
        query.clear();
                //qDebug()<<ia1aspmax<<ia1vacmax<<ia2aspmax<<ia2vacmax<<"these are retereived from the sql";
    } else {
        //qDebug() << "No data found for surgeon:" << surgeonName;
    }
    db.close();
    QSqlDatabase::removeDatabase("PATH");
}

void avsmode::disablefunction()
{
   protimer->start(1);
   Tacutalsensor->start(1);

}


void avsmode::on_butCI_clicked()
{
    QString styleSheetOn = "QPushButton {"
                           "font: 20pt Ubuntu;"
                           "background-color: green;"
                           "color: black;"
                           "image: url(:/images/ci.png);"
                           "border: 5px solid black;"
                           "border-radius: 30px;"
                           "font-weight: bold;"
                           "}";

    QString styleSheetOff = "QPushButton {"
                            "font: 20pt Ubuntu;"
                            "background-color: red;"
                            "image: url(:/images/ci.png);"
                            "border: 5px solid black;"
                            "border-radius: 30px;"
                            "font-weight: bold;"
                            "}";

    // Toggle the overallci state
    overallci = !overallci;

    if (overallci) {
        // Turn ON Continuous Irrigation
        ui->butCI->setStyleSheet(styleSheetOn);
        handler->pinchvalve_on();       // Activate pinch valve
        handler->speaker_on(0, 0, 1, 0); // Activate speaker
    } else {
        // Turn OFF Continuous Irrigation
        ui->butCI->setStyleSheet(styleSheetOff);
        handler->pinchvalve_off();     // Deactivate pinch valve
        handler->speaker_off();        // Deactivate speaker
    }
    ui->butCI->update(); // Ensure UI updates immediately
}

void avsmode::on_SETTINGS_BUT_2_clicked()
{
    in->show();
}

void avsmode::on_butposition_clicked()
{
    foot->show();
}

void avsmode::on_butia1mode_clicked()
{
    handler->buzz();
   ia1= ui->butia1mode->text();

      if(ia1== "Surgeon")
      {

          ui->butia1mode->setStyleSheet(
              "font: 15pt;"
              "image: url(:/images/panelbutton.png);"
              "background-color: transparent;"
              "border: none;"
              "outline: none;"
          );
          ui->butia1mode->setText("Panel");
           footpedalcheck();
              }
      else if(ia1 == "Panel")
      {
          ui->butia1mode->setStyleSheet(
              "font: 15pt;"
              "image: url(:/images/panelbutton.png);"
              "background-color: transparent;"
              "border: none;"
              "outline: none;"
          );
          ui->butia1mode->setText("Surgeon");
          footpedalcheck();
              }
}

void avsmode::on_butia2mode_clicked()
{
    handler->buzz();
   ia2 = ui->butia2mode->text();

      if(ia2 == "Surgeon")
      {
          ui->butia2mode->setText("Panel");
          ui->butia2mode->setStyleSheet(
              "font: 15pt;"
              "image: url(:/images/panelbutton.png);"
              "background-color: transparent;"
              "border: none;"
              "outline: none;"
          );             footpedalcheck();
               }
      else if(ia2 == "Panel")
      {
          ui->butia2mode->setText("Surgeon");
          ui->butia2mode->setStyleSheet(
              "font: 15pt;"
              "image: url(:/images/panelbutton.png);"
              "background-color: transparent;"
              "border: none;"
              "outline: none;"
          ); footpedalcheck();
      }
}

void avsmode::on_vitvacmode_clicked()
{
    handler->buzz();
     vvit=ui->vitvacmode->text();

     if(vvit =="Surgeon")
     {


          ui->vitvacmode->setText("Panel");
          ui->vitvacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
          footpedalcheck();
             }
     else if(vvit == "Panel")
     {

         ui->vitvacmode->setText("Surgeon");
         ui->vitvacmode->setStyleSheet("font:15pt;image: url(:/images/panelbutton.png);background-color:transparent;border:none");
         footpedalcheck();
            }
}


void avsmode::on_butvitonoff_clicked()
{
    QString text = ui->butvitonoff->text();
    // Define the style for "ON" state (green background)
    QString styleSheet1 = "QPushButton {"
                          " font:20pt Ubuntu;"
                          " background-color: green;"
                          " color: black;"
                          " border:5px solid black;"
                          " border-radius:30px;"
                          " font-weight: bold;"
                          "}";

    // Define the style for "OFF" state (red background)
    QString styleSheet2 = "QPushButton {"
                          " font:20pt Ubuntu;"
                          " background-color: rgb(224, 27, 36);"
                          " color: black;"
                          " border:5px solid black;"
                          " border-radius:30px;"
                          " font-weight: bold;"
                          "}";

    // Toggle the vitonoff state
    vitonoff = !vitonoff;

    // Check the current state and update the button text and styles accordingly
    if (vitonoff) {
        ui->butvitonoff->setText("ON");
        ui->butvitonoff->setStyleSheet(styleSheet1);
        ui->butvitup->setEnabled(true);
        ui->butvitdown->setEnabled(true);

    } else {
        ui->butvitonoff->setText("OFF");
        ui->butvitonoff->setStyleSheet(styleSheet2);
        handler->vit_off();
        ui->butvitup->setEnabled(false);
        ui->butvitdown->setEnabled(false);
    }
}
void avsmode::moved(int gpio) {

    QPushButton *buttons1[] = {
         ui->DIABUT, ui->IA1BUT,
         ui->IA2BUT, ui->VITRECTOMYBUT
    };
    int totalButtons1 = sizeof(buttons1) / sizeof(buttons1[0]);

    // Handling for nHandPiece == 1
    if (gpio == 0) {
        if (currentButtonIndex == -1) {
            currentButtonIndex = 0; // Start from DIABUT
        } else {
            currentButtonIndex = (currentButtonIndex + 1) % totalButtons1;
        }

//        // Debugging output
//        qDebug() << "Handpiece 1, GPIO: " << gpio << ", Button Index: " << currentButtonIndex;
//        qDebug() << "Selected Button: " << buttons1[currentButtonIndex]->text();

        // Handle each button's specific action
        if (buttons1[currentButtonIndex] == ui->DIABUT) {
            on_DIABUT_clicked();
        } else if (buttons1[currentButtonIndex] == ui->IA1BUT) {
           on_IA1BUT_clicked();
        } else if (buttons1[currentButtonIndex] == ui->IA2BUT) {
            on_IA2BUT_clicked();
        } else if (buttons1[currentButtonIndex] == ui->VITRECTOMYBUT) {
            on_VITRECTOMYBUT_clicked();
        }

        buttons1[currentButtonIndex]->click();
        buttons1[currentButtonIndex]->setFocus();
    }
}
void avsmode::movePushButtonBottomToTop(int gpio) {

    QPushButton *buttons1[] = {
        ui->DIABUT, ui->IA1BUT,
        ui->IA2BUT, ui->VITRECTOMYBUT
    };

    int totalButtons1 = sizeof(buttons1) / sizeof(buttons1[0]);



        // Handle second set of buttons (buttons1) if nHandPiece == 1 and nHandPiece1 == 0
        if (nHandPiece == 1 && nHandPiece1 == 0) {
            if (currentButtonIndex == -1) {
                currentButtonIndex = totalButtons1 - 1; // Start at the last button
            } else {
                // Handle DIABUT separately for GPIO check
                if (buttons1[currentButtonIndex] == ui->DIABUT && gpio == 0) {
                    // If GPIO is 0, decrement to the previous button
                    currentButtonIndex = (currentButtonIndex - 1 + totalButtons1) % totalButtons1;
                } else {
                    // Move to the previous button (bottom to top)
                    currentButtonIndex = (currentButtonIndex - 1 + totalButtons1) % totalButtons1;
                }
            }

            //qDebug() << "Handpiece 1, GPIO: " << gpio << ", Button Index: " << currentButtonIndex;

            // Handle actions for buttons in buttons1
            if (buttons1[currentButtonIndex] == ui->DIABUT) {
                on_DIABUT_clicked();
                qDebug() << "Diathermy mode triggered";
            } else if (buttons1[currentButtonIndex] == ui->IA1BUT) {
              on_IA1BUT_clicked();
            } else if (buttons1[currentButtonIndex] == ui->IA2BUT) {
                on_IA2BUT_clicked();
            } else if (buttons1[currentButtonIndex] == ui->VITRECTOMYBUT) {
                on_VITRECTOMYBUT_clicked();
            }

            buttons1[currentButtonIndex]->click();
            buttons1[currentButtonIndex]->setFocus();
        }

}
void avsmode::footreflux(int gpio)
{
   reflux=gpio;
    if (gpio == 0) {
        motorccwon();
      //  QTimer::singleShot(1000, [this]() {
      //      motoroff();
       // });

//reflux= 1;       // Update the flag to indicate motor action completed
   // }

   // else{
      //  reflux=0;
    }
}
void avsmode::continousirrigation(int value)
{
    QString styleSheetOn = "QPushButton {"
                           "font: 20pt Ubuntu;"
                           "background-color: green;"
                           "color: black;"
                           "image: url(:/images/ci.png);"
                           "border: 5px solid black;"
                           "border-radius: 30px;"
                           "font-weight: bold;"
                           "}";

    QString styleSheetOff = "QPushButton {"
                            "font: 20pt Ubuntu;"
                            "background-color: red;"
                            "image: url(:/images/ci.png);"
                            "border: 5px solid black;"
                            "border-radius: 30px;"
                            "font-weight: bold;"
                            "}";

    // Adjust Continuous Irrigation based on GPIO input
    if (value == 0 && !overallci) {
        // GPIO indicates to turn ON Continuous Irrigation
        overallci = true;
        ui->butCI->setStyleSheet(styleSheetOn);
        handler->pinchvalve_on();
        handler->buzz(); // Indicate change
    } else if (value == 0 && overallci) {
        // GPIO indicates to turn OFF Continuous Irrigation
        overallci = false;
        ui->butCI->setStyleSheet(styleSheetOff);
        handler->pinchvalve_off();
        handler->buzz(); // Indicate change
    }
    ui->butCI->update(); // Ensure UI updates immediately
}
