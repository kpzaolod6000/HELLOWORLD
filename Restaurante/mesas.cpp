#include "mesas.h"

static int mesas;
static char* mozo;
static QSqlQuery query;
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

Mesas::Mesas(QSqlQuery query)
{
    ::query = query;
}


int Mesas :: getmesa(){
    return mesas;
}
char* Mesas :: getmozos(){
    return mozo;
}

QSqlQuery Mesas::enviarquey()
{
    return query;
}
