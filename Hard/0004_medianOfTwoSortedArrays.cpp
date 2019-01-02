/*
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Time complexity: O(N + M)
 * Memory complexity: O(1)
 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // We can merge two sorted vectors in O(N + M) time, so why not do that?
        // We don't actually need to build the new vector, just keep the two new numbers for the median 

        int a, b, c, d,
            combinedLength = nums1.size() + nums2.size(),
            currentLength  = 0;
        
        while(currentLength * 2 <= combinedLength){
            
            if(nums1.size()){
                c = nums1[nums1.size() - 1];
            } else {
                // Force nums2 to be popped back
                c = nums2[nums2.size() - 1] - 1;
            }
            
            if(nums2.size()){
                d = nums2[nums2.size() - 1];
            } else {
                // Force nums1 to be popped back
                d = c - 1;
            }
            
            if(c >= d){
                // This one is the next item
                a = b;
                b = c;
                nums1.pop_back();
            } else {
                // This one is the next item
                a = b;
                b = d;
                nums2.pop_back();
            }
            
            currentLength++;
        }
        
        return combinedLength & 1 ? b : (a + b) / 2.0;
    }
};