#include <iostream>

using namespace std;

struct Plan{
int startDay;
int endDay;
int cores;
int price;
};


int main()
{
    //ifstream fIn ("input.txt");
    int days, dailyCores, plansNumber;
    cin >> days >> dailyCores >> plansNumber;
    //fIn >> days >> dailyCores >> plansNumber;
    Plan plans[plansNumber];
    long int sum = 0;
    int x;
    int i;
    Plan dummyPlan;
    for(x = 0; x < plansNumber; x++){
            cin >> plans[x].startDay >> plans[x].endDay >> plans[x].cores >> plans[x].price;
            //fIn >> plans[x].startDay >> plans[x].endDay >> plans[x].cores >> plans[x].price;
            for(i = 0; i < x; i++){
                if(plans[x].price < plans[i].price){
                    dummyPlan = plans[i];
                    plans[i] = plans[x];
                    plans[x] = dummyPlan;
                }
            }
    }

    if(plans[0].endDay - plans[0].startDay == days && plans[0].cores >= dailyCores){
        sum = plans[0].price*dailyCores*days;
        cout << sum;
        return 0;
    }

    int coresLeft;
    for(x = 0; x < days; x++){
        i = 0;
        coresLeft = dailyCores;
        while(i < plansNumber){
            if(plans[i].endDay-1 >= x && plans[i].startDay-1 <= x){

            if(plans[i].cores - coresLeft >= 0){
                    sum+= plans[i].price*coresLeft;
                break;
            }else{
                coresLeft -= plans[i].cores;
                sum += plans[i].price*plans[i].cores;
                i++;
            }
        }else{
        i++;
        }
        }
    }
     cout <<sum << endl;
    return 0;
}
