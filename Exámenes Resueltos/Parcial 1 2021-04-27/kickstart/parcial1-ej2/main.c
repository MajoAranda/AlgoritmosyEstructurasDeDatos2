#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "odd.h"





int main (){
    int unsigned length;
    printf("Ingrese el tamaño del arreglo\n");
    scanf("%u",&length);
    int array[length];
    for(unsigned int i = 0; i < length; i++){
        printf ("Ingrese los elementos del arreglo\n");
        scanf("%d",&array[i]);
    }


    bool result = is_odd_sorted(array,length);
     printf("is_SORTED = %s\n", result ? "true" : "false");




    return 0;
}