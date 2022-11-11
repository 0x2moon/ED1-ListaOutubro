#include <stdio.h>
#include <stdlib.h>
#include "./../lib/chavepar.h"
#define EXERCICIO 2
#define ADD 8

int main(){
    fprintf(stdout,"\nExercicio -> %d,\nConteudo da execução do binario do programa estadentro de TAG \"<numero do exercico>\"\nSegue a saida completa do terminal o programa:\n\n< %d >\n\n",EXERCICIO,EXERCICIO);
    puts("\nLista Ligada Simples 1:\n(size = par) ->\n");
    struct cpar * chavepar = create_cpar(); 
    for(int i = 0; i <= ADD; i++){
        add_last(chavepar,get_cpnode_start(chavepar), i+2);
    }
    print_lls(get_cpnode_start(chavepar));
    puts("\nLista Ligada Simples 1:\nSem os numeros pares ->\n\n");

    remove_Allnodes_valuespar(chavepar,get_cpnode_start(chavepar));
    print_lls(get_cpnode_start(chavepar));
    destroy_cpar_removeAllnodes(&chavepar,get_cpnode_start(chavepar));
    
    puts("\nLista Ligada Simples 2:\n(size = impar) ->\n");
    struct cpar * chavepar2 = create_cpar(); 
    for(int i = 0; i <= ADD-3; i++){
        add_last(chavepar2,get_cpnode_start(chavepar2), i+3);
    }
    print_lls(get_cpnode_start(chavepar2));
    puts("\nLista Ligada Simples 2:\nSem os numeros pares ->\n\n");

    remove_Allnodes_valuespar(chavepar2,get_cpnode_start(chavepar2));
    print_lls(get_cpnode_start(chavepar2));
    destroy_cpar_removeAllnodes(&chavepar2,get_cpnode_start(chavepar2));

    fprintf(stdout,"\n\n< %d >\n\n",EXERCICIO);
    return 0;
}