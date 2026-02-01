// Problem: Binary Tree Zigzag Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n) - queue

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
        return {};
      vector<vector<int>>ans;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        int size=q.size();
        vector<int>res;
        for(int i=0;i<size;i++){
            TreeNode*temp=q.front();
            q.pop();
            res.push_back(temp->val);
            if(temp->left)
            q.push(temp->left);            
            if(temp->right)
            q.push(temp->right);

        }
        ans.push_back(res);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};