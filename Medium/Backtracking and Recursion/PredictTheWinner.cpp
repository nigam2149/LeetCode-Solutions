// Problem: Find the Winner of the Circular Game (Josephus Problem)
// Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion stack
// Approach: Recursive Josephus formula

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int winner(int n, int k) {
        if(n == 1)  // Base case: only 1 person left
            return 0;  // 0-indexed position
        
        return (winner(n - 1, k) + k) % n;
    }
    
    int findTheWinner(int n, int k) {
        return winner(n, k) + 1;  // Convert to 1-indexed
    }
};