#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct entry{
char *value;
int length;
}Entry;

int main()
{
    Entry *Entries;
    Entries = calloc(1, sizeof(Entry));
    FILE *fp;
    fp = fopen("code.txt", "r");
    char *symbols;
    symbols = malloc(20);
    int i;
    int pzdc = FALSE;
    int index = 0;
    int x = 0;
    char *number;
    int realNum;
    char a;
    //printf("%d ",x);
    while((*symbols = fgetc(fp)) != EOF){
            i=1;
            while(TRUE){
                *(symbols+i) = fgetc(fp);
                if(*(symbols+i) == EOF){
                    pzdc = TRUE;
                    break;
                }
                if(*(symbols+i)> 47 && *(symbols+i) < 58){
                    i++;
                }else{
                    number = malloc(10);
                    strncpy(number, symbols, i);
                    realNum = atoi(number);
                    a = *(symbols+i);
                    Entries = realloc(Entries, (index+1)*sizeof(Entry));
                    if(realNum){
                        Entries[index].length = Entries[realNum-1].length+1;
                        Entries[index].value = malloc(Entries[index].length);
                        strcpy(Entries[index].value, Entries[realNum-1].value);
                        Entries[index].value[Entries[realNum-1].length] = a;
                    }else{
                    Entries[index].value = malloc(1);
                    Entries[index].length = 1;
                    *(Entries[index].value) = a;
                    }
                    for(x=0; x < Entries[index].length; x++)
                        printf("%c", Entries[index].value[x]);
                    index++;
                    free(symbols);
                    break;
                }
            }
            symbols = malloc(20);
            if(pzdc){   break;}
    }
    free(symbols);
    free(Entries);
    return 0;
}
