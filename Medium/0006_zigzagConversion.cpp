/*
 * https://leetcode.com/problems/zigzag-conversion/
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *  And then read line by line: "PAHNAPLSIIGYIR"
 *
 *  Write the code that will take a string and make this conversion given a number of rows
 * 
 * Time complexity: O(N)
 * Memory complexity: O(N)
 */


class Solution {
public:
    string convert(string s, int numRows) {
        string arr[numRows + 1] = {""};
        string output = "";
        int n = 0,
            d = 1;

        for(char&c : s){
            if(n == 0){
                d = 1;
            } else if(n == numRows - 1) {
                d = -1;
            }
            arr[n] += c;
            if(-1 < n + d && n + d < numRows)
                n += d;
        }
        

        for(string&str : arr)
            output += str;
        
        return output;
    }
};