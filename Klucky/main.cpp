#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");
    string hex;
    fIn >> hex;
    if(hex[hex.length()-1] == 'f' || hex[hex.length()-1] == '7'){
        fOut << "YES";
    }else{
        fOut << "NO";
    }
    return 0;
}
