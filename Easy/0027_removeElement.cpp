/*
 * https://leetcode.com/problems/remove-element/
 *
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * 
 * Time complexity: O(N)
 * Memory complexity: O(1)
 *
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pointer = 0;
        for(auto num : nums){
            if(num != val)
                nums[pointer++] = num;
        }
        
        return pointer;
    }
};