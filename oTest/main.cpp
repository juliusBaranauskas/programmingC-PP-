#include <iostream>

using namespace std;

int main()
{
    double n;
    double a, b, c , d, sum;
    cin >> n;
    cin >> a >> b >> c >> d;
    sum = (a+b*(0.8)+c*(0.5)+d*(0.3))/n;
    cout << sum;
    return 0;
}
