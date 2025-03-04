int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int freq[10] = {0};
    //Number of 3-digit numbers: 999
    //Excluding numbers with leading 0s:(-99) 900
    //Only even numbers: (/2) 450
    int* resultArray = (int*)malloc(sizeof(int) * 450);
    int count = 0;
    bool canFormNumber = true;
    int centum, decem, unitas;

    for (int i = 0; i < digitsSize; i++) {
        freq[digits[i]]++;
    }

    for (int i = 100; i <= 999; i += 2) {
	
        centum = i / 100;
        decem = (i / 10) % 10;
        unitas = i % 10;

        int requiredDigits[10] = {0};
        requiredDigits[centum]++;
        requiredDigits[decem]++; 
        requiredDigits[unitas]++;

        canFormNumber = true;
        for (int j = 0; j < 10; j++) { 
            if (requiredDigits[j] > freq[j]) {
                canFormNumber = false;
                break;
            }
        }
        if (canFormNumber) { 
            resultArray[count++] = i;
        }
    }
    *returnSize = count;
    return resultArray;
}


