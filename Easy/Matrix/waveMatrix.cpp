// Problem: Wave Print a Matrix
// Link: https://www.geeksforgeeks.org/problems/wave-print/1
// Difficulty: Easy
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Approach: Column wise traversal, alternate up and down

#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> wave;

    for(int i = 0; i < mCols; i++) {
        // Even column - top to bottom
        if(i % 2 == 0) {
            for(int j = 0; j < nRows; j++) {
                wave.push_back(arr[j][i]);
            }
        }
        // Odd column - bottom to top
        else {
            for(int j = nRows - 1; j >= 0; j--) {
                wave.push_back(arr[j][i]);
            }
        }
    }
    return wave;
}