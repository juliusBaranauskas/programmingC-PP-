#include <iostream>

using namespace std;

struct packet{
int src;
int dest;
int time;
};

struct pc{
int inf;
int time;
};

int main()
{
    int T = 0;
    int N,M;
    int x;
    int infected;
    int y;
    int leastIndex;
    int leastTime;
    while(T < 30){
            infected = 1;
        cin >> N >> M;
        if(N == 0 && M == 0){
            break;
        }
        packet Packets[M];
        packet fakePack;
        pc pcs[N];
        for(x = 0; x < N; x++){
                if(x == 0){
                pcs[x].inf = 1;
                pcs[x].time = 0;
                }else{
            pcs[x].inf = 0;
            pcs[x].time = M+1;
        }
        }
        for(x = 0; x < M; x++){
            cin >> Packets[x].time >> Packets[x].src >> Packets[x].dest;
        }
        for(x = 0; x < M-1; x++){
                leastTime = Packets[x].time;
                leastIndex = x;
            for(y = x+1; y < M; y++){
             if(Packets[y].time < leastTime){
                leastTime = Packets[y].time;
                leastIndex = y;
             }
            }
            fakePack = Packets[leastIndex];
            Packets[leastIndex] = Packets[x];
            Packets[x] = fakePack;
        }
        for(x = 0; x < M; x++){
            if(pcs[Packets[x].src-1].inf == 1 && pcs[Packets[x].src-1].time < Packets[x].time){
                if(pcs[Packets[x].dest-1].inf == 1){
                }else{
                infected++;
                pcs[Packets[x].dest-1].inf = 1;
                pcs[Packets[x].dest-1].time = Packets[x].time;
                }
            }
        }
        cout << infected << "\n";
        T++;
    }
    return 0;
}
