#ifndef GENERAL_H
#define GENERAL_H

#include <QDialog>

namespace Ui {
class general;
}

class general : public QDialog
{
    Q_OBJECT

public:
    explicit general(QWidget *parent = nullptr);
    ~general();

private slots:
    void About();

    void Storage();

    void Clock();

    void Update_time_date();

    void Network();

    void Back();


private:
    Ui::general *ui;
};

#endif // GENERAL_H
