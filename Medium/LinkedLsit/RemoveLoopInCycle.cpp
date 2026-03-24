// Problem: Remove Loop in Linked List
// Link: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Floyd's Cycle Detection + find loop start + remove loop

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        if(head == NULL || head->next == NULL) return;

        Node* slow = head;
        Node* fast = head;

        // Detect loop
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        // No loop found
        if(fast == NULL || fast->next == NULL) return;

        // Find loop start
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Find last node of loop
        while(slow->next != fast) {
            slow = slow->next;
        }

        // Remove loop
        slow->next = NULL;
    }
};