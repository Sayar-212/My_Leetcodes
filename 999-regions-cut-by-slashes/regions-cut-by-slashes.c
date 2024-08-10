void incarcare(int **grid,int x,int y,int n){
    if(x<0 || x>=3*n || y<0 ||y>=3*n||grid[x][y]!=0)return;
    grid[x][y]=-1;
    incarcare(grid,x+1,y,n);
    incarcare(grid,x-1,y,n);
    incarcare(grid,x,y+1,n);
    incarcare(grid,x,y-1,n);
}
int regionsBySlashes(char** grid, int gridSize) {
    int expandatSize=3*gridSize;
    int **expandat=(int **)malloc(expandatSize*sizeof(int*));
    for(int i=0;i<expandatSize;i++){
        expandat[i]=(int*)malloc(expandatSize*sizeof(int));
        memset(expandat[i],0,expandatSize*sizeof(int));
    }
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridSize;j++){
            if(grid[i][j]=='/'){
                expandat[3*i][3*j+2]=1;
                expandat[3*i+1][3*j+1]=1;
                expandat[3*i+2][3*j]=1;
            }
            else if(grid[i][j]=='\\'){
                expandat[3*i][3*j]=1;
                expandat[3*i+1][3*j+1]=1;
                expandat[3*i+2][3*j+2]=1;
            }
        }
    }
    int regions = 0;
    for (int i = 0; i < expandatSize; i++) {
        for (int j = 0; j < expandatSize; j++) {
            if (expandat[i][j] == 0) {
                incarcare(expandat, i, j, gridSize);
                regions++;
            }
        }
    }
    for (int i = 0; i < expandatSize; i++) {
    free(expandat[i]);
    }
    free(expandat);
    return regions;
}