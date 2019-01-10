/*
 * https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * 
 * Time complexity: O(N)
 * Memory complexity: O(1)
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* output = new ListNode(0);
        ListNode* copy = output;
        
        int a, b;
        
        while(l1 != NULL || l2 != NULL){
            
            a = INT_MAX;
            b = INT_MAX;
            
            if(l1 != NULL){
                a = l1->val;
            }
            
            if(l2 != NULL){
                b = l2->val;
            }
            
            if(a < b){
                copy->next = new ListNode(a);
                l1 = l1->next;
            } else {
                copy->next = new ListNode(b);
                l2 = l2->next;
            }
            
            copy = copy->next;
            
        }
        
        return output->next;
    }
};