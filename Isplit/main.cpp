#include <iostream>

using namespace std;

int main()
{
    int T, n;
    long int x;

    cin >> T;

    for (int y=0; y<T; y++)
    {
        cin >> x >> n;
        if (x/n>0)
        {
        for (int s=0; s<n-(x%n); s++)
        {
             cout << x/n << " ";
        }

        for (int f=0; f<(x%n); f++)
        {
            cout << 1 + x/n << " ";
        }
        }
        else
        {
            cout << -1;
        }
        cout << "\n";

    }


    return 0;
}
