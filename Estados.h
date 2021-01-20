#ifndef ESTADOS_H
#define ESTADOS_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Cidades.h"

using namespace std;

class Estados
{
    public:
        Estados();

        virtual ~Estados();

        void setCodEstado(string codEstado);

        string getCodEstado();

        void setNumCidades(int n);
        int getNumCidades();

        Cidades* cidades;//5570 cidades

    protected:

    private:
        string codigoEstado;
        int numCidades;
};

#endif // ESTADOS_H
