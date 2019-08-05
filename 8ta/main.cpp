#include <iostream>
#include <fstream>

using namespace std;

struct Sriuba
{
    int kaina;
    double kiekis;
    double soupPerKid;
    int kiekValgo;
};

int main() {
    int T, N, childrenCount, money;
    ifstream fIn ("input.txt");
    fIn >> T >> N >> childrenCount >> money;
    int kiekMegstaSita[N];
    Sriuba sriubos[N];
    for (int x = 0; x < N; x++) {
        kiekMegstaSita[x] = 0;
    }
    for (int x = 0; x < childrenCount; x++) {
        int sriuba;
        fIn >> sriuba;
        kiekMegstaSita[sriuba-1]++;

    }

    for (int x = 0; x < N; x++) {
        fIn >> sriubos[x].kiekis >> sriubos[x].kaina;
        sriubos[x].kiekValgo = kiekMegstaSita[x];
        sriubos[x].soupPerKid = sriubos[x].kiekis/(double)kiekMegstaSita[x];
    }

            for (int x = 0; x < N-1; x++) {
                Sriuba a = sriubos[x];
                int aIndex = x;
                for (int i = x+1; i < N; i++) {
                    if(a.soupPerKid >= sriubos[i].soupPerKid){
                            //cout << a.soupPerKid<< " a  b" << sriubos[i].soupPerKid<<endl;
                       // if(a.kaina <= sriubos[i].kaina && a.soupPerKid == sriubos[i].soupPerKid){

                        //}else{
                            a = sriubos[i];
                            aIndex = i;
                       // }
                    }
                }
                sriubos[aIndex] = sriubos[x];
                sriubos[x] = a;
            }
            for(int x = 0; x < N; x++){
                cout<<endl << sriubos[x].soupPerKid << " " << sriubos[x].kaina << endl;
            }
            while(money > 0.01){
                double newSPKid = (((double)money/(double)sriubos[0].kaina)
                 + sriubos[0].kiekis) /
                ((double)sriubos[0].kiekValgo);
                cout << newSPKid << "new sPkfaefwf "<<endl;
                if(newSPKid > sriubos[1].soupPerKid){
                   // double moneySpent = 0;
                    double moneySpent = (((sriubos[1].soupPerKid+0.0001)*
                    ((double)sriubos[0].kiekValgo))-
                    (sriubos[0].kiekis))*
                    (double)sriubos[0].kaina;
                    money -=moneySpent;
                    cout << moneySpent <<endl;
                    sriubos[0].kiekis += (moneySpent/sriubos[0].kaina);
                    sriubos[0].soupPerKid = sriubos[0].kiekis / sriubos[0].kiekValgo;
                    if(sriubos[2].soupPerKid - sriubos[1].soupPerKid > 0.0015){
                        Sriuba b = sriubos[0];
                        sriubos[0] = sriubos[1];
                        sriubos[1] = b;
                    }else{
                        for (int x = 0; x < N-1; x++) {
                            Sriuba a = sriubos[x];
                            int aIndex = x;
                            for (int i = x+1; i < N; i++) {
                                if(a.soupPerKid >= sriubos[i].soupPerKid){
                                    if(a.kaina >= sriubos[i].kaina){
                                        a = sriubos[i];
                                        aIndex = i;
                                    }
                                }
                            }
                            sriubos[aIndex] = sriubos[x];
                            sriubos[x] = a;
                        }
                    }

                }else{
                    double answer = newSPKid;
                    cout << answer << " 91 eilute " << money <<  endl;
                    break;
                }
            }
        cout << sriubos[0].soupPerKid << " soup Per kid. Ja megsta " << sriubos[0].kiekValgo<< endl;



    return 0;
}
