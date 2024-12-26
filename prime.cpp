#include "prime.h"
#include "ui_prime.h"
#include <QMessageBox>
#include<QTimer>
#include<QFile>
#include<QImage>
#include<QDebug>
#include<QIODevice>
#include<QSqlError>

prime::prime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prime)
{
    ui->setupUi(this);
    move(0,0);
  //  m=new MainWindow;
    sur=new doctor;

    hand=new hwhandler;
    tune=new tuning;
    cleantimer=new QTimer;
    hand->phaco_off();
    hand->phaco_power(0);
    hand->freq_count(0);
    ui->progressBar_2->setRange(0,100);
    hand->fs_count_limit(0);
    hand->phaco_off();
    hand->freq_count(0);
    hand->safetyvent_off();
    hand->pinchvalve_off();
    hand->speaker_off();
    ui->progressBar_2->hide();
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 40pt;"
                         "font:bold;"
                         "    background-color: transparent;"
                         "    image: url(:/images/primeddd.png);"
                         "    color: white;"
                         "    min-width: 380px;"
                         "    max-width: 380px;"
                         "    min-height: 200px;"
                         "    max-height: 200px;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "width: 401;"
                         "height:211;"
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";
    setLastSelectedValue();

    QString tabStyle = "QTabBar::tab:selected { background-color: black; color: #ffffff; border-radius:50px}";
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setStyleSheet("QTabWidget::pane { border: 0; }");
    QString styleSheet3 =
        "QTabBar::tab {"
        "    font-size: 16px; /* Set the font size */"
        "    border-radius: 10px; /* Set the border radius */"
        "}";


    ui-> tabWidget->setStyleSheet(tabStyle);
    ui->tabWidget->setTabText(0 ,"     PRIME        ");
    // ui->tabWidget->setTabText(1,"      TUNE        ");
    ui->tabWidget->setTabText(1,"     CLEAN        ");
    ui->tabWidget->insertTab(1,tune,"    TUNE       ");


    statusUpdateTimer = new QTimer(this);
    serialnumber();
   //
    connect(ui->comboBox_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &prime::onComboBoxIndexChanged);
  connect(this,&prime::sendsurgeon_tune,tune,&tuning::rx_surgeonName);
    //connect(statusUpdateTimer, &QTimer::timeout, this, &prime::onUpdateStatusTimeout);
    // statusUpdateTimer->start(500); // Update every second

     //connect(this,&prime::sendsignal,m,&MainWindow::receivesignal);
    connect(ui->prime1_but,&QPushButton::clicked,this,&prime::Prime);
    //connect(this,&prime::sendcomboBoxsignals,m,&MainWindow::doctorwindow_show);

    //  connect(ui->Tune_but,&QPushButton::clicked,this,&prime::Tune);
    // connect(ui->Start_tune_2,&QPushButton::clicked,this,&prime::Start_Tune);
    connect(ui->clean_but,&QPushButton::clicked,this,&prime::Clean);
    //connect(cleantimer,&QTimer::timeout,this,&prime::on_begin_clean_but_2_clicked);
    //cleantimer->stop();

    connect(ui->prime1_but, &QPushButton::clicked, [=](){
        ui->prime1_but->setStyleSheet(styleSheet);
        ui->prime1_but->move(20,40);
        ui->label->move(20,120);
        ui->prime1_but->raise();
        ui->label->raise();
        hand->buzz();



    });
    connect(ui->Tune_but, &QPushButton::clicked, [=](){
        ui->Tune_but->setStyleSheet(styleSheet);
        ui->Tune_but->move(20,240);
        ui->label_2->move(30,380);
        ui->Tune_but->raise();
        ui->label_2->raise();
hand->buzz();

    });
    connect(ui->clean_but, &QPushButton::clicked, [=](){
        ui->clean_but->setStyleSheet(styleSheet);
        ui->clean_but->move(20,450);
        ui->label_3->move(30,580);
        ui->clean_but->raise();
        ui->label_3->raise();
hand->buzz();

    });
    //timerssss
    timer1=new QTimer;
    pretimer=new QTimer;
    connect(timer1, &QTimer::timeout, this, &prime::timer);
    connect(pretimer,&QTimer::timeout,this,&prime::primetimer);

    QDateTime date = QDateTime::currentDateTime();
    QString formatteddate = date.toString("dd.MM.yyyy");
    ui->lab_date->setText(formatteddate);

    QTime time = QTime::currentTime();
    QString formatTime = time.toString("hh:mm:ss");
    ui->lab_time->setText(formatTime);

    ui->progressBar_2->setRange(0, 100);
    current(1);
    on_Tune_but_clicked();


}

prime::~prime()
{
    delete ui;
    delete timer1;
    delete pretimer;
}
bool prime::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::TouchBegin || event->type() == QEvent::TouchUpdate || event->type() == QEvent::TouchEnd) {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        QList<QTouchEvent::TouchPoint> points = touchEvent->touchPoints();

        foreach (const QTouchEvent::TouchPoint &point, points) {
            if (point.state() == Qt::TouchPointPressed) {
                //qDebug() << "Touch detected at position: " << point.pos();
                // You can perform actions here based on touch events
            }
            if (point.state() == Qt::TouchPointReleased) {
                //qDebug() << "Touch released at position: " << point.pos();
            }
        }
    }
    return QWidget::eventFilter(watched, event);  // Allow default processing
}

void prime::click()
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/tuneddd.png);"
                         "    background-color: transparent;"
                         "    color: white;"
                         "    min-width: 341px;"
                         "    max-width: 341px;"
                         "    min-height: 141px;"
                         "    max-height: 141px;"
                         "    border-radius: 40px;" // Adjust the radius as needed

                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";
    QString style="QLabel{"
                    "image: url(:/images/prime.png);"
                    "background-color:transparent;"
                    "border:none;"
                    "width:71;"
                    "height:71;"
                    "}";
    QString style1="QLabel{"
                     "image: url(:/images/wifi.png);"
                     "background-color:transparent;"
                     "border:none;"
                     "width:71;"
                     "height:71;"
                     "}";

    QString style2="QLabel{"
                     "image: url(:/images/clean.png);"
                     "background-color:transparent;"
                     "border:none;"
                     "width:71;"
                     "height:71;"
                     "}";



    ui->prime1_but->setStyleSheet(styleSheet);
    ui->Tune_but->setStyleSheet(styleSheet);
    ui->clean_but->setStyleSheet(styleSheet);
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label->setStyleSheet(style);
    ui->label_2->setStyleSheet(style1);
    ui->label_3->setStyleSheet(style2);

}
void prime::current(int tab)
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 40pt;"
                         "font:bold;"
                         "    image: url(:/images/primeddd.png);"
                         "    background-color: transparent;"
                         "    color: white;"
                         "    min-width: 380px;"
                         "    max-width: 380px;"
                         "    min-height: 200px;"
                         "    max-height: 200px;"

                         //"    border-radius: 20px;" // Uncomment if needed
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";


    QString styleSheet1 = "QPushButton {"
                          "    font-family: Ubuntu;"
                          "    font-size: 20pt;"
                          "    image: url(:/images/tuneddd.png);"
                          "    background-color: transparent;"
                          "    color: black;"
                          "    min-width: 341px;"
                          "    max-width: 341px;"
                          "    min-height: 141px;"
                          "    max-height: 141px;"
                          //"    border-radius: 40px;" // Uncomment if needed
                          "    font-weight: bold;"  // Corrected from 'font: bold;'

                          "}"
                          "QPushButton:focus {"
                          "    outline: none;"
                          "    border: none;"
                          "}";
    QString style="QLabel{"
                    "image: url(:/images/prime.png);"
                    "background-color:transparent;"
                    "border:none;"
                    "width:71;"
                    "height:71;"
                    "}";
    QString style1="QLabel{"
                     "image: url(:/images/wifi.png);"
                     "background-color:transparent;"
                     "border:none;"
                     "width:71;"
                     "height:71;"
                     "}";

    QString style2="QLabel{"
                     "image: url(:/images/clean.png);"
                     "background-color:transparent;"
                     "border:none;"
                     "width:71;"
                     "height:71;"
                     "}";


    // Reset all buttons to the default style
    ui->prime1_but->setStyleSheet(styleSheet1);
    ui->prime1_but->move(0,70);
    ui->Tune_but->setStyleSheet(styleSheet1);
    ui->Tune_but->move(0,280);
    ui->clean_but->setStyleSheet(styleSheet1);
    ui->clean_but->move(0,500);
    ui->label->setStyleSheet(style);
    ui->label_2->setStyleSheet(style1);
    ui->label_3->setStyleSheet(style2);

    if (tab == 0) {
        ui->prime1_but->setStyleSheet(styleSheet);
        ui->label->setStyleSheet(style);
        ui->prime1_but->move(0,10);
        ui->label->move(30,380);
        ui->prime1_but->raise();
    } else if (tab == 1) {
        ui->Tune_but->setStyleSheet(styleSheet);
        ui->Tune_but->move(20,240);
        ui->label_2->move(30,380);
        ui->label_2->setStyleSheet(style1);
        pretimer->stop();
        timer1->stop();
        ui->Tune_but->raise();
    } else if (tab == 2) {
        ui->clean_but->setStyleSheet(styleSheet);
        ui->label_3->setStyleSheet(style2);
        ui->clean_but->move(20,500);
        ui->label_3->move(30,580);
        pretimer->stop();
        ui->clean_but->raise();
        timer1->stop();

    }
}



void prime::onUpdateStatusTimeout(){
}
void prime::timer(){

}
void prime::primetimer()
{
    int value = ui->progressBar_2->value();
    if (value < 100) {
        ui->progressBar_2->setValue(value + 1);
    }
    else{
        pretimer->stop();

    }
}
void prime::on_start_prime_but_2_clicked()
{
    // Reset progress bar and UI elements
    ui->progressBar_2->setValue(0);
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);

    // Stop any ongoing timers to reset the state
    if (pretimer->isActive()) {
        pretimer->stop();
    }

//    // Ensure motor and irrigation are off before restarting
//    motoroff();
//    hand->pinchvalve_off();
//    hand->safetyvent_off();

    // Buzz to indicate start
    hand->buzz();

    // Begin the priming process
    motoron();
    hand->pinchvalve_on();
  // start_irrigation();
}

void prime::start_irrigation()
{
    // Start irrigation and update UI
   // hand->pinchvalve_on();
    ui->start_check_2->setChecked(true);

    // Start progress bar timer
    pretimer->start(420);

    // Schedule chamber filling
    QTimer::singleShot(15000, this, &prime::champer_Filled);
}

void prime::motoron()
{
    // Turn on the motor and update UI
    hand->write_motor(0x01, 0x03, 40);
    ui->motor_Check_2->setChecked(true);

    // Start progress bar timer
    pretimer->start(420);

    // Schedule irrigation start after motor initialization
    QTimer::singleShot(15000, this, &prime::start_irrigation);
}

void prime::motoroff()
{
    // Turn off the motor
    hand->write_motor(0x00, 0x00, 0);
}

void prime::champer_Filled()
{
    // Update UI for chamber filled
    ui->wait_Check_2->setChecked(true);

    // Continue progress bar timer
    pretimer->start(420);

    // Schedule completion
    QTimer::singleShot(15000, this, &prime::done);
}

void prime::done()
{
    // Finalize the priming process
    ui->done_Check_2->setChecked(true);


    // Turn off hardware controls
    hand->safetyvent_off();
    hand->pinchvalve_off();
    motoroff();
}

void prime::Prime()
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/tuneddd.png);"
                         "    background-color: transparent;"
                         "    color: black;"
                         "    min-width: 341px;"
                         "    max-width: 341px;"
                         "    min-height: 141px;"
                         "    max-height: 141px;"
                         //"    border-radius: 20px;" // Uncomment if needed

                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";
    QString style="QLabel{"
                    "image: url(:/images/prime.png);"
                    "background-color:transparent;"
                    "border:none;"
                    "width:71;"
                    "height:71;"
                    "}";
    ui->label->setStyleSheet(style);

    ui->tabWidget->setCurrentIndex(0);
    ui->prime1_but->raise();
    timer1->stop();
    ui->clean_but->setStyleSheet(styleSheet);
    ui->clean_but->move(0,500);
    ui->Tune_but->setStyleSheet(styleSheet);
    ui->Tune_but->move(0,280);
    ui->label->raise();
    ui->label_2->raise();
    ui->label_3->raise();
    ui->label_2->move(270,360);
    ui->label_3->move(270,570);
    cleantimer->stop();
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);
    ui->progressBar_2->setValue(0);

}

void prime::Tune()
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 60pt;"
                         "font:bold;"
                         "    background-color: transparent;"
                         "    image: url(:/images/primeddd.png);"
                         "    color: white;"
                         "    min-width: 411px;"
                         "    max-width: 411px;"
                         "    min-height: 241px;"
                         "    max-height: 241px;"
                         "    border-radius: 20px;" // Adjust the radius as needed

                         "    color: black;"
                         "    border-radius: 20px;" // Adjust the radius as needed
                         "width: 401;"
                         "height:211;"
                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";
    ui->Tune_but->setStyleSheet(styleSheet);

    ui->Tune_but->move(20,240);
    ui->label_2->move(30,380);
    ui->Tune_but->raise();
    ui->label_2->raise();

}

void prime::comboboxselected()
{
}



void prime::onComboBoxIndexChanged(int index) {
    // Ensure the database connection is valid
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE", "ComboBoxConnection");
        db.setDatabaseName(PATH);
    }

    // Open the database connection
    if (!db.isOpen() && !db.open()) {
        //qDebug() << "Error: connection with database failed:" << db.lastError().text();
        return;
    }

    // Prepare and execute the query to update the last selected index
    QSqlQuery query(db);
    query.prepare("UPDATE phacohigh SET lastupdate = :index");
    query.bindValue(":index", index);
    //emit sendcomboBoxsignals(ui->comboBox_4->currentText());
    // Push the current combo box text

    // m->push(ui->comboBox_4->currentText());
   // emit sendsignal(ui->comboBox_4->currentText());

   // qDebug()<<"the current text is"<<ui->comboBox_4->currentText();

    if (!query.exec()) {
        //qDebug() << "Error updating last selected index:" << query.lastError().text();
    } else {
        //qDebug() << "Last selected index updated to" << index;
    }


    // Close and clean up the database connection
    db.close();
    QSqlDatabase::removeDatabase("ComboBoxConnection");
}

void prime::setLastSelectedValue() {
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE", "connection1");
        db.setDatabaseName(PATH);  // Ensure PATH points to the correct database file
    }

    if (!db.open()) {
        //qDebug() << "Error: connection with database failed:" << db.lastError().text();
        return;
    }

    // Prepare and execute the query
    QSqlQuery query(db);
    query.prepare("SELECT lastupdate FROM phacohigh LIMIT 1");
    if (!query.exec()) {
        //qDebug() << "Error retrieving last index:" << query.lastError().text();
        db.close();
        QSqlDatabase::removeDatabase("connection1");
        return;
    }

    if (query.next()) {
        int lastIndex = query.value(0).toInt();

        if (lastIndex >= 0 && lastIndex <= 4) {  // Ensure index is within valid range
            ui->comboBox_4->setCurrentIndex(lastIndex);
            QString surgeonName = ui->comboBox_4->currentText();
            //qDebug()<<surgeonName<<"the last surgeon is updated";



}
        }

         else {
            //qDebug() << "Invalid index found in the database. Verify the data in the table.";
        }


    // Close and clean up the database connection
    db.close();
    QSqlDatabase::removeDatabase("connection1");
}

void prime::serialnumber() {
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE", "connection2");
        db.setDatabaseName(PATH); // Ensure PATH is correctly set
    }

    if (!db.open()) {
        //qDebug() << "Failed to open database. Error:" << db.lastError().text();
        return;
    }

    QString surgeonName = ui->comboBox_4->currentText();

    // Prepare a single query to fetch the serial number
    QSqlQuery query(db);
    query.prepare(
        "SELECT iNanoPlusVP_SerialNo, "
                "fzero, fone, ftwo "
        "FROM phacohigh "
        "WHERE surgeon = :surgeon"
        );
    query.bindValue(":surgeon", surgeonName);

    if (query.exec()) {
        if (query.next()) {
            QString serialNumber = query.value(0).toString(); // Correct index for the result
            int nfpo = query.value("fzero").toInt();
            int nfp1 = query.value("fone").toInt();
            int nfp2 = query.value("ftwo").toInt();
           // qDebug()<<nfpo<<nfp1<<nfp2<<"that is the sql value before calibration";
            int nfpzero = static_cast<int>((nfpo / 100.0) * 4090);
            int nfpone = static_cast<int>((nfp1 / 100.0) * 4090);
            int nfptwo = static_cast<int>((nfp2 / 100.0) * 4090);
           // qDebug()<<nfpzero<<nfpone<<nfptwo<<"that is the sql value after calibration";

            nFsCount=(nfpzero+nfpone+nfptwo);
           // qDebug()<<"the surgeon name is sended to tune window"<<nFsCount;
            ui->label_6->setText(serialNumber);
            emit sendsurgeon_tune(nFsCount);
           // qDebug()<<"the nfscount is sended to tune window";

        } else {
            //qDebug() << "No data found for the given surgeon.";
            ui->label_6->setText("N/A");
        }
    } else {
        //qDebug() << "Query execution failed:" << query.lastError().text();
    }

    // Close and clean up the database connection
    db.close();
    QSqlDatabase::removeDatabase("connection2");
}

void prime::on_Tune_but_clicked()
{

    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/tuneddd.png);"
                         "    background-color: transparent;"
                         "    color: black;"
                         "    min-width: 341px;"
                         "    max-width: 341px;"
                         "    min-height: 141px;"
                         "    max-height: 141px;"
                         //"    border-radius: 20px;" // Uncomment if needed

                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";
    QString style1="QLabel{"
                     "image: url(:/images/wifi.png);"
                     "background-color:transparent;"
                     "border:none;"
                     "width:71;"
                     "height:71;"
                     "}";

    ui->label_2->setStyleSheet(style1);

    ui->tabWidget->setCurrentIndex(1);
    ui->prime1_but->setStyleSheet(styleSheet);
    ui->clean_but->setStyleSheet(styleSheet);
    tune->updatehandpieceStatus();
    ui->prime1_but->setStyleSheet(styleSheet);
    ui->prime1_but->move(0,80);
    ui->clean_but->setStyleSheet(styleSheet);
    ui->clean_but->move(0,500);
    ui->label->move(270,140);
    ui->label_3->move(270,570);
    ui->label->raise();
    ui->label_2->raise();
    ui->label_3->raise();
    cleantimer->stop();
    emit sendsurgeon_tune(nFsCount);


}

void prime::Clean()
{
    QString styleSheet = "QPushButton {"
                         "    font-family: Ubuntu;"
                         "    font-size: 20pt;"
                         "    image: url(:/images/tuneddd.png);"
                         "    background-color: transparent;"
                         "    color: black;"
                         "    min-width: 341px;"
                         "    max-width: 341px;"
                         "    min-height: 141px;"
                         "    max-height: 141px;"
                         //"    border-radius: 20px;" // Uncomment if needed

                         "}"
                         "QPushButton:focus {"
                         "    outline: none;"
                         "    border: none;"
                         "}";
    QString style2="QLabel{"
                     "image: url(:/images/clean.png);"
                     "background-color:transparent;"
                     "border:none;"
                     "width:71;"
                     "height:71;"
                     "}";
    ui->label_3->setStyleSheet(style2);

    ui->tabWidget->setCurrentIndex(2);
    pretimer->stop();
    ui->prime1_but->setStyleSheet(styleSheet);
    ui->prime1_but->move(0,80);
    ui->Tune_but->setStyleSheet(styleSheet);
    ui->Tune_but->move(0,280);
    ui->label->move(270,140);
    ui->label_2->move(270,360);
    ui->label->raise();
    ui->label_2->raise();
    ui->label_3->raise();
}


void prime::Start_Tune()
{
    // Stop the motor and pinch valve after 1 minute
    motoroff();
    hand->pinchvalve_off();

    // Optionally provide feedback for the end of the cleaning process
    hand->buzz();

    // Stop the clean timer
    if (cleantimer->isActive()) {
        cleantimer->stop();
    }

    // Update UI to indicate cleaning is complete
    ui->done_Check_2->setChecked(true);

}
void prime::on_begin_clean_but_2_clicked()
{
    // Provide feedback (e.g., a buzz to indicate start)
    hand->buzz();

    // Reset the UI indicators
    ui->start_check_2->setChecked(false);
    ui->motor_Check_2->setChecked(false);
    ui->wait_Check_2->setChecked(false);
    ui->done_Check_2->setChecked(false);

    // Reset the progress bar
    ui->progressBar_2->setValue(0);

    // Ensure timers are stopped before starting the clean process
    if (pretimer->isActive()) {
        pretimer->stop();
    }

    // Start the motor and pinch valve
    motoron();
    hand->pinchvalve_on();

    // Start the clean timer for 1 minute (60000 ms)
    cleantimer->start(60000);

    // Connect the timer's timeout signal to a cleanup slot if necessary
    connect(cleantimer, &QTimer::timeout, this, &prime::Start_Tune);
}

