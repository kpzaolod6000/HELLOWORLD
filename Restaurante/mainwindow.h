#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include "empleados.h"
#include "ubicacion.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();
    void esconder();
    void esconder2();
    void on_pushButton_clicked();

    void on_pushButton_salir_clicked();

private:
    Ui::MainWindow *ui;
    Empleados* ventana;
    Ubicacion* ventana2;
};
#endif // MAINWINDOW_H
