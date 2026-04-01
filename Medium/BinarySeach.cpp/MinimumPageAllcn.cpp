// Problem: Allocate Minimum Pages
// Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Difficulty: Medium
// Time Complexity: O(n*log(sum))
// Space Complexity: O(1)
// Approach: Binary search on answer, check if k students can read with mid as max pages

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();

        if(k > n) return -1;

        int start = arr[0], end = arr[0];
        int ans = -1;

        // start = max element, end = sum of all elements
        for(int i = 1; i < n; i++) {
            start = max(start, arr[i]);
            end  += arr[i];
        }

        while(start <= end) {
            int mid = start + (end - start) / 2;
            int count = 1, page = 0;

            // Count students needed for mid as max pages
            for(int i = 0; i < n; i++) {
                page += arr[i];
                if(page > mid) {
                    page = arr[i];
                    count++;
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