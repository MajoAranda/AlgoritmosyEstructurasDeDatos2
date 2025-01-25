#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"
#include <stdio.h>

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = (counter)malloc(sizeof(struct _counter));
    if(c == NULL){
        printf("Error: no se pudo reservar memoria \n");
        exit(EXIT_FAILURE);
    }
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    c->count = c->count + 1;
}

bool counter_is_init(counter c) {
    if (c == NULL){
        return false;
    }
    return c->count==0;

}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    if (c == NULL) {  
        printf("Error: El contador a copiar es NULL\n");
        exit(EXIT_FAILURE);
    }
    counter new = (counter)malloc(sizeof(struct _counter));
    if (new == NULL) {
        printf("Error: no se pudo reservar memoria \n");
        exit(EXIT_FAILURE);
    }
    new->count = c->count;
    return new;
}

void counter_destroy(counter c) {
   free(c);

}
