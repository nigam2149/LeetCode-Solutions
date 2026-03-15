// Problem: Rotate List
// Link: https://leetcode.com/problems/rotate-list/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Find length, calculate rotation, break and reconnect

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(!head || !head->next) return head;

        int count=0;
        ListNode*curr=head;
        while(curr){
            curr=curr->next;
            count++;
        }
        k=k%count;
        if(k==0) return head;
        count-=k;

        curr=head;
        ListNode*prev=NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        }

        prev->next=NULL;
        ListNode*tail=curr;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        head=curr;
        return head;
    }
};