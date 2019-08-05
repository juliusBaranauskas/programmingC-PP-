#include<iostream>
#include<stdio.h>

using namespace std;

struct element
{
    int color;
    int closest;
};


int main(){
    int t;
    int n;
    cin >> t;
    int i;
    int jumps = n-1;
    int maxJump, maxInd;
    int j;
    int current;
    for(int x = 0; x < t; x++){
        scanf("%d", &n);
        maxJump = 1;
        maxInd = 0;
        element elements[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", &elements[i].color);
            elements[i].closest = -1;
        }
        for(i = 0; i < n-2; i++)
        {
            current = elements[i].color;
            for(j = i+1; j < n; j++)
            {
                if(elements[j].closest != -1){
                    j = elements[j].closest;
                    continue;
                }
                if(current == elements[j].color){
                    if(j-i > maxJump){
                        maxJump = j-i;
                        elements[maxInd].closest = -1;
                        elements[i].closest = j;
                        maxInd = i;
                    }
                    break;
                }
            }
        }
    jumps-=(elements[maxInd].closest-maxInd-1);
    maxJump = 1;
    maxInd = i+1;
        
    }
    return 0;
}