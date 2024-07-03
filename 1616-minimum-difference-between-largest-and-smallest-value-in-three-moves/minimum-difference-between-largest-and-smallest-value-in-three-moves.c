int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int minDifference(int* nums, int numSize) {
    if (numSize <= 4) return 0; 
    qsort(nums, numSize, sizeof(int), compare); 
    int minDiff = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        int diff = nums[numSize - 4 + i] - nums[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}