bool    find_negative_k(int *nums, int numsSize, int k)
{
    int i;

    i = 0;
    while (i < numsSize)
    {
        if (-k == nums[i])
            return (true);
        i++;
    }
    return (false);
}

int findMaxK(int* nums, int numsSize) {
    int max;
    int i;
    
    max = -1;
    i = 0;
    while (i < numsSize)
    {
        if (nums[i] > max)
        {
            if (find_negative_k(nums, numsSize, nums[i]))
                max = nums[i];
        }
        i++;
    }
    return (max);
}