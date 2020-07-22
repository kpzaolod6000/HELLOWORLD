#ifndef REPORTES_H
#define REPORTES_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>

namespace Ui {
class Reportes;
}

class Reportes : public QDialog
{
    Q_OBJECT

public:
    explicit Reportes(QWidget *parent = nullptr);
    ~Reportes();

private slots:
    void on_pushButton_cliente_clicked();

    void on_pushButton_clisucursal_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::Reportes *ui;
};

#endif // REPORTES_H