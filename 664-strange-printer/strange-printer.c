
int strangePrinter(char* s) {
    int n = strlen(s);
    int dp[n][n] = {};
    for(int i = n - 1; i >= 0; --i){
        dp[i][i] = 1;
        for(int j = i + 1; j < n; ++j){
            dp[i][j] = 1 + dp[i + 1][j];
            for(int k = i + 1; k < (j + 1); ++k){
                if(s[i] == s[k])
                    dp[i][j] = fmin(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
            }
        }
    }
    return dp[0][n - 1];
}