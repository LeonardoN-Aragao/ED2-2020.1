#include <iostream>
#include <fstream>
#include <vector>
#include "Sort.h"
#include "Registros.h"

using namespace std;

char * caminho = "";

void leitura(vector<Registros> r, char* caminho){

    ifstream arquivo;

    arquivo.open(caminho);

    if(arquivo.is_open())
    {
        std::cout<<"O arquivo "<<caminho<<" foi aberto com sucesso."<<endl;
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
        estado = r[0].estados[0].getCodEstado();

        std::cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;

        while(!arquivo.eof())
        {
            getline(arquivo,aux,',');
            if(!strmcmp(aux.c_str(),_data.c_str()))
            {//ainda em r[i]
                getline(arquivo,aux,',');
                if(!strmcmp(aux.c_str(),estado.c_str()))
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

                    std::cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
                }
                else
                {//Mudança no código do estado, deve passar para o próximo estado

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

                    std::cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
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

                std::cout<<"Data: "<<r[i].getData()<<", "<<"Estado: "<<r[i].estados[j].getCodEstado()<<", "<<"Cidade: "<<r[i].estados[j].cidades[k].getNome()<<", "<<"Codigo: "<<r[i].estados[j].cidades[k].getCodigo()<<", "<<"Casos: "<<r[i].estados[j].cidades[k].getCasos()<<", "<<"Mortes: "<<r[i].estados[j].cidades[k].getMortes()<<endl;
            }
        }
        arquivo.close();
        std::cout<<"Arquivos lidos com sucesso."<<endl;
    }
    else
        std::cout<<"Erro ao abrir o arquivo"<<endl;
}

void menuAux(char a) {
    
    cout<<endl;

    switch (a) {

        case '1':
        {   
            std::string  file_name = "";
            std::cout << "Digite o nome do arquivo: ";
            std::cin >> file_name; 

            std::string data;
            std::fstream file;
            file.open(file_name);

            if(file.is_open()){
                getline(file,data);
                int tam =  stoi(data);

                for(int i = 0; i<tam; i++){
                    getline(file,data);
                }
            }
            else
                std::cout << "\nArquivo " << file_name << " não encontrado!\n";

            break;
        }
        case '2':
        {   
            clock_t ti, tf; 

            //Zera variaveis dos sort
            trocaQS = 0;
            trocaMS = 0;
            trocaCS = 0;
            compQS = 0;
            compMS = 0;
            compCS = 0;

            cout<<"MergeSort"<<endl;

            int tam = 6;
            int numero[tam] = {0};

            numero[0] = 4;
            numero[1] = 1;
            numero[2] = 7;
            numero[3] = 3;
            numero[4] = 8;
            numero[5] = 2;

            int vetAux[tam];

            ti=clock();

            mergeSort(numero,0,tam,vetAux);

            tf=clock();
            cout<<endl<<"Tempo gasto: "<<(tf-ti)/1000<<endl;

            for(int i = 0; i < tam; i++)
                cout<<numero[i]<<" ";
            cout<<endl;

            cout<<endl;
            cout<<"Quick Sort"<<endl;

            vector<Registros> registros;

            std::string  file_name = "";
            std::cout << "Digite o nome do arquivo: ";
            std::cin >> file_name; 

            leitura(registros, caminho);
            
            ti=clock();
            
            for (int i = 0; i < registros.size(); i++){
                for(int j = 0; j < 27; j ++){
                    for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                        quickSort(registros[i].estados[j].cidades, 0 ,registros[i].estados[j].getNumCidades());
                    }
                }

            }

            tf=clock();
            cout<<endl<<"Tempo gasto: "<<(tf-ti)/1000<<endl;

            cout<<endl;
            for(int i = 0; i < tam; i++)
                cout<<numero[i]<<" ";
            cout<<endl;
            
            cout<<endl;
            cout<<"trocaMS: "<<trocaMS<<" compMS: "<<compMS<<endl;
            cout<<"trocaQS: "<<trocaQS<<" compMS: "<<compQS<<endl;

            cout<<"Cocktail Sort"<<endl;

            int vet[] = { 5, 1, 4, 2, 8, 0, 2 };
            int n =  7;

            printf("Vetor nao ordenado : \n");
            ImprirmirVetores(vet, n);

            ti = clock();

            CocktailSort(vet, n);

            tf = clock();
            printf("Vetor ordenado :\n");
            ImprirmirVetores(vet, n);
            
            cout<<endl<<"Tempo gasto: "<<(tf-ti)/1000<<endl;
            cout<<endl;
            cout<<"trocaCS: "<<trocaCS<<" compCS: "<<compCS<<endl;
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

    if(arg_t > 1)
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