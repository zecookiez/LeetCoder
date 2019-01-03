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
        int a, b,
            left = 0,
            longest = 0,
            l_pos   = 0;

        for(;left < s.size();left++){
            
            // Break early if it's impossible to find a longer palindrome
            if((s.size() - left) * 2 <= longest)
                break;
            
            // Odd length
            
            a = left;
            b = left;
            
            while(-1 < a && b < s.size() && s[a] == s[b]){
                // Keep moving pointers
                a--;
                b++;
            }
            
            if(b + ~a > longest){
                longest = b + ~a;
                l_pos = a + 1;
            }
            
            // Even length
            
            a = left;
            b = left + 1;
            
            while(-1 < a && b < s.size() && s[a] == s[b]){
                a--;
                b++;
            }
            
            if(b + ~a > longest){
                longest = b + ~a;
                l_pos = a + 1;
            }
        }

        return s.substr(l_pos, longest);
    }
};