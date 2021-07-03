#include <stdio.h>

int cmp (int a, int b)
{
    int r=0;
    if (a<b) r = -1;
    else if (a>b) r = 1;
    return r;
}

int comunsOrd (int a[], int na, int b[], int nb)
{
    int ia, ib, r=0;
    for (ia = 0, ib = 0; ia < na && ib < nb; )
    {
        switch(cmp(a[ia], b[ib]))
        {
            case 0:
                ia++;
                ib++;
                r++;
                break;
            case 1:
                ib++;
                break;
            case -1:
                ia++;
                break;
        }
    }
    return r;
}

int main ()
{
    int c;
    c=comunsOrd(a, 15, b, 20);
    printf("c : %d\n", c);
}