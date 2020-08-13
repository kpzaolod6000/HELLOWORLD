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
    QTableWidget *table = new QTableWidget(0,0);

    QSqlQuery query;
    QStringList headers = { "Codigo", "Nombre", "Apellido Paterno", "Apellido Materno","Direccion","Telefonos,Lugar"};

    //table->clear();
    query.prepare("SELECT * FROM Persona p INNER JOIN Clientes c ON p.codigo = c.codigo");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        table->setColumnCount(7);
        while(query.next()){
            table->insertRow(fila);
            table->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            table->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            table->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            table->setItem(fila,3,new QTableWidgetItem(query.value(3).toString()));
            table->setItem(fila,4,new QTableWidgetItem(query.value(4).toString()));
            table->setItem(fila,5,new QTableWidgetItem(query.value(5).toString()));
            table->setItem(fila,6,new QTableWidgetItem(query.value(6).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);

            fila++;
        }

    }
    table->setStyleSheet("background-color: rgb(170, 255, 127)");
    table->setHorizontalHeaderLabels(headers);
    table->show();

}

void Reportes::on_pushButton_clisucursal_clicked()
{
    QTableWidget *table = new QTableWidget(0,0);

    QSqlQuery query;
    QStringList headers = { "Codigo", "Nombre", "Apellido Paterno", "Apellido Materno","Direccion","Telefonos,Lugar"};

    //table->clear();
    query.prepare("SELECT * FROM Persona p INNER JOIN Clientes c ON p.codigo = c.codigo UNION SELECT * FROM [192.168.0.102].Restaurante.dbo.Persona p INNER JOIN [192.168.0.102].Restaurante.dbo.Clientes c ON p.codigo = c.codigo");
    if(query.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        table->setColumnCount(7);
        while(query.next()){
            table->insertRow(fila);
            table->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            table->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            table->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            table->setItem(fila,3,new QTableWidgetItem(query.value(3).toString()));
            table->setItem(fila,4,new QTableWidgetItem(query.value(4).toString()));
            table->setItem(fila,5,new QTableWidgetItem(query.value(5).toString()));
            table->setItem(fila,6,new QTableWidgetItem(query.value(6).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);

            fila++;
        }

    }
    table->setStyleSheet("background-color: rgb(170, 255, 127)");
    table->setHorizontalHeaderLabels(headers);
    table->show();

}

void Reportes::on_pushButton_back_clicked()
{
    this->setVisible(false);
}


void Reportes::on_pushButton_pedidos_clicked()
{
   QTableWidget *table = new QTableWidget(0,0);

   QSqlQuery query;
   QStringList headers = { "Codigo", "Nombres", "Precio"};

   //table->clear();
   query.prepare("SELECT * FROM Pedidos");
   if(query.exec()){
       qDebug()<<"CONSULTA CORRECTA";
       int fila = 0;
       table->setColumnCount(3);
       while(query.next()){
           table->insertRow(fila);
           table->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
           table->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
           table->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
           //ui->tableWidget_tables->setRowHeight(fila,50);

           fila++;
       }

   }
   table->setStyleSheet("background-color: rgb(170, 255, 127)");
   table->setHorizontalHeaderLabels(headers);
   table->show();
}

void Reportes::on_pushButton_pedidos_2_clicked()
{
    QTableWidget *table = new QTableWidget(0,0);

    QSqlQuery query,query2;
    QStringList headers = { "Codigo", "Nombres", "Precio"};

    //table->clear();
    query.prepare("SELECT * FROM [192.168.0.102].Restaurante.dbo.Pedidos");
    query2.prepare("SELECT * FROM Pedidos");
    if(query.exec() && query2.exec()){
        qDebug()<<"CONSULTA CORRECTA";
        int fila = 0;
        table->setColumnCount(3);
        while(query2.next()){
            table->insertRow(fila);
            table->setItem(fila,0,new QTableWidgetItem(query2.value(0).toString()));
            table->setItem(fila,1,new QTableWidgetItem(query2.value(1).toString()));
            table->setItem(fila,2,new QTableWidgetItem(query2.value(2).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);

            fila++;
        }

        while(query.next()){
            table->insertRow(fila);
            table->setItem(fila,0,new QTableWidgetItem(query.value(0).toString()));
            table->setItem(fila,1,new QTableWidgetItem(query.value(1).toString()));
            table->setItem(fila,2,new QTableWidgetItem(query.value(2).toString()));
            //ui->tableWidget_tables->setRowHeight(fila,50);

            fila++;
        }



    }
    table->setStyleSheet("background-color: rgb(170, 255, 127)");
    table->setHorizontalHeaderLabels(headers);
    table->show();
}
