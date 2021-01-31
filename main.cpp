#include <iostream>
#include <fstream>
#include <vector>
#include "Sort.h"
#include "Registros.h"

using namespace std;

//VARIAVEIS QUE GUARDAM CAMINHO DO ARQUIVO E O NUM DE REGISTRO LIDOS
char * caminho;
int n;

void testaSort(int n){  

    Registros * registros = new Registros[257];
    clock_t ti, tf; 

    //Zera variaveis dos sort
    trocaQS = 0;
    trocaIS = 0;
    trocaCS = 0;
    compQS = 0;
    compIS = 0;
    compCS = 0;

    cout<<endl;
    cout<<"Insertion Sort"<<endl;

    registros->leitura(registros,caminho);

    ti=clock();

    for (int i = 0; i < registros->getTamanho(); i++){
        for(int j = 0; j < 27; j ++){
            for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                insertionSort(registros[i].estados[j].cidades,registros[i].estados[j].getNumCidades());
            }
        }
    }

    tf=clock();
    cout<<endl<<"Tempo gasto: "<<(tf-ti)/double(CLOCKS_PER_SEC)<<endl;
    
    registros->leitura(registros,caminho);

    cout<<endl;
    cout<<"Quick Sort"<<endl;
    
    ti=clock();
     
    for (int i = 0; i < registros->getTamanho(); i++){
        for(int j = 0; j < 27; j ++){
            for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                //quickSort(registros[i].estados[j].cidades, 0 ,registros[i].estados[j].getNumCidades());
            }
        }
    }

    tf=clock();
    cout<<endl<<"Tempo gasto: "<<(tf-ti)/double(CLOCKS_PER_SEC)<<endl;
    
    cout<<endl;
    cout<<"Cocktail Sort"<<endl;

    ti = clock();

    for (int i = 0; i < registros->getTamanho(); i++){
        for(int j = 0; j < 27; j ++){
            for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                cocktailSort(registros[i].estados[j].cidades,registros[i].estados[j].getNumCidades());
            }
        }
    }

    tf = clock();

    cout<<"Num Registros: "<<n<<endl;
    cout<<endl<<"Tempo gasto: "<<(tf-ti)/double(CLOCKS_PER_SEC)<<endl;
    cout<<"trocaIS: "<<trocaIS<<" compIS: "<<compIS<<endl;
    cout<<"trocaQS: "<<trocaQS<<" compMS: "<<compQS<<endl;
    cout<<"trocaCS: "<<trocaCS<<" compCS: "<<compCS<<endl;
    cout<<endl;
}

void menuAux(char a) {
    
    cout<<endl;

    switch (a) {

        case '1':
        {   
            //Passo 1: leitura dos arquivos corretamente e armazenamento em estrutura apropriada (definida pelo programador);
            //Passo 2: Algoritmo de ordenação: (Estado/Cidade)->Data;
            //Passo 3: Transformar totais acumulados em totais diarios;
            //Passo 4: Armazenar os dados em "brazil_covid19_cities_processado.csv";

            //=============================================PASSO 1=============================================
            cout<<"O caminho: "<<caminho<<" foi recebedio."<<endl;
            Registros*r = new Registros[260];
            r->leitura(r,caminho);

            ofstream saida;
            saida.open("brazil_covid19_cities_processado.csv"); //PREPARANDO PASSO 4
                
            //=============================================PASSO 2=============================================
            for(int i=0;i<r->getTamanho();i++)
            {
                for (int j=0; j<27;j++)
                {
                    insertionSortCidades(r[i].estados[j].cidades,r[i].estados[j].getNumCidades());
                }
                insertionSortEstados(r[i].estados,27);
            }
            insertionSortRegistros(r,r->getTamanho());

            //=============================================PASSOS 3 e 4=============================================
            int c=0,m=0;
            int i=0,j=0,k=0;
            saida<<"date,state,name,cases,death"<<endl;
            for(i=0;i<27;i++)
            {
                for (j=0;j<r[k].estados[i].getNumCidades();j++)
                {
                    for (k=0;k<r->getTamanho();k++)
                    {
                        if(k==0)
                        {
                            c=r[k].estados[i].cidades[j].getCasos();
                            m=r[k].estados[i].cidades[j].getMortes();
                        }
                        else
                        {
                            c=r[k].estados[i].cidades[j].getCasos()-r[k-1].estados[i].cidades[j].getCasos();
                            m=r[k].estados[i].cidades[j].getMortes()-r[k-1].estados[i].cidades[j].getMortes();
                        }

                        if(c<0) c=0; //O arquivo brazil_covid19_cities.csv deveria apresentar um conjunto acumulativo de dados de casos de morte e infecção por covid 19, no entanto em alguns campos apresenta-se um decressimo de um valor que deveria ser acumulativo...
                        if(m<0) m=0; //... para contornar essa inconsistencia, ela sera considerada um erro. Ou seja, toda vez que o numero acumulado de mortes ou casos seja inferior que o da data anterior, a diferenca sera considerada 0

                        saida<<r[k].getData()<<","<<r[k].estados[i].getCodEstado()<<","<<r[k].estados[i].cidades[j].getNome()<<","<<c<<","<<m<<endl;
                    }
                }
            }
            saida.close();

            break;
        }
        case '2':
        {   
            int num_registros [4]= {10000, 50000,100000,1000000};
            //for(int i = 0; i<4; i ++)
             //   testaSort(num_registros[i]);

            testaSort(0);
            break;
        }
        case '3':
        {        
            
            std::cout << "\nAguarde... \n";

            std::cout << "\nFinalizado! \n";
            break;
        }
        //---------- Usar para Testes ----------
        case '4':
        {
            std::cout << "\nSem testes por aqui no momento. :(\n";
            break;
        }
        default:
            break;
    }
}

void menu() {
    //System("tput reset");
    char menu;

    while (true) {
        std::cout << "\n";
        std::cout << "# Menu principal #\n";
        std::cout << "[1] - Parte 1\n";
        std::cout << "[2] - Parte 2\n";
        std::cout << "[3] - Parte 3\n";
        std::cout << "[4] - Testes\n";
        std::cout << "\n";

        do {
            std::cout << "Digite uma opcao do menu: ";
            std::cin >> menu;
        } while (((menu < '0' || menu > '5') && (menu < 'a' || menu > 'z')) && menu != 'q');

        if (menu == 'q') {
            std::cout << "Saindo...\n";
            std::cout << "Bye\n";
            return;
        }
        menuAux(menu);
    }
}

int main(int arg_t, char ** argv){

    if(arg_t == 2)
        caminho = argv[1];
    else
        exit(1);

    char a [4] = {'m','i','r','o'};
    char b [5] = {'m','i','n','a','s'}; 
    
    //cout<<"O caminho "<<argv[1]<<" foi recebido"<<endl;
    //Registros * r = new Registros[260];
    //r->leitura(r,argv[1]);

    if(! true){ // Usar func compare sei la
        int c = strcmp(a,b); //retorna se a é menor ou mair que b, e precisa de um compare antes, pois em caso igual pega o numero da tabela ASCII
        if( c < 0)
            //é menor
        cout<< "TESTE:"<<c;
    }
    menu();
}