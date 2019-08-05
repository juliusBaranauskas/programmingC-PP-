#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"


Node *newElement(dataType value){
    Node *elem = (Node*)malloc(sizeof(Node));
    elem->next = NULL;
    elem->value = value;
    if(elem == NULL){
        return NULL;
    }else
        return elem;
}

Queue *createEmptyQueue(){
    Queue *que = (Queue*)malloc(sizeof(Queue));
    que->front = que->back = NULL;
    if(que != NULL){
        return que;
    }else
        return NULL;
}

int enqueue(Queue *que, dataType value){
    if(que == NULL){    printf("FIRST CREATE QUEUE!\n"); return -1;}
    Node *elem = newElement(value);
    if(que->back == NULL){
        que->back = que->front = elem;
        return 0;
    }
    que->back->next = elem;
    que->back = elem;
    return 0;
}

dataType *dequeue(Queue *que){
    if(que == NULL){    printf("FIRST CREATE QUEUE!\n"); return NULL;}
    if(que->front == NULL){
        printf("Queue EMPTY\n");
        return NULL;
    }
    Node *temporary = que->front->next;
    dataType *temp = &(que->front->value);
    free(que->front);
    que->front = temporary;
    if(que->front == NULL){
        que->back = NULL;
    }
    return temp;
}

int checkEmpty(Queue *que){
    if(que == NULL){
        printf("FIRST CREATE QUEUE!\n");
        return -1;
    }
    if(que->front == NULL){
        printf("FIRST CREATE QUEUE!\n");
        return 1;
    }else
        return 0;
}

dataType *getFirst(Queue *que){
    if(que == NULL){    printf("FIRST CREATE QUEUE!\n");    return NULL;}
    if(que->front == NULL){  printf("Queue EMPTY\n");  return NULL; }
    dataType *temp = &(que->front->value);
    return temp;
}

int getQueueLength(Queue *que){
    if(que == NULL){    printf("FIRST CREATE QUEUE!\n");    return -1;}
    if(que->front == NULL){  printf("QUEUE EMPTY!\n");   return 0; }
    int i = 0;
    Node *tmp = que->front;
    while(tmp != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

void empty(Queue *que){
    while(dequeue(que) != NULL);
}