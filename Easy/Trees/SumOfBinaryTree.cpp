// Problem: Sum of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Postorder traversal, add left + right + root

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
    int sumBT(Node* root) {
        if(!root) return 0;

        int leftsum  = sumBT(root->left);
        int rightsum = sumBT(root->right);

        return leftsum + rightsum + root->data;
    }
};