/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {

    if(head==NULL) return NULL;
    if(head->next == NULL) return head;

    struct ListNode *p1, *p2;
    p1=head; p2=head->next;
    struct ListNode *pre = NULL;

    while(p2 != NULL) {

        p1->next = p2->next;
        p2->next = p1;
        if(pre != NULL)
            pre->next = p2;
        else
            head = p2;
        pre = p1;
        if(p1->next==NULL) break;
        p1 = p1->next;
        p2 = p1->next;
        
    }

    return head;
}
