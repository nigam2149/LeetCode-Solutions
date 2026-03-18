// Problem: Reverse Linked List II
// Link: https://leetcode.com/problems/reverse-linked-list-ii/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Reverse sublist between left and right positions

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right)
        return head;

        ListNode*prev=NULL;
        ListNode*curr=head;
        int pos=1;
        while(pos<left){
            prev=curr;
            curr=curr->next;
            pos++;
        }
        ListNode*leftp=prev;// left se pahle wala node
        ListNode*tail=curr;// left node
        ListNode*next=NULL;
        while(pos<=right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            pos++;
        }
        if (leftp!=NULL)
            leftp->next = prev; // left se pehle wale ko new head se jodo
        else
            head=prev;        // agar left=1 tha

        tail->next = curr;  
        return head;      
    }
};