#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node_t {
    list_elem elem;
    struct node_t *next;
};

typedef struct node_t node;

list empty(){
    list new = NULL;
    return new;
}

list addl(list l, list_elem e){
    node *new = malloc(sizeof(node));
    new->elem = e;
    new->next = l; //Hago que el nuevo nodo apunte al nodo que era el primero de la lista
    l = new;      //Actualizo la lista para que ahora comience desde el nuevo nodo
    return l;
}

list destroy(list l){
    while ( l !=NULL)
    {
        node* p = l;  //p apunta al primer nodo
        l = l->next; // l apunta al nodo siguiente
        free(p);     //hago free del primer nodo
    }
    
    return NULL;
}

bool is_empty(list l){
    return l == NULL;
}

list_elem head(list l){
    assert(!is_empty(l));  //PRECONDITION: !is_empty(l)
    return l->elem;
}

   

list tail(list l){
    assert(!is_empty(l));  //PRECONDITION: !is_empty(l)
    node* p = l;
    l = l->next;
    free(p);
    return l;
}


list addr(list l, list_elem e){
    node* new = malloc(sizeof(node));
    if(new == NULL){
        printf("Error: no se pudo alocar memoria");
        exit(EXIT_FAILURE);
    }
    new->elem = e;
    new->next = NULL;

    if (l==NULL){
        l = new;
    }
    else{
        node *p = l;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
    }
   return l;

}

unsigned int length(list l){
    unsigned int length = 0;
    if (l == NULL){
        return length;
    }
    else{
        node*p = l;
        while(p != NULL){
            length = length + 1;
            p = p->next;
        }
    }
    return length;
}

list concat(list l1, list l2) {
    if (l1 == NULL) {
        return l2; 
    }
    node *p = l1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = l2;
    return l1;
}

list_elem index(list l, unsigned int i){
    assert (length(l) > 1);    //PRECONDITION: length(l)>i
    node* p = l;
    while (i > 0 && p->next != NULL)
    {
        p = p->next;
        i--;
    }
    return p->elem;
}


 void take(list l, unsigned int i) {
    node *p = l;
    while (i > 0 && p->next != NULL) {
        p = p->next;
        i--;
    }
    node *to_free = p->next;
    while (to_free != NULL) {
        node *next = to_free->next;
        free(to_free);
        to_free = next;
    }
    p->next = NULL; 
}

void drop(list l, unsigned int i){
    unsigned int j=1;
    struct node_t *p,*q;
    p=l;
    while(j<i && p!=NULL){
        q=p->next;
        free(p);
        p=q;
        j++;
    }
    l=q;
}

list copy_list(list l1){
    list copy_l=empty();
    list p=l1;
    while(p!=NULL){
        addr(copy_l,p->elem);
    }
    return copy_l;
}
