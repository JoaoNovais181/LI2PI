#include <stdio.h>
#include <stdlib.h>

typedef struct staticStack {
    int sp;
    int values [10];
} STACK, *SStack;

void SinitStack (SStack s)
{
    s->sp = 0;
}

int SisEmpty (SStack s)
{
    return (s->sp ==0) ?1 : 0;
}

int Spush (SStack s, int x)
{
    int c = ((s->sp) < (sizeof(s->values)/sizeof(int)));
    if (c==1)
    {
        s->values[s->sp] = x;
        s->sp++;
    }
    return (c==1) ?0 : 1; 
}

int Spop (SStack s, int *x)
{
    int c = SisEmpty(s);
    if (!c)
    {
        *x = s->values[(s->sp)-1];
        s->sp--;
    }
    return (!c) ?0 : 1;
}

int Stop (SStack s, int *x)
{
    int c = SisEmpty(s);
    if (!c)
    {
        *x = s->values[(s->sp)-1];
    }
    return (!c) ?0 : 1;
}

typedef struct staticQueue {
    int front;
    int length;
    int values [10];
} QUEUE, *SQueue;

void SinitQueue (SQueue q)
{
    q->length = 0;
    q->front = -1;
}

int SisEmptyQ (SQueue q)
{
    return (q->length == 0) ?1 : 0;
}

int Senqueue (SQueue q, int x)
{
    int c = ((q->length) < (sizeof(q->values)/sizeof(int)));
    if (c)
    {
        q->values[(q->length)-1] = x;
        q->length++;
    }
    return c ?0 : 1;
}

int Sdequeue (SQueue q, int *x)
{
    int i, c = SisEmptyQ(q);
    if (!c)
    {
        *x = q->front;
        for (i=0 ; i<q->length ; i++)
            q->values[i] = q->values[i+1];
        q->length--;
    }
    return (!c) ?0 : 1;
}

int Sfront (SQueue q, int *x)
{
    int i, c = SisEmptyQ(q);
    if (!c)
        *x = q->front;
    return (!c) ?0 : 1;
}

typedef struct dinStack {
    int size; 
    int sp;
    int *values;
} *DStack;

void DinitStack (DStack s)
{
    s->sp = 0;
    s->values = malloc(s->size * sizeof(int));
}

int  DisEmpty (DStack s)
{
    return (s->size == 0) ?1 : 0;
}

int  Dpush (DStack s, int x)
{
    if (s->sp < s->size)
    {
        s->values[s->sp] = x;
        s->sp++;
    }
    else
    {
        s->values = malloc(s->size * 2 * sizeof(int));
        s->values[s->sp] = x;
        s->sp++;   
    }
    return 0;
}

int  Dpop (DStack s, int *x)
{
    c = DisEmpty(s);
    if (!c)
    {
        *x = s->values[s->sp - 1];
        s->sp--;
        free(s->values[s->sp]);
    }
    return (!c) ?0 : 1;
}

int  Dtop (DStack s, int *x)
{
    c = DisEmpty(s);
    if (!c)
        *x = s->values[s->sp - 1];
    return (!c) ?0 : 1;
}

int main ()
{
    STACK s;
    SStack s2 = &s;
    int value;
    SinitStack(s2);
    printf("Pop 1 : %d\n", Spop(s2, &value));
    for (int i = 0; i<10 ; i++)
        s2->values[i] = i;
    s2->sp = 10;
    printf("Pop 2 : %d\n", Spop(s2, &value));
    printf("Push : %d\n", Spush(s2, 10));
}