#include "Estados.h"

Estados::Estados()
{
    codigoEstado = " ";
    cidades = new Cidades[855];
    numCidades=0;
}

Estados::~Estados()
{
    delete [] cidades;
}

void Estados::setCodEstado(string codEstado)
{
    this->codigoEstado=codEstado;
}


void Estados::setNumCidades(int n) {this->numCidades=n;}


string Estados::getCodEstado() {return this->codigoEstado;}

int Estados::getNumCidades() {return this->numCidades;}
