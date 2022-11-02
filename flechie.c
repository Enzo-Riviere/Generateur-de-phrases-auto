//
// Created by yael1 on 25/10/2022.
//

#include "flechie.h"
#include "node.h"
#include "t_std.h"

mot* creer_mot(char mot_court[]) {
    mot *temp;
    temp = (mot*) malloc(sizeof(mot));
    temp->nb_flechie = 0;
    int i = 0;
    while(mot_court[i] != '\0') {
        temp->nom_mot[i] = mot_court[i];
    }
    temp->nom_mot[i] = '\0';
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
    if (!(pn->fin_mot)) {
        pn->fin_mot = 0;
        pn->si_fin_mot = creer_mot(mot_court);
    }
    pn->si_fin_mot->nb_flechie++;
    pn->fin_mot++;
    p_cell_mot temp = pn->si_fin_mot->flechies.head;
    while(temp->next == NULL) {
        temp = temp->next;
    }
    temp->next = createCellMot(flechie);
    temp = pn->si_fin_mot->forme_grammatical.head;
    while(temp->next == NULL) {
        temp = temp->next;
    }
    temp->next = createCellMot(type);
}