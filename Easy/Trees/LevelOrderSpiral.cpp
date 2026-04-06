// Problem: Spiral Order Traversal of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n) - two stacks
// Approach: Two stacks, alternate between R to L and L to R

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
    vector<int> findSpiral(Node* root) {
        stack<Node*> s1; // R to L
        stack<Node*> s2; // L to R
        vector<int> ans;

        s1.push(root);

        while(!s1.empty() || !s2.empty()) {

            // R to L
            if(!s1.empty()) {
                while(!s1.empty()) {
                    Node* temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->data);

                    if(temp->right) s2.push(temp->right);
                    if(temp->left)  s2.push(temp->left);
                }
            }
            // L to R
            else {
                while(!s2.empty()) {
                    Node* temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->data);

                    if(temp->left)  s1.push(temp->left);
                    if(temp->right) s1.push(temp->right);
                }
            }
        }
        return ans;
    }
};