#include <iostream>
#include <fstream>

using namespace std;

int absValue(int number){
if(number < 0){
    number*=-1;
}
return number;
}

int calcDistance(int points[][4], int n){
    int sandauga = 1;
for(int x = 0; x < n; x++){
sandauga*=(absValue()*absValue());
}
return sandauga;
}

int findSlope(int points[][4], int n){

int main()
{
    int n;
    ifstream fIn("input.txt");
    fIn >> n;
    int points[n][4];
    for(int i = 0; i < 4; i++){
    for(int x = 0; x < n; x++){
        fIn >> points[x][i];
        cout << points[x][i] << " ";
    }
    cout << endl;
    }
    int slope = findSlope(po);
    int distance = calcDistance(points, n);
    return 0;
}
