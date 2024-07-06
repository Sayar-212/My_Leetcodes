int numberOfAlternatingGroups(int* colors,int n,int k) {
     int res = 0;
    for (int i = 1, l = 0; i < n + k; i++) {
        if (colors[i % n] == colors[(i - 1) % n])
            l = i - 1;
        l = (l > i - k) ? l : i - k;
        if (i - l == k)
            res++;
    }
    return res;
}