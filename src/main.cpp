#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

#define TRUE 1
#define FALSE 0 

int main(int argc, char const *argv[])
{

    system("clear");
    printf("Bienvenido al juego del ahorcado. Tienes 5 oportunidades. Introduce una palabra: ");
    char wordToPlay[50];
    char wordToShow[50];
    int total_chars = 0;

    scanf("%s",wordToPlay);
    memset(wordToShow,'*',strlen(wordToPlay));    // fill *
    wordToPlay[strcspn(wordToPlay, "\n")] = '\0'; // remove end line

    system("clear");

    total_chars = (int)strlen(wordToShow);

    printf("Tienes que averiguar %d letras\n", total_chars);
    int lifes = 5;
    int win = 0;
    int end_game = 0;
    int_array *matchsList = NULL;
    while(end_game == 0)
    {
        system("clear");
        printf("%s\n",wordToShow);

        char letter[2];
        printf("Tienes %d oportunidades y vas por %d aciertos de %d. ¿letra?-> ",lifes,win,total_chars);
        scanf("%s",letter);
        letter[strcspn(letter, "\n")] = '\0'; // \0 Elimina el carácter de nueva línea

         if (exists_char_on_string(wordToShow,letter) == 0)
         {
             lifes--;
         }
         else
         {

            matchsList = index_of(wordToPlay,letter);
            if(matchsList != NULL){
                
                int exists_match = 0;
                for(int index_match_list = 0 ; index_match_list < matchsList->size ; index_match_list++){
                    int match = matchsList->array_pointer[index_match_list];
                    if(match != -1){
                        exists_match = 1;
                        wordToShow[match] = letter[0];
                        win++;
                    }
                }

                if(exists_match == 0){
                    lifes--;
                }

                //check if user win
                char *check_hidden_chars = NULL; 
                check_hidden_chars = strchr(wordToShow , '*' );
                if(check_hidden_chars == NULL){
                    printf("BIEN !! HAS GANADO!!\n");
                    end_game = 1;
                }

                if(lifes == 0){
                    printf("PERDISTE :(\n");
                    end_game = 1;
                }
        }
    };
}
    free(matchsList->array_pointer);
    return 0;
}