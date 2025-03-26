char* findDifferentBinaryString(char** nums, int numsSize) {
    
    char *retString = (char*)malloc(numsSize+1);

    for(int i=0; i<numsSize; i++) {
        retString[i] = (nums[i][i]=='0'? '1':'0');
    }

    retString[numsSize] = '\0';
    return retString;
}
