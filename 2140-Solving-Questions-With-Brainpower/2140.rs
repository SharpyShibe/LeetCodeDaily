impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut dp = vec![0i64; n + 1];
        let mut solveThis = 0;
        let mut skipThis = 0;

        for i in (0..n).rev() {
            let points = questions[i][0] as i64;
            let brainpower = questions[i][1] as usize;
            let next = i + brainpower + 1;
            
            if next < n {
                solveThis = points + dp[next];
            } else {
                solveThis = points;
            }
            skipThis = dp[i + 1];
            if solveThis > skipThis {
                dp[i] = solveThis;
            } else {
                dp[i] = skipThis;
            }
        }

        dp[0]
    }
}

