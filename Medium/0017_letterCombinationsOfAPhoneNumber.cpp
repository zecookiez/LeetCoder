/*
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent
 * 
 * Time complexity: ~O(4^N)
 * Memory complexity: O(1)
 *
 */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0)
            return {};
        
        vector<string> new_comb, combinations = {""};
        string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for(char& c : digits){
            new_comb = {};
            for(auto comb : combinations){
                for(char& l : letters[c - '2']){
                    new_comb.push_back(comb + l);
                }
            }
            combinations = new_comb;
        }
        return combinations;
    }
};