#include <stdio.h>
#include <stdlib.h>
#include "./../lib/llsimples.h"
#define SIZE 8

int main(){
    struct llsimples *listasimples = create_llsimples();

    add_lest(listasimples, listasimples->start, "numero 3 final");
    add_lest(listasimples, listasimples->start, "numero 2 final");
    add_first(listasimples,"numero dois");
    add_lest(listasimples, listasimples->start, "numero 7 final");
    add_lest(listasimples, listasimples->start, "numero 3 final");
    add_lest(listasimples, listasimples->start, "numero 2 final");
    add_lest(listasimples, listasimples->start, "numero 7 final");
    add_lest(listasimples, listasimples->start, "numero 3 final");
    add_lest(listasimples, listasimples->start, "numero 2 final");
    add_lest(listasimples, listasimples->start, "numero 7 final");
  
    print_lls(listasimples->start);
    destroy_llsimples(&listasimples);
    
    return 0;
}