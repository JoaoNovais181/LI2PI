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

int maiorPrefixo (char s1 [], char s2 []) {
    int i,r=0;

    for (i=0 ; (s1[i]!=0)&&(s2[i]!=0) ; i++) {
        if (s1[i]!=s2[i]) return r;
        else r++;
    }
    return r;
}

//Melhorar
int len (char s[]) {
    int i=0;
    while (s[i]!=0) i++;
    return i-1;    
}
int maiorSufixo (char s1 [], char s2 []) {
    int l1, l2,r=0;
    l1 = len(s1); l2 = len(s2);
    while ((l1>=0) && (l2>=0)) {
        if (s1[l1]!=s2[l2]) return r;
        else r++;
        l1--;
        l2--;
    }
    return r;
}

int sufPref (char s1[], char s2[]) {
    int inicio, i, r=0, atual;

    for (inicio=0 ; s1[inicio]!=0 ; inicio++) {
        atual = 0;
        for (i=0 ; (s1+inicio)[i]!=0 ; i++) {
            if ((s1+inicio)[i] != s2[i]) atual = 0;
            else atual++;
        }
        if (atual>r) r=atual;
    }
    return r;
}

int contaPal (char s[]) {
    int i, r=0;

    for (i=0 ; s[i]!=0 ; i++)
        if (((s[i-1]==' ') || (s[i-1]==0)) && ((s[i]!=' ') && (s[i]!='\n'))) r++;

    return r;
}

int isVowel (char a) {
    char str[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'}; int i;

    for (i=0 ; i<10 ; i++) if (a == str[i]) return 1;

    return 0;
}

int contaVogais (char s[])  {
    int i, r=0;

    for (i=0 ; s[i]!=0 ; i++) if (isVowel(s[i]) == 1) r++;

    return r; 
}

int estaEm (char a, char s[]) {
    int i;

    for (i=0 ; s[i]!=0 ; i++) if (s[i] == a) return 1;

    return 0;
}

int contida (char a[], char b[]) {
    int i;

    for (i=0 ; a[i]!=0 ; i++) if (estaEm(a[i], b) == 0) return 0;

    return 1;
}

int palindorome (char s[]) {
    int i, l = len(s);

    for (i=0 ; i<(l/2)+1 ; i++) if (s[i]!=s[l-i]) return 0;

    return 1;
}

int remRep (char x[]) {
    if (x[0]==0) return 0;
    else {
        int i, c , r=1; char ultimo = x[0];
        for (i=1 ; x[i]!=0 ; i++) {
            if (x[i]==ultimo) {
                for (c=i ; x[c]!=0 ; c++) x[c]=x[c+1]; 
                i--;
            }
            else r++;
            ultimo = x[i];
        }
        return r;
    }
}

int limpaEspacos (char t[]) {
    int i, c, r=0, aux=0;

    for (i=0 ; t[i]!=0 ; i++) {
        if (t[i]==' ') {
            if (aux >= 1) {
                for (c=i ; t[c]!=0 ; c++) t[c]=t[c+1]; 
                i--;
            }
            else r++;
            aux ++;
            
        }
        else {
            aux = 0;
            r++;
        }
    }
    return r;
}

void rightShift (int v[], int N, int x, int *i) {
    int atual, c , proximo;
    atual = v[*i];
    for (c=(*i)+1 ; c<N+1 ; c++) {
        proximo = v[c];
        v[c]=atual;
        atual = proximo;
    }
    v[*i]=x;
    (*i)++;
}

void insere (int v[], int N, int x) {
    int i;

    for (i=0 ; i<=N ; i++) {
        if ((i==0) && (x<v[i])) {
            rightShift(v,N,x,&i);
        }
         if ((x>=v[i]) && (x<v[i+1])) {
            i++;
            rightShift(v,N,x,&(i));
         }
    }
}

// Merge

int menor (int a, int b, int* ia, int* ib)
{
    if (a<=b)
        (*ia)++;
    else
        (*ib)++;
    return a<=b ? a: b;
}

void merge (int r [], int a[], int b[], int na, int nb)
{
    int i, ia=0, ib=0;

    for (i=0 ; i<na+nb ; i++)
    {   
        if (ia>=na) 
        {
            r[i] = b[ib];
            ib++;
        }
        else if (ib>=nb) 
        {
            r[i] = a[ia];
            ia++;
        }
        else 
            r[i] = menor(a[ia], b[ib], &ia, &ib);
    }   
}

// Crescente

int crescente (int a[], int i, int j)
{
    int r=1;
    for ( ; i<j ; i++)
        if (a[i]>a[i+1]) r=0;

    return r;
}

// Retira Neg

int retiraNeg (int a[], int N)
{
    int i, retirados=0;

    for (i=0 ; i<N ; i++)
    {
        if (a[i]<0) retirados++;
        else a[i-retirados] = a[i];
    }
    return N-retirados;
}

// Menos Freq
void resetVal (int *Atual, int i, int *anterior, int valor, int *contador)
{
    *Atual = i;
    *anterior = valor;
    *contador = 1;
}

int menosFreq (int v[], int N)
{
    int i, iAtual, iMenosFrequente, contador=0, anterior, contadorMenosFreq;

    for (i=0 ; i<N ; i++)
    {
        if (i==0)
        {
            iAtual = 0;
            iMenosFrequente = 0;
            contador++;
            anterior = v[0];
        }
        else 
        {
            if (v[i]==anterior) contador++;
            else
            {
                if (iAtual == 0)
                {
                    contadorMenosFreq = contador;
                    resetVal(&iAtual, i, &anterior, v[i], &contador);
                }
                else if (contador < contadorMenosFreq) 
                {
                    contadorMenosFreq = contador;
                    iMenosFrequente = iAtual;
                    resetVal(&iAtual, i, &anterior, v[i], &contador);
                }
                else
                {
                    resetVal(&iAtual, i, &anterior, v[i], &contador);
                }
            }
        }
    }

    if (contador < contadorMenosFreq) 
    {
        contadorMenosFreq = contador;
        iMenosFrequente = iAtual;
    }

    return v[iMenosFrequente];
}



int main(){
    int a[] = { 2  ,2  ,2  ,3 , 3,  3,  4,  4,  5,  5,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6 };
    printf("%d\n", menosFreq(a, 20));
    return 0;
}

