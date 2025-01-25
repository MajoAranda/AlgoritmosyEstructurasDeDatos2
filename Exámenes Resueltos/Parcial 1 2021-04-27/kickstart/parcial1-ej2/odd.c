#include <stdbool.h>

#include "odd.h"



bool is_odd_sorted(int array[], unsigned int length) {
    bool  res = true;
    unsigned int j = 1;
    while (j + 2 < length){
        if (array[j] > array [j+2]){
         res = false;
         break;  
        }
        j = j+2;
  
}
return res;
}
