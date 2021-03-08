#include <stdio.h>

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

char *strcpy (char *dest, char source[]){
    int i;

    for(i=0 ; source[i] != '\0' ; i++) dest[i]=source[i];

    dest[i] = '\0';

    return dest;
}

int strcmp (char s1[], char s2[]) {
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

int main(){
    char a[] = "aaaa"; char b[] = "aaaaa";
    printf("%d\n", strcmp(a,b));
    return 0;
}