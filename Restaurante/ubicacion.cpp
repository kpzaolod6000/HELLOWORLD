#include "ubicacion.h"
#include "ui_ubicacion.h"

Ubicacion::Ubicacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ubicacion)
{
    ui->setupUi(this);
}


void Ubicacion::on_pushButton_back_clicked()
{
    emit(back());
}

Ubicacion::~Ubicacion()
{
    delete ui;
}

