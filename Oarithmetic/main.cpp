#include <iostream>

using namespace std;

int main()
{
    int first, dif, x;
    cin >> first >> dif >> x;
    if(dif != 0){
    if((x-first)%dif != 0 || (dif < 0 && first < x) || (dif > 0 && first > x)){
        cout << "X";
    }else{
        cout << ((x-first)/dif)+1;
    }
    }else{
        if(x == first){
            cout << "1";
        }else{
            cout << "X";
        }
    }
    return 0;
}
