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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                
            ListNode *returnList = new ListNode();
            ListNode *p1 = l1, *p2 = l2, *temp = returnList;

            int carry = 0;

            while(p1 != nullptr || p2 != nullptr) {
                int val1 = (p1 != nullptr)? p1->val : 0; 
                int val2 = (p2 != nullptr)? p2->val : 0; 

                int sum = carry + val1 + val2;
                carry = (sum >= 10)? 1 : 0;

                temp->val = sum % 10; 

                if((p1 != nullptr && p1->next != nullptr) || (p2 != nullptr && p2->next != nullptr)) {
                    temp->next = new ListNode();
                    temp = temp->next;
                } else {
                    temp->next = nullptr;
                }

                if(p1 != nullptr) p1 = p1->next;
                if(p2 != nullptr) p2 = p2->next;
            }

            if(carry > 0) {
                temp->next = new ListNode(1);
                temp = temp->next;
                temp->next = nullptr;
            }

            return returnList;
    }
};