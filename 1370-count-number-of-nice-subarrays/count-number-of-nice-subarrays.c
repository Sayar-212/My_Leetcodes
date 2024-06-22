int isOdd(int num) {
    return num % 2 != 0;
}

int numberOfSubarrays(int nums[], int numsSize, int k) {
    int count = 0;
    int oddCount = 0;
    int oddCounter[numsSize + 1]; // Using a fixed-size array instead of calloc

    // Initialize oddCounter array to zero
    for (int i = 0; i <= numsSize; i++) {
        oddCounter[i] = 0;
    }
    oddCounter[0] = 1;  // Base case for 0 odd numbers encountered initially

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