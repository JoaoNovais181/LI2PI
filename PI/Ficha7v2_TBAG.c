#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula 
{
  char *palavra;
  int ocorr;
  struct celula * prox;
} * Palavras;

Palavras novo (char *pal)
{
  Palavras l = malloc(sizeof(struct celula));
  l->ocorr = 1;
  l->palavra = strdup(pal);
  l->prox = NULL;
  return l;
}

void libertaLista (Palavras l)
{
  if (l == NULL) return;
  libertaLista(l->prox);
  free(l);
}

int quantasP (Palavras l)
{
  return (l==NULL) ?0 :(1+quantasP(l->prox));
}

void listaPal (Palavras l)
{
  for ( ; l!=NULL ; l = l->prox)
    printf("%s ocorre %d vezes\n", l->palavra, l->ocorr);
}

char * ultima (Palavras l)
{
  if (l==NULL)
    return NULL;
  
  char *ult;
  
  while (l->prox != NULL)
    l = l->prox;
    
  ult = strdup(l->palavra);
  
  return ult;
}

Palavras acrescentaInicio (Palavras l, char *p)
{
  Palavras inicio = novo(p);
  inicio->prox = l;
  return inicio;
}

Palavras acrescentaFim (Palavras l, char *p)
{
  Palavras fim = novo(p), *Plista = &l;
  while (*(Plista) != NULL)
    Plista = &((*Plista)->prox);
  *Plista = fim;
  return l;
}

int encontra (Palavras l, char *pal)
{
  for ( ; l!=NULL ; l=l->prox)
    if (!strcmp(l->palavra, pal)) return 1;
  
  return 0;
}

Palavras acrescenta (Palavras l, char *p)
{
  if (l==NULL)
  {
    Palavras nova = novo(p);
    return nova;
  }
  Palavras atual = l;

  if (encontra(l,p))  // Se a palavra p for encontrada na lista
  {
    while (strcmp(atual->palavra,p))  // Percorrer a lista até encontrar a palavra
      atual= atual->prox;
    
    atual->ocorr++;  //Aumentar as ocorrências
    return l;
  }  // Se chegar aqui é pq não e NULL a lista e a palavra que se quer acrescentar não ocorre  

  return acrescentaInicio(l,p);
}

Palavras acrescentaAlfabeticamente (Palavras l, char *p)
{
  if (l==NULL)
  {
    Palavras nova = novo(p);
    return nova;
  }
  Palavras atual = l;
  if (encontra(l,p))  // Se a palavra p for encontrada na lista
  {
    while (strcmp(atual->palavra,p))  // Percorrer a lista até encontrar a palavra
      atual= atual->prox;
    
    atual->ocorr++;  //Aumentar as ocorrências
    return l;
  }  // Se chegar aqui é pq não e NULL a lista e a palavra que se quer acrescentar não ocorre
  
  Palavras ant = NULL;  // Guardar o anterior (no inicio nao tem anterior)
  while (atual!=NULL && strcmp(p, atual->palavra)>0)  // Percorrer enquanto nao for NULL e enquanto a palavra atual for menor lexicograficamente que a que se quer adicionar
  {
    ant = atual;
    atual = ant->prox;
  }
  if (ant!=NULL)  // Se o ant for NULL e porque a palavra vai ser adicionada no inicio, ou seja, se n for null tem que ser adicionar no meio de ant e do atual
  {
    Palavras novaCel = novo(p);
    ant->prox = novaCel;
    novaCel->prox = atual;
    return l;
  }
  return acrescentaInicio(l,p); // Se for NULL acrescento no inicio
}


int main() {
  Palavras l;
  char *pal = "PUTA";
  l = novo(pal);
  pal = "VELHA";
  l = acrescentaFim(l,pal);
  pal = "ZZZZZe";
  l = acrescentaAlfabeticamente(l, pal);
  listaPal(l);
  libertaLista(l);
  return 0;
}