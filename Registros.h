#ifndef REGISTROS_H
#define REGISTROS_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <math.h>

#include "Estados.h"

using namespace std;

class Registros
{
    public:
        Registros();
        virtual ~Registros();

        void setData(string date) {data = date;}
        void setTamanho(int t) {tamanho = t;}
        string getData() {return data;}
        int getTamanho() {return tamanho;}

        void imprimir(Registros* r);
        Estados* estados;

    private:
        string data;
        int tamanho;
};


#endif // REGISTROS_H