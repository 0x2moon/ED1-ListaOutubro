#ifndef LLSIMPLES_H
#define LLSIMPLES_H

struct llsimples
{
    int size;
    struct llnode *start;
};

struct llnode
{
    char *nome;
    struct llnode *next;
};

struct llsimples *create_llsimples();
struct llnode *create_llnode();
void destroy_llsimples(struct llsimples **lls);

char *sAlloc(char *namepoint);
int __get_Size(struct llsimples *lls);
int __isEmpty(struct llsimples *lls);

void add_first(struct llsimples *lls, char *value);
void add_lest(struct llsimples *lls, struct llnode *lln, char *value);
void remove_all(struct llnode *lln);
void print_lls(struct llnode *lln);
#endif