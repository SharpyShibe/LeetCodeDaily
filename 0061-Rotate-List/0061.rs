// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {

        if head.is_none() {
            return None;
        }

        let mut head = head;
        let mut len = 1; 
        let mut temp = head.as_ref();

        while let Some(node) = temp {
            if node.next.is_none() {
                break;
            }
            temp = node.next.as_ref();
            len += 1;
        }

        let mut k = k % len;
        while k > 0 {
            head = Self::rotate_once(head);
            k -= 1;
        }

        head
    }

    fn rotate_once(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head
        }

        let mut curr = head;
        let mut prev: Option<Box<ListNode>> = None;
        let mut last_val: i32 = 0;

        let mut temp = Some(Box::new(ListNode { val: 0, next: curr }));
        let mut node = temp.as_mut().unwrap().next.as_mut();

        while let Some(inner) = node {
            if inner.next.is_some() && inner.next.as_ref().unwrap().next.is_none() {
                last_val = inner.next.as_ref().unwrap().val;
                inner.next = None;
                break;
            }
            node = inner.next.as_mut();
        }

        let mut new_head = Some(Box::new(ListNode {
            val: last_val,
            next: temp.unwrap().next,
        }));

        new_head
    }
}