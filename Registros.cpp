#include "Registros.h"
#include <string.h>

Registros::Registros()
{
    this->data = " ";
    this->estados = new Estados[27];
}

Registros::~Registros()
{
    //dtor
}

void Registros::imprimirRegistros (Registros* r)
{
    for(int i=0; i<258; i++)
    {
        for (int j=0; j<27; j++)
        {
            for(int k=0;k<r[i].estados[j].getNumCidades(); k++)
            {
                cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
            }
        }
    }
}
