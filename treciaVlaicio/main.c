#include<stdio.h>
#include<stdlib.h>
#include "functions.h"


int main(int argc, char const *argv[]) {
  char io[3];
  char * buffer = NULL;
  int length = 0;
  if (argc != 3) {
    printf("Too many or too few args. \nExiting...");
    exit(1);
  }
  io[0] = argv[1];
  io[1] = argv[2];
  char line[255];
  FILE *fIn;
  fIn = fopen(io[0], "r");
  fscanf(fIn, "%s", line);
  if(!feof(fIn)){
    //getline(buffer, length, fIn);
    convert(line, io[1]);
  }

  return 0;
}
