#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

// Variaveis de troca e comparação dos algoritmos
int trocaQS;
int compQS;
int trocaMS;
int compMS;
int trocaCS;
int compCS;

// Chave de ordenação o número de casos confirmados

void troca(int * a, int * b)
{
    int t = *a;
    *a=*b;
    *b=t;
}

int particao(int vet[], int inicio, int fim)//particionamento de Livro por conta do id
{
    int meio = (inicio+fim)/2;
    int m = 0;

    cout<<"fim: "<<fim<<endl;
    cout<<"\nAntes de escolher o pivo"<<endl;
    for(int i = 0; i <= fim ; i++)
        cout<<vet[i]<<" ";
    cout<<endl;

    if (vet[inicio]<vet[meio])// comparacao dos ids para decidir a mediana
    {
        if ((vet[meio])<(vet[fim]))
        {
            m = meio;
            compQS++;
        }
        else
        {
            if ((vet[inicio])<(vet[fim]))
            {
                m = fim;
                compQS++;
            }
            else
            {
                m = inicio;
                compQS++;
            }
        }
    }
    else
    {
        if ((vet[fim])<(vet[meio]))
        {
            m = meio;
            compQS++;
        }
        else
        {
            if ((vet[fim])<(vet[inicio]))
            {
                m = fim;
                compQS++;
            }
            else
            {
                m = inicio;
                compQS++;
            }
        }
    }
    troca(&vet[m],&vet[fim]); //troca do livro na posicao mediana para o da posicao final
    trocaQS++;

    int pivo = vet[fim]; // selecao do pivo

    cout<<"\npivo: "<<pivo<<endl;
    for(int i = 0; i <= fim ; i++)
        cout<<vet[i]<<" ";
    cout<<endl;


    int i = inicio-1;
    for (int j = inicio;j<=fim;j++)
    {
        if (vet[j]<pivo) //comparacao do id de cada livro com o pivo
        {
            i++;
            troca(&vet[i],&vet[j]);
            trocaQS++;
            compQS++;
        }
    }
    troca(&vet[i+1],&vet[fim]);
    trocaQS++;
    compQS++;
    return i+1; //retorno da particao
}

void quickSort(int vet[],int inicio,int fim){
    if (inicio<fim-1){
        int part = particao(vet,inicio,fim-1);
        quickSort(vet,inicio,part);
        quickSort(vet,part+1,fim-1);
    }
}

// ------------- MERGESORT -------------

/*
    Passo 1: Divida o vetor ao meio
    Passo 2: Ordenar as duas metade
    Passo 3: intercalar as duas metades. 
*/

void merge(int vet[], int inicio, int meio, int fim, int aux[]) {

    // Não precisa de 2 vetores auxiliares apenas um resolve
    // Separa as partições
    int a = inicio;
    int b = meio;

    for (int i = inicio; i < fim; ++i) {
        // Se ainda existe algum numero na partição A não usado
        if (a < meio) {
            // Se o valor de A for < que o valor de B ou se os valores de B já foram completamente usado
            if((vet[a] < vet[b]) || (b >= fim)){
                aux[i] = vet[a];
                trocaMS++;
                a++;
            }
            else {
                aux[i] = vet[b];
                b++;
            }
            compMS++;
        }
        else {
            aux[i] = vet[b];
            ++b;
        }
        compMS++;
    }

    // Copia as alterações de aux para vet
    for (int i = inicio; i < fim; ++i)
        vet[i] = aux[i];
}

void mergeSort(int vet[], int inicio, int fim, int aux[]) {

    if(inicio < fim-1){
        int meio = (inicio + fim)/2;
        mergeSort(vet, inicio, meio, aux);
        mergeSort(vet, meio, fim, aux);
        merge(vet, inicio, meio, fim, aux);
    }
}

// https://www.geeksforgeeks.org/cocktail-sort/
void cocktailSort(){}
