#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int count = 0;
    if(n > 2){
        count++;
    }else if(n < 3){
        cout << 0;
        return 0;
    }
    cout << n << endl;

    for(long int i = 0; i < )

    
    bool lyginis = n%2 == 0 ? true : false;
    long long int division;
    for(long long int i = 2; i < n/2; i++){
        cout << i << "\n";
        if(lyginis && i == 2){
            i++;
        }
        division = n/i;
        if(division == n-(division*i)){
            count++;
        }
        //if(lyginis) i++;
    }
    cout << count;
    return 0;
}   