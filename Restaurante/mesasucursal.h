#ifndef MESASUCURSAL_H
#define MESASUCURSAL_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include "registrarmesa.h"
#include "mesas.h"

namespace Ui {
class MesaSucursal;
}

class MesaSucursal : public QDialog
{
    Q_OBJECT

public:
    explicit MesaSucursal(QWidget *parent = nullptr);
    ~MesaSucursal();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_mesa1_clicked();

    void on_pushButton_mesa2_clicked();

    void on_pushButton_mesa3_clicked();

    void on_pushButton_mesa4_clicked();

    void on_pushButton_mesa5_clicked();

    void on_pushButton_mesa6_clicked();

    void on_pushButton_mesa7_clicked();

    void on_pushButton_mesa8_clicked();

private:
    Ui::MesaSucursal *ui;
    RegistrarMesa* ventana;
    Mesas* mesas;
    Mesas* queryenvio;
};

#endif // MESASUCURSAL_H
