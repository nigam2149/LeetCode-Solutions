#include <iostream>
#include <vector>
using namespace std;

int find(int arr[], int index, int n, int target) {
    if (index == n) {
        if (target == 0) {
            return 1;
        }
        return 0;
    }
    
    return find(arr, index + 1, n, target) || find(arr, index + 1, n, target - arr[index]);
}

int main() {
    int arr[] = {2, 4, 1, 8, 7};
    int target = 15;
    cout << find(arr, 0, 5, target) << endl;
    return 0;
}

