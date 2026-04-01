// Problem: Painter's Partition
// Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// Difficulty: Medium
// Time Complexity: O(n*log(sum))
// Space Complexity: O(1)
// Approach: Binary search on answer, check if k painters can paint with mid as max length

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int start = -1, end = 0;

        // start = max element, end = sum of all elements
        for(int i = 0; i < arr.size(); i++) {
            start = max(start, arr[i]);
            end  += arr[i];
        }

        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            int count = 1, pos = arr[0];

            // Count painters needed for mid as max length
            for(int i = 1; i < arr.size(); i++) {
                if(pos + arr[i] <= mid) {
                    pos += arr[i];
                } else {
                    count++;
                    pos = arr[i];
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