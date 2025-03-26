class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        std::string retString = "";
        for(int i=0; i<nums.size(); i++) {
            retString.push_back(nums[i][i]=='0'? '1' : '0');
        }
        return retString;
    }
};
