#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/gstring.h"

int main(int argc, char const *argv[])
{

    printf("Bienvenido al juego del ahorcado. Tienes 5 oportunidades. Introduce la palabra\n");
    char wordToPlay[10];
    char wordToShow[10];
    

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
        int *matchsList = indexOf(wordToPlay,letter);

        //list of matchs
        if(matchsList != NULL){
            for(int i = 0 ; i < (int)sizeof(matchsList) ; i++){
                printf("POSICION %d\n",matchsList[i]);
            }
        }
        
        
        
        /*if(index == -1){
            lifes--;
            printf("ERROR !! Llevas %d fallos\n",lifes);
        }else{
            wordToShow[index] = letter[0];
        }*/

        printf("%s\n",wordToShow);
        free(matchsList);

        //TODO :
        // comprobar si ya el caracter fue introducido
        //  devolver un array de apariciones , por ejemplo para palabra "elefante"
        //  si pones la 'e' te tiene que aparecer el array 0-2-7
    //};

    return 0;
}