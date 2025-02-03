class Solution {
    public boolean isPalindrome(int x) {
        
        if(x < 0) return false;
        if(x == 0) return true;

        int num = x; 
        long rev = 0; 

        while(num > 0) {
            int digit = num % 10; 
            rev = rev * 10 + digit; 
            num /= 10;
        }

        return x == rev;
    }
}