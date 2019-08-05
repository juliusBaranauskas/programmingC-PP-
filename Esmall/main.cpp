#include<iostream>

using namespace std;


int main(){
    string s;
    cin >> s;
    if(s.length() > 38){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    int skaiciai[s.length()];
    int zeroCount = 0;
    for(int i = 0; i < s.length(); i++){
        skaiciai[i] = s[i]-48;
        if(skaiciai[i] == 0){
            zeroCount++;
        }
    }
    if(zeroCount > s.length()-2){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    int minVal;
    int minIndex;
    int kazkam;
    for(int i = 0; i < s.length()-1; i++){ // SORTING
        minVal = skaiciai[i];
        minIndex = i;
        for(int j = i+1; j < s.length(); j++){
            if(skaiciai[j] < minVal){
                minVal = skaiciai[j];
                minIndex = j;
            }
        }
        kazkam = skaiciai[i];
        skaiciai[i] = minVal;
        skaiciai[minIndex] = kazkam;
    }

    for(int i = 0; i < s.length(); i++) // COUT
    {
        cout << skaiciai[i] << " ";
    }
    cout << endl;

    if(zeroCount > 17){
        if(skaiciai[zeroCount] == 1){
            cout << skaiciai[zeroCount+1];
            for(int i = 0; i < zeroCount-18; i++){
                cout << skaiciai[i];
            }
            for(int i = zeroCount+2; i < s.size()-18-(zeroCount-18+1); i++)
            {
                cout << skaiciai[i];
            }
            cout << " ";
            cout << skaiciai[zeroCount];
            for(int i = 0; i < 18; i++)
            {
                cout << 0;
            }
        }else{
            cout << skaiciai[zeroCount];
            for(int i = 0; i < count; i++)
            {
                /* code */
            }
            

        }
    }
    for(int i = 0; i < s.length()-19; i++)
    {
        
    }
    
    cout << skaiciai[zeroCount+1];
    for(int i = 0; i < s.length(); i++)
    {
        if(i == zeroCount || i == zeroCount+1){
            continue;
        }
        cout << skaiciai[i];
    }    
    
cout << endl;

    cout << endl<< zeroCount << endl;
    return 0;
}