/*
 * https://leetcode.com/problems/generate-parentheses/
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * Time complexity: O(2^N)
 * Memory complexity: O(1)
 *
 */


class Solution {
public:
   void helper(string current, int left, int right, vector<string>&result, int n){
        if(right == n){
            // Done building
            result.push_back(current);
        } else {
            // More open than closed
            if(left > right)
                helper(current + ')', left, right + 1, result, n);
            // Not enough open parantheses
            if(left < n)
                helper(current + '(', left + 1, right, result, n);   
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;  
        helper("", 0, 0, result, n);   
        return result;
    }
};