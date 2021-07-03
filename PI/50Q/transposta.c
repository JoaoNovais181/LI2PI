#include <stdio.h>

void swap (float *a, float *b)
{
    *b += *a;
    *a = *b - *a;
    *b -= *a;
}
void transposta (int N, float m [N][N])
{
    int i, j;

    for (i=0 ; i<N ; i++)
        for (j=i+1 ; j<N ; j++)
            swap(&m[i][j], &m[j][i]);
}

void printMat (int N, float m[N][N])
{
    int i,j;
    for (i=0 ; i<N ; i++)
    {
        for (j=0 ; j<N ; j++)
            printf("%f ", m[i][j]);
        putchar('\n');
    }
 
}

int main ()
{
    float m[5][5];
    int i, j;
    for (i=0 ; i<5 ; i++)
        for (j=0 ; j<5 ; j++)
            m[i][j] = j+1;
    printMat(5,m);

    transposta(5,m);

    printMat(5,m);
}