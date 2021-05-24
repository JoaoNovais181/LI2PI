#include <stdlib.h>
#include <stdio.h>

typedef struct lligada 
{
    int valor;
    struct lligada *prox;
} *LInt;

int length (LInt l)
{
    int r = 0;

    for ( ; l != NULL ; l = l->prox)
        r++;

    return r;
}

void freeL (LInt l)
{
    LInt aux;
    for ( ; l->prox != NULL ; l = aux)
    {
        aux = l->prox;
        free(l);
    }
}

void imprimeL (LInt l)
{
    for ( ; l != NULL ; l = l->prox)
        printf("%d ", l->valor);

    printf("\n");
}

LInt reverseL (LInt l)
{
    LInt aux = NULL, aux1;
    
    while (l != NULL)
    {
        aux1 = l->prox;
        l->prox = aux;
        aux = l;
        l = aux1;
    }
    l = aux;

    return l;
}

LInt newLInt (int v, LInt t)
{
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void insertOrd (LInt *l , int x)
{
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    LInt temp = *l;
    if (temp == NULL || temp->valor >= x)
    {
        *l = new;
        new->prox = temp;
    }
    else
    {
        for ( ; temp->prox != NULL && temp->prox->valor < x ; temp = temp->prox);
        LInt temp2 = temp->prox;
        temp->prox = new;
        new->prox = temp2;
    }
}

int removeOneOrd (LInt *l, int x)
{
    LInt temp, temp2;
    temp = temp2 = *l;
    if (*l == NULL)
    return 1;

    if (temp->valor == x)
    {
        *l = temp->prox;
       return 0;
    }
    
    while(temp != NULL && temp->valor < x)
    {
        temp2 = temp;
        temp = temp->prox;
    }
    
    if (temp != NULL && temp->valor == x)
    {
        temp2->prox = temp->prox;
        return 0;
    }
    return 1;
}

void merge (LInt *r, LInt a, LInt b)
{
    if (a==NULL || b == NULL)
        (a==NULL) ?((b==NULL) ?(*r = NULL) :(*r = b)) :(*r = a);
    else 
    {
        LInt last = NULL;
        while (a!=NULL && b!=NULL)
        {
            LInt node = malloc(sizeof(struct lligada));
            if (a->valor <= b->valor)
            {
                node->valor = a->valor;
                a = a->prox;
            }
            else
            {
                node->valor = b->valor;
                b = b->prox;
            }
            (last == NULL) ?(*r = node) :(last->prox = node);
            last = node;
        }
        (a==NULL) ?(last->prox = b) :(last->prox = a);
    }
}

void addEsq (LInt *l, int x)
{
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(*l != NULL)
    {
        LInt temp = *l;
        while (temp->prox != NULL)
            (temp) = (temp)->prox;
        (temp)->prox = new;
    }
    else 
        *l = new;
}
void splitQS (LInt l, int x, LInt *mx, LInt *Mx)
{
    if (l != NULL)
    {
        while (l!=NULL)
        {
            (l->valor < x) ?(addEsq(mx, l->valor)) :(addEsq(Mx, l->valor));
            l = l->prox;
        }
    }
    else
        *mx = *Mx = NULL;
}

LInt copia(LInt *l)
{
    LInt nova = malloc(sizeof(struct lligada));
    nova->valor = (*l)->valor;
    *l = (*l)->prox;
    return nova;
}

LInt parteAmeio (LInt *l)
{
    if (*l == NULL)
        return NULL;
    int len = length(*l), nr = len/2;
    LInt aux = NULL, r;
    while(nr>0)
    {
        LInt nova1 = copia(l);
        (aux == NULL) ?(r=nova1) :(aux->prox=nova1);
        aux = nova1;
        nr--;
    }
    return r;
}

int removeAll (LInt *l, int x){
    if (*l == NULL)
        return 0;
    int r=0;
    LInt ant = NULL, atual=*l;
    while (atual != NULL)
    {
        if (atual->valor == x)
        {
            r++;
            if (ant != NULL)
            {
                ant->prox = atual->prox;
                atual = atual->prox;
                continue;
            }
            *l = (*l)->prox;
            atual = atual->prox;
            continue;
        }
        ant = atual;
        atual = atual->prox;
    }
    return r;
}

int removeDups (LInt *l){
    int r = 0;
    LInt atual = *l;
    while (atual != NULL)
    {
        r += removeAll(&(atual->prox), atual->valor);
        atual = atual->prox;
    }
    return r;
}

int removeMaiorL (LInt *l)
{
    LInt ant = NULL, antmaior = NULL, maiorl = *l, aux = *l;
    int maior = aux->valor;
    while(aux!=NULL)
    {
        if (aux->valor > maior)
        {
            maior = aux->valor;
            maiorl = aux;
            antmaior = ant; 
        }
        ant = aux;
        aux = aux->prox;
    }
    (antmaior!=NULL) ?(antmaior->prox = maiorl->prox) :((*l) = (*l)->prox);
    free(maiorl);
    return maior;
}

void init (LInt *l){
    LInt ant = NULL, aux = *l;
    while (aux->prox != NULL)
    {
        ant = aux;
        aux = aux->prox;
    }
    (ant!=NULL) ?(ant->prox = NULL) :((*l)=NULL);
    free(aux);
}

void appendL (LInt *l, int x){
    LInt novo = malloc(sizeof(struct lligada)), aux = *l;
    novo->valor = x;
    novo->prox = NULL;
    while((*l)!=NULL)
        l = &((*l)->prox);
    *l = novo;
    
}

void concatL (LInt *a, LInt b){
    while ((*a)!=NULL)
        a = &(*a)->prox;
    *a = b;
}

LInt cloneL (LInt l)
{
    LInt r = NULL, *rp = &r;
    while (l!=NULL)
    {
        *rp = malloc(sizeof(struct lligada));
        (*rp)->valor = l->valor;
        (*rp)->prox = NULL;
        rp = &(*rp)->prox;
        l = l->prox;
    }
    return r;
}

LInt cloneRev (LInt l)
{
    LInt r = NULL, atual = NULL;
    while (l != NULL)
    {
        atual = malloc(sizeof(struct lligada));
        atual->valor = l->valor;
        atual->prox = r;
        r = atual;
        atual = NULL;
        l = l->prox;
    }
    return r;
}

int maximo (LInt l)
{
    int maior = l->valor;
    for (l=l->prox ; l!=NULL ; l=l->prox)
        maior = (l->valor > maior) ?l->valor :maior;

    return maior;
}

int main ()
{
    LInt l, l2 = NULL, r = NULL;

    l = newLInt(-1, newLInt(1,newLInt(2, newLInt(3, newLInt(4, NULL)))));

    l2 = cloneRev(l);
    imprimeL(l2);
}