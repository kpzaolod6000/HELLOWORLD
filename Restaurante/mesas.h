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
    Mesas(QSqlQuery query);
    int getmesa();
    char *getmozos();
    QSqlQuery enviarquey();
};

#endif // MESAS_H
