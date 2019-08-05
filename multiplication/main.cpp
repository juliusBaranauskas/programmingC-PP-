#include <iostream>

using namespace std;

int biggest(int number1, int number2, int number3){
    int ans = number1;
if(number1 >= number2 && number1 >= number3){
    ans = number1;
}
if(number2 >= number1 && number2 >= number3){
    ans = number2;
}
if(number3 >= number2 && number3 >= number1){
    ans = number3;
}
return ans;
}

int main()
{
    int n, k;
    ifstream fIn("input.txt");
    fIn >> n >> k;
    int numbers[n];
    int previous = 0;
    int streakSize = 0;
    int numberOfStreaks =0;
    int streaks[n/2];
    int currentStreak = 0;
    int answer;
    bool done = false;
    for(int x = 0; x < n; x++){
        fIn >> numbers[x];
        if(numbers[x] >= previous){
            streakSize++;
            if(streakSize >= k*2){
                done = true;
                answer = x-k+1;
                break;
            }
        }else{
        streakSize = 0;
        numberOfStreaks++;
        }
    }
    ofstream fOut("output.txt");
    if(done){
        fOut << answer;
    }
    int biggest = 0;
    for(int x = 0; x < n-k; x++){
            biggest = biggest(numbers[x], numbers[x+1], numbers[x+2]);
        for(int i = x+k; i < k; i++){
            if(numbers[i] >= biggest){
                for(int z = i-1; z > i-k;z--){
                    if(numbers[z] >= biggest){

                    }else{
                    break;
                    }
                }
            }
        }
    }
    return 0;
}
