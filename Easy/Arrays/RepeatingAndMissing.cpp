// Problem: Missing And Repeating
// Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Encode frequency in same array using index mapping

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Frequency encode karo
        for(int i = 0; i < n; i++) {
            int idx = (arr[i] - 1) % n;
            arr[idx] += n;
        }

        int repeating = -1, missing = -1;

        // Step 2: Freq check karo
        for(int i = 0; i < n; i++) {
            int freq = arr[i] / n;

            if(freq == 2) repeating = i + 1;
            if(freq == 0) missing   = i + 1;
        }

        return {repeating, missing};
    }
};