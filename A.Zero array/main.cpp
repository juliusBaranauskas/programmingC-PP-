#include <iostream>
using namespace std;

int main()
{
    //ifstream fIn("input.txt");
    //ofstream fOut("output.txt");
    unsigned int nTests;
    cin >> nTests;
    bool first = true;
    for (int x = 0; x < nTests; x++) {
        unsigned int n, q;
        cin >> n >> q;
        int arrayz[n];
        for (unsigned int i = 0; i < n; i++) {
            cin >> arrayz[i];
        }
        int operation;
        int location, newValue;
        int diffValues = 0;

        for (unsigned int y = 0; y < q; y++) {
        cin >> operation;
        if(operation == 1){
            cin >> location >> newValue;
            arrayz[location-1] = newValue;
        }else if(operation == 2){
            diffValues = 0;
            for (unsigned int z = 0; z < n; z++) {
                //fOut << arrayz[z] << " ";
                if(arrayz[z] != 0){
                for (unsigned int i = z+1; i < n; i++) {
                    if(arrayz[i] == arrayz[z]){
                        arrayz[i] = 0;
                    }
                }
                diffValues++;
            }

             }
             //fOut << endl;
             if(!first){
                 cout << endl;
             }
             first = false;
             cout << diffValues;
        }
    }

    }
    return 0;
}
