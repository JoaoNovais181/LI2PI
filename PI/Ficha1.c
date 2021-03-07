#include <stdio.h>
/* Exercicio 1
 * 1. 12 16
 * 2. 0 0
 * 3. 'A' 65
 *    'B' 66 '2' 50
 *    'b' 98
 * 4. 100 200
 */
/* Exercicio 2
 * (a) 3 5
 * (b) 11 66
 * (c) _#_#_#_#_#_#_#_#_#_#
 * (d)
 *     1
 *     01
 *     11
 *     001
 *     101
 *     011
 *     111
 *     0001
 *     1001
 *     0101
 *     1101
 *     0011
 *     1011
 *     0111
 *     1111
 *
 */
int main();
void quadrado (int x){
    int l , a;
    l = a = x;
    for (int k = a; k > 0 ; --k) {
        for (int j = l; j >= 0 ; --j) {
            if (j == 0) putchar('\n');
            else putchar('#');
        }
    }
    main();
}

void xadrez (int x) {
    int l , a;
    for (a=0 ; a<x ; a++){
        for (l=0 ; l<x ; l++){
            if((a+l)%2 == 0) putchar('#');
            else putchar('_');
        }
        putchar('\n');
    }
    main();
}

void repeteChar(char c, int n){
    int j;
    for (j = n; j>0 ; --j) putchar(c);
}
void trianguloVertical (int x){
    int i;
    for (i = 1  ; i<=x ; ++i){
        repeteChar('#',i);
        putchar('\n');
    }
    for (i = x-1  ; i >0 ; --i){
        repeteChar('#',i);
        putchar('\n');
    }
    main();
}
 /*
void trianguloHorizontal (int x){
    int a = x; int k; int base = (2*a - 1);
    for (k=0 ; k <= a ; ++k) {
        int j;
        for (j = 1 ; j <= base +1; ++j) {
            int l = k-1;
            if (j == base +1) putchar('\n');
            else if ((j < (base / 2) - (l-1)) || (j > (base / 2) + (l+1))) putchar(' ');
            else putchar('#');
        }
    }
    main();
}
*/

void trianguloHorizontal (int n){
    int i;
    for (i=1 ; i<=n ; i++){
        repeteChar(' ', n-i);
        repeteChar('#', 2*i-1);
        putchar('\n');
    }
    main();
}

void circulo(int raio){
    int x,y;
    for(y=raio ; y>=-raio ; y--){
        for(x=-raio ; x<=raio ; x++) {
            if (x*x + y*y <= raio * raio) putchar('#');
            else putchar(' ');
        }
        putchar('\n');
    }
    main();
}

int main() {
    putchar('\n');
    int i, p ;
    printf("Introduza o dígito da ação que pretende fazer:\n 1. Fazer quadrado\n 2. Fazer tabuleiro de xadrez\n 3. Fazer Triângulo Vertical\n 4. Fazer Triângulo Horizontal\n 5. Fazer Círculo\n outro. Sair\n");
    scanf("%i", &p);
    switch (p) {
        case 1:
            printf("Qual é o comprimento do lado que deseja?\n");
            scanf ("%d",&i);
            quadrado(i);
        break;
        case 2:
            printf("Qual é o comprimento do lado que deseja?\n");
            scanf ("%d",&i);
            xadrez(i);
        break;
        case 3:
            printf("Qual é a altura que deseja?\n");
            scanf("%d",&i);
            trianguloVertical(i);
        break;
        case 4:
            printf("Qual é a altura que deseja?\n");
            scanf ("%d",&i);
            trianguloHorizontal(i);
            break;
        case 5:
            printf("Qual o raio que deseja?\n");
            scanf("%d", &i);
            circulo(i);
            break;
        default:
            break;
        return 0;
    }
}
