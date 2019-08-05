#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"


Node *newElement(void *value){
    Node *elem = (Node*)malloc(sizeof(Node));
    elem->next = NULL;
    elem->value = value;
    return elem;
}

Queue *createEmptyQueue(){
    Queue *que = (Queue*)malloc(sizeof(Queue));
    que->front = que->back = NULL;
    return que;
}

int enqueue(Queue *que, void *value){
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

void *dequeue(Queue *que){
    if(que == NULL){    printf("FIRST CREATE QUEUE!\n"); return NULL;}
    if(que->front == NULL){
        printf("Queue EMPTY\n");
        return NULL;
    }
    Node *temporary = que->front->next;
    void *temp = que->front->value;
    free(que->front);
    que->front = temporary;
    if(que->front == NULL){
        que->back = NULL;
    }
    return temp;
}


void printQueue(Queue que){
    if(que.front == NULL){    printf("FIRST CREATE QUEUE!\n"); return;}
    Node *temp = que.front;
    if(temp == NULL){
        printf("\nEmpty\n");
        return;
    }
    while(temp != NULL){
        printf("%p ", temp->value);
        temp = temp->next;
    }
}

int checkEmpty(Queue que){
    if(que.front == NULL){
        printf("FIRST CREATE QUEUE!\n");
        return 1;
    }else
        return 0;
}

void *getFirst(Queue que){
    if(que.front == NULL){  printf("Queue EMPTY\n");  return NULL; }
    return  que.front->value;
}

int getQueueLength(Queue que){
    if(que.front == NULL){  printf("QUEUE EMPTY!\n");   return 0; }
    int i = 0;
    Node *tmp = que.front;
    while(tmp != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

void empty(Queue *que){
    while(dequeue(que) != NULL);
}