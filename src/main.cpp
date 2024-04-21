#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

#define TRUE 1
#define FALSE 0 

int main(int argc, char const *argv[])
{

    //system("clear");
    printf("Bienvenido al juego del ahorcado. Tienes 5 oportunidades. Introduce la palabra\n");
    char wordToPlay[20];
    char wordToShow[20];

    scanf("%s",wordToPlay);
    memset(wordToShow,'*',strlen(wordToPlay)); // rellenamos de *
    //wordToShow[strlen(wordToShow) +1] = '\0';
    //wordToPlay[strcspn(wordToPlay, "\n")] = '\0'; // Elimina el carácter de nueva línea

    
    system("clear");
    //printf("%s\n",wordToShow);
    printf("Tienes que averiguar %d letras\n",(int)strlen(wordToShow));



    int lifes = 5;
    int win = 0;
    int *matchsList = NULL;
    while(lifes > 0){

        printf("%s\n",wordToShow);

        char letter[2];
        printf("?:-> ");
        scanf("%s",letter);
        letter[strcspn(letter, "\n")] = '\0'; // \0 Elimina el carácter de nueva línea

        //show existing char
        if (exists_char_on_string(wordToShow,letter) == 0){
            lifes--;
            printf("LO SIENTO , YA HABIAS ESCRITO ESA LETRA, te quedan %d oportunidades\n",lifes);
        }else{

            //list of matchs
            matchsList = index_of(wordToPlay,letter);
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

                //check if user win
                if(win == (int)strlen(wordToShow)){
                    printf("BIEN !! HAS GANADO!!\n");
                    break;
                }
        
        }

        
        
 
    };
}
    free(matchsList);


    return 0;
}