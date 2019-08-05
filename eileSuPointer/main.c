#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"


int main()
{
    Queue *que = NULL;    
    que = createEmptyQueue(-1);
    double a;
    enqueue(que, 2.7);
    a = dequeue(que);
    if(a != que->errVal){
        printf("%.2f ", a);
    }
    enqueue(que, 8.216);
    a = dequeue(que);
    if(a != que->errVal){
        printf("%.2f ", a);
    }
    enqueue(que, 21);
    a = dequeue(que);
    if(a != que->errVal){
        printf("%.2f ", a);
    }
    a = getFirst(que);
    if(a != que->errVal){
        printf("%.2f ", a);
    }
    if(getFirst(que) == que->errVal){
    printf("%s\n", "empty");
    }
    enqueue(que, 2.1);
    printf("%d", checkEmpty(que));
    empty(que);
    return 0;
}
