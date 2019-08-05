#include <iostream>

using namespace std;

int main()
{
    int n;
    int answer = 0;
    int picos[3];
    cin >> picos[0] >> picos[1] >> picos[2] >> n;
    short int tastyPizza = 0;
    for(int x = 0; x < 3; x++){
        if(picos[x] > tastyPizza){
            tastyPizza = picos[x];
        }
    }
    if(n == 1){
        answer = tastyPizza;
    }
    if(n == 2){
        answer = tastyPizza*2;
    }
    if (answer ==0){
        answer = (n/3)*picos[0]+(n/3)*picos[1]+(n/3)*tastyPizza;
        if(n-((n/3)*3) == 2){
            answer+= tastyPizza*2;
        }else if(n-((n/3)*3) == 1){
        answer+= tastyPizza;
        }
    }
    cout << answer << endl;
    return 0;
}
