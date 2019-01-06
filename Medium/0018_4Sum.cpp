/*
 * https://leetcode.com/problems/4sum/
 *
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Time complexity: O(N^3)
 * Memory complexity: O(1)
 *
 */


// Same thing as 3Sum, but with an extra loop

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int left, right, sum, m,
            n = 0;
        vector<vector<int>> output;
        
        for(auto&a : nums){
            
            if(++n > 1 && nums[n - 2] == a)
                continue;
            m = 0;
            
            for(auto&b : nums){
                
                if(m++ < n)
                    continue;
                if(m > n+1 && nums[m - 2] == b)
                    continue;
                
                left = m;
                right = nums.size() - 1;

                while(left < right){ // Shrink left and right one at a time, balancing around the target as much as possible
                    sum = a + b + nums[left] + nums[right];

                    if(sum == target){
                        output.push_back({a, b, nums[left++], nums[right--]});

                        while(left < right && nums[left] == nums[left - 1]) // Avoid duplicates
                            left++;
                        while(left < right && nums[right] == nums[right + 1]) // Avoid duplicates
                            right--;
                    } else if(sum < target){
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return output;
    }
};