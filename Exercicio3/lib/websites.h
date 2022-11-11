#ifndef WEBSITES_H
#define WEBSITES_H

struct websites;
struct websites_node;

struct websites *create_websites();
struct websites_node *__create_websites_node();

struct websites_node *get_websites_node_start(struct websites* wb);
struct websites_node *get_websites_node_end(struct websites_node* wbnodes);
char *get_name_websites(struct websites_node* wbnodes);
char *get_link_websites(struct websites_node* wbnodes);
int get_size(struct websites* wb);

char *sAlloc(char *_string);
int __isEmpty(struct websites* wb);

void add_last(struct websites* wb, struct websites_node* wbnodes, char *nome, char *link);
void destroy_wb_removeAllnodes(struct websites **wb, struct websites_node* wbnodes);

void search_websites(struct websites *wb, struct websites_node* wbnodes, char* value);
void print_lista_websites(struct websites_node* wbnodes);
#endif