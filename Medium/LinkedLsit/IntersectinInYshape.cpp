// Problem: Intersection Point in Y Shaped Linked Lists
// Link: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
// Difficulty: Medium
// Time Complexity: O(n+m)
// Space Complexity: O(1)
// Approach: Find lengths, advance longer list, then move together

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
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* curr1 = head1;
        Node* curr2 = head2;
        int count1 = 0, count2 = 0;

        // Find lengths
        while(curr1) { count1++; curr1 = curr1->next; }
        while(curr2) { count2++; curr2 = curr2->next; }

        curr1 = head1;
        curr2 = head2;

        // Advance longer list
        while(count1 > count2) { count1--; curr1 = curr1->next; }
        while(count1 < count2) { count2--; curr2 = curr2->next; }

        // Move together until intersection
        while(curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr2;
    }
};