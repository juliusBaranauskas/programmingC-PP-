#include<iostream>
    
using namespace std;

int main(){
    string current;
    char letter;
    bool tautogram = true;
    cin >> current;
    bool didzoji = false;
    if(current[0] < 97){
        didzoji = true;
    }
    letter = current[0];
    while(cin >> current){
        if(current[0] < 97){
            if(didzoji){
            if(current[0] != letter){
                tautogram = false;
                break;
            }
        }else{
           if(current[0] != letter-32){
                tautogram = false;
                break;
            } 
        }
        }else{

            if(didzoji){
            if(current[0] != letter+32){
                tautogram = false;
                break;
            }
        }else{

            if(current[0] != letter){
                tautogram = false;
                break;
            }
        }
        }
    }
    if(tautogram){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}