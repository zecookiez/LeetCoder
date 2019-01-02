/*
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Time complexity: O(N^2)
 * Memory complexity: O(1)
 */


/* 
 * An overkill solution would be to use Manacher's Algorithm, which can solve this in O(N).
 *
 * https://tarokuriyama.com/projects/palindrome2.php
 */


class Solution {
public:
    string longestPalindrome(string s) {

        // Go through every center, add on both sides until it stops being a palindrome

        int a, b,
            left = 0,
            longest = 0,
            l_pos   = 0;

        for(;left < s.size();left++){
            
            // Odd length
            
            a = left;
            b = left;
            
            // Keep expanding the center until it isn't a palindrome
            while(0 < a && b < s.size() - 1 && s[a - 1] == s[b + 1]){
                a--;
                b++;
            }
            
            if(b - a + 1 > longest){
                longest = b - a + 1;
                l_pos = a;
            }
            
            // Even length
            
            a = left + 1;
            b = left;
            
            // Keep expanding the center until it isn't a palindrome
            while(0 < a && b < s.size() - 1 && s[a - 1] == s[b + 1]){
                a--;
                b++;
            }
            
            if(b - a + 1 > longest){
                longest = b - a + 1;
                l_pos = a;
            }
        }

        return s.substr(l_pos, longest);
    }
};