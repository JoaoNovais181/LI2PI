#include <stdio.h>

int contaRepetidos (int v[], int a, int N)
{
    int i, r=0;
    for (i=0 ; v[i]==a ; i++) r++;
    return r;
}

int maisFreq (int v[], int N)
{
    int i, contMenor, contAtual, iMenor;

    iMenor = 0;
    contMenor = contaRepetidos(v,v[0], N);
    i = contMenor;

    while (i<N)
    {
        contAtual = contaRepetidos(v+i, v[i], N-i);
        if (contAtual > contMenor)
        {
            iMenor = i;
            contMenor = contAtual;
        } 
        i+=contAtual;
    }

    return v[iMenor];
}