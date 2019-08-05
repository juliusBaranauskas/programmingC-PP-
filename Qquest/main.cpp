#include<iostream>
    
using namespace std;

int main(){
    string beginning = "Forty-two is ";
    string toRead;
    string current;
    while(cin >> current){
        if(current == "What"){
            cin >> current;
            if(current == "is"){
                toRead = beginning;
                while(cin >> current){
                    if(current == "?"){
                        cout << "Forty-two is.\n";
                        break;
                    }
                    if(current[current.length()-1] == '?'){
                        current[current.length()-1] = '.';
                        cout << toRead << current << endl;
                        break;
                    }
                    if(current[current.length()-1] == '.'){
                        break;
                    }
                    toRead += current + " ";
                }
            }else if(current == "is?"){
                cout << "Forty-two is.\n";
            }
        }
    }
    return 0;
}
