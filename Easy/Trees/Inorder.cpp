// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack, h = height
// Approach: Recursive Inorder (Left-Root-Right)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root)
            return;
        
        inorder(root->left, ans);      // Left
        ans.push_back(root->val);      // Root
        inorder(root->right, ans);     // Right
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};