//
// Created by yael1 on 25/10/2022.
//

#ifndef GENERATEUR_DE_PHRASES_AUTO_T_STD_H
#define GENERATEUR_DE_PHRASES_AUTO_T_STD_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "flechie.h"

//Création de la structure d'une cellule pour une chaine de caractère (stockage des mots fléchies) :
typedef struct{
    char value[1000];
    struct p_cell_mot *next;
}*p_cell_mot, t_cell_mot;

//Création de la structure d'une cellule pour un mot (stockage des lettres de l'alphabet dans les arbres):
/*typedef struct{
    char value;
    struct p_cell_mot *next;
}*p_cell_lettre, t_cell_lettre;*/

/*typedef struct{
    p_node valeur;
    struct p_cell_mot *next;
}*p_cell_lettre, t_cell_lettre;
*/

//Création de la structure d'une liste simple pour stocker des cellules avec des chaines de caractères :
typedef struct{
    p_cell_mot head;
} t_std_list_mot;

//Création de la structure d'une liste simple pour stocker des cellules avec un lettre :
/*typedef struct{
    p_cell_lettre head;
} t_std_list_lettre;*/


//p_cell_lettre createCellLettre(char);
p_cell_mot createCellMot(char[]);

//t_std_list_lettre createEmptylistLettre();
t_std_list_mot createEmptylistmot();

//p_node chainageLettre(t_std_list_lettre* ,char);
//p_node chainageMot(t_std_list_lettre* , char*);



#endif //GENERATEUR_DE_PHRASES_AUTO_T_STD_H
