//
// Created by Quentin on 23/10/2022.
//

#include "function.h"

char *typeIndentify(char *ligne) {
    /*
     * char** ligne : correspond à une ligne du du dictionnaire.
     * return char* est le nom du type.
     */
    //on prend le troisième caractère de la troisième chaine de caracctères qui à chaque fois propre à chaque type.
    char caractere_important;
    caractere_important = ligne[2];
    switch(caractere_important) {
        //En regarder les information pour chaque mots, on se rends compte que 'Nom', 'Ver', 'Adj', 'Adv' ont un troisième carctère unique
        case 'm' : {
            return "Nom";
            break;
        }
        case 'r': {
            return "Verbe";
            break;
        }
        case 'j': {
            return "Adjectif";
            break;
        }
        case 'v': {
            return  "Adverbe";
            break;
        }
        default : {
            //le cas où c'est un déterminat ou une préposistion, on l'ignore
            return "Non";
            break;
        }
    }
}


void magie(char** chaine1) {
    *chaine1 = '1';
}
