// Problem: Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy
// Time Complexity: O(n*m log n) - n strings, m avg length
// Space Complexity: O(1)
// Approach: Sort and compare first & last strings

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        string ans = "";
        
        // Sort strings
        sort(strs.begin(), strs.end());
        
        // Compare first and last strings only
        string start = strs[0];
        string last = strs[strs.size() - 1];
        
        int i = 0;
        while(i < start.size() && start[i] == last[i]) {
            ans.push_back(start[i]);
            i++;
        }
        
        return ans;
    }
};