#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/gstring.h"

int *index_of(char *wordToSearch , char *letter){

    int *ocurrencesList = NULL;
    ocurrencesList = (int*) calloc(sizeof(wordToSearch) , sizeof(int));
    //set to -1 all matchs
    for(int i=0 ; i < (int)strlen(wordToSearch) ; i++){
        ocurrencesList[i] = -1;
    }

    int position = -1;
    int index = 0;
    for(int i=0 ; i < (int)strlen(wordToSearch) ; i++){
        if(wordToSearch[i] == letter[0]) {
            position = i;
            //printf("POSICIONES ENCONTRADAS %d\n",position);
            //add match on list
            //ocurrencesList = (int*)realloc(ocurrencesList,1 * sizeof(int));
            ocurrencesList[index] = position;
            index++;
        }

    }

    return ocurrencesList;
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