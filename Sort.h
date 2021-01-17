#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void quickSort(){}


// ------------- MERGESORT -------------

/*
    Passo 1: Divida o vetor ao meio
    Passo 2: Ordenar as duas metade
    Passo 3: intercalar as duas metades. 
*/
vector<int> merge(vector<int> vet, int inicio, int meio, int fim){
    
    for(int z = inicio; z < fim; z++)
        cout<<vet[z]<<" ";
    cout<<endl;

    int i = inicio;
    int j = meio;
    int k = 0;

    while(i <= meio && j <= fim){
        if(vet[i] < vet[j]){
            vet[k] = vet[j];
            i++;
        }
        else{
            vet[k] = vet[i];
            j++;
        }
        k++;
    }
    while(i <= meio){
        vet[k] = vet[i];
        i++;
        k++;
    }
    while(j <= fim){
        vet[k] = vet[j];
        j++;
        k++;
    }
    return vet;
}

void mergeSort(vector<int> vet, int inicio, int final){
    cout<<endl;
    cout<<"inicio: "<<inicio<<endl;
    cout<<"final: "<<final<<endl;

    if(inicio < (final-1)){
        int meio = (inicio + final)/2;
        cout<<"meio: "<<meio<<endl;
        mergeSort(vet,inicio,meio);
        cout<<endl;
        mergeSort(vet,meio,final);
        vet = merge(vet,inicio,meio,final);
    }
}


struct Regiao
{
    string cidade;
    string estado;
};

struct Relatorio
{
    int numero_casos;
    int numero_mortes;
    int numero_notificados;
    int numero_suspeitos;
    int numero_infectados;
    string data;
    Regiao local;
};

/*
 { AM MG MT}
 AM { ... }, MG { ... }, MT { ... }

 Relatorio estado_relatorio[num_estados][cidade][num_relatorio]

*/

// https://www.geeksforgeeks.org/cocktail-sort/
void cocktailSort(){}