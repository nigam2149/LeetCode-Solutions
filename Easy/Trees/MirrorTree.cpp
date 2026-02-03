// Problem: Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Recursive mirror check

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
bool isMirror(TreeNode*l,TreeNode*r){
    if(l==nullptr && r==nullptr)
    return true;
    if(l==nullptr || r==nullptr)
    return false;
    if(l->val!=r->val)
    return false;
    return isMirror(l->left,r->right)&& isMirror(l->right,r->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        return true;
        return isMirror(root->left,root->right);   
    }
};