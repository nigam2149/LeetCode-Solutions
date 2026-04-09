// Problem: Inorder Traversal (Iterative)
// Link: https://www.geeksforgeeks.org/problems/inorder-traversal/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - stack
// Approach: Iterative using stack, go left first then root then right

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
    vector<int> inOrder(Node* root) {
        stack<Node*> st;
        vector<int> ans;
        Node* curr = root;

        while(curr || !st.empty()) {

            // Go as left as possible
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);

            // Move to right
            curr = curr->right;
        }
        return ans;
    }
};