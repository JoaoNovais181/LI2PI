int min (int a, int b)
{
    return (a>b) ?b : a;
}

int intersectMSet (int N, int v1[N], int v2[N],int r[N])
{
    int i;

    for (i=0 ; i<N ; i++)
        r[i] = min(v1[i],v2[i])*(v1[i] && v2[i]);

    return 0;
}