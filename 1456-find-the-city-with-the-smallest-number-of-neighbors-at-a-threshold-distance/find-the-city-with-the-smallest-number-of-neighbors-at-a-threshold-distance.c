#define INF INT_MAX
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int distances[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                distances[i][j] = 0;
            } else {
                distances[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        distances[from][to] = weight;
        distances[to][from] = weight;  
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[i][k] != INF && distances[k][j] != INF && distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
    int minReachable = INF;
    int bestCity = -1;
    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && distances[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }
        if (reachableCount < minReachable || (reachableCount == minReachable && i > bestCity)) {
            minReachable = reachableCount;
            bestCity = i;
        }
    }
    return bestCity;
}