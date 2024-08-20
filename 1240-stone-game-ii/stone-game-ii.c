#define MAX_N 100

int n;
int postsum[MAX_N + 1];
int mem[MAX_N][MAX_N];

int max(int a, int b) {
return a > b ? a : b;
}

int dfs(int i, int m) {
if (i >= n) return 0;
if (i + 2 * m >= n) return postsum[i]; // optimization, just take it all
if (mem[i][m] >= 0) return mem[i][m];
int best = 0;
for (int x = 1; x <= 2 * m && i + x <= n; x++) {
best = max(best, postsum[i] - dfs(i + x, max(x, m)));
}
return (mem[i][m] = best);
}
int stoneGameII(int* piles, int pilesSize) {
n = pilesSize;
int maxM = (n + 5) / 4; // m < maxM
memset(mem, -1, sizeof(mem));
memset(postsum, 0, sizeof(postsum));
for (int i = n - 1; i >= 0; i--) {
postsum[i] = piles[i] + postsum[i + 1];
}
return dfs(0, 1);
}