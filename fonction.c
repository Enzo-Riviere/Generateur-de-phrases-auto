//
// Created by yael1 on 25/10/2022.
//

#include "fonction.h"

int lettre_dans_liste(t_std_list_lettre liste, char lettre){
    p_cell_lettre tmp = liste.head;
    int res = 0;
    while (tmp != NULL && (tmp->valeur->val != lettre)){
        tmp = tmp->next;
    }
    if (tmp != NULL){
        res = 1;
    }
    return res;
}

char* copier_mot(char chaine_vide[], char chaine_a_copier[]){
    int i = 0;
    while(chaine_a_copier[i] != '\0'){
        chaine_vide[i] = chaine_a_copier[i];
        i++;
    }
    return chaine_vide;
}
