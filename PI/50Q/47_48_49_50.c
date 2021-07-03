#include <math.h>

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao 
{
    int x, y;
} Posicao;

// dadas as posições inicial e final do robot, preenche o array mov com os movimentos 
// suficientes para que o robot passe de uma posição para a outra.
// A função deverá preencher no máximo N elementos do array e
// retornar o nú́mero de elementos preenchidos.
// Se não for possível atingir a posição final com N movimentos, 
// a função deverá retornar um nú́mero negativo.
int cmp (int *a, int *b)
{
    int r=0;
    if (*a<*b) 
    {
        r = -1;
        (*a)++;
    }
    else if (*a>*b)
    {
        r=1;
        (*a)--;
    }
    return r;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N)
{
    int i = 0;
    while (i<=N && (inicial.x != final.x || inicial.y != final.y))
    {
        switch (cmp(&inicial.x, &final.x))
        {
            case 1:
                mov[i] = Oeste;
                break;
            case -1:
                mov[i] = Este;
                break;
            default:
                switch (cmp(&inicial.y, &final.y))
                {
                    case 1:
                        mov[i] = Sul;
                        break;
                    case -1:
                        mov[i] = Norte;
                        break;
                }
        }
        i++;
    }
    return (i<=N) ?i : -1;
}

Posicao posFinal (Posicao inicial, Movimento mov[], int N)
{
    for (N-- ; N>=0 ; N--)
        switch (mov[N])
        {
            case Norte:
                inicial.y++;
                break;
            case Sul:
                inicial.y--;
                break;
            case Este:
                inicial.x++;
                break;
            case Oeste:
                inicial.x--;
                break;
        }

    return inicial;
}

float dist (Posicao p)
{
    return sqrt(p.x*p.x+p.y*p.y);
}

int maisCentral (Posicao pos[], int N)
{
    int r=0;

    for (N-- ; N>0 ; N--)
        if (dist(pos[N]) < dist(pos[r])) r=N;

    return r;
}

int vizinhos (Posicao p, Posicao pos[], int N)
{
    int r=0;
    for (N-- ; N>=0 ; N--)
        if (sqrt(pow(p.x-pos[N].x,2) + pow(p.y-pos[N].y,2)) == 1) r++;

    return r;
}