class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {

        std::vector<int> charMap(256, 0);

        int max = 0, start = 0;
        int currLength = 0;
        int sLen = s.length();

        for (int end = 0; end < sLen; end++) {

            char currentChar = s[end];

            if (charMap[currentChar] == 1) {

                while (s[start] != currentChar) {
                    charMap[s[start]] = 0;
                    start++;
                    currLength--;
                }

                start++;

            } else {
                charMap[currentChar] = 1;
                currLength++;
                if (currLength > max) {
                    max = currLength;
                }
            }
        }

        return max;
    }
};
