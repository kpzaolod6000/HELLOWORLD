#include "facturas.h"
#include "ui_facturas.h"
#include<random>
#include<ctime>

static int ingresados = 0;
Facturas::Facturas(QWidget *parent,QString codigo,QStringList* nombre,QStringList* precio,QStringList* cantidad) :
    QDialog(parent),
    ui(new Ui::Facturas)
{
    ui->setupUi(this);
    this->codigo = codigo;
    this->nombre=*nombre;
    this->precio=*precio;
    this->cantidad=*cantidad;
    mostrar();

}

Facturas::~Facturas()
{
    delete ui;
}

void Facturas :: mostrar(){
    //ui->label_nombre->setText(codigo);
    //ui->tableWidget_factura->clear();
    ui->tableWidget_factura->setColumnCount(4);
    double Saldo = 0;

    for(int i=0;i<this->nombre.size();i++){
       ui->tableWidget_factura->insertRow(i);
       ui->tableWidget_factura->setItem(i,1,new QTableWidgetItem(nombre[i]));
       ui->tableWidget_factura->setItem(i,2,new QTableWidgetItem(precio[i]));
       ui->tableWidget_factura->setItem(i,3,new QTableWidgetItem(cantidad[i]));
       //recuperar
       Saldo = Saldo + ui->tableWidget_factura->item(i,2)->text().toDouble();
    }
    ui->tableWidget_factura->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_factura->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_factura->verticalHeader()->setVisible(false);
    ui->tableWidget_factura->setStyleSheet("QTableView {selection-background-color:#00afaf}");

    ui->label_saldp->setText(QString::number(Saldo));

    //ACA MUESTRO EL NOMBRE DEL USUARIO DE LA FACTURA
    QSqlQuery query;
    QStringList Lista,Lista1, Lista2, Lista3;

    codigo.size();
    qDebug() << codigo;

    query.prepare("SELECT c.codigo,p.nombre,p.apel_paterno,p.apel_materno FROM Clientes c INNER JOIN Persona p ON c.codigo = p.codigo");

    query.exec();
    while(query.next()){
        Lista << query.value(0).toByteArray().constData();
        Lista1 << query.value(1).toByteArray().constData();
        Lista2 << query.value(2).toByteArray().constData();
        Lista3 << query.value(3).toByteArray().constData();
    }
    qDebug() << Lista;
    int index;
    for(int j = 0;j < Lista.size();j++){
        if(Lista[j] == codigo){
            index = j;
        }
    }
    qDebug() << index;
    ui->label_nombre->setText(Lista1[index]+ " "+Lista2[index]+ " "+Lista3[index]);
}
void Facturas::on_pushButton_cancelar_clicked()
{
    if(ingresados == 0){
        ingresados++;

    //viendo facturas

    QSqlQuery select;
    QStringList Lista;
    select.prepare("SELECT * FROM Facturas");
    select.exec();
    while(select.next()){
        Lista << select.value(0).toByteArray().constData();
    }

    QString cod_fact = "A";
    bool esta = true;

    while(esta != false){
        srand(static_cast<unsigned int>(time(0)));
        int value=0+rand() % 200;
        //qDebug() << value;
        cod_fact = cod_fact + QString::number(value);
        for(int j = 0;j < Lista.size();j++){
            if(Lista[j] == codigo){
                esta = true;
                break;
            }else{
                esta = false;
            }
        }
    }

    //ingresando facturas
    QSqlQuery select1;
    QStringList Lista1;
    select1.prepare("SELECT * FROM Cajeros");
    select1.exec();
    while(select1.next()){
        Lista1 << select1.value(0).toByteArray().constData();
    }

    srand(static_cast<unsigned int>(time(0)));
    int ran=0+rand() % (Lista1.size());

    qDebug() << Lista1.size() << ran;

    QString cajero = Lista1[ran];
    QString a = "2020-07-26";
    QString b = "10:41:00";

    float descuento = 10.0;
    float impuestos = 10.0;
    QString descuento_ = QString::number(descuento);
    QString impuestos_ = QString::number(impuestos);
    qDebug() << cod_fact;

    if(esta == false)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO Facturas VALUES('"+cod_fact+"','"+a+"','"+b+"','"+descuento_+"','"+impuestos_+"','"+cajero+"','"+codigo+"')");
        if(query.exec()){
            qDebug() <<"Datos ingresados en Facturas";
        }
        else{
            qDebug() <<"Datos no ingresados en Facturas";
        }
    }
    //ui->label_nombre->setText(codigo);


    //viendo las Lineas_fact

    QSqlQuery selectf;
    QStringList Listaf;
    selectf.prepare("SELECT * FROM Lineas_Fact");
    selectf.exec();
    while(selectf.next()){
        Listaf << selectf.value(1).toByteArray().constData();
    }
    bool estaf = true;
    int cod_lineas;

    while(estaf != false){
        srand(static_cast<unsigned int>(time(0)));
        int value=500+rand() % 1001;
        //qDebug() << value;
        cod_lineas = value;
        for(int j = 0;j < Listaf.size();j++){
            if(Listaf[j] == cod_lineas){
                estaf = true;
                break;
            }else{
                estaf = false;
            }
        }
    }
    qDebug() << Listaf << cod_fact << cod_lineas;
    QSqlQuery querylineas;

        //viendo Pedidos

        QSqlQuery selectp;
        QStringList Listap;
        selectp.prepare("SELECT * FROM Pedidos");
        selectp.exec();
        while(selectp.next()){
            Listap << selectp.value(0).toByteArray().constData();
        }
        bool estap = true;
        int cod_pro;

        while(estap != false){
            srand(static_cast<unsigned int>(time(0)));
            int value=100+rand() % 1001;
            //qDebug() << value;
            cod_pro = value;
            for(int j = 0;j < Listap.size();j++){
                if(Listap[j] == cod_pro){
                    estap = true;
                    break;
                }else{
                    estap = false;
                }
            }
        }

        qDebug() << Listap <<cod_pro;

        //vista de categorias e ingreso de pedidos
        QSqlQuery selectc,querype;
        QStringList Listac,Listan,Listaprecio;
        selectc.prepare("SELECT * FROM Categorias c INNER JOIN Producto p ON c.cod_catg = p.cod_catg INNER JOIN [192.168.0.100].Restaurante.dbo.Producto ipp ON p.enlace = ipp.enlace");
        selectc.exec();
        while(selectc.next()){
            Listac << selectc.value(0).toByteArray().constData();
            Listan << selectc.value(3).toByteArray().constData();
            Listaprecio << selectc.value(7).toByteArray().constData();
        }
        //qDebug() << Listac <<Listan << Listaprecio;

        bool encontro = false;
        int index;
        for(int p = 0;p < nombre.size(); p++){
            for(int q =0 ;q < Listan.size();q++){
                if(nombre[p] == Listan[q]){
                    encontro = true;
                    index = q;
                }
            }
            qDebug() << Listac[index] << Listan[index] << Listaprecio[index];

            //qDebug() << "entrooo";
            if(encontro){
                qDebug() << "entrooo";
                QString cod_pro_ = QString::number(cod_pro);
                QString cod_lineas_ = QString::number(cod_lineas);
                querype.prepare("INSERT INTO Pedidos VALUES('"+cod_pro_+"','"+Listan[index]+"','"+Listaprecio[index]+"','"+Listac[index]+"')");
                QString precio__=precio[p];
                querylineas.prepare("INSERT INTO Lineas_Fact VALUES('"+cod_fact+"','"+cod_lineas_+"','"+cantidad[p]+"','"+precio__+"','"+cod_pro_+"')");
                if(querype.exec() && querylineas.exec())
                    qDebug() << "Datos ingresados a Pedidos y ha Lineas_Fact";
                else
                    qDebug() << "Datos no ingresados a Pedidos";

                encontro = false;
                cod_pro++;
                cod_lineas++;

            }

        }
        //Ocupando Mesa
        mesas = new Mesas();
        int mesa = mesas->getmesa();
        QString mesa_= QString::number(mesa);

        char* recuperar = mesas->getmozos();

        qDebug() << "MESA: "<< mesa << recuperar;


        //viendo mesa
        QSqlQuery selectmesa,querymesa,querymesa2;
        QStringList Listamesa;
        selectmesa.prepare("SELECT * FROM Mesas");
        selectmesa.exec();
        while(selectmesa.next()){
            Listamesa << selectmesa.value(0).toByteArray().constData();
        }

        bool estamesa = false;
        for(int k=0; k < Listamesa.size() ; k++){
            if(Listamesa[k] == mesa_){
                estamesa = true;
                break;
            }
        }

        //eliminando mesa e insertando
        if(estamesa){
            qDebug() <<"eliminando mesa e insertando";
            querymesa.prepare("DELETE Mesas WHERE cod_mesa ="+mesa_);
            querymesa.exec();
            querymesa2.prepare("INSERT INTO Mesas VALUES ('"+mesa_+"','"+codigo+"','"+recuperar+"')");
            querymesa2.exec();
        }
        this->setVisible(false);

    }else{
        QMessageBox msg(this);
        msg.setStyleSheet(" background : #67FFF8 ; font:20px");
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("FUE REGISTRADO");
        msg.setText("La Factura ya fue realizada");
    }
}
