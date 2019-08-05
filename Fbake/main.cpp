#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;

int main()
{
    int T;
    long double areas[3];
    cin >> T;
    long double sumTwo = 0;
    for(int x = 0; x < T; x++){
        sumTwo = 0;
        cin >> areas[0] >> areas[1] >> areas[2];
        sumTwo += (sqrt(areas[0]/PI)*2)+(sqrt(areas[1]/PI)*2);
        if(sumTwo < (sqrt(areas[2]/PI)*2)){
            cout << "TAK\n";
        }else{
            cout << "NIE\n";
        }
    }
    return 0;
}
