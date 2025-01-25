#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */


struct s_pair_t {
    int fst;
    int snd;
};


pair_t pair_new(int x, int y){
    pair_t new = (pair_t)malloc(sizeof(struct s_pair_t));
    if(new == NULL){
        printf("Error: No se pudo reservar memoria para el par\n");
        exit(EXIT_FAILURE);
    }
    new->fst = x;
    new->snd = y;
    return new;
    }



int pair_first(pair_t p){
    return p->fst;
}

int pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    pair_t new = (pair_t)malloc(sizeof(struct s_pair_t));
    if(new == NULL){
        printf("Error: No se pudo reservar memoria para el par\n");
        exit(EXIT_FAILURE);
    }
    new->fst = p->snd;
    new->snd = p->fst;
    return new;
}

pair_t pair_destroy(pair_t p){
    free(p);
    p=NULL;
    return p;  
}