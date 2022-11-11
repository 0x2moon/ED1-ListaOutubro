#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "./../lib/llsimples.h"
#define EXERCICIO 1
#define ADD 8

int main(){
    fprintf(stdout,"\nExercicio -> %d,\nConteudo da execução do binario do programa estadentro de TAG \"<numero do exercico>\"\nSegue a saida completa do terminal o programa:\n\n< %d >\n\n",EXERCICIO,EXERCICIO);
    struct llsimples *listasimples = create_llsimples();
    //lista simples 
    for(int i = 0; i <= ADD; i++){
        add_lest(listasimples, get_start(listasimples), "valor");
    }
    //teste não recursivo
    add_first(listasimples,"Testando lista 1");
    struct llsimples *listasimples2 = create_llsimples();
    //lista simples 
    for(int i = 0; i <= ADD-3; i++){
        add_lest(listasimples2, get_start(listasimples2), "valor");
    }
    //teste não recursivo
    add_first(listasimples2,"Testando lista 2");
    //print recursivo
    puts(" Lista Ligada Simples 1:\n");
    print_lls(get_start(listasimples));
    destroy_llsimples(&listasimples);

    puts("\n\n Lista Ligada Simples 2:\n");
    print_lls(get_start(listasimples2));
    destroy_llsimples(&listasimples2);

    fprintf(stdout,"\n\n< %d >\n\n",EXERCICIO);
    return 0;
}