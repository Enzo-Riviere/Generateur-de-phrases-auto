//
// Created by yael1 on 25/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "t_std.h"
#include "flechie.h"

#ifndef GENERATEUR_DE_PHRASES_AUTO_ARBRE_H
#define GENERATEUR_DE_PHRASES_AUTO_ARBRE_H

//Création de la structure d'un arbre :
typedef struct {
    p_node root;
}t_tree;

t_tree createEmptyTree();

void ajout_mot(t_tree*, char[], char[], char[]);


#endif //GENERATEUR_DE_PHRASES_AUTO_ARBRE_H
