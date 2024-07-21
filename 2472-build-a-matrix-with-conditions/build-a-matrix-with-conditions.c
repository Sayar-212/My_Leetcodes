/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int topologicalSort(int k, int** conditions, int conditionsSize, int* result) {
    int* indegree = (int*)calloc(k + 1, sizeof(int));
    int** adjList = (int**)malloc((k + 1) * sizeof(int*));
    int* adjCount = (int*)calloc(k + 1, sizeof(int));

    for (int i = 0; i <= k; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < conditionsSize; i++) {
        int u = conditions[i][0];
        int v = conditions[i][1];
        adjCount[u]++;
        adjList[u] = (int*)realloc(adjList[u], adjCount[u] * sizeof(int));
        adjList[u][adjCount[u] - 1] = v;
        indegree[v]++;
    }

    int* queue = (int*)malloc((k + 1) * sizeof(int));
    int front = 0, rear = 0;
    
    for (int i = 1; i <= k; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;
        
        for (int i = 0; i < adjCount[u]; i++) {
            int v = adjList[u][i];
            if (--indegree[v] == 0) {
                queue[rear++] = v;
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (adjList[i] != NULL) {
            free(adjList[i]);
        }
    }
    free(adjList);
    free(adjCount);
    free(indegree);
    free(queue);

    return (count == k) ? 1 : 0;
}

void printMatrix(int** matrix, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** buildMatrix(int k, int** rowConditions, int rowConditionsSize, int* rowConditionsColSize, int** colConditions, int colConditionsSize, int* colConditionsColSize, int* returnSize, int** returnColumnSizes) {
    int* rowOrder = (int*)malloc(k * sizeof(int));
    int* colOrder = (int*)malloc(k * sizeof(int));
    
    if (!topologicalSort(k, rowConditions, rowConditionsSize, rowOrder) || 
        !topologicalSort(k, colConditions, colConditionsSize, colOrder)) {
        free(rowOrder);
        free(colOrder);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int** matrix = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        matrix[i] = (int*)calloc(k, sizeof(int));
    }
    
    int* posRow = (int*)calloc(k + 1, sizeof(int));
    int* posCol = (int*)calloc(k + 1, sizeof(int));

    for (int i = 0; i < k; i++) {
        posRow[rowOrder[i]] = i;
        posCol[colOrder[i]] = i;
    }

    for (int i = 1; i <= k; i++) {
        matrix[posRow[i]][posCol[i]] = i;
    }

    free(rowOrder);
    free(colOrder);
    free(posRow);
    free(posCol);

    *returnSize = k;
    *returnColumnSizes = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = k;
    }
    
    return matrix;
}