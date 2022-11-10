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
    copieProfonde(flechie->value, (ad_fle->nom_mot));
    ad_fle->forme_grammatical.head = forme_grammatical;
}

char** separeCaractGramm(char* chaine) {
    /*
     * Cette fonction sert à separer la chaine de caratères forme grammatical
     */
    char** res, *tempo;
    int i = 1;
    res = malloc(sizeof(char *));
    tempo = strtok(chaine,":");
    if(tempo == NULL) {
        free(res);
        res = NULL;
    }
    while(tempo != NULL) {
        copieProfonde(tempo, *(res + (i - 1)));
        tempo = strtok(chaine,":");
        if(tempo != NULL) {
            i++;
            res = realloc(res, sizeof(char*) * i);
        }
    }
    //res = realloc(res, sizeof(char*) * (i - 1));
    return res;
}


flechies obtFlechNom(mot nom_choisi) {
    /*
     * Cette fonction permet d'obtenir le flechie du nom.
     */
    srand(time(NULL));
    flechies res;
    p_cell_mot temp_f = nom_choisi.flechies.head, temp_g = nom_choisi.forme_grammatical.head;
    while((temp_f->next != NULL) && (rand() % 2 == 1)) {
        temp_f = temp_f->next;
        temp_g = temp_g->next;
    }
    remplFlechi(temp_f, temp_g, &res);
    return res;
}


int bonFlechiesAdj(t_std_list_mot forme_nom, t_std_list_mot form_adj) {
    char typeNom[4], genreNom[7], nbNom[3];
    fscanf(forme_nom.head->value, "%s:%s+%s", &typeNom, &genreNom, &nbNom);
}
/*
flechies obtFlechAdj(mot nom_choisi, mot adj_choisi) {
    flechies res;

}
 */