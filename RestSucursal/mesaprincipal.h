#ifndef MESAPRINCIPAL_H
#define MESAPRINCIPAL_H

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
class MesaPrincipal;
}

class MesaPrincipal : public QDialog
{
    Q_OBJECT

public:
    explicit MesaPrincipal(QWidget *parent = nullptr);
    ~MesaPrincipal();

private slots:
    void on_pushButton_atras_clicked();

    void on_pushButton_mesa1_clicked();

    void on_pushButton_mesa2_clicked();

    void on_pushButton_mesa3_clicked();

    void on_pushButton_mesa4_clicked();

    void on_pushButton_mesa5_clicked();

    void on_pushButton_mesa6_clicked();

    void on_pushButton_mesa7_clicked();

    void on_pushButton_mesa8_clicked();

private:
    Ui::MesaPrincipal *ui;
    RegistrarMesa* ventana;
    Mesas* mesas;
    Mesas* queryenvio;
};

#endif // MESAPRINCIPAL_H
