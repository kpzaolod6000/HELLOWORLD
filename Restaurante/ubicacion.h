#ifndef UBICACION_H
#define UBICACION_H

#include <QDialog>

namespace Ui {
class Ubicacion;
}

class Ubicacion : public QDialog
{
    Q_OBJECT

public:
    explicit Ubicacion(QWidget *parent = nullptr);
    ~Ubicacion();

signals:
    void back();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::Ubicacion *ui;
};

#endif // UBICACION_H
