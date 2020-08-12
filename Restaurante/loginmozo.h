#ifndef LOGINMOZO_H
#define LOGINMOZO_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include "escojermesa.h"
#include "mesasucursal.h"
#include "mesas.h"

namespace Ui {
class LoginMozo;
}

class LoginMozo : public QDialog
{
    Q_OBJECT

public:
    explicit LoginMozo(QWidget *parent = nullptr,QString reservar = nullptr);
    ~LoginMozo();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::LoginMozo *ui;
    //RegistrarMesa* ventana;
    EscojerMesa* ventana;
    MesaSucursal* sucursal;
    Mesas* mesas;
    QString reservar;
};

#endif // LOGINMOZO_H
