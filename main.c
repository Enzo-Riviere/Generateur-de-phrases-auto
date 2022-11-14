#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "node.h"
#include "fonction.h"
#include "Creation_arbres.h"
#include "recherche_base.h"
#include "recherche_flechie.h"

#define TAILLE_MAX 100

int main() {
    printf("Hello, World!\n");

    //Création des arbres :
    t_tree* arbre_mot;
    arbre_mot = creation_arbres_et_donne();
    t_tree arbre_nom, arbre_verb, arbre_adj, arbre_adve;

    int arreter = 0;
    while(arreter != 2) {
        int choix = 0, menu_1 = 0, masque = 0, ligne, colonne;


        //Menu 1
        while (choix < 1 || choix > 2) {
            printf("Que voulez-vous faire ?");
            printf("1. Generer une phrase automatiquement.\n");
            printf("2. Rechercher un mot.\n");
            printf("Veuillez saisir une valeur entre 1 et 2.\n");
            scanf("%d", &choix);
        }


        switch (choix) {
            case 1 : {
                int choix2 = 0;
                while (choix2 < 1 || choix2 > 2) {
                    printf("Quel type de phrase voulez-vous ?\n");
                    printf("1. Des phrases avec des mots de bases.\n");
                    printf("2. Des phrases avec des mots flechies.\n");
                    printf("Veuillez saisir une valeur entre 1 et 2.\n");
                    scanf("%d", &choix2);
                }

                switch (choix2) {
                    case 1 : {
                        int choix_grammaticale = 0;
                        while (choix_grammaticale < 1 || choix_grammaticale > 4) {
                            printf("Quelle forme de phrase voulez-vous ?\n");
                            printf("1. nom – adjectif – verbe – nom\n");
                            printf("2. nom – ‘qui’ – verbe – verbe – nom – adjectif\n");
                            printf("3. \n");
                            printf("4. \n");
                            printf("Veuillez saisir une valeur entre 1 et 4.\n");
                            scanf("%d", &choix_grammaticale);
                        }

                        //Appeler la fonction pour les phrases de bases avec la forme grammaticale demandé

                        break;
                    }
                    case 2: {
                        int choix_grammaticale = 0;
                        while (choix_grammaticale < 1 || choix_grammaticale > 4) {
                            printf("Quelle forme de phrase voulez-vous ?\n");
                            printf("1. nom - adjectif - verbe - nom\n");
                            printf("2. nom - ‘qui’ - verbe - verbe - nom - adjectif\n");
                            printf("3. \n");
                            printf("4. \n");
                            printf("Veuillez saisir une valeur entre 1 et 4.\n");
                            scanf("%d", &choix_grammaticale);
                        }

                        //Appeler la fonction pour les phrases fléchies avec la forme grammaticale demandé
                        break;
                    }

                }
            }
            case 2: {
                int choix3 = 0;
                while (choix3 < 1 || choix3 > 2) {
                    printf("Quel type de mot voulez-vous rechercher ?\n");
                    printf("1. Un mot de base.\n");
                    printf("2. Un mot flechie.\n");
                    printf("Veuillez saisir une valeur entre 1 et 2.\n");
                    scanf("%d", &choix3);
                }

                switch (choix3) {
                    case 1:{
                        char base[25];
                        printf("Quel mot de base cherchez-vous ?\n");
                        scanf("%s",base);
                        recherche_base(base, *(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 1), *(arbre_mot + 3));
                        break;
                    }
                    case 2 :{
                        char flechie[25];
                        printf("Quel mot flechie cherchez-vous ?\n");
                        scanf("%s",flechie);
                        //appeler la fonction qui recherchera
                        break;
                    }

                }
            }
        }

        arreter = 0;
        printf("Voulez-vous revenir au menu ou arreter ?\n");
        printf("1. Revenir au menu.\n");
        printf("2. Arreter.\n");
        printf("Veuillez saisir 1 ou 2.\n");
        while (arreter != 1 && arreter != 2) {
            scanf("%d", &arreter);
        }
    }








    /*mot* resultat;
    resultat = genMotAleat(&arbre_nom);
    printf("\n");
    printf(resultat->nom_mot);

    //creation_arbres();

    t_tree* arbre_mot;
    //arbre_mot = creation_arbres_et_donne_vieux();
    arbre_mot = creation_arbres_et_donne();

    //t_tree arbre_nom, arbre_verb, arbre_adj, arbre_adve;
    //genPhraseAleat(*(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 3), *(arbre_mot + 1), 2);

    /*char base[25];
    printf("Quel base cherchez-vous ?\n");
    scanf("%s",base);
    recherche_base(base, *(arbre_mot), *(arbre_mot + 2), *(arbre_mot + 1), *(arbre_mot + 3));*/

    /*printf("Quel mot cherchez-vous ?\n");
    char mot[] = "preneuse";
    recherche_flechie(*(arbre_mot), mot);

    return 0;


    printf("\n");
    flechies tempo;
    tempo = obtFlechNom(*genMotAleat(arbre_mot));
    printf(tempo.nom_mot);
    */
     return 0;
}
