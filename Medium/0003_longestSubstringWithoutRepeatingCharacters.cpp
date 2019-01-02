/*
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Time complexity: O(N)
 * Memory complexity: O(1)
 */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool freq[129] = {false}; // Every character is mapped to a unique ASCII value
        int longest    = 0,
            current    = 0,
            left       = 0;
        
        for(char&value : s){
            while(freq[value]){ // Slide the pointer until we don't have duplicates
                freq[s[left++]] = false; // Remove the character
                current--;
            }

            // Use the current character
            current++;
            freq[value] = true;

            // Update the length
            if(current > longest)
                longest = current;
        }
        
        return longest;
    }
};