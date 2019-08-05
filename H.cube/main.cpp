#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned short int n;
    cin >> n;
    unsigned long int answer;
    for (int x = 0; x < n; x++) {
        if(x != 0){
            cout << endl;
        }
        unsigned long int area;
        cin >> area;
        answer = sqrt(area/6);
        if(area < 6){
            answer = 1;
        }
        cout << answer;
    }
    return 0;
}
