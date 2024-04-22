#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

#define TRUE 1
#define FALSE 0 

int main(int argc, char const *argv[])
{

    system("clear");
    printf("Bienvenidoooo al juego del ahorcado. Tienes 5 oportunidades. Introduce una palabra: ");
    char wordToPlay[50];
    char wordToShow[50];
    int total_chars = 0;

    scanf("%s",wordToPlay);
    memset(wordToShow,'*',strlen(wordToPlay)); // rellenamos de *
    wordToPlay[strcspn(wordToPlay, "\n")] = '\0'; // Elimina el carácter de nueva línea

    system("clear");

    total_chars = (int)strlen(wordToShow);

    printf("Tienes que averiguar %d letras\n", total_chars);
    int lifes = 5;
    int win = 0;
    int_array *matchsList = NULL;
    while(lifes > 0)
    {
        system("clear");
        printf("%s\n",wordToShow);

        char letter[2];
        printf("Tienes %d oportunidades y vas por %d aciertos. ¿letra?-> ",lifes,win);
        scanf("%s",letter);
        letter[strcspn(letter, "\n")] = '\0'; // \0 Elimina el carácter de nueva línea

        //show existing char
         if (exists_char_on_string(wordToShow,letter) == 0)
         {
             lifes--;
             printf("LO SIENTO , YA HABIAS ESCRITO ESA LETRA, te quedan %d oportunidades\n",lifes);
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
                if(win == total_chars){
                    printf("BIEN !! HAS GANADO!!\n");
                    break;
                }

                if(lifes == 0){
                    printf("PERDISTE :(\n");
                    break;
                }
        }
    };
}
    free(matchsList->array_pointer);
    return 0;
}