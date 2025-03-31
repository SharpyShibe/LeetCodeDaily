/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) {

    if(numsSize==0 || numsSize==1) {
        *returnSize = numsSize;
        return nums;
    }

    for(int i=0; i<numsSize-1; i++)
        if(nums[i]==nums[i+1]) {
            nums[i] *= 2;
            nums[i+1] = 0;
        }

    int zeroesStart = 0;
    for(int i=0; i<numsSize; i++)
        if(nums[i] != 0) nums[zeroesStart++]=nums[i];

    for(int i=zeroesStart; i<numsSize; i++) 
        nums[i] = 0;

    //return in place to save memory
    *returnSize = numsSize;
    return nums;
}
