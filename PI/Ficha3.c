#include <stdio.h>

/*  Exercicio 1

a) 
int main () {
    int x [15] = {1,  2, 3, 4, 5,
                  6,  7, 8, 9,10,
                  11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x+3;
    for (i=0; i<5; i++) {
        printf ("%d %d %d\n",
                x[i], *y, *z);
        y = y+1; z = z+2;
    }
}

y -> x -> 1
z -> x+3 -> 4

i=0 ->  i<5 -> Executa :
    1 1 4\n
    
    y -> y+1 -> x+1 -> 2
    z -> z+2 -> x+3+2 -> 6

i=1 ->  i<5 -> Executa:
    2 2 6\n 

    y -> y+1 -> x+1+1 -> 3
    z -> z+2 -> x+3+2+2 -> 8

i=2 ->  i<5 -> Executa:
    3 3 8\n 

    y -> y+1 -> x+1+1+1 -> 4
    z -> z+2 -> x+3+2+2+2 -> 10

i=3 ->  i<5 -> Executa:
    4 4 10\n 

    y -> y+1 -> x+1+1+1+1 -> 5
    z -> z+2 -> x+3+2+2+2+2 -> 12

i=4 ->  i<5 -> Executa:
    5 5 12\n 

    y -> y+1 -> x+1+1+1+1+1 -> 6
    z -> z+2 -> x+3+2+2+2+2+2 -> 14

i=2 ->  i==5 -> Não executa

output ->   1 1 4
            2 2 6
            3 3 8
            4 4 10
            5 5 12

b)
int main () {
  int i, j, *a, *b;
    
  i=3; j=5;
  a = b = 42;
  a = &i; b = &j;
  i++;
  j = i + *b;
  b = a;
  j = j + *b;
  printf ("%d\n", j);

  return 0;
}

i=3 e j=5

a=b=42 (não vai fazer nada pois como a e b sao endereços de int não podem tomar o valor de Int)

a=&i e b=&j (a é o endereço de i e b o endereço de j)

i++ -> i=4

j = i + *b -> j = 4 + 5 -> j = 9 (j toma o valor de i mais o valor presente no endereço b, que é o valor de j)

b = a -> b = &i (b passa a ser o endereço de i)

j = j + *b -> j = 9 + 4 -> j = 13 (j toma o valor de j mais o valor presente no endereço b, que é o valor de i)

output : 13
*/

//Exercicio 2
void swapM (int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

//Exercicio 3
void swap (int v[], int i, int j){
    swapM(&v[i],&v[j]);
    /* Ou assim
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux; */
}

//Exercicio 4
int soma (int v[], int N){
    int i,r=0;
    for (i=0; i<N ; i++) r+=v[i];
    return r; 
}

//Exercicio 5
void inverteArray1 (int v[], int N){
    int i=0;
    for (i=0 ; i<(N/2) ; i++) swapM(&v[i], &v[N-1-i]);
}
void inverteArray2 (int v[], int N){
    int i=0;
    for (i=0 ; i<(N/2) ; i++) swap(v,i,(N-1-i));
}

//Exercicio 6
int maximum (int v[], int N, int *m){
    if (N>0) {
        *m = v[0];
        for (int i = 0 ; i<N ; i++) {
            if (v[i] > (*m)) *m = v[i];
        }
        return 0;
    }
    else return 1;
}

//Exercicio 7
void quadrados (int q[], int N){
    int i = -1;
    for ( ; i<N-1 ; i++) q[i+1] = i*i + (2*i+1);
}

/* Maneira do Stor
void quadrados (int q[], int N) {
    int quad = 0, i;
    for (i=0 ; i<N ; i++) {
        if (i==0) q[0] = 0;
        else q[i] = q[i-1] + 2*(i-1)+1;
    }
}
*/

//Exercicio 8
void pascal (int v[], int N) {
    if (N>1) {
        v[0] = v[N] = 1;
        int N1 = N-1, v1[N1];
        pascal(v1,N1);
        for (int i = N-1 ; i >= 1 ; i--) v[i] = v1[i] + v1[i-1];
    }
    else if (N==0) v[0] = 1;
    else if (N==1) {v[0] = 1; v[N] = 1;}
}

void pascal1 (int v[], int N) {
    if (N>1) {
        v[0] = v[N] = 1;
        int N1 = N-1, v1[N1];
        pascal1(v1,N1);
        for (int i = N-1 ; i >= 1 ; i--) v[i] = v1[i] + v1[i-1];
        for (int k = 0 ; k <= N ; k++) printf("%d ", v[k]);
        putchar('\n');
    }
    else if (N==0) v[0] = 1;
    else if (N==1) {
        v[0] = 1; v[N] = 1;
        printf("1\n1 1\n");
    }
}

void aux (int v[], int N){
    int i; 
    if (N!=0) { 
        v[N-1]=1;
        for(i=N-2 ; i>=0 ; i--)
            v[i] = v[i] + v[i-1];
        for (i=0 ; i<N ; i++)
            printf("%d ", v[i]);
        putchar('\n');
    }
}

void pascal2 (int v[], int N) {
    int i;
    for (i=1 ; i<=N ; i++) {
        aux(v,i);
    }
}

int main () {
    int v[100000], q[10];
    int n=4;
    pascal1(v, n);
}
