#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include <assert.h>  /* assert()...     */  
#include "pair.h"



pair_t pair_new(int x, int y) {
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;
    return p;
}

int pair_first(pair_t p) {
    return p.values[0];
}

int pair_second(pair_t p) {
    return p.values[1];
}

pair_t pair_swapped(pair_t p) {
    pair_t new_pair;
    new_pair.values[0] = p.values[1];
    new_pair.values[1] = p.values[0];
    return new_pair;
}

pair_t pair_destroy(pair_t p) {
    return p;
    }
