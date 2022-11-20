cmake_minimum_required(VERSION 3.21)
project(Generateur_de_phrases_auto C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Generateur_de_phrases_auto
        arbre.c
        arbre.h
        Creation_arbres.c
        Creation_arbres.h
        flechie.c
        flechie.h
        fonction.c
        fonction.h
        main.c
        node.c
        node.h
        recherche_base.c
        recherche_base.h
        recherche_flechie.c
        recherche_flechie.h
        t_std.c
        t_std.h)
