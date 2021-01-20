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

void merge(int vetor[], int inicio, int meio, int fim, int aux[]) {

    int a = inicio;
    int b = meio;

    for (int i = inicio; i < fim; ++i) {
        
        if (a < meio) {
            if((b >= fim) || (vetor[a] < vetor[b])){
                aux[i] = vetor[a];
                ++a;
            }
            else {
                aux[i] = vetor[b];
                ++b;
            }
        }
        else {
            aux[i] = vetor[b];
            ++b;
        }
    }

    for (int i = inicio; i < fim; ++i)
        vetor[i] = aux[i];
}

void mergeSort(int vet[], int inicio, int fim, int aux[]) {

    if(inicio < fim-1){
        int meio = (inicio + fim)/2;
        mergeSort(vet, inicio, meio, aux);
        mergeSort(vet, meio, fim, aux);
        merge(vet, inicio, meio, fim, aux);
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

