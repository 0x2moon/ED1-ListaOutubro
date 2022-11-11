#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../lib/ltelefonica.h"

struct ltelefonica{
    int size;
    struct ltelefonica_node *start;
};

struct ltelefonica_node{
    char *ltelefonica_nome;
    char *ltelefonica_adress;
    char *ltelefonica_num;
    struct ltelefonica_node *next;
};

char *sAlloc(char *_string){
    char *_stringAlloc = (char *) malloc (strlen(_string)*sizeof(char));
    return _stringAlloc;
}

struct ltelefonica *create_ltelefonica(){
    struct ltelefonica *new = (struct ltelefonica *) malloc (sizeof(struct ltelefonica));
    new->start = NULL;
    new->size = 0;
    return new;
}

struct ltelefonica_node *__create_ltelefonica_node(){
    struct ltelefonica_node *new = (struct ltelefonica_node *) malloc (sizeof(struct ltelefonica_node));
    new->ltelefonica_nome = NULL;
    new->ltelefonica_num = NULL;
    new->next = NULL;
    return new;
}

struct ltelefonica_node *get_ltelefonica_node_start(struct ltelefonica* lt){
    return lt->start;
}

struct ltelefonica_node *get_ltelefonica_node_end(struct ltelefonica_node* ltnodes){
    if (ltnodes->next == NULL)
    {
        return ltnodes;
    }
    get_ltelefonica_node_end(ltnodes->next);
}

char *get_name_ltelefonica(struct ltelefonica_node* ltnodes){
    return ltnodes->ltelefonica_nome;
}

char *get_adress_ltelefonica(struct ltelefonica_node* ltnodes){
    return ltnodes->ltelefonica_adress;
}

char *get_num_ltelefonica(struct ltelefonica_node* ltnodes){
    return ltnodes->ltelefonica_num;
}

int get_size(struct ltelefonica* lt){
    return lt->size;
}

int __isEmpty(struct ltelefonica* lt){
    if (lt->size == 0 && lt->start == NULL)
    {
        return 1;
    }
    return 0;
}

void add_last(struct ltelefonica* lt, struct ltelefonica_node* ltnodes, char *nome, char *adress, char *num){
    if (__isEmpty(lt) == 1)
    {   
        lt->start = __create_ltelefonica_node();
        lt->start->ltelefonica_nome = sAlloc(nome);
        lt->start->ltelefonica_nome = nome;
        lt->start->ltelefonica_adress = sAlloc(adress);
        lt->start->ltelefonica_adress = adress;
        lt->start->ltelefonica_num = sAlloc(num);
        lt->start->ltelefonica_num = num;
        lt->size++;
        return;
    }

    if(ltnodes->next == NULL){
        ltnodes->next = __create_ltelefonica_node();
        ltnodes->next->ltelefonica_nome = sAlloc(nome);
        ltnodes->next->ltelefonica_num  = sAlloc(num);
        ltnodes->next->ltelefonica_adress = sAlloc(adress);
        ltnodes->next->ltelefonica_adress = adress;
        ltnodes->next->ltelefonica_nome   = nome;
        ltnodes->next->ltelefonica_num    = num;
        lt->size++;
        return;
    }
    add_last(lt, ltnodes->next, nome, adress, num);
}

void destroy_lt_removeAllnodes(struct ltelefonica **lt, struct ltelefonica_node* ltnodes){
     if(get_size(*lt) == 0){
        (*lt)->start = NULL;
        free(*lt);
        free(lt);
        return;
    }

    if(ltnodes->next != NULL){   
        destroy_lt_removeAllnodes(lt, ltnodes->next);
    }
    free(ltnodes->next);
        (*lt)->size--;
}

void search_ltelefonica(struct ltelefonica *lt, struct ltelefonica_node* ltnodes, char* value){
    if(ltnodes != NULL){
     
     if (strncmp(get_name_ltelefonica(lt->start), value, strlen(value)) == 0)
        {
            fprintf(stdout, "\n========================================================\nLista telefonica Nome: %s\nLista telefonica Numero: %s\nLista telefonica endereco: %s\n", get_name_ltelefonica(ltnodes->next),get_num_ltelefonica(ltnodes->next), get_adress_ltelefonica(ltnodes->next));
            return;
           
        }        
    if (strncmp(get_name_ltelefonica(ltnodes->next), value, strlen(value)) == 0)
        {
            fprintf(stdout, "\n========================================================\nLista telefonica Nome: %s\nLista telefonica Numero: %s\nLista telefonica endereco: %s\n", get_name_ltelefonica(ltnodes->next),get_num_ltelefonica(ltnodes->next), get_adress_ltelefonica(ltnodes->next));
            struct ltelefonica_node *aux = __create_ltelefonica_node();
            aux = ltnodes->next;
            ltnodes->next = ltnodes->next->next;
            aux->next = lt->start;
            lt->start = aux;
            return;

        }
        search_ltelefonica(lt,ltnodes->next,value);   
    }
}

void remove_Onenode(struct ltelefonica *lt, struct ltelefonica_node* ltnodes, char* value){
    search_ltelefonica(lt,ltnodes,value);
    puts("\n========================================================\nElemento removido.");
    struct ltelefonica_node *aux = __create_ltelefonica_node();
    aux = lt->start;
    lt->start = NULL;
    lt->start = aux->next;
    free(aux);
}

void print_lista_ltelefonica(struct ltelefonica_node* ltnodes){
    if (ltnodes != NULL)
    {
        fprintf(stdout, "\n========================================================\nLista telefonica Nome: %s\nLista telefonica Numero: %s\nLista telefonica endereco: %s\n", get_name_ltelefonica(ltnodes),get_num_ltelefonica(ltnodes), get_adress_ltelefonica(ltnodes));
        print_lista_ltelefonica(ltnodes->next);
    }else{
        puts("\n========================================================\nNULL\n========================================================\n");
    }   
}