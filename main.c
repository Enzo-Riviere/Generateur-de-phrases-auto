#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 1000

int main() {

    FILE* fichier = NULL;
    char chaine1[TAILLE_MAX] = "";
    char chaine2[TAILLE_MAX] = "";
    char chaine3[TAILLE_MAX] = "";
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("C:\\Users\\enzor\\CLionProjects\\Phrases-auto\\test.txt", "r+");

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL){

            char chaine1[TAILLE_MAX] = "";
            char chaine2[TAILLE_MAX] = "";
            char chaine3[TAILLE_MAX] = "";

            fscanf(fichier, "%s   %s   %s", &chaine1, &chaine2, &chaine3);

            printf("%s\n%s\n%s\n\n\n", chaine1, chaine2, chaine3);

        }

        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}