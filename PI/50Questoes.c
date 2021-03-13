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

int main(){
    char a[] = "Puta Puta Puta";
    truncW(a,3);
    printf("%s\n", a);
    return 0;
}