impl Solution {
    pub fn count_subarrays(nums: Vec<i32>) -> i32 {
        let mut count = 0; 

        for i in 0..nums.len()-2 {
            let x = nums[i];
            let y = nums[i+1];
            let z = nums[i+2];
            if 2*(x+z) == y {
                count += 1;
            }
        }

        count
    }
}
