void somasAc (int v[], int Ac [], int N)
{
    int i, j;

    for (i=0 ; i<N ; i++)
        for (j=0, Ac[i]=0 ; j<=i ; j++) Ac[i]+=v[j]; 
}
   