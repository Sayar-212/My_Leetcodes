bool isValid(char* s) {
    int length = strlen(s);
    char* stack = (char*)malloc(length);
    int top = -1;

    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                free(stack);
                return false;
            }
        }
    }

    bool isValid = top == -1;
    free(stack);
    return isValid;
}