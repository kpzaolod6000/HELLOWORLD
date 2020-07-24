#include "registrarmesa.h"
#include "ui_registrarmesa.h"

static int escojer = 0;
static int aumen = 0;
static int reduc = 0;
static int quitar = -1;

static int fila = 0;
static int listapedidos = 0;

RegistrarMesa::RegistrarMesa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrarMesa)
{
    ui->setupUi(this);

    escojer = 0;
    fila = 0;
    listapedidos = 0;

    aumen = 0;
    reduc = 0;
    quitar = -1;
}

RegistrarMesa::~RegistrarMesa()
{
    delete ui;
}


void RegistrarMesa::on_pushButton_back_clicked()
{
    escojer = 0;
    fila = 0;
    quitar = -1;
    listapedidos = 0;

    //mesas = new Mesas();
    //mesas->enviarquey().value("ROLLBACK");
    //mesas->enviarquey().prepare("ROLLBACK");

    QSqlDatabase::database().rollback();
    /*if(mesas->enviarquey().exec()){
        qDebug() << "ROLLBACK";
    }else{
        qDebug() << "ERROR";
    }*/
    this->setVisible(false);
}

void RegistrarMesa::on_pushButton_helados_clicked()
{
    escojer++;

    //ui->tableWidget_productos->removeRow(0); este escojer en un for para borra las filas

    ui->tableWidget_productos->clear();
    //ELIMINAR LAS FILAS VACIAS

    QSqlQuery query;

    query.prepare("SELECT nombres,precio,stock FROM Producto p INNER JOIN [192.168.0.104].Restaurante.dbo.Producto ipp ON p.enlace = ipp.enlace WHERE p.cod_catg = 5550");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget_productos->setColumnCount(3);
        while(query.next()){
            ui->tableWidget_productos->insertRow(fila);
            ui->tableWidget_productos->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_productos->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_productos->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            fila++;
        }
        QStringList cabeza = {"nombres","precio","stock"};
        ui->tableWidget_productos->setHorizontalHeaderLabels(cabeza);
        ui->tableWidget_productos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_productos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_productos->verticalHeader()->setVisible(false);
        ui->tableWidget_productos->setStyleSheet("QTableView {selection-background-color:#00afaf}");

    }
    else{
        qDebug()<<"ERROR";
    }
}

void RegistrarMesa::on_pushButton_fria_clicked()
{
    escojer++;

    ui->tableWidget_productos->clear();

    QSqlQuery query;
    query.prepare("SELECT nombres,precio,stock FROM Producto p INNER JOIN [192.168.0.104].Restaurante.dbo.Producto ipp ON p.enlace = ipp.enlace WHERE p.cod_catg = 55511");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget_productos->setColumnCount(3);
        while(query.next()){
            ui->tableWidget_productos->insertRow(fila);
            ui->tableWidget_productos->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_productos->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_productos->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            fila++;
        }
        QStringList cabeza = {"nombres","precio","stock"};
        ui->tableWidget_productos->setHorizontalHeaderLabels(cabeza);
        ui->tableWidget_productos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_productos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_productos->verticalHeader()->setVisible(false);
        ui->tableWidget_productos->setStyleSheet("QTableView {selection-background-color:#00afaf}");

    }
    else{
        qDebug()<<"ERROR";
    }

}

void RegistrarMesa::on_pushButton_entrada_clicked()
{
    escojer++;
    ui->tableWidget_productos->clear();

    QSqlQuery query;
    query.prepare("SELECT nombres,precio,stock FROM Producto p INNER JOIN [192.168.0.104].Restaurante.dbo.Producto ipp ON p.enlace = ipp.enlace WHERE p.cod_catg = 5554");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget_productos->setColumnCount(3);
        while(query.next()){
            ui->tableWidget_productos->insertRow(fila);
            ui->tableWidget_productos->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_productos->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_productos->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            fila++;
        }
        QStringList cabeza = {"nombres","precio","stock"};
        ui->tableWidget_productos->setHorizontalHeaderLabels(cabeza);
        ui->tableWidget_productos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_productos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_productos->verticalHeader()->setVisible(false);
        ui->tableWidget_productos->setStyleSheet("QTableView {selection-background-color:#00afaf}");

    }
    else{
        qDebug()<<"ERROR";
    }
}

void RegistrarMesa::on_pushButton_segund_clicked()
{
    escojer++;
    ui->tableWidget_productos->clear();

    QSqlQuery query;
    query.prepare("SELECT nombres,precio,stock FROM Producto p INNER JOIN [192.168.0.104].Restaurante.dbo.Producto ipp ON p.enlace = ipp.enlace WHERE p.cod_catg = 5557");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget_productos->setColumnCount(3);
        while(query.next()){
            ui->tableWidget_productos->insertRow(fila);
            ui->tableWidget_productos->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_productos->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_productos->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            fila++;
        }
        QStringList cabeza = {"nombres","precio","stock"};
        ui->tableWidget_productos->setHorizontalHeaderLabels(cabeza);
        ui->tableWidget_productos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_productos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_productos->verticalHeader()->setVisible(false);
        ui->tableWidget_productos->setStyleSheet("QTableView {selection-background-color:#00afaf}");

    }
    else{
        qDebug()<<"ERROR";
    }

}


void RegistrarMesa::on_pushButton_postres_clicked()
{
    escojer++;

    ui->tableWidget_productos->clear();

    QSqlQuery query;
    query.prepare("SELECT nombres,precio,stock FROM Producto p INNER JOIN [192.168.0.104].Restaurante.dbo.Producto ipp ON p.enlace = ipp.enlace WHERE p.cod_catg = 5555");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget_productos->setColumnCount(3);
        while(query.next()){
            ui->tableWidget_productos->insertRow(fila);
            ui->tableWidget_productos->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_productos->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_productos->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            fila++;
        }
        QStringList cabeza = {"nombres","precio","stock"};
        ui->tableWidget_productos->setHorizontalHeaderLabels(cabeza);
        ui->tableWidget_productos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_productos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_productos->verticalHeader()->setVisible(false);
        ui->tableWidget_productos->setStyleSheet("QTableView {selection-background-color:#00afaf}");

    }
    else{
        qDebug()<<"ERROR";
    }
}

void RegistrarMesa::on_pushButton_platos_clicked()
{

}


void RegistrarMesa::mostrarpedidos(QString nombre,QString precio)
{
    listapedidos++;
    qDebug() << listapedidos <<"Numero de pedidos";
    int cantidad = 1;
    QString cantidad_ = QString::number(cantidad);
    int conservarfila = fila;
    if(quitar != -1){
        fila = quitar;
    }
    ui->tableWidget_muestra->insertRow(fila);
    ui->tableWidget_muestra->setItem(fila,0,new QTableWidgetItem(nombre));
    ui->tableWidget_muestra->setItem(fila,1,new QTableWidgetItem(precio));
    ui->tableWidget_muestra->setItem(fila,2,new QTableWidgetItem(cantidad_));

    ui->tableWidget_muestra->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_muestra->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_muestra->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_muestra->verticalHeader()->setVisible(false);
    ui->tableWidget_muestra->setStyleSheet("QTableView {selection-background-color:#00afaf}");
    if(quitar != -1){
        fila = conservarfila;
    }else{
        fila++;
    }
    //suma para el conteo
    //Saldo();
}


void RegistrarMesa::on_pushButton_escojer_clicked()
{
    if(escojer != 0){
        int setfila = ui->tableWidget_productos->currentRow();
        if(setfila != -1){
            qDebug() << setfila <<"AQUIII";
            //qDebug() << ui->tableWidget_productos->item(setfila,0)->text()<< " "<<ui->tableWidget_productos->item(setfila,1)->text() <<"AQUIII";
            QString nombre = ui->tableWidget_productos->item(setfila,0)->text();
            QString precio = ui->tableWidget_productos->item(setfila,1)->text();

            bool esta = false;
            if(listapedidos !=0){
                for(int k=0;k<listapedidos;k++){
                    QString verificar = ui->tableWidget_muestra->item(k,0)->text();
                    if(nombre == verificar){
                        esta = true;
                    }
                }
            }
            /*
            bool esta = false;
            for(int j = 0; j < i ;j++){
                if(Lista[j] == setfila){
                    esta = true;
                }
            }*/
            if(esta){
                ui->label_puesto->setText("El plato ya fue escogido");
            }else{
                //Lista[i] = setfila;
                mostrarpedidos(nombre,precio);//
                //i++;
                ui->label_puesto->setText(" ");
                //setfila = -1;//NO funciona porque ya esta selecionando ptmr
           }
        }else{
            QMessageBox msg(this);
            msg.setStyleSheet(" background : #F36400 ; font:20px");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("ESCOJA");
            msg.setText("Por favor seleccione un producto");
            msg.exec();
        }
    }
    //suma para el conteo
    /*double sumatotal = 0.0;
    for(int j = 0;j < escojer;j++){
        sumatotal = sumatotal + ui->tableWidget_muestra->item(j,1)->text().toDouble();
    }
    QString sumatotal_ = QString::number(sumatotal);

    ui->label_saldo->setText(sumatotal_);*/
}

static double preciomas;
void RegistrarMesa::on_pushButton_aumentar_clicked()
{
    int setfila = ui->tableWidget_muestra->currentRow();
    if(setfila != -1){
        int cantidad = ui->tableWidget_muestra->item(setfila,2)->text().toInt();
        if(cantidad == 1){
            preciomas = ui->tableWidget_muestra->item(setfila,1)->text().toDouble();
        }
        cantidad++;

        double precio1 = preciomas * cantidad;
        QString precio_ = QString::number(precio1);
        QString cantidad_ = QString::number(cantidad);
        ui->tableWidget_muestra->setItem(setfila,1,new QTableWidgetItem(precio_));
        ui->tableWidget_muestra->setItem(setfila,2,new QTableWidgetItem(cantidad_));

    }else{
        ui->label_puesto->setText("Por favor escoja el plato que quiere eliminar");
    }
    //suma para el conteo
    //Saldo();

}

void RegistrarMesa::on_pushButton_reducir_clicked()
{
    int setfila = ui->tableWidget_muestra->currentRow();
    if(setfila != -1){
        int cantidad = ui->tableWidget_muestra->item(setfila,2)->text().toInt();
        double precio = ui->tableWidget_muestra->item(setfila,1)->text().toDouble();

        if(cantidad != 1){
            cantidad--;
            double precio1 = precio-preciomas;

            QString precio_ = QString::number(precio1);
            QString cantidad_ = QString::number(cantidad);
            ui->tableWidget_muestra->setItem(setfila,1,new QTableWidgetItem(precio_));
            ui->tableWidget_muestra->setItem(setfila,2,new QTableWidgetItem(cantidad_));
        }
    }else{
        ui->label_puesto->setText("Por favor escoja el plato que quiere eliminar");
    }

    //suma para el conteo
    //Saldo();
}


void RegistrarMesa::on_pushButton_quitar_clicked()
{
    int setfila = ui->tableWidget_muestra->currentRow();
    if(setfila != -1){
        ui->tableWidget_muestra->removeRow(setfila);
        quitar = setfila;
        listapedidos--;
        //ui->tableWidget_muestra->insertRow(setfila);
    }else{
        ui->label_puesto->setText("Por favor escoja el plato que quiere eliminar");
    }
    //cuando se quita uno
    //listapedidos--;recomendable guardar las filas eliminadas en un arreglo static int

}

void RegistrarMesa :: Saldo(){
    /*//suma para el conteo
    double sumatotal = 0;
    qDebug() << listapedidos;
    for(int j = 0;j < listapedidos;j++){
        sumatotal = sumatotal + ui->tableWidget_muestra->item(j,1)->text().toDouble();
    }
    QString sumatotal_ = QString::number(sumatotal);

    ui->label_saldo->setText(sumatotal_);*/
}


//pasar a caja
void RegistrarMesa::on_pushButton_registrar_clicked()
{

    QStringList nombre;
    QStringList precio;
    QStringList cantidad;


    if(listapedidos != 0){
        for(int j = 0;j<listapedidos;j++){

           nombre << ui->tableWidget_muestra->item(j,0)->text();
           precio << ui->tableWidget_muestra->item(j,1)->text();
           cantidad << ui->tableWidget_muestra->item(j,2)->text();

        }
        /*QStringList cantidad1 = cantidad;

        for(int j = 0;j< nombre.size();j++){
            qDebug() << nombre[j] << " " << precio[j] << cantidad1[j];
        }*/
        ventana = new RegistrarCliente(this,&nombre,&precio,&cantidad);
        QObject :: connect(ventana,SIGNAL(back()),this,SLOT(esconder()));
        this->setVisible(false);
        ventana->setVisible(true);
    }else{
        QMessageBox msg(this);
        msg.setStyleSheet(" background : #F36400 ; font:20px");
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("ERROR");
        msg.setText("Debe hacer por lo menos un pedido");
        msg.exec();
    }
}

void RegistrarMesa::esconder()
{
    this->setVisible(true);
    ventana->setVisible(false);
}



