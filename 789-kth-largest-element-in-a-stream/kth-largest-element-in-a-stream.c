typedef struct {
    int k;
    int *nums;
    int numsSize;
} KthLargest;

int compare(const void * a, const void * b) {
    return ( *(int*)b - *(int*)a );
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
   KthLargest *box=malloc(sizeof(KthLargest));
   box->k=k;
   box->numsSize=numsSize;
   box->nums=malloc(sizeof(int)*numsSize);
   for(int i = 0; i < numsSize; i++) {
    box->nums[i] = nums[i];
    }
    qsort(box->nums, box->numsSize, sizeof(int), compare);
    return box;
}

int kthLargestAdd(KthLargest* obj, int val) {
   
    obj->nums = realloc(obj->nums, (obj->k+1) * sizeof(int));
    int i;
    for (i = obj->k - 1; i >= 0; i--) {
        if (obj->nums[i] < val) {
            obj->nums[i + 1] = obj->nums[i]; 
            } 
            else {
            break;
        }
    }

    obj->nums[i + 1] = val;
    return  obj->nums[obj->k-1] ;
    
}

void kthLargestFree(KthLargest* obj) {
    free(obj);
}