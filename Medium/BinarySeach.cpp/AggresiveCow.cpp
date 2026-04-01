// Problem: Aggressive Cows
// Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
// Difficulty: Medium
// Time Complexity: O(n*log(max-min))
// Space Complexity: O(1)
// Approach: Binary search on minimum distance, check if k cows can be placed

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int>& stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());

        int st = 1, end = stalls[n - 1] - stalls[0];
        int ans = 0;

        while(st <= end) {
            int mid = st + (end - st) / 2;
            int count = 1, pos = stalls[0];

            // Count cows placed with min distance mid
            for(int i = 1; i < n; i++) {
                if(pos + mid <= stalls[i]) {
                    count++;
                    pos = stalls[i];
                }
            }

            if(count < k) {
                end = mid - 1;
            } else {
                ans = mid;
                st  = mid + 1;
            }
        }
        return ans;
    }
};