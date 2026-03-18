// Problem: Flatten Binary Tree to Linked List
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1) - Morris-like traversal
// Approach: Move left subtree to right, connect rightmost to old right

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            // left does not exist
            if(!root->left){
                root=root->right;
            }else{
                // left exist
                TreeNode*curr=root->left;
                while(curr->right)
                curr=curr->right;

                curr->right=root->right;
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
        }
    }
};