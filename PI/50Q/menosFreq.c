#include <stdio.h>

// Versao 1

void resetVal (int *Atual, int i, int *anterior, int valor, int *contador)
{
    *Atual = i;
    *anterior = valor;
    *contador = 1;
}

int menosFreq (int v[], int N)
{
    int i, iAtual, iMenosFrequente, contador=0, anterior, contadorMenosFreq;

    for (i=0 ; i<N ; i++)
    {
        if (i==0)
        {
            iAtual = 0;
            iMenosFrequente = 0;
            contador++;
            anterior = v[0];
        }
        else 
        {
            if (v[i]==anterior) contador++;
            else
            {
                if (iAtual == 0)
                {
                    contadorMenosFreq = contador;
                    resetVal(&iAtual, i, &anterior, v[i], &contador);
                }
                else if (contador < contadorMenosFreq) 
                {
                    contadorMenosFreq = contador;
                    iMenosFrequente = iAtual;
                    resetVal(&iAtual, i, &anterior, v[i], &contador);
                }
                else
                {
                    resetVal(&iAtual, i, &anterior, v[i], &contador);
                }
            }
        }
    }

    if (contador < contadorMenosFreq) 
    {
        contadorMenosFreq = contador;
        iMenosFrequente = iAtual;
    }

    return v[iMenosFrequente];
}


// Versao 2

int contaRepetidos (int v[], int a, int N)
{
    int i, r=0;
    for (i=0 ; v[i]==a ; i++) r++;
    return r;
}

int menosFreq1 (int v[], int N)
{
    int i, contMenor, contAtual, iMenor;

    iMenor = 0;
    contMenor = contaRepetidos(v,v[0], N);
    i = contMenor;

    while (i<N)
    {
        contAtual = contaRepetidos(v+i, v[i], N-i);
        if (contAtual < contMenor)
        {
            iMenor = i;
            contMenor = contAtual;
        } 
        i+=contAtual;
    }

    return v[iMenor];
}

int main(){
    int a[] = { 2  ,2  ,2  ,3 , 3,  3,  4,  4,  5,  5,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6 };
    printf("%d\n", menosFreq1(a, 20));
    return 0;
}