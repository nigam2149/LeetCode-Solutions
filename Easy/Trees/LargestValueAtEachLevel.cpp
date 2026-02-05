// Problem: Find Largest Value in Each Tree Row
// Source: GfG
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(h) - h is height of tree
// Approach: Level order traversal, track max at each level

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void traverse(Node* root, vector<int>& ans) {
        if(!root) return;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;
            
            while(size--) {
                Node* temp = q.front();
                q.pop();
                maxi = max(maxi, temp->data);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            ans.push_back(maxi);
        }
    }
    
    vector<int> largestValues(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
