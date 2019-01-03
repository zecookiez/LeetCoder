/*
 * https://leetcode.com/problems/string-to-integer-atoi/
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *  
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *  
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Time complexity: O(N)
 * Memory complexity: O(1)
 */


class Solution {
public:
    int myAtoi(string str) {
        bool found = false; // If we've already found a digit, +, or - sign
        long r = 0,
             n = 1;
        
        for(char&c : str){
            
            if(isdigit(c)){
                r = r * 10 + (c - 48);
                found = true;
                
                // Too large
                if(r > INT_MAX)
                    return n == -1 ? INT_MIN : INT_MAX;
                
            } else if(found){
                // Invalid string
                break;
                
            } else if(c == 43 || c == 45){

                // + or -
                found = true;
                
                if(c == 45) // - case
                    n = -1;
                
            } else if(c != 32){
                // Skip whitespace
                break;
            }
            
        }
        
        return r * n;
    }
};