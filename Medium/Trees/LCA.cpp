// Problem: Lowest Common Ancestor of a Binary Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Recursive search in left and right subtrees

// Problem: Lowest Common Ancestor of a Binary Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Postorder, if both sides return non-null then root is LCA

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)          return NULL;
        if(root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right)   return root;
        else if(left)       return left;
        else if(right)      return right;
        else                return NULL;
    }
};