// Problem: Check if Two Trees are Identical
// Link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Recursively check data and structure of both trees

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        if(!r1 && !r2) return true;

        if((!r1 && r2) || (r1 && !r2)) return false;

        if(r1->data != r2->data) return false;

        return (isIdentical(r1->left, r2->left) &&
                isIdentical(r1->right, r2->right));
    }
};