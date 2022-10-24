#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../lib/llsimples.h"

struct llsimples *create_llsimples(){
    struct llsimples *llnew = (struct llsimples *) malloc (sizeof(struct llsimples));
    llnew->size  = 0;
    llnew->start = NULL;
    return llnew;    
}

struct llnode *create_llnode(){
    struct llnode *llnewnode = (struct llnode *) malloc (sizeof(struct llnode));
    return llnewnode;
}
void destroy_llsimples(struct llsimples **lls){
    struct  llsimples *laux = create_llsimples();
    laux = *lls;
    remove_all(laux->start);
    free(*lls);
    *lls = NULL;
}

char *sAlloc(char *namepoint){
    char *nome = (char *) malloc (strlen(namepoint)*sizeof(char));
    return nome;
}

int __get_Size(struct llsimples *lls){
    return lls->size;
}

int __isEmpty(struct llsimples *lls){
    if (lls->size == 0 && lls->start == NULL)
     {
        return 1;
     }
    return 0;
}

void add_first(struct llsimples *lls, char *value){
  struct llnode *lln = create_llnode();
    if (__isEmpty(lls) == 1)
    {
        lls->start = lln;
        lln->next  = NULL;

    }else{
        lln->next  = lls->start;
        lls->start = lln;
    }
    lln->nome = sAlloc(value);
    lln->nome = value;
    lls->size++;
    
}

void add_lest(struct llsimples *lls, struct llnode *lln, char *value){
    if (__isEmpty(lls) == 1)
    {
        struct llnode *llnew = create_llnode();
        lls->start = llnew;
        llnew->next = NULL;
        llnew->nome = sAlloc(value);
        llnew->nome = value;

    }else{

        if (lln->next == NULL)
        {
            struct llnode *llnew = create_llnode();
            lln->next   = llnew;
            llnew->next = NULL;
            llnew->nome = sAlloc(value);
            llnew->nome = value;
            lls->size++;
        }else{
            add_lest(lls, lln->next, value);
        }
    }
}


void remove_all(struct llnode *lln){
    struct llnode *llnaux = create_llnode();
    llnaux = lln;
    if (llnaux != NULL){
        remove_all(llnaux->next);       
    }
    free(llnaux);
    puts("+ um free");
}

void print_lls(struct llnode *lln){
    if (lln != NULL){
        printf(" -> %s ", lln->nome);
        print_lls(lln->next);
    }
    else{  
        printf(" -> NULL ");
    }
    
}

