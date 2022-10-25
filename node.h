//
// Created by yael1 on 25/10/2022.
//
#include "t_std.h"
#include "flechie.h"

#ifndef GENERATEUR_DE_PHRASES_AUTO_NODE_H
#define GENERATEUR_DE_PHRASES_AUTO_NODE_H

//Création de la structure d'un noeud :
typedef struct {
    char val;
    t_std_list_lettre enfant;
    int fin_mot;
    mot *si_fin_mot;
}t_node, *p_node;

p_node createNode(char val);

#endif //GENERATEUR_DE_PHRASES_AUTO_NODE_H
