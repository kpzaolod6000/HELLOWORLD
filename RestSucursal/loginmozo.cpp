#include "loginmozo.h"
#include "ui_loginmozo.h"

LoginMozo::LoginMozo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginMozo)
{
    ui->setupUi(this);
}

LoginMozo::~LoginMozo()
{
    delete ui;
}

void LoginMozo::on_pushButton_login_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString password = ui->lineEdit_password->text();
    /////////////////////////////////////////////
    char *str= new char[0];
    QByteArray ba=id.toLatin1();
    strcpy(str,ba.data());
    mesas = new Mesas(str);//enviando el codigo del mozo
    //////////////////////////////////////////////
    QStringList Lista,Lista2;

    QSqlQuery query;
    query.prepare("SELECT * FROM Logins l INNER JOIN Mozos m ON m.codigo = l.codigo");
    query.exec();
    while(query.next()){
        Lista << query.value(0).toByteArray().constData();
        Lista2 << query.value(1).toByteArray().constData();
    }
    qDebug() << Lista;
    for(int j = 0;j < Lista.size();j++){
        qDebug() << Lista[j]<<" "<<Lista2[j];
    }

    QString usuario = "";
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
        ventana = new EscojerMesa();
        this->setVisible(false);
        ventana->setVisible(true);
    }else{
        ///MENSAJE
        QMessageBox msg(this);
        msg.setStyleSheet(" background : #B40404 ; font:20px");
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("Error");
        msg.setText("Ingreso de Usuario erronea");
        msg.exec();

        ui->lineEdit_id->clear();
        ui->lineEdit_password->clear();
        ui->lineEdit_id->setFocus();

    }
}

void LoginMozo::on_pushButton_back_clicked()
{
    this->setVisible(false);
}
