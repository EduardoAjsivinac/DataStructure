#import "List.h"

//"Private" methods
node * create_node(void * data, char * value){
    node * new_no = (node*)malloc(sizeof (node));
    new_no->data = data;
    new_no->next = null;
    strcpy(new_no->value_data, value);
    return  new_no;
}

void insert_fifo(void * data, char * order_value, list * self){
    node * a = create_node(data, order_value);
    if (self->first_node != null){
        self->last_node->next = a;
        self->last_node = a;
    }else{
        self->first_node = a;
        self->last_node = a;
    }
}

void insert_lifo(void * data, char * order_value, list * self){
    node * a = create_node(data, order_value);
    if (self->first_node != null){
        a->next = self->first_node;
        self->first_node = a;
    }else{
        self->first_node = a;
        self->last_node = a;
    }
}

void insert_ascending(void * data, char * order_value, list * self){
    node * a = create_node(data, order_value);
    if(self->first_node!=null){
        node * anterior = self->first_node;
        if(strcmp(order_value,self->first_node->value_data)<0){
            self->first_node = a;
            a->next = anterior;
            return;
        }
        if(strcmp(order_value,self->last_node->value_data)>0){
            self->last_node->next = a;
            self->last_node = a;
            return;
        }
        node * temporal = anterior->next;
        while (temporal!=null) {
            if(strcmp(order_value,temporal->value_data)<0){
                anterior->next = a;
                a->next = temporal;
                return;
            }
            anterior = anterior->next;
            temporal=temporal->next;
        }
    }else{
        self->first_node = a;
        self->last_node = a;
    }
}

void insert_descending(void * data, char * order_value, list * self){
    node * a = create_node(data, order_value);
    if(self->first_node!=null){
        node * anterior = self->first_node;
        if(strcmp(order_value,self->first_node->value_data)>0){
            self->first_node = a;
            a->next = anterior;
            return;
        }
        if(strcmp(order_value,self->last_node->value_data)<0){
            self->last_node->next = a;
            self->last_node = a;
            return;
        }
        node * temporal = anterior->next;
        while (temporal!=null) {
            if(strcmp(order_value,temporal->value_data)<0){
                a->next = temporal;
                anterior->next = a;
                return;
            }
            anterior = anterior->next;
            temporal=temporal->next;
        }
    }else{
        self->first_node = a;
        self->last_node = a;
    }
}

void insert_circular(void * data, char * order_value, list * self){
    node * a = create_node(data, order_value);
    if (self->first_node != null){
        self->last_node->next = a;
        self->last_node = a;
        self->last_node->next = self->first_node;
    }else{
        self->first_node = a;
        self->last_node = a;
        self->last_node->next = self->first_node;
    }
}

//"Public" methods
struct list * create_list(char * name, int type){
    list * new_list = (list *) malloc(sizeof (list));
    strcpy(new_list->name,name);
    new_list->type_list = type;
    new_list->last_node = null;
    new_list->first_node = null;
    return  new_list;
}

void insert_data(void * data, char * order_value, list * self){
    int type = self->type_list;
    switch (type) {
    case fifo:
        insert_fifo(data, order_value,self);
        break;
    case lifo:
        insert_lifo(data, order_value,self);
        break;
    case ascending:
        insert_ascending(data,order_value,self);
        break;
    case descending:
        insert_descending(data,order_value,self);
        break;
    case circular:
        insert_circular(data,order_value,self);
        break;
    default:
        break;
    }
}

void imprimir_data(list * self){
    node * temporal = self->first_node;
    printf("\nLos datos de la lista %s son:\n",self->name);
    if(self->type_list!=circular){
        while (temporal!=null) {
            printf("%s\n",temporal->data);
            temporal = temporal->next;
        }
    }else{
        while (temporal->next!=self->first_node) {
            printf("%s\n",temporal->data);
            temporal = temporal->next;
        }
        printf("%s\n",temporal->data);
    }

}
