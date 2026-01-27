// Problem: Find the Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Algorithm: Floyd's Cycle Detection (Tortoise and Hare)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];
        
        do {
            slow = arr[slow];         
            fast = arr[arr[fast]];      
        } while(slow != fast);
        
        slow = arr[0];
        while(slow != fast) {
            slow = arr[slow];           
            fast = arr[fast];           
        }
        
        return slow;
    }
};