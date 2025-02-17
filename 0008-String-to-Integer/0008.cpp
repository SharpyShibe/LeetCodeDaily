#include <ctype.h>
#include <limits.h>
#include <string>

using namespace std;

class Solution {

private:
    void  extractNumber(const string& s, bool& neg, int& start, int& end) {
        start = 0; 
        end = 0; 
        neg = false;

        while(start < s.length() && s.at(start) == ' ') start++;

        if(start >= s.length()) return;

        char c = s.at(start);

        if(c=='+') 
            start++;
        else if(c == '-') {
            start++;
            neg = true;
        } else if(!isdigit(c)) {
            start = -1;
            return;
        }

        while(start < s.length() && s.at(start)=='0') start++;

        end = start;

        while(end < s.length() && isdigit(s.at(end))) end++;
        end--;

     }


public:
    int myAtoi(string s) {
        int start, end; 
        bool neg;

        extractNumber(s, neg, start, end);

        if(start >= s.length() || !isdigit(s.at(start)) || end >= s.length()) return 0;
        
        long result = 0;

        for(int i=start; i<= end; i++) {
            result = result*10 + (int)(s.at(i)-'0');

            if(!neg && result > INT_MAX) return INT_MAX;
            if(neg && -result < INT_MIN) return INT_MIN;
        }

        return neg? -result : result;
    }

};
