#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    ifstream fIn("input.txt");
    ofstream fOut("output.txt");
    fIn >> n;
    int current;
    long int product;
    vector<int> masyvas;
    bool firstZero = false;
    bool twoZeros = false;
    int negativeCount = 0;
    int evenCnt = 0;
    int oddCnt = 0;
    int ans;
    int ones = 0;
    for(int x = 0; x < n; x++){
        fIn >> current;
        if(current == 0){
            if(firstZero){
                twoZeros = true;
            }else{
                firstZero = true;
            }
        }
        if(current < 0){
            negativeCount++;
        }
        if(current == 1){
            ones++;
        }else{
            if(current %2 == 0){  evenCnt++;
            }else{  oddCnt++;   }
        masyvas.push_back(current);
        sort(masyvas.rbegin(), masyvas.rend());
        }
    }
    n-=ones;
    if(n == 0){
        fOut << "Yes\n" << 1;
    }else if(n<2){
        fOut << "No";
        return 0;
    }
    if(firstZero){
            if(twoZeros){
                fOut << "Yes\n"<< 0;
                return 0;
                }else{
                    fOut << "No";
                    return 0;
                }
    }
    int x;
    if(masyvas[0] < masyvas[masyvas.size()-1]*-1 && negativeCount > 0){
            if(negativeCount%2 == 0){
                product = masyvas[masyvas.size()-1];
                x = 0;
                n -=1;
                ans = masyvas[masyvas.size()-1];
            }else{
                fOut << "No";
                return 0;
            }
    }else{
    product = masyvas[0];
    x = 1;
    ans = masyvas[0];
    }
    if(product%2 != 0 && evenCnt >0){
        fOut << "No";
        return 0;
    }
    if(product%2 == 0 && evenCnt == 0){
        fOut << "No";
        return 0;
    }
    for(; x < n; x++){
        if(product%masyvas[x] == 0){
            product /= masyvas[x];
        }else{
            fOut << "No";
            return 0;
        }
    }
    if(product == 1){

     fOut << "Yes\n"<< ans;
        return 0;
        }else{
            fOut << "No";
            return 0;
        }
    return 0;
}
