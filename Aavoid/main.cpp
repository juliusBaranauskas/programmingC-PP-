#include <iostream>
#include <string>
#include <vector>


using namespace std;


struct per
{
   int p;
   char letter;

};

int factorial(int num)
{
    int rez = 1;

    for (int u=1;u<=num; u++)
    {
        rez*=u;
    }
    return rez;
}

int combinations(int ns, int slots)
{
return (factorial(ns)/factorial(ns-slots)*factorial(slots));

}



int main()
{
string s;
vector<per> inList;
per narys;
int num=1;
cin >> s;
for (int x=0; x<s.size(); x++)
{
for (int y=0; y<inList.size(); y++)
{
    if (inList[y].letter == s[x])
        {
            inList[y].p++;
            break;
        }
    if (y+1 == inList.size())
    {
        narys.p = 1;
        narys.letter = s[x];

        inList.push_back(narys);
        break;
    }

}
if (inList.size() == 0)
{
     narys.p = 0;
        narys.letter = s[x];

        inList.push_back(narys);

}

}

int rez=0;
int com;
// jei tiek pat raidziu subliste tai negali but po tiek pat tokiu paciu raidziu dviejose zodziuose reiskia tai yra combinations


for (int slots=1; slots<=s.size();slots++) // kiek raidziu imam
{

for (int y= 0; y<inList.size(); y++) // pradedant nuo kiekvieno skirtingo nario
{
    for (int u=0; u<slots; u++) // kiek vienodu nariu turi taip pildom pvz a(com(abc)) aa(com(abc))
    {
        if (inList[y].p -1 < u) break;
        {
            rez+=combinations(inList.size()-1, slots-1);
        }
    }


}



}

cout << rez << endl;



return 0;
}
