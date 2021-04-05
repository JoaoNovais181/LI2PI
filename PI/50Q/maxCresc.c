#include <stdio.h>

int contaCresc (int v[], int N)
{
    int i, r=1;

    for (i=0 ; i<N-1 ; i++) 
    {
        if (v[i]<=v[i+1]) r++;
    }
    return r;
}

int maxCresc (int v[], int N)
{
    int i=0, contAtual=0, contMaior;
    
    contMaior = contaCresc(v, N);
    i = contMaior;

    while (i<N)
    {
        contAtual = contaCresc(v+i, N-i);
        if (contAtual > contMaior) contMaior=contAtual;
        i += contAtual;
    }

    return contMaior;
}