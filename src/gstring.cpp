#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/gstring.h"

int *indexOf(char *wordToSearch , char *letter){

    int *ocurrencesList = NULL;
    ocurrencesList = (int*) calloc(sizeof(wordToSearch) , sizeof(int));
    //set to -1 all matchs
    for(int i=0 ; i < (int)strlen(wordToSearch) ; i++){
        ocurrencesList[i] = -1;
    }

    int position = -1;
    int index = 0;
    for(int i=0 ; i < (int)strlen(wordToSearch) ; i++){
        
        //printf("LETRA [%c]-[%d]--->[%d]\n",wordToSearch[i],wordToSearch[i],letter[0]);

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