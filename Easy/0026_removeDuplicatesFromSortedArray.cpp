/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
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
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty())
            return 0;
        
        int pos = 0;
        
        for(auto num : nums)
            if(num != nums[pos])
                nums[++pos] = num;
        
        return pos + 1;
    }
};