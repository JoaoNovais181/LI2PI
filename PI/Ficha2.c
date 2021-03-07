#include <stdio.h>

float multInt1 (int n, float m) {
    float r = 0;
    for (n= n ; n > 0 ; n--){
        r += m;
    }

    return r;
}

float multInt2 (int n, float m) {
    float r = 0;

    while (n>0){
        if (n%2 != 0) r+=m;
        m = m*2;
        n = n/2;
    }

    return r;
}

float multInt3 (int n, float m, int *count){
    float r = 0;

    while (n>0){
        if (n%2 != 0) {r+=m; (*count)++;}
        m = m*2;
        n = n/2;
    }
    (*count)--;

    return r;    
}

void printList (int list[], int a){
    int i;
    for (i = 0; i < a; ++i)
    {
        printf("%d\n", list[i]);
    }
}

int mdc1 (int a, int b){
    if (a > b) {
        int aux = a;
        a = b;
        b = aux;
    }

    int div[a], i=0, r=0;

    for (int k=1; k<= a ; k++){
        if (a%k == 0) div[i] = k;
        else div[i] = 0;
        i++;
    }

    for (i=0; i<=a ; i++) if ((div[i] > r) && (b%div[i]==0)) r = div[i];
    return r;
} 

int mdc2 (int a, int b){
    while (a != b) {
        if (a > b) a-=b;
        else b-=a;
    }
    return a;
}

int mdc3 (int a, int b, int *count){
    while (a != b) {
        if (a > b) a-=b;
        else b-=a;
        (*count)++;
    }
    return a;
}

int mdc4 (int a, int b, int *count){
    while (a != b) {
        if (a > b) a = a%b;
        else b = b%a;
        (*count)++;
    }
    return a;
}

int fib1 (int n) {
    if (n==0) return 0;
    else if (n<2) return 1;
    else return (fib1(n-1) + fib1(n-2));
}

int fib2 (int n){
    int i = 0, j = 1;

    for (int k = 1; k < n ; k++){
        int t = i + j;
        i = j;
        j = t;
    }
    return (i+j);
}

int main() {
    int a , b;
    scanf("%d %d", &a, &b);
    printf("%d\n", mdc1(a,b));

    return 0;
}