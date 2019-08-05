#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int sumMax = 0;
    int happiness1;
    int happiness2;
    int n;
    int z;
    for(int i = 0; i < T; i++){
            if(i != 0){
                cout << endl;
            }
            cin >> n;
            int masyvs[n*2];
            for(z = 0; z< n*2; z++){
                cin >> masyvs[z];
            }
            for(z = 0; z < n; z++){
                if(masyvs[z] + masyvs[2*n-z-1] > sumMax){
                    sumMax = masyvs[z] + masyvs[2*n-z-1];
                }
            }
            cout << sumMax;
            sumMax = 0;
    }
    return 0;
}
