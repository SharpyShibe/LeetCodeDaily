/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *returnList = malloc(sizeof(struct ListNode));
    struct ListNode *p1 = l1, *p2 = l2, *temp = returnList;

    int carry = 0;

    while(p1 != NULL || p2 != NULL) {
        int val1 = (p1 != NULL)? p1->val : 0; 
        int val2 = (p2 != NULL)? p2->val : 0; 

        int sum = carry + val1 + val2;
        carry = (sum >= 10)? 1 : 0;

        temp->val = sum % 10;
        
        if(p1 != NULL && p1->next != NULL || p2 != NULL && p2->next != NULL) {
            temp->next = malloc(sizeof(struct ListNode));
            temp = temp->next;
        } else {
            temp->next = NULL;
        }

        if(p1 != NULL) p1 = p1->next;
        if(p2 != NULL) p2 = p2->next;
    }

    if(carry > 0) {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = 1;
        temp->next = NULL;
    }

    return returnList;
}