//Less runtime efficient than hash map approach, but
//memory usage is in average range.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int *nums, int numsSize, int target, int *returnSize) {

    *returnSize = 2; //guaranteed by description
    int *result = (int*)malloc(sizeof(int) * 2);

	
    for (int i=0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] =j;
                return result; 
            }
        }
    }
    return NULL;
 }
