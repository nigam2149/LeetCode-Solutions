// Problem: Flatten a Linked List
// Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Difficulty: Medium
// Time Complexity: O(n*m)
// Space Complexity: O(1)
// Approach: Merge two sorted lists iteratively across all columns

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* merge(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* head  = dummy;

    // Merge two sorted bottom lists
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            head->bottom = new Node(head1->data);
            head1 = head1->bottom;
        } else {
            head->bottom = new Node(head2->data);
            head2 = head2->bottom;
        }
        head = head->bottom;
    }

    if(head1) head->bottom = head1;
    else       head->bottom = head2;

    return dummy->bottom;
}

class Solution {
  public:
    Node* flatten(Node* root) {
        Node* head1, *head2, *head3;

        while(root->next) {
            head1 = root;
            head2 = root->next;
            head3 = root->next->next;

            root       = merge(head1, head2);
            root->next = head3;
        }
        return root;
    }
};