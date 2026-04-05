// Problem: Count Leaves in Binary Tree
// Link: https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: If no children return 1, else recurse left + right

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
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        if(!root) return 0;
        if(!root->left && !root->right){
            return 1;
        }
        return countLeaves(root->left) + countLeaves(root->right);
    }
};