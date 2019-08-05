#include <iostream>


using namespace std;

int main(){
    int a, lastDig;
    int num;
    long int n;
    cin >> n >> a;
    num = a;
    long int first[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    long int last[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;
    for(long int x = 1; x <= n; x++){
        if(x > 1){
            num*=a;
        }
        if(num < 10){
            last[num]++;
            first[num-1]++;
            lastDig = num;
        }else{
            lastDig *= a;
            lastDig = lastDig%10;
            if(num/100 > 0){
                num/=10;
            }
            last[lastDig]++;
            first[(num/10)-1]++;
        }
    }


    for(i = 0; i < 9; i++){
        cout << first[i]<< " ";
    }
    cout << endl;
    for(i = 0; i < 10; i++){
        cout << last[i]<< " ";
    }
    return 0;
}