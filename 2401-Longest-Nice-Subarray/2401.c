int longestNiceSubarray(int* nums, int numsSize) {
    int longest = 0;
    int start = 0;
    int seenBitmask = 0;

    for (int end=0; end<numsSize; end++) {
        while ((seenBitmask & nums[end]) !=0)//bitmask clashes
                 seenBitmask ^= nums[start++];//shrink window

        seenBitmask |= nums[end];

        if (end-start+1 > longest)
            longest = end-start+1;
    }

    return longest;
}
