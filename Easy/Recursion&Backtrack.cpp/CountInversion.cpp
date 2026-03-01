#include<iostream>
#include<vector>
using namespace std;

int merge(int arr[], int start, int mid, int end) {
    // size = end-start+1
    vector<int> temp;
    int left = start, right = mid + 1;
    int CountInv = 0;
    
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
             left++;
        } else {
            temp.push_back(arr[right]);
            right++;
            CountInv += (mid - left + 1); // Count inversions
        }
    }

    // left is not empty yet
    while (left <= mid) {
        temp.push_back(arr[left]);
         left++;
    }
    
    // right is not empty yet
    while (right <= end) {
        temp.push_back(arr[right]);
       right++;
    }

    // put the value of temp in arr
    int index = 0;
    while (start <= end) {
        arr[start] = temp[index];
        start++, index++;
    }
    return CountInv;
}

int mergesort(int arr[], int start, int end) {
    int CountInv = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Count inversions in the left and right subarrays
        int leftInv = mergesort(arr, start, mid);
        int rightInv = mergesort(arr, mid + 1, end);

        // Count inversions during the merge step
        int CountMerge = merge(arr, start, mid, end);

        // Total inversion count
        CountInv = leftInv + rightInv + CountMerge;
    }
    return CountInv;
}



int main() {
    int arr[] = {1,3,5,10,2,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=mergesort(arr, 0,n-1);
    cout<<count;
}