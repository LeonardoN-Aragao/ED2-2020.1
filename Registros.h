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
        void imprimirRegistros(Registros* r);
        void setData(string data);
        string getData();
        Estados* estados;

    private:
        string data;
};

#endif // REGISTROS_H
