// Problem: Binary Tree Maximum Path Sum
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Difficulty: Hard
// Time Complexity: O(n)
// Space Complexity: O(h) - recursion stack
// Approach: Postorder, consider all 4 cases: both, one, only root, neeche

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
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_ans       = root->val + l + r;     // both sides + root
        int koi_ek_accha     = max(l, r) + root->val; // one side + root
        int only_root_accha  = root->val;              // only root

        maxSum = max({maxSum, neeche_ans, koi_ek_accha, only_root_accha});

        return max(koi_ek_accha, only_root_accha);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};