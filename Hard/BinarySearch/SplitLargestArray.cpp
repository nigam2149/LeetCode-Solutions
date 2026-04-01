// Problem: Split Array Largest Sum
// Link: https://leetcode.com/problems/split-array-largest-sum/
// Difficulty: Hard
// Time Complexity: O(n*log(sum))
// Space Complexity: O(1)
// Approach: Binary search on answer, check if array can be split into k subarrays

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        if(k > n) return -1;

        int start = 0, end = 0, ans = 0;

        // start = max element, end = sum of all elements
        for(int i = 0; i < n; i++) {
            start = max(start, arr[i]);
            end  += arr[i];
        }

        while(start <= end) {
            int mid = start + (end - start) / 2;
            int pages = 0, count = 1;

            // Count subarrays needed for mid as max sum
            for(int i = 0; i < n; i++) {
                pages += arr[i];
                if(pages > mid) {
                    count++;
                    pages = arr[i];
                }
            }

            if(count <= k) {
                ans   = mid;
                end   = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};