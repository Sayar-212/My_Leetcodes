long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    int i,j,k,minCost[123][123]={0};
    for(i=97;i<123;i++)
        for(j=97;j<123;j++)
            minCost[i][j]=i==j?0:(1<<25);
    for(i=0;i<costSize;i++)
        cost[i]<minCost[original[i]][changed[i]]?minCost[original[i]][changed[i]]=cost[i]:1;
    for(i=97;i<123;i++)
        for(j=97;j<123;j++)
            for(k=97;k<123;k++)
                minCost[j][k]=minCost[j][k]<minCost[j][i]+minCost[i][k]?minCost[j][k]:minCost[j][i]+minCost[i][k];
    long long totalCost=0;
    for(i=0;source[i];i++){
        if(source[i]!=target[i]){
            if(minCost[source[i]][target[i]]<(1<<25))
                totalCost+=minCost[source[i]][target[i]];
            else
                return -1;
        }
    }
    return totalCost;
}