impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        
        if x < 0 {
        	return false;
        }

        if x == 0 {
        	return true;
        }

        let mut num = x; 
        let mut rev = 0; 

        while num > 0 {
        	let digit = num % 10; 
        	rev = rev * 10 + digit; 
        	num /= 10;
        }

        return x == rev;
    }
}