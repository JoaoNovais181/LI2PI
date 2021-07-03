int comuns (int a[], int na, int b[], int nb)
{
    int r=0, i, j;

    for (i=0 ; i<na ; i++)
        for (j=0 ; j<nb ; j++)
            if (a[i] == b[j])
            {
                r++;
                j = nb;
            }

    return r;
}