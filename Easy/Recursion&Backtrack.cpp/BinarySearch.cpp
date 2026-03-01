#include<iostream>
using namespace std;

int binary(int arr[], int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == tar) {
            return mid;
        }
        if (arr[mid] < tar) {
            return binary(arr, tar, mid + 1, end);
        } else {
            return binary(arr, tar, st, mid - 1);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int tar = 4;
    int n = 6;
    int result = binary(arr, tar, 0, n - 1); 
    cout << "Element found at index: " << result << endl;  // Print the result
    return 0;
}