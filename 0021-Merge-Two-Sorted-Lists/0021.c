/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if(list1 == NULL && list2 != NULL) return list2;
    if(list1 != NULL && list2 == NULL) return list1;
    if(list1 == NULL && list2 == NULL) return NULL;

    struct ListNode *temp, *insertTemp;
    struct ListNode *otherList;
    struct ListNode *newList;

    if(list1->val <= list2->val) {
        newList = list1;
        temp = list1;
        otherList = list2;
    } else {
        newList = list2;
        temp = list2;
        otherList = list1;
    }


    while(temp != NULL) {

        if( otherList != NULL && 
            temp->next != NULL &&
            temp->val <= otherList->val &&
            otherList->val <= temp->next->val) {

                insertTemp = otherList->next;
                otherList->next = temp->next;
                temp->next = otherList;
                otherList = insertTemp;

            } else if(otherList != NULL && 
                      temp->next == NULL) {

                temp->next = otherList;
                break;

            } else {
                temp = temp->next;
            }
        }
        
    return newList;
}
