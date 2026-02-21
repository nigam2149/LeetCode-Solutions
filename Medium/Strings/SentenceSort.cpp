// Problem: Sorting the Sentence
// Link: https://leetcode.com/problems/sorting-the-sentence/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Extract words with positions, place in array, rebuild sentence

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        int i = 0, n = s.size();
        string temp = "";
        int count = 0;
        
        while(i < n) {
            if(s[i] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp = "";
                count++;
            } else {
                temp += s[i];
            }
            i++;
        }
        
        // Last word
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        count++;

        string res = "";
        for(int i = 1; i < 10; i++) {
            if(ans[i] != "") {
                res += ans[i];
                res += ' ';
            }
        }
        res.pop_back();
        
        return res;
    }
};