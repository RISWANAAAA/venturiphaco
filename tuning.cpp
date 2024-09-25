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
    exportGPIO(960);
    setGPIODirection("in",960);
    readGPIOValue(960);
     ui->label->hide();
      ui->label->setStyleSheet("font-size: 70px; font-weight: bold; color: #00050B; background-color: transparent;");
      connect(handpiece,&QTimer::timeout,this,&tuning::updatehandpieceStatus);
      handpiece->start(100);
    connect(timer, &QTimer::timeout, [=]() {
        if (m_value < 100) {
            m_value++;
            ui->label->setText(QString::number(m_value));
            ui->label->move(360,180);
        } else {
            ui->pushButton->show();
            ui->pushButton->setText("Tune is completed");
            main->show();
            main->setTuneMode(true);
            main->DIATHERMYBUT();
            timer1->stop();// Stop the timer when reaching 100
            isRunning = false;         // Update running status
        }
        update(); // Repaint the circular progress
    });
    currentCircle = 0; // Initialize to start with the first circle
timer1=new QTimer;
    connect(timer1, &QTimer::timeout, this, &tuning::updateCircle);
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
    int status = readGPIOValue(960);


    QString styleSheet4 = "QLabel {"
          "image: url(:/images/connected.png);"
            "border:none;"
            "background-color:transparent;"


 "}";

    QString styleSheet5 = "QLabel {"

            "image: url(:/images/notconnected.png);"

         "border:none;"
            "background-color:transparent;"

                                     "}";

   if(status==0)
   {
       ui->label_2->setStyleSheet(styleSheet4);
//       ui->label->setStyleSheet("background-color:transparent;");

      // qDebug()<<"handpiece on"<<status;
       ui->pushButton->setEnabled(true);



   }
   else
   {
       ui->label_2->setStyleSheet(styleSheet5);
       ui->pushButton->setEnabled(false);
   //      ui->label->setStyleSheet("background-color:transparent;");

   }
}
void tuning::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    update(); // Trigger paint event on resize
}


void tuning::paintEvent(QPaintEvent *event)
{

    // Start painting
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set the background color
    painter.fillRect(rect(), QColor("#DEDDDA")); // Replace with your color

    // Ensure we handle the event properly
    if (!event) return; // Check for a valid event

    // Define the circle parameters
    int width = qMin(this->width(), this->height());
    QPoint center = rect().center();
    int radius = 200;

    // Calculate active lines based on progress
    int totalLines = 80;
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
        pen.setColor(i < activeLines ? QColor("#00050B") : QColor("#e0e0e0")); // Active/Inactive colors
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
    int baseOffsetX = 40; // Base horizontal position (center of circles)
    int baseOffsetY = 421; // Base vertical position (center of circles)

    // Define colors for each circle
    QColor colors[14] = {
        QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"),
        QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"),
        QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"), QColor("#C0C0C0"),
        QColor("#C0C0C0"), QColor("#33FF57") // The last color will always be green
    };

    // Calculate how many circles are fully completed based on m_value
    int completedCircles = (m_value * 20) / 100; // Assuming m_value is in percentage (0 to 100)

    // Draw each circle based on the currentCircle index (from inner to outer)
    for (int j = 0; j <= currentCircle; ++j) {
        int radius = radii[j]; // Current circle radius (starting from inner, moving to outer)

        // Check if the entire circle should be fully colored (if it is completed)
        bool fullCircle = (j < completedCircles);

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
            pen.setWidth(5); // Set the width for bold lines

            // Set the color for the entire circle if it is fully completed, else gray
            if (fullCircle) {
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
void tuning::updateCircle()
{
    if (currentCircle < 13) { // Ensure we stay within the bounds (0-4)
        currentCircle++; // Move to the next circle
    } else {
        currentCircle = 0; // Reset to the first circle
    }
    update(); // Repaint the widget to reflect changes
}

void tuning::on_pushButton_clicked()
{
    // Start the timer if it's not running
    circleColor = (isRunning) ? QColor("#C0C0C0") : QColor("#C0C0C0");

    // Reset progress if already at 100 or if it's not running
      if (m_value >= 100 || !isRunning) {
          m_value = 0; // Reset progress
          ui->label->setText(QString::number(m_value)); // Update label
      }
      hand->freq_count(2500);
      hand->phaco_on();
      hand->phaco_power(80);
      // Start the timer if not running
      timer->start(500); // Update every 100 milliseconds
      // Start the timer automatically with an interval of 1 second
      timer1->start(1000);
      isRunning = true; // Set the running status
      ui->pushButton->hide();
      ui->label->show();
      connect(timer, &QTimer::timeout, this, &tuning::updateProgress);

}
void tuning::updateProgress()
{
    // Increment the progress value
    m_value += 10; // Or however you want to increase the value

    // Update the label with the new value
    ui->label->setText(QString::number(m_value));

    // Check if m_value has reached or exceeded 100
    if (m_value >= 100) {
        m_value = 0; // Reset the value back to 0
        ui->label->setText(QString::number(m_value)); // Update label with 0
    }
}
