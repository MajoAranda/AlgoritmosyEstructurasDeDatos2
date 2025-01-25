#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int aux;      // Variable auxiliar para realizar el intercambio
    aux = *a;     // Guardar el valor de a en aux
    *a = *b;      // Asignar el valor de b a a
    *b = aux;     // Asignar el valor de aux a b
}


int main(void) {
    int x = 6, y = 4;
    printf("Antes del swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Después del swap: x = %d, y = %d\n", x, y);
    return EXIT_SUCCESS;
}
