#include <stdio.h>
#include <stdlib.h>
#include "./../lib/websites.h"

int main(){
   
    struct websites *weblista = create_websites();
    add_last(weblista, get_websites_node_start(weblista), "youtube","www.youtub.com");
    add_last(weblista, get_websites_node_start(weblista), "EAD IFMS","www.ead.ifms.edu.br");
    add_last(weblista, get_websites_node_start(weblista), "Instagram","www.instagram.com");
    add_last(weblista, get_websites_node_start(weblista), "IBGE","www.ibge.gov.br");
    add_last(weblista, get_websites_node_start(weblista), "gmail","www.gmail.com");
    add_last(weblista, get_websites_node_start(weblista), "drive","www.drive.com");
    add_last(weblista, get_websites_node_start(weblista), "TSSECRET","www.tssecret.me");
    
    puts("\n\n\n LISTA WEBSITES\n\n");
    print_lista_websites(get_websites_node_start(weblista));
    
    puts("\n\n\n pesquisando gmail\n\n");
    search_websites(weblista,get_websites_node_start(weblista),"gmail");
    puts("\n\n\n pesquisando TSSECRET\n\n");
    search_websites(weblista,get_websites_node_start(weblista),"TSSECRET");
    puts("\n\n\n LISTA WEBSITES\n\n");
    print_lista_websites(get_websites_node_start(weblista));

    destroy_wb_removeAllnodes(&weblista,get_websites_node_start(weblista));
    return 0;
}