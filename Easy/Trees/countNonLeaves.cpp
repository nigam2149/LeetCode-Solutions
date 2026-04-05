// Problem: Count Non-Leaf Nodes in Binary Tree
// Link: https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: If has atleast one child return 1, else recurse left + right

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
    int countNonLeaves(Node* root) {
        if(!root) return 0;

        if(!root->left && !root->right) {
            return 0;
        }

        return 1 + countNonLeaves(root->left) + countNonLeaves(root->right);
    }
};