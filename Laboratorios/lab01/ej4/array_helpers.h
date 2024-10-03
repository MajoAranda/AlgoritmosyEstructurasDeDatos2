#ifndef EXAMPLE_H  // Verifica si EXAMPLE_H no ha sido definido
#define EXAMPLE_H  // Si no lo ha sido, lo define

#include <stdbool.h>

unsigned int array_from_file(int array[],unsigned int max_size,const char *filepath);
void array_dump(int a[], unsigned int length);
bool array_is_sorted(int a[], unsigned int length);

#endif  // Fin de la condición

