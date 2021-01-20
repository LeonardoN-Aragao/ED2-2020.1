#include <iostream>
#include <fstream>
#include <vector>
#include "Sort.h"

void menuAux(char a) {
    
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
        cout<<endl;
        vector<int> numero;
        numero.resize(6);

        numero[0] = 4;
        numero[1] = 1;
        numero[2] = 7;
        numero[3] = 3;
        numero[4] = 8;
        numero[5] = 2;

        mergeSort(numero,0,numero.size());
        cout<<endl;
        for(int i = 0; i < numero.size(); i++)
            cout<<numero[i]<<" ";
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

int main(){
    char a [4] = {'m','i','t','o'};
    char b [5] = {'m','i','n','a','s'}; 

    if(! true){ // Usar func compare sei la
        int c = strcmp(a,b);
        if( c < 0)
            //é menor
        cout<< "TESTE:"<<c;
    }
    menu();
}