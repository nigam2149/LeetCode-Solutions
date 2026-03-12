// Problem: Power Set / All Subsequences of String
// Link: https://www.geeksforgeeks.org/power-set/
// Difficulty: Medium
// Time Complexity: O(2^n * n log n) - 2^n subsets, sorting
// Space Complexity: O(2^n) - storing all subsets
// Approach: Backtracking - include/exclude each character

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void find(int i,string curr,string &s,vector<string>&ans){
      if(i==s.size()){
          ans.push_back(curr);
          return;
      }
      // exclude
      find(i+1,curr,s,ans);
      // include
      find(i+1,curr+s[i],s,ans);
  }
    vector<string> powerSet(string s) {
        vector<string>ans;
        find(0,"",s,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};