//
// Created by yael1 on 25/10/2022.
//


#ifndef GENERATEUR_DE_PHRASES_AUTO_FLECHIE_H
#define GENERATEUR_DE_PHRASES_AUTO_FLECHIE_H

#include <stdio.h>
#include <stdlib.h>
#include "t_std.h"

//Création de la structure de chaque mot fléchie :
typedef struct {
    char nom_mot[100];
    t_std_list_mot forme_grammatical;
}flechies;

//Création de la structure pour stocker tout les noms fléchies :
typedef struct{
    char nom_mot[100];
    int nb_flechie;
    t_std_list_mot forme_grammatical;
    t_std_list_mot flechies;
}mot;

void copieProfonde(char* chaine_origine, char* chaine_cible);
char** separeCaractGramm(char* chaine);
char* chaProch(char* phrase, char lettre);

#endif //GENERATEUR_DE_PHRASES_AUTO_FLECHIE_H
