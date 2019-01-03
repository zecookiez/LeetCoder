/*
 *  https://leetcode.com/problems/palindrome-number/
 *
 *  Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 *  
 *  Overall complexity: O(log N)
 *  Memory complexity: O(1)
 *
 */

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false; // Negative numbers are never palindromes
        
        /* Cooler solution IMO, but slower (380ms)
         *
         * int position = pow(10, (int) log10(x));
         *
         * while(x > 0){
         *     if(x % 10 != x / position){
         *         return false;
         *     }
         *     x = x % position / 10;
         *     position /= 100;
         * }
         *
         * return true;
         */
        
        int reverse = 0,
            copy    = x;
        
        // Build reversed number
        for(;x; x /= 10)
            reverse = reverse * 10 + x % 10;
        
        return reverse == copy;
    }
};