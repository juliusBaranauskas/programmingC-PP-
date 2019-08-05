#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<string> names;
    int n;
    cin >> n;
    string current;
    int x;
    bool nebuvo;
    for (int i = 0; i < n; i++){
        cin >> current;
        nebuvo = true;
        for(x = 0; x < names.size(); x++){
            if(current == names[x]){
                nebuvo = false;
                break;
            }
        }
        if(nebuvo){
            names.push_back(current);
            nebuvo = false;
        }
    }
    cout << n-names.size();
    return 0;
}   