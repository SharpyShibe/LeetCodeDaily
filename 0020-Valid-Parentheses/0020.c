bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c =='(' || c=='{' || c=='[') {
            stack[++top] = c; 
        } else if (c == ')' || c == '}' || c == ']') {
            if (top < 0 ) return false;

            char openingBracket;
            switch (c) {
                case ')': openingBracket = '('; break;
                case '}': openingBracket = '{'; break;
                case ']': openingBracket = '['; break;
                default : openingBracket = '\0';
            }

            if (stack[top--] != openingBracket) 
		return false;
        }
    }
    return top == -1;
}
