int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a > 0 ? a : -a;
}

char* fractionAddition(char* expression) {
    int a = 0, b = 1, c, d;

    while (expression != NULL) {
        sscanf(expression, "%d/%d", &c, &d);
        a = a * d + c * b;
        b *= d;
        expression = strpbrk(expression + 1, "+-");
    }
    c = gcd(a, b);
    a /= c, b /= c;

    char *s = malloc(snprintf(NULL, 0, "%d/%d", a, b) + 1);
    sprintf(s, "%d/%d", a, b);
    return s;
}