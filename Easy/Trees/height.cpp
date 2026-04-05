// Problem: Height of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Postorder, return 1 + max of left and right height

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
    int height(Node* root) {
        if(!root) return -1;

        return 1 + max(height(root->left), height(root->right));
    }
};