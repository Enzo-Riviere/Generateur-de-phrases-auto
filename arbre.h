//
// Created by yael1 on 25/10/2022.
//


#ifndef GENERATEUR_DE_PHRASES_AUTO_ARBRE_H
#define GENERATEUR_DE_PHRASES_AUTO_ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "t_std.h"
#include "flechie.h"

//Création de la structure d'un arbre :
typedef struct {
    p_node root;
}t_tree;

t_tree createEmptyTree();

void ajout_mot(t_tree*, char[], char[], char[]);

mot* genMotAleat(t_tree* arbre_mot);
void genPhraseAleat(t_tree Nom, t_tree Adj, t_tree Adv, t_tree Verb, int cas);

#endif //GENERATEUR_DE_PHRASES_AUTO_ARBRE_H
