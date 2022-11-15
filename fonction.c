//
// Created by yael1 on 25/10/2022.
//

#include "fonction.h"

int lettre_dans_tableau(p_node noeud, char lettre){
    int i = 0, verif = 0;

    while((i < noeud->nb_enfants ) && (verif == 0)){
        if (noeud->enfants[i]->val == lettre) {
            verif = 1;
        }
        i++;
    }

    return verif;
}

char* copier_mot(char chaine_vide[], char chaine_a_copier[]){
    int i = 0;
    while(chaine_a_copier[i] != '\0'){
        chaine_vide[i] = chaine_a_copier[i];
        i++;
    }
    return chaine_vide;
}
