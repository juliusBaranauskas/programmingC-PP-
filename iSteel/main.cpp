#include <iostream>

using namespace std;

int main()
{
    int testCases, n;
    cin >> testCases;
    int sum = 0, switches =0;
    bool first = true;
    for(int x = 0; x < testCases; x++){
            if(!first){
            cout << endl;
        }
        cin >> n;
        int numbers[n];
        switches = n-1;
        sum = 0;
        for(int i = 0; i < n; i++){
         cin >> numbers[i];
         sum+=numbers[i];
        }
        cout << "\nSUM = " << sum<<endl;
        if(!first){
            cout << endl;
        }
        if(sum%2==0){
            if(switches!= 0){
               if(switches%2==0){
                cout<<"Bob";
               }else{
               cout<<"Alice";
               }
            }else{
            cout << "Bob";
            }
        }else{
        if(switches!= 0){
               if(switches%2==0){
                cout<<"Alice";
               }else{
               cout<<"Bob";
               }
            }else{
            cout << "Alice";
            }
        }
        first = false;
    }
    return 0;
}
