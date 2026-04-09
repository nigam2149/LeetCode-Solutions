// Problem: Postorder Traversal (Iterative)
// Link: https://www.geeksforgeeks.org/problems/postorder-traversal/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - stack
// Approach: Reverse of NRL gives LRN, push left then right

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
    vector<int> postOrder(Node* node) {
        stack<Node*> st;
        vector<int> ans;

        st.push(node);

        // NRL traversal
        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);

            if(temp->left)  st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }

        // Reverse NRL = LRN (postorder)
        reverse(ans.begin(), ans.end());
        return ans;
    }
};