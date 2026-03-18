// Problem: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Two pass - count nodes, then remove

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case: single node
        if(head->next == NULL && n == 1) 
            return NULL;
        
        // Count total nodes
        ListNode* curr = head;
        int count = 0;
        while(curr) {
            count++;
            curr = curr->next;
        }
        
        // Calculate position from start
        ListNode* temp = head;
        ListNode* prev = NULL;
        count = count - n;
        
        // If removing head
        if(count == 0) 
            return head->next;
        
        // Traverse to node before target
        while(count--) {
            prev = temp;
            temp = temp->next;
        }
        
        // Remove node
        prev->next = temp->next;
        delete temp;
        
        return head;
    }
};