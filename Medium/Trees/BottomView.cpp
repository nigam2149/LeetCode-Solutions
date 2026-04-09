// Problem: Bottom View of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Difficulty: Medium
// Time Complexity: O(n*logn)
// Space Complexity: O(n) - map and queue
// Approach: BFS with horizontal distance, overwrite node at each HD (last wins)

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
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        map<int, int> topNode;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {
            pair<Node*, int> p = q.front();
            q.pop();
            Node* temp = p.first;
            int hd     = p.second;

            // Overwrite - last node at each HD wins
            topNode[hd] = temp->data;

            if(temp->left)  q.push({temp->left,  hd - 1});
            if(temp->right) q.push({temp->right, hd + 1});
        }

        for(auto it : topNode) {
            ans.push_back(it.second);
        }
        return ans;
    }
};