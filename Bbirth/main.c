#include <stdio.h>
#include <stdlib.h>

struct Birthday{
int day;
int diff;
};

int main()
{
    int n;
    scanf("%d", &n);
    int x;
    char name[20];
    int arr[n-1];
    struct Birthday birthdays[n];
    int day, mm, sum;
    for(x = 0; x < n; x++){
        scanf("%s%d%c%d", &name, &mm, &name, &day);
        birthdays[x].day = day + (mm/2)*31 +
            (mm-(mm/2)-1)*30;
        if(mm>2){
            birthdays[x].day-=2;
        }
        if(birthdays[x].day <= 300){
            birthdays[x].diff = 300 - birthdays[x].day;
        }else{
            birthdays[x].diff = birthdays[x].day-300;
        }
    }
    short int lowDiff;
    int index;
    int fake;
    for(x = 0; x < n-1; x++){
        lowDiff = birthdays[x].day;
        index = x;
        for(y = x+1; y < n; y++){
            if(birthdays[y].day < lowDiff){
                lowDiff = birthdays[y].day;
                index = y;
            }
        }
        fake = birthdays[x].day;
        birthdays[x].day = lowDiff;
        birthdays[index].day = fake;
    }
    lowDiff = 367;
    for(x = 1; x < n; x++){

    }

    return 0;
}
