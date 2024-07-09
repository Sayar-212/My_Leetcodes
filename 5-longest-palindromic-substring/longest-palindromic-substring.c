int expandAroundCenter(char *s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char *s) {
    int len = strlen(s);
    if (len == 0) return "";

    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int max_len = len1 > len2 ? len1 : len2;
        if (max_len > end - start) {
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }

    char *result = (char*)malloc((end - start + 2) * sizeof(char));
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';
    return result;
}