long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int i, j, n = pointsSize, m = pointsColSize[0];
    long long *c, *dp1 = (long long*)malloc(sizeof(long long) * m),
    *dp2 = (long long*)malloc(sizeof(long long) * m),
    *dpl = (long long*)malloc(sizeof(long long) * m),
    *dpr = (long long*)malloc(sizeof(long long) * m);

    for(j = 0; j < m; j++)
        dp1[j] = points[0][j];

    for(i = 1; i < n; i++){
        dpl[0] = dp1[0];
        for(j = 1; j < m; j++)
            dpl[j] = dpl[j - 1] - 1 > dp1[j] ? dpl[j - 1] - 1 : dp1[j];
        
        dpr[m - 1] = dp1[m - 1];
        for(j = m - 2; j >= 0; j--)
            dpr[j] = dpr[j + 1] - 1 > dp1[j] ? dpr[j + 1] - 1 : dp1[j];

        for(j = 0; j < m; j++)
            dp2[j] = points[i][j] + (dpr[j] > dpl[j] ? dpr[j] : dpl[j]);

        c = dp1, dp1 = dp2, dp2 = c;
    }

    free(dp2); free(dpl); free(dpr);
    long long res = 0;
    for(i = 0; i < m; i++)
        if(dp1[i] > res) res = dp1[i];

    free(dp1);
    return res;
}