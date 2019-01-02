/*
 * https://leetcode.com/problems/add-two-numbers/
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Time complexity: O(N)
 * Memory complexity: O(N)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *output = new ListNode(0),
                 *copy   = output;
        int sum = 0;
        
        while(l1 || l2 || sum){
            
            // Any more values?
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
             
            // Any more values?
            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            
            // Add value in the list
            copy -> next = new ListNode(sum % 10);
            copy = copy -> next;
            
            // Keep the carry for the next node
            sum /= 10;
        }
        
        return output -> next;
    }
};