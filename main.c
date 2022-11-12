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
    arbre_mot = creation_arbres_et_donne_vieux();

    //t_tree arbre_nom, arbre_verb, arbre_adj, arbre_adve;
    //genPhraseAleat(*(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 3), *(arbre_mot + 1), 2);

    printf("\n");

    flechies tempo_nom, tempo_adj;
    tempo_nom = obtFlechNom(*genMotAleat(arbre_mot));
    printf(tempo_nom.forme_grammatical.head->value);
    printf("\n");
    mot *adj = genMotAleat(arbre_mot + 2);
    printf(adj->flechies.head->value);
    printf("test de l'adj flechie\n");
    printf("\n");
    printf("debut du test\n");
    tempo_adj = obtFlechAdj(tempo_nom, *adj, *(arbre_mot + 2));
    printf("fin du test\n");
    printf(tempo_adj.forme_grammatical.head->value);
     return 0;
}
