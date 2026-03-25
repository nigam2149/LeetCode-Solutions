// Problem: Reverse a Linked List in Groups of K
// Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n/k) - recursion stack
// Approach: Recursive reversal of every k nodes

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

int counting(Node* head) {
    if(!head) return 0;
    int x = 0;
    while(head) { x++; head = head->next; }
    return x;
}

Node* reverse(Node* head, int k) {
    int x = k;
    Node* curr = head;
    Node* fut  = NULL;
    Node* prev = NULL;

    // Reverse k nodes
    while(curr && x--) {
        fut        = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = fut;
    }

    // Recursively reverse remaining
    if(fut != NULL) {
        head->next = reverse(fut, k);
    }

    return prev;
}

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        int count = counting(head);
        if(count < k) return head;
        return reverse(head, k);
    }
};