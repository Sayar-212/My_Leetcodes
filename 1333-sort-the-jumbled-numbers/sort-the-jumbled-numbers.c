/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(*(int**)a + 1) - *(*(int**)b + 1));
}
int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    int** mapping_nums = malloc(sizeof(int *) * numsSize);
    for(int i = 0; i < numsSize; i++) {
        *(mapping_nums + i) = calloc(2, sizeof(int));
        mapping_nums[i][0] = i;
        mapping_nums[i][1] = mapping[nums[i] % 10];
        int power = 10;
        int new_num = nums[i] / 10;
        while(new_num > 0) {
            mapping_nums[i][1] += mapping[new_num % 10] * power;
            power *= 10;
            new_num /= 10;
        }
    }
    qsort(mapping_nums, numsSize, sizeof(int *), compare);
    int* ans = malloc(sizeof(int) * numsSize);
    for(*returnSize = 0; *returnSize < numsSize; (*returnSize)++) {
        ans[*returnSize] = nums[mapping_nums[*returnSize][0]];
        free(*(mapping_nums + *returnSize));
    }
    free(mapping_nums);
    return ans;
}