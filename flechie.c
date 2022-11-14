//
// Created by yael1 on 25/10/2022.
//

#include "flechie.h"
#include "t_std.h"
#include <stdlib.h>
#include <Time.h>
#include <string.h>

void copieProfonde(char* chaine_origine, char* chaine_cible) {
    /*
     * Cette fonction est utilisée pour cocpier tous les caractères d'un chaien de charactère dans une autres
     */
    int i = 0;
    while (chaine_origine[i] != '\0') {
        *(chaine_cible + i) = chaine_origine[i];
        i++;
    }
    *(chaine_cible + i) = '\0';
}

void remplFlechi(p_cell_mot flechie, p_cell_mot forme_grammatical, flechies *ad_fle) {
    int i = 0;
    /*
    while(flechie->value[i] != '\0') {
        ad_fle->nom_mot[i] = flechie->value[i];
    }
     */
    ad_fle->nom_mot[i] = '\0';
    //copieProfonde(flechie->value, (ad_fle->nom_mot));
    ad_fle->forme_grammatical.head = forme_grammatical;
}



char** separeCaractGramm(char* chaine) {
    /*
     * Cette fonction sert à separer la chaine de caratères forme grammatical
     * cette fonction est abandonné
     */
    /*
    printf("initialisation\n");
    char** res, *tempo;
    int i = 1;
    res = malloc(sizeof(char *));
    printf("premirer strok\n");
    tempo = strtok(chaine,":");
    printf("condition if\n");
    if(tempo == NULL) {
        free(res);
        res = NULL;
    }
    else {
        int j;
        printf("boucle\n");
        while (tempo != NULL) {
            printf("start %d\n", i);
            copieProfonde(tempo, *(res + (i - 1)));
            j = 0;
            while (tempo[j] != '\0') {
                *(*(res + (i - 1)) + j) = tempo[j];
                j++;
            }
            *(*(res + (i - 1)) + j) = '\0';
            printf(*(res + (i - 1)));
            printf("\n");
            tempo = strtok(NULL, ":");
            printf("condition if 2 \n");
            if (tempo != NULL) {
                i++;
                printf("la nouvelle taille %d\n", sizeof(char*) * i);
                res = realloc(res, (sizeof(char *) * i));
            }
            printf("end %d\n", i);
        }
        printf("out\n");
    }
     */
    //res = realloc(res, sizeof(char*) * (i - 1));
    return NULL;
}

char* chaProch(char* phrase, char lettre) {
    int i = 0;
    while((*(phrase + i + 1 ) != '\0') && (*(phrase + i) != lettre)) {
        i++;
    }
    return (phrase + i + 1 );
}

