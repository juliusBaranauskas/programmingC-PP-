#include <stdio.h>
#include <stdlib.h>

void versk(char line[]){
    printf(line);

}

int main(int argc, char *argv[])
{
    /*char fileNames[3];
    if(argc != 3){
        printf("Wrong paramaeters\n");
        return -1;
    }*/
    //char *fileIn = argv[1];
    //char *fileOut = argv[2];

    char *fileIn = "input.txt";
    char *fileOut = "output.txt";
    int length = 255;
    char line[255];

    FILE *fIn;
    FILE *fOut;
    fIn = fopen(fileIn, "r");
    fOut = fopen(fileOut, "w");
    while(fgets(line, length, fIn)){
        versk(line);
        fprintf(fOut, line);

    }
    return 0;
}
