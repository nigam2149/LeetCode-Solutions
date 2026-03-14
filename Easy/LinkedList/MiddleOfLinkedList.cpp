// Problem: Delete Middle Node of Linked List
// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Count nodes, find middle, delete

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* deleteMid(Node* head) {
        // Edge cases: empty or single node
        if(!head || !head->next) {
            return nullptr;
        }
        
        // Count total nodes
        int count = 0;
        Node* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }
        
        // Find middle position
        count /= 2;
        
        // Traverse to node before middle
        Node* curr = head;
        Node* prev = NULL;
        while(count--) {
            prev = curr;
            curr = curr->next;
        }
        
        // Delete middle node
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
    
    // Alternative: Two-pointer approach (Faster - single pass)
    /*
    Node* deleteMid(Node* head) {
        if(!head || !head->next) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        delete slow;
        
        return head;
    }
    */
};