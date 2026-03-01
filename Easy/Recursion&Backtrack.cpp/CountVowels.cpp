#include<iostream>
using namespace std;

int count(string str, int index) {
    if(index == -1) {
        return 0;
    }
    if(str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u') {
        return 1 + count(str, index - 1);
    }
    return count(str, index - 1);
}

int main() {
    string str = "naman";
    cout << count(str, str.size() - 1) << endl;
    return 0;
}
