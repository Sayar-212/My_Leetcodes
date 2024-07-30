int minimumDeletions(char* s) {
    int n = strlen(s);
    int a = 0, b = 0;
    int out = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            a++;
        }
    }
    out = a;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            a--;
        } else {
            b++;
        }
        int deletions = b + a;
        if (deletions < out) {
            out = deletions;
        }
    }
    return out;
}