#include<iostream>
using namespace std;

bool checkpal(string str, int start, int end){
    if(start >= end){
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }
    return checkpal(str, start + 1, end - 1);
}

int main(){
    string str = "NAMAN";
    cout << checkpal(str, 0, str.size() - 1);
    return 0;
}


