#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    bool res = true;
    if(piv >=length){
        printf("Invalid pivot");
        exit(EXIT_FAILURE);
    }

    for(unsigned int j = 0; j < piv; j++){
        if (array[j] <= array[piv]){
            res = res && true;
        }

        else{
            res = res && false;
        }
    }

       for(unsigned int k = (length - 1); k > piv; k--){
        if (array[k] > array[piv]){
            res = res && true;
        }

        else{
            res = res && false;
        }

    }
    return res;
}


