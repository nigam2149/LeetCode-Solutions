// Problem: Min Cost Climbing Stairs
// Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1) - modifying input array
// Approach: Dynamic Programming (Bottom-up)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2)
        return min(cost[0],cost[1]);
        // i<n bcoz n wala not included
        for(int i=2;i<n;i++){
            cost[i]=cost[i]+min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};