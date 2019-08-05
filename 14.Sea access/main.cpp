#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");
    int n;
    fIn >> n;
    fOut << n-2;
    return 0;
}
