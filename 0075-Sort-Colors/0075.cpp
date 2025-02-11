class Solution {
public:
    void sortColors(vector<int>& nums) {

        int redCount = 0, whiteCount = 0, blueCount = 0; 

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) redCount++;
            else if(nums[i]==1) whiteCount++;
            else blueCount++;
        }

        int i = 0;

        while(redCount > 0) {
            nums[i] = 0;
            redCount--;
            i ++;
        }

        while(whiteCount>0) {
            nums[i] = 1;
            whiteCount --;
            i++;
        }

        while(blueCount > 0) {
            nums[i] = 2;
            blueCount--;
            i++;
        }

    }
};