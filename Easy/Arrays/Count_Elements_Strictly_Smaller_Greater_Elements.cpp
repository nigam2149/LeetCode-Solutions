// Problem: Count Elements With Strictly Smaller and Greater Elements
// Link: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Find min/max, count elements in between
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int x:nums){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        int count=0;
        for(int num:nums){
            if(mini < num && num < maxi){
                count++;
            }
        }
        return count;
    }
};