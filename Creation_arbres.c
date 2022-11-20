//
// Created by yael1 on 03/11/2022.
//

#include "Creation_arbres.h"
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

#define TAILLE_MAX 100



char typeIndentifie(char *ligne) {
    /*
     * Cette fonction identify le type d'un mot.
     * char** ligne : correspond à une ligne du du dictionnaire.
     * return char* est le nom du type.
     */
    char caractere_important;
    caractere_important = ligne[2];
    if (ligne[0] == 'N' && ligne[1] == 'o' && ligne[2] == 'm') {
        return 'n';
    }
    if (ligne[0] == 'V' && ligne[1] == 'e' && ligne[2] == 'r') {
        return 'v';
    }
    if (ligne[0] == 'A' && ligne[1] == 'd' && ligne[2] == 'j') {
        return 'j';
    }
    if (ligne[0] == 'A' && ligne[1] == 'd' && ligne[2] == 'v') {
        return 'a';
    }
    if (ligne[0] == 'D' && ligne[1] == 'e' && ligne[2] == 't') {
        return 'd';
    }
    return '0';
}


//Cette fonction créer les différents arbres
//Elle ne prend rien en paramètre
//Elle ne retourne rien car on utilise les adresses des arbres afin de pouvoir les utiliser par la suite
t_tree* creation_arbres_et_donne(){

    t_tree arbre_nom = createEmptyTree();
    t_tree arbre_verbe = createEmptyTree();
    t_tree arbre_adj = createEmptyTree();
    t_tree arbre_adv = createEmptyTree();
    t_tree arbre_det = createEmptyTree();
    t_tree* arbre_mot;
    arbre_mot = (t_tree*) malloc(sizeof(t_tree) * 5);
    *(arbre_mot) = arbre_nom;
    *(arbre_mot + 1) = arbre_verbe;
    *(arbre_mot + 2) = arbre_adj;
    *(arbre_mot + 3) = arbre_adv;
    *(arbre_mot + 4) = arbre_det;
    //FILE* fichier = NULL;
    char chaine1[TAILLE_MAX] = "";
    char chaine2[TAILLE_MAX] = "";
    char chaine3[TAILLE_MAX] = "";


    FILE* fichier = fopen("..\\dictionnaire_non_accentue.txt", "r");
    //Si le fichier n'est pas vide
    if (fichier != NULL)
    {
        //tant qu'on n'est pas à la dernière ligne
        while (fscanf(fichier,"%s\t%s\t%s", chaine1,chaine2,chaine3) != EOF){


            char type = typeIndentifie(chaine3);

            switch (type) {
                // n = Nom
                case 'n' :{
                    ajout_mot(&arbre_nom, chaine2, chaine1, chaine3);
                    break;
                }
                    // v = verbe
                case 'v':{
                    ajout_mot(&arbre_verbe,chaine2, chaine1, chaine3);
                    break;
                }
                    // j = Adjectif
                case 'j' :{
                    ajout_mot(&arbre_adj,chaine2, chaine1, chaine3);
                    break;
                }
                    // a = adverbe
                case 'a':{
                    ajout_mot(&arbre_adv,chaine2, chaine1, chaine3);
                    break;
                }
                case 'd':{
                    //d = determinant
                    ajout_mot(&arbre_det, chaine2, chaine1, chaine3);
                    break;
                }
                default : {
                    //le cas où c'est un déterminat ou une préposistion, on l'ignore
                    break;
                }

            }

        }

        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier\n");
    }
    return arbre_mot;
}
