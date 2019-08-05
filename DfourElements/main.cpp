#include <iostream>
#include <vector>
using namespace std;

int main()
{
    short int n, sum;
    int l, r;
    vector<int> elements;
    cin >> n >> sum;
    int ans = 0;
    for(int x = 0; x < n; x++){
        cin >> l >> r;
        for(int y = l; y <= r; y++){    elements.push_back(y);  }
    }
    if(elements.size() > 3){
    for(int x = elements.size()-1; x >= 3; x--){

        if(elements[x] <= sum-3){
        for(int y = x-1; y >= 2; y--){

            if(elements[x]+elements[y] <= sum-1){
            for(int i = y-1; i >= 1; i--){

                if(elements[x]+elements[y]+elements[i] <= sum){
                for(int j = i-1; j >= 0; j--){

                    if(elements[x]+elements[y]+elements[i]+elements[j] == sum){
                        ans++;
                    }
                }
                }
            }
            }
        }
        }
    }
    }
    cout << ans;
    return 0;
}
