// Problem: Boundary Traversal of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Queue based - left boundary, leaves, right boundary

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
    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if(!root) return ans;

        ans.push_back(root->data);

        // Left boundary
        Node* temp = root->left;
        while(temp) {
            if(temp->left || temp->right)
                ans.push_back(temp->data);
            if(temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }

        // Leaf nodes using queue
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if(!curr->left && !curr->right) {
                ans.push_back(curr->data);
            }
            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        // Right boundary in reverse
        stack<int> st;
        temp = root->right;
        while(temp) {
            if(temp->left || temp->right)
                st.push(temp->data);
            if(temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};