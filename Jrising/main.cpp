#include<iostream>

using namespace std;


struct point{
    int x;
    int y;
}

int main(){
    int n;
    cin >> n;
    point points[2*n];
    for(int i = 0; i < n*2; i++)
    {
        cin >> points[i].x;
        if(i == 0){
            points[i].y = 0;
        }else{
            if(i % 2 == 0){
                points[i].y = points[i-1].y- (points[i].x - points[i-1].x)
            }else{
                points[i].y = points[i-1].y+ (points[i].x - points[i-1].x)
            }
        }
    }
    point namas;
    cin >> namas.x;
    int highestPeak = 0;
    for(int i = 0; i < 2*n; i++)
    {
        if(namas.x <= points[i].x){
            if(i % 2 == 0){
                
            }else{

            }
        }
        if(points[i].y >= highestPeak)
    }
    
    
    return 0;
}