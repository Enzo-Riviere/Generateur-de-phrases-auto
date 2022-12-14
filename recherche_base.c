//
// Created by enzor on 05/11/2022.
//

#include "recherche_base.h"

//Cette fonction vérifie si le mot est dans l'arbre
//Elle prend en paramètre un arbre et le mot que l'on recherche
//Elle retourne un entier
int mot_dans_arbre(t_tree arbre, char mot[]){
    p_node tmp = arbre.root;
    int i = 0, taille_mot = 0;
    while(mot[i] != '\0'){
        taille_mot ++;
        i++;
    }
    i = 0;
    //On parcourt le mot lettre par lettre
    while(mot[i] != '\0'){
        //Si la lettre du mot est dans le tableau
        if(lettre_dans_tableau(tmp, mot[i])==1){
            int j = 0;
            //On se place sur la lettre du mot dans l'arbre
            while ((j< tmp->nb_enfants) && (tmp->enfants[j]->val != mot[i])){
                j++;
            }
            //On va à la lettre suivante
            tmp = tmp->enfants[j];
        }
        else{
            return 0;
        }
        i++;
    }
    return 1;
}

//Cette fonction recherche si le mot existe dans les différents arbres
//Elle prend en paramètre la base que l'on cherche et tous nous arbres (nom, verbes, adjectifs, adverbe)
//Elle ne retourne rien
void recherche_base(char base[], t_tree arbre_nom, t_tree arbre_adjectif, t_tree arbre_verbe, t_tree arbre_adverbe) {
    int res = 0;
    if (mot_dans_arbre(arbre_nom, base)) {
        printf("La base %s est un nom\n", base);
        res = 1;
    }
    if (mot_dans_arbre(arbre_adjectif, base)){
        printf("La base %s est un adjectif\n", base);
        res = 1;
    }
    if (mot_dans_arbre(arbre_verbe, base)){
        printf("La base %s est un verbe\n", base);
        res = 1;
    }
    if(mot_dans_arbre(arbre_adverbe, base)){
        printf("La base %s est un adverbe\n", base);
        res = 1;
    }
    //Si le mot n'a été trouvé dans aucun des arbres
    if(res == 0){
        printf("Le mot n'est pas une base ou n'est pas dans le dictionnaire");
    }
}

