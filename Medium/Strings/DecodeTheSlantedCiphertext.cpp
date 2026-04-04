// Problem: Decode the Slanted Ciphertext
// Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Traverse diagonally column by column, strip trailing spaces

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if(n == 0) return "";

        int cols = n / rows;
        string res = "";

        // Traverse each diagonal starting from each column
        for(int col = 0; col < cols; col++) {
            int i = 0, j = col;
            while(i < rows && j < cols) {
                res += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        // Remove trailing spaces
        while(!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};