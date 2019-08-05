#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct node{
	int value;
	struct node* nextNode;
} node_type;

void addNode(node_type *head, int val){
    node_type *currentNode = head;
	while(currentNode->nextNode != NULL){
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = malloc(sizeof(node_type));
	currentNode->nextNode->value = val;
	currentNode->nextNode->nextNode = NULL;
	return;
}

void deleteNth(node_type * head, int n){
    if(n < 1){
        printf("No such position %d exists", n);
        return;
    }
    if(n == 1){
        if(head->nextNode == NULL){
            printf("List contains one element: %d I ain't deletin that. Naaw man\n", head->value);
            return;
        }
        head->value = head->nextNode->value;
        head->nextNode = head->nextNode->nextNode;
        return;
    }
    int i = 0;
    while(i != n-2){
        head = head->nextNode;
        i++;
    }
    node_type *nodeToFree = head->nextNode;
    head->nextNode = head->nextNode->nextNode;
    free(nodeToFree);
    return;
}

void deleteByValue(node_type * head, int val, int listSize){
    if(head->nextNode == NULL){
        printf("List contains one element: %d\n", head->value);
        return;
    }
    while(head->value == val){
        head->value = head->nextNode->value;
        head->nextNode = head->nextNode->nextNode;
        (listSize)--;
        if(head->nextNode == NULL){
            printf("Leaving single element > %d < in the list\n", head->value);
            return;
        }
    }
    while(head->nextNode->value != val){
        head = head->nextNode;
        if(head->nextNode == NULL){
            return;
        }
    }
    node_type *nodeToFree = head->nextNode;
    head->nextNode = head->nextNode->nextNode;
    free(nodeToFree);
    (listSize)--;
    if(head->nextNode == NULL){
        return;
    }
    deleteByValue(head, val, &listSize);
}

void deleteSmallest(node_type *head){
int notTheOnly = 0;
int smallest;
int smallestIndex = 1;
int smalInd = 1;
node_type *currentNode = head;
smallest = currentNode->value;
while(currentNode->nextNode != NULL){
    if(currentNode->value < smallest){
        smallest = currentNode->value;
        smalInd = smallestIndex;
    }
    smallestIndex++;
    currentNode = currentNode->nextNode;
    notTheOnly = 1;
}
if(currentNode->value < smallest){
    smallest = currentNode->value;
    smalInd = smallestIndex;
}
if(!notTheOnly){
    printf("List contains one element: %d I ain't deletin that. Naaw man\n", head->value);
    return;
}
deleteNth(head, smalInd);
return;
}

void addSorted(node_type * head, int val){
    node_type *biggestPtr = head;
    biggestPtr->value = head->value;
    node_type *currentNode = head;

    // SORT OR SMTH
}

void deleteList(node_type *head){
    node_type *realHead = head;
    while(head->nextNode!=NULL){
        deleteSmallest(head);
    }
    free(head);
}

void printList(node_type * head){
    int i = 1;
while(head->nextNode!= NULL){
    printf("%d value = %d\n", i, head->value);
    head = head->nextNode;
    i++;
}
printf("%d value = %d\n", i, head->value);
return;
}

void clrscr(){  system("@cls||clear");}


int main(){
	node_type* head = NULL;
	head = malloc(sizeof(node_type));
	head->value = 0;
	head->nextNode = NULL;
	int listSize = 1;
	int *ptrSize = &listSize;
	char command;
	//command = malloc(sizeof(char)); // MALLOCint
	int value;
	while(1){
		printf("\nEnter \"a\" to add a node\nEnter \"q\" to quit the program\nEnter \"d\" to delete nth list element\nEnter \"p\" to print the list\nEnter \"c\" to clear screen\nEnter \"v\" to delete element by value\nEnter \"s\" to delete lowest element by value\n");
		scanf("%s", &command);
		if(command == 'q'){
            printf("quiting\n");
			break;
		}else if(command == 'a'){
            printf("Enter value: ");
			scanf("%d", &value);
			addNode(head, value);
			listSize++;
		}else if(command == 'd'){
            printf("Enter which element you want to delete: ");
			scanf("%d", &value);
			if(listSize < value){
                printf("There is no such element %d in the list %d\n", value, &ptrSize);
			}else{
			deleteNth(head, value);
			listSize--;
			}
		}else if(command == 'p'){
			printList(head);
		}else if(command == 'v'){
		    printf("Enter what value(s) you want to delete: ");
			scanf("%d", &value);
			deleteByValue(head, value, &ptrSize);
		}else if(command == 's'){
			deleteSmallest(head);
		}else if(command == 'c'){
		clrscr();
		}
	}
	deleteList(head);
    return 0;
}
