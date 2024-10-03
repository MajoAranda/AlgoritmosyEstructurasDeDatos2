#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include <stdbool.h>

// te devuelve la cantidad de elementos del array leido del archivo
unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    int a;
    unsigned int length;
    //abrir el archivo
    FILE *f = fopen(filepath,"r");
    //verificar que pudo abrir el archivo
    if (f == NULL){
        printf("Error al abrir el archivo");
    }
    //leer el primer caracter que es la cantidad de elementos y guardarlo en una variable
    fscanf (f,"%u",&length);
    //condicionar con max_size
    if(length > max_size || length <=0){
        printf("Error, invalid length");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    //bucle para leer los elementos del array
    for(unsigned int i=0; i<length; i++){
       a = fscanf(f,"%i",&array[i]);
       if(a==-1)
       {
         printf("Error: Missing array element(s) acording its length.\n");
         exit(EXIT_FAILURE);
       }
    }
    fclose(f);
    return length;
}

//imprime todo 
void array_dump(int a[], unsigned int length) {
    printf("[ ");
    for (unsigned int  i = 0; i < length - 1; i++)
    {
        printf("%d, ",a[i]);
    }
    printf("%d", a[length-1]);
    printf (" ]\n");
}

bool array_is_sorted(int a[], unsigned int length){
    bool res = true;
    for(unsigned int i = 0; i < length - 1 ; i++){
        if(a[i] <= a[i+1]){
            res = res && true;
        }
        else{
            res = res && false;
        }

    }



   return res;
}

void array_swap(int a[], unsigned int i, unsigned int j){
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}