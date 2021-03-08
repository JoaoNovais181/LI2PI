#include <stdio.h>
#include <assert.h>


void repeteNum (int vezes, int num) {
    if (vezes > 0) {
        for (int i = vezes ; i > 0 ; i--) {
            printf("%d", num);
        }
    }
}

int main () {
    int diagrama[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}},
        input = 0, i;

    while (input != -1) {

        assert((scanf("%d", &input)) == 1);

        int dezenas, unidades;

        unidades = input%10;
        dezenas = input/10;

        diagrama[dezenas][unidades] += 1;

    }

    for (i = 0 ; i <= 9 ; i++) {
        printf("%d|", i);
        for (int k = 0 ; k <= 9 ; k++) {
            if (diagrama[i][k] != 0) repeteNum(diagrama[i][k], k);
        }
        putchar('\n');
    }
    

    return 0;

}