#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int testai;
    unsigned long long a, pinigai, v;
    int b;
    cin>>testai;
    string bin;
    int n=0;
    int z;
    int m1=0, m2=0, m=0;
    int N, kof = 1, saugu=0 ;

    for(int i = 0; i < testai; i++){
            cin>>a>>b>>pinigai;
            n =0;
            z= 0;
            bin = bitset<29>(pinigai).to_string();

            for (int x=0; x<29; x++)
            {
                 if (n>0 && bin[x] == '1')
                 {
                     N = 29-x;
                     break;
                 }
                 if (bin[x] == '1' && n==0)
                {
                    n = 29-x;
                }
            }
            cout << n << " " << N << endl;


            // apskaiciuojam m1
            for (int x=0; x<n-1; x++) // visi iki a
            {
                m2+=kof;
                kof*=2;
            }
            kof=1;

            for (int x=0; x<N; x++) // ne visi iki a o iki n-1 (m1)
            {
                m1+=kof;
                kof*=2;
            }
            if (m2-a < m1)
            {
                cout << m1+m2-a;
            }


            cout << m1 << endl;
            cout << m2 << endl;


            // apskaiciuojam m2

    }
    return 0;
}
