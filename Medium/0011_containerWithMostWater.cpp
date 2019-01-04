/*
 *  https://leetcode.com/problems/container-with-most-water/
 *
 *  Given n non-negative integers a1, a2, ..., aN , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *  
 *  Overall complexity: O(N)
 *  Memory complexity: O(1)
 *
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // Have two pointers on both sides, keep reducing the width
        //   going greedy, shorten the side with the current shorter height
        
        
        int area,
            left = 0,
            right = height.size() - 1,
            max = 0;
        
        while(left < right){
            
            area = right - left;
            
            if(height[left] > height[right])
                area *= height[right--]; // Reduce the right side
            else
                area *= height[left++]; // Reduce the left side
            
            if(area > max)
                max = area;
        }
        
        return max;
    }
};