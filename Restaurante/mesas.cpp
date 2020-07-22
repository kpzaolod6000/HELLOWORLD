#include "mesas.h"

static int mesas;
static char* mozo;
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

int Mesas :: getmesa(){
    return mesas;
}
char* Mesas :: getmozos(){
    return mozo;
}
