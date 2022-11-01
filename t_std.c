//
// Created by yael1 on 25/10/2022.
//

#include <malloc.h>
#include "t_std.h"
#include "node.h"
#include "flechie.h"

//Fonction qui créer une cellule stockant une lettre
//Elle prend en paramètre un caractère qui est la lettre à stocker dans la cellule, er retourne donc une cellule
/*p_cell_lettre createCellLettre(char lettre){
    p_cell_lettre p_res = NULL;
    p_res = (p_cell_lettre) malloc (sizeof(t_cell_lettre));

    p_res->value = lettre;
    p_res->next = NULL;

    return p_res;
}*/

/*p_cell_lettre createCellLettre(char lettre){
    p_cell_lettre nv_cellule = NULL;
    nv_cellule = (p_cell_lettre) malloc (sizeof(t_cell_lettre));

    p_node nouveau_noeud = createNode(lettre);
    nv_cellule->valeur = nouveau_noeud;
    nv_cellule->next = NULL;

    return nv_cellule;
}*/

//Fonction qui créer une cellule stockant une mot
//Elle prend en paramètre une chaine de caractère qui est le mot à stocker dans la cellule, er retourne donc une cellule
p_cell_mot createCellMot(char mot_cours[100]){
    p_cell_mot p_res = NULL;
    p_res = (p_cell_mot) malloc (sizeof(t_cell_mot));
    if (p_res != NULL){
        int i = 0;
        while(mot_cours[i] != '\0') {
            p_res->value[i] = mot_cours[i];
            i++;
        }
        p_res->value[i] = '\0';
        p_res->next = NULL;
    }
    return p_res;
}



//Fonction qui créer une liste de "lettre" vide
//Elle ne prend rien en parametre et retourne une liste de lettre (t_std_list_lettre)
/*t_std_list_lettre createEmptylistLettre(){
    t_std_list_lettre maListVide;
    maListVide.head = NULL;
    return maListVide;
}*/


//Fonction qui créer une liste de "mot" vide
//Elle ne prend rien en paramètre et retourne une liste de mot (t_std_list_mot)
t_std_list_mot createEmptylistMot(){
    t_std_list_mot maListVide;
    maListVide.head = NULL;
    return maListVide;
}


//Fonction qui permet d'ajouter une nouvelle une nouvelle cellule dans une liste de lettre
//Elle prend en paramètre la liste de lettre à laquelle on veut ajouter une cellule, ainsi que la lettre à mettre dans cette nouvelle cellule. Elle ne retourne rien.
/*p_node chainageLettre(t_std_list_lettre *listeLettre, char lettre){
    p_cell_lettre nouvelle_cellule;
    nouvelle_cellule = createCellLettre(lettre);

    if (listeLettre->head == NULL){
        listeLettre->head = nouvelle_cellule;
    }else{
        nouvelle_cellule->next = listeLettre->head;
        listeLettre->head = nouvelle_cellule;
    }
    return nouvelle_cellule->valeur;
}
*/
/*p_node chainageMot(t_std_list_lettre *listeLettre, char lettre){
    p_cell_lettre nouvelle_cellule;
    nouvelle_cellule = createCellLettre(lettre);

    if (listeLettre->head == NULL){
        listeLettre->head = nouvelle_cellule;
    }else{
        nouvelle_cellule->next = listeLettre->head;
        listeLettre->head = nouvelle_cellule;
    }
    return nouvelle_cellule->valeur;
}*/