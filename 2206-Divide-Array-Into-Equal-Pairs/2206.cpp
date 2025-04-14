class Solution {
public:
    bool divideArray(vector<int>& nums) {

        size_t len = nums.size();
        if(len % 2 != 0) return false;

        for(int i=0; i<len; i++) {
            if(nums[i]==-1) continue;
            for(int j=i+1; j<len; j++) {
                if(nums[i]==nums[j]){
                    nums[i]=-1;
                    nums[j]=-1;
                    break;
                }
            }
            if(nums[i]!=-1) return false;
        }   

        for(int i=0; i<len; i++) {
            if(nums[i]!=-1) return false;
        }

        return true;
    }
};
