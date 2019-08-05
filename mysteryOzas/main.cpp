#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fIn("input2.txt");
    ofstream fOut("out.txt");
    char simbolis;
    bool number = false;
    long long int *addTo;
    long long int numx = 0;
    long long int numX = 0;
    long long int numy = 0;
    long long int numY = 0;

    int currentNum = 0;
    int numTen = 1;
    while(!fIn.eof()){
        simbolis = fIn.get();
        if(number && (simbolis > 57 || simbolis < 48)){
            number = false;
            *addTo += currentNum;
            currentNum = 0;
            numTen = 1;
        }
        if(simbolis == 'x'){
            number = true;
            addTo = &numx;
            continue;
        }
        if(simbolis == 'X'){
            number = true;
            addTo = &numX;
            continue;

        }
        if(simbolis == 'y'){
            number = true;
            addTo = &numy;
            continue;
        }
        if(simbolis == 'Y'){
            number = true;
            addTo = &numY;
            continue;
        }
         
        if(number){
            currentNum = currentNum*numTen + (simbolis-48);
            numTen*=10;
        }
    }
    if(number){
        *addTo += currentNum;
    }
    cout << "numx\t" << numx << endl;
    cout << "numX\t" << numX << endl;
    cout << "numy\t" << numy << endl;
    cout << "numY\t" << numY << endl << endl;

    cout << "numxs\t" << numx+numX << endl;
    cout << "numYs\t" << numY+numy << endl;
    return 0;
}
