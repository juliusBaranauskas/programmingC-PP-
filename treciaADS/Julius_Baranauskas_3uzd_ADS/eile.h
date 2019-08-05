#ifndef EILE_H_INCLUDED
#define EILE_H_INCLUDED
#include "header.h"

typedef Plane* priority_queue_type;

typedef struct sarasas{
    priority_queue_type reiksme;
    int prioritetas;
    struct sarasas *kitas;
}*Mazgas;

typedef struct pe{
    Mazgas pradzia;
    int kiek;
}*priority_queue;//prioritetine eile apibrezia pointeri i pe

priority_queue Sukurti_eile();
int Ar_Tuscia(priority_queue);
void Ideti_Elementa( priority_queue ,priority_queue_type ,int ,int *);
void Isimti_Elementa(priority_queue p, int *err, priority_queue_type *reiksme);
void Virsune(priority_queue , priority_queue_type *, int * );
void Ilgis(priority_queue, int *, int *);
void Sunaikinti_Eile(priority_queue, int *);
void Salinti_Pagal_Prioriteta (priority_queue, int *);
#endif // EILEE_H_INCLUDED
