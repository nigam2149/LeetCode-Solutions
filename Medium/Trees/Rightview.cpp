// Problem: Right View of Binary Tree
// Platform: GFG
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector<int> rightView(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            // first node of each level (right view)
            ans.push_back(q.front()->data);

            int n = q.size();
            while (n--) {
                Node* temp = q.front();
                q.pop();

                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
};
