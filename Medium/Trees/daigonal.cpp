// Problem: Diagonal Traversal of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Queue BFS, keep going right, push left to queue

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
    vector<int> diagonal(Node* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();

            // Keep going right, push left to queue
            while(temp) {
                ans.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                temp = temp->right;
            }
        }
        return ans;
    }
};