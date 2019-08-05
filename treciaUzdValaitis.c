#include<stdio.h>
#include<stdlib.h>

void convert(char text[], char output[]){
  int a = 0;
  char word[255];
  int nope = 0;
  int consecutiveSpaces = 0;
  FILE *fOut;
  fOut = fopen(output, "a");
  for (int i = 0; i < 255; i++) {
    if(text[i] != " "){
      consecutiveSpaces++;
      if(consecutiveSpaces == 5){
        break;
      }
      int a = 0; // whataaattatta
      for (i; i < 255; i++) {
        if(text != " "){
        word[a] = text[i]; a++;} else{  break;}
      }
      consecutiveSpaces = 0;
      for (int z = 0; z < 255; z++) {
        if((a+1)/2 < z+1){
          for (int m = 0; m < 255; m++) {
            if (word[m] == null) {
              break;
            }else{
              fprint(fOut, word[m]);
            }
          }
          break;
        }
        if(word[a-z] == word[z]){

        }else{
          break;
          nope = 1;
        }
      }
    }
  }

}

int main(int argc, char const *argv[]) {
  char io[3];
  char * buffer = null;
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
  //fscanf(fIn, "%s", text);
  if(!feof(fIn)){
    getline(buffer, length, fIn)
    convert(text, io[1]);
  }

  return 0;
}
