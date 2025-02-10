class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalSum = 0;
        int tempSum = 0;
        int start = 0;

        for(int i=0; i<gas.size(); i++) {
            int diff = gas[i]-cost[i];
            totalSum += diff;
            tempSum += diff;

            if(tempSum < 0) {
                start = i+1;
                tempSum = 0;
            }
        }

        if(totalSum < 0) return -1;

        return start;
        

    }
};