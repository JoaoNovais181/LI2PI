#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Exercicio 1
int contaVogais (char *s) {
    int i, r=0;
    for (i=0 ; s[i]!=0 ; i++) if ((s[i]=='a') || (s[i]=='A') || (s[i]=='e') || (s[i]=='E') || (s[i]=='i') || (s[i]=='I') || (s[i]=='o') || (s[i]=='O') || (s[i]=='u') || (s[i]=='U')) r++;
    return r;
}
//Exercicio 2 - str auxiliar
void copiaStr (char *s1, char *s2) {
    int i;

    for (i=0 ; s1[i]!=0 ; i++) s2[i]=s1[i];
    for ( ; s2[i]!=0 ; i++) s2[i]=0;
}
int retiraVogaisRep1 (char *s) {
    int i, j=0, r=0; char saux[100] = {0}, ultimo=0;

    for (i=0 ; s[i]!= 0 ; i++) {
        if ((s[i]=='a') || (s[i]=='A') || (s[i]=='e') || (s[i]=='E') || (s[i]=='i') || (s[i]=='I') || (s[i]=='o') || (s[i]=='O') || (s[i]=='u') || (s[i]=='U')) {
            if (s[i]!=ultimo) {
                saux[j] = s[i];
                ultimo = saux[j];
                j++;
            }
            else r++;
        }
        else {
            saux[j] = s[i];
            ultimo = 0;
            j++;
        }
    }
    copiaStr(saux, s);
    return r;
}
//Exercicio 2 - s/ str auxiliar
int retiraVogaisRep (char *s) {
    int i, r=0; char ultimo=0;

    for (i=0 ; s[i]!= 0 ; i++) {
        if ((s[i]=='a') || (s[i]=='A') || (s[i]=='e') || (s[i]=='E') || (s[i]=='i') || (s[i]=='I') || (s[i]=='o') || (s[i]=='O') || (s[i]=='u') || (s[i]=='U')) {
            if (s[i]!=ultimo) { //Diferente do anterior
                s[i-r] = s[i]; // Trago o char s[i] r posicoes para tras (sendo r o numero de vogais retiradas)
                ultimo = s[i-r]; // Como s[i] e vogal, interessa saber que ele foi o ultimo char
            }
            else { //Igual ao anterior
                r++;
            }
        }
        else { // Caso seja consoante
            s[i-r]=s[i];
            ultimo = 0; // Nao interessa qual e o anterior, por isso ponho como Nulo
        }
    }
    for (i-=r ; s[i]!=0 ; i++) s[i]=0; // Como tirei r vogais, dei shift a string r posicoes para tras, por isso agora tiro essas r posicoes
    return r;
}
// Exercicio 3 - str auxiliar 
int duplicaVogais1 (char *s) {
    int i, j=0, r=0; char saux[100] = {0};

    for (i=0 ; s[i]!=0 ; i++) {
        if ((s[i]=='a') || (s[i]=='A') || (s[i]=='e') || (s[i]=='E') || (s[i]=='i') || (s[i]=='I') || (s[i]=='o') || (s[i]=='O') || (s[i]=='u') || (s[i]=='U')) {
            saux[j] = s[i];
            j++;
            saux[j] = s[i];
            j++;
            r++;
        }
        else {
            saux[j] = s[i];
            j++;
        }
    }
    copiaStr(saux, s);
    return r;
}
// Exercicio 3 - s/ str auxiliar

//Versao Senhor Engenheiro Deadlock
int isVogal (char a) {
    if ((a=='a') || (a=='A') || (a=='e') || (a=='E') || (a=='i') || (a=='I') || (a=='o') || (a=='O') || (a=='u') || (a=='U')) return 1;
    else return 0;
}
int duplicaVogaisSrEng(char* s){
    
    int n = strlen(s);      //Número de elementos base da string argumento
    int v = contaVogais(s); //Número de elementos que vão ser adicionados à string
    
    s = realloc(s,n+v);     //Copiamos o conteúdo de s para um bloco de memória com espaço
                            //para aguentar as inserções que vão ser feitas
    s[n+v] = '\0';          //Marca o final da nova string
    
    for(n = n-1; n >= 0; n--){  //Preenche a nova string do fim para o início
        if(isVogal(s[n])){      //Se o char for uma vogal
            s[n+v] = s[n];      // coloca o duplicado na última posição que ainda não foi preenchida
            v--;                //Diminui o número de vogais que faltam ser duplicadas
            s[n+v] = s[n];      //  coloca o original na última posição que ainda não foi preenchida
        } else {
            s[n+v] = s[n];      //Se não for vogal preenchemos simplesmente a ultima posição não preenchida
        }
    }
    return (contaVogais(s)/2);
}

// Versao Aula
void shiftRight (char v[]) {
    int i, l=strlen(v); char last=v[0], atual;

    for (i=1 ; i<=l ; i++) {
        atual = v[i];
        v[i] = last;
        last = atual; 
    } 
}
int duplicaVogais (char *s) {
    int i, r=0;
    for (i=0 ; s[i]!=0 ; i++) {
        if (isVogal(s[i])) {
            shiftRight(s+i);
            i++;
            r++;
        }
    }
    return r;
}

//PARTE DOIS

//Exercicio 1
int ordenado (int v[], int N) {
    int i, r=1;

    for (i=0 ; i<N-1 ; i++) {
        if (v[i]>v[i+1]) r=0; 
    }

    return r;
}

void merge (int a[], int na, int b[], int nb, int r[]) {
    int i, ia=0, ib=0;
//    na--, nb--;
    for (i=0 ; i<na+nb ; i++) {
        if (a[ia] <= b[ib]) {
            r[i] = a[ia];
            ia++;
        }
        else {
            r[i] = b[ib];
            ib++;
        }
    }
}

int partition (int v[], int N, int x) {}

int main () {
    int b[] = {1,3,5,7,9}, a[] = {2,4,6,8,10}, c[10];
    merge(a,5,b,5,c);
    for (int i = 0 ; i<10 ; i++) printf("%d ", c[i]);
    return 0;
}