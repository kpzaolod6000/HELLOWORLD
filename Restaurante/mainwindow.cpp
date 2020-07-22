#include "mainwindow.h"
#include "ui_mainwindow.h"

static QSqlDatabase conexion = QSqlDatabase :: addDatabase ( "QODBC") ; // Controlador PostgreSQL

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conexion.setHostName ( "DESKTOP-U4DCD1F" ) ; // establece el nombre de tu host
    conexion.setDatabaseName ( "DRIVER={SQL SERVER};SERVER=DESKTOP-U4DCD1F;DATABASE=Restaurante" ) ; // establece el nombre de tu base de datos
    conexion.setUserName ( "sa" ) ; // establece el nombre del usuario, que es el propietario de la base de datos
    conexion.setPassword ( "1234" ) ; // establece la contraseña del usuario
    bool ok = conexion.open() ; // comprueba el estado de la conexión
    if(ok == true){
        ui->label->setText("ABIERTO");
    }else{
        ui->label->setText("CERRADO");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::esconder()
{
    this->setVisible(true);
    ventana->setVisible(false);
}


void MainWindow::on_pushButton_login_clicked()
{
    ventana = new Empleados();
    QObject :: connect(ventana,SIGNAL(back()),this,SLOT(esconder()));
    this->setVisible(false);
    ventana->setVisible(true);

}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Persona");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget->setColumnCount(7);
        while(query.next()){
            ui->tableWidget->insertRow(fila);
            ui->tableWidget->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(fila,3,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(fila,4,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(fila,5,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setItem(fila,6,new QTableWidgetItem(query.value(8).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);
            fila++;

        }

    }


}
