impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut foundConsec = 0;

        for n in arr {
            if (n % 2 == 1) {
                foundConsec += 1;

                if (foundConsec == 3) {
                    return true;
                }
            } else {
                foundConsec = 0;
            }
        }

        false
    }
}
