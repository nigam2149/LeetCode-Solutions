// Problem: Detect Loop in Linked List
// Link: https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Floyd's Cycle Detection (Slow & Fast pointer)

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
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) // Loop detected
                return true;
        }
        return false;
    }
};