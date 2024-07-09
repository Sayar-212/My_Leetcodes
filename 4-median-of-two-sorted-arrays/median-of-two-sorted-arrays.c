double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
int i=0,j=0,k=0,c[1000000];
while(i<nums1Size && j<nums2Size)
{
    if(nums1[i]>=nums2[j])
    {
        c[k]=nums2[j];
        j++;
    }
    else if(nums2[j]>nums1[i])
    {
        c[k]=nums1[i];
        i++;
    }
    k++;
}

    while(j!=nums2Size)
    {
        c[k]=nums2[j];
        k++;
        j++;
    }

    while(i!=nums1Size)
    {
        c[k]=nums1[i];
        k++;
        i++;
    }

int x,y;
float z;
    x=k/2;
    y=x-1;
if(k%2==0)
{
    z=(c[x]+c[y])/2.0; 
    return z;
}
else{
    z=c[x];
    return z;
}
}