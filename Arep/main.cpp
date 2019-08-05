#include<iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    long int k;
    bool isIt = true;
    cin >> k;
    for(int x = 0; x < (s.length()/2)+1; x++){
        if(s[x] != s[s.length()-x-1]){
            cout << "NO";
            isIt = false;
            break;
        }
    }
    if(isIt){
        cout << "YES";
    }
    cout << 100/199;
    return 0;
}