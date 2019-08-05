#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(!n){
        cout << 0;
        return 0;
    }
    int lastHeight, currentHeight, answer = 1;
    for(int x = 0; x < n; x++){
        if(x == 0){
            cin >> lastHeight;
            continue;
        }
        cin >> currentHeight;
        if(currentHeight > lastHeight){
            answer++;
        }
        lastHeight = currentHeight;
    }
    cout << answer;
    return 0;
}