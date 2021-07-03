//  dado um vector v com n inteiros, retorna o índice do menor elemento do vector.
int minInd (int v[], int n)
{
    int r = 0, i;

    for (i=0 ; i<n ; i++)
        if (v[i] < v[r]) r=i;

    return r;
}