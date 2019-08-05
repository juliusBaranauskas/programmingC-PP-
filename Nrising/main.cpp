#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fIn("input.txt");
    int n;
    fIn >> n;
    int koords[n*2];
    int heights[n];
    int namoKoord = 0;
    int namoHeight = 0;
    int highestPeak = 0;
    int highestPeakX;
    int kalnasHeight;
    int kalnasKoord;
    int time = 0;
    bool frontMount = false;
    bool namasYra = false;
    int x;
    for(x = 0; x < n*2; x++){
        fIn >> koords[x];
    }
    fIn >> namoKoord;
        for (x = 0; x < n*2; x++){
            if(namoKoord <= koords[x]){
            if(x%2 == 1){
                frontMount = true;
            }else{
                frontMount = false;
            }
            break;
        }
        }
    heights[0] = koords[1]-koords[0];
    highestPeak = heights[0];
    highestPeakX = koords[1];

    int i = 0;
    for(x = 1; x < n; x++){

        heights[x] = heights[x-1]-(koords[x*2]-koords[(x*2)-1])+(koords[(x*2)+1]-koords[x*2]);
        if(koords[x+(2*i)] >= namoKoord && frontMount){   namoHeight = heights[x]-(koords[x+2*i]-namoKoord);   namasYra = true;

        }else if(koords[x+(2*i)] > namoKoord && !frontMount) {    namoHeight = heights[x-1]-(namoKoord-koords[x+(2*i)]);
            namasYra = true; kalnasHeight = heights[x-1]; kalnasKoord = koords[x+(2*i)];

        }

        if(heights[x] > highestPeak && !namasYra)
            {
            highestPeak = heights[x];
            highestPeakX = koords[x+2*i];
            }
            i++;
    }
    if(!namasYra){
        namoHeight = heights[n-1]-(namoKoord-koords[(n*2)-1]);
        kalnasHeight = highestPeak;
        kalnasKoord = highestPeakX;
    }
    if(!frontMount){
        time = kalnasHeight+kalnasKoord;
    }else{

        if(namoKoord <= koords[1]){
            time = 0;
        }else{
            double tg = ((double)kalnasHeight-(double)namoHeight)/((double)namoKoord-(double)kalnasKoord);
            cout << tg << endl;
            if(namoHeight > kalnasHeight){
                tg*=-1;
            }
            double saulesHeight = (double)namoHeight+(tg*(double)namoKoord);
            time = saulesHeight;
            if(saulesHeight-time != 0){
                time++;
            }
            cout  << time << endl;
            //cout << kalnasHeight;
        }
    }
    cout << time << endl;
    return 0;
}
