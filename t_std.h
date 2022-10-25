//
// Created by yael1 on 25/10/2022.
//

#ifndef GENERATEUR_DE_PHRASES_AUTO_T_STD_H
#define GENERATEUR_DE_PHRASES_AUTO_T_STD_H

//Création de la structure d'une cellule pour une chaine de caractère :
typedef struct{
    char value[1000];
    struct p_cell_mot *next;
}*p_cell_mot;

//Création de la structure d'une cellule pour un mot :
typedef struct{
    char value;
    struct p_cell_mot *next;
}*p_cell_lettre;


//Création de la structure d'une liste simple pour stocker des cellules avec des chaines de caractères :
typedef struct{
    p_cell_mot head;
} t_std_list_mot;

//Création de la structure d'une liste simple pour stocker des cellules avec un lettre :
typedef struct{
    p_cell_lettre head;
} t_std_list_lettre;



#endif //GENERATEUR_DE_PHRASES_AUTO_T_STD_H
