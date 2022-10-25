//
// Created by yael1 on 25/10/2022.
//

#include "fonction.h"

int lettre_dans_liste(t_std_list_lettre list, char lettre){
    p_cell_lettre tmp = list.head;
    int res = 0;
    while (tmp != NULL && (tmp->value != lettre)){
        tmp = tmp->next;
    }
    if (tmp != NULL){
        res = 1;
    }
    return res;
}
