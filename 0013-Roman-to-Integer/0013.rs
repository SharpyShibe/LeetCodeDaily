use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {

        let roman: HashMap<char, i32> = [
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]
        .iter()
        .cloned() //ownership for collect() hash map creation
        .collect();

        let chars: Vec<char> = s.chars().collect();
        let mut total = 0;
        let mut i = 0;

        while (i < chars.len()) {
            let curr = *roman.get(&chars[i]).unwrap_or(&0);
            let next = if i + 1 < chars.len() {
                *roman.get(&chars[i + 1]).unwrap_or(&0)
            } else {
                0
            };

            if (curr < next) {
                total += next - curr;
                i += 2;
                continue;
            } else if(curr==next) {
                total += 2*curr;
                i += 2;
                continue;
            } else if (
                i+2 < chars.len() &&
                chars[i]==chars[i+1] && 
                chars[i]==chars[i+2]) {
                total += 3*curr;
                i += 3;
                continue
            }

            total += curr;
            i += 1;
        }

        total
    }
}
