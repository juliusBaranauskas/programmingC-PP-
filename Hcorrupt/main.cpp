#include<iostream>

using namespace std;

int main(){
    int t;
    int y;
    cin >> t;
    int m, n;
    int indxGot;
    int freeOnes;
    string num;
    int i;
    for(int x = 0; x < t; x++){
        cin >> n >> m;
        freeOnes = 0;
        indxGot = 0;
        for(i = 0; i < n; i++){
            cin >> num;
            for(y = 0; y < m; y++){
                if(num[y] == '1'){
                    if(i == 0 || y == 0 || i == n-1 || y == m-1){
                        indxGot++;
                    }else{
                        freeOnes++;
                    }
                }
            }
        }
        if(freeOnes+indxGot < 2*n+m*2-4){
            cout <<-1<< endl;
        }else{
            cout << 2*n+m*2-4-indxGot << endl;
        }
    }
}