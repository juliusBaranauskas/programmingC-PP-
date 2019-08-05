#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    int n, m, c, r;
    ifstream fin("input.txt");
    fin >> n >> m >> c >> r;
    char field[n][m];
    string lines[n];
    for(int x = 0; x < n; x++){
        fin >> lines[x];
    }
    fin.close();
    for(int x = 0; x < n; x++){
        for(int i = 0; i < m; i++){
        field[x][i] = lines[x].at(i);

    }
    }

    for(int x = 0; x < n; x++){
        for(int i = 0; i < m; i++){
        cout << field[x][i] << " ";
    }
    cout <<endl;
    }

    int aCoords[2];
    int bCoords[2];

    for(int x = 0; x < n; x++){
        for(int i = 0; i < m; i++){
        if(field[x][i] == 'A'){
            aCoords[0] == x;
            aCoords[1] == i;
        }else if(field[x][i] == 'B'){
            bCoords[0] == x;
            bCoords[1] == i;
        }
    }
}



    return 0;
}
