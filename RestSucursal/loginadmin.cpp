#include "loginadmin.h"
#include "ui_loginadmin.h"

LoginAdmin::LoginAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}
void LoginAdmin::on_pushButton_login_clicked()
{

    QString id = ui->lineEdit_codigo->text();
    QString password = ui->lineEdit_password->text();
    QSqlQuery query;
    QStringList Lista,Lista2;
    query.prepare("SELECT * FROM Logins l INNER JOIN Administrador a ON l.codigo = a.codigo");
    query.exec();
    while(query.next()){
        Lista << query.value(0).toByteArray().constData();
        Lista2 << query.value(1).toByteArray().constData();

    }
    QString usuario;
    bool ingreso = false;
    for(int j = 0;j < Lista.size();j++){
        if(id == Lista[j]){
            for(int i=0; i<Lista2.size() ;i++){
                if(password == Lista2[i]){
                    ingreso = true;
                    usuario = Lista[j];
                }
            }
        }
    }
    qDebug() << usuario;

    if(ingreso){
        ventana = new Reportes();
        this->setVisible(false);
        ventana->setVisible(true);

        qDebug() << usuario;
    }else{
        ///MENSAJE
        QMessageBox msg(this);
        msg.setStyleSheet(" background : #B40404 ; font:20px");
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("Error");
        msg.setText("Ingreso de Usuario erronea");
        msg.exec();

        ui->lineEdit_codigo->clear();
        ui->lineEdit_password->clear();
        ui->lineEdit_codigo->setFocus();
    }
}




void LoginAdmin::on_pushButton_back_clicked()
{
    this->setVisible(false);
}

