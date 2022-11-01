//
// Created by yael1 on 25/10/2022.
//
#include <stdlib.h>
#include "arbre.h"
#include "fonction.h"

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
        printf("Enfant numero %d depuis root : %c\n",i, tmp->val);
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

    printf("Enfant numero %d depuis root : %c\n",i, tmp->val);
    /*if(tmp->fin_mot == 0){
        tmp->fin_mot = 1;
        flechies nv_mot;
        nv_mot.nom_mot = copier_mot(nv_mot.nom_mot,flechie);

    }*/
}


/*void ajout_mot(t_tree* arbre, char mot_court[], char* flechie, char type[]){
    int i = 0;
    p_node tmp = arbre->root;
    while(mot_court[i+1] != '\0'){
        if (lettre_dans_liste(tmp->enfant, mot_court[i]) == 0){
            p_node nv_tmp = chainageLettre(&tmp->enfant,  mot_court[i]);
            tmp = nv_tmp;
        }else{
            p_cell_lettre verif = tmp->enfant.head;
            while (verif->valeur->val != mot_court[i]){
                verif = verif->next;
            }
            tmp = verif->valeur;
        }
        i++;
    }
    if (lettre_dans_liste(tmp->enfant, mot_court[i]) == 0){
        p_node nv_tmp = chainageLettre(&tmp->enfant,  mot_court[i]);
        tmp = nv_tmp;
    }else{
        p_cell_lettre verif = tmp->enfant.head;
        while (verif->valeur->val != mot_court[i]){
            verif = verif->next;
        }
        tmp = verif->valeur;
    }
    if(tmp->fin_mot == 0){
        tmp->fin_mot = 1;
        flechies nv_mot;
        nv_mot.nom_mot = copier_mot(nv_mot.nom_mot,flechie);

    }
}*/


