//
// Created by yael1 on 25/10/2022.
//
#include <stdlib.h>
#include "arbre.h"
#include "fonction.h"
#include "flechie.h"
#include <Time.h>

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
            //on ajoute la nouvelle lettre comme branche du noeud et le pointeur prend son addresse
            p_node nv_tmp = ajouter_enfant(tmp, mot_court[i]);
            tmp = nv_tmp;

        }else{
            //on parcours la liste des lettres déja existant pour trouver l'adresse et le pointeru tmp prend cette adresse.
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
    srand(time(NULL));
    p_node temp = arbre_mot->root;
    int i = 1, nombre_enfant, f = 0;
    while (i) {
        //printf("\n%d\n",f);
        //printf("_____v\n%c\n_____^\n",temp->val);
        //cas où on peut s'arrêter à ce p_node
        if (temp->fin_mot != 0) {
            //printf("cas où on peut s'arrêter à ce p_node\n");
            //cas où ne peut pas continuer
            if (temp->nb_enfants == 0) {
                //printf("cas où ne peut pas continuer\n");
                i = 0;
            }
            else {
                //si on à les deux choix alors on si rand sort un nompre impaire alors on continue
                if (rand() % 2 == 1) {
                    //printf("si on à les deux choix alors on si rand sort un nompre impaire alors on continue\n");
                    nombre_enfant = temp->nb_enfants;
                    temp = *(temp->enfants + (rand() % nombre_enfant));
                }
                //si c'est paire on s'arrête
                else {
                    //printf("si c'est paire on s'arrête\n");
                    i = 0;
                }
            }
        }
        else {
            //cas où on ne peut pas s'arrêter
            //printf("cas où on ne peut pas s'arrêter\n");
            nombre_enfant = temp->nb_enfants;
            temp = *(temp->enfants + (rand() % nombre_enfant));
        }
        f++;
    }
    /*
    printf("afficher nombre\n");
    printf("\n%d\n",f);
    printf("hhhhhhhhhhhhhhhhhhh\n");
    printf("%d\n", (temp != NULL));
    printf("%c",temp->val);
    printf("hhhhhhhhhhhhhhhhhhh\n");
     */
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


void genPhraseAleat(t_tree Nom, t_tree Adj, t_tree Adv, t_tree Verb, int cas) {
    mot *nom_debut, *adjectif, *verbe1, *nom_fin;
    nom_debut = genMotAleat(&Nom);
    nom_fin = genMotAleat(&Nom);
    adjectif = genMotAleat(&Adj);
    verbe1 = genMotAleat(&Verb);

    /*
    printf(nom_debut->flechies.head->value);
    printf("\t");
    printf(nom_debut->nom_mot);
    printf("\t");
    printf(nom_debut->forme_grammatical.head->value);
    printf("\n");
    printf(adjectif->flechies.head->value);
    printf("\t");
    printf(adjectif->nom_mot);
    printf("\t");
    printf(adjectif->forme_grammatical.head->value);
    printf("\n");
    printf(verbe1->flechies.head->value);
    printf("\t");
    printf(verbe1->nom_mot);
    printf("\t");
    printf(verbe1->forme_grammatical.head->value);
    printf("\n");

    printf(nom_debut->flechies.head->value);
    printf("\t");
    printf(nom_debut->nom_mot);
    printf("\t");
    printf(nom_debut->forme_grammatical.head->value);
    printf("\n");
     */

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
            mot* verbe2;
            verbe2 = genMotAleat(&Verb);
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
            mot *adverbe;
            adverbe = genMotAleat(&Adv);
            printf(nom_debut->nom_mot);
            printf(" ");
            printf(adjectif->nom_mot);
            printf(" ");
            printf(verbe1->nom_mot);
            printf(" ");
            printf(adverbe->nom_mot);
            printf(".\n");
        }
    }
}