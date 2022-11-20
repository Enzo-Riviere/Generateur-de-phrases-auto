//
// Created by yael1 on 25/10/2022.
//

#include <malloc.h>
#include "t_std.h"
#include "node.h"
#include "flechie.h"


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



//Fonction qui créer une liste de "mot" vide
//Elle ne prend rien en paramètre et retourne une liste de mot (t_std_list_mot)
t_std_list_mot createEmptylistMot(){
    t_std_list_mot maListVide;
    maListVide.head = NULL;
    return maListVide;
}
