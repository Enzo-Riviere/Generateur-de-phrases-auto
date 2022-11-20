Avant de compiler le fichier assurez-vous que l’exécutable est dans un dossier qui est à côté du fichier dictionnaire_non_accentue.txt.
Si ce n'est pas le cas aller à la ligne 64 dans le fichier creation_arbre.c et changez ..\\dictionnaire_non_accentue.txt de
FILE* fichier = fopen("..\\dictionnaire_non_accentue.txt", "r"); par le chemin absolu vers le fichier dictionnaire_non_accentue.txt ou relatif.
Dans le cas du chemin relatif, le chemin à parcourir est celui de l'exécutable pas des fichiers sources.
