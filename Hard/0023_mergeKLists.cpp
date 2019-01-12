/*
 * https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Time complexity: O(N log K), we do log K comparisons for all the nodes.
 * Memory complexity: O(K)
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
    class customComparison {
    public:
         bool operator() (const ListNode *listA, const ListNode *listB) const {
             return listA->val > listB->val;
         }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *output = new ListNode(0);
        ListNode *node,
                 *copy = output;
        
        priority_queue<ListNode*, vector<ListNode*>, customComparison> queue;
        
        for(auto node : lists) {
            if(node)
                queue.push(node);
        }
        
        while(!queue.empty()) {
            node = queue.top();
            queue.pop();
            
            if(node->next)
                queue.push(node->next);
            
            copy->next = new ListNode(node->val);
            copy = copy->next;
        }
        
        return output->next;
    }
};