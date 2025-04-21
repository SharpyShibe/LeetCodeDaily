/**
 * Counts the number of contiguous sub-arrays of length 3 that fulfill the criteria:
 * [X, Y, Z] where X + Z = Y / 2.
 *
 * @param nums Pointer to the array of integers.
 * @param numsSize The size of the array.
 * @return The count of special sub-arrays.
 */
int countSubarrays(int* nums, int numsSize) {
    int x,y,z;
    int count;

    for(int i=0; i <= numsSize-3; i++) {
        x = nums[i];
        y = nums[i+1];
        z = nums[i+2];
        if(2*(x+z) == y) count++;
    }
    return count;
}
