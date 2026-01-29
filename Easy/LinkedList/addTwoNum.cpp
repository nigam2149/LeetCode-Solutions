// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers/
// Difficulty: Medium
// Time Complexity: O(max(m, n))
// Space Complexity: O(max(m, n))
// Approach: Traverse both lists, handle carry

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int sum = carry;
            
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            int digit = sum % 10;
            
            dummy->next = new ListNode(digit);
            dummy = dummy->next;           
        }
        
        return current->next;
    }
};