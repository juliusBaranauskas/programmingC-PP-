#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool findPath(vector<long int> elements, long int sum, long int at, long int sumNeeded, long int m, vector<long int> chosen);

int main(){
    ifstream fIn("input.txt"); // input file first line: n(number of elements) m(sum of m elements) s(sum value)
    long int n, m;              // second line: n natural numbers
    long int s;
    fIn >> n;
    vector<long int> numbers;
    long int num;
    fIn >> m >> s;
    if(n < 1 || m < 1 || s < 0){
        cout << "WRONG INPUT" << endl;
        fIn.close();
        return 0;
    }
    for(long int i = 0; i < n; i++)
    {
        fIn >> num;
        if(num <= s){
            numbers.push_back(num);
        }
    }
    if(m > numbers.size()){
        cout << "THERE ARE NO SUCH " << m << " ELEMENTS THAT WOULD ADD UP TO " << s <<endl;
        fIn.close();
        return 0;
    }

    { // SORTING VECTOR
        long int minIndex;
        long int minNum;
        long int atX;
        for(long int x = 0;  x < numbers.size()-1; x++){
            minIndex = x;
            minNum = numbers[x];
            for(long int i = x+1; i < numbers.size(); i++){
                if(numbers[i] < minNum){
                    minNum = numbers[i];
                    minIndex = i;
                }
            }
            atX = numbers[x];
            numbers[x] = minNum;
            numbers[minIndex] = atX;
        }
    }
    long int suma = 0;
    if(numbers.size() > m){
    for(int i = numbers.size()-1; i > numbers.size()-m-1; i--){
        suma+=numbers[i];
    }
    if(suma < s){
        cout << "THERE ARE NO SUCH " << m << " ELEMENTS THAT WOULD ADD UP TO " << s <<endl;
        return 0;
    }
    }
    suma = 0;
        if(!(numbers.size() <= m)){
            for(long int i = 0; i < m-1; i++){   suma+=numbers[i];   }
            
            n = numbers.size()-1;
            while(true){
                if(suma+numbers[n] == s){
                    cout << "NUMBERS: ";
                    for(long int x = 0; x < m-1; x++){   cout << numbers[x] << " ";}
                    cout << numbers[n] << " ADDS UP TO: " << s << endl;
                    fIn.close();
                    return 0;
                }else if(suma+numbers[n] > s){
                    numbers.erase(numbers.begin()+n);
                    if(numbers.size() == m){
                        break;
                    }
                    n--;
                }else{
                    break;
                }
                if(n == m-2){
                    break;
                }
            }
        }
        /*
    for(long int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;*/

    vector<long int> chosen;
    findPath(numbers, 0, 0, s, m, chosen);
    cout << "NO MORE SUMS FOUND\n";
    fIn.close();
    return 0;
}

bool findPath(vector<long int> elements, long int sum, long int at, long int sumNeeded, long int m, vector<long int> chosen){

    while(at <= elements.size()-(m-chosen.size())){
        
        if (chosen.size() < m && sum < sumNeeded) {
            vector<long int> newChosen = chosen;
            newChosen.push_back(elements[at]);  
            findPath(elements, sum+elements[at], at+1, sumNeeded, m, newChosen);
        }else if(chosen.size() == m){
            if(sum == sumNeeded)
            {
                for(long int x = 0; x < m; x++){
                    if(x != 0){
                        cout << "+ ";
                    }
                    cout << chosen[x] << " ";
                }
                cout << " EQUALS TO " << sumNeeded << endl;
                return true;
                
            }else{  return false;   }
        }
        at++;
    }
    return false;
}