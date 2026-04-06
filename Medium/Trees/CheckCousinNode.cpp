// Problem: Cousins in Binary Tree
// Link: https://www.geeksforgeeks.org/problems/cousins-of-a-given-node/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n) - queue
// Approach: BFS level order, find parents of x and y, check same level different parent

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
    bool isCousins(Node* root, int x, int y) {
        if(!root) return false;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* parentX = NULL;
            Node* parentY = NULL;
            int size = q.size();

            while(size--) {
                Node* temp = q.front();
                q.pop();

                if(temp->left) {
                    if(temp->left->data == x) parentX = temp;
                    if(temp->left->data == y) parentY = temp;
                    q.push(temp->left);
                }
                if(temp->right) {
                    if(temp->right->data == x) parentX = temp;
                    if(temp->right->data == y) parentY = temp;
                    q.push(temp->right);
                }
            }

            // Same level different parent
            if(parentX && parentY)  return parentX != parentY;
            // Only one found at this level
            if(parentX || parentY)  return false;
        }
        return false;
    }
};