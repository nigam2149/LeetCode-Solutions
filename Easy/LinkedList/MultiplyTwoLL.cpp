// Problem: Multiply Two Linked Lists
// Link: https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1
// Difficulty: Easy
// Time Complexity: O(n+m)
// Space Complexity: O(1)
// Approach: Convert linked lists to numbers then multiply

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
    long long multiplyTwoLists(Node* first, Node* second) {
        long long num1 = 0, num2 = 0;

        // Convert first list to number
        while(first) {
            num1 = num1 * 10 + first->data;
            first = first->next;
        }

        // Convert second list to number
        while(second) {
            num2 = num2 * 10 + second->data;
            second = second->next;
        }

        return (num1 * num2) % 1000000007;
    }
};