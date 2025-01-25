#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));

    printf("\nDirecciones de memoria:\n");
    printf("Dirección de name  : %p\n",(void *)&messi.name);
    printf("Dirección de age   : %p\n",(void *)&messi.age);
    printf("Dirección de height: %p\n",(void *)&messi.height);
    printf("Dirección de messi : %p\n", (void *)&messi);

    return EXIT_SUCCESS;
}

//¿La suma de los miembros coincide con el total? No necesariamente, porque el compilador puede agregar padding entre los campos para alinear la memoria y mejorar el rendimiento.
//¿El tamaño del campo name depende del nombre que contiene? No, el tamaño de name siempre será NAME_MAXSIZE (30 bytes), independientemente de cuántos caracteres contenga la cadena.
//¿Hay algo raro en las direcciones de memoria? Sí, debido al padding, las direcciones de los campos pueden no ser consecutivas.  