int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}
int longestSubarray(int* nums, int numsSize, int limit) {
    int maxLength = 0;
    for (int start = 0; start < numsSize; ++start) {
        int minIdx = start;
        int maxIdx = start;
        for (int end = start; end < numsSize; ++end) {
            if (nums[end] < nums[minIdx]) minIdx = end;
            if (nums[end] > nums[maxIdx]) maxIdx = end;
            if (abs_diff(nums[minIdx], nums[maxIdx]) > limit) {
                break; 
            }
            int length = end - start + 1;
            if (length > maxLength) {
                maxLength = length;
            }
            if (numsSize - start <= maxLength) {
                break; 
            }
        }
    } 
    return maxLength;
}