#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int countLargestGroup(int n) {
    std::vector<int> countArray(36, 0); //As 36 is the largest digit sum possible (1 <= n <= 10^4)
    int returnCounter = 0;
    int mostFrequentCount = 0;

    auto digitSum = [](int num) -> int {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    };

    for (int num = 1; num <= n; ++num) {
        countArray[digitSum(num) - 1]++;
    }

    for (const auto& count : countArray) {
        if (count > mostFrequentCount) {
            returnCounter = 1;
            mostFrequentCount = count;
        } else if (count == mostFrequentCount) {
            returnCounter++;
        }
    }

    return returnCounter;
    }
};
