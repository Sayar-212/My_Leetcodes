int countSeniors(char **details, int detailsSize) {
    int count = 0;
    for (int i = 0; i < detailsSize; i++) {
        if (details[i] != NULL && strlen(details[i]) >= 13) {
            int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');
            if (age > 60) {
                count++;
            }
        }
    }
    return count;
}
