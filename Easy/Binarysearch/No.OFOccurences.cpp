// Problem: Count Frequency in a Sorted Array
// Link: https://www.geeksforgeeks.org/problems/number-of-occurrences-of-a-given-word/1
// Difficulty: Easy
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Two binary searches - find first and last position of target

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int st = 0, end = arr.size() - 1;
        int first = -1;

        // Find first position
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid] == target) {
                first = mid;
                end = mid - 1;
            }
            if(arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if(first == -1) return 0;

        st = 0; end = arr.size() - 1;
        int last = -1;

        // Find last position
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid] == target) {
                last = mid;
                st = mid + 1;
            }
            if(arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return last - first + 1;
    }
};