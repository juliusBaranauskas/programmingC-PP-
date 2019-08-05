#include <iostream>

using namespace std;

int main()
{
    long int testCases;
    long long int n, x;
    cin >> testCases;
    int tens, answer, digits, pagesUsed;
    for(long int z = 0; z < testCases; z++){
        cin >> n >> x;
        tens = 1;
        digits = 1;
        answer = 0;
        pagesUsed= 0;
        while(tens <= x){
            tens*=10;
            digits++;
        }
        while(true){
            if((digits-1)>n){
                answer = -1;
                break;
            }
         if((tens-x)*(digits-1)+answer >= n){
                if((tens-x)*(digits-1)+answer == n){
                  answer += tens-x;
                }else{
                if(((n-pagesUsed) / (digits-1))*(digits-1) == (n-pagesUsed)){
                        answer += (n-pagesUsed)/(digits-1);
                        break;
                    }else{
                    answer=-1;
                    break;
                    }
                }

            break;
        }else{
            answer+=tens-x;
        }
        pagesUsed += answer*(digits-1);
        tens*=10;
        x = tens/10;
        digits++;
    }
        cout << answer << endl;
    }
    return 0;
}
