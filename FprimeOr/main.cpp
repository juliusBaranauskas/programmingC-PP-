#include<iostream>

using namespace std;


int main(){
    long double n, z;
    cin >> n;
    if(n == 1){
        cout << "No\n";
        return 0;
    }
    z=1;
    while(1){
        z *= 2.0;
        if(z == n){ 
            cout << "Yes\n";
            break;
        }
        if(z > n){
            cout << "No\n";
            break;
        }
    }
    return 0;
}