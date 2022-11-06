//
// Created by enzor on 05/11/2022.
//

#include "recherche_base.h"

int mot_dans_arbre(t_tree* arbre, char base[]){
    p_node tmp = arbre->root;
    int i = 0;
    while(base[i+1] != '\0'){
        if(lettre_dans_tableau(tmp, base[i])){
            tmp = tmp->enfants;
        }
        else{
            return 0;
        }
        i++;
    }
    return 1;
}

void recherche_base(char base[]){

}