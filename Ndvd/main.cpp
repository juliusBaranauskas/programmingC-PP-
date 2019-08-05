#include <iostream>

using namespace std;

int main()
{
    short int maxStock, stockCurrently, transactions;
    string name;
    cin >> name;
    cin >> maxStock >>  stockCurrently;
    cin >> transactions;
    char letter;
    int number;
    for(int x = 0; x < transactions; x++){
        cin >> letter;
        if(letter == 'S'){
            cin >> number;
            if(number > stockCurrently){    stockCurrently = 0;}
            else{   stockCurrently-=number;}
        }else{
            cin >> number;
            if(number+stockCurrently > maxStock){   stockCurrently = maxStock;}
            else{   stockCurrently+=number;}
        }
    }
    cout << name;
    cout << " " <<stockCurrently;
    return 0;
}
