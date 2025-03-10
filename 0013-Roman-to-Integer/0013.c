//use an array lookup table instead of a function
//like "int romanCharToInt(char c)" to avoid function
//call overhead
int rtoi[256] = {0};

void initRomanLookupTable() {
    rtoi['I'] = 1;
    rtoi['V'] = 5;
    rtoi['X'] = 10;
    rtoi['L'] = 50;
    rtoi['C'] = 100;
    rtoi['D'] = 500;
    rtoi['M'] = 1000;
}

int romanToInt(char* s) {
    uint romanLen = strlen(s);
    int total = 0;
    int currInt, nextInt;

    initRomanLookupTable();

    for(int i=0; i < romanLen; i++) {

        if(s[i+1] != '\0') {
            currInt = rtoi[(unsigned char)s[i]];
            nextInt = rtoi[(unsigned char)s[i+1]];
            if( currInt < nextInt)  {
                total += nextInt - currInt;
                i++;
                continue;
            }

            total += currInt;
            
            if(s[i+1]==s[i] && s[i+2] != s[i]) {
                total += currInt;
                i++;
                continue;
            }

            if(s[i+1]==s[i] && s[i+2] == s[i]) {
                total += 2*currInt;
                i += 2;
                continue;
            }
        }
        else {
            total += rtoi[(unsigned char)s[i]];
            break;
        }
    }
    return total;
}
