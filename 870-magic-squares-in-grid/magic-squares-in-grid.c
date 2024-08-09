int checkOneToNine(int** arr, int ii, int jj) {
    int cnt[10] = {0};
    for (int i = ii; i < ii + 3; i++) {
        for (int j = jj; j < jj + 3; j++) {
            if (arr[i][j] > 9 || arr[i][j] < 1) {
                return 0;
            } else {
                cnt[arr[i][j]]++;
                if (cnt[arr[i][j]] > 1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int checkRowSum(int** arr, int ii, int jj) {
    int prevsum = -1;
    for (int i = ii; i < ii + 3; i++) {
        int sum = 0;
        for (int j = jj; j < jj + 3; j++) {
            sum += arr[i][j];
        }
        if (prevsum > -1) {
            if (sum != prevsum) {
                return 0;
            }
        } else {
            prevsum = sum;
        }
    }
    return prevsum;
}

int checkColSum(int** arr, int ii, int jj) {
    int prevsum = -1;
    for (int j = jj; j < jj + 3; j++) {
        int sum = 0;
        for (int i = ii; i < ii + 3; i++) {
            sum += arr[i][j];
        }
        if (prevsum > -1) {
            if (sum != prevsum) {
                return 0;
            }
        } else {
            prevsum = sum;
        }
    }
    return prevsum;
}

int checkdiag(int** arr, int ii, int jj) {
    int a = arr[ii][jj] + arr[ii + 1][jj + 1] + arr[ii + 2][jj + 2];
    int b = arr[ii][jj + 2] + arr[ii + 1][jj + 1] + arr[ii + 2][jj];
    if (a != b) {
        return 0;
    }
    return a;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    for (int i = 0; i <= gridSize - 3; i++) {
        for (int j = 0; j <= (*gridColSize) - 3; j++) {
            if (!checkOneToNine(grid, i, j)) {
                continue;
            }
            int sum = 0;
            int rowSum = checkRowSum(grid, i, j);
            if (rowSum == 0) {
                continue;
            } else {
                sum = rowSum;
            }
            int Colsum = checkColSum(grid, i, j);
            if (rowSum != Colsum) {
                continue;
            }
            int diag = checkdiag(grid, i, j);
            if (diag != rowSum) {
                continue;
            }
            ans++;
        }
    }
    return ans;
}