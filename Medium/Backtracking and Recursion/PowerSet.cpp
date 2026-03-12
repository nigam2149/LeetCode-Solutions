// Problem: All Possible Non-Empty Subsequences
// Link: https://www.geeksforgeeks.org/print-subsequences-string/
// Difficulty: Medium
// Time Complexity: O(2^n * n log n)
// Space Complexity: O(2^n)
// Approach: Backtracking - exclude empty string

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(int i, string curr, string& s, vector<string>& ans) {
        // Base case
        if(i == s.size()) {
            if(curr != "")  // Only add non-empty subsequences
                ans.push_back(curr);
            return;
        }
        
        // Exclude current character
        find(i + 1, curr, s, ans);
        
        // Include current character
        find(i + 1, curr + s[i], s, ans);
    }
    
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        find(0, "", s, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};