// Problem: Find First and Last Position of Element in Sorted Array
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Difficulty: Medium
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Two binary searches - one for first, one for last position

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
     int first=-1;
     int last=-1;
     int st=0;
     int e=arr.size()-1;
     while(st<=e){
        int mid=e+(st-e)/2;
        if(arr[mid]==target){
            first=mid;
            e=mid-1;
        }
        else if(arr[mid]<target){
            st=mid+1;
        }
        else{
            e=mid-1;
        }
     }
     st=0;
     e=arr.size()-1;
     while(st<=e){
        int mid=e+(st-e)/2;
        if(arr[mid]==target){
            last=mid;
            st=mid+1;
        }
        else if(arr[mid]<target){
            st=mid+1;
        }
        else{
            e=mid-1;
        }
     }
     vector<int>ans;
     ans.push_back(first);
     ans.push_back(last);
     return ans;        
    }
};