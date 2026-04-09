// Problem: Right View of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - queue
// Approach: BFS level order, push right first, take first node of each level

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> rightView(Node* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            // First node of each level (right pushed first)
            ans.push_back(q.front()->data);

            while(n--) {
                Node* temp = q.front();
                q.pop();

                if(temp->right) q.push(temp->right);
                if(temp->left)  q.push(temp->left);
            }
        }
        return ans;
    }
};