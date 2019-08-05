#include <iostream>
using namespace std;
    int main(){
        double skaicius;
        cin >> skaicius;
        int n =0;
        while(n<64){
        skaicius*=2;
        if(skaicius>=1){
            cout<<1;
            skaicius-=1;
            }else{
                cout<<0;
            }
            if(n%4==0){ 
                cout <<" ";
            }
            n++;
        }
        return 0;
        }
