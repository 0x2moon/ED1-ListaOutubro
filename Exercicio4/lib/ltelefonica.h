#ifndef LTELEFONICA_H
#define LTELEFONICA_H

struct ltelefonica;
struct ltelefonica_node;

struct ltelefonica *create_ltelefonica();
struct ltelefonica_node *__create_ltelefonica_node();

struct ltelefonica_node *get_ltelefonica_node_start(struct ltelefonica* lt);
struct ltelefonica_node *get_ltelefonica_node_end(struct ltelefonica_node* ltnodes);
char *get_name_ltelefonica(struct ltelefonica_node* ltnodes);
char *get_adress_ltelefonica(struct ltelefonica_node* ltnodes);
char *get_num_ltelefonica(struct ltelefonica_node* ltnodes);
int get_size(struct ltelefonica* lt);

char *sAlloc(char *_string);
int __isEmpty(struct ltelefonica* lt);

void add_last(struct ltelefonica* lt, struct ltelefonica_node* ltnodes, char *nome, char *adress, char *num);
void destroy_lt_removeAllnodes(struct ltelefonica **lt, struct ltelefonica_node* ltnodes);
void remove_Onenode(struct ltelefonica *lt, struct ltelefonica_node* ltnodes, char* value);

void search_ltelefonica(struct ltelefonica *lt, struct ltelefonica_node* ltnodes, char* value);
void print_lista_ltelefonica(struct ltelefonica_node* ltnodes);
#endif