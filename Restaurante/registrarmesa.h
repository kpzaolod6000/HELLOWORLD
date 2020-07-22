#ifndef REGISTRARMESA_H
#define REGISTRARMESA_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include "registrarcliente.h"

namespace Ui {
class RegistrarMesa;
}

class RegistrarMesa : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrarMesa(QWidget *parent = nullptr);
    ~RegistrarMesa();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_helados_clicked();

    void on_pushButton_fria_clicked();
    void mostrarpedidos(QString,QString);
    void Saldo();

    void on_pushButton_escojer_clicked();

    void on_pushButton_aumentar_clicked();

    void on_pushButton_quitar_clicked();

    void on_pushButton_reducir_clicked();


    void on_pushButton_registrar_clicked();

    void esconder();

private:
    Ui::RegistrarMesa *ui;
    RegistrarCliente* ventana;

};

#endif // REGISTRARMESA_H
