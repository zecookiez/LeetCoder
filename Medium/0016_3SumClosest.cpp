/*
 * https://leetcode.com/problems/3sum/
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Time complexity: O(N^2)
 * Memory complexity: O(1)
 *
 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int left, right, sum,
            n = 0;
        vector<vector<int>> output;
        
        for(auto&target : nums){
            
            if(++n > 1 && nums[n - 2] == target)
                continue;
            
            left = n;
            right = nums.size() - 1;
            
            while(left < right){ // Shrink left and right one at a time, balancing around the target as much as possible
                sum = nums[left] + nums[right];
                
                if(sum == -target){
                    output.push_back({target, nums[left++], nums[right--]});
                    
                    while(left < right && nums[left] == nums[left - 1]) // Avoid duplicates
                        left++;
                    while(left < right && nums[right] == nums[right + 1]) // Avoid duplicates
                        right--;
                } else if(sum < -target){
                    left++;
                } else {
                    right--;
                }
            }
        }

        return output;
    }
};