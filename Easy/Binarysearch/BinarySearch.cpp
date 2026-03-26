// Problem: Binary Search
// Link: https://leetcode.com/problems/binary-search/
// Difficulty: Easy
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Standard iterative binary search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int BS(vector<int>&nums,int target,int st,int end){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        return BS(nums,target,0,nums.size()-1); 
    }
};