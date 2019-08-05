#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    short int n;
    cin >> n;
    vector<string> words;
    vector<char> firstLetter;
    words.clear();
    firstLetter.clear();
    string word;
    bool exists;
    short int letterCount = 0;

    for(int x = 0; x < n; x++){
        cin >> word;
        words.push_back(word);
        exists = false;
        for(int i = 0; i < firstLetter.size(); i++){
            if(word.at(0) == firstLetter[i]){
                exists = true;
                break;
            }
        }
        if(!exists){
            firstLetter.push_back(word[x]);
            letterCount++;
        }
    }
    sort(words.begin(), words.end());

    cout << letterCount << endl;
    for(int i = 0; i < words.size(); i++){
        if(i != 0){
            if(words[i-1].at(0) != words[i].at(0)){
                cout << endl << words[i];
            }else{
                cout << " " << words[i];
            }
        }else{
            cout << words[i];
        }
    }
    return 0;
}