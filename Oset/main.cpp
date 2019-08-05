#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int membs[n];
    int minMemb;
    bool yraNelyginis = false;
    for(int x = 0; x < n; x++){
        cin >> membs[x];
        if(x == 0){
            minMemb = membs[x];
        }
        if(membs[x] < minMemb){
            minMemb = membs[x];
        }
        if(membs[x] % 2 != 0){
            yraNelyginis = true;
        }
    }
    int j;
    int i;
    bool nope;
    int count = 0;
    vector<int> dalikliai;
    dalikliai.clear();
    if(yraNelyginis){
        i = 3;
        while(i <= minMemb){
            j = 0;
            nope = false;
            while(j < n){
                if(membs[j] % i != 0){
                    nope = true;
                    break;
                }
                j++;
            }
            if(!nope){
                dalikliai.push_back(i);
                count++;
            }
            i+=2;
        }
    }else{
        i = 2;
        while(i <= minMemb){
            j = 0;
            nope = false;
            while(j < n){
                if(membs[j] % i != 0){
                    nope = true;
                    break;
                }
                j++;
            }
            if(!nope){
                dalikliai.push_back(i);
                count++;
            }
            i++;
        }
    }
    cout << count<<endl;
    for(int x = 0; x < count; x++){
        cout << dalikliai[x] << endl;
    }

    return 0;
}