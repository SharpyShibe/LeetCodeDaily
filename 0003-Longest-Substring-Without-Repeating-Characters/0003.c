#define ASCII_SIZE 256

int charMap[ASCII_SIZE]; //assuming input is ASCII only

void clearMap() {
    memset(charMap, 0, sizeof(charMap));
}

int lengthOfLongestSubstring(char* s) {
    int sLen = strlen(s);
    int max = 0, start = 0;
    int currLength = 0;

    clearMap();

    for (int fin = 0; fin < sLen; fin++) {

        char currentChar = s[fin];

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