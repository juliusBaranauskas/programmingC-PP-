#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    int n;
    int maxi, mini;
    int ats;
    int i;
    for(int x = 0; x < t; x++){
        scanf("%d", &n);
        ats = 0;
        int mas[n];
        int tinka[n];
        for(i = 0; i < n; i++){
            scanf("%d", &mas[i]);
            tinka[i] = 0;
        }
        if(n > 2){
            maxi = mas[0];
            for(i = 1; i < n-1; i++){
                if(mas[i] >= maxi){
                    tinka[i] = 1;
                    maxi = mas[i];
                }
            }
            mini = mas[n-1];
            for(i = n-2; i > 0; i--){
                if(mas[i] <= mini){
                    if(tinka[i] == 1){
                        ats++;
                    }
                    mini = mas[i];
                }
            }
        }
        printf("%d\n", ats);
    }
    return 0;
}