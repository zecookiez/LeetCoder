/*
 *
 *  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *  
 *  Overall complexity: O(n)
 *
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++){
            // Is the other half of target already found?
            if(seen.find(target - nums[i]) != seen.end()){
                // Return the two indices
                return {std::find(nums.begin(), nums.end(), target - nums[i]) - nums.begin(), i};
            }
            // Add the first half into the set
            seen.insert(nums[i]);
        }
        
        // Nothing found just in case
        return {-1, -1};
    }
};