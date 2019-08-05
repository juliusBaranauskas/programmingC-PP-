#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "func.h"
#include "eile.h"
#include "header.h"


Plane *spawnPlane(BigInt *probOfPlane, BigInt *lDuration, BigInt *tDuration, int tim, int id);
 
void printMsg(int addOr, int tim, FILE *ptr, int id, int takeOff){
    char msg[15];
    char land[10];
    if(addOr == 1){
        strcpy(msg, "added to");
    }else{
        strcpy(msg, "deleted from");
    }
    if(takeOff == 1){
        strcpy(land, "takingOff");
    }else{
        strcpy(land, "landing");
    }
    fprintf(ptr, "Plane num %d %s is %s queue at time %d", id, land, msg, tim);
    if(addOr == 0){
        fprintf(ptr,"--------------------------");
    }
    fprintf(ptr,"\n\n");
}

int main(){

    BigInt *takeOffDuration;
    BigInt *landingDuration;
    BigInt *fuelLeftFor;
    BigInt *probabilityOfPlane;

    BigInt *longestLanding = naujasSkaicius("0");
    BigInt *numberOfLandings = naujasSkaicius("0");
    BigInt *longestTakeOff = naujasSkaicius("0");
    BigInt *numberOfTakeOffs = naujasSkaicius("0");
    BigInt *sumOfTakeOffs = naujasSkaicius("0");
    BigInt *sumOfLandings = naujasSkaicius("0");
    char eilute[256];

    int *eror = malloc(sizeof(int));
    FILE *fIn = fopen("output.txt", "w");

    printf("Enter plane take-off duration:\n");
    scanf("%s", eilute);
    takeOffDuration = naujasSkaicius(eilute);

    printf("Enter plane landing duration:\n");
    scanf("%s", eilute);
    landingDuration = naujasSkaicius(eilute);

    printf("Enter probability of wild plane appearing:\n");
    scanf("%s", eilute);
    if(strlen(eilute) > 3){
        printf("WRONG INPUT\n");
        return -1;
    }
    probabilityOfPlane = naujasSkaicius(eilute);

    printf("Enter the ammount of fuel left in the gas tank in minutes: \n");
    scanf("%s", eilute);
    fuelLeftFor = naujasSkaicius(eilute);

    int tim = 0;
    priority_queue planeQueue = Sukurti_eile();
    int id = 0;
    char curTime[10];
    srand(time(NULL));
    
    Plane *newPlane;
    BigInt *timeTook = malloc(sizeof(BigInt));


//////////////////////////////////////////////
        while(tim < 1440){
        newPlane = spawnPlane(probabilityOfPlane, landingDuration, takeOffDuration, tim, id);
        
        if(newPlane != NULL){
            if(newPlane->takeOff){
                if(planeQueue->kiek != 0){
                    Ideti_Elementa(planeQueue, newPlane, 0, eror);
                        if(*eror != 0){ printf("FAILED ADDING ELEMENT\n"); return -1;}
                    printMsg(1, tim, fIn, newPlane->id, newPlane->takeOff);
                }else{
                    Ideti_Elementa(planeQueue, newPlane, 2, eror);
                        if(*eror != 0){ printf("FAILED ADDING ELEMENT\n"); return -1;}
                    printMsg(1, tim, fIn, newPlane->id, newPlane->takeOff);
                }
            }else{
                if(planeQueue->kiek != 0){
                    Ideti_Elementa(planeQueue, newPlane, 1, eror);
                        if(*eror != 0){ printf("FAILED ADDING ELEMENT\n"); return -1;}
                    printMsg(1, tim, fIn, newPlane->id, newPlane->takeOff);
                }else{
                    Ideti_Elementa(planeQueue, newPlane, 2, eror);
                        if(*eror != 0){ printf("FAILED ADDING ELEMENT\n"); return -1;}
                    printMsg(1, tim, fIn, newPlane->id, newPlane->takeOff);
                }    
            }
            id++;
        }else{
            printf("NO NEW PLANE at time %d\n", tim);
        }
        
        Virsune(planeQueue, &newPlane, eror);
        if(*eror == -1){
            printf("NO EXISTING QUEUE\n");
            return -1;
        }
        if(*eror == 1){
            tim++;
            continue;
        }
        
        
        sprintf(curTime, "%d", tim);
        if(!(newPlane->takeOff)){
            if(palyginti(atimti(naujasSkaicius(curTime), newPlane->timeOfAppearance), fuelLeftFor) == 1){ // ilgiau manevruoja nei yra kuro
                printf("Plane crashed. Appearance time: %s\nTime of crash: %d\n", toString(newPlane->timeOfAppearance), tim);
                return 0;
            }
        }
        if(palyginti(newPlane->timeOfAppearance, naujasSkaicius(curTime)) != 0){
            newPlane->maneouverTime = atimti(newPlane->maneouverTime, naujasSkaicius("1"));
        }
        Plane *firstPlane;
        if(palyginti(newPlane->maneouverTime, naujasSkaicius("0")) == 0){
            Isimti_Elementa(planeQueue, eror, &newPlane);
                if(*eror == -1){    printf("NO EXISTING QUEUE\n"); return -1; }
            printMsg(0, tim, fIn, newPlane->id, newPlane->takeOff);
            Isimti_Elementa(planeQueue, eror, &firstPlane);
                if(*eror == -1){    printf("NO EXISTING QUEUE\n"); return -1; }
            if(*eror == 0){
                Ideti_Elementa(planeQueue, firstPlane, 2, eror);
            }
            timeTook = atimti(naujasSkaicius(curTime), newPlane->timeOfAppearance);
            if(newPlane->takeOff){
                if(palyginti(timeTook, longestTakeOff) == 1){
                    kopijuotiSkaiciu(longestTakeOff, timeTook);
                }
                numberOfTakeOffs = sudeti(numberOfTakeOffs, naujasSkaicius("1"));
                sumOfTakeOffs = sudeti(sumOfTakeOffs, timeTook);
            }else{
                if(palyginti(timeTook, longestLanding) == 1){
                    kopijuotiSkaiciu(longestLanding, timeTook);
                }
                numberOfLandings = sudeti(numberOfLandings, naujasSkaicius("1"));
                sumOfLandings = sudeti(sumOfLandings, timeTook);
            }
        }
        tim++;
        
    }
    printf("AVG takeOff time: %s mins\n", toString(padalinti(sumOfTakeOffs, numberOfTakeOffs)));
    printf("AVG landing time: %s mins\n", toString(padalinti(sumOfLandings, numberOfLandings)));
    printf("Longest landing: %s\n", toString(longestLanding));
    printf("Longest takeOff: %s\n", toString(longestTakeOff));

    while(!Ar_Tuscia(planeQueue)){
        Isimti_Elementa(planeQueue, eror, &newPlane);
        printf("DELETING PLANE No.%d\n", newPlane->id);
    }

    return 0;
} 

Plane *spawnPlane(BigInt *probOfPlane, BigInt *lDuration, BigInt *tDuration, int tim, int id){
    char randNumber[10];
    sprintf(randNumber, "%d", rand()%100);
    printf("Generated rand = %s prob = %s\n", randNumber, toString(probOfPlane));
    BigInt *num = naujasSkaicius(randNumber);
    if(palyginti(probOfPlane, num) == 1){
        Plane *newPlane = malloc(sizeof(Plane));
        sprintf(randNumber, "%d", tim);
        newPlane->timeOfAppearance = naujasSkaicius(randNumber);
        newPlane->id = id;
        newPlane->takeOff = (rand()%100) > 49 ? 1 : 0;
        newPlane->maneouverTime = (BigInt*)malloc(sizeof(BigInt*));
        newPlane->takeOff ? kopijuotiSkaiciu(newPlane->maneouverTime, tDuration) : kopijuotiSkaiciu(newPlane->maneouverTime, lDuration);
        printf("%d\n", newPlane->takeOff);  
        return newPlane;
    }else{
        return NULL;
    }
}