//
// Created by yael1 on 25/10/2022.
//

#include "flechie.h"
#include "t_std.h"
#include <stdlib.h>
#include <Time.h>
#include <string.h>

//Cette fonction permet de d'obetnir un pointeur de caractère vers le caractère qui est après un caractère donné
//Elle prend en paramètre une chaine de caractère ainsi qu'un caratère simple
//Elle retourne un pointeur de caractère poinatnt vers le caractère après lettre dans la chaine phrase
char* chaProch(char* phrase, char lettre) {
    int i = 0;
    while((*(phrase + i + 1 ) != '\0') && (*(phrase + i) != lettre)) {
        i++;
    }
    return (phrase + i + 1 );
}

