#include <stdio.h>
#include <stdlib.h>
#include "./../lib/ltelefonica.h"

int main(){
   
    struct ltelefonica *lista_telefonica = create_ltelefonica();
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Alano","+55 67 9 9988-7766","Avenida A");
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Blano",   "+55 67 9 9988-7766","Avenida A");
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Clano",  "+55 67 9 9988-7766","Avenida A");
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Dlano",   "+55 67 9 9988-7766","Avenida A");
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Elano",    "+55 67 9 9988-7766","Avenida A");
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Fulano",    "+55 67 9 9988-7766","Avenida A");
    print_lista_ltelefonica(get_ltelefonica_node_start(lista_telefonica));
    print_ficheiro(lista_telefonica, get_ltelefonica_node_start(lista_telefonica));
    
    add_last(lista_telefonica, get_ltelefonica_node_start(lista_telefonica), "Glano",    "+55 67 9 9988-7766","Avenida A");
    print_ficheiro(lista_telefonica, get_ltelefonica_node_end(lista_telefonica));

    print_lista_ltelefonica(get_ltelefonica_node_start(lista_telefonica));
    
    puts("\n\n\n pesquisando Elano\n\n");
    search_ltelefonica(lista_telefonica,get_ltelefonica_node_start(lista_telefonica),"Elano");
    puts("\n\n\n pesquisando Fulano\n\n");
    search_ltelefonica(lista_telefonica,get_ltelefonica_node_start(lista_telefonica),"Fulano");
    
    puts("\n\n\n LISTA TELEFONICA\n\n");
    print_lista_ltelefonica(get_ltelefonica_node_start(lista_telefonica));

    puts("\n\n\n REMOVENDO - Clano\n\n");
    remove_Onenode(lista_telefonica,get_ltelefonica_node_start(lista_telefonica),"Clano");
    puts("\n\n\n REMOVENDO - Fulano\n\n");
    remove_Onenode(lista_telefonica,get_ltelefonica_node_start(lista_telefonica),"Fulano"); 

    puts("\n\n\n LISTA TELEFONICA\n\n");
    print_lista_ltelefonica(get_ltelefonica_node_start(lista_telefonica));
    printf("\n\n\nLISTA TELEFONICA\nTotal de elementos (nomes): %d\n", get_size(lista_telefonica));

    destroy_lt_removeAllnodes(&lista_telefonica, get_ltelefonica_node_start(lista_telefonica));
    return 0;
}