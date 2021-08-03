#ifndef NODE_H
#define NODE_H

#define null 0

#include <stdio.h>

//linked node
typedef struct node node;

struct node {
    void * data;
    struct node * next;
    char value_data[10];
};

#endif // NODE_H
