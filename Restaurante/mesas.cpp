#include "mesas.h"

static int mesas;
static char* mozo;
static QString reserva;
Mesas::Mesas(int mesas)
{
    ::mesas = mesas;
}
Mesas::Mesas()
{
}

Mesas::Mesas(char* mozo)
{
    ::mozo = mozo;
}
Mesas :: Mesas(QString reserva)
{
    ::reserva = reserva;
}

int Mesas :: getmesa(){
    return mesas;
}
char* Mesas :: getmozos(){
    return mozo;
}

QString Mesas::getreserva()
{
    return reserva;
}
