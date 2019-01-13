/*
 * https://leetcode.com/problems/divide-two-integers/
 *
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 *
 * Time complexity: O(log N)
 * Memory complexity: O(1)
 *
 */


class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1) // Overflow issues
            return INT_MAX;
        
        if(divisor == 1) // No need to divide anything
            return dividend;
        
        
        bool neg = dividend < 0;

        if(neg)
            dividend = -dividend;
        
        if(divisor < 0){
            divisor = -divisor;
            neg = !neg;
        }
        
        unsigned int start,
                 magnitude,
                 left = dividend,
                 quotient = 0;
        
        while(left >= divisor){
            
            start = divisor;
            magnitude = 0;
            
            for(;start <= left - start; magnitude++)
                start += start;
            
            quotient += 1 << magnitude;
            left -= start;
            
        }
        
        return neg ? -quotient : quotient;
    }
};