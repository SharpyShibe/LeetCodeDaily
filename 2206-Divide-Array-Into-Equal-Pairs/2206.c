#define MAXVAL 500 // 1 <= nums[_] <= 500

bool divideArray(int* nums, int numsSize) {

    if(numsSize%2 != 0) return false;

    char hashmap[MAXVAL] = {0};

    for(int i=0; i<numsSize; i++)
        hashmap[nums[i]-1]++;
    
    for(int i=0; i<MAXVAL; i++)
        if(hashmap[i]%2 != 0) return false;

    return true;

}
