#ifndef REGISTRARCLIENTE_H
#define REGISTRARCLIENTE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <cstdlib>
#include <QRandomGenerator64>
#include "facturas.h"
#include "mesas.h"
namespace Ui {
class RegistrarCliente;
}

class RegistrarCliente : public QDialog
{
    Q_OBJECT

signals:
    void back();
public:
    explicit RegistrarCliente(QWidget *parent = nullptr,QStringList* nombre = nullptr,QStringList* precio = nullptr,QStringList* cantidad = nullptr);
    ~RegistrarCliente();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_guardar_clicked();

private:
   Ui::RegistrarCliente *ui;
   QStringList nombre_;
   QStringList precio_;
   QStringList cantidad_;
   Facturas* ventana;
   Mesas* mesas;
};

#endif // REGISTRARCLIENTE_H
