#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long countBadPairs(int* nums, int numsSize) {
    
    int ownValues[numsSize];
    long long goodPairCount = 0;
    long long totalPairs = (long long)(numsSize) * (numsSize - 1) / 2;

    for(int i=0; i<numsSize; i++) {
        ownValues[i] = nums[i]-i;
    }

    qsort(ownValues, numsSize, sizeof(int), compare);

    long long i = 0; 
    long long j = 0;
    while(i<numsSize) {
        j = i;

        while(j<numsSize && ownValues[j]==ownValues[i]) j++;
        j--;

        goodPairCount += (j-i)*(j-i+1)/2;

        i = j+1;
    }
    
    return totalPairs - goodPairCount;
    
}
