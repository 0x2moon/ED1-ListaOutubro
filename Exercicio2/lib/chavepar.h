#ifndef CHAVEPAR_H
#define CHAVEPAR_H
#include <stdbool.h>

struct cpar;
struct cpnode;

struct cpar *create_cpar();
struct cpnode *create_cpnode();

struct cpnode *get_cpnode_start(struct  cpar* cparr);
int get_size(struct cpar*  cparr);
int get_value(struct cpnode* cpnodee);

int __isEmpty(struct cpar* cparr);

bool set_bool_ispar(struct cpnode *cp);
bool get_bool_ispar(struct cpnode *cp);

void add_last(struct cpar* cparr, struct cpnode* cpnodee, int value);
void remove_Allnodes_valuespar(struct cpar *cparr, struct cpnode *cpnodee);
void destroy_cpar_removeAllnodes(struct cpar **cparr, struct cpnode *cpnodee);

void print_lls(struct cpnode *cpnodee);
#endif