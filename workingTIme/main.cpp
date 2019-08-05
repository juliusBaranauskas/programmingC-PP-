#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

   string nuo, iki;
   int periodsT;
   int dienos, effLaikas;
   int valandos, minutes;



   cin >> periodsT;


   for (int x=0; x<periodsT; x++)
    {
        valandos =0;
        minutes = 0;

  cin >> dienos >> effLaikas;
   for (int y=0;y<dienos; y++)
   {
       cin >> nuo >> iki;
valandos += iki[0]*10+iki[1]-(nuo[0]*10+nuo[1]);
if (iki[0]*10+iki[1]!=(nuo[0]*10+nuo[1]))
{
	if(iki[3]*10+iki[4]-(nuo[3]*10+nuo[4]) < 0){
	minutes += -1*(iki[3]*10+iki[4]-(nuo[3]*10+nuo[4]));
}else{
    minutes += iki[3]*10+iki[4]-(nuo[3]*10+nuo[4]);
}
}
else
    {
    minutes += iki[3]*10+iki[4]-(nuo[3]*10+nuo[4]);
    }
   }

   valandos += minutes/60;
   if (valandos >= effLaikas)
   {
       cout <<"YES" << endl;
   }
   else
   {
       cout <<"NO" << endl;
   }

    }
   }
