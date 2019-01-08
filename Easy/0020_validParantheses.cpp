/*
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * 
 * Time complexity: O(N)
 * Memory complexity: O(N)
 *
 */

class Solution {
public:
    bool isValid(string s) {

        vector<char> stack = {'A'}; // Filler character to prevent indexing an empty vector

        for(char& i : s){
            if(i == '}'){

                if(stack[stack.size() - 1] != '{')
                    return false;
                stack.pop_back();

            } else if(i == ')'){

                if(stack[stack.size() - 1] != '(')
                    return false;
                stack.pop_back();

            } else if(i == ']'){

                if(stack[stack.size() - 1] != '[')
                    return false;
                stack.pop_back();

            } else {
                stack.push_back(i);
            }
        }
        return stack.size() == 1;
    }
};