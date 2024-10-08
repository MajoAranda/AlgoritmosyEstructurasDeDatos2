#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    while (s[i] != '\0'){
        i++;
        
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) { 
    bool res = true;
    unsigned int length_s1 = fstring_length(s1); 
    unsigned int length_s2 = fstring_length(s2);

    if(length_s1 != length_s2){
        return false;
    }

    for(unsigned int i = 0; i<length_s1; i++){
        if(s1[i] != s2[i]) {
            res = false;
            break;
        }
        
    }
    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;

    
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return true; 
        } else if (s1[i] > s2[i]) {
            return false; 
        }
        i++;  
    }

 
    if (s1[i] == '\0' && s2[i] != '\0') {
        return true;  
    } else if (s1[i] != '\0' && s2[i] == '\0') {
        return false; 
    }

    return true;  
}


