#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

int isItPalindrome(char *word, int length);

void findWords(char *line, int longline, FILE *fOut){
    int lengthLine;
    if(longline){lengthLine = strlen(line);}
        else{lengthLine = strlen(line)-1;}
    int x;
    char word[lengthLine];
    int wordIndex = 0;
    int i;
    for(x = 0; x < lengthLine; x++){
        if(line[x] == ' ' || x == lengthLine-1){
            if(wordIndex != 0){
                if(isItPalindrome(word, wordIndex)){    wordIndex = 0;}
                    else{  for(i = 0; i < wordIndex;i++){fputc((int)word[i],fOut);}  fputc((int)' ', fOut); wordIndex = 0;}
            }
        }else{
            word[wordIndex] = line[x];
            wordIndex++;
        }
    }
}

int isItPalindrome(char *word, int length){
    if(length==1){  return true;}
int i = 0;
printf("%s\n", word);
for(; i < length/2; i++){
    if(word[i] != word[length-1-i]){    return false;}
}
return true;
}

void dummyRead(FILE *fileIn){
if(fgetc(fileIn) != '\n'){
 dummyRead(fileIn);
}else{
return;
}
}

int main(int argc, char* argv[]) {
    if(argc != 3){  printf("wrong parameters\nexiting");
        return -1;}
	char *fileIN = argv[1];
	char *fileOUT = argv[2];
	FILE *fIn;
	FILE *fOut;
	fIn = fopen(fileIN, "r");
    fOut = fopen(fileOUT, "w");
    int length = 257;
    char line[length];
    while(1){
        fgets(line, length, fIn);
        if(strlen(line) == 256){
            printf("yes\n");
            findWords(line, false,fOut);
            dummyRead(fIn);
        }else{
            findWords(line, true, fOut);
        }
        printf("Length is: %d\n", strlen(line));
        if(feof(fIn)){
            break;
        }
        fprintf(fOut, "\n");
    }
	return 0;
}
