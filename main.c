#include <stdio.h>
#include "arbre.h"
#include "node.h"
#include "fonction.h"
#include "Creation_arbres.h"

#define TAILLE_MAX 100

int main() {
    printf("Hello, World!\n");

    /*mot* resultat;
    resultat = genMotAleat(&arbre_nom);
    printf("\n");
    printf(resultat->nom_mot);*/

    //creation_arbres();
    t_tree* arbre_mot;
    arbre_mot = creation_arbres_et_donne();
    //t_tree arbre_nom, arbre_verb, arbre_adj, arbre_adve;
    genPhraseAleat(*(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 3), *(arbre_mot + 1), 3);

    return 0;
}
