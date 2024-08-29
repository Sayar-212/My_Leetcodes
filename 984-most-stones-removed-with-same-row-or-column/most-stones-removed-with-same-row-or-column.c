
typedef struct {
    int *parent;
    int *rank;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    uf->parent = (int *)malloc(n * sizeof(int));
    uf->rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 1;
    }
    return uf;
}

int find(UnionFind *uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}

void unionSets(UnionFind *uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);

    if (rootX != rootY) {
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    UnionFind *uf = createUnionFind(stonesSize);

    int *rowMap = (int *)calloc(10001, sizeof(int));
    int *colMap = (int *)calloc(10001, sizeof(int));

    for (int i = 0; i < stonesSize; i++) {
        int row = stones[i][0];
        int col = stones[i][1];

        if (rowMap[row] != 0) {
            unionSets(uf, i, rowMap[row] - 1);
        } else {
            rowMap[row] = i + 1;
        }

        if (colMap[col] != 0) {
            unionSets(uf, i, colMap[col] - 1);
        } else {
            colMap[col] = i + 1;
        }
    }

    int *uniqueComponents = (int *)calloc(stonesSize, sizeof(int));
    int componentsCount = 0;
    for (int i = 0; i < stonesSize; i++) {
        int root = find(uf, i);
        if (uniqueComponents[root] == 0) {
            uniqueComponents[root] = 1;
            componentsCount++;
        }
    }

    free(rowMap);
    free(colMap);
    free(uf->parent);
    free(uf->rank);
    free(uf);
    free(uniqueComponents);

    return stonesSize - componentsCount;
}