// Problem: Check if Binary Tree is Balanced
// Link: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Postorder, check height difference of left and right subtree

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
    int height(Node* root, bool& isvalid) {
        if(!root) return 0;

        int left  = height(root->left, isvalid);
        int right = height(root->right, isvalid);

        if(abs(left - right) > 1) {
            isvalid = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(Node* root) {
        if(!root) return true;
        bool isvalid = true;
        height(root, isvalid);
        return isvalid;
    }
};