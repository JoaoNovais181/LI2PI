#include <stdio.h>

int difConsecutivos (char s[])
{
    int arr[255] = {0};
    int i, j, maior = 0, contador = 0;

    for (i=0; s[i]!=0 ; i++)
    {
        for (j=i, contador = 0 ; s[j]!=0 ; j++)
        {
            if(!arr[(int)s[j]])
            {
                maior = (maior<contador) ?contador :maior;
            }
            else 
            {
                arr[(int)s[j]] = 1;
                contador++;
            }
        }
    }
    return maior;
}