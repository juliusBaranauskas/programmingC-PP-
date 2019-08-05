#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a, b, ats;
    string veiksmas;
    cout << "Iveskite 2 skaicius"<<endl;
    cin >> a>>b;
    system("cls");
    cout<< endl<< "iveskite veiksma (s , d , dl , a , l)"<<endl;
    cin>> veiksmas;
        system("cls");

    if (veiksmas == "s")
       {ats = a+b;
       cout << "atsakymas:" <<ats<<endl;}
    else if (veiksmas == "d")
        {ats = a*b;
        cout << "atsakymas:" <<ats<<endl;}
    else if (veiksmas == "dl")
       {ats = a/b;
       cout << "atsakymas:" <<ats<<endl;}
    else if (veiksmas == "a")
        {ats = a-b;
        cout << "atsakymas:" <<ats<<endl;}
    else if (veiksmas == "l")
        {ats = a%b;
        cout << "atsakymas:" <<ats<<endl;}
    else
        {cout << "ivestas neteisingas veiksmas";}
    return 0;
}
