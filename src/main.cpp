#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

#define TRUE 1
#define FALSE 0 

int main(int argc, char const *argv[])
{

    printf("Bienvenido al juego del ahorcado. Tienes 5 oportunidades. Introduce la palabra\n");
    char wordToPlay[15];
    char wordToShow[15];

    fgets(wordToPlay,sizeof(wordToPlay),stdin);
    wordToPlay[strcspn(wordToPlay, "\n")] = '\0'; // Elimina el carácter de nueva línea
    //printf("A jugar %s\n",wordToPlay);
    memset(wordToShow,'*',strlen(wordToPlay)); // rellenamos de *
    printf("%s\n",wordToShow);


    int lifes = 5;
    int *matchsList = NULL;
    while(lifes > 0){

        char letter[2];
        printf("?:->\n");
        fgets(letter,sizeof(letter),stdin);
        letter[strcspn(letter, "\n")] = '\0'; // Elimina el carácter de nueva línea
        letter[strcspn(letter, "\n")] = '\0'; // Elimina el carácter de nueva línea

        //list of matchs
        matchsList = indexOf(wordToPlay,letter);
        if(matchsList != NULL){

            int exists_match = 0;
            for(int index_match_list = 0 ; index_match_list < (int)sizeof(matchsList) / (int)sizeof(matchsList[0]) ; index_match_list++){
                    int match = matchsList[index_match_list];
                    if(match != -1){
                        exists_match = 1;
                        wordToShow[match] = letter[0];
                    }
            }

            if(exists_match == 0){
                lifes--;
                printf("PERDISTE, te quedan %d oportunidades\n",lifes);
            }


        }

        printf("Sigue jugando ...\n");
        printf("%s\n",wordToShow);
        
 
    };

    free(matchsList);


    return 0;
}