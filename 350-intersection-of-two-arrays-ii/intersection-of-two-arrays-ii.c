int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;
    int* used = (int*)calloc(nums2Size, sizeof(int)); 
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j] && !used[j]) { 
                result[*returnSize] = nums1[i]; 
                (*returnSize)++; 
                used[j] = 1; 
                break; 
            }
        }
    }
    free(used);
    return result;
}