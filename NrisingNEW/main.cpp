#include <iostream>
#include <fstream>

using namespace std;

struct Kalnai{
int aukstis;
int koord;
int ilgisPriekin;
};

int main()
{
    ifstream fIn("input.txt");
    int n;
    fIn >> n;
    int x;
    Kalnai kalnai[n];
    int koord, koord2;
    int namoKoord;
    int namoAukstis;
    int time;
    for(x = 0; x < n; x++){
            fIn >> koord;
            fIn >> koord2;
            kalnai[x].koord = koord2;
            if(x == 0){
                kalnai[x].aukstis = koord2 - koord;
            }else{
        kalnai[x].aukstis = kalnai[x-1].aukstis-(koord-kalnai[x-1].koord)+(koord2 - koord);
        kalnai[x-1].ilgisPriekin = koord - kalnai[x-1].koord;
            }
    }
    kalnai[n-1].ilgisPriekin = kalnai[n-1].aukstis;
    fIn >> namoKoord;
    bool houseFound = false;
    for(x = 0; x < n; x++){
            if(namoKoord <= kalnai[0].koord){
                time = 1;
                houseFound = true;
                break;
            }
        if(namoKoord < kalnai[x].koord){
                if(namoKoord >= kalnai[x-1].koord+kalnai[x-1].ilgisPriekin){
                    namoAukstis = kalnai[x].aukstis-(kalnai[x].koord-namoKoord);
                }else{
                    namoAukstis = kalnai[x-1].aukstis-(namoKoord-kalnai[x-1].koord);
                }
                houseFound = true;
        }
    }
    if(!houseFound){
        namoAukstis = kalnai[n-1].aukstis - (namoKoord-kalnai[n-1].koord);
    }
    double tgMax = -2;
    double tg;
    for(x = 0; x < n; x++){
        if(kalnai[x].koord < namoKoord){
            tg = ((double)kalnai[x].aukstis-(double)namoAukstis)/((double)namoKoord-(double)kalnai[x].koord);
            if(tg > tgMax){
                tgMax = tg;
            }
        }else{
        break;
        }
    }
    double ats = tgMax*namoKoord+namoAukstis;
    int hah = ats;
    if(ats-hah != 0){
        hah++;
    }
    if(time == 1){
    hah = 0;
    }
    if(ats<0){
        hah = 0;
    }
    ofstream out("output.txt");
    out << hah;
    return 0;
}
