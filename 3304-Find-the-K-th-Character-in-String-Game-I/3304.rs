impl Solution {
    pub fn kth_character(k: i32) -> char {

        let mut arr = String::from("a");
 
        let k_usize = match k.try_into() {
            Ok(value) => value,
            Err(_) => return ' ',
        }; //to compare with arr.len(). k<=500 

        while arr.len() <= k_usize {
            let newChars: String = arr.chars()
                .map(|c| {
                    let next_char = 
                        ((c as u8 - b'a'+1)%26) as u8 + b'a';
                    next_char as char
                }).collect();
            arr.push_str(&newChars);
        } 

        arr.chars().nth(k_usize - 1).unwrap()
    }
}
