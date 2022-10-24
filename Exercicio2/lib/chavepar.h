#ifndef CHAVEPAR_H
#define CHAVEPAR_H

struct cpar
{
    int size;
    struct cpnode *start;
};

struct cpnode
{
    char *nome;
    struct cpnode *next;
};

struct cpar *create_cpar();
struct cpnode *create_cpnode();
void destroy_cpar(struct cpar **lls);

char *sAlloc(char *namepoint);
int __get_Size(struct cpar *lls);
int __isEmpty(struct cpar *lls);

void add_first(struct cpar *lls, char *value);
void add_lest(struct cpar *lls, struct cpnode *lln, char *value);
void remove_all(struct cpnode *lln);
void print_lls(struct cpnode *lln);
#endif