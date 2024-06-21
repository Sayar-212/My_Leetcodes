int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int total = 0;
    int s = 0, cur = 0;
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0) {
            total += customers[i];
        }
    }
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) {
            cur += customers[i];
        }
    }
    s = cur;
    for (int i = minutes; i < customersSize; i++) {
        cur += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
        if (cur > s) {
            s = cur;
        }
    }
    return total + s;
}