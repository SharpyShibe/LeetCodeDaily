char* makeFancyString(char* s) {
    if(strlen(s)<2) return s;

    size_t len = strlen(s);
    size_t consec = 1;
    char prev = s[0];
    char *retStr = (char*)malloc(len+1);
        if(retStr==NULL) return NULL;
    int retStrIndex = 0;
    retStr[retStrIndex++]=s[0];

    for(int i=1; i<len; i++) {
        if(prev==s[i]) {
            consec++;
            if(consec>=3) continue;
        } else consec = 1;

        prev=s[i];
        retStr[retStrIndex++] = s[i];
    }

    retStr[retStrIndex]='\0';

    return retStr;
}
