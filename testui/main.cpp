#include<iostream>
#include<fstream>

using namespace std;


int main(){
    string s = "000075400000000008080190000300001060000000034000068170204000603900000020530200000";
    ofstream fout("out.txt");
    for(int c = 0; c < s.length(); c++){
        fout << s[c] << " ";
    }
    fout.close();
    return 0;
}