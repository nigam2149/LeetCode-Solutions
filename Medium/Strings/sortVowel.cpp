// Problem: Sort Vowels in a String
// Link: https://leetcode.com/problems/sort-vowels-in-a-string/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1) - fixed size arrays
// Approach: Extract vowels, sort them, place back in positions

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        
        // Mark and count lowercase vowels
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
        }
        
        // Mark and count uppercase vowels
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }
        
        // Build sorted vowel string (uppercase first, then lowercase)
        string vowel = "";
        for(int i = 0; i < 26; i++) {
            char c = 'A' + i;
            while(upper[i]--) {
                vowel += c;
            }
        }
        for(int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while(lower[i]--) {
                vowel += c;
            }
        }
        
        // Place sorted vowels back
        int vow = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                s[i] = vowel[vow];
                vow++;
            }
        }
        
        return s;
    }
};