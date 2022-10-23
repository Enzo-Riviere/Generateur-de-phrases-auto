//
// Created by Quentin on 23/10/2022.
//

#include "function.h"

char* typeIndentify(char** ligne) {
    /*
     * char** ligne : correspond à une ligne du du dictionnaire.
     * return char* esst le nom du type.
     */
    //on prend le troisième caractère de la troisième chaine de caracctères qui à chaque fois propre à chaque type.
    char important_char = *(*(ligne + 2) + 2);
    switch(important_char) {
        case 'm' : {
            char res[] = "Nom";
            break;
        }
        case 'r': {
            char res[] = "Verbe";
            break;
        }
        case 'j': {
            char res[] = "Adjectif";
            break;
        }
        case 'v': {
            char res[] = "Adverbe";
            break;
        }
    }
    return res;
}
