#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void *value;
    struct node *next;
}Node;

typedef struct vector{
    Node *front;
    Node *back;
}Vector;

Node *newElement(void *value){
    Node *elem = (Node*)malloc(sizeof(Node));
    elem->next = NULL;
    elem->value = value;
    return elem;
}

Vector *createEmptyVector(){
    Vector *vec = (Vector*)malloc(sizeof(Vector));
    vec->front = vec->back = NULL;
    return vec;
}

void enVector(Vector *vec, void *value){
    Node *elem = newElement(value);
    if(vec->back == NULL){
        vec->back = vec->front = elem;
        return;
    }
    vec->back->next = elem;
    vec->back = elem;
}

void *deVector(Vector *vec){
    if(vec == NULL){    printf("FIRST CREATE VECTOR!\n"); return NULL;}
    if(vec->front == NULL){
        return NULL;
    }
    Node *temporary = vec->front->next;
    void *temp = vec->front->value;
    free(vec->front);
    vec->front = temporary;
    if(vec->front == NULL){
        vec->back = NULL;
    }
    return temp;
}


void printVector(Vector vec){
    Node *temp = vec.front;
    if(temp == NULL){
        printf("\nEmpty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

int checkEmpty(Vector vec){
    if(vec.front == NULL){
        return 1;
    }else return 0;
}

int getFirst(Vector vec){
    return vec.front == NULL ? -1 : vec.front->value;
}

int getLast(Vector vec){
    return vec.back == NULL ? -1 : vec.back->value;
}

int getVectorLength(Vector vec){
    if(vec.front == NULL){
        return 0;
    }
    int i = 0;
    Node *tmp = vec.front;
    while(tmp != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

void *getElement(Vector vec, int at){
    if(vec.front == NULL){
        printf("\nEmpty\n");
        return -1;
    }
    int i = 1;
    Node *temp = vec.front;
    while(at != i){
        temp = temp->next;
        if(temp == NULL){
            printf("\nNo such index in vector\n");
            return -1;
        }
        i++;
    }
    return temp->value;
}

void *removeElementAt(Vector *vec, int at){
    if(at == 1){    deVector(vec);  return;}
    if(vec->front == NULL){
        printf("\nEmpty\n");
        return;
    }
    int i = 1;
    Node *temp = vec->front;
    while(at-1 != i){
        temp = temp->next;
        if(temp == NULL){
            printf("\nNo such index in vector\n");
            return;
        }
        i++;
    }
    if(temp->next != NULL){
        temp->next = temp->next->next;
    }else{
        printf("\nNo such index in vector\n");
        return NULL;
    }
}

void *insertElementAt(Vector *vec, void *value, int at){
    if(at == 1){
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->next = vec->front;
        tmp->value = value;
        vec->front = tmp;
        return;
    }
    if(vec->front == NULL){
        printf("\nEmpty\n");
        return NULL;
    }
    int i = 1;
    Node *temp = vec->front;
    while(at-1 != i){
        temp = temp->next;
        if(temp == NULL){
            printf("\nNo such index in vector\n");
            return NULL;
        }
        i++;
    }
    Node *tnp = (Node*)malloc(sizeof(Node));
    tnp->value = value;
    tnp->next = temp->next;
    temp->next = tnp;
}

void printOptions(){
    printf("\nPress 0 to exit");
    printf("\nPress 1 to create an empty Vector");
    printf("\nPress 2 to check if the Vector is empty");
    printf("\nPress 3 to push back a new element to the Vector");
    printf("\nPress 4 to print the elements");
    printf("\nPress 5 to remove first element");
    printf("\nPress 6 get first element value");
    printf("\nPress 7 to get Vector length");
    printf("\nPress 8 to remove element at chosen point");
    printf("\nPress 9 to get an element value at chosen point");
    printf("\nPress 10 to insert an element at chosen index");
    printf("\nOption: ");
}

int main()
{
    int action;
    int brk = 0;
    int value;
    int otheInt;
    char newElementMsg[] = "\nValue of the new element: ";
    Vector *vecto = NULL;
    Node *nod;
    /* enVector(vecto, 'a');
    enVector(vecto, 'a');
    enVector(vecto, 'a'); */
    vecto = createEmptyVector();
    enVector(vecto, 'a');
    enVector(vecto, 'b');
    printVector(*vecto);
    printf("\n");
    deVector(vecto);
    printVector(*vecto);
    printf("\n");
    enVector(vecto, 'z');
    insertElementAt(vecto, 12, 2);
    printVector(*vecto);
    printf("\n");
    /*
    while(!brk){
        printOptions();
        scanf("%d", &action);
        switch(action){
            case 0:
                brk=1;
                break;
            case 1:
                vecto = createEmptyVector();
                break;
            case 2:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("\t%d\n", checkEmpty(*vecto));
                break;
            case 3:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("%s", newElementMsg);
                scanf("%d", &value);
                enVector(vecto, value);
                break;
            case 4:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printVector(*vecto);
                break;
            case 5:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                //if(nod = deVector(vecto) != NULL)
                    printf("\nElement deVectord: %p\n", deVector(vecto));
                break;
            case 6:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("First element: %d", getFirst(*vecto));
                break;
            case 7:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("Vector length: %d", getVectorLength(*vecto));
                break;
            case 8:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("%s", "\nwhich to remove\n");
                scanf("%d", &value);
                removeElementAt(vecto, value);
                break;
            case 9:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("%s", "\nwhich to get\n");
                scanf("%d", &value);
                getElement(*vecto, value);
                break;
            case 10:
                if(vecto == NULL){    printf("FIRST CREATE Vector!\n"); continue;}
                printf("%s", "\nwhere to insert\n");
                scanf("%d", &otheInt);
                printf("%s", "\nwhat value\n");
                scanf("%d", &value);
                insertElementAt(vecto, value, otheInt);
                break;
            default:
                break;
            }
    }
    */
    return 0;
}
