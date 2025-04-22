int countLargestGroup(int n) {
    short countarray[36] = {}; //As 36 is largest digit sum possible (1 <= n <= 10^4)
    int returnCounter = 0;
    short mostFrequentCount = 0;

    short tnum = 0;
    short digit = 0;
    short digitSum = 0;
    for(short num=1; num <= n; num++) {
        tnum = num; 
        while(tnum != 0) {
            digit = tnum % 10; 
            digitSum += digit;
            tnum /= 10;
        }

        countarray[digitSum-1]++;
        digitSum = digit = 0; 
    }

    for(char i=0; i<36; i++) {
        if(countarray[i] > mostFrequentCount) {
            returnCounter = 1; 
            mostFrequentCount = countarray[i];
        } else if(countarray[i] == mostFrequentCount) {
            returnCounter++;
        }
    }

    return returnCounter;
}
