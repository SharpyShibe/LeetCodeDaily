char* removeOccurrences(char* s, char* part) {
    if (s==NULL || part==NULL || *part=='\0') {
        return s;
    }
    
    int partLength = strlen(part);

    while(strstr(s,part) != NULL) {
        char* subStr = strstr(s, part);
        int subStrCounter = 0;
        while(subStr[subStrCounter+partLength] != '\0') {
            subStr[subStrCounter] = subStr[subStrCounter+partLength];
            subStrCounter++;
        }
        subStr[subStrCounter] = '\0';
    }

    return s;
}

