// Problem: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Floyd's Cycle Detection (Slow & Fast Pointers)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;   
    }
};