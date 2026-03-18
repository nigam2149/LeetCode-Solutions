// Problem: Remove Duplicates from Sorted List II
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n) - map (optimized: O(1))
// Approach: Count frequencies, keep only unique nodes

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
        if(head->next==NULL && n==1) return NULL;
        ListNode*curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        ListNode*temp=head;
        ListNode*prev;
        count=count-n;
        if(count==0) return head->next;
        while(count--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};