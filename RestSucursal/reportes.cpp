#include "reportes.h"
#include "ui_reportes.h"

Reportes::Reportes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reportes)
{
    ui->setupUi(this);
}

Reportes::~Reportes()
{
    delete ui;
}

void Reportes::on_pushButton_cliente_clicked()
{
    QSqlQuery query;
    ui->tableWidget->clear();

    //ui->tableWidget->deleteLater();TAPA TODO
    //ui->tableWidget->close()
    ui->tableWidget->clearSelection();

    ui->tableWidget->show();
    //ui->tableWidget->clearMask();
    //ui->tableWidget->showNormal();


    //ui->tableWidget->destroyed();
    query.prepare("SELECT * FROM Persona p INNER JOIN Clientes c ON p.codigo = c.codigo");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget->setColumnCount(7);
        while(query.next()){
            ui->tableWidget->insertRow(fila);
            ui->tableWidget->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(fila,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(fila,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(fila,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(fila,6,new QTableWidgetItem(query.value(6).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);
            fila++;

        }

    }

}

void Reportes::on_pushButton_clisucursal_clicked()
{
    QSqlQuery query;
    ui->tableWidget->clear();
    ui->tableWidget->clearSelection();
    //ui->tableWidget->deleteLater();
    //ui->tableWidget->close();
    ui->tableWidget->show();

    query.prepare("SELECT * FROM Persona p INNER JOIN Clientes c ON p.codigo = c.codigo UNION SELECT * FROM [192.168.0.103].Restaurante.dbo.Persona p INNER JOIN [192.168.0.103].Restaurante.dbo.Clientes c ON p.codigo = c.codigo");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        ui->tableWidget->setColumnCount(7);
        while(query.next()){
            ui->tableWidget->insertRow(fila);
            ui->tableWidget->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(fila,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(fila,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(fila,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(fila,6,new QTableWidgetItem(query.value(6).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);
            fila++;

        }

    }

}

void Reportes::on_pushButton_back_clicked()
{
    this->setVisible(false);
}
