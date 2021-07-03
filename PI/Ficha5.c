#include <stdio.h>

typedef struct aluno {
    int    numero;
    char   nome[100];
    int    miniT [6];
    float  teste;
} Aluno;

// Na Aula



int nota (Aluno a);

void imprimeAluno (Aluno *a)
{
    int i;
    printf("%.5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for (i=1 ; i<6 ; i++) printf(", %d", a->miniT[i]);
    printf(") %5.2f %d\n", a->teste, nota(*a));
}

float notaMiniTestes(Aluno a)
{
    float r = 0.0;
    int i;
    for(i=0 ; i<6 ; i++)   
        r+= a.miniT[i];
    return r*((float)20/12);
}

int nota (Aluno a)
{
    float miniTestes = notaMiniTestes(a);
    float notaTeste = a.teste;
    if (notaTeste >= 8.0 && miniTestes > 8.0)
        return 0.3*(1.666666*miniTestes) + 0.7*notaTeste;

    return 0;
}

int procuraNum (int num, Aluno t[], int N)
{
    int i;
    for (i=0 ; i<N && t[i].numero <= num ; i++)
        if (t[i].numero == num) return i;

    return -1;
}

void swap(Aluno v[], int i, int j)
{
    Aluno aux = v[i];
    v[i] = v[j];
    v[j] = aux;
} 

int partition (Aluno v[], int N, int x)
{
    int i, counter=0;

    for (i=0 ; i+counter<N ; i++)
    {
        if (v[i].numero>x)
        {
            swap(v,i,N-counter-1);
            counter++;
            i--;
        }
    }
    return i;
}

/* void mergeSort (int v[], int N)
{
    if (N<=1) return;
    int i=0;
    int pivot = v[0];
    int menores = partition(v+1,N-1,pivot);
    //printf("%d\n", menores);

    swap(v,0,menores);
    mergeSort(v, menores);

    mergeSort(v+menores+1, N-menores-1);
}*/

void ordenaPorNum (Aluno t[], int N)
{
    if (N<=1) return;
    int pivot = t[0].numero;
    int menores = partition(t+1,N-1,pivot);

    swap(t,0,menores);
    ordenaPorNum(t, menores);
    ordenaPorNum(t+menores+1, N-menores-1);
}

int IndMaior (Aluno t[], int N, int max)
{
    int i,r=0;
    for (i=0 ; i<N ; i++) if (t[i].numero < max) {r=i; break;}
    for (i=1 ; i<N ; i++)
        if (t[i].numero < max && t[i].numero > t[r].numero) r=i;

    return r;
}
void criaIndPorNum (Aluno t [], int N, int ind[])
{
    if (N<=0) return;
    int i, imaior, maior = 2147483647;

    for (i=0 ; i<N ; i++)
    {
        imaior = IndMaior(t,N, maior);
        maior = t[imaior].numero;
        ind[N-i-1] = imaior;
    }
}

// Feito por mim

void imprimeTurma (int ind[], Aluno t[], int N)
{
    int i,j;
    Aluno a;

    for (i=0 ; i<N ; i++)
    {
        a = t[ind[i]];
        printf("%d %s { ", a.numero, a.nome);

        for(j=0 ; j<6 ; j++)
            printf("%d ", a.miniT[j]);

        printf("} %lf\n", a.teste);
    }
}

int procuraNum2 (int num, Aluno t[], int ind[], int N)
{
    int i;

    for (i=0 ; i<N && t[ind[i]].numero <= num ; i++)
        if (t[ind[i]].numero == num) return ind[i];

    return -1;
}

//  Exercicio 7

int menor (char nome[], char nome2[]) // retorna um bool que diz se nome é exclusivamente menor lexicograficamente que nome2
{
    int i=0;

    for ( ; nome[i] != 0 && nome2[i] != 0 ; i++)
    {
        if (nome[i] >= nome2[i]) return 0;
        if (nome[i] < nome2[i]) return 1;
    }

    return 1;
}

int maiorNome (Aluno t[], int N, char max[])  // retorna o maior nome lexicograficamente entre um array de Alunos de Tamanho N que sejam menores que a string max
{
    int i,r=0;
    for (i=0 ; i<N ; i++)
    {
        if (menor(t[i].nome, max) && (1-(menor(t[i].nome, t[r].nome)))==1) r=i;   // se for menor lexicograficamente que max e maior que o maior até ao momento substitui o valor da resposta
    }

    return r;
}

void criaIndPorNome (Aluno t [], int N, int ind[])
{
    if (N<=0) return;
    int i, imaior = maiorNome(t,N, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    ind[N-1] = imaior;

    for (i=1 ; i<N ; i++)
    {
        imaior = maiorNome(t,N, t[imaior].nome);
        ind[N-i-1] = imaior;
    }
}

void imprimeTurma2 (Aluno t[], int N)
{
    int i, j;
    Aluno a;

    for (i=0 ; i<N ; i++)
    {
        a = t[i];
        printf("%d %s { ", a.numero, a.nome);

        for(j=0 ; j<6 ; j++)
            printf("%d ", a.miniT[j]);

        printf("} %lf\n", a.teste);
    }
}

int main ()
{
    Aluno lista[4] = {{4444, "Andre", {2,1,0,2,2,2}, 10.5},
                      {2222, "Joana", {2,2,2,1,0,0}, 14.5},
                      {7777, "Maria", {2,2,2,2,2,1}, 18.5},
                      {3333, "Paulo", {0,0,2,2,2,1},  8.7}};
    int ind[4];

    ordenaPorNum(lista,4);

    imprimeTurma2(lista, 4);

    return 0;
}