bool isValid(char* word) {

    if(word == NULL) return false;
    if(strlen(word)<3) return false;

    const char *vowels = "aeiouAEIOU";

    bool vowel = false;
    bool consonant = false;

    for(char i=0; word[i] != '\0'; i++) {
         
        if(!isdigit(word[i]) && !isalpha(word[i]))
            return false;
        
        if(strchr(vowels, word[i])) {
            vowel = true;
            continue;
        }

        if(isalpha(word[i]) && !strchr(vowels,word[i])) {
            consonant = true;
        }
    }

    return vowel && consonant;
}
