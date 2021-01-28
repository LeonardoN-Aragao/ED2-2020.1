#include <iostream>
#include <fstream>
#include <vector>
#include "Sort.h"
//#include "Registros.h"

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

            numero[0] = 4;
            numero[1] = 1;
            numero[2] = 7;
            numero[3] = 3;
            numero[4] = 8;
            numero[5] = 2;

            ti=clock();

            quickSort(numero,0,tam);

            tf=clock();
            cout<<endl<<"Tempo gasto: "<<(tf-ti)/1000<<endl;

            cout<<endl;
            for(int i = 0; i < tam; i++)
                cout<<numero[i]<<" ";
            cout<<endl;
            
            cout<<endl;
            cout<<"trocaMS: "<<trocaMS<<" compMS: "<<compMS<<endl;
            cout<<"trocaQS: "<<trocaQS<<" compMS: "<<compQS<<endl;

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

void menu()
{
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