#include <stdio.h>

int elimRepOrd (int v[], int n)
{
    if (n>=1) {
        int i, anterior = v[0], k;
        
        for (i=1, k=1 ; i<n ; i++)
        {
            if (v[i] != anterior)
            {
                v[k] = v[i];
                k++;
            }
            anterior = v[i];
        }
        return k;
    }
}

void printArray (int v[], int size)
{
    int i;
    printf("{ ");
    for (i=0 ; i<size ; i++) printf("%d ", v[i]);
    printf("}\n");
}

int main ()
{
    int v [] = {1,1,2,2,2,2,3,4,5,5}, size;

    printArray(v,10);
    size = elimRepOrd(v, 10);
    printArray(v,size); 

} 