#ifndef LIST_H
#define LIST_H

#define fifo 0
#define lifo 1
#define ascending 2
#define descending 3
#define circular 4

//imports
#import "Node.h"
#include <string.h>

//Linked list
typedef struct list list;

list * create_list(char * name, int type);
void insert_data(void * data, char * order_value, list * self);
void imprimir_data(list * self);

struct list{
    char name[10];
    int type_list;
    node * first_node;
    node * last_node;
};

#endif // LIST_H
