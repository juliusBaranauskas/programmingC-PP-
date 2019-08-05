#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void funkcija(int x, int *y){
    x*=*y;
}

typedef struct Kids{
    int age;
    char*ha;
}kids;

struct Studentas{
char var[80], pav[80], dom[80];
int sem;
char *email;
};

char* join_strs(char* s1, char* s2, char c){
char *ptr = malloc(strlen(s1)+strlen(s2)+2);
strcpy(ptr, s1);
*(ptr+strlen(s1))=c;
strcpy(ptr+strlen(s1)+1, s2);
return ptr;
}

void inc_sem(int *n){
*n++;
}

int main()
{
    /*
    int masyvas[4]={0, 5, 2, 3};
    int *pInt, **pInt2;
    pInt2 = &pInt;
    int length;
    scanf("%i", &length);
    pInt = malloc(length*sizeof(int));
    int x;
    int temp;
    for(x = 0; x < length; x++){
        scanf("%i", &temp);
        pInt[x] = temp;
    }
    scanf("%i", &temp);
    pInt = realloc(pInt, (temp+length)*sizeof(int));
    length+=temp;
    for(x = 0; x < length; x++){
        printf("\n%d", pInt[x]);
    }
    printf("\n%d", *pInt);
    */

//    int a = 10;
//    int *b= &a;
//    int *c= &b;
//    funkcija(*c);
//    int ab[3] = {1, 2, 3};
//    int z = 1;
//    printf("%d", z[ab]);
//
//    kids kid;
//    kid.age = 5;
//    printf("%d", kid.age);


//    int array[2]={1, 2};
//    int *pointer=array;
//    *(array+1) = *pointer +1;
    //printf("%d", *array);
    int i=1, j=2;
    //funkcija(i, &j);
    int *ptr= &i;
    j=*ptr++;
    printf("%d %d", i, j);

    struct Studentas st;
    *st.var="Julius";
    *st.pav = "Baranauskas";
    *st.dom="mif.vu.lt";
    *st.email=join_strs(&st.var, &st.pav, '.');
    *st.email=join_strs(&st.email, &st.dom, '@');
    printf("%s", st.email);
    return 0;
}
