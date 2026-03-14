// Problem: Add One to a Number Represented as Linked List
// Link: https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Reverse, add one with carry, reverse back

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* rev(Node* head) {
        Node* prev = NULL;
        Node* fut = NULL;
        Node* curr = head;
        
        while(curr) {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        
        return prev;
    }
    
    Node* addOne(Node* head) {
        // Reverse the linked list
        head = rev(head);
        
        Node* curr = head;
        int carry = 1;
        
        while(curr) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            
            if(carry == 0) 
                break;
            
            // If last node and carry exists, add new node
            if(curr->next == NULL && carry != 0) {
                curr->next = new Node(carry);
                carry = 0;
                break;
            }
            
            curr = curr->next;
        }
        
        // Reverse back to original order
        head = rev(head);
        
        return head;
    }
};