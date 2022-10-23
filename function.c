//
// Created by Quentin on 22/10/2022.
//

#include "function.h"
#include <stdlib.h>

char** stringSliceList(char* astring, char limit) {
    /*
     * Cette focntion découpe la chaine astring de charactère une liste de caractère. La variable limite sert à séparer la liste en sous liste.
     * char* astring : chaine de caractère qui vas être découpé.
     * char limit : charactère délimitant chaque chaine de charactère
     * note : chaque chaine de carctère se termine par '\0'.
     * return : char** res : la chaine de chaine de caractère.
     */
    char **res = NULL;
    int nb_char = 0, prime_size = 0, size = 0, cicle = 0;
    //printf("%c \n", *(astring + cicle));
    if (*(astring + cicle) != '.') {
        res = (char **) malloc(sizeof(char*)  * ++prime_size);
        //*(res) = (char*) malloc(sizeof(char) * ++size);
        while (*(astring + cicle) != '.') {
            //temp = astring + cicle++ * sizeof(char);
            //printf("%d %c %d\n", size, *(astring + cicle), *(astring + cicle) != '.');
            //temp = astring + nb_char;
            if (*(astring + cicle) == limit) {
                //printf("yee\n");
                if (prime_size) {
                    /*
                    *(res + prime_size - 1) = realloc(*(res + prime_size), ++size);
                    *(*(res + prime_size - 1) + (size - 1)) = '\0';
                     * */
                    res = realloc(res, ++prime_size);
                    size = 0;
                }
            } else {
                printf("%c\n", *(astring + cicle));
                if (!size) {
                    *(res + prime_size - 1) = (char*) malloc(sizeof(char) * ++size);
                    printf("\n %c \n", *(astring + cicle));
                    *(*(res + prime_size - 1) + (size - 1)) = *(astring + cicle);
                } else {
                    *(res + prime_size - 1) = realloc(*(res + prime_size - 1), ++size);
                    *(*(res + prime_size - 1) + (size - 1)) = *(astring + cicle);
                    printf("\n %c \n", *(astring + cicle));
                }
            }
            //printf(*(res + prime_size - 1));
            printf("\n %d \n", size);
            cicle++;
        }
    }
    return res;
}

char** strslice(char* astring, char* limit) {
    char **res, *temp, *slice;
    int number = 0;
    res = (char**) malloc(sizeof(char*));
    slice = strtok(astring, limit);
    *(res) = slice;
    number++;
    while(slice != NULL) {
        res = realloc(res, number + 1);
        slice = strtok(NULL, limit);
        *(res + number++) = slice;
    }
    printf("ok\n");
    return res;
}