//
// Created by yael1 on 25/10/2022.
//

#include "fonction.h"

//Cette fonction permet de verifier si un caractère est dans un tableau
//Elle prend en paramètre un noeud ainsi que la lettre que nous voulons vérifier
//Elle retourne un entier, 0 si la lettre n'y est pas et 1 sinon
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

