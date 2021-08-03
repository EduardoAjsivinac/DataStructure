#include <stdio.h>
#include "List.h"

int main()
{
    list * fifo_list = create_list("FIFO",fifo);
    list * lifo_list = create_list("LIFO",lifo);
    list * ascending_list = create_list("ASCENDING",ascending);
    list * descending_list = create_list("DESCENDING",descending);
    list * circular_list = create_list("CIRCULAR",circular);
    char * a= "hola";
    char * b= "mundo";
    char * c= "C";
    char * d= "D";
    insert_data(a,a,fifo_list);
    insert_data(b,b,fifo_list);
    insert_data(c,c,fifo_list);
    insert_data(d,d,fifo_list);
    imprimir_data(fifo_list);
    insert_data(a,a,lifo_list);
    insert_data(b,b,lifo_list);
    insert_data(c,c,lifo_list);
    insert_data(d,d,lifo_list);
    imprimir_data(lifo_list);
    insert_data(a,a,ascending_list);
    insert_data(b,b,ascending_list);
    insert_data(c,c,ascending_list);
    insert_data(d,d,ascending_list);
    imprimir_data(ascending_list);
    insert_data(a,a,descending_list);
    insert_data(b,b,descending_list);
    insert_data(c,c,descending_list);
    insert_data(d,d,descending_list);
    imprimir_data(descending_list);
    insert_data(a,a,circular_list);
    insert_data(b,b,circular_list);
    insert_data(c,c,circular_list);
    insert_data(d,d,circular_list);
    imprimir_data(circular_list);
    return 0;
}
