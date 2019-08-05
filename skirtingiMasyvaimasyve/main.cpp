#include <iostream>

using namespace std;

struct namas{
    int z;
//int namai[z];

namas(int n){
z = n;
int namai[z];
}
};

int main()
{
    namas Namai[4];
    Namai[0].namas(5);
    Namai[0].namai[6] = 2;
    cout << Namai[0].namai[6];
    return 0;
}
