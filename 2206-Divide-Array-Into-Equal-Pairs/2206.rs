impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        let mut count = vec![0u16; 500];

        for num in nums {
            count[num as usize - 1] += 1;
        } 

        for i in count {
            if i%2 != 0 {
                return false;
            }
        }

        true
    }
}
