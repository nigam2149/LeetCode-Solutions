// Problem: Preorder Traversal (Iterative)
// Link: https://www.geeksforgeeks.org/problems/preorder-traversal/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - stack
// Approach: Iterative using stack, push right then left

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
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;

        st.push(root);

        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);

            // Push right first so left is processed first
            if(temp->right) st.push(temp->right);
            if(temp->left)  st.push(temp->left);
        }
        return ans;
    }
};