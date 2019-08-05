#include <iostream>

using namespace std;
long int mas[1000010];

int main()
{

    int T, n;
    long int maxA, minA, a;
    long int sum=0;
    cin >> T;
    for (int x=0; x<T; x++)
    {
        cin >> n;
        for (int y=0; y<n; y++)
        {
            cin >> a;
            if (a>maxA)
            {
                maxA = a;
                mas[a]=0;
            }
            if (a<minA)
            {
               minA = a;
               mas[a]=0;
            }
            mas[a]++;
            if (y == 0)
            {
                minA = a;
                maxA = a;
            }
        }
        for (int y=maxA; y>=minA; y--)
        {
            if (mas[y] > 0)
            {
            for (int z=minA; z<=maxA; z++)
            {
                if (z>=y || mas[z]==0) break;
                if (y%z==0 && y>z && mas[z]>0)
                {
                    mas[z]+=mas[y];
                    mas[y] = 0;
                    for (int p=maxA; p>=minA; p--)
                    {
                        if (mas[p]>0)
                        {
                            maxA = p;
                            break;
                        }
                    }
                }
            }
            }
        }
        for (int y=minA; y<=maxA; y++)
        {
            sum+=mas[y]*y;
        }
cout << sum << endl;
sum = 0;

    }



    return 0;
}
