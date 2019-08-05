#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned long long int pow(unsigned long long int number, unsigned long long int number2){
    unsigned long long int answer = 1;
    for(int x = 0; x < number2; x++){
        answer*=number;
    }
        if(number2 == 0){
            answer = 1;
        }
 return answer;
}

string multiply(string number, string number2){
int length = number.length()*number2.length();
string substring[number.length()];
int ans;
int moduluz = 0;
for(int x = number2.length(); x > 0; x--){

    for(int i = number.length(); i > 0; i--){
        ans = stoi(number.at(i))*stoi(number2.at(x))+moduluz;
        if(ans >=10){
         ans = ans%10;
         moduluz = ans/10;
        }else{
        moduluz = 0;
        substring[i].insert(0, ans);
    }
}
}
;
return stringSum(number.length, substring);
}

string stringSum(int n, string substring[]){
string sum;
for(int x = n; x > 0; x--){
    substring[x]
}

return sum;
}


int main()
{
    unsigned long long int number, number2, moduluz, answer = 0;
    ifstream fIn("input.txt");
    fIn >> number >> number2 >> moduluz;
    if(number != 1){
    for(int x = 0; x <= number2; x++){
        answer+= pow(number, x);
        cout << "doin somethin "<< x << "asnwer is: "<< answer<<endl;
    }
    answer = answer%moduluz;
    }else{
    answer = 1%moduluz;
    }
    ofstream fOut("output.txt");
    fOut << answer;
    fOut.close();
    fIn.close();
    return 0;
}
