#include "another.h"
#include "ui_another.h"

another::another(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::another)
{
    ui->setupUi(this);
}

another::~another()
{
    delete ui;
}

void another::setValue(int value) {
    m_value = qBound(0, value, 100);
    update(); // Trigger repaint
}

void another::setValue1(int value) {
    m_value1 = qBound(0, value, 100);
    update();
}

void another::setValue2(int value) {
    m_value2 = qBound(0, value, 100);
    update();
}

void another::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the first progress bar
    QRectF rect1(50, 50, 100, 100);
    painter.setPen(QPen(Qt::lightGray, 40));
    painter.drawEllipse(rect1);
    painter.setPen(QPen(Qt::blue, 10));
    painter.drawArc(rect1, 90 * 16, -m_value * 3.6 * 16);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    painter.drawText(rect1, Qt::AlignCenter, "Power 1");

    // Draw the second progress bar
    QRectF rect2(200, 50, 100, 100);
    painter.setPen(QPen(Qt::lightGray, 40));
    painter.drawEllipse(rect2);
    painter.setPen(QPen(Qt::blue, 10));
    painter.drawArc(rect2, 90 * 16, -m_value1 * 3.6 * 16);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    painter.drawText(rect2, Qt::AlignCenter, "Power 2");

    // Draw the third progress bar
    QRectF rect3(125, 200, 100, 100);
    painter.setPen(QPen(Qt::lightGray, 40));
    painter.drawEllipse(rect3);
    painter.setPen(QPen(Qt::blue, 10));
    painter.drawArc(rect3, 90 * 16, -m_value2 * 3.6 * 16);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    painter.drawText(rect3, Qt::AlignCenter, "Power 3");
}
