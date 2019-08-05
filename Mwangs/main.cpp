#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");
    int n;
    fIn >> n;
    int lazdos[n];
    int dezes[n];
    for(int x = 0; x < n; x++){
        fIn >> lazdos[x];
    }
    for(int x = 0; x < n; x++){
        fIn >> dezes[x];
    }


    return 0;
}
