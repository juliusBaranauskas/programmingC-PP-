#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    string binary;
    int testai, n, index = 0, counter = 1;
    cin>>testai;
    for(int i=0;i<testai;i++){
        cin>>n;
        binary = bitset<29>(n).to_string();
        while(binary[28-index]!='1'){
            index++;
            counter++;
        }
        cout<<counter<<endl;
        index = 0;
        counter = 1;
    }
    return 0;
}
