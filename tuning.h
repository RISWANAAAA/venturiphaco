#ifndef TUNING_H
#define TUNING_H

#include <QDialog>
#include<QPainter>
#include<QTimer>
#include<QtMath>
#include"mainwindow.h"
#include"hwhandler.h"
namespace Ui {
class tuning;
}

class tuning : public QDialog
{
    Q_OBJECT

public:
    explicit tuning(QWidget *parent = nullptr);
    ~tuning();
    // Sets the progress value (0-100)
    void setValue(int value);
    void updateCircle();
    void resizeEvent(QResizeEvent *event);
    void exportGPIO(int pin);
    void setGPIODirection(const QString &direction,int pin);
    int readGPIOValue(int pin);
    void updatehandpieceStatus();
    void updateProgress();

protected:
    // Override paintEvent to draw the circular progress bar
    void paintEvent(QPaintEvent *event) override;
    void paintEvent1(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::tuning *ui;
    int m_value; // Holds the current value of the progress (0 to 100)
    int m_value1; // Holds the current value of the progress (0 to 100)
    int currentCircle;
    QTimer *timer;
     bool isRunning=false;
     QTimer *timer1;
      QColor circleColor; // New member variable for color
      MainWindow *main;
      hwhandler *hand;
      QTimer *handpiece;
};

#endif // TUNING_H
