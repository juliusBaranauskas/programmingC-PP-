#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eile.h"
#include "header.h"

priority_queue Sukurti_eile()
{
    priority_queue p = malloc(sizeof(struct pe));
    if (p != NULL)
    {
        p->pradzia = NULL;
        p->kiek =0;
    }
    return p;
}

int Ar_Tuscia(priority_queue p)
{
    if(p == NULL)
        return -1;//eile nebuvo sukurta
    else if(p->kiek != 0)
        return 0;//netuscia eile
    else
		return 1;//tuscia eile
}

void Ideti_Elementa(priority_queue p, priority_queue_type reiksme, int prioritetas, int *err)
{
    if (p != NULL) {
        Mazgas n = malloc (sizeof(struct sarasas));
        if(n == NULL)
        {
            *err=1;//negalima isskirti atminties naujam elementui
            return;
        }
        else
        {
            Mazgas prev = NULL;
            Mazgas now = p -> pradzia;
            while (now != NULL && now->prioritetas >= prioritetas)
            {
                prev = now;
                now = now->kitas;
            }
            n->reiksme = reiksme;
            n->prioritetas = prioritetas;
            n->kitas = now;
            if (prev == NULL)
            {
                p -> pradzia = n;
            }
            else
            {
                prev -> kitas = n;
            }

            p->kiek++;
            *err=0;//sekmingai
            return;
        }
    }
    else
    {
        *err = -1;//eile nebuvo sukurta
        return;
    }

}
void Isimti_Elementa(priority_queue p, int *err, priority_queue_type *reiksme)
{
    if (p != NULL)
    {
        if (p->pradzia == NULL)
        {
            *err = 1; //eile tuscia
            return;
        }
        else
        {
            *reiksme = p -> pradzia -> reiksme;
            Mazgas n = p -> pradzia;
            p -> pradzia = p -> pradzia -> kitas;
            free(n);
            p -> kiek--;
            *err = 0;//sekmingai
            return;
        }
    }
    else
    {
        *err = -1; //eile nebuvo sukurta
    }
}

void Virsune(priority_queue p, priority_queue_type *reiksme, int *err)
{
    
    if (p != NULL)
    {
        if (p->pradzia != NULL)
        {
            *reiksme = p->pradzia->reiksme;
            *err = 0; //sekmingai
            return;
        }
        else
        {
            *err = 1; //eile tuscia
            return;
        }
    }
    else
    {
        *err = -1;//eile nebuvo sukurta
        return;
    }

}
void Ilgis(priority_queue p, int *err, int *kiek)
{
    if (p != NULL)
    {
        if (p->pradzia != NULL)
        {
            *kiek = p->kiek;
            *err = 0;//sekmingai
            return;
        }
        else
        {
            *err = 1; //eile tuscia
            return;
        }
    }
    else
    {
        *err = -1;//eile nebuvo sukurta
        return;
    }
}

void Sunaikinti_Eile(priority_queue p, int *err)
{
    if (p != NULL)
    {
        Mazgas n = p -> pradzia;
        while (n != NULL)
        {
            Mazgas kitas = n -> kitas;
            free(n);
            n = kitas;
        }
        p -> kiek = 0;
        *err = 0;//sekmingai
        return;
    }
    else
    {
        *err = -1;//eile nebuvo sukurta
        return;
    }
}
void Salinti_Pagal_Prioriteta (priority_queue p, int *err)
{
    if (p != NULL)
    {
        if (p->pradzia == NULL)
        {
            *err = 1; //eile tuscia
            return;
        }
        else
        {
            int prior = p -> pradzia -> prioritetas;
            while (p->pradzia!=NULL && p->pradzia->prioritetas == prior)
            {

                    Mazgas n = p -> pradzia;
                    p -> pradzia = p -> pradzia -> kitas;
                    free(n);
                    p -> kiek--;
                    *err = 0;//sekmingai
            }
            return;
        }
    }
    else
    {
        *err = -1;
        return;
    }





}
