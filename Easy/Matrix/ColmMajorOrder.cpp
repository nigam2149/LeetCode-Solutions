#include <bits/stdc++.h>
using namespace std;

vector<int> colMajor(vector<vector<int>>& arr, int nRows, int mCols) {
    vector<int> ans;

    for(int j = 0; j < mCols; j++) {
        for(int i = 0; i < nRows; i++) {
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

    vector<int> col = colMajor(arr, 3, 3);
    for(int x : col) cout << x << " ";
    return 0;
}