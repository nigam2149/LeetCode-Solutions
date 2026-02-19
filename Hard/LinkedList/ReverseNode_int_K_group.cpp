// Problem: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Difficulty: Hard
// Time Complexity: O(n)
// Space Complexity: O(n/k) - recursion stack
// Approach: Count nodes, reverse k at a time recursively

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
    int count; // Global counter for remaining nodes

    int counting(ListNode* head) {
        if(!head) 
            return 0;
        
        int x = 0;
        while(head) {
            x++;
            head = head->next;
        }
        return x;
    }

    // Reverse k nodes at a time
    ListNode* reverse(ListNode* head, int k) {
        if(count < k) 
            return head;

        int x = k;
        ListNode* curr = head;
        ListNode* fut = NULL;
        ListNode* prev = NULL;
        
        // Reverse k nodes
        while(curr && x--) {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        
        count -= k;
        
        // Recursively reverse next k nodes
        if(fut != NULL) {
            head->next = reverse(fut, k);
        }
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        count = counting(head);
        if(count < k) 
            return head;
        
        return reverse(head, k);        
    }
};