#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)
        return res;

        queue<TreeNode*>q;
        bool leftToRight=true;
        q.push(root);

        while(!q.empty()){
            vector<int>ans;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            if (leftToRight) {
            // No reverse needed
             leftToRight = false;
            } else {
            reverse(ans.begin(), ans.end());
            leftToRight = true;
            }
            res.push_back(ans);
        }
        return res;
    }
};