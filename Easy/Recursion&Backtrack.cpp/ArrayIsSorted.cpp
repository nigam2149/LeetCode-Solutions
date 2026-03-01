#include<iostream>
using namespace std;

bool isSorted(int arr[],int n){
    // base case hai ye KYoki agar arr ki size n=2 (n-1=1) (n-2=0) further aage nahi jayenge to base case lagana jaruri hai
    if(n==0|| n==1){
        return true;
    }
return arr[n-1]>=arr[n-2] && isSorted(arr,n-1);
}

int main() {
    int arr[] = {1, 2, 3, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted(arr, n) << endl;
    return 0;
}