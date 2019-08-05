#include <iostream>
using namespace std;

int main()
{
    int n, price;
    cin >> n >> price;
    int sum=n;
    int arr[n];
    int realN = n;
    int x;
    int xReg = 0;
    int lowest, highest;
    for(x = 0; x < n; x++){
        cin >> arr[x];
        if(!(arr[x] < price)){
            x--;
            realN--;
        }else{
        if(!x){highest = arr[x];}
        if(arr[x] > highest && arr[x] < price){ highest = arr[x]; highestInd = x;}
        }
    }

    while(true){
        for(x = 0; x < realN; x++){
            if(arr[x] >)
        }
    }



    for(x = 0; x < n; x++){
        if(arr[x] < price){
            if(xReg){
                if(xReg + arr[x] > price){
                    sum--;
                }
            xReg = (xReg >arr[x])?  xReg : arr[x];
        }else{
            xReg = arr[x];
        }
        }else{
            sum--;
        }
    }
    if(n == 1 || sum == 0){
        sum = 1;
    }
    cout << endl << sum;
    return 0;
}
