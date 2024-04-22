#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/gstring.h"

int_array *index_of(char *wordToSearch , char *letter){

    struct int_array *_int_array;
    int total_chars = strlen(wordToSearch);

    // set size of list.
    _int_array->size = total_chars;
    
    //prepare list pointe
    int *ocurrences_list_pointer = NULL;
    ocurrences_list_pointer = (int*) malloc(total_chars * sizeof(int));
    if(ocurrences_list_pointer != NULL){

        _int_array->array_pointer = ocurrences_list_pointer;
        for(int i=0 ; i < _int_array->size; i++){
            //set to -1 all matchs
            _int_array->array_pointer[i] = -1;
        }

        int position = -1;
        int index = 0;
        for(int i=0 ; i < _int_array->size ; i++){
            if(wordToSearch[i] == letter[0]) {
                position = i;
                _int_array->array_pointer[i] = position;
                index++;
            }

        }
    }

    return _int_array;
}

int exists_char_on_string(char *string_to_search, char *letter){
    int exists = -1;
    for(int i=0 ; i < (int)strlen(string_to_search) ; i++){
        if (string_to_search[i] == letter[0]){
            exists = 0;
            break;
        }
    }
    return exists;
}