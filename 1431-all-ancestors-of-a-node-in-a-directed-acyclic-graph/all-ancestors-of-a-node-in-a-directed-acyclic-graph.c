void dfs(int x, int curr, int** ans, int* ansColSize, int** directChild, int* directChildColSize) {
    for (int i = 0; i < directChildColSize[curr]; i++) {
        int ch = directChild[curr][i];
        if (ansColSize[ch] == 0 || ans[ch][ansColSize[ch] - 1] != x) {
            ans[ch][ansColSize[ch]++] = x;
            dfs(x, ch, ans, ansColSize, directChild, directChildColSize);
        }
    }
}

int** getAncestors(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes) {
    // Initialize result array
    int** ans = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = 0;
    }

    // Initialize graph adjacency list
    int** directChild = (int**)malloc(n * sizeof(int*));
    int* directChildColSize = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        directChild[i] = (int*)malloc(n * sizeof(int));
        directChildColSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        directChild[u][directChildColSize[u]++] = v;
    }

    // Perform DFS for each node
    for (int i = 0; i < n; i++) {
        dfs(i, i, ans, *returnColumnSizes, directChild, directChildColSize);
    }

    // Cleanup and return
    for (int i = 0; i < n; i++) {
        free(directChild[i]);
    }
    free(directChild);
    free(directChildColSize);

    *returnSize = n;
    return ans;
}