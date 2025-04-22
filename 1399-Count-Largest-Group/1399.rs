impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
    let mut countarray = [0; 36]; // As 36 is the largest digit sum possible (1 <= n <= 10^4)
    let mut returnCounter = 0;
    let mut mostFrequentCount = 0;

    let mut tnum: i16;
    let mut digit: i16;
    let mut digitSum: i16;

    for num in 1..=n {
        tnum = num as i16;
        digitSum = 0;

        while tnum != 0 {
            digit = tnum % 10;
            digitSum += digit;
            tnum /= 10;
        }

        countarray[(digitSum - 1) as usize] += 1;
    }

    for count in countarray.iter() {
        if *count > mostFrequentCount {
            returnCounter = 1;
            mostFrequentCount = *count;
        } else if *count == mostFrequentCount {
            returnCounter += 1;
        }
    }

    returnCounter
    }
}
