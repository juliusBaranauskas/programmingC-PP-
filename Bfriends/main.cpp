#include <iostream>

using namespace std;

int main()
{
    int T;
    int n;
    long long int x;
    cin >> T;
    long long int sum = 0;
    int z;
    for(int i = 0; i < T; i++){
            if(i != 0){
                cout <<endl;
            }
        cin >> x >> n;
        if(n == 1){
              cout << x;
        }else{
        if(x <= n){
                for(z = 0; z < n; z++){
                    if(z != 0){
                        cout <<" ";
                    }
                  if(z < x){
                    cout << "1";
                  } else{ cout << "0"; }
                }
        }else{
           sum = ((x-n)/(n-1))+1;
           if(sum % 2==0){
            for(z = 0; z < n; z++){
                if(z != 0){
                        cout <<" ";
                    }
                if(z == 0){
                        cout << sum-(sum/2)+1;
                    }else if(z == n-1){
                        cout << sum-(sum/2);
                        }else if(z < x-((sum-1)*(n-1)+n)+1 && z != 0){
                        sum++;
                        cout << sum;
                        sum--;
                    }else{
                        cout << sum;
                    }

                }
           }else{
              for(z = 0; z < n; z++){
                    if(z != 0){
                       cout << " ";
                    }
                    if(z ==0 || z == n-1){
                        cout << sum-(sum/2);
                    }else if(z > n-(x-((sum-1)*(n-1)+n))-1-1 && z!= n-1){
                        sum++;
                        cout << sum;
                        sum--;
                    }else{
                        cout << sum;
                    }
                }
           }

        }

        }
    }

    return 0;
}
