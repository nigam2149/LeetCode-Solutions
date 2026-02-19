// Problem: Count Common Words with One Occurrence
// Link: https://leetcode.com/problems/count-common-words-with-one-occurrence/
// Difficulty: Medium
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
// Approach: Use hash maps to count frequencies, check common words with freq 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp1, mp2;
        
        // Count frequencies in words1
        for(int i = 0; i < words1.size(); i++) {
            mp1[words1[i]]++;
        } 
        
        // Count frequencies in words2
        for(int i = 0; i < words2.size(); i++) {
            mp2[words2[i]]++;
        }
        
        int count = 0;
        
        // Check common words with exactly 1 occurrence in both
        for(auto it : mp1) {
            if(it.second == 1 && mp2[it.first] == 1) {
                count++;
            }
        }
        
        return count;
    }
};