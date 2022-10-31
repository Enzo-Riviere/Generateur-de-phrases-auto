//
// Created by yael1 on 25/10/2022.
//


#ifndef GENERATEUR_DE_PHRASES_AUTO_NODE_H
#define GENERATEUR_DE_PHRASES_AUTO_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "t_std.h"
#include "flechie.h"

//Création de la structure d'un noeud :
typedef struct {
    char val;
    p_node* enfants;
    int nb_enfants;
    int fin_mot;
    mot *si_fin_mot;
}t_node, *p_node;

p_node createNode(char val);
void ajouter_enfant(p_node, p_node);

#endif //GENERATEUR_DE_PHRASES_AUTO_NODE_H
