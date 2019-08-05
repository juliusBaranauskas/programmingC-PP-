#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"


int main()
{
    int action;
    int brk = 0;
    char value;
    char newElementMsg[] = "\nValue of the new element: ";
    Queue *que = NULL;
    void *nod;
    
    que = createEmptyQueue();
    enqueue(que, "afa");
    enqueue(que, "b");
    printQueue(*que);
    printf("\n");
    dequeue(que);
    printQueue(*que);
    printf("\n");
    enqueue(que, "zaf");
    printQueue(*que);
    printf("\n");
    /*
    while(!brk){
        scanf("%d", &action);
        switch(action){
            case 0:
                brk=1;
                break;
            case 1:
                que = createEmptyQueue();
                break;
            case 2:
                if(checkEmpty(*que)){	printf("\tQueue empty\n");
                }else{	printf("\tQueue NOT empty\n");}       
                break;
            case 3:
                printf("%s", newElementMsg);
                scanf("%c", &value);
                enqueue(que, value);
                break;
            case 4:
                printQueue(*que);
                break;
            case 5:
                nod = dequeue(que);
                if(nod != NULL)
                    printf("\nElement dequeued: %c\n", nod);
                break;
            case 6:
                printf("First element: %c", getFirst(*que));
                break;
            case 7:
                printf("Queue length: %d\n", getQueueLength(*que));
                break;
            default:
                break;
            case 8:
                empty(que);
                break;
            }
    }
    */
    return 0;
}
