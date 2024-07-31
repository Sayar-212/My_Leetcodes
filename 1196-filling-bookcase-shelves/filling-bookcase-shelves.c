int solve(int ind, int **books, int width, int* dp, int n) {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int maxy = 0, w = 0, ans = INT_MAX;
        for (int i = ind; i < n; ++i) {
            if (w + books[i][0] > width)
                break;
            w += books[i][0];
            maxy = fmax(maxy, books[i][1]);
            ans = fmin(ans, maxy + solve(i + 1, books, width, dp, n));
        }
        dp[ind] = ans;
        return dp[ind];
    }
int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    int n = booksSize;
    int dp[n + 1] = {};
    for(int i = 0; i < (n + 1); i++)
        dp[i] = -1;
    return solve(0, books, shelfWidth, dp, n);
}