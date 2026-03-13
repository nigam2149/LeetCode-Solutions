#include <bits/stdc++.h>
using namespace std;

void printPrimes(int n) {
    for(int i = 2; i <= n; i++) {
        bool isPrime = true;
        
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) 
            cout << i << " ";
    }
}

int main() {
    int n = 50;
    printPrimes(n);
    return 0;
}