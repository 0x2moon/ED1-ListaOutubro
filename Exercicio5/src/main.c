#include <stdio.h>
#include <stdlib.h>
#include "./../lib/park.h"
#define EXERCICIO 2
#define ADD 8

int main(){
    struct parking *new_Parking = create_parking(10);
    add_lest(new_Parking,_get_start_parking_space(new_Parking),"teste","122415","6546sdf","BMW - IX200");
    pp(_get_start_parking_space(new_Parking));
    return 0;
}