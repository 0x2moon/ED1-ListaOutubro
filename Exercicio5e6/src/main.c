#include <stdio.h>
#include <stdlib.h>
#include "./../lib/park.h"
#define EXERCICIO 2
#define ADD 8

int main(){
    struct parking *new_Parking = create_parking(10);
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"teste","122415","6546sdf","BMW - IX200");
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"a","122415","6546sdf","BMW - IX200");
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"tesdste","122415","6546sdf","BMW - IX200");
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"ff","122415","6546sdf","BMW - IX200");
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"vv","122415","6546sdf","BMW - IX200");
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"dd","122415","6546sdf","BMW - IX200");
    print_parking_space(_get_start_parking_space(new_Parking));
    puts("Removendo elemento 3 e 4");
    remove_Onenode(new_Parking,_get_start_parking_space(new_Parking),3);
    remove_Onenode(new_Parking,_get_start_parking_space(new_Parking),2);
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"dd","122415","6546sdf","BMW - IX200");
    print_parking_space(_get_start_parking_space(new_Parking));
    printf("\n\nnumero total de veiculos: %d ", _get_size_spaceFull(new_Parking));
    remove_all(&new_Parking, _get_start_parking_space(new_Parking));
    return 0;
}