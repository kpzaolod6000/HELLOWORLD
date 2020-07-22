#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <QDialog>
#include "loginmozo.h"
#include "loginadmin.h"

namespace Ui {
class Empleados;
}

class Empleados : public QDialog
{
    Q_OBJECT

public:
    explicit Empleados(QWidget *parent = nullptr);
    ~Empleados();
signals:
    void back();
private slots:
    void on_pushButton_mozo_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_administrador_clicked();

private:
    Ui::Empleados *ui;
    LoginMozo* miniventana;
    LoginAdmin* miniventanal;
};

#endif // EMPLEADOS_H
