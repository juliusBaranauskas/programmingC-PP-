#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

struct team{
    int won;
    string name;
};

int main(){
    /* int n;
    cin >> n;
    int gamesN = n-1;
    int k = 0;
    while(true){
        k++;
        if(n/2 == 1){
            break;
        }
        n = n/2;
    }
    vector<team> teams;
    string team1;
    bool found;
    string team2;
    int biggest = 0;
    string nameBig;
    for(int x = 0; x < gamesN; x++){
        cin >> team1 >> team2;
        found = false;
        if(x == 0){
            biggest = 1;
            nameBig = team1;
        }
        for(int i = 0; i < teams.size(); i++){
            if(teams[i].name == team1){
                teams[i].won++;
                if(teams[i].won > biggest){
                    biggest = teams[i].won;
                    nameBig = teams[i].name;
                    if(biggest == k){
                        cout << nameBig;
                        return 0;
                    }
                }
                found = true;
                break;
            }
        }
        if(!found){
            team newTeam;
            newTeam.won = 1;
            newTeam.name = team1;
            teams.push_back(newTeam);
        }
    }
    cout << nameBig;
 */

    int n;
    cin >> n;
    int gamesN = n-1;
    string a, b;
    vector<string> teams;
    teams.clear();
    int k = 0;
    while(true){
        k++;
        if(n/2 == 1){
            break;
        }
        n = n/2;
    }
    for(int i = 0; i < gamesN; i++){
        cin >> a >> b;
        teams.push_back(a);
    }
    int gamesWon;
    for(int x = 0; x < gamesN-k+1; x++){
        gamesWon = 1;
        if(gamesWon == k){
            cout << teams[x];
            return 0;
        }
        for(int i = x+1; i < gamesN; i++){
            if(teams[x] == teams[i]){
                gamesWon++;
                if(gamesWon == k){
                    cout << teams[x];
                    return 0;
                }
            }
        }
    }
    return 0;
}