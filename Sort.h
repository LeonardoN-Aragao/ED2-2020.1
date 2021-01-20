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

void intercala(int vet[], int inicio, int meio, int fim) //funcao de intercalacao do Mergesort
{
    /*recebe o vetor vet[] a ser ordenado
    o inicio de uma das particoes: inicio_l1
    o meio onde as particoes foram divididas: meio
    o fim da particao seguinte: fim_l2*/

    int i,j,k;
    int tam_A = meio-inicio+1; //tamanho da primeira particao
    int tam_B = fim-meio; //tamanho da segunta particao

    int A[tam_A], B[tam_B]; //vetores auxiliares das particoes

    for (i=0;i<tam_A;i++) //copia dos elementos de vet para a primeira particao
    {
        A[i]=vet[inicio+i];
    }
    for (j=0;j<tam_B;j++) // copia dos elementos de vet para a segunda particao
    {
        B[j]=vet[meio+1+j];
    }

    i=0;
    j=0;
    k=inicio;

    while (i<tam_A && j<tam_B) // ordenacao
    {
        if(A[i]<B[j])
        {
            vet[k]=A[i];
            i++;
        }
        else
        {
            vet[k]=B[j];
            j++;
        }
        k++;
    }
    while (i<tam_A) //copia dos elementos restantes da primeira particao
    {
        vet[k]=A[i];
        i++;
        k++;
    }
    while (j<tam_B) // copia dos elemtnos restantes da segunda particao
    {
        vet[k]=B[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[],int inicio, int fim)
{
    if (inicio<fim)
    {
        int meio=(inicio+fim)/2;// inicio + (fim-1)/2 evita overflow de numeros grandes
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        intercala(vetor,inicio,meio,fim);
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

