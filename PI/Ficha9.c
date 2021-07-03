#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
        m = rand() % N;
        a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;    
}

int max (int a, int b)
{
  return (a>b) ?a :b;
}

int altura (ABin a)
{
  if (a == NULL) return 0;
  return 1 + max(altura(a->esq),altura(a->dir));
}

int isFolha (ABin a)
{
  return (a->esq == NULL) && (a->dir == NULL);
}


int nFolhas (ABin a)
{
  // Se a for NULL da return a 0 senao da return ao resultado de isFolha(a) (1 se for folha, 0 caso contrario), mais o numero de folhas da esquerda mais o numero de folhas da direita
  return (a==NULL) ?0 :(isFolha(a) + nFolhas(a->esq) + nFolhas(a->dir)); 
}

ABin maisEsquerda (ABin a)
{
  if (a==NULL) return a;
  
  while (a->esq != NULL)
    a = a->esq;
  return a;
}

void imprimeNivel (ABin a, int l)
{
  if (a==NULL) return;
  if (l<0) return;  // Se o nivel for menor que 0 não se faz nada
  if (l == 0)  {printf("%d ", a->valor); return;} // Se o nivel for 0 estamos no nivel que se quer
  l--;  // Se não for o nivel que se quer, decrementamos o nivel e imprimimos a esquerda e a direita
  imprimeNivel(a->esq,l);
  imprimeNivel(a->dir,l);
}

int procuraE (ABin a, int x)
{
  if (a == NULL) return 0;
  return (a->valor == x) || procuraE(a->esq,x) || procuraE(a->dir,x);
}


struct nodo *procura (ABin a, int x)
{
    if (a == NULL) return a;
    while (a!=NULL && a->valor!=x)
        a = (a->valor > x) ?a->esq :a->dir;
    
    return a;
}

int nivel (ABin a, int x)
{
    if (!procura(a,x)) return -1;  // Se nao encontrar o elemento retorna -1
    if (a->valor == x) return 0;  // Se for o nivel atual retorna 0
    return 1 + nivel((a->valor>x) ?a->esq :a->dir, x);  // Se nao estiver no atual retorna 1 mais a chamada recursiva sobre o lado melhor
}

void imprimeAte (ABin a, int x)
{
    if (a==NULL) return;
    imprimeAte(a->esq, x); // Imprimir os da esquerda
    // So vale aq pena chamar a funçao para o ramo da direita se o valor for maior que o da raiz, porque se for menor, qualquer que esteja a direita será maior
    if (a->valor < x) // Se o valor for menor
    {
        printf("%d ", a->valor); // Imprimo o valor
        imprimeAte(a->dir, x); // Imprimo o que esta a direita
    }
}


int main() {
  int v1[15] = { 1, 3, 5, 7, 9,11,13,15,17,19,21,23,25,27,29};
  ABin a1;
  srand(time(NULL));
  a1 = RandArvFromArray (v1, 15);
  imprimeNivel(a1,0);
  //imprimeNivel(a1,1);
  //imprimeNivel(a1,2);
  return 0;
}