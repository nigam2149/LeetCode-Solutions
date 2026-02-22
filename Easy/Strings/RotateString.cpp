// Problem: Rotate String
// Link: https://leetcode.com/problems/rotate-string/
// Difficulty: Easy
// Time Complexity: O(n²)
// Space Complexity: O(n)
// Approach: Try all rotations, check if matches goal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) 
            return false;

        int n = s.size();
        for(int i = 0; i < n; i++) {
            string temp = s.substr(i + 1) + s.substr(0, i + 1);
            if(temp == goal) 
                return true;
        }
        
        return false;
    }
};