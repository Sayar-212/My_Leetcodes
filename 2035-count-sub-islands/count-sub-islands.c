bool scanIsland(int** grid1, int** grid2, short row, short col, short n, short m){
    grid2[row][col] = 2;
    bool subIsland = 1;

    if(row > 0 && grid2[row - 1][col] == 1)
        subIsland &= grid1[row - 1][col] ? scanIsland(grid1, grid2, row - 1, col, n, m) : 0;

    if(col > 0 && grid2[row][col - 1] == 1)
        subIsland &= grid1[row][col - 1] ? scanIsland(grid1, grid2, row, col - 1, n, m) : 0;

    if(row < n - 1 && grid2[row + 1][col] == 1)
        subIsland &= grid1[row + 1][col] ? scanIsland(grid1, grid2, row + 1, col, n, m) : 0;

    if(col < m - 1 && grid2[row][col + 1] == 1)
        subIsland &= grid1[row][col + 1] ? scanIsland(grid1, grid2, row, col + 1, n, m) : 0;

    return subIsland;
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    short i, j, n = grid1Size, m = grid1ColSize[0], res = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(grid1[i][j] && grid2[i][j] == 1)
                res += scanIsland(grid1, grid2, i, j, n, m);

    return res;
}