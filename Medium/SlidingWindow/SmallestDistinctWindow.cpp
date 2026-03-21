// Problem: Smallest Window Containing All Distinct Characters
// Link: https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
// Difficulty: Hard
// Time Complexity: O(n)
// Space Complexity: O(1) - fixed size array (256)
// Approach: Sliding window with two pointers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubString(string& str) {
        vector<int> count(256, 0);
        int first = 0, second = 0;
        int len = str.size();
        int diff = 0;
        
        // Calculate total unique characters
        while(first < str.size()) {
            if(count[str[first]] == 0)
                diff++;
            
            count[str[first]]++;
            first++;
        }
        
        // Reset for sliding window
        for(int i = 0; i < 256; i++) {
            count[i] = 0;
        }
        first = 0;
        
        while(second < str.size()) {
            // Expand window until all distinct chars found
            while(diff && second < str.size()) {
                if(count[str[second]] == 0)
                    diff--;
                
                count[str[second]]++;
                second++;
            }
            
            // Update minimum length
            len = min(len, second - first);
            
            // Shrink window from left
            while(diff != 1) {
                len = min(len, second - first);
                count[str[first]]--;
                
                if(count[str[first]] == 0)
                    diff++;
                
                first++;
            }
        }
        
        return len;
    }
};