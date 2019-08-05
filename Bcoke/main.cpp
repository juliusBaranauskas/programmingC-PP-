#include<iostream>

using namespace std;

int main(){
    int n, k, speed;
    cin >> n >> k >> speed;
    int t, pause;
    int minTime;
    int tim;
    for(int i = 0; i < n; i++)
    {
        cin >> t >> pause;
        tim = 0;
        //tim = ((k/(t*speed))*t)+pause*(k/(t*speed)-1)+(k%(t*speed))/speed;
        if(k/(t*speed) > 0){
            tim+= (k/(t*speed))*t;
            tim+= pause*(k/(t*speed)-1);
            if(k%(t*speed) != 0){
                tim+=pause;
            }
        }
        /*if(k/(t*speed)-1 == 0){
            tim+=pause;
        }*/
        tim+= (k%(t*speed))/speed;
        if(i==0){
            minTime = tim;
        }
        if(tim < minTime){
            minTime = tim;
        }
    }
    cout << minTime;
    return 0;
}