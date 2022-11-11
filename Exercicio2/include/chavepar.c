#include <stdio.h>
#include <stdlib.h>
#include "./../lib/chavepar.h"

struct cpar{
    int size;
    struct cpnode *start;
};

struct cpnode{
    int chave;
    bool ispar;
    struct cpnode *next;
};

struct cpar *create_cpar(){
    struct cpar *new = (struct cpar *) malloc (sizeof(struct cpar));
    new->start = NULL;
    new->size  = 0;
    return new;
}

struct cpnode *create_cpnode(){
    struct cpnode *new = (struct cpnode *) malloc (sizeof(struct cpnode));
    new->ispar = false;
    new->next  = NULL;
}

struct cpnode *get_cpnode_start(struct  cpar* cparr){
    return cparr->start;
}

int get_size(struct cpar*  cparr){
    return cparr->size;
}

int get_value(struct cpnode* cpnodee){
    return cpnodee->chave;
}

int __isEmpty(struct cpar* cparr){

    if (cparr->size == 0 && cparr->start == NULL)
    {
        return 1;
    }
    return 0;
}

bool set_bool_ispar(struct cpnode *cp){
    if (cp->chave % 2 == 0)
    {
       return cp->ispar = true;
    }
    return cp->ispar = false;
}

bool get_bool_ispar(struct cpnode *cp){
    return cp->ispar;
}

void add_last(struct cpar* cparr, struct cpnode* cpnodee, int value){
    
    if (__isEmpty(cparr) == 1)
    {   
        cparr->start = create_cpnode();
        cparr->start->chave = value;
        set_bool_ispar(cparr->start);
        cparr->size++;
        return;
    }

    if(cpnodee->next == NULL){
        cpnodee->next = create_cpnode();
        cpnodee->next->chave = value;
        set_bool_ispar(cpnodee->next);
        cparr->size++;
        return;
    }
    add_last(cparr, cpnodee->next, value);
}

void destroy_cpar_removeAllnodes(struct cpar **cparr, struct cpnode *cpnodee){
    if(get_size(*cparr) == 0){
        (*cparr)->start = NULL;
        free(*cparr);
        free(cparr);
        return;
    }

    if(cpnodee->next != NULL){   
        destroy_cpar_removeAllnodes(cparr, cpnodee->next);
    }
    free(cpnodee->next);
        (*cparr)->size--;

}

void print_lls(struct cpnode *cpnodee){
    if (cpnodee != NULL)
    {
        fprintf(stdout, " %d => ", get_value(cpnodee));
        print_lls(cpnodee->next);
    }else{
        puts(" NULL ");
    }   
}

void remove_Allnodes_valuespar(struct cpar *cparr, struct cpnode *cpnodee){
    
    if (get_size(cparr) == 0){
        return;
    }

    if(get_bool_ispar(cpnodee->next) == true){
        struct cpnode *aux = create_cpnode();
        aux = cpnodee->next;
        cpnodee->next = cpnodee->next->next;
        cparr->size--;
        free(aux);
        aux = NULL;
    }
   
    if(cpnodee->next != NULL){
        remove_Allnodes_valuespar(cparr,cpnodee->next);
   
    }else{
   
        if(get_bool_ispar(cparr->start) == true){
        struct cpnode *aux_start = cparr->start->next;
        free(cparr->start);
        cparr->start = aux_start;
        cparr->size--;
        aux_start = NULL;
        }
    }   
}