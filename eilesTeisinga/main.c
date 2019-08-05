#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"

int main()
{
    Queue *que = NULL;    
    que = createEmptyQueue();
    int x;
    for(x = 0; x < 3; x++){
        enqueue(que, x);
    }
    enqueue(que, 1);
    enqueue(que, 420);
    dequeue(que);
        dequeue(que);

    dequeue(que);

    printf("%d ", *getFirst(que));
    printf("\n");
    dequeue(que);
    enqueue(que, 69);
    for(x = 0; x < 2; x++){
        dequeue(que);
    }
    if(getFirst(que) == NULL){
    printf("%s\n", "empty");
    }

    return 0;
}
