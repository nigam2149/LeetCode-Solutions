#include <bits/stdc++.h>
using namespace std;

vector<int> rowMajor(vector<vector<int>>& arr, int nRows, int mCols) {
    vector<int> ans;

    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < mCols; j++) {
            ans.push_back(arr[i][j]);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> row = rowMajor(arr, 3, 3);
    for(int x : row) cout << x << " ";
    return 0;
}