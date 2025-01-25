#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pivot.h"

#define LENGHT 4



int main (){
    int array[LENGHT];
    for(unsigned int i = 0; i < LENGHT; i++){
        printf ("Ingrese los elementos del arreglo\n");
        scanf("%d",&array[i]);
    }

    unsigned int piv;
    printf("Ingrese el número del pivote: \n");
    scanf("%u",&piv);

    bool result = is_pivot(array,LENGHT,piv);
     printf("is_pivot = %s\n", result ? "true" : "false");




    return 0;
}