//not efficient at all but linked lists are pretty neat 
typedef struct Node {
    char bracket;
    struct Node* next;
} Node;

void push(Node **head, char bracket) {
    struct Node *newHead = (Node*)malloc(sizeof(Node));
    newHead->next = *head;
    newHead->bracket = bracket;
    *head = newHead;
}

void pop(Node **head) {
    if(*head == NULL) return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

bool isValid(char* s) {
    struct Node *head = NULL;
    struct Node *temp;

    for(int i=0; i<strlen(s); i++) {
        char c = s[i];
        if(c=='(' || c=='{' || c=='[') {
            push(&head, c);
        }
        else if(c==')' || c=='}' || c==']') {
            char openingBracket;
            switch(c) {
                case ')': openingBracket = '('; break;
                case '}': openingBracket = '{'; break;
                case ']': openingBracket = '['; break;
            }
            if(head==NULL) return false;
            if(head->bracket!=openingBracket) return false;
            pop(&head);
        }
    }
    if (head == NULL) return true;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return false;
}
