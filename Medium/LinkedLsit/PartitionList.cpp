// Problem: Partition List
// Link: https://leetcode.com/problems/partition-list/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1) - optimized (your version uses O(n))
// Approach: Two dummy nodes for less and greater, merge at end

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      vector<int>ans;
      vector<int>greater;
      int count=0;
      ListNode*L=head;
      while(L){
        if(L->val<x){
            ans.push_back(L->val);
        }
        else{
            greater.push_back(L->val);
        }
        L=L->next;
      }

      for(int i=0;i<greater.size();i++){
        ans.push_back(greater[i]);
      }

     if (ans.empty()) return nullptr;

      ListNode*curr=new ListNode(ans[0]);
      ListNode*Li=curr;

      for(int i=1;i<ans.size();i++){
        Li->next=new ListNode(ans[i]);
        Li=Li->next;
      }
      Li->next=nullptr;
      return curr;
    }
};