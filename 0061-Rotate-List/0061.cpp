/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return NULL;

        int listLength = 1;
        ListNode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
            listLength += 1; 
        }
        k %= listLength;

        while(k>0) {
            head = rotateOnce(head);
            k -= 1;
        }

        return head;
    }

private:
    ListNode* rotateOnce(ListNode *head) {

        if(head == NULL || head->next == NULL) return head;
        ListNode *temp = head;
        
        while(temp->next != NULL) {
            temp = temp->next;
        }

        ListNode *pretemp = head;
        while(pretemp->next != temp) pretemp = pretemp->next;

        temp->next = head;
        pretemp->next = NULL;

        return temp;
    }
};