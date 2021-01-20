#ifndef REGISTROS_H
#define REGISTROS_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "Estados.h"

using namespace std;

class Registros
{
    public:
        Registros();
        virtual ~Registros();

        void setData(string data);

        void leitura (Registros* r, char* caminho);

        string getData();

        void imprimirRegistros(Registros* r);

        Estados* estados;

    protected:

    private:
        string data;
};

#endif // REGISTROS_H
