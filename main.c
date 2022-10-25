#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    char mystring[1000] = "Adv";
    printf(typeIndentify(mystring));
    printf("\n");
    char **bhi, hbil[1000] = "0";
    bhi = &hbil;
    magie(bhi);
    printf("%c",hbil[0]);
    return 0;
}
