int lengthOfLongestSubstring(char * s){
    if (!s || !strnlen(s, 5*10000)) {
        return 0;
    }

    static const int notSeen = -1;
    int lastIndex[CHAR_MAX] = {0};
    for (int i = 0; i < CHAR_MAX; ++i) {
        lastIndex[i] = notSeen;
    }
    int l = 0;
    int r = 0;
    int max_len = 0;

    while (*(s+r)) {
        char c = *(s+r);
        if (lastIndex[c] != notSeen && lastIndex[c] >= l) {
            l = lastIndex[c] + 1;
        } else {
            max_len = max_len < r - l + 1 ? r - l + 1 : max_len;
            lastIndex[c] = r++;
        }
    }

    return max_len;
}