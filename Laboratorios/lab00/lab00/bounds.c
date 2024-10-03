#include <stdlib.h> //malloc y free, propósito general
#include <stdio.h> //operaciones de i/o ej printf,scanf,open
#include <stdbool.h> //Biblioteca de booleanos

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_lowerbound = true;
    res.is_upperbound = true;
    res.exists = false;
    for(int i = 0; i < length; i++){
        if(value <= arr[i]){
            res.is_lowerbound = true && res.is_lowerbound;
        }
        else{
            res.is_lowerbound = false;
        }
        if(value >= arr[i]){
            res.is_upperbound = true && res.is_upperbound;
        }
        else{
            res.is_upperbound = false;
        }
        if(value == arr[i]){
            res.exists = true;
            res.where = i;
        }
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;

    for(int i=0; i<ARRAY_SIZE;i++){
        printf("Ingrese el elemento en la posición %d: ", i);
        scanf("%d",&a[i]);
    }
    printf("Ingrese el valor: ");
    scanf("%d",&value);
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    
    if (result.is_upperbound){
		if (result.exists){
			printf("El valor ingresado es máximo y se encuentra en la posición %d\n",result.where);
		} else{
			printf("El valor ingresado es cota superior.\n");
			}
	}
	if(result.is_lowerbound){
		if (result.exists){
			printf("El valor ingresado es mínimo y se encuentra en la posición %d\n",result.where);
		} else{
			printf("El valor ingresado es cota inferior.\n");
			}

    return EXIT_SUCCESS;
}
}
