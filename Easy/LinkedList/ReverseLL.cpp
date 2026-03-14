// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1) - Iterative
// Approach: Three pointers - prev, curr, next

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
    // Iterative Approach
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut = NULL;
        
        while(curr) {
            fut = curr->next;      // Save next
            curr->next = prev;     // Reverse link
            prev = curr;           // Move prev forward
            curr = fut;            // Move curr forward
        }
        
        return prev;
    }
};