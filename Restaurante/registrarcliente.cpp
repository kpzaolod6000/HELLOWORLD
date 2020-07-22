#include "registrarcliente.h"
#include "ui_registrarcliente.h"
#include<random>
#include<ctime>


RegistrarCliente::RegistrarCliente(QWidget *parent,QStringList* nombre,QStringList* precio,QStringList* cantidad) :
    QDialog(parent),
    ui(new Ui::RegistrarCliente)
{
    ui->setupUi(this);
    qDebug() << nombre[0][0]<<nombre->size();// ESTA BIEN
    nombre_ = *nombre;
    precio_ = *precio;
    cantidad_ = *cantidad;

}

RegistrarCliente::~RegistrarCliente()
{
    delete ui;
}

void RegistrarCliente::on_pushButton_2_clicked()
{
    emit(back());
}

void RegistrarCliente::on_pushButton_guardar_clicked()
{
    QString nombre = ui->lineEdit_nombre->text();
    QString apel_paterno = ui->lineEdit_apelpaterno->text();
    QString apel_materno = ui->lineEdit_apel_materno->text();
    QString direccion = ui->lineEdit_direccion->text();
    QString telefonos = ui->lineEdit_telefono->text();
    QString codigo = "AAA";

    QSqlQuery select;
    QStringList Lista;
    select.prepare("SELECT * FROM Clientes");
    select.exec();
    while(select.next()){
        Lista << select.value(0).toByteArray().constData();
    }
    qDebug() << Lista;

    bool esta = true;
    while(esta != false){
        srand(static_cast<unsigned int>(time(0)));
        int value=100+rand() % 1001;
        //qDebug() << value;
        codigo = codigo + QString::number(value);
        for(int j = 0;j < Lista.size();j++){
            if(Lista[j] == codigo){
                esta = true;
                break;
            }else{
                esta = false;
            }
        }
    }

    QString lugar = ui->label_lugar->text();

    if(esta == false){
        QSqlQuery query,query1;
        if(!nombre.isEmpty() && !apel_materno.isEmpty() && !apel_paterno.isEmpty() ){
            query.prepare("INSERT INTO Persona VALUES('"+codigo+"','"+nombre+"','"+apel_paterno+"','"+apel_materno+"','"+direccion+"','"+telefonos+"','"+lugar+"')");
            query1.prepare("INSERT INTO Clientes VALUES ('"+codigo+"')");
            if(query.exec() && query1.exec()){
                QMessageBox msg(this);
                msg.setStyleSheet(" background : #67FFF8 ; font:20px");
                msg.setIcon(QMessageBox::Information);
                msg.setWindowTitle("REGISTRO");
                msg.setText("Registro Guardado");
                msg.exec();

                ventana = new Facturas(this,codigo,&nombre_,&precio_,&cantidad_);
                this->setVisible(false);
                ventana->setVisible(true);

            }else{
                QMessageBox msg(this);
                msg.setStyleSheet(" background : #67FFF8 ; font:20px");
                msg.setIcon(QMessageBox::Warning);
                msg.setWindowTitle("SIN REGISTRAR");
                msg.setText("Registro No Guardado");
                msg.exec();
            }
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet(" background : #67FFF8 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("SIN REGISTRAR");
            msg.setText("Registro No Guardado");
            msg.exec();
        }
    }else{
        qDebug()<<"ERROR" << codigo;
    }

}
