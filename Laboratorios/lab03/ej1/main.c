#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



#define MAX_SIZE 1000

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}



static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

//llena los arreglos con datos y devuelve la cantidad de datos que tenía
unsigned int data_from_file(const char *path, unsigned int indexes[],
char letters[], unsigned int max_size){

    //abrir el archivo
    FILE *f = fopen(path,"r");
    unsigned int length = 0;

    if(f == NULL){
        printf ("Error when trying to open the file\n");
        exit(EXIT_FAILURE);

    }

    while (!feof(f) && length < max_size){
        fscanf(f,"%u -> *%c* \n", &indexes[length], &letters[length]);
        length++;
    }

    fclose(f);
    return length;

}


void array_sorted (char sorted[],unsigned int length ,unsigned int indexes[], char letters[]){
    unsigned int position = 0;
    char letter;

    for (unsigned int i = 0; i < length; i++){
        position = indexes[i];
        if(position >= length){
            printf("Error, invalid index\n");
            exit(EXIT_FAILURE);

        }
        letter= letters[i];
        sorted [position] = letter;
    }

}


int main(int argc, char *argv[]) {

    char *file;
    file= parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    length= data_from_file(file,indexes,letters,MAX_SIZE);
    array_sorted(sorted,length,indexes,letters);
    dump(sorted, length);

    return EXIT_SUCCESS;
}

