#ifndef PARK_H
#define PARK_H
#include <stdbool.h>

struct parking;
struct parking_space;
struct __owner_person;
struct __car;


struct parking *create_parking(int parking_capacity);
struct parking_space *create_parking_space(struct parking *p, char *nome, char *cpf, char *placa, char *mm_car);
struct __owner_person *__create_owner_person(char *nome, char *cpf);
struct __car *__create_car(int p_size, char *nome, char *cpf, char *placa, char *mm_car);

char *sAlloc(char *namepoint);
struct parking_space *_get_start_parking_space(struct parking *p);
int _get_id_car(struct parking_space *ps);
int _get_size_spaceFull(struct parking *p);
char *_get_owner_name(struct  parking_space *p_space);
char *_get_owner_cpf(struct  parking_space *p_space);
char *_get_car_placa(struct  parking_space *p_space);
char *_get_car_mm(struct  parking_space *p_space);
int _isFull(struct parking *_parking);
int _isEmpty(struct parking *_parking);

void add_lest(struct parking *_parking, struct parking_space *p_space, char *nome, char *cpf, char *placa, char *mm_car);
void remove_all(struct parking **p,struct parking_space *p_space);
void print_parking_space(struct parking_space  *p_space);
void remove_Onenode(struct parking *p,struct parking_space *p_space, int id);
void search_id(struct parking *p,struct parking_space *p_space, int id);
void pp(struct parking_space  *p_space);

#endif