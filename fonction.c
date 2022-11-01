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


    /*do{
        if (tab_enfant[i]->val == lettre) {
            verif = 1;
            return 1;

        }
        i++;
    }while((tab_enfant[i] != 0) && (verif == 0));*/

    return verif;


    /*p_cell_lettre tmp = liste.head;
    int res = 0;
    while (tmp != NULL && (tmp->valeur->val != lettre)){
        tmp = tmp->next;
    }
    if (tmp != NULL){
        res = 1;
    }
    return res;*/
}

char* copier_mot(char chaine_vide[], char chaine_a_copier[]){
    int i = 0;
    while(chaine_a_copier[i] != '\0'){
        chaine_vide[i] = chaine_a_copier[i];
        i++;
    }
    return chaine_vide;
}
