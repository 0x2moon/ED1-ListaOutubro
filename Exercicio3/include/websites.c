#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../lib/websites.h"

struct websites{
    int size;
    struct websites_node *start;
};

struct websites_node{
    char *website_nome;
    char *website_link;
    struct websites_node *next;
};

char *sAlloc(char *_string){
    char *_stringAlloc = (char *) malloc (strlen(_string)*sizeof(char));
    return _stringAlloc;
}

struct websites *create_websites(){
    struct websites *new = (struct websites *) malloc (sizeof(struct websites));
    new->start = NULL;
    new->size = 0;
    return new;
}

struct websites_node *__create_websites_node(){
    struct websites_node *new = (struct websites_node *) malloc (sizeof(struct websites_node));
    new->website_nome = NULL;
    new->website_link = NULL;
    new->next = NULL;
    return new;
}

struct websites_node *get_websites_node_start(struct websites* wb){
    return wb->start;
}

struct websites_node *get_websites_node_end(struct websites_node* wbnodes){
    if (wbnodes->next == NULL)
    {
        return wbnodes;
    }
    get_websites_node_end(wbnodes->next);
}

char *get_name_websites(struct websites_node* wbnodes){
    return wbnodes->website_nome;
}

char *get_link_websites(struct websites_node* wbnodes){
    return wbnodes->website_link;
}

int get_size(struct websites* wb){
    return wb->size;
}

int __isEmpty(struct websites* wb){
    if (wb->size == 0 && wb->start == NULL)
    {
        return 1;
    }
    return 0;
}

void add_last(struct websites* wb, struct websites_node* wbnodes, char *nome, char *link){
    if (__isEmpty(wb) == 1)
    {   
        wb->start = __create_websites_node();
        wb->start->website_nome = sAlloc(nome);
        wb->start->website_nome = nome;
        wb->start->website_link = sAlloc(link);
        wb->start->website_link = link;
        wb->size++;
        return;
    }

    if(wbnodes->next == NULL){
        wbnodes->next = __create_websites_node();
        wbnodes->next->website_nome = sAlloc(nome);
        wbnodes->next->website_link = sAlloc(link);
        wbnodes->next->website_nome = nome;
        wbnodes->next->website_link = link;
        wb->size++;
        return;
    }
    add_last(wb, wbnodes->next, nome, link);
}

void destroy_wb_removeAllnodes(struct websites **wb, struct websites_node* wbnodes){
     if(get_size(*wb) == 0){
        (*wb)->start = NULL;
        free(*wb);
        free(wb);
        return;
    }

    if(wbnodes->next != NULL){   
        destroy_wb_removeAllnodes(wb, wbnodes->next);
    }
    free(wbnodes->next);
        (*wb)->size--;
}

void search_websites(struct websites *wb, struct websites_node* wbnodes, char* value){
    if(wbnodes != NULL){
     
     if (strncmp(get_name_websites(wb->start), value, strlen(value)) == 0)
        {
            fprintf(stdout, "========================================================\nWebsite Nome: %s\nWebsite link: %s", get_name_websites(wb->start),get_link_websites(wb->start));
            return;
           
        }        
    if (strncmp(get_name_websites(wbnodes->next), value, strlen(value)) == 0)
        {
            fprintf(stdout, "========================================================\nWebsite Nome: %s\nWebsite link: %s", get_name_websites(wbnodes->next),get_link_websites(wbnodes->next));
            struct websites_node *aux = __create_websites_node();
            aux = wbnodes->next;
            wbnodes->next = wbnodes->next->next;
            aux->next = wb->start;
            wb->start = aux;
            return;

        }
        search_websites(wb,wbnodes->next,value);   
    }
}


void print_lista_websites(struct websites_node* wbnodes){
    if (wbnodes != NULL)
    {
        fprintf(stdout, "\n========================================================\n\nWebsite Nome: %s\nWebsite link: %s\n", get_name_websites(wbnodes),get_link_websites(wbnodes));
        print_lista_websites(wbnodes->next);
    }else{
        puts("\n========================================================\nNULL\n========================================================\n");
    }   
}