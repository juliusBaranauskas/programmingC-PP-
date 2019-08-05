#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

struct Vertex{
vector<int> links;
int vertexNumber;
bool removed;
};

int findLongestPath(int linkai[][2], int linkuKiekis, int verticesCount, int verticeNumber){
int linkTo;
int pathLength = 1;
bool linksLeft = true;
bool linkExists = true;
linkTo = verticeNumber;
while(linksLeft){
    linkuKiekis--;
    if(linkuKiekis == 0){
        linksLeft = false;
    }
while(linkExists){
for(int x = 0; x < verticesCount-1; x++){
    if(linkai[linkTo][0] == x){
        linkTo = linkai[linkTo][1];
    }
    if(linkai[linkTo][1] == x){
        linkTo = linkai[linkTo][0];
    }
}
}
}
}

int main()
{
    int verticesCount;
    ifstream fIn("input.txt");
    fIn >> verticesCount;
    Vertex vertices[verticesCount];
    int linkai[verticesCount-1][2];
    int linksWith[verticesCount];
    /*
    for(int x = 0; x < verticesCount-1; x++){
        int a, b;
        fIn >> a >> b;
    for()
    }*/
    for(int x = 0; x < verticesCount-1; x++){
            fIn >> linkai[x][0] >> linkai[x][1];
    }
    /*
    int verticesWentThrouh = 0;
    int a,b;

    for(int x = 0; x < verticesCount-1; x++){
        fIn >> a >> b;
        int found = 0; // if both are there then its 1 if one is its 2

        a = linkai[x][0];
        b = linkai[x][1];
        for(int i = x+1; i < verticesCount-1; i++){
            if(a == linkai[i][0]){linksWith[a-1]++;}
            if(a == linkai[i][1]){linksWith[a-1]++;}
            if(b == linkai[i][0]){linksWith[b-1]++;}
            if(b == linkai[i][1]){linksWith[b-1]++;}

        }
    }*/
    int removeAll = -1;

    for(int x = 1; x < verticesCount; x++){
        for(int i = 0; i < verticesCount-1; i++){
            if(x == linkai[i][0]){linksWith[x-1]++;}
            if(x == linkai[i][1]){linksWith[x-1]++;}
        }
    }
    for(int x = 0; x < verticesCount; x++){
        if(linksWith[x] > verticesCount-1){
            removeAll = x;
        }
    }

    for(int x = 0; x < vertices-1; x++){
        findLongestPath(linkai, linksWith[x], verticesCount, x);
    }


    return 0;
}
