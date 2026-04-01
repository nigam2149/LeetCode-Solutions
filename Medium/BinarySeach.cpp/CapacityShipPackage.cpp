// Problem: Capacity To Ship Packages Within D Days
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Difficulty: Medium
// Time Complexity: O(n*log(sum))
// Space Complexity: O(1)
// Approach: Binary search on answer, check if packages can be shipped within days

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = -1, end = 0;

        // start = max element, end = sum of all elements
        for(int i = 0; i < weights.size(); i++) {
            start = max(start, weights[i]);
            end  += weights[i];
        }

        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            int count = 1, packages = 0;

            // Count days needed for mid as max capacity
            for(int i = 0; i < weights.size(); i++) {
                packages += weights[i];
                if(packages > mid) {
                    count++;
                    packages = weights[i];
                }
            }

            if(count <= days) {
                ans   = mid;
                end   = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};