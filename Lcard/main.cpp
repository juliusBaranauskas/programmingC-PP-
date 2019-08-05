#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    int a = 1;
    int inc = 2;
    bool one = false;
    while(a <= n){
        if(a == n){
            one = true;
            break;
        }
        a+=inc;
        inc+=1;
    }
    if(one){
        cout << 1;
    }else{
        cout << 2;
    }
    return 0;
}