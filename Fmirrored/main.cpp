#include<iostream>
    
using namespace std;

int main(){
    string s;
    cin >> s;
    bool mirrored = false;
    string rev=s;
    for(int i = 0; i < s.length()/2+1; i++){
        if(s[i] == 'p'){
            rev[s.length()-i-1] ='q';
            if(s[s.length()-i-1] != 'q'){
                mirrored = false;
            }else{
                mirrored = true;
            }
            mirrored = true;
        }else if(s[i] == 'q'){
            rev[s.length()-i-1] ='p';
            if(s[s.length()-i-1] != 'p'){
                mirrored = false;
            }else{
                mirrored = true;
            }
        }else if(s[i] == 'd'){
            rev[s.length()-i-1] ='b';
            if(s[s.length()-i-1] != 'b'){
                mirrored = false;
            }else{
                mirrored = true;
            }        
        }else if(s[i] == 'b'){
            rev[s.length()-i-1] ='d';
            if(s[s.length()-i-1] != 'd'){
                mirrored = false;
            }else{
                mirrored = true;
            }
        }else if(s[i] == 'H' || s[i] == 'I' || s[i] == 'M' || s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' || s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'o' || s[i] == 'v' || s[i] == 'w' || s[i] == 'x'){
            rev[s.length()-i-1] = s[i];
            mirrored = true;
        }else{
            rev[s.length()-i-1] =s[i];
        }
    
    }
    for(int x = 0; x < s.length(); x++){
        //cout << rev[x];
        if(s[x] != rev[x]){
            mirrored =false;
            break;
        }
    }
    if(s.length() == 1){
        int i =0;
        if(s[i] == 'H' || s[i] == 'I' || s[i] == 'M' || s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' || s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'o' || s[i] == 'v' || s[i] == 'w' || s[i] == 'x'){
            mirrored = true;
        }
    }
    if(mirrored){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}