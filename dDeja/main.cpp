#include <iostream>

using namespace std;

int main()
{
    int T;
    int n, m;
    int y;
    int lenkas;
    cin >> T;
    for(int x = 0; x < T; x++){
        cin >> n >> m;
        for(y=0; y < n; y++){
            cin >> lenkas;
        }
        for(y=0; y < m; y++){
            cin >> lenkas;
        }
        if(n <= m){
            cout << "Yes\n";
        }else{
        cout <<"No\n";
        }
    }
    return 0;
}
