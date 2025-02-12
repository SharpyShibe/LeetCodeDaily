/*
 * Rust implementation for Dijkstra's Dutch National Flag
 * algorithm.
*/

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {

        let mut i = 0;
        let mut j = 0;
        let mut k = nums.len() - 1;
        let mid = 1; //Pivot value

        //Handle edge case arrays of length 1 and 2 seperately
        if (nums.len() == 1) { return; }
        if (nums.len() == 2) {
            if (nums[0] > nums[1]) {
                nums.swap(0,1);
            }
            return;
        }
        
        while (j <= k) {
            if(nums[j] < mid) {
                nums.swap(i,j);
                i  += 1;
                j += 1;
            } else if(nums[j] > mid) {
                nums.swap(j,k);
                k -= 1;
            } else {
                j += 1;
            }
        }
    }
}