// Problem: Sqrt(x)
// Link: https://leetcode.com/problems/sqrtx/
// Difficulty: Easy
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Binary search, track answer when mid*mid <= x

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int st=0,e=x,ans;
        while(st<=e){
            long long mid=st+(e-st)/2;
            if(mid*mid==x){
                ans=mid;
                break;
            }
            else if(mid*mid<x){
                ans=mid;
                st=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans; 
    }
};