#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



struct photoData{
vector<string> tags; // tags names
short int tagsN; // Number of tags
int ID; // ID
int ID2 = 0;
//bool pos;  // Vertical - 1 or Horizontal - 0
};





int main()
{
int N, k; // Numbers of photos
char VH;
bool Vertical;
string tag;
vector<photoData> photoesH;
vector<photoData> photoesV;
photoData photo;

fstream fs ("duom.txt");
ofstream fd ("rez.txt");

fs >> N;

for (int x = 0; x < N; x++ )
{
    fs >> VH; // givin position
    if (VH == 'V') Vertical = 1;
    else Vertical = 0;

    fs >> photo.tagsN; // giving tag num

   // cout << x << endl;
photo.ID = x;




photo.tags.clear();

    for (int y=0 ;y<photo.tagsN; y++)
    {
        fs >> tag;
        photo.tags.push_back(tag);

    }

    if (Vertical == 1)
    {
        for (int y=0; y<photoesV.size(); y++) // lookin for spot
        {
            if (photo.tagsN > photoesV[y].tagsN)
            {
                photoesV.insert(photoesV.begin()+y,  photo);
                break;
            }
            else if ( y+1 == photoesV.size())
            {
                photoesV.push_back(photo);
                break;
            }

        }
    }
    else
    {
         for (int y=0; y<photoesH.size(); y++) // lookin for spot
        {
            if (photo.tagsN > photoesH[y].tagsN)
            {
                photoesH.insert(photoesH.begin()+y,  photo);
                break;
            }
            else if ( y+1 == photoesH.size())
            {
                photoesH.push_back(photo);
                break;
            }

        }
    }
    if (photoesV.size() == 0 && Vertical == 1)
  {
      photoesV.push_back(photo);
  }

  else if (photoesH.size() == 0 && !Vertical)
  {
     photoesH.push_back(photo);
  }


}

///  foras kuris sumeta dvi vertikales i viena ir imeta i photoesh

for(int x = 0; x < photoesV.size()/2; x++){
    photoData phot;
    phot.ID = photoesV[x].ID;
    phot.ID2 = photoesV[photoesV.size()-1-x].ID;
    phot.tagsN = photoesV[photoesV.size()-1-x].tagsN + photoesV[x].tagsN;

    for (int y=0; y<photoesH.size(); y++) // lookin good
        {
            if (phot.tagsN > photoesH[y].tagsN)
            {
                photoesH.insert(photoesH.begin()+y,  phot);
                break;
            }
            else if ( y+1 == photoesH.size())
            {
                photoesH.push_back(phot);
                break;
            }

        }

}



fd << photoesH.size() << "\n";
for (int x=0; x<photoesH.size(); x++)
{
 fd << photoesH[x].ID ;
 if (photoesH[x].ID2 != 0 ) fd << " " << photoesH[x].ID2;

 fd << "\n";
}
fd << endl;










    return 0;
}