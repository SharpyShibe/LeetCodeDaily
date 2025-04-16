class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int shortestLen = 201; //max length 200
        int shortestInd = 0;
        for(int i=0; i<strs.size(); i++) {
            if(strs.at(i).size() < shortestLen) {
                shortestLen = strs.at(i).size();
                shortestInd = i;
            }
        }
        
        char currChar;
        for(int currPos=0; currPos < shortestLen; currPos++) {

            currChar = strs.at(shortestInd).at(currPos);

            for(int i=0; i<strs.size(); i++)
                if(strs.at(i).at(currPos) != currChar)
                    return strs.at(0).substr(0,currPos);
        }

    return strs.at(0).substr(0,shortestLen);
    }
};
