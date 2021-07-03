#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula 
{
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l)
{
    if (l->prox != NULL)
    {
        libertaLista(l->prox);
        free(l);
    }
}

int quantasP (Palavras l)
{
    int r=0;
    while (l !=NULL)
    {
        r++;
        l = l->prox;   
    }
    return r;
}

void listaPal (Palavras l)
{
    while (l!=NULL)
    {
        printf("%s -> %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

char * ultima (Palavras l)
{
    char *r = NULL;
    if (l!=NULL)
    {
        while (l->prox != NULL)
            l = l->prox;

        r = l->palavra;
    }

    return r;
}

Palavras acrescentaInicio (Palavras l, char *p)
{
    Palavras l1 = malloc(sizeof(struct celula));
    l1->palavra = p;
    l1->ocorr = 1;
    l1->prox = l; 
    return l1;
}

Palavras acrescentaFim (Palavras l, char *p)
{
    if (l!=NULL)
    {    
        Palavras l1, nova = malloc(sizeof(struct celula));
        nova->palavra = p;
        nova->ocorr = 1;
        nova->prox = NULL;
        l1 = l;
        while (l1->prox != NULL)
        {
            l1 = l1->prox;
        }
        l1->prox = nova;
    }
    else
    {
        Palavras nova = malloc(sizeof(struct celula));
        nova->palavra = p;
        nova->ocorr = 1;
        nova->prox = NULL;
        l = nova;
    }
    return l;
}

// Verificar se a palavra p existe em l
Palavras encontra (Palavras l, char *p)
{
    Palavras r = NULL;
    if (l != NULL)
    {
        r = l;
        while (strcmp(r->palavra, p) != 0 && r != NULL) // Percorrer a lista enquanto a palavra for diferente e l nao for NULL
        {
            r = r->prox;
        }
    }
    return r;
}

Palavras acrescenta (Palavras l, char *p)
{
    Palavras r = l, l1;
    if (l!=NULL)
    {
        l1 = encontra(l, p);
        if (l1 != NULL) // A palavra existe em l, logo aumentamos o número de ocorrências
                l1->ocorr++;
        else            // A palavra não existe em l, logo adicionamos ao início
            r = acrescentaInicio(l, p);
    }
    else
        r = acrescentaInicio(l, p);
    return r;
}

Palavras encontraAlfabeticamente (Palavras l, char *p)
{
    Palavras r = l;
    if (l != NULL)
    {
        if (strcmp(r->palavra, p) == -1)
        {
            while (r != NULL && strcmp(r->prox->palavra, p) == -1) // Percorrer a lista enquanto a palavra for menor e l nao for NULL
            {
                printf("%s\n", r->palavra);
                r = r->prox;
            }
        }
    }
    return r;
}


Palavras acrescentaAlfabeticamente (Palavras l, char *p)
{
    Palavras r = l, l1;
    if (l!=NULL)
    {
        l1 = encontraAlfabeticamente(l, p);
        if (l1 != NULL) // Existe pelo menos um elemento maior ou igual a p
                {
                    if (strcmp(l1->palavra, p) == 0)  // Existe um elemento igual, pelo que se incrementa às ocorrências
                        l1->ocorr++; 
                    else                              // Não há nenhum igual, apenas maiores, pelo que se adiciona antes
                    {
                        Palavras Nova = malloc(sizeof(struct celula));
                        Nova->palavra = p;
                        Nova->ocorr = 1;
                        Nova->prox = l1->prox;
                        l1->prox = Nova;
                    }
                }
        else // Todos os elementos sao menores que p, pelo que se acrescenta no fim
            r = acrescentaFim(l, p);
    }
    else
        r = acrescentaInicio(l, p);
    return r;
}

int main ()
{
    Palavras l = NULL;
    l = acrescentaInicio(l , "zebra");
    l = acrescentaInicio(l , "xilofone");
    l = acrescentaInicio(l , "mamaco");
    l = acrescentaInicio(l , "bruna");
    l = acrescentaInicio(l , "andre");
    l = acrescentaAlfabeticamente(l, "roberto");
    listaPal(l);
}