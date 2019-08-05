#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int t;
    int n, m;
    scanf("%d", &t);
    //cin >> t;
    int num;
    int first;
    bool notFound;
    for(int x = 0; x < t; x++){
        //cin >> n >> m;
        scanf("%d", &n);
        scanf("%d", &m);
        notFound = true;
        for(int i = 0; i < n; i++){
            //cin >> num;
            scanf("%d", &num);
            if(num != -1 && notFound){
                first = (num - (i%m)+m)%m;
                notFound = false;
            }
        }
        for(int i = 0; i < n; i++){
            if(first%m == 0){
                first = 0;
            }
            //cout << first << " ";
            printf("%d ", first);
            first++;
        }
        printf("\n");
    }
    return 0;
}