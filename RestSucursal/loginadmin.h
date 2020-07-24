#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include "reportes.h"

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::LoginAdmin *ui;
    Reportes* ventana;
};

#endif // LOGINADMIN_H
