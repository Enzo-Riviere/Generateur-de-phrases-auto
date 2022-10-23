#include <stdio.h>
#include "function.h"

int main() {
    char mystring[] = "j'aime beaucoup le brouge.";
    char** temp;
    temp = stringSliceList(mystring, ' ');
    printf(*temp);
    return 0;
}
