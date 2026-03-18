// Problem: Remove Duplicates from Sorted List
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Keep one copy, skip consecutive duplicates

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        
        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                // Skip duplicate
                curr->next = curr->next->next;
            } else {
                // Move to next
                curr = curr->next;
            }
        }
        
        return head; 
    }
};