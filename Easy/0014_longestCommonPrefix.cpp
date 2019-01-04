/*
 * https://leetcode.com/problems/longest-common-prefix/
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Time complexity: O(S) - S being the total number of characters
 * Memory complexity: O(1)
 *
 */

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0) // Don't accidentally index an empty vector
            return "";
        
        int n, right = INT_MAX;
        
        for(auto str : strs){
            
            // Shorten the right side to fit
            if(str.size() < right)
                right = str.size();
            
            // Keep moving n until it isn't a common prefix
            n = 0;
            while(n < right && str[n] == strs[0][n])
                n++;
                
            right = n;
        }
        
        return strs[0].substr(0, right);
    }
};