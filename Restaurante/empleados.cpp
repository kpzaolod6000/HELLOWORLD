#include "empleados.h"
#include "ui_empleados.h"

Empleados::Empleados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Empleados)
{
    ui->setupUi(this);
}

Empleados::~Empleados()
{
    delete ui;
}

void Empleados::on_pushButton_mozo_clicked()
{
    //esconder esta ventanamainwindow y s emuestra la ventana mostrar
    miniventana = new LoginMozo();
    miniventana -> exec();
}

void Empleados::on_pushButton_back_clicked()
{
    emit(back());
}

void Empleados::on_pushButton_administrador_clicked()
{
    //esconder esta ventanamainwindow y s emuestra la ventana mostrar
    miniventanal = new LoginAdmin();
    miniventanal -> exec();
}
