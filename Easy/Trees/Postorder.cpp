// Problem: Binary Tree Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Recursive Postorder (Left-Right-Root)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if(!root)
            return;
        
        postorder(root->left, ans);    // Left
        postorder(root->right, ans);   // Right
        ans.push_back(root->val);      // Root
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};