/*
 *  https://leetcode.com/problems/reverse-integer/
 *
 *  Given a 32-bit signed integer, reverse digits of an integer.
 *  
 *  Overall complexity: O(log N)
 *  Memory complexity: O(1)
 *
 */

class Solution {
public:
    int reverse(int x) {
        long r = 0;
        
        for(; x; x /= 10){
            // Add digit at the end
            r = r * 10 + x % 10;

            // Too big
            if(r > INT_MAX || r < INT_MIN)
                return 0;
        }
        
        return r;
    }
};