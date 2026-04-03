// Problem: Max Area of Island
// Link: https://leetcode.com/problems/max-area-of-island/
// Difficulty: Medium
// Time Complexity: O(n * m)
// Space Complexity: O(n * m) (due to visited array + recursion stack)
// Approach: DFS traversal to find connected components (islands) and calculate their area

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS function to calculate area of island
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: out of bounds OR already visited OR water cell
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0)
            return 0;

        vis[i][j] = true;

        // Explore all 4 directions
        return 1 
            + dfs(i + 1, j, grid, vis)
            + dfs(i - 1, j, grid, vis)
            + dfs(i, j + 1, grid, vis)
            + dfs(i, j - 1, grid, vis);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, false));

        // Traverse each cell
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If land and not visited → start DFS
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int area = dfs(i, j, grid, vis);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};