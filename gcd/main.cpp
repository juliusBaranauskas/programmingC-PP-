#include <iostream>
#include <fstream>
#include<vector>
using namespace std;


int calculateGCD(int a, int b){
    int GCD = 1;
    bool veikia = true;
    int daliklis = 2;
    vector<int> dalikliai;
    vector<int> dalikliai2;
    while(veikia){
        if(a % daliklis == 0){
            dalikliai.push_back(daliklis);
            a = a/daliklis;
        }else{
        daliklis++;
        }
        if(daliklis == a || a == 1){
            veikia = false;
        }
    }
    veikia = true;
    daliklis = 2;
    while(veikia){
        if(b % daliklis == 0){
            dalikliai2.push_back(daliklis);
            b = b/daliklis;
        }else{
        daliklis++;
        }
        if(daliklis == b || b == 1){
            veikia = false;
        }
    }

    veikia = true;
    int value;
            for(int x = 0; x < dalikliai.size(); x++){
             value = dalikliai[x];
        for(int i = 0; i < dalikliai2.size(); i++){
          if(value == dalikliai2[i]){
            GCD*=value;
            dalikliai2.erase(dalikliai2.begin()+i);
          }
        }
    }

    return GCD;
}

void darykButerbroda(int testNumbers[], int queries[][2], int queriesCount, int testNumbersCount){
    int pairGCD = 1;
    int commonGCDs = 0;
    ofstream fout("output.txt");
for(int x = 0; x < queriesCount; x++){
    pairGCD = calculateGCD(testNumbers[queries[x][0]], testNumbers[queries[x][1]]);
    for(int i = 0; i < testNumbersCount; i++){
        for(int y = i; y < testNumbersCount; y++){
          if(calculateGCD(testNumbers[i], testNumbers[y]) == pairGCD){
            commonGCDs++;
            }
        }
    }
    fout << pairGCD << " " << commonGCDs << endl;
}
}


int main()
{
    int testCases;
    ifstream fin("input.txt");
    fin >> testCases;
    ofstream fout("output.txt");
    int testsNumbersCount[testCases];
    int queriesCount;
    for(int x = 0; x < testCases; x++){
        fin >> testsNumbersCount[x];
        int testsNumbers[testsNumbersCount[x]];
        for(int i = 0; i < testsNumbersCount[x]; i++){
            fin >> testsNumbers[i];
            cout << testsNumbers[i] <<" ";
        }
        cout <<endl;
        fin >> queriesCount;
        int queries[queriesCount][2];
        for(int i = 0; i < queriesCount; i++){
            fin >> queries[i][0] >> queries[i][1];
        }
        darykButerbroda(testsNumbers, queries, queriesCount, testsNumbersCount[x]);
    }
    return 0;
}
