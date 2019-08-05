#include<iostream>
    
using namespace std;

int main(){
    double a,b,c,d,e;
    cin >> d >> e;
    if(d < e){ // a <= b
        a = d;
        b = e;
    }else{
        b = d;
        a = e;
    }
    double num;
    double sum;
    if((int)(a+b) %3 == 0){
        num = 0;
    }else if((int)(a+b+1) % 3 == 0){
        num = 1;
    }else{
        num = 2;
    }
    sum = a+b+num;
    while(true){
        if(num <= a){
            if(sum/3 == a){
                cout << num;
                break;
            }
        }
        if(num >= a && num <= b){
            if(sum/3 == num){
                cout << num;
                break;
            }
        }
        if(num >= a && num >= b){
            if(sum/3 == b){
                cout << num;
                break;
            }
        }
        num+=3;
        sum+=3;
    }
    return 0;
}