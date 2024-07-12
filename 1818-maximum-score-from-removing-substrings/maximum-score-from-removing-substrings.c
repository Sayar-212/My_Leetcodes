int removeAndScore(char* s, int n, char c1, char c2, int score) {
    char* stack = (char*)malloc(n + 1);
    int top = -1, points = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c2 && top >= 0 && stack[top] == c1) {
            top--;
            points += score;
        } else {
            stack[++top] = s[i];
        }
    }
    stack[++top] = '\0';
    strcpy(s, stack);
    free(stack);
    return points;
}
int maximumGain(char* s, int x, int y) {
    int n = strlen(s);
    int points = 0;
    if (x > y) {
        points += removeAndScore(s, n, 'a', 'b', x);
        points += removeAndScore(s, strlen(s), 'b', 'a', y);
    } else {
        points += removeAndScore(s, n, 'b', 'a', y);
        points += removeAndScore(s, strlen(s), 'a', 'b', x);
    }
    return points;
}