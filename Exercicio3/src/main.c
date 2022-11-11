#include <stdio.h>
#include <stdlib.h>
#include "./../lib/websites.h"

int main(){
   
    struct websites *weblista = create_websites();
    add_last(weblista, get_websites_node_start(weblista), "youtube","www.youtub.com");
    add_last(weblista, get_websites_node_start(weblista), "AAAA","www.AAAAA.com");
    add_last(weblista, get_websites_node_start(weblista), "yyyyy","www.yyyy.com");
    add_last(weblista, get_websites_node_start(weblista), "uube","www.uube.com");
    add_last(weblista, get_websites_node_start(weblista), "out","www.out.com");
    add_last(weblista, get_websites_node_start(weblista), "ybe","www.ybe.com");
    add_last(weblista, get_websites_node_start(weblista), "yte","www.yte.com");
    print_lista_websites(get_websites_node_start(weblista));
    
    puts("\n\n\n pesquisando OUT\n\n");
    search_websites(weblista,get_websites_node_start(weblista),"out");
    puts("\n\n\n pesquisando yte\n\n");
    search_websites(weblista,get_websites_node_start(weblista),"yte");
    puts("\n\n\n imprimindo\n\n");
    print_lista_websites(get_websites_node_start(weblista));

    destroy_wb_removeAllnodes(&weblista,get_websites_node_start(weblista));
    return 0;
}