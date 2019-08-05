#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream fIn ("input.txt");
    int n;
    fIn >> n;
    int a;
    int lastVal;
    int ekstremumai[n/2];
    int maxRangeBetween = 0;
    int dideja = 0; // dideja = 1 mazeja = -1
    int ekstrIndex = 0;
    for (int i = 0; i < n; i++) {
        fIn >> a;
        if(i != 0){
            if(a > lastVal){
                if(dideja == -1){
                    ekstremumai[ekstrIndex] = i;
                    cout << i << endl;
                    if(maxRangeBetween < i-ekstremumai[ekstrIndex-1]){
                        maxRangeBetween = i-ekstremumai[ekstrIndex-1];
                    }
                    ekstrIndex++;
                }else if(dideja == 0){
                    dideja = 1;
                }
            }else if(a < lastVal){
                if(dideja == 1){
                    ekstremumai[ekstrIndex] = i;
                    cout << i << endl;
                    if(maxRangeBetween < i-ekstremumai[ekstrIndex-1]){
                        maxRangeBetween = i-ekstremumai[ekstrIndex-1];
                    }
                    ekstrIndex++;
                }else if(dideja == 0){
                    dideja = -1;
                }
            }
        }
        lastVal = a;

    }
    cout << "MAx range between extremes is: "<< maxRangeBetween<<endl;
    return 0;
}
