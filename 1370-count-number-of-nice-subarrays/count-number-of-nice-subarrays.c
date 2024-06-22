int isOdd(int num) {
    return num % 2 != 0;
}
int numberOfSubarrays(int* nums, int numsSize, int k) {
    int left = 0, right = 0;
    int oddCount = 0, result = 0, prefixCount = 0;
    while (right < numsSize) {
        if (isOdd(nums[right])) {
            oddCount++;
            prefixCount = 0;
        }
        while (oddCount == k) {
            prefixCount++;
            if (isOdd(nums[left])) {
                oddCount--;
            }
            left++;
        }
        result += prefixCount;
        right++;
    }
    return result;
}