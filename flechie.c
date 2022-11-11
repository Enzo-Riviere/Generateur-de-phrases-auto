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


int bonFlechAdj(p_cell_mot forme_nom, p_cell_mot forme_adj) {
    /*
     * cette fonction dit si le flechie si l'adjectif qui est accordé.
     */
    char signi_nom, signi_adj,**tempo_nom = (char**) malloc(sizeof(char*) * 2), **tempo_adj = (char**) malloc(sizeof(char*) * 2);
    int res = 0;
    *(tempo_nom) = chaProch(forme_nom->value, ':');
    *(tempo_nom + 1 ) = chaProch(*(tempo_nom), '+');
    *(tempo_adj) = chaProch(forme_adj->value, ':');
    *(tempo_adj + 1 ) = chaProch(*(tempo_adj), '+');
    while((*(*(tempo_adj)) != '\0') && !(res)) {
    signi_nom = *(*(tempo_nom));
    signi_adj = *(*(tempo_adj));
    if ((signi_nom != 'I')) {
        res = ((signi_nom == signi_adj) || (signi_adj == 'I'));
    }
    else {
        res = ((signi_adj == 'I') || (signi_adj == 'M'));
    }
    signi_nom = *(*(tempo_nom + 1));
    signi_adj = *(*(tempo_adj + 1));
    res = res && (signi_nom == signi_adj);
    }
    return res;
}

flechies obtFlechAdj(flechies nom_choisi, mot adj_choisi) {
    flechies res;
    p_cell_mot tempo_gramm = adj_choisi.forme_grammatical.head, tempo_flech;
    while((tempo_gramm != NULL) && bonFlechAdj(nom_choisi.forme_grammatical, tempo_gramm)) {
        tempo = tempo->next;
    }
    remplFlechi()
}