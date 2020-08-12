#include "mesas.h"

static int mesas;
static char* mozo;
static QString reservar;
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

Mesas::Mesas(QString reservar)
{
    ::reservar = reservar;
}

int Mesas :: getmesa(){
    return mesas;
}
char* Mesas :: getmozos(){
    return mozo;
}

QString Mesas::getreservar()
{
    return reservar;
}
