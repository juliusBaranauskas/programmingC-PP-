#include<iostream>

using namespace std;

int main(){
    int t;
    int n;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n;
        if((n/2)%2 == 0){
            cout << "Second\n";
        }else{
            cout << "First\n";
        }
    }

    return 0;
}