#include <iostream>
using namespace std;

int funkcija(int num){
    int sth;
    while(num/=10 > 0){
        sth = y%10;
            if(sth != 0 || sth != 2 || sth != 4 || sth != 6 || sth != 8){
                if(sth != 5){
                    if(y%7 != 0 && y%3 != 0){
                            ans += funkcija(y);
                        }
                }
            }
    }
}

int main()
{
    short int n;
    int l, r, ans = 0;
    cin >> n;
    int sth;
    for(int x = 0; x < n; x++){
        cin >> l >> r;
        for(int y = l; y <= r; y++){
        sth = y%10;
            if(sth != 0 || sth != 2 || sth != 4 || sth != 6 || sth != 8){
                if(sth != 5){
                    if(y%7 != 0 && y%3 != 0){
                            ans += funkcija(y);
                        }
                }
            }
        }
        cout << ans<<endl;
        ans=0;
    }
    return 0;
}
