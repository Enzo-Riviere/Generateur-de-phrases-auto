#include <stdio.h>
#include "arbre.h"
#include "node.h"
#include "fonction.h"

int main() {
    printf("Hello, World!\n");

    p_node test = createNode('a');

    ajouter_enfant(test, 'b');
    ajouter_enfant(test, 'c');
    ajouter_enfant(test, 'd');

    printf("%c\n", test->val),

    printf("%c\n", test->enfants[0]->val);
    printf("test");
    printf("%c\n", test->enfants[1]->val);
    printf("test");


    //printf("%d", lettre_dans_tableau(test->enfants, 'c'));
    /*t_tree arbre_nom = createEmptyTree();
    t_tree arbre_verbe = createEmptyTree();
    t_tree arbre_adjectif = createEmptyTree();
    t_tree arbre_adverbe = createEmptyTree();*/
    return 0;
}
