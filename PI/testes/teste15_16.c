#include <stdio.h>
#include <stdlib.h>

typedef struct listaC 
{
    int coluna;
    float valor;
    struct listaC *prox;
} *Colunas;

typedef struct listaL 
{
    int linha;
    Colunas lcol;
    struct listaL *prox;
} *Mat;

Mat make_mat (int m, int n, float array[m][n])
{
      int i, j;
      Mat r, ant=NULL;
      Colunas antcol = NULL;
      for (i=m ; i>0 ; i--)
      {
             Mat linha = malloc(sizeof(struct listaL)) ;
             linha->linha = i-1;
             for (j=n; j>0;j--)
             {
                    Colunas col = malloc(sizeof (struct listaC));
                    col->coluna = j-1;
                    col->valor = array[i-1][j-1];
                    col->prox = antcol;
                    antcol = col;
                    if(j-1==0) linha->lcol = col;
             }
             antcol = NULL;
             linha->prox = ant;
             ant = linha;
             if (i-1==0) r=linha;
    }
    return r;
}

void print_mat (Mat m)
{
  Mat matriz = m;
  while (matriz != NULL)
  {
    Colunas col = matriz->lcol;
    while (col!=NULL)
    {
      printf("%f ", col->valor);
      col = col->prox;
    }
    printf("\n");
    matriz = matriz->prox;
  }
}


float getEntry (Mat m, int linha, int coluna)
{
    if (m == NULL)
        return 0;

    while (m!=NULL && m->linha != linha)
        m = m->prox;

    while (m!=NULL && m->lcol!=NULL && m->lcol->coluna != coluna)
        m->lcol = m->lcol->prox;

    if (m==NULL || m->lcol==NULL)
        return 0;

    return m->lcol->valor;
}

Mat Make_linha(int linha)
{
    Mat mat = malloc(sizeof(struct listaL));
    mat->linha = linha;
    mat->prox = NULL;
    mat->lcol = NULL;
    return mat;
}

Colunas Make_col(int coluna, float valor)
{
    Colunas col = malloc(sizeof(struct listaC));
    col->coluna = coluna;
    col->valor = valor;
    col->prox = NULL;
    return col;
}

void setEntry (Mat *m, int linha, int coluna, float valor)
{
    Mat mat = *m, iniciol = *m,  lant = NULL;
    while (mat!=NULL && mat->linha != linha)
    {
        lant = mat;
        mat = mat->prox;
    }
    
    if (mat==NULL)
    {
        Mat mat2 = Make_linha(linha);
        Colunas col = Make_col(coluna, valor);
        mat2->lcol = col;
        if (lant != NULL)
        {
            lant->prox = mat2;
            m = &iniciol;
        }
        else
            *m = mat2;
    }
    else
    {
        Colunas inicio, atual, ant = NULL;
        inicio = atual = mat->lcol;
        while (atual != NULL && atual->coluna != coluna)
        {
            ant = atual;
            atual = atual ->prox;
        }
        if (atual == NULL)
            atual = Make_col(coluna, valor);
        atual->valor = valor;
        if (ant != NULL)
            ant->prox = atual;
        mat->lcol = inicio;
    }
}

void addTo (Mat *m1, Mat m2)
{
    Mat mat = *m1;
    while (mat != NULL && m2 != NULL)
    {
        Colunas inicio, lcolaux;
        inicio = lcolaux = mat->lcol;
        while (lcolaux!=NULL && m2->lcol!=NULL)
        {
            lcolaux->valor += m2->lcol->valor;
            lcolaux = lcolaux->prox;
            m2->lcol = m2->lcol->prox;
        }
        mat->lcol = inicio;
        mat = mat->prox;
        m2 = m2->prox;
    }
}

void transpose (Mat *m)
{
    Mat transposed = NULL;
    Mat mat = *m;
    for ( ; mat != NULL ; mat = mat->prox)
    {
        for ( ; mat->lcol != NULL ; mat->lcol = mat->lcol->prox)
            setEntry(&transposed, mat->lcol->coluna, mat->linha, mat->lcol->valor);
    }
    free(mat);
    *m = transposed;
}

int main ()
{
    float array[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    Mat m;
    m = make_mat(3,3,array);
    transpose(&m);
    print_mat(m);  
}