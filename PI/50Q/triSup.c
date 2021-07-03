int triSup (int N, float m [N][N])
{
    int i, j;

    for (i=0 ; i<N ; i++)
        for (j=i+1 ; j<N ; j++)
            if (m[i][i] == 0 || m[j][i] != 0) return 0;

    return 1;
}
