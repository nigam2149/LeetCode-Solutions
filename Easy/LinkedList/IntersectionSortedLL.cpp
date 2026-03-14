// Problem: Intersection of Two Sorted Linked Lists
// Link: https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
// Difficulty: Easy
// Time Complexity: O(m + n)
// Space Complexity: O(min(m, n)) - result list
// Approach: Two pointers, add common elements

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* dummy = new Node(0);  // Dummy node
        Node* tail = dummy;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->data < head2->data) {
                head1 = head1->next;
            } 
            else if(head1->data > head2->data) {
                head2 = head2->next;
            } 
            else {
                // Data same hai, add to intersection list
                tail->next = new Node(head1->data);
                tail = tail->next;
                
                // Move both pointers
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        
        // Return list after dummy node
        return dummy->next; 
    }
};