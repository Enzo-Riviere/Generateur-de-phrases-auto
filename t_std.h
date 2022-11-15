//
// Created by yael1 on 25/10/2022.
//

#ifndef GENERATEUR_DE_PHRASES_AUTO_T_STD_H
#define GENERATEUR_DE_PHRASES_AUTO_T_STD_H

#include <stdio.h>
#include <stdlib.h>

//Création de la structure d'une cellule pour une chaine de caractère (stockage des mots fléchies) :
typedef struct n_cell_mot{
    char value[1000];
    struct n_cell_mot *next;
}*p_cell_mot, t_cell_mot;



//Création de la structure d'une liste simple pour stocker des cellules avec des chaines de caractères :
typedef struct{
    p_cell_mot head;
} t_std_list_mot;


//p_cell_lettre createCellLettre(char);
p_cell_mot createCellMot(char[]);

//t_std_list_lettre createEmptylistLettre();
t_std_list_mot createEmptylistMot();


//p_node chainageMot(t_std_list_lettre* , char*);



#endif //GENERATEUR_DE_PHRASES_AUTO_T_STD_H
