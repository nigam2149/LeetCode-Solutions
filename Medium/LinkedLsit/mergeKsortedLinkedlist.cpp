// Problem: Merge K Sorted Linked Lists
// Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Difficulty: Medium
// Time Complexity: O(n*k*logk)
// Space Complexity: O(logk) - recursion stack
// Approach: Merge sort on array of lists + merge two sorted lists

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

Node* merge(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* head  = dummy;

    // Merge two sorted lists
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            head->next = new Node(head1->data);
            head1 = head1->next;
        } else {
            head->next = new Node(head2->data);
            head2 = head2->next;
        }
        head = head->next;
    }

    if(head1) head->next = head1;
    else       head->next = head2;

    return dummy->next;
}

void mergeSort(vector<Node*>& arr, int start, int end) {
    if(start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    arr[start] = merge(arr[start], arr[mid + 1]);
}

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
        return arr[0];
    }
};