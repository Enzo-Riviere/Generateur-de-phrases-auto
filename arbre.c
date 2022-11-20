//
// Created by yael1 on 25/10/2022.
//
#include <stdlib.h>
#include "arbre.h"
#include "fonction.h"
#include "flechie.h"
#include <time.h>

#define TAILLE_MAX 25

t_tree createEmptyTree (){
    t_tree mytree;
    mytree.root = createNode(' ');
    return mytree;
}

void ajout_mot(t_tree* arbre, char mot_court[], char flechie[], char type[]){
    int i = 0;
    p_node tmp = arbre->root;

    //On traite tout le mot en s'arrêtant avant le dernier caractère
    while(mot_court[i+1] != '\0'){
        //on regard si la lettre et dans le tableau
        if(lettre_dans_tableau(tmp, mot_court[i]) == 0){
            //on ajoute la nouvelle lettre comme branche du noeud et le pointeur prend son adresse
            p_node nv_tmp = ajouter_enfant(tmp, mot_court[i]);
            tmp = nv_tmp;

        }else{
            //on parcourt la liste des lettres déjà existant pour trouver l'adresse et le pointeur tmp prend cette adresse.
            int j = 0;
            while ((j< tmp->nb_enfants) && (tmp->enfants[j]->val != mot_court[i])){
                j++;
            }
            tmp = tmp->enfants[j];
        }
        i++;
    }

    //On traite le dernier caractère
    // on fait la même chose que dans la boucle
    if(lettre_dans_tableau(tmp, mot_court[i]) == 0){
        p_node nv_tmp = ajouter_enfant(tmp, mot_court[i]);
        tmp = nv_tmp;
    }else{
        int k = 0;
        while ((k< tmp->nb_enfants) && (tmp->enfants[k]->val != mot_court[i])){
            k++;
        }
        tmp = tmp->enfants[k];
    }

    ajout_flech(tmp,mot_court,flechie, type);
}



mot* genMotAleat(t_tree* arbre_mot) {
    /*
     * Cette fonction prend en paramètre un arbre de mot est sort un mot aléatoirement.
     * */
    //srand(time(NULL));
    p_node temp = arbre_mot->root;
    int i = 1, nombre_enfant, f = 0;
    while (i) {

        //cas où on peut s'arrêter à ce p_node
        if (temp->fin_mot != 0) {

            //cas où ne peut pas continuer
            if (temp->nb_enfants == 0) {
                i = 0;
            }
            else {
                //si on à les deux choix alors on si rand sort un nombre impaire alors on continue
                if (rand() % 2 == 1) {
                    //printf("si on à les deux choix alors on si rand sort un nombre impaire alors on continue\n");
                    nombre_enfant = temp->nb_enfants;
                    temp = *(temp->enfants + (rand() % nombre_enfant));
                }
                //si c'est paire on s'arrête
                else {
                    i = 0;
                }
            }
        }
        else {
            //cas où on ne peut pas s'arrêter
            nombre_enfant = temp->nb_enfants;
            temp = *(temp->enfants + (rand() % nombre_enfant));
        }
        f++;
    }
    return temp->si_fin_mot;
}

char* accord_flechies_Adj(mot* nom_choisi, mot* adjectif_choisi, char type[]) {
    //On suppose le nom à un suel flechie
    return NULL;
}


/*
char* donne_flechoe(mot* mot_choisi) {
    char caractere_important;
    caractere_important = ligne[2];
    switch(caractere_important) {
        //En regarder les information pour chaque mots, on se rends compte que 'Nom', 'Ver', 'Adj', 'Adv' ont un troisième carctère unique
        case 'm' : {
            return "Nom";
            break;
        }
        case 'r': {
            return "Verbe";
            break;
        }
        case 'j': {
            return "Adjectif";
            break;
        }
        case 'v': {
            return  "Adverbe";
            break;
        }
        default : {
            //le cas où c'est un déterminat ou une préposistion, on l'ignore
            return "Non";
            break;
        }
    }
}*/

void extrait_mot_aleat(t_tree Nom, t_tree Adj, t_tree Adv, t_tree Verb ){
    /*
     * Cette foncton choisi aléatoirement depuis quelle arbre on doit générer aléatoirement un mot brut et lan,ce la fonction générant aléatoirement un mot brut.
     */
    //srand(time(NULL));
    int val = rand() % 4+1;

    switch (val) {
        case 1:{
            mot *nom = genMotAleat(&Nom);
            printf("%s\n",nom->nom_mot);
            break;
        }
        case 2:{
            mot *verbe = genMotAleat(&Verb);
            printf("%s\n",verbe->nom_mot);
            break;
        }
        case 3:{
            mot *adj = genMotAleat(&Adj);
            printf("%s\n",adj->nom_mot);
            break;
        }
        case 4:{
            mot *adv = genMotAleat(&Adv);
            printf("%s\n",adv->nom_mot);
            break;
        }
        default : {
            //le cas où c'est un déterminat ou une préposistion, on l'ignore
            printf("Non");
            break;
        }
    }
}




void genPhraseAleat(t_tree Nom, t_tree Adj, t_tree Adv, t_tree Verb, int cas) {
    /*
     * Cette fonction tous les arbes de mots et les utilise pou faire une phrase aléatoire sans accord.
     * */
    mot *nom_debut, *adjectif, *verbe1, *nom_fin, *verbe2, *adverbe;
    nom_debut = genMotAleat(&Nom);
    nom_fin = genMotAleat(&Nom);
    adjectif = genMotAleat(&Adj);
    verbe1 = genMotAleat(&Verb);
    verbe2 = genMotAleat(&Verb);
    adverbe = genMotAleat(&Adv);


    if (cas == 1) {
        // cas 1 : nom - adjectif - verbe - nom
        printf(nom_debut->nom_mot);
        printf(" ");

        printf(adjectif->nom_mot);
        printf(" ");

        printf(verbe1->nom_mot);
        printf(" ");

        printf(nom_fin->nom_mot);
        printf(".\n");
    }
    else {
        if (cas == 2) {
            // cas 2 : nom - 'qui' - verbe - verbe - nom - adjectif

            printf(nom_debut->nom_mot);
            printf(" qui ");

            printf(verbe1->nom_mot);
            printf(" ");

            printf(verbe2->nom_mot);
            printf(" ");

            printf(nom_fin->nom_mot);
            printf(" ");

            printf(adjectif->nom_mot);
            printf(".\n");
        }
        else {
            //cas 3 : nom - adjectif - verbe - adverbe


            nom_debut = genMotAleat(&Nom);
            printf(nom_debut->nom_mot);
            printf(" ");

            adjectif = genMotAleat(&Adj);
            printf(adjectif->nom_mot);
            printf(" ");

            verbe1 = genMotAleat(&Verb);
            printf(verbe1->nom_mot);
            printf(" ");

            printf(adverbe->nom_mot);
            printf(".\n");
        }
    }
}


flechies obtFlechNom(mot nom_choisi) {
    /*
     * Cette fonction permet d'obtenir le flechie du nom.
     */
    //srand(time(NULL));
    flechies res;
    p_cell_mot temp_f = nom_choisi.flechies.head, temp_g = nom_choisi.forme_grammatical.head;
    while((temp_f->next != NULL) && (rand() % 2 == 1)) {
        temp_f = temp_f->next;
        temp_g = temp_g->next;
    }

    res.nom_mot = temp_f->value;
    res.forme_grammatical.head = temp_g;
    return res;
}


int bonFlechAdj(p_cell_mot forme_nom, p_cell_mot forme_adj) {
    /*
     * cette fonction dit si le flechie si l'adjectif qui est accordé.
     */

    char signi_nom, signi_adj,**tempo_nom = (char**) malloc(sizeof(char*) * 2), **tempo_adj = (char**) malloc(sizeof(char*) * 2);
    int res = 0;
    //printf("initilisation\n");
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
        if ((signi_adj != 'I') && (signi_nom != 'I')) {
            res = res && (signi_nom == signi_adj);
        }

        *(tempo_adj) = chaProch(*(tempo_adj), ':');
        *(tempo_adj + 1 ) = chaProch(*(tempo_adj), '+');
    }

    return res;
}

flechies obtFlechAdj(flechies nom_choisi, mot adj_choisi, t_tree t) {
    /*
     * Cette fonction sert à trouver le bon fléchie d'un mot par rapport à un fléchie donné.
     * */

    //srand(time(NULL));

    flechies res;
    p_cell_mot tempo_gramm, tempo_flech;
    p_cell_mot sure_gramm, sure_flech;
    do {
        tempo_gramm = adj_choisi.forme_grammatical.head;
        tempo_flech = adj_choisi.flechies.head;
        sure_gramm = tempo_gramm;
        sure_flech = tempo_flech;

        while ((tempo_gramm != NULL) &&
               (!(bonFlechAdj(nom_choisi.forme_grammatical.head, sure_gramm)) || (rand() % 2 == 0))) {

            if (bonFlechAdj(nom_choisi.forme_grammatical.head, tempo_gramm) &&
                (!(bonFlechAdj(nom_choisi.forme_grammatical.head, sure_gramm)) || (rand() % 2 == 0))) {
                sure_gramm = tempo_gramm;
                sure_flech = tempo_flech;
            }

            tempo_gramm = tempo_gramm->next;
            tempo_flech = tempo_flech->next;
        }
        adj_choisi = *genMotAleat(&t);
    } while(!(bonFlechAdj(nom_choisi.forme_grammatical.head, sure_gramm)));

    if (!(bonFlechAdj(nom_choisi.forme_grammatical.head, sure_gramm))) {
        // Cas ou on n'a rien trouve
        res = obtFlechAdj(nom_choisi, *genMotAleat(&t), t);
    }
    else {
        // Cas ou on a trouvé quelque chose
        res.nom_mot = sure_flech->value;
        res.forme_grammatical.head = sure_gramm;
    }
    return res;
}


int bonFlechVer(p_cell_mot forme_nom, p_cell_mot forme_adj) {
    /*
     * cette fonction dit si le flechie si le verbe qui est accordé.
     */

    char signi_nom, signi_adj,**tempo_nom = (char**) malloc(sizeof(char*) * 2), **tempo_adj = (char**) malloc(sizeof(char*) * 3);

    int res = 0;

    if((forme_adj->value[6] != 'f') && ((forme_adj->value[4] != 'P') || (forme_adj->value[5] != 'P') || (forme_adj->value[6] != 'r') || (forme_adj->value[6] != 'e'))) {
        *(tempo_nom) = chaProch(forme_nom->value, ':');
        *(tempo_nom + 1) = chaProch(*(tempo_nom), '+');
        *(tempo_adj) = chaProch(forme_adj->value, ':');
        *(tempo_adj + 1) = chaProch(*(tempo_adj), '+');
        *(tempo_adj + 2) = chaProch(*(tempo_adj + 1), '+');

        while ((*(*(tempo_adj)) != '\0') && !(res)) {

            signi_adj = *(*(tempo_adj + 2) + 1);

            res = (signi_adj == '3');

            signi_nom = *(*(tempo_nom + 1));
            signi_adj = *(*(tempo_adj + 1));
            if (signi_nom != 'I') {
                res = res && (signi_nom == signi_adj);
            }

            *(tempo_adj) = chaProch(*(tempo_adj), ':');
            *(tempo_adj + 1) = chaProch(*(tempo_adj), '+');
            *(tempo_adj + 2) = chaProch(*(tempo_adj + 1), '+');
        }
    }

    return res;
}

flechies obtFlechVer(flechies nom_choisi, mot adj_choisi, t_tree t) {
    /*
    * Cette fonction sert à trouver le bon fléchie d'un verbe par rapport à un fléchie d'un mot donné.
    * */
    //srand(time(NULL));

    flechies res;
    p_cell_mot tempo_gramm, tempo_flech;
    p_cell_mot sure_gramm, sure_flech;
    do {
        tempo_gramm = adj_choisi.forme_grammatical.head;
        tempo_flech = adj_choisi.flechies.head;
        sure_gramm = tempo_gramm;
        sure_flech = tempo_flech;

        while ((tempo_gramm != NULL) &&
               (!(bonFlechVer(nom_choisi.forme_grammatical.head, sure_gramm)) || (rand() % 2 == 0))) {

            if (bonFlechVer(nom_choisi.forme_grammatical.head, tempo_gramm) &&
                (!(bonFlechVer(nom_choisi.forme_grammatical.head, sure_gramm)) || (rand() % 2 == 0))) {
                sure_gramm = tempo_gramm;
                sure_flech = tempo_flech;
            }

            tempo_gramm = tempo_gramm->next;
            tempo_flech = tempo_flech->next;
        }
        adj_choisi = *genMotAleat(&t);
    } while(!(bonFlechVer(nom_choisi.forme_grammatical.head, sure_gramm)));

    if (!(bonFlechVer(nom_choisi.forme_grammatical.head, sure_gramm))) {
        // Cas ou on n'a rien trouve
        res = obtFlechVer(nom_choisi, *genMotAleat(&t), t);
    }
    else {
        // Cas ou on a trouvé quelque chose
        res.nom_mot = sure_flech->value;
        res.forme_grammatical.head = sure_gramm;
    }

    return res;
}



void genPhraseAleatFlech(t_tree Nom, t_tree Adj, t_tree Adv, t_tree Verb, t_tree Det, int cas) {
    /*
     * Cette fonction tous les arbes de mots et les utilise pou faire une phrase aléatoire avec accord.
     * */
    mot *nom_debut_mot, *adjectif_mot, *verbe1_mot, *nom_fin_mot, *detereminant_debut_mot, *detereminant_fin_mot;
    nom_debut_mot = genMotAleat(&Nom);
    nom_fin_mot = genMotAleat(&Nom);
    adjectif_mot = genMotAleat(&Adj);
    verbe1_mot = genMotAleat(&Verb);

    detereminant_debut_mot = genMotAleat(&Det);
    detereminant_fin_mot = genMotAleat(&Det);

    flechies nom_debut, adjectif, verbe1, nom_fin, detereminant_debut, detereminant_fin;

    //Generation nom :
    detereminant_debut = obtFlechNom(*detereminant_debut_mot);
    detereminant_fin = obtFlechNom(*detereminant_fin_mot);

    //Generation verbe :
    verbe1 = obtFlechVer(detereminant_debut, *verbe1_mot, Verb);

    //Generation determinant :
    nom_debut = obtFlechAdj(detereminant_debut, *nom_debut_mot, Nom);
    nom_fin = obtFlechAdj(detereminant_fin, *nom_fin_mot, Nom);


    if (cas == 1) {
        // cas 1 : nom - adjectif - verbe - nom

        //Generation adjetcif :
        adjectif = obtFlechAdj(detereminant_debut, *adjectif_mot, Adj);

        printf(detereminant_debut.nom_mot);
        printf(" ");

        printf(nom_debut.nom_mot);
        printf(" ");

        printf(adjectif.nom_mot);
        printf(" ");

        printf(verbe1.nom_mot);
        printf(" ");

        printf(detereminant_fin.nom_mot);
        printf(" ");

        printf(nom_fin.nom_mot);
        printf(".\n");
    }
    else {
        if (cas == 2) {
            // cas 2 : nom - 'qui' - verbe - verbe - nom - adjectif
            mot* verbe2_mot;
            verbe2_mot = genMotAleat(&Verb);
            flechies verbe2;
            verbe2 = obtFlechVer(detereminant_debut, *verbe2_mot, Verb);

            //Generation adjetcif :
            adjectif = obtFlechAdj(detereminant_fin, *adjectif_mot, Adj);

            printf(detereminant_debut.nom_mot);
            printf(" ");

            printf(nom_debut.nom_mot);
            printf(" qui ");
            printf(verbe1.nom_mot);
            printf(" ");
            printf(verbe2.nom_mot);
            printf(" ");

            printf(detereminant_fin.nom_mot);
            printf(" ");

            printf(nom_fin.nom_mot);
            printf(" ");
            printf(adjectif.nom_mot);
            printf(".\n");
        }
        else {
            //cas 3 : nom - adjectif - verbe - adverbe
            mot *adverbe;
            adverbe = genMotAleat(&Adv);

            //Generation adjetcif :
            adjectif = obtFlechAdj(detereminant_debut, *adjectif_mot, Adj);

            printf(detereminant_debut.nom_mot);
            printf(" ");
            printf(nom_debut.nom_mot);
            printf(" ");
            printf(adjectif.nom_mot);
            printf(" ");
            printf(verbe1.nom_mot);
            printf(" ");
            printf(adverbe->nom_mot);
            printf(".\n");
        }
    }
}