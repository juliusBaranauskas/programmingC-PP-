#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string zodziai[1000];

int convertToNumber(string belkas){
    int number;
    int x = belkas.length()-1;
    int desimtux = 1;
    while(x>0){
        number+= desimtux*(belkas[x]-48);
        x--;
        desimtux*=10;
    }
    return number;
}

int main()
{
    ifstream fIn("input.txt");
    string kodas;
    fIn >> kodas;
    int x = 0;
    int z = 0;
    string number = "";
    int num;
    int raide;
    cout << kodas[x]-48;
    //while(true){
            raide = 0;
        while(kodas[x] <= '0' && kodas[x] >= '9'){
            number[raide]+=kodas[x];
            x++;
            raide++;
        }
        num = convertToNumber(number);
        if(num != 0){
            cout << zodziai[num];
        }else{
            zodziai[z] = kodas[x];
            z++;
        }
        cout << kodas[x];
        x++;
        if(x >= kodas.length()-1){
            break;
        }
        num = 0;
        number = "";
    //}
    return 0;
}

