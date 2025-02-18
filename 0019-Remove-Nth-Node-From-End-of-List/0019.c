/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *p; 
    struct ListNode *q; 
    
    p = head;

    for(int i=0; i<n; i++) p = p->next;

    if(p == NULL) {
        struct ListNode *h = head->next;
        free(head);
        return h;
    }

    q = head;

    while(p->next != NULL) {
        p = p->next;
        q = q->next;
    }

    //to remove: q->next
    struct ListNode *temp = q->next;
    q->next = q->next->next;
    free(temp);

    return head;

}