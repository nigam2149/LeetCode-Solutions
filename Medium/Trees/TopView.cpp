// Problem: Top View of Binary Tree
// Platform: GFG
// Difficulty: Medium
// Time Complexity: O(n log n)
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
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        // hd -> node data
        map<int, int> topNode;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // store first node at each horizontal distance
            if (topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode->data;

            if (frontNode->left)
                q.push({frontNode->left, hd - 1});
            if (frontNode->right)
                q.push({frontNode->right, hd + 1});
        }

        for (auto it : topNode)
            ans.push_back(it.second);

        return ans;
    }
};
