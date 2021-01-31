#include <iostream>
#include <fstream>
#include <vector>
#include "Sort.h"
#include "Registros.h"

using namespace std;

//VARIAVEIS GLOBAIS QUE GUARDAM CAMINHO DO ARQUIVO, QUANTIDADE TOTAL DE REGISTROS E O NUM DE REGISTRO LIDOS
const int quantidadeRegistros = 1431490; // Está no relatório e pode ajudar caso precise ler o arquivo inteiro.
char * caminho;

void leitura(Registros* r, int num_registros, char* caminho)
{
    if (num_registros > 0 && num_registros <= quantidadeRegistros) //Se quiser ler o arquivo inteiro, usar a variavel QuantidadeRegistros.
    {
        ifstream arquivo;
        arquivo.open(caminho);

        if(arquivo.is_open())
        {
            std::cout<<"O arquivo "<<caminho<<" foi aberto com sucesso."<<endl;
            /*
            //Pega tamanho do arquivo
            arquivo.seekg(0,arquivo.end);
            int tamanho = arquivo.tellg();
            arquivo.seekg(0,arquivo.beg);
            */

            string aux; //variavel auxiliar de leitura de texto
            getline(arquivo,aux,'\n');//Lendo a primeira linha

            int auxInt;//Variavel auxiliar de conversao de texto em inteiros

            //Leitura dos primeiros elementos
            getline(arquivo,aux,',');
            r[0].setData(aux);

            string _data,estado;//Variaveis de controle da etapa de leitura
            _data = aux;//Ajustando a variavel de controle dos registros

            getline(arquivo,aux,',');
            r[0].estados[0].setCodEstado(aux);
            estado = aux;//Ajustando a variavel de controle dos estados

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

            int c=1;//Variavel de controle do movimento de linhas da leitura do arquivo

            int i=0;
            int j=0;
            int k=0;
            while(!arquivo.eof() && c < num_registros)
            {
                getline(arquivo,aux,',');//Lendo o campo da data
                if(!(abs(comparacao(aux,_data)))) //strncmp retorna valores diferentes de zero se as strings forem diferentes, e igual a zero se forem iguais. If reconhece verdadeiro se diferente de zero e falso se igual a zero, portanto e valido usar a funcao desta forma.
                {//ainda em r[i]
                    getline(arquivo,aux,',');
                    if(!(abs(comparacao(aux,estado))))
                    {//ainda em estados[j];
                        k++;//Com isso, as cidades variam

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
                    }
                    else
                    {//Mudan�a no codigo do estado, deve passar para o proximo estado

                        r[i].estados[j].setNumCidades(k+1); //Atualizando o numero de cidades do estado anterior. Nao e preciso mudar essa grandeza quando i !=0, pois isso ja tera sido feito na primeira iteracao de i.
                        
                        estado=aux;//Definindo o novo estados[j]

                        j++;k=0;
                        
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
                    }
                }
                else
                {//Deve passar para o proximo r[i]

                    _data=aux;//Definindo o novo r[i]

                    if(r[i].estados[j].getNumCidades()==0) 
                        r[i].estados[j].setNumCidades(k+1);
                        
                    i++;j=0;k=0;//Atualizando as posicoes de i,j,k

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
                }
                c++;
            }
            r[0].setTamanho(i-1);//Desconsidera a ultima linha
            std::cout<<"Arquivo lido com sucesso."<<endl;
        }
        else
            std::cout<<"Erro ao abrir o arquivo"<<endl;
    }
    else
        std::cout<<"Tamanho de parametro invalido."<<endl;
}

void testaSort(int num_registros){  

    Registros * registros = new Registros[257];
    clock_t ti, tf; 

    //Zera variaveis dos sort
    trocaQS = 0;
    trocaIS = 0;
    trocaCS = 0;
    compQS = 0;
    compIS = 0;
    compCS = 0;

    std::cout<<endl;
    std::cout<<"Insertion Sort"<<endl;
    leitura(registros,num_registros,caminho);

    ti=clock();

    for (int i = 0; i < registros->getTamanho(); i++){
        for(int j = 0; j < 27; j ++){
            for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                insertionSort(registros[i].estados[j].cidades,registros[i].estados[j].getNumCidades());
            }
        }
    }

    tf=clock();
    std::cout<<endl<<"Tempo gasto: "<<(tf-ti)/double(CLOCKS_PER_SEC)<<endl;
    
    std::cout<<endl;
    std::cout<<"Quick Sort"<<endl;
    leitura(registros,num_registros,caminho);
    
    ti=clock();
     
    for (int i = 0; i < registros->getTamanho(); i++){
        for(int j = 0; j < 27; j ++){
            for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                //quickSort(registros[i].estados[j].cidades, 0 ,registros[i].estados[j].getNumCidades());
            }
        }
    } 
 
    tf=clock();
    std::cout<<endl<<"Tempo gasto: "<<(tf-ti)/double(CLOCKS_PER_SEC)<<endl;
    
    std::cout<<endl;
    std::cout<<"Cocktail Sort"<<endl;

    leitura(registros,num_registros,caminho);

    ti = clock();

    for (int i = 0; i < registros->getTamanho(); i++){
        for(int j = 0; j < 27; j ++){
            for(int k = 0; k < registros[i].estados[j].getNumCidades(); k ++){
                cocktailSort(registros[i].estados[j].cidades,registros[i].estados[j].getNumCidades());
            }
        }
    }

    tf = clock();

    std::cout<<"Num Registros: "<<num_registros<<endl;
    std::cout<<endl<<"Tempo gasto: "<<(tf-ti)/double(CLOCKS_PER_SEC)<<endl;
    std::cout<<"trocaIS: "<<trocaIS<<" compIS: "<<compIS<<endl;
    std::cout<<"trocaQS: "<<trocaQS<<" compMS: "<<compQS<<endl;
    std::cout<<"trocaCS: "<<trocaCS<<" compCS: "<<compCS<<endl;
    std::cout<<endl;
}

void menuAux(char a) {
    
    std::cout<<endl;

    switch (a) {

        case '1':
        {   
            //Passo 1: leitura dos arquivos corretamente e armazenamento em estrutura apropriada (definida pelo programador);
            //Passo 2: Algoritmo de ordenação: (Estado/Cidade)->Data;
            //Passo 3: Transformar totais acumulados em totais diarios;
            //Passo 4: Armazenar os dados em "brazil_covid19_cities_processado.csv";

            //=============================================PASSO 1=============================================
            std::cout<<"O caminho: "<<caminho<<" foi recebedio."<<endl;
            Registros*r = new Registros[260];
            leitura(r,quantidadeRegistros,caminho);

            ofstream saida;
            saida.open(caminho); //PREPARANDO PASSO 4

            //=============================================PASSO 2=============================================
            if(saida.is_open()){

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
                std::cout<<"Leitura do arquivo terminada, saida gerada."<<endl;
            }
            else
                std::cout<<"Não foi possivel abrir o arquivo "<<caminho<<"."<<endl;

            break;
        }
        case '2':
        {   
            int num_registros [4]= {10000, 50000,100000,1000000};
            for(int i = 0; i<4; i ++)
                testaSort(num_registros[i]);
            break;
        }
        case '3':
        {        
            
            std::cout << "\nAguarde... \n";
            std::cout << "\nNada por aqui no momento.\n";
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
        std::cout << "[1] - Leitura e pré-processamento de todo o arquivo\n";
        std::cout << "[2] - Execução dos Sorts (InsertionSort,QuickSort,CocktailSort)\n";
        std::cout << "[3] - Teste MergeSort\n";
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
    menu();
}