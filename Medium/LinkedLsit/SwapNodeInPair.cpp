// Problem: Swap Nodes in Pairs
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Iterative swapping with pointer manipulation

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
    ListNode* swapPairs(ListNode* head) {
        // Base case: empty or single node
        if(!head || head->next == NULL)
            return head;
        
        ListNode* prev = NULL;
        ListNode* first = head;
        ListNode* sec = head->next;
        
        while(first && sec) {
            ListNode* third = sec->next;
            
            // Swap first and second
            sec->next = first;
            first->next = third;
            
            // Connect previous pair to current pair
            if(prev != NULL) {
                prev->next = sec;
            } else {
                head = sec;  // Update head for first swap
            }
            
            // Update pointers for next iteration
            prev = first;
            first = third;
            
            if(third != NULL)
                sec = third->next;
            else
                sec = NULL;
        }
        
        return head;
    }
};