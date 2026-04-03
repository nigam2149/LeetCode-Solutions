// Problem: Number of Islands
// Link: https://leetcode.com/problems/number-of-islands/
// Difficulty: Medium
// Time Complexity: O(n * m)
// Space Complexity: O(n * m) (visited array + recursion stack)
// Approach: Traverse grid, whenever we find unvisited land ('1'), 
//           run DFS to mark the whole island → increment count

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to mark all connected land cells
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {

        // Base case: out of bounds OR visited OR water
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1')
            return;

        vis[i][j] = true;

        // Explore 4 directions
        dfs(i - 1, j, vis, grid, n, m); // up
        dfs(i, j + 1, vis, grid, n, m); // right
        dfs(i + 1, j, vis, grid, n, m); // down
        dfs(i, j - 1, vis, grid, n, m); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse entire grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If land and not visited → new island found
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }
};