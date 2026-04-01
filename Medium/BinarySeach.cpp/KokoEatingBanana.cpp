// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/
// Difficulty: Medium
// Time Complexity: O(n*log(maxPile))
// Space Complexity: O(1)
// Approach: Binary search on speed, check if koko can eat all within h hours

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 0, ans = 0;
        int n = piles.size();

        // end = max pile size
        for(int i = 0; i < n; i++) {
            end = max(end, piles[i]);
        }

        while(start <= end) {
            long long mid   = start + (end - start) / 2;
            long long count = 0;

            // Count hours needed at speed mid
            for(int i = 0; i < n; i++) {
                count += piles[i] / mid;
                if(piles[i] % mid) count++;
            }

            if(count > h) {
                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};