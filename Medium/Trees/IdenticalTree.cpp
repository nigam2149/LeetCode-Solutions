// Problem: Check if Two Trees are Identical
// Source: GfG
// Difficulty: Medium
// Time Complexity: O(n) - n is number of nodes
// Space Complexity: O(h) - h is height of tree (due to recursion)
// Approach: Recursively compare nodes of both trees

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
    bool isIdentical(Node* r1, Node* r2) {
        if(!r1 && !r2) 
            return true;
        if((!r1 && r2) || (r1 && !r2)) 
            return false;
        if(r1->data != r2->data) 
            return false;
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};
