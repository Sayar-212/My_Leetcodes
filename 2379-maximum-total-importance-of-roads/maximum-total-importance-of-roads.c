typedef struct{
    int node; 
    int roads;
}Help;
int cmp(const void* a, const void* b){
    Help c = *(Help*)a;
    Help d = *(Help*)b;
    return c.roads - d.roads;
}

long long maximumImportance(int n, int** roads, int roadsSize, int* roadsColSize){
    Help* help = calloc(n, sizeof(Help));
    int* importance = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        help[i].node = i;
        help[i].roads = 0;
    }
    for(int i = 0; i < roadsSize; i++){
        help[roads[i][0]].roads++;
        help[roads[i][1]].roads++;
    }
    qsort(help, n, sizeof(Help), cmp);
    int j;
    for(int i = 0; i < n; i++){
        importance[help[i].node] = i+1;
    }
    long long ans = 0;
    for(int i = 0; i < roadsSize; i++){
        ans += (importance[roads[i][0]] + importance[roads[i][1]]);
    }
    free(help);
    free(importance);
    return ans;
}