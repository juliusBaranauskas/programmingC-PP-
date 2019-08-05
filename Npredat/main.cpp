#include <iostream>

using namespace std;

struct organ{
int siz;
char type;
int leftBehind;
};

int main()
{
    int T;
    int N, M;
    int y;
    int a;
    int i;
    int bigIndex;
    int bigSize;
    int leftBehinds;
    long int suma;
    organ fakeAnimal;
    cin >> T;
    for(int x = 0; x < T; x++){
        cin >> N >> M;
        organ animals[N+M];
        leftBehinds = M;
        suma = 0;
        a = 0;
        for(y = 0; y < N+M; y++){
            cin >> animals[y].siz;
            if(y < N){
                animals[y].type = 'A';
            }else{
            animals[y].type = 'B';
            animals[y].leftBehind = 0;
            }
        }
        for(y = 0; y < N+M-1; y++){
            bigIndex = y;
            bigSize = animals[y].siz;
            for(i = y+1; i < N+M; i++){
                if(animals[i].siz > bigSize){
                    bigSize = animals[i].siz;
                    bigIndex = i;
                }
            }
            fakeAnimal = animals[y];
            animals[y] = animals[bigIndex];
            animals[bigIndex] = fakeAnimal;
            if(animals[y].type == 'B'){
                animals[y].leftBehind = leftBehinds;
                leftBehinds--;
            }
        }
        for(i = 0; i < N+M; i++){
            cout<< animals[i].siz << endl;

        }
        for(y = 0; y < N+M-1; y++){
            if(animals[y].type == 'A'){
                for(i = y+1; i < N+M; i++){
                    if(animals[i].type == 'B' && animals[i].siz < animals[y].siz){
                        suma+=animals[i].leftBehind;
                    }
                }
                a++;
                if(a == N){
                    break;
                }
            }
        }
        cout << suma << "\n";
    }
    return 0;
}
