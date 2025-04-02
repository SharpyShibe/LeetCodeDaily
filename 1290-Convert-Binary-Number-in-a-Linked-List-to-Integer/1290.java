/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        if(head == null) return 0;

        int pow = 0;

        for(ListNode temp = head;
            temp != null;
            temp = temp.next) {
            pow++;
        }

        pow--;

        int retVal = 0;

        while(head != null) {
            retVal += head.val * (1<<pow);
            pow--;
            head=head.next;
        }

        return retVal;

    }
}
