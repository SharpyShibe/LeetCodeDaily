/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA == nil || headB == nil {
        return nil
    }

    var tailA *ListNode = headA
    var tailB *ListNode = headB

    for tailA.Next != nil {
        tailA = tailA.Next
    }
    for tailB.Next != nil {
        tailB = tailB.Next
    }

    if tailA != tailB {
        return nil
    }

    var p1 *ListNode
    var p2 *ListNode
    for tailA != headA && tailB != headB {
        p1 = headA
        p2 = headB
        for p1.Next != tailA {
            p1 = p1.Next
        }
        for p2.Next != tailB {
            p2 = p2.Next
        }
        if p1 != p2 {
            return tailB
        }
        tailA = p1
        tailB = p2
    }

    return tailB
}
