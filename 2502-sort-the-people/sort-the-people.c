/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    char** result = (char**)malloc(namesSize * sizeof(char*));
    int* sortedHeights = (int*)malloc(heightsSize * sizeof(int));
    memcpy(sortedHeights, heights, heightsSize * sizeof(int));
    qsort(sortedHeights, heightsSize, sizeof(int), compare);
    for (int i = 0; i < namesSize; ++i) {
        for (int j = 0; j < heightsSize; ++j) {
            if (heights[j] == sortedHeights[i]) {
                result[i] = names[j];
                break;
            }
        }
    }
    free(sortedHeights);
    *returnSize = namesSize;
    return result;
}