#include <stdio.h>

void swap (int v[], int a, int b) 
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

// AULA T9 (23. Mar)

int bubble (int v[], int N) 
{
    int i;
    int r=1;

    for (i=0 ; i<N-1 ; i++)
        if (v[i] > v[i+1]) { swap(v,i,i+1); r=0;}
    return r;
}

void bubbleSort (int v[], int N) 
{
    int i;
    int ord = 0;

    for (i=0 ; i<N-1 && ! ord ; i++)
        ord = bubble (v,N);
}

//----------------------------------------------------

int bubble2 (int v[], int N)
{
    int i;
    int r=0;

    for (i=0 ; i<N-1 ; i++)
        if (v[i] > v[i+1]) 
        {  
            swap(v , i , i+1);
            r=1;
        }
    return r;
}

// TPC : fazer uma versão xpto do bubblesort com a bubble2 

// INSERTION SORT

void insere (int v[], int N, int x) // Inserir ordenadamente no array
{
    // v[0..N[ está ordenado
    // inserir o x
    // no final v[0..N+1[ está ordenado
    int j;
    for (j=N-1; j>=0 && v[j] > x ; j--) // "puxamos" os numeros maiores que x para a direita 
        v[j+1] = v[j];
    v[j+1] = x; // colocamos o x na posição correta
}

void insSort (int v[], int N)
{
    int i;
    // o array v, nos índices [0..i[ está ordenado
    i=1;
    while (i<N)
    {
        insere (v,i,v[i]);
        i++;

    }
}

// ------------------------------------------

// Divisao e Conquista

// Merge - Sort

void merge (int a[], int na, int b[], int nb, int r[]);

void mergeSort (int v[], int N)
{
    int m;
    int aux[N];
    if (N>1)
    {
        n=N/2;
        // 1ª metade v[0..m[ que tem m   elementos
        // 2ª metade v[m..N[ que tem N-m elementos
        mergeSort(v,m);
        mergeSort(v+m, N-m);
        merge(v,m,v+m,N-m, aux);
        for (i=0 ; i<N ; i++) v[i] = aux[i];
    }
}

// ---------------------------------------------

// Quick-Sort

/*
Escolher um elemento x do array (pivot)
reorganizar o array de forma a que
 - começam por aparecer todos os elementos menores ou iguais a x
 - de seguida aparecem os restantes elementos (maiores do que x)
*/
int partition (int v[], int N)
{
    // Usa como pivot v[N-1]

    int r, i;

    for (r=i=0 ; i<N-1 ; i++)
        if (v[i] <= v[N-1]) swap(v, r++, i); 

    swap(v, r, N-1);
    return r;
}

void qSort (int v[], int N)
{
    int p;

    if (N>1)
    {
        p = partition (v,N);
        qSort (v, p);
        qSort (v+p+1, N-p-1);
    }
}