int isOdd(int num) {
    return num % 2 != 0;
}
int numberOfSubarrays(int nums[], int numsSize, int k) {
    int count = 0;
    int oddCount = 0;
    int oddCounter[numsSize + 1];
    for (int i = 0; i <= numsSize; i++) {
        oddCounter[i] = 0;
    }
    oddCounter[0] = 1;  
    for (int i = 0; i < numsSize; i++) {
        if (isOdd(nums[i])) {
            oddCount++;
        }
        if (oddCount >= k) {
            count += oddCounter[oddCount - k];
        }
        oddCounter[oddCount]++;
    }
    return count;
}