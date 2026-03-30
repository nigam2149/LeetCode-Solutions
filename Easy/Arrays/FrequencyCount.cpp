// Problem: Frequency of Array Elements
// Link: https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Direct index mapping, freq[arr[i]-1]++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n, 0);

        for(int i = 0; i < n; i++) {
            freq[arr[i] - 1]++;
        }
        return freq;
    }
};