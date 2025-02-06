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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        
        let mut temp = Box::new(ListNode::new(0)); //temp serves as dummy node
        let mut current = &mut temp;
        let mut p1 = l1; 
        let mut p2 = l2; 

        let mut carry = 0;

        while p1.is_some() || p2.is_some() {

            let val1 = p1.as_ref().map_or(0, |node| node.val);
            let val2 = p2.as_ref().map_or(0, |node| node.val);

            let sum = carry + val1 + val2;
            carry = if sum >= 10 {1} else {0};

            current.next = Some(Box::new(ListNode::new(sum % 10)));
            current = current.next.as_mut().unwrap();

            if let Some(node) = p1.take() { 
                p1 = node.next;
            }

            if let Some(node) = p2.take() {
                p2 = node.next;
            }

        }


        if carry > 0 {
            current.next = Some(Box::new(ListNode::new(carry)));
        }

        temp.next //actual return list starts after temp
    }
}