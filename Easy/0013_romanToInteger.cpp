/*
 * https://leetcode.com/problems/integer-to-roman/
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Overall complexity: O(1) - We're going over the same amount of symbols
 * Memory complexity: O(1)
 *
 */

class Solution {
public:
    int romanToInt(string s) {
        const string symbol[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        const int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        int length, number = 0,
            n = 0;
        
        for(auto sym : symbol){
            // Go greedy - Roman numerals are represented with as many large symbols as possible
            length = sym.size();
            while(s[0] == sym[0] && (length < 2 || s[1] == sym[1])){
                s.erase(0, length);
                number += values[n];
            }
            n++;
        }
        return number;
    }
};