int minKBitFlips(int* nums, int numsSize, int k) {
    int flips = 0;
    int needsFlip = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i >= k) {
            needsFlip -= nums[i - k] >> 1;
        }
        if ((nums[i] + needsFlip) % 2 == 0) { 
            if (i + k > numsSize) {
                return -1; 
            }
            flips++;
            needsFlip++;
            nums[i] += 2;
        }
    }
    return flips;
}