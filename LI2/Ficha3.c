#include <stdio.h>

void repeteChar (int n, char c){
    int i;
    for(i=0 ; i<n ; i++) putchar(c);
}
int main (){
    int n , i;
    if (scanf("%d", &n) == 1){

        for (i = 1; i<=2*n-1 ; i++){
            if (i < n) {
                repeteChar(i,'*');
                repeteChar(2*n-(2*i), '.');
                repeteChar(i,'*');
                putchar('\n');
            }
            else if (i>n) {
                int j;
                j = 2*n-i;
                repeteChar(j,'*');
                repeteChar(2*n-(2*j), '.');
                repeteChar(j,'*');
                putchar('\n');
            }
            else {
                repeteChar(2*n, '*');
                putchar('\n');
            }
        }
    }
}