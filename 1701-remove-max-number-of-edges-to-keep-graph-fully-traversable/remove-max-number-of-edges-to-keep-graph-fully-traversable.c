#define MAX_EDGES 100000
typedef struct {
    int type, u, v;
} Edge;
typedef struct {
    int parent, rank;
} UnionFind;
UnionFind* createUnionFind(int n) {
    UnionFind* uf = (UnionFind*)malloc(n * sizeof(UnionFind));
    for (int i = 0; i < n; i++) {
        uf[i].parent = i;
        uf[i].rank = 0;
    }
    return uf;
}
int find(UnionFind* uf, int x) {
    if (uf[x].parent != x) {
        uf[x].parent = find(uf, uf[x].parent);
    }
    return uf[x].parent;
}
int unionSets(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX != rootY) {
        if (uf[rootX].rank > uf[rootY].rank) {
            uf[rootY].parent = rootX;
        } else if (uf[rootX].rank < uf[rootY].rank) {
            uf[rootX].parent = rootY;
        } else {
            uf[rootY].parent = rootX;
            uf[rootX].rank++;
        }
        return 1;
    }
    return 0;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    int removableEdges = 0;
    UnionFind* aliceUF = createUnionFind(n);
    UnionFind* bobUF = createUnionFind(n);
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 3) {
            if (!unionSets(aliceUF, edges[i][1] - 1, edges[i][2] - 1)) {
                removableEdges++;
            } else {
                unionSets(bobUF, edges[i][1] - 1, edges[i][2] - 1);
            }
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 1) {
            if (!unionSets(aliceUF, edges[i][1] - 1, edges[i][2] - 1)) {
                removableEdges++;
            }
        } else if (edges[i][0] == 2) {
            if (!unionSets(bobUF, edges[i][1] - 1, edges[i][2] - 1)) {
                removableEdges++;
            }
        }
    }
    int aliceComponents = 0, bobComponents = 0;
    for (int i = 0; i < n; i++) {
        if (find(aliceUF, i) == i)
            aliceComponents++;
        if (find(bobUF, i) == i)
            bobComponents++;
    }
    free(aliceUF);
    free(bobUF);
    if (aliceComponents > 1 || bobComponents > 1) {
        return -1;
    }
    return removableEdges;
}