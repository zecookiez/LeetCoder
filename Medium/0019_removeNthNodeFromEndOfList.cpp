/*
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Given a linked list, remove the n-th node from the end of list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* copy = head;
        ListNode* delay = head;

        while(n--)
            copy = copy->next;
        
        if(copy == NULL)
            return head->next;

        while(copy->next != NULL){
            copy = copy->next;
            delay = delay->next;
        }
        
        delay->next = delay->next->next;
        
        return head;
    }
};