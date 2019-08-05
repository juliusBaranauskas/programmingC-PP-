#include <iostream>
#include <string>
using namespace std;

int main()
{
    short int currentHouse;
    cin >> currentHouse;
    char combination;
    bool visited[20];
    bool illegal = false;
    for(int x = 0; x < 20; x++){ visited[x] = false;}    visited[currentHouse-1] = true;
    short int i = 0, number;

    while(i < 22){
    cin >> combination;
        cin.ignore();

    if(combination == '\n'){  break;}
    cin >> number;

        if(combination == 'U'){  if(currentHouse+number < 21 && !visited[currentHouse+number-1]){     visited[currentHouse+number-1] = true;   currentHouse+=number;}else{  cout << "illegal";  illegal = true;  break;}}
   else if(combination == 'D'){  if(currentHouse-number > 0  && !visited[currentHouse-number-1]){     visited[currentHouse-number-1] = true;   currentHouse-=number;}else{  cout << "illegal";  illegal = true;  break;}}
        i++;
    }

    bool none = true;
    if(!illegal){
    for(int x = 0; x < 20; x++){
        if(!visited[x]){
            cout << x+1<<" ";
            none = false;
        }
    }
    if(none){
        cout << "none";
    }
    }
    return 0;
}
