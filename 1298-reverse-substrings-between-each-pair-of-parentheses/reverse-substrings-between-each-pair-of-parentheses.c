void reverseSubstring(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
char* reverseParentheses(char *s) {
    int n = strlen(s);
    char *result = (char*)malloc((n + 1) * sizeof(char));
    strcpy(result, s);
    while (1) {
        int open = -1, close = -1;
        for (int i = 0; i < n; i++) {
            if (result[i] == '(') {
                open = i;
            }
            if (result[i] == ')') {
                close = i;
                break;
            }
        }
        if (open == -1 || close == -1) {
            break;
        }
        reverseSubstring(result, open + 1, close - 1);
        for (int i = open; i < n; i++) {
            result[i] = result[i + 1];
        }
        for (int i = close - 1; i < n - 1; i++) {
            result[i] = result[i + 1];
        }
        n -= 2;
        result[n] = '\0';
    }
    return result;
}