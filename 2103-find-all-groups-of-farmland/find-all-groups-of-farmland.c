void dfs(int** land, int m, int n, int r, int c, int* top_left, int* bottom_right, int* count) {
    if (r < 0 || r >= m || c < 0 || c >= n || land[r][c] == 0) {
        return; 
    }
    (*count)++;
    land[r][c]=0; 
    if (r < top_left[0]) top_left[0] = r;
    if (c < top_left[1]) top_left[1] = c;
    if (r > bottom_right[0]) bottom_right[0] = r;
    if (c > bottom_right[1]) bottom_right[1] = c;
    dfs(land, m, n, r + 1, c, top_left, bottom_right, count);
    dfs(land, m, n, r - 1, c, top_left, bottom_right, count);
    dfs(land, m, n, r, c + 1, top_left, bottom_right, count);
    dfs(land, m, n, r, c - 1, top_left, bottom_right, count);
}
int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {
    int m = landSize, n = *landColSize;
    int** result = (int**)malloc(sizeof(int*) * m * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (m * n));
    *returnSize = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 1) {
                int top_left[2] = {i, j};
                int bottom_right[2] = {i, j};
                int count = 0;
                dfs(land, m, n, i, j, top_left, bottom_right, &count);
                int* group = (int*)malloc(sizeof(int) * 4);
                group[0] = top_left[0];
                group[1] = top_left[1];
                group[2] = bottom_right[0];
                group[3] = bottom_right[1];
                result[*returnSize] = group;
                (*returnColumnSizes)[*returnSize] = 4;
                (*returnSize)++;
            }
        }
    }
    return result;
}