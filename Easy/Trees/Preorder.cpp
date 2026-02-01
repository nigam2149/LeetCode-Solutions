// Problem: Binary Tree Preorder Traversal
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Recursive Preorder (Root-Left-Right)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if(!root)
            return;
        
        ans.push_back(root->val);      // Root
        preorder(root->left, ans);     // Left
        preorder(root->right, ans);    // Right
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};