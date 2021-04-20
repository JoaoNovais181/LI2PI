#include <stdio.h>

int elimRep (int v[], int n)
{
    int i, j, k;

    for (i=0, k=0 ; i<n ; i++)
    {
        int elem = 0;
        for (j=0 ; j<k ; j++) if (v[j] == v[i]) elem = 1;

        if (elem == 0) 
        {
            v[k] = v[i];
            k++;
        }
    }
    return k; 
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
    int v[] = {1, 2, 2, 1, 4, 2, 3, 5, 4}, size;
    printArray(v,9);
    size = elimRep(v,9);
    printArray(v,size);
}