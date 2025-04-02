/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    
    if(head==NULL) return 0;
    if(head->next == NULL) return head->val==1;

    int retVal = 0;
    int pow = 1;

    for(struct ListNode *temp = head;
        temp->next != NULL;
        temp = temp->next)
            pow += 1;

    pow--;
    
    while(head != NULL) {
        retVal += (head->val)*(1<<pow);
        pow--;
        head = head->next;
    }

    return retVal;
}
