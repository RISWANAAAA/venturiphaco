#include "tuning.h"
#include "ui_tuning.h"

tuning::tuning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tuning)
{
    ui->setupUi(this);
    // Initialize the timer for updating the progress bar
    main=new MainWindow;
    timer = new QTimer(this);
    hand=new hwhandler;
    handpiece=new QTimer;
    vacSensor=new Vaccum;
    exportGPIO(960);
    setGPIODirection("in",960);
    readGPIOValue(960);
    connect(handpiece,&QTimer::timeout,this,&tuning::updatehandpieceStatus);
    handpiece->start(10);
     ui->But_value->hide();
    ui->But_value->setStyleSheet("font-size: 90px; font-weight: bold; color: white; background-color: transparent;");
    ui->But_Tune->show();
    currentCircle = 0;
    timer1=new QTimer;
    connect(timer1, &QTimer::timeout, this, &tuning::updateCircle);
    connect(ui->But_Tune,&QPushButton::clicked,this,&tuning::on_pushButton_clicked);
    connect(this,&tuning::sendfreq,main,&MainWindow::nReceiveFreq);
    connect(this,&tuning::activatemain,main,&MainWindow::disablefunction);

}

tuning::~tuning()
{
    delete ui;
}
void tuning::exportGPIO(int pin)
{
    QFile file("/sys/class/gpio/export");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << pin;
        file.close();
    }
}

void tuning::setGPIODirection(const QString &direction,int pin)
{
    QFile file(QString("/sys/class/gpio/gpio%1/direction").arg(pin));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << direction;
        file.close();

    }
}

int tuning::readGPIOValue(int pin)
{
    QFile file(QString("/sys/class/gpio/gpio%1/value").arg(pin));
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        int value;
        stream >> value;
        file.close();

        return value;
    }
}

void tuning::updatehandpieceStatus()
{
     statushp = readGPIOValue(960);
    QString styleSheet4 = "QPushButton {"
          "image: url(:/images/connected.png);"
            "border:none;"
            "background-color:transparent;"
 "}";
    QString styleSheet5 = "QPushButton {"
            "image: url(:/images/notconnected.png);"
         "border:none;"
            "background-color:transparent;"
                                     "}";
   if(statushp==0)
   {
       ui->But_Handpiece->setStyleSheet(styleSheet4);
       ui->But_Tune->setEnabled(true);
       ui->But_value->setEnabled(true);


       // ui->But_Next->hide();
   }
   else if(statushp==1)
   {
     //  qDebug()<<status;
       ui->But_Handpiece->setStyleSheet(styleSheet5);
       ui->But_Tune->setEnabled(false);
       ui->But_value->hide();
       ui->But_Tune->move(170, 280); // Move button back to starting position
       ui->But_Tune->resize(541, 141); // Resize button back to original size
       ui->But_Handpiece->show();

       isRunning=false;
     //  ui->But_Next->show();

   }
}
void tuning::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    update(); // Trigger paint event on resize
}

void tuning::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor("#0C2852")); // Replace with your color
    // Ensure we handle the event properly
    if (!event) return; // Check for a valid event
    // Define the circle parameters
    int width = qMin(this->width(), this->height());
    QPoint center = rect().center();
    int radius = 200;
    // Calculate active lines based on progress
    int totalLines = 100;
    int activeLines = (m_value * totalLines) / 100;
    double angleStep = 360.0 / totalLines;

    // Draw lines around the circle
    for (int i = 0; i < totalLines; ++i) {
        double angle = angleStep * i - 270;
        double radAngle = qDegreesToRadians(angle);

        // Calculate line points
        int x1 = center.x() + (radius - 10) * qCos(radAngle);
        int y1 = center.y() + (radius - 10) * qSin(radAngle);
        int x2 = center.x() + radius * qCos(radAngle);
        int y2 = center.y() + radius * qSin(radAngle);

        // Set pen for lines
        QPen pen;
        pen.setWidth(8);
        pen.setColor(i < activeLines ? QColor("#e0e0e0") : QColor("#00050B")); // Active/Inactive colors
        painter.setPen(pen);
        painter.drawLine(x1, y1, x2, y2);
    }

    // Call your custom painting function
    paintEvent1(event); // Ensure this function is safe as well
}
void tuning::paintEvent1(QPaintEvent *event)
{
    Q_UNUSED(event); // Unused event parameter

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Define radii for each circle (smallest first for inner to outer drawing)
    int radii[14] = {30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290}; // Radii from smallest to largest
    int totalLines = 60; // Total number of lines for a full circle

    // Define a base center for positioning all circles
    int baseOffsetX = 430; // Base horizontal position (center of circles)
    int baseOffsetY = 450; // Base vertical position (center of circles)

    // Define colors for each circle
    QColor colors[14] = {
        QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"),
        QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"),
        QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"),
        QColor("#C0C0C0"), QColor("#33FF57") // The last color will always be green
    };


    // Calculate how many circles are fully completed based on m_value
    //int completedCircles = ((nADCValue/14) * 20) / 100; // Assuming m_value is in percentage (0 to 100)
    //int completedCircles = ((nADCValue/4096) * 300.0); // Assuming m_value is in percentage (0 to 100)

    int circle=(int)(nADCValue-1024)*10.0/4096;


    // Draw each circle based on the currentCircle index (from inner to outer)
    for (int j = 0; j < circle; ++j) {
        //int completedCircles = ((nADCValue/4096) * 300.0);
        //int radius = radii[j]; // Current circle radius (starting from inner, moving to outer)
        int radius=radii[j];

        if(j>circle){
            break;
        }
        // Define the angle step for each line (360 degrees divided by total lines)
        double angleStep = 360.0 / totalLines;

        // Center for all circles is the same
        QPoint center(baseOffsetX, baseOffsetY); // Common center for all circles

        // Draw the line shapes around the full circle
        for (int i = 0; i < totalLines; ++i) {
            // Calculate the angle for the current line, starting from 0 degrees
            double angle = angleStep * i;

            // Convert angle to radians for trigonometric functions
            double radAngle = qDegreesToRadians(angle);
            int x1 = center.x() + (radius - 10) * qCos(radAngle);
            int y1 = center.y() + (radius - 10) * qSin(radAngle);
            int x2 = center.x() + radius * qCos(radAngle);
            int y2 = center.y() + radius * qSin(radAngle);

            // Set the pen for bold lines
            QPen pen;

            // Set the color for the entire circle if it is fully completed, else gray
            if (circle) {
                pen.setColor(colors[j % 14]); // Assign color based on circle index
            } else {
                pen.setColor(QColor("#C0C0C0")); // Inactive lines (gray)
            }

            // Ensure the last circle is always green
            if (j == 13) {
                pen.setColor(QColor("#33FF57")); // Always green for the last circle
            }

            painter.setPen(pen); // Apply the pen settings
            painter.drawLine(x1, y1, x2, y2); // Draw the line
        }
    }

}
int tuning::ADC_value(){
    int value=vacSensor->convert(0XA7);
    return value;
}

void tuning::updateCircle()
{
    if (currentCircle < 13) { // Ensure we stay within the bounds (0-4)
        currentCircle++; // Move to the next circle
    } else {
        currentCircle = 0; // Reset to the first circle
    }
    update(); // Repaint the widget to reflect changes
}
//handpiece
void tuning::on_But_Handpiece_clicked()
{
    if (!isRunning) { // Only start if the progress is not currently running
    //       ui->But_Tune->move(150, 230);
        ui->But_Handpiece->hide();
           ui->But_value->setStyleSheet("font-size: 90px; font-weight: bold; color: white; background-color: transparent;");

           ui->But_value->show();

Tune_Phaco();
    }
}
//button value
void tuning::on_But_value_clicked()
{
    if (!isRunning) { // Only start if the progress is not currently running
           ui->But_Tune->move(170, 330);
           ui->But_Handpiece->hide();

           ui->But_value->setStyleSheet("font-size: 90px; font-weight: bold; color: white; background-color: transparent;");

           ui->But_value->show();

Tune_Phaco();
    }
}
// Slot for handling the button click
void tuning::on_pushButton_clicked()
{
    if (!isRunning) { // Only start if the progress is not currently running
        ui->But_Tune->move(170, 330);
        ui->But_Handpiece->hide();
        ui->But_value->setStyleSheet("font-size: 90px; font-weight: bold; color: white; background-color: transparent;");
        ui->But_value->show();

Tune_Phaco();
    }
}

// Update the circle which reaches 100 and then moves to MainWindow
void tuning::updateProgress()
{
    m_value = 0; // Reset value
    ui->But_value->setText(QString::number(m_value)); // Update label to show 0
      ui->But_value->move(400, 270); // Move label if necessary

    ui->But_value->show(); // Show the label
    update();
    ui->But_Tune->move(170, 280); // Move button back to starting position
    ui->But_Tune->resize(541, 141); // Resize button back to original size
  //  ui->But_Handpiece->show();
    // ui->But_Handpiece->move(270,360);
    // ui->But_Handpiece->resize(141,131);
   timer1->stop();


}


int tuning::Tune_Phaco()
{

    int phacoPower=0;
    int nFreqCount;
    int loop1;
    long int nAveADC7841CurrentCount;
    int nADC7841CurrentCountPrev;
    int nADC7841CurrentCount1=0;
    int nADC7841CurrentCount[1024];
    int nInvADC7841CurrentCount[1024];
    int nResonantFreqCount;
    int nAveFeedBack;
    int iCount;
    int nNoOfCurrentCount;
    int ntmpDiffVolt;
    int loopcounter;
    int arrayCounter;
    static int fileCounter;
    float fResFrequency;
    bool trueFreqFound=false;
    int nLowCountValue=0;
    int nLowValueFreq=0;
    int i=0;
    int nResonantPosition;


    updateProgress();
    // Start the timer if it's not running
    if (!isRunning) {
        ui->But_value->show();
        isRunning = true; // Set the running status
        ui->But_Tune->move(150, 260);
        ui->But_Tune->resize(271, 171);
        timer1->start(100);
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString dateTimeString = currentDateTime.toString("yyyy-MM-dd_HH-mm-ss");  // e.g., 20240924_142530
        QDir dir = QDir("/home/tune/");
        QString fileName = dir.path()+"/" + QString("tuning_%1.dat").arg(dateTimeString);

        QFile file(fileName);

        qDebug()<<fileName;

        QTextStream out(&file);

        file.open(QIODevice::WriteOnly | QIODevice::Text);
        qDebug()<<"file opend";


        hand->phaco_power(100);
        //hand->phaco_on();
        hand->emitTunePhaco();

        nNoOfCurrentCount=0;
        // Loop until m_value reaches 100
        qDebug()<<"PHACO_ON";
        for (iCount=TUNE_LOWERFREQ_COUNT; iCount >= TUNE_HIGHFREQ_COUNT; iCount--) {
            hand->freq_count(iCount);


            nAveADC7841CurrentCount =0;
            nADC7841CurrentCount1 =0;
            for(loop1=0;loop1<1024;loop1++){
                nADC7841CurrentCount1 = vacSensor->convert(ADS7841_CURRENTSENSOR_CH2);
                nADCValue=nADC7841CurrentCount1;
                nAveADC7841CurrentCount += nADC7841CurrentCount1;

            }
            nADC7841CurrentCount[nNoOfCurrentCount] = (int) ((nAveADC7841CurrentCount/1024.0));
            //qDebug()<<100000.0/(TUNE_LOWERFREQ_COUNT-nNoOfCurrentCount)<<nADC7841CurrentCount[nNoOfCurrentCount];
            // Update the UI
            nNoOfCurrentCount++;



            m_value=(int)(nNoOfCurrentCount*90.0/(TUNE_LOWERFREQ_COUNT-TUNE_HIGHFREQ_COUNT));
            ui->But_value->setText(QString::number(m_value)); // Update label with current value

            update();

            QCoreApplication::processEvents(); // Process events
           // usleep(5000); // Sleep for a while to create the effect
        }

        for(int nLoop=0;nLoop<nNoOfCurrentCount;nLoop++){
            nInvADC7841CurrentCount[nLoop]=4096-nADC7841CurrentCount[nLoop];
            out<<100000.0/(TUNE_LOWERFREQ_COUNT-nLoop)<<"\t"<<nInvADC7841CurrentCount[nLoop]<<"\n";

        }


        for(i=0;i<nNoOfCurrentCount;i++)
        {
            //qDebug()<<i<<nInvADC7841CurrentCount[i] << nLowCountValue;
            if ((nInvADC7841CurrentCount[i] > nLowCountValue)){
                nLowCountValue =  nInvADC7841CurrentCount[i];
                nLowValueFreq = i;
                //qDebug()<<"Value="<<nLowValueFreq<<","<<nLowCountValue<<nInvADC7841CurrentCount[i];
            }
        }

        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT - (nLowValueFreq))<<","<<nInvADC7841CurrentCount[nLowValueFreq]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT - (nLowValueFreq-50))<<","<<nInvADC7841CurrentCount[nLowValueFreq-50]<<" radius 0.01"<<"\n";


        for(i=nLowValueFreq-50;i<nLowValueFreq;i++){
            if ((nInvADC7841CurrentCount[i] < nInvADC7841CurrentCount[i+2]) && (nInvADC7841CurrentCount[i+2] < nInvADC7841CurrentCount[i+4]) && (nInvADC7841CurrentCount[i+4] < nInvADC7841CurrentCount[i+6]) && (nInvADC7841CurrentCount[i] < nInvADC7841CurrentCount[i-2])){

                trueFreqFound = true;
                nResonantFreqCount=TUNE_LOWERFREQ_COUNT-i;
                nResonantPosition=i;
                nADC7841CurrentCountPrev=nADC7841CurrentCount[i];
                //qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT - i)<<","<<nInvADC7841CurrentCount[i]<<" radius 0.01"<<"\n";
                //qDebug()<<i<<100000.0/(TUNE_LOWERFREQ_COUNT - i)<<nInvADC7841CurrentCount[i]<<nADC7841CurrentCount[i];
                break;
            }
            else{
                // qDebug()<<nADC7841CurrentCount[i] << nADC7841CurrentCount[nLowValueFreq];
                trueFreqFound = false;
            }
        }
        //qDebug()<<"set object circle at " <<100000.0/nResonantFreqCount<<","<<nADC7841CurrentCount[nLowValueFreq]<<" radius 0.01"<<"\n";
        //qDebug()<<"set object circle at " <<100000.0/nResonantFreqCount<<","<<nInvADC7841CurrentCount[nLowValueFreq]<<" radius 0.01"<<"\n";

        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-1))<<","<<nInvADC7841CurrentCount[nLowValueFreq-1]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-2))<<","<<nInvADC7841CurrentCount[nLowValueFreq-2]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-3))<<","<<nInvADC7841CurrentCount[nLowValueFreq-3]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-4))<<","<<nInvADC7841CurrentCount[nLowValueFreq-4]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-5))<<","<<nInvADC7841CurrentCount[nLowValueFreq-5]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-6))<<","<<nInvADC7841CurrentCount[nLowValueFreq-6]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-7))<<","<<nInvADC7841CurrentCount[nLowValueFreq-7]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-8))<<","<<nInvADC7841CurrentCount[nLowValueFreq-8]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-9))<<","<<nInvADC7841CurrentCount[nLowValueFreq-9]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-10))<<","<<nInvADC7841CurrentCount[nLowValueFreq-10]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-11))<<","<<nInvADC7841CurrentCount[nLowValueFreq-11]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-12))<<","<<nInvADC7841CurrentCount[nLowValueFreq-12]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-13))<<","<<nInvADC7841CurrentCount[nLowValueFreq-13]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-14))<<","<<nInvADC7841CurrentCount[nLowValueFreq-14]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-15))<<","<<nInvADC7841CurrentCount[nLowValueFreq-15]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-16))<<","<<nInvADC7841CurrentCount[nLowValueFreq-16]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-17))<<","<<nInvADC7841CurrentCount[nLowValueFreq-17]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-18))<<","<<nInvADC7841CurrentCount[nLowValueFreq-18]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-19))<<","<<nInvADC7841CurrentCount[nLowValueFreq-19]<<" radius 0.01"<<"\n";
        qDebug()<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT-(nLowValueFreq-20))<<","<<nInvADC7841CurrentCount[nLowValueFreq-20]<<" radius 0.01"<<"\n";


        nResonantFreqCount=TUNE_LOWERFREQ_COUNT-(nLowValueFreq-20);

        fResFrequency = 100000.0/nResonantFreqCount;

        qDebug()<<fResFrequency<<nADC7841CurrentCount[nResonantPosition];


        if (nLowValueFreq < 5){
            qDebug()<<"Error < 5";
            hand->phaco_off();
            hand->phaco_power(0);
            trueFreqFound=false;
            return -1;
        }
        else{
            if ( nADC7841CurrentCountPrev >= 3100){

                hand->phaco_power(100);
                hand->freq_count(nResonantFreqCount);
                usleep(50);
                nAveFeedBack=0;
                for(iCount=0;iCount<100;iCount++){
                    nAveADC7841CurrentCount =0;
                    for(loop1=0;loop1<1024;loop1++){
                        nADC7841CurrentCount1=vacSensor->convert(ADS7841_CURRENTSENSOR_CH2);
                        nAveADC7841CurrentCount += nADC7841CurrentCount1;
                    }
                    nADC7841CurrentCount1 = (int) (nAveADC7841CurrentCount/1024.0);
                    nAveFeedBack += nADC7841CurrentCount1;
                    // qDebug()<<iCount<<nADC7841CurrentCount1;
                    m_value=90+(int)(iCount/10.0);
                    //qDebug()<<m_value;
                    ui->But_value->setText(QString::number(m_value)); // Update label with current value
                    QCoreApplication::processEvents(); // Process events
                    //usleep(100);
                }
                fResFrequency = (int)(nAveFeedBack/100.0);
                ntmpDiffVolt = abs(nADC7841CurrentCountPrev - fResFrequency);
                //qDebug()<<nADC7841CurrentCountPrev<<fResFrequency<<"diff "<<ntmpDiffVolt;
                hand->phaco_off();
                hand->phaco_power(0);


                qDebug()<<"diff "<<ntmpDiffVolt;
                if(ntmpDiffVolt<500){
                    if(nADC7841CurrentCountPrev > 4095){

                        qDebug()<<"Tune Completed H"<<nResonantFreqCount;

                    }
                    else{
                        qDebug()<<"Tune Completed H"<<nResonantFreqCount;
                       // return nResonantFreqCount;

                    }
                    //nTuneFreq=nResonantFreqCount;


                }

            }


        }
        out<<"set object circle at " <<100000.0/(TUNE_LOWERFREQ_COUNT - (nLowValueFreq+25))<<","<<nADC7841CurrentCount[nLowValueFreq+25]<<" radius 0.01\n";

        isRunning = false;
        hand->phaco_off();
        main->show();
        main->ULTRASONICBUT1();
        main->setTuneMode();
        updateProgress();
        emit sendfreq(nResonantFreqCount);
        emit activatemain();
        qDebug()<<nResonantFreqCount;
        if(statushp==0){
            ui->But_Handpiece->hide();
        ui->But_value->setStyleSheet("border:none;background-color:transparent;image: url(:/images/doubled.png);outline:none");
             ui->But_value->move(680,270);
            ui->But_value->resize(141,131);
             ui->But_value->show();
        }else{
            ui->But_value->setEnabled(false);
            ui->But_value->hide();
            ui->But_value->setStyleSheet("border:none;background-color:transparent;image: url(:/images/singletick.png);outline:none");

        }
        file.close();

    }

    return 0;
}



void tuning::on_But_Next_clicked()
{
    main->show();
    emit activatemain();

}
