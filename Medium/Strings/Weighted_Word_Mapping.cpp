// Problem: Map Word Weights (Custom problem or contest)
// Link: https://leetcode.com/problems/weighted-word-mapping/description/
// Difficulty: Medium
// Time Complexity: O(n*m) - n words, m avg length
// Space Complexity: O(1)
// Approach: Calculate weight sum for each word, map to character

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        // Create reverse alphabet mapping
        vector<char> arr(26);
        char ch = 'a';
        for(int i = 25; i >= 0; i--) {
            arr[i] = ch;
            ch++;
        }
        
        string ans = "";
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int indi = 0;
            
            // Calculate total weight for current word
            for(int j = 0; j < word.size(); j++) {
                int index = word[j] - 'a';
                indi += weights[index];
            }
            
            // Map weight to character (mod 26)
            indi = indi % 26;
            ans += arr[indi];
        }
        
        return ans;
    }
};