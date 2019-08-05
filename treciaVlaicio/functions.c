#include "functions.h"

void convert(char text[], char output[]){
  int a = 0;
  FILE *fOut;
  fOut = fopen(output, "a");
  int i;
  for (i = 0; i < 255; i++) {
    if(text[i] != " "){
      a = 0;
      /*
      for(int d = 0; d < 255; d++){
        word[d] = null;
      }*/
      char *word[255];
      for (i; i < 255; i++) {
        if(text != " "){
        word[a] = text[i]; a++;} else{  break;}
      }
      int z;
      for (z = 0; z < 255; z++) {
        if((a+1)/2 < z+1){
            int m;
          for (m = 0; m < 255; m++) {
            if (*word[m] == NULL) {
              break;
            }else{
              fprintf(fOut, word[m]);
            }
          }
          break;
        }
        if(word[a-z] != word[z]){
            break;
        }
      }
    }
  }

}