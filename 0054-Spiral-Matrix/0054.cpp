class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int boundUpper {0}, boundLeft {0};
        int boundLower = matrix.size()-1;
        int boundRight = matrix[0].size()-1;
        std::vector<int> retVec;

        if(boundLower == -1|| boundRight == -1) return retVec;

        int i;
        while(boundUpper <= boundLower && boundLeft <= boundRight) {
            
            for(i=boundLeft; i<= boundRight; i++) {
                retVec.push_back(matrix[boundUpper][i]);
            }
            boundUpper += 1;

            for(i=boundUpper; i <= boundLower; i++) {
                retVec.push_back(matrix[i][boundRight]);
            }
            boundRight -= 1; 

            if(boundUpper <= boundLower) {
                for(i=boundRight; i >= boundLeft; i--) {
                    retVec.push_back(matrix[boundLower][i]);
                }
                boundLower -= 1;
            }

            if(boundLeft <= boundRight) {
                for(i=boundLower; i >= boundUpper; i--) {
                    retVec.push_back(matrix[i][boundLeft]);
                }
                boundLeft += 1;
            }
        }

        return retVec;
    }
};
    