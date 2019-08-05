#include <iostream>
#include <string>


using namespace std;

int main(){
    string full, target;
    cin >> full >> target;
    long int num = 0;
    int index = 0;
    int startIndex = 0;
    for(int x = 0; x < full.length(); x++){
        if(full[x] == target[index]){
            index++;
            if(index == 1){ startIndex = 0;}
            if(index == target.length()-1){
                
            }
        }
    }
    return 0;
}