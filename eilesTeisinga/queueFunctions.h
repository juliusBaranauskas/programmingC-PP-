#ifndef queueFunctions_H_
#define queueFunctions_H_
#define dataType int

typedef struct node{
    dataType value;
    struct node *next;
}Node;

typedef struct queue{ // when instantiating a queue must set its pointer value to NULL
    Node *front;
    Node *back;
}Queue;


struct queue *createEmptyQueue(); // creates and returns empty queue on success, NULL on failure

int enqueue(Queue*, dataType); // returns 0 on success, -1 on failure

dataType *dequeue(Queue*); // returns NULL pointer on failure, pointer to element value on success

int checkEmpty(Queue*); // returns 1 if it is empty, 0 otherwise

dataType *getFirst(Queue*); // returns first element value, NULL on failure

int getQueueLength(Queue*); // returns queue length. If it's empty returns 0

void empty(Queue*); // empties queue

#endif

