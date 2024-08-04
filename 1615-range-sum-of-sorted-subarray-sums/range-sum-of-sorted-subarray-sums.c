#define MOD 1000000007

int sort(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

int sumOfSubArray(int* nums,int Size,int index1,int index2){
    int sum = 0;
    int i;
    for(i=index1;i<=index2;i++){
        sum += nums[i];
    }
    return sum;
}

long long sumOfRange(int* subArray,int index1,int index2){
    long long sum = 0;
    int i;
    for(i=index1;i<=index2;i++){
        sum += subArray[i];
    }
    return sum;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int sumOfSub;
    int start,end,len=0;
    int size = n*(n+1)/2;
    int* subArray = (int*)calloc(size,sizeof(int));
    for(start=0;start<numsSize;start++){
        for(end=start;end<numsSize;end++){
            sumOfSub = 0;
            sumOfSub += sumOfSubArray(nums,numsSize,start,end);
            subArray[len++] = sumOfSub;
        }
    }
    qsort(subArray,len,sizeof(int),sort);
    long long num = sumOfRange(subArray,left-1,right-1);
    free(subArray);
    return num%MOD; 
}