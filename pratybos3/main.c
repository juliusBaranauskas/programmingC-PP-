#include <stdio.h>
#include <stdlib.h>

void byRef(int *a){
printf(a);
printf("\n");
}

void byRef2(int *a){
printf(&a);
printf("\n");
}

void byVal(int a){
printf(&a);
printf("\n");
}
void byVal2(int a){
printf(a);
printf("\n");
}

int main()
{
    int a = 5;
    printf(&a);
    printf("\n");
    byRef(a);
    byRef2(a);
    byVal(a);
    byVal2(a);
    return 0;
    }
}
