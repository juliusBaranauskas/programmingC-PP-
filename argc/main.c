#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    for(int x = 0; x < argc; x++){
            printf("%d variable: %s", x, argv[x]);
    }
    return 0;
 }
