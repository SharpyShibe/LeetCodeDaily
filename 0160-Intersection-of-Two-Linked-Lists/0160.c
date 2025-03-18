/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if(headA == NULL) return NULL;
    if(headB == NULL) return NULL;

    struct ListNode *tailA, *tailB;
    tailA = headA;
    tailB = headB;

    while(tailA->next != NULL) tailA = tailA -> next;
    while(tailB->next != NULL) tailB = tailB -> next;

    if(tailA != tailB) return NULL;

    struct ListNode *p1, *p2;
    while(tailA != headA && tailB != headB){
        p1 = headA; p2 = headB;
        while(p1->next != tailA) p1 = p1 -> next;
        while(p2->next != tailB) p2 = p2 -> next;

        if(p1 != p2) return tailB;
        tailA = p1;
        tailB = p2;
    }
    return tailB;
}
