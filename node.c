//
// Created by yael1 on 25/10/2022.
//

#include <malloc.h>
#include "node.h"

p_node createNode(char lettre){
    p_node noeud;
    noeud = (p_node)malloc(sizeof(t_node));

    noeud->val = lettre;
    noeud->nb_enfants = 0;
    noeud->enfants = (p_node*) malloc (sizeof (p_node));
    noeud->fin_mot = 0;

    return noeud;
}

void ajouter_enfant(p_node noeud, char lettre){
    p_node nv_enfant= createNode(lettre);
    noeud->enfants[noeud->nb_enfants] = nv_enfant;
    noeud->nb_enfants ++;
    noeud->enfants = (p_node*) realloc (noeud->enfants ,sizeof (p_node) * noeud->nb_enfants+1);
}