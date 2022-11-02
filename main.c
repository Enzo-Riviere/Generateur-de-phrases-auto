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

    printf("%c\n", test->val);

    printf("%c\n", test->enfants[0]->val);
    //printf("test");
    printf("%c\n", test->enfants[1]->val);
   //printf("test\n");
    printf("%c\n", test->enfants[2]->val);


    printf("%d\n", lettre_dans_tableau(test, 'b'));

    ajouter_enfant(test, 'z');
    printf("%c\n", test->enfants[3]->val);
    printf("%d\n", lettre_dans_tableau(test, 'z'));

    t_tree arbre_nom = createEmptyTree();
    printf("\nMot 1:\n");
    ajout_mot(&arbre_nom, "aeb", "aifav", "zvoznv");

    printf("Le sous enfant 0 du sous enfant 0 de root est : %c\n", arbre_nom.root->enfants[0]->enfants[0]->val);
    //p_cell_mot omm = arbre_nom.root->enfants[0]->enfants[0]->enfants[0]->si_fin_mot->forme_grammatical.head;
    printf(arbre_nom.root->enfants[0]->enfants[0]->enfants[0]->si_fin_mot->forme_grammatical.head->value);


    printf("\nMot 2:\n");
    ajout_mot(&arbre_nom, "aqb", "aifav", "zvoznv");
    printf("Le sous enfant 0 du sous enfant 0 de root est : %c\n", arbre_nom.root->enfants[0]->enfants[1]->val);

    printf("\nMot 3:\n");
    ajout_mot(&arbre_nom, "bzb", "aifav", "zvoznv");
    printf("Le sous enfant 0 du sous enfant 0 de root est : %c\n", arbre_nom.root->enfants[1]->enfants[0]->val);
    /*t_tree arbre_nom = createEmptyTree();
    t_tree arbre_verbe = createEmptyTree();
    t_tree arbre_adjectif = createEmptyTree();
    t_tree arbre_adverbe = createEmptyTree();*/


    return 0;
}
