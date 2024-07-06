int numberOfAlternatingGroups(int* colors, int colorsSize) {
    int c = 0;
    for (int i = 0; i < colorsSize; i++) {
        int left = colors[(i - 1 + colorsSize) % colorsSize];
        int middle = colors[i];
        int right = colors[(i + 1) % colorsSize];
        if (middle != left && middle != right && left == right) {
            c++;
        } 
}
    return c;
}