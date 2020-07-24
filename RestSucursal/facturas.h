#ifndef FACTURAS_H
#define FACTURAS_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include <QRandomGenerator64>
#include "mesas.h"

namespace Ui {
class Facturas;
}

class Facturas : public QDialog
{
    Q_OBJECT

public:
    explicit Facturas(QWidget *parent = nullptr,QString codigo = nullptr,QStringList* nombre = nullptr,QStringList* precio = nullptr,QStringList* cantidad = nullptr);
    ~Facturas();

private slots:

    void on_pushButton_cancelar_clicked();
    void mostrar();

private:
    Ui::Facturas *ui;
    QString codigo;
    QStringList nombre;
    QStringList precio;
    QStringList cantidad;
    Mesas* mesas;
};

#endif // FACTURAS_H
