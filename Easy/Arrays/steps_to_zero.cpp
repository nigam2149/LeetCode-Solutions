#include <iostream>
using namespace std;

int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0) {
        if (num % 2 == 0) num /= 2;
        else num--;
        steps++;
    }
    return steps;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Steps: " << numberOfSteps(num) << endl;
}

