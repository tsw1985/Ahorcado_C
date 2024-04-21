#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

#define TRUE 1
#define FALSE 0 

int main(int argc, char const *argv[])
{

    system("clear");
    printf("Bienvenido al juego del ahorcado. Tienes 5 oportunidades. Introduce la palabra\n");
    char wordToPlay[20];
    char wordToShow[20];

    scanf("%s",wordToPlay);
    wordToPlay[strcspn(wordToPlay, "\n")] = '\0'; // Elimina el carácter de nueva línea

    memset(wordToShow,'*',strlen(wordToPlay)); // rellenamos de *
    system("clear");
    printf("%s\n",wordToShow);
    printf("Tienes que averiguar %d letras\n",(int)strlen(wordToShow));


    int lifes = 5;
    int win = 0;
    int *matchsList = NULL;
    while(lifes > 0){

        char letter[2];
        printf("?:-> ");
        scanf("%s",letter);
        letter[strcspn(letter, "\n")] = '\0'; // \0 Elimina el carácter de nueva línea

        //list of matchs
        matchsList = indexOf(wordToPlay,letter);
        if(matchsList != NULL){

            int exists_match = 0;
            for(int index_match_list = 0 ; index_match_list <= (int)sizeof(matchsList) / (int)sizeof(matchsList[0]) ; index_match_list++){
                    int match = matchsList[index_match_list];
                    if(match != -1){
                        exists_match = 1;
                        wordToShow[match] = letter[0];
                        win++;
                    }
            }

            if(exists_match == 0){
                lifes--;
                printf("PERDISTE, te quedan %d oportunidades\n",lifes);
            }

            if(win == (int)strlen(wordToShow)){
                printf("BIEN !! HAS GANADO!!\n");
                break;
            }


        }

        printf("Sigues jugando ...\n");
        printf("%s\n",wordToShow);
        
 
    };

    free(matchsList);


    return 0;
}