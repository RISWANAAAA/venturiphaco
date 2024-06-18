#ifndef FOOTPEDAL_H
#define FOOTPEDAL_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "doctor.h"

#define PATH "phaco1.db"

class doctor;

namespace Ui {
class footpedal;
}

class footpedal : public QDialog
{
    Q_OBJECT

public:
    explicit footpedal(QWidget *parent = nullptr);
    ~footpedal();


private slots:
    void Back();

   // void on_pushButton_2_clicked();

    void SaveForAll();


private:
    Ui::footpedal *ui;
    QString left;
    QString right;
    QString bleft;
    QString bright;
    doctor *d1;
};

#endif // FOOTPEDAL_H
