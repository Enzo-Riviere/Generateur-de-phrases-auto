//
// Created by yael1 on 25/10/2022.
//

#include <malloc.h>
#include "node.h"

p_node createNode(char lettre){
    p_node noeud;
    noeud = (p_node)malloc(sizeof(t_node));

    noeud->val = lettre;
    noeud->enfant = createEmptylistLettre();
    noeud->fin_mot = 0;

    return noeud;
}