//
// Created by yael1 on 25/10/2022.
//

#include <malloc.h>
#include "node.h"

//Cette fonction permet de créer un noeud
//Elle prend en paramètre le caractère qu'on veut y stocker
//Elle retourne un noeud
p_node createNode(char lettre){
    p_node noeud;
    noeud = (p_node)malloc(sizeof(t_node));

    noeud->val = lettre;
    noeud->nb_enfants = 0;
    noeud->enfants = (p_node*) malloc (sizeof (p_node));
    noeud->fin_mot = 0;

    return noeud;
}

//Cette fonction permet d'ajouter un enfant dans un tableau d'enfant d'un noeud
//Elle prend en paramètre un noeud ansi que le caractère à ajouter
//Elle retourne un noeud
p_node ajouter_enfant(p_node noeud, char lettre){
    p_node nv_enfant= createNode(lettre);
    noeud->enfants[noeud->nb_enfants] = nv_enfant;
    noeud->nb_enfants ++;
    noeud->enfants = (p_node*) realloc (noeud->enfants ,sizeof (p_node) * (noeud->nb_enfants+1));

    return nv_enfant;
}

//Cette fonction permet mot vide
//Elle prend en paramètre la chaine de caractère du mot sous forme de base
//Elle retourne un type mot
mot* creer_mot(char mot_court[]) {
    mot *temp;
    temp = (mot*) malloc(sizeof(mot));
    temp->nb_flechie = 0;

    //boucle pour copier le mot
    int i = 0;
    while(mot_court[i] != '\0') {
        temp->nom_mot[i] = mot_court[i];
        i++;
    }
    temp->nom_mot[i] = '\0';
    //initilaisation des deux liste
    temp->flechies = createEmptylistMot();
    temp->forme_grammatical = createEmptylistMot();
    return temp;
}

void ajout_flech(p_node pn, char mot_court[], char flechie[], char type[]) {
    /*
     * Cette fonction sert à jouter le mot fléchie à au dernier caratère du mot de base.
     * Cette fonction est appelée dans void ajout_mot(t_tree* arbre, char mot_court[], char flechie[], char type[])
     * p_node pn : pointeur sur le noeud correspondant au dernier caractère du mot sous sa forme basique
     * char mot_court[] : chaine de charactère contenant
     * char flechie[] : la forme fléchie du mt
     * char type[] : chaine de carcatère contenant tous les indormation sur le mot fléchie. exemple : "Nom:Mas+SG"
     * note : l'exemple précédent s'applique uniquement pour les noms et est unquement pour désigner la chaine de carctère qui est constiruer de tous les carctère entre \t et \n dans le fichier .txt
     */
    //Implementation du flechie
    //on regarde si c'est le premier flechie
    //actualistation
    if (!(pn->fin_mot)) {
        pn->fin_mot = 1;
        pn->si_fin_mot = creer_mot(mot_court);
    }
    //on incrémente le nombre de flechie
    pn->si_fin_mot->nb_flechie++;
    //boucle pour le flechie
    //On rajoute une noeud contenant la chaine de caractère qui est le flechie
    if (pn->si_fin_mot->flechies.head != NULL) {
        p_cell_mot temp = pn->si_fin_mot->flechies.head;
        p_cell_mot mom = pn->si_fin_mot->forme_grammatical.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createCellMot(flechie);
        //on fait de meme pour la forme gramaticale
        //boucle pour la forme grammaticale
        while (mom->next != NULL) {
            mom = mom->next;
        }
        mom->next = createCellMot(type);
    }
    else {
        //autre cas
        pn->si_fin_mot->flechies.head = createCellMot(flechie);

        pn->si_fin_mot->forme_grammatical.head = createCellMot(type);
    }

}