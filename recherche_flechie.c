//
// Created by enzor on 13/11/2022.
//

#include "recherche_flechie.h"

//Cette fonction permet chercher dans un arbre dans quel noeud se situe le fléchi recherché
//Elle prend en paramètre un p_node et une chaine de caractère (notre fléchi)
//Elle retourne le noeud dans lequel est situé notre mot
p_node trouver_flechie(p_node pn, char mot[25])
{
    int i = 0, taille_mot = 0;
    if(pn->fin_mot != 0){
        p_cell_mot flechie = pn->si_fin_mot->flechies.head;
        //Calcule la taille du mot
        while(mot[i]!='\0')
        {
            taille_mot++;
            i++;
        }
        while (flechie != NULL)
        {
            i = 0;
            int cpt = 0;
            while (flechie->value[i] != '\0')
            {
                if (flechie->value[i] == mot[i])
                {
                    cpt++;
                }
                else
                {
                    cpt--;
                }
                i++;
            }

            if (cpt == taille_mot)
            {
                return pn;
            }
            else
            {
                flechie = flechie->next;
            }
        }
    }
    for(int j=0; j < pn->nb_enfants; j++)
    {
        p_node tmp = trouver_flechie(pn->enfants[j], mot);
        if (tmp != NULL){
            return tmp;
        }
    }
    return NULL;
}

//Cette fonction cherche dans la liste d'un noeud le fléchi recherché
//Elle prend en paramètre un arbre et une chaine de caractère (notre fléchi)
//Elle retourne un entier
int recherche_flechie(t_tree arbre, char mot[25]){
    p_node pn = trouver_flechie(arbre.root, mot);
    if (pn == NULL){
        return 0;
    }
    else {
        int i = 0, taille_mot = 0;
        p_cell_mot flechie = pn->si_fin_mot->flechies.head;
        int trouve = 0, pos = 0;
        //Calcule la taille du mot
        while (mot[i] != '\0') {
            taille_mot++;
            i++;
        }
        while ((flechie != NULL) && trouve != 1) {
            i = 0;
            int cpt = 0;
            while (flechie->value[i] != '\0') {
                if (flechie->value[i] == mot[i]) {
                    cpt++;
                } else {
                    cpt--;
                }
                i++;
            }

            if (cpt == taille_mot) {
                trouve = 1;
            } else {
                //printf("flechie suivant\n");
                flechie = flechie->next;
                pos++;
            }
        }
        p_cell_mot gram = pn->si_fin_mot->forme_grammatical.head;
        for (int j = 0; j < pos; j++) {
            gram = gram->next;
        }
        printf("Le mot %s vient du mot de base %s avec la forme grammaticale suivante : %s\n", flechie->value, pn->si_fin_mot->nom_mot, gram->value);
        return 1;
    }
}

//Cette fonction va utiliser nos fonctions précédentes afin de chercher le fléchi dans nos différents arbres
//Elle prend en paramètre des arbres (nom, adjectif, verbe, adverbe) et une chaine de caractère (le fléchie recherché)
//Elle ne retourne rien
void recherche_mot_dans_arbres(t_tree arbre_nom, t_tree arbre_adjectif, t_tree arbre_verbe, t_tree arbre_adverbe, char mot[25]){
    int res;
    res += recherche_flechie(arbre_nom,mot);
    res += recherche_flechie(arbre_adjectif,mot);
    res += recherche_flechie(arbre_verbe,mot);
    res += recherche_flechie(arbre_adverbe,mot);

    if (res ==0){
        printf("Le mot recherche n'est pas dans le dictionnaire\n");
    }
}