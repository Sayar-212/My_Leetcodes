int minSwaps(int nums[], int s) {
    int ones = 0;
    for (int i = 0; i < s; i++) {
        ones += nums[i];
    }
    if (ones == 0 || ones == s) {
        return 0;
    }
    int curr = 0;
    for (int i = 0; i < ones; i++) {
        curr += nums[i];
    }
    int maxi = curr;
    for (int i = 0; i < s; i++) {
        curr -= nums[i];
        curr += nums[(i + ones) % s];
        maxi = (maxi > curr) ? maxi : curr;
    }
    return ones - maxi;
}