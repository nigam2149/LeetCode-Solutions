// Problem: Length of Loop in Linked List
// Link: https://www.geeksforgeeks.org/problems/find-the-length-of-the-loop/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Floyd's Cycle Detection + count loop length

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if(slow == fast) {
                int count = 1;
                slow = slow->next;
                while(slow != fast) {
                    slow = slow->next;
                    count++;
                }
                return count;
            }
        }
        // No loop found
        return 0;
    }
};