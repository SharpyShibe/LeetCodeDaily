use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen_map = HashMap::new();

        for(index, &num) in nums.iter().enumerate() {

            let diff = target - num;
            let diff_index_ref_opt = seen_map.get(&diff);

            if diff_index_ref_opt.is_some() {
                let diff_index_ref = diff_index_ref_opt.unwrap();
                return vec![*diff_index_ref, index as i32]
            }

            seen_map.insert(num, index as i32);
        }  

        vec![]
    }
}