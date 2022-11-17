#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../lib/park.h"

struct parking{
    int capacity_parking;
    int size_spaceFull;

    struct parking_space *start_car;
    struct parking_space *end_car;
};

struct parking_space{
    int id_car_space;
    struct __car * car_intoSpace;
    struct parking_space *next_car;
};

struct __owner_person{
    char *nome;
    char *cpf;
};

struct __car{
    int id_car;
    char *placa;
    char *modelo_marca;
    struct __owner_person *owner_person_car;
};

char *sAlloc(char *namepoint){
    char *wold_alloc = (char *) malloc (strlen(namepoint)*sizeof(char));
    // wold_alloc = namepoint;
    return wold_alloc;
}

int _get_id_car(struct parking_space *ps){
    return ps->car_intoSpace->id_car;
}

int _get_size_spaceFull(struct parking *p){
    return p->size_spaceFull;
}

char *_get_owner_name(struct  parking_space *p_space){
    return p_space->car_intoSpace->owner_person_car->nome;
}

char *_get_owner_cpf(struct  parking_space *p_space){

    return p_space->car_intoSpace->owner_person_car->cpf;
}

char *_get_car_placa(struct  parking_space *p_space){

    return p_space->car_intoSpace->placa;
}

char *_get_car_mm(struct  parking_space *p_space){

    return p_space->car_intoSpace->modelo_marca;
}

struct parking_space *_get_start_parking_space(struct parking *p){
    return p->start_car;
}

int _isFull(struct parking *_parking){
    if (_parking->size_spaceFull == _parking->capacity_parking)
    {
        return 1;
    }
    return 0;
}

int _isEmpty(struct parking *_parking){
    if (_parking->size_spaceFull == 0)
    {
        return 1;
    }
    return 0;
}

void add_lest(struct parking *_parking, struct parking_space *p_space, char *nome, char *cpf, char *placa, char *mm_car){
    
    if (_isEmpty(_parking) == 1)
    {
        _parking->size_spaceFull++;
        _parking->start_car = create_parking_space(_parking->size_spaceFull,nome,cpf,placa,mm_car);
                
    }else{

        if (p_space->next_car == NULL)
        {
            _parking->size_spaceFull++;
             p_space->next_car = create_parking_space(_parking->size_spaceFull,nome,cpf,placa,mm_car);
            _parking->end_car  = p_space->next_car;

        }else{
            add_lest(_parking, p_space->next_car, nome,cpf,placa,mm_car);
        }
    }
}

void remove_all(struct parking **p,struct parking_space *p_space){
    if(_get_size_spaceFull(*p) == 0){
        (*p)->start_car = NULL;
        free(*p);
        free(p);
        return;
    }

    if(p_space->next_car != NULL){   
        remove_all(p, p_space->next_car);
    }
    free(p_space->next_car);
    (*p)->size_spaceFull--;
}

void remove_Onenode(struct parking *p,struct parking_space *p_space, int id){
    search_id(p,p_space,id);
    struct parking_space *aux = p->start_car;
    p->start_car = aux->next_car;
    p->size_spaceFull--;
    free(aux);
    system("clear");
    print_parking_space(_get_start_parking_space(p));
}

void search_id(struct parking *p,struct parking_space *p_space, int id){
    if(p_space != NULL){
     
     if (_get_id_car(p_space) == id)
        {  
           struct parking_space *aux = p_space->next_car;
            p_space->next_car = p_space->next_car->next_car;
            aux->next_car = p->start_car;
            p->start_car  = aux;
            system("clear");
            print_parking_space(_get_start_parking_space(p));
            return;
           
        }       
        search_id(p,p_space->next_car,id);   
    }
}

void print_parking_space(struct parking_space  *p_space){
    puts("\n=============================================\n");
    puts("\t\tPARKING");
    puts("\n=============================================\n");
    puts("ID\tNOME\tCPF\tCARRO\tPLACA\t\n");
    puts("\n=============================================\n");
    pp(p_space);
}   

void pp(struct parking_space  *p_space){
    if (p_space!= NULL)
    {
        fprintf(stdout, "\n%d\t%s\t%s\t%s\t%s\n", _get_id_car(p_space), _get_owner_name(p_space), _get_owner_cpf(p_space), _get_car_placa(p_space),_get_car_mm(p_space));
        pp(p_space->next_car);
    }else{
     puts("\n=============================================\nNULL\n=============================================\n");  
        return;
    }
}

struct parking *create_parking(int parking_capacity){
    struct parking  *New_parking  = (struct parking *) malloc (sizeof(struct parking));
    New_parking->capacity_parking = parking_capacity;
    New_parking->size_spaceFull   = 0;
    New_parking->start_car = NULL;
    New_parking->end_car   = NULL;
    return New_parking;
}

struct parking_space *create_parking_space(int p_size, char *nome, char *cpf, char *placa, char *mm_car){
    struct parking_space *New_parking_space = (struct parking_space *) malloc (sizeof(struct parking_space));
    New_parking_space->car_intoSpace = __create_car(p_size,nome,cpf,placa,mm_car);
    New_parking_space->id_car_space  = _get_id_car(New_parking_space);
    New_parking_space->next_car = NULL;
    return New_parking_space;
}

struct __owner_person *__create_owner_person(char *nome, char *cpf){
    struct __owner_person *new = (struct __owner_person *) malloc (sizeof(struct __owner_person));
    new->cpf  = sAlloc(cpf);
    new->nome = sAlloc(nome);
    new->cpf  = cpf;
    new->nome = nome;
}

struct __car *__create_car(int p_size, char *nome, char *cpf, char *placa, char *mm_car){
    struct __car *new = (struct __car *) malloc (sizeof(struct __car));
    new->owner_person_car = __create_owner_person(nome, cpf);
    new->modelo_marca = sAlloc(mm_car);
    new->modelo_marca = mm_car;
    new->id_car = p_size;
    new->placa  = sAlloc(placa);
    new->placa  = placa;
    return new;
}