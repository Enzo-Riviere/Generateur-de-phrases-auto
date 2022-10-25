//
// Created by yael1 on 25/10/2022.
//
#include <stdlib.h>
#include "arbre.h"
#include "fonction.h"

#define TAILLE_MAX 25

t_tree createEmptyTree (){
    t_tree mytree;
    mytree.root = NULL;
    return mytree;
}

void ajout_mot(t_tree* arbre, char mot_court[], char flechie[], char type[]){
    int i = 0;
    while(mot_court[i] != '\0'){
        if (lettre_dans_liste(arbre->root->enfant, mot_court[i]) == 0){
            p_node newp;
            if (arbre->root == NULL){
                arbre->root->
            }
        }

    }

}
