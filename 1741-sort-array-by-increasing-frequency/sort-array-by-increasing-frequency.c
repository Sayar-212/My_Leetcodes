/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b, void* count) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    int* cnt = (int*)count;

    if (cnt[valA + 100] == cnt[valB + 100]) {
        return valB - valA;
    }
    return cnt[valA + 100] - cnt[valB + 100]; 
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int count[201] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 100]++;
    }

    qsort_r(nums, numsSize, sizeof(int), compare, count);

    *returnSize = numsSize;
    return nums;
}