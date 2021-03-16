#include <stdio.h>
#include <string.h>

void um(){
    int max,a;
    max=scanf("%d",&a);
    while (a!=0){
        scanf("%d",&a);
        if (a>max) max=a;
    }
    printf("%d\n",max);
}
void dois(){
    int somatorio,n,a=1;
    while (a!=0){
        scanf("%d",&a);
        somatorio+=a;
        n++;
    }
    n--;
    printf("%d\n",somatorio/n);
}
void tres(){
    int max,a,max2;
    max=scanf("%d",&a);
    while (a!=0){
        scanf("%d",&a);
        if (a>max){
            max2=max;
            max=a;
        }
    }
    printf("%d\n",max2);
}


int bitsUm (unsigned int n){
    int c=0;
    while (n!=0){
        if (n%2==1) c++;
        n/=2;
    }
    return c;
}

int trailingZ (unsigned int n){
    if (n==0) return 32;
    else{
    int c=0;
    while (n%2!=1 && n!=0){
        c++;
        n/=2;
    }
    return c;
}}

int qDig (unsigned int n){
    int c=0;
    while (n>9){
        n=n/10;
        c++;
    }
    c++;
    return c; 
}

char *mystrcat (char s1[], char s2[]){
    int i,j;
    for (i = 0;s1[i]!='\0';i++);
    for (j = 0;s2[j]!='\0';j++){
        s1[i+j] = s2[j];
    }
    s1[i+j]='\0';
    return s1;
}

char *mystrcpy (char *dest, char source[]){
    int i;

    for(i=0 ; source[i] != '\0' ; i++) dest[i]=source[i];

    dest[i] = '\0';

    return dest;
}

int mystrcmp (char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' ; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        else if (s1[i] < s2[i]) {
            return (-1);
        }
    }

    if (s2[i++] != '\0') {
        return -1;
    }
    return 0;    
}

/* Primeira tentativa
int igual (char s1[], char s2[]){
    int i,r=0;

    for(i=0 ; (s1[i]!='\0') || (s2[i]!='\0') ; i++){
        r += (1 - (s1[i] == s2[i]));
    }

     return (r>0) ? 1: 0;
}
char *mystrstr (char s1[], char s2[]){
    int i,k,j; char *r;

    for (i=0 ; s1[i] != '\0' ; i++) {
        if (s1[i] == s2[0]) {
            for (k = 0 ; s2[k] != '\0' ; k++) {
                if (s1[i+k] == s2[k]) (r[k] = s1[i+k]);
                else;
            }
            if (igual(s2, r) == 0) {
                for (j = 0; s1[i+j] != '\0' ; j++) {
                    r[k+j] = s1[i+j];
                }
                return r;
            }
            else;
        }
    }

    return NULL;
}*/

char *mystrstr (char s1[], char s2[]){
    int i, j=0, inicio;

    if (s2[0] == '\0') return s1;

    for (i=0 ; s1[i] != '\0' ; i++){

        if (s1[i] == s2[j] && j==0) {
            inicio = i;
            j++;
        }
    
        else if (s1[i] == s2[j]) j++;
             else j=0;
    
        if (s2[j] == '\0') return s1+inicio;
    }

    return NULL;
}

int length (char s[]) {
    int r = 0, i;

    for (i=0 ; s[i]!='\0' ; i++) r+=1;

    return r; 
}


void strrev (char s[]) {
    int i, l = (length(s)-1);

    for (i=0 ; i<=l; i++) {
        char a = s[i];
        s[i] = s[l];
        s[l] = a;
        l--;
    }
}

void strnoV (char s[]){
    int i;

    for (i=0 ; s[i]!='\0' ; i++) {
        if (((char)s[i] == 'a') || ((char)s[i] == 'A') || ((char)s[i] == 'e') || ((char)s[i] == 'E') || ((char)s[i] == 'i') || ((char)s[i] == 'I') || ((char)s[i] == 'o') || ((char)s[i] == 'O') || ((char)s[i] == 'u') || ((char)s[i] == 'U')) {
            for (int k = i ; s[k] != '\0' ; k++) s[k] = s[k+1];
            i--;
        }
    }
}

void truncW (char t[], int n){
    int i, aux=n, k;

    for (i=0 ; t[i] != '\0' ; i++) {
        if (t[i] == ' ') aux=n;
        else if (aux == 0) {
            for (k=i ; t[k] != '\0' ; k++) {
                t[k] = t[k+1];
            }
            i--;
        }
        else aux--;
    }
}

char charMaisfreq (char s[]){
    if (length(s) == 0) return 0;
    else {
        int charList[255] = {0}, raux = 0, r, i;

        for (i = 0 ; s[i]!= 0 ; i++) charList[(int)(s[i])]++;

        for (i = 0 ; s[i]!=0 ; i++) if (charList[(int)(s[i])] > raux) {
            r=(int)(s[i]);
            raux=charList[(int)(s[i])];
        }
        
        return (char)(r);
    }
}

int maior2 (int a, int b) {
    return a>b?a:b;
}

int iguaisConsecutivos (char s[]) {
    int i, atual=0, maior=0; char ultimo=0;

    for (i=0 ; s[i]!=0 ; i++) {
        if (s[i]!=ultimo) {
            ultimo = s[i];
            atual = 1;
            maior = maior2(atual, maior);
        }
        else {
            atual++;
            maior = maior2(atual, maior);
        }
    }
    return maior;
}

void reset (char s[]) {
    int i;
    for (i=0 ; s[i]!=0 ; i++) s[i]='\0';
}

int elem(char a, char s[]) {
    int i,r=1;
    for (i=0 ; s[i]!=0 ; i++) if (s[i]==a) r=0;
    
    return r;
}
void adicionaAtras (char a, char s[],int N) {
    int i; char antes=s[0], atual;

    for (i=1 ; i<N ; i++) {
        atual = s[i];
        s[i] = antes;
        antes = atual;
    }
    s[0] = a;
}

int difConsecutivos (char s[]) {
    int i, atual=0, maior=0, len, j=0;
    len = length(s);
    char saux[len];
    reset(saux);

    for (i=0 ; s[i]!=0 ; i++) {
        if (elem(s[i], saux)==0) {
            reset(saux);
            j=0;
            saux[j] = s[i];
            j++;
            maior = maior2(atual, maior);
            atual = 1;
        }
        else {
            atual++;
            maior = maior2(atual, maior);
            saux[j] = s[i];
            j++;
        }
    }
    reset(saux);
    atual=0;
    for (i=len-1 ; i>=0 ; i--) {
        if (elem(s[i], saux)==0) {
            reset(saux);
            atual = 1;
            maior = maior2(atual, maior);
            adicionaAtras(s[i], saux,len);
        }
        else {
            atual++;
            maior = maior2(atual, maior);
            adicionaAtras(s[i], saux,len);
        }
    }
    return maior;
}

int main(){
    char a[] = "abccc";int b;
    b = difConsecutivos(a);
    printf("%d\n", b);
    return 0;
}

