#include <stdio.h>
#include <stdlib.h>
#include "./../lib/ltelefonica.h"

int main(){
   
    struct ltelefonica *weblista = create_ltelefonica();
    add_last(weblista, get_ltelefonica_node_start(weblista), "Youtube","+55 67 9 9988-7766","Avenida A");
    add_last(weblista, get_ltelefonica_node_start(weblista), "AAAA",   "+55 67 9 9988-7766","Avenida A");
    add_last(weblista, get_ltelefonica_node_start(weblista), "yyyyy",  "+55 67 9 9988-7766","Avenida A");
    add_last(weblista, get_ltelefonica_node_start(weblista), "uube",   "+55 67 9 9988-7766","Avenida A");
    add_last(weblista, get_ltelefonica_node_start(weblista), "out",    "+55 67 9 9988-7766","Avenida A");
    add_last(weblista, get_ltelefonica_node_start(weblista), "ybe",    "+55 67 9 9988-7766","Avenida A");
    add_last(weblista, get_ltelefonica_node_start(weblista), "yte",    "+55 67 9 9988-7766","Avenida A");
    print_lista_ltelefonica(get_ltelefonica_node_start(weblista));
  
    puts("\n\n\n pesquisando OUT\n\n");
    search_ltelefonica(weblista,get_ltelefonica_node_start(weblista),"out");
    puts("\n\n\n pesquisando yte\n\n");
    search_ltelefonica(weblista,get_ltelefonica_node_start(weblista),"yte");
    puts("\n\n\n imprimindo\n\n");
    print_lista_ltelefonica(get_ltelefonica_node_start(weblista));
    puts("\n\n\n remover\n\n");
    remove_Onenode(weblista,get_ltelefonica_node_start(weblista),"uube");
    remove_Onenode(weblista,get_ltelefonica_node_start(weblista),"AAAA"); 
    puts("\n\n\nimprimindo\n\n\n");
    print_lista_ltelefonica(get_ltelefonica_node_start(weblista));
    destroy_lt_removeAllnodes(&weblista, get_ltelefonica_node_start(weblista));
    return 0;
}