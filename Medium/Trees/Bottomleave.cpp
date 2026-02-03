// Problem: Find Bottom Left Tree Value
// Link: https://leetcode.com/problems/find-bottom-left-tree-value/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)-queue
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
        return -1;

        queue<TreeNode*>q;
        q.push(root);
        int leftVal=q.front()->val;

        while(!q.empty()){
            int size=q.size();
            leftVal=q.front()->val;
            
            while(size--){
                TreeNode*temp=q.front();
                q.pop();

                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);                
            }
        }
        return leftVal;
    }
};