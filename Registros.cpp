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

void Registros::setData(string data) {this->data=data;}

string Registros::getData() {return this->data;}

void Registros::leitura(Registros* r, char* caminho)
{
    ifstream arquivo;

    arquivo.open(caminho);

    if(arquivo.is_open())
    {
        cout<<"O arquivo "<<caminho<<" foi aberto com sucesso."<<endl;
        arquivo.seekg(0,arquivo.end);
        int tamanho = arquivo.tellg();
        arquivo.seekg(0,arquivo.beg);

        string aux;
        getline(arquivo,aux);

        int i=0;
        int j=0;
        int k=0;

        int auxInt;

        //Leitura dos primeiros elementos
        getline(arquivo,aux,',');
        r[0].setData(aux);

        getline(arquivo,aux,',');
        r[0].estados[0].setCodEstado(aux);

        getline(arquivo,aux,',');
        r[0].estados[0].cidades[0].setNome(aux);

        getline(arquivo,aux,',');
        r[0].estados[0].cidades[0].setCodigo(aux);

        getline(arquivo,aux,',');
        istringstream(aux)>>auxInt;
        r[0].estados[0].cidades[0].setCasos(auxInt);

        getline(arquivo,aux,'\n');
        istringstream(aux)>>auxInt;
        r[0].estados[0].cidades[0].setMortes(auxInt);

        //Inicializando os campos de controle da leitura
        string _data,estado;
        data = r[0].getData();
        estado = r[0].estados[0].getCodEstado();

        cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;

        while(!arquivo.eof())
        {
            getline(arquivo,aux,',');
            if(!stricmp(aux.c_str(),_data.c_str()))
            {//ainda em r[i]
                getline(arquivo,aux,',');
                if(!stricmp(aux.c_str(),estado.c_str()))
                {//ainda em estados[j];

                    k++;//Com isso, as cidades variam
                    //cout<<"mudou de cidade"<<endl;

                    getline(arquivo,aux,',');//Lendo o nome da cidade
                    r[i].estados[j].cidades[k].setNome(aux);

                    getline(arquivo,aux,',');//Lendo o codigo da cidade
                    r[i].estados[j].cidades[k].setCodigo(aux);

                    getline(arquivo,aux,',');//Lendo a quantidade de casos naquela cidade, naquele dia
                    istringstream(aux)>>auxInt;
                    r[i].estados[j].cidades[k].setCasos(auxInt);

                    getline(arquivo,aux,'\n');//Lendo a quantidade de mortes naquela cidade, naquele dia
                    istringstream(aux)>>auxInt;
                    r[i].estados[j].cidades[k].setMortes(auxInt);

                    cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
                }
                else
                {//Mudan�a no codigo do estado, deve passar para o proximo estado

                    if(i==0) {r[i].estados[j].setNumCidades(k+1);} //Atualizando o numero de cidades do estado anterior. Nao e preciso mudar essa grandeza quando i !=0, pois isso ja tera sido feito na primeira iteracao de i.

                    estado=aux;//Definindo o novo estados[j]

                    j++;k=0;
                    //cout<<"mudou de estado"<<endl;

                    //Iniciando as informacoes do novo estados[j]
                    r[i].estados[j].setCodEstado(aux);

                    //Dados da primeira cidade do novo estados[j]
                    getline(arquivo,aux,',');
                    r[i].estados[j].cidades[k].setNome(aux);

                    getline(arquivo,aux,',');
                    r[i].estados[j].cidades[k].setCodigo(aux);

                    getline(arquivo,aux,',');
                    istringstream(aux)>>auxInt;
                    r[i].estados[j].cidades[k].setCasos(auxInt);

                    getline(arquivo,aux,'\n');
                    istringstream(aux)>>auxInt;
                    r[i].estados[j].cidades[k].setMortes(auxInt);

                    cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
                }
            }
            else
            {//Deve passar para o proximo r[i]

                _data=aux;//Definindo o novo r[i]

                i++;j=0;k=0;//Atualizando as posicoes de i,j,k
                //cout<<i<<endl;

                r[i].setData(aux);//Atualizando as informacoes de r[i]

                getline(arquivo,aux,',');
                estado=aux;//Definindo o novo estados[j]
                r[i].estados[j].setCodEstado(aux);//Atualizando as informacoes de estados[j]

                //Atualizando as informacoes da primeira cidade
                getline(arquivo,aux,',');
                r[i].estados[j].cidades[k].setNome(aux);

                getline(arquivo,aux,',');
                r[i].estados[j].cidades[k].setCodigo(aux);

                getline(arquivo,aux,',');
                istringstream(aux)>>auxInt;
                r[i].estados[j].cidades[k].setCasos(auxInt);

                getline(arquivo,aux,'\n');
                istringstream(aux)>>auxInt;
                r[i].estados[j].cidades[k].setMortes(auxInt);

                cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
            }
        }
        arquivo.close();
        cout<<"Arquivos lidos com sucesso."<<endl;
    }
    else
        cout<<"Erro ao abrir o arquivo"<<endl;
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
