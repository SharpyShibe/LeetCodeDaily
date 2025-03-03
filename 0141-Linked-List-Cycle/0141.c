/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {

    //Based on Floyd's Cycle Finding Algorithm 
    //Reusing the head parameter as slow iterator 

    if(head == NULL || head->next == NULL) return false;

    struct ListNode *p = head;

    while(p != NULL && p->next != NULL) {
        head = head->next;
        p = p->next->next;

        if(head==p) return true;
    }
    return false;
}
