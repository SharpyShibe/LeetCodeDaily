class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //assuming nums1 is smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int arrSize1 = nums1.size();
        int arrSize2 = nums2.size();

        int half = (arrSize1 + arrSize2 + 1) / 2;

        int l = 0;
        int r = arrSize1;

        while (l <= r ) {
            int i = (l + r) / 2;
            int j = half - i;

            int aL, aR, bL, bR;
            
            if(i==0) aL = INT_MIN;
            else aL = nums1[i-1];

            if(i==arrSize1) aR = INT_MAX;
            else aR = nums1[i];

            if(j==0) bL = INT_MIN;
            else bL = nums2[j-1];

            if(j==arrSize2) bR = INT_MAX;
            else bR = nums2[j];

            if (aL <= bR && bL <= aR) {
                if (((arrSize1 + arrSize2) % 2) == 0) {
                    //even total
                    return (max(aL, bL) + min(aR, bR)) / (2.0);
                } else {
                    //uneven total, return max left
                    return max(aL, bL);
                }
            } else if (aL > bR) {
                //aL too big, move left
                r = i - 1;
            } else {
                //aR too small, move right
                l = i + 1;
            }
        }

        return 42.0;
    }
};
