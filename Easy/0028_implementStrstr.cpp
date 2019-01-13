/*
 * https://leetcode.com/problems/implement-strstr/
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Time complexity: O(N * S), S being the length of the pattern
 * Memory complexity: O(1)
 *
 */


// A more efficient solution would be using Rabin-karp, KMP, or the Z function, all 3 of which can perform in linear-time.

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};