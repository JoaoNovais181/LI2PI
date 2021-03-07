#include <stdio.h>
#define INT_MIN -2147483647

int verifica (int num, int num2){
    if (num > num2) return num;
    else return num2;
}

void um(){
    int num, maior;
    maior = 0;

    while (num != 0) {
        printf("Introduza um número: ");
        scanf("%d", &num);
        maior = verifica(num, maior);
    }

    printf("O maior número é: %d\n", maior);
}

void dois(){
    int num, soma = 0, total = 0;

    while (num!=0) {
        printf("Introduza um número: ");
        scanf("%d", &num);
        total ++;
        soma += num;
    }
    total--;

    printf("A média é: %.2f\n", (float)soma/total);
}

void tres(){
    int num, maior = INT_MIN, maior2 = INT_MIN;

    while (num != 0) {
        printf("Introduza um número: ");
        scanf("%d", &num);
        if ((num >= maior2) && (num< maior)) (maior2 = num);
        else if (num > maior) {
            (maior2 = maior);
            (maior = num);
        }
    }

    printf("O segundo maior número é: %d\n", maior2);

}

int bitsUm (unsigned int n){
    int contador=0;
    while (n>=1){
        if (n%2 != 0) ++contador;
        n = n/2;
    }
    printf("%d\n", contador);
    return contador;
}

int trailingZ (unsigned int n){
    if (n == 0) return 32;
    else { 
        int contador=0;
        while (n>0){
            if (n/2 == 0) n = n/2;
            else {
                ++contador;
                n = n/2;
            }
        }
        return contador;
    }
}

int qDig (unsigned int n) {
    int contador = 0;
    while (n>0) {
        ++contador;
        n = n/10;
    }
    return contador;   
}

char *strcat (char s1[], char s2[]){
    int i1 , i2;

    for (i1=0 ; s1[i1]!=0 ; i1++);
    for (i2=0 ; s2[i2]!=0 ; i2++){
        s1[i1] = s2[i2];
        i1++;
    }
    s1[i1] = 0;
    return s1;
}


int main (){
    char a[100] = "papapapa", b[] = "pepepe";
    strcat(a,b);
    puts(a);
}