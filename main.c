#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "node.h"
#include "fonction.h"
#include "Creation_arbres.h"
#include "recherche_base.h"

#define TAILLE_MAX 100

int main() {
    printf("Hello, World!\n");

    /*mot* resultat;
    resultat = genMotAleat(&arbre_nom);
    printf("\n");
    printf(resultat->nom_mot);*/

    //creation_arbres();

    t_tree* arbre_mot;
    //arbre_mot = creation_arbres_et_donne_vieux();
    arbre_mot = creation_arbres_et_donne();

    //t_tree arbre_nom, arbre_verb, arbre_adj, arbre_adve;
    genPhraseAleat(*(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 3), *(arbre_mot + 1), 2);

    char base[20];
    printf("Quel base cherchez-vous ?\n");
    scanf("%s",base);
    recherche_base(base, *(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 1), *(arbre_mot + 3));

    return 0;

    /*
    printf("\n");
    flechies tempo;
    tempo = obtFlechNom(*genMotAleat(arbre_mot));
    printf(tempo.nom_mot);
    */
     return 0;
}
