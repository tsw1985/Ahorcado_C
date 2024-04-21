#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

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


    //int lifes = 5;
    //while(lifes > 0){

        char letter[2];
        printf("?:->\n ");
        fgets(letter,sizeof(letter),stdin);
        letter[strcspn(letter, "\n")] = '\0'; // Elimina el carácter de nueva línea

        //list of matchs
        int *matchsList = indexOf(wordToPlay,letter);
        if(matchsList != NULL){
            for(int index_match_list = 0 ; index_match_list < (int)sizeof(matchsList) ; index_match_list++){
                    int match = matchsList[index_match_list];
                    if(index_match_list != -1){
                        wordToShow[match] = letter[0];
                    }
            }
        }

        printf("Sigue jugando ...\n");
        printf("%s\n",wordToShow);
        free(matchsList);
 
    //};
    return 0;
}