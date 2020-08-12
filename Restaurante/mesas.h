#ifndef MESAS_H
#define MESAS_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

class Mesas
{
public:
    Mesas(int);
    Mesas();
    Mesas(char*);
    Mesas(QString);
    int getmesa();
    char *getmozos();
    QString getreserva();
};

#endif // MESAS_H
