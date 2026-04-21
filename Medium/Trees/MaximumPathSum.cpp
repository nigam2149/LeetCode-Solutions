// Problem: Maximum Path Sum in a Binary Tree
// Link: https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
// Difficulty: Hard
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Postorder, track max path through each node, ignore negative paths

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
    int ans = INT_MIN;

    int func(Node* root) {
        if(!root) return 0;

        // Ignore negative paths
        int l = max(0, func(root->left));
        int r = max(0, func(root->right));

        // Update max path through current node
        ans = max(ans, l + r + root->data);

        // Return max single path to parent
        return max(l, r) + root->data;
    }

    int findMaxSum(Node* root) {
        func(root);
        return ans;
    }
};