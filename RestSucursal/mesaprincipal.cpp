#include "mesaprincipal.h"
#include "ui_mesaprincipal.h"

MesaPrincipal::MesaPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MesaPrincipal)
{
    ui->setupUi(this);
}

void MesaPrincipal::on_pushButton_mesa1_clicked()
{
    QString a = "1";

    mesas = new Mesas(1); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET XACT_ABORT ON; SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("SET XACT_ABORT ON; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 1 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }
}

void MesaPrincipal::on_pushButton_mesa2_clicked()
{
    QString a = "2";

    mesas = new Mesas(2); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 2 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }

}

void MesaPrincipal::on_pushButton_mesa3_clicked()
{
    QString a = "3";

    mesas = new Mesas(3); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 3 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }

}

void MesaPrincipal::on_pushButton_mesa4_clicked()
{
    QString a = "4";

    mesas = new Mesas(4); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 4 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }

}

void MesaPrincipal::on_pushButton_mesa5_clicked()
{
    QString a = "5";

    mesas = new Mesas(5); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 5 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }
}

void MesaPrincipal::on_pushButton_mesa6_clicked()
{
    QString a = "6";

    mesas = new Mesas(6); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 6 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }
}

void MesaPrincipal::on_pushButton_mesa7_clicked()
{
    QString a = "7";

    mesas = new Mesas(7); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 7 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }
}

void MesaPrincipal::on_pushButton_mesa8_clicked()
{
    QString a = "8";

    mesas = new Mesas(8); // llevando numero de la mesa

    QStringList Lista,MozosL;
    QStringList cod_mesa;

    QSqlQuery query;
    query.prepare("SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; SELECT * FROM [192.168.0.104].Restaurante.dbo.Mesas");
    query.exec();
    while(query.next()){
        cod_mesa << query.value(0).toByteArray().constData();
        Lista << query.value(1).toByteArray().constData();
        MozosL << query.value(2).toByteArray().constData();
    }

    qDebug() << Lista;
    bool ocupado = false;
    for(int j = 0;j < cod_mesa.size();j++){
       if(a == cod_mesa[j]){
           if(Lista[j] != nullptr){
               ocupado = true;
               break;
           }
       }
    }

    if(ocupado){
        ///MENSAJE
        QMessageBox msgBox;
        msgBox.setStyleSheet(" background : #DF7401 ; font:20px");
        msgBox.setText("Mesa Ocupada");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("OCUPADO");
        msgBox.setInformativeText("Desea desocupar la mesa ? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        QSqlQuery queryborrar;
        switch(ret){
            case QMessageBox::Yes:
                queryborrar.prepare("UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_cli = null, cod_moz = null WHERE cod_mesa="+a);
                if(queryborrar.exec())
                    qDebug() << "Se desocupo la mesa";
                else{
                    qDebug() << "error";
                    break;
                }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }

    }else{
        char* mozos = mesas->getmozos();
        QString mo = mozos;
        qDebug() << a;

        int index;
        for(int j=0;j<cod_mesa.size();j++){
            if(cod_mesa[j] == a)
                index=j;
        }
        if(MozosL[index] == nullptr){
            QSqlDatabase::database().transaction();//SE PUDO LA TRANSACTION

            QSqlQuery querynew;
               querynew.prepare("SET XACT_ABORT ON;SET TRANSACTION ISOLATION LEVEL READ COMMITTED; UPDATE [192.168.0.104].Restaurante.dbo.Mesas SET cod_moz ='"+mo+"' WHERE cod_mesa="+a);
               if(querynew.exec()){
                   qDebug() << "RESERVANDO MESA: " << 8 <<"...";
               }else{
                   qDebug() << "ERROR EN LA RESERVA";
            }

            ventana = new RegistrarMesa();
            ventana->setVisible(true);
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet("background : #B40404 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("CARGANDO...");
            msg.setText("Mesa en plena Reserva...");
            msg.exec();
        }
    }
}

MesaPrincipal::~MesaPrincipal()
{
    delete ui;
}

void MesaPrincipal::on_pushButton_atras_clicked()
{
    this->setVisible(false);
}

