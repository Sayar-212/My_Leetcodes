int compare(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int countpairs(int *nums,int numsSize,int mid){
    int count = 0;
    for(int i = 0; i<numsSize;i++){
        int j = i+1;
        while (j < numsSize && nums[j] - nums[i] <= mid){
            count++;
            j++;
        }
    }
    return count;
}
int smallestDistancePair(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),compare);
    int low = 0,high = nums[numsSize-1]-nums[0];
    while(low < high){
        int mid = low + (high - low) / 2;
        int count = countpairs(nums,numsSize,mid);
        if(count < k){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}