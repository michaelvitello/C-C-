#define TAILLE_MAX 256
#include "dico.h"
#include <stddef.h>
#include <stdio.h>

/* Cette file contient toutes les fonctions servant
a gerer un dictionnaire de mots pour le jeu du pendu */

// Choix d'un chiffre random, qui servira a choisir une ligne dans le dictionnaire (= un mot)

int motAleatoire(int nombreLignes)
{
    srand(time(NULL));
    return (rand() % nombreLignes);
}

// Fonction pour choisir un mot a un certain endroit dans le dictionnaire

int choixDuMot(char *motMagique)
{

    int compteRetourLigne = 0; int longueurMot = 0; int retourLigne = 0;

    FILE* dictionnaire = NULL;
    dictionnaire = fopen("dictionnaire.txt", "r");

    // 0. Test fichier

    if (dictionnaire == NULL)
    {
        printf("Impossible d'ouvrir le dictionnaire");
        exit(0);
    }

    // 1. Lecture du nombre de lignes dans fichier

    do
    {
        retourLigne = fgetc(dictionnaire);
        if (retourLigne == '\n')
            compteRetourLigne++;
    } while(retourLigne != EOF);

    // 1.1. CompteRetourLigne a une valeur, donc on peut select une ligne random

    int choixLigneRandom = motAleatoire(compteRetourLigne);

    // 2. Positionnement du curseur a la ligne choisie par le RAND

    rewind(dictionnaire);

    while (choixLigneRandom > 0)
    {
        retourLigne = fgetc(dictionnaire);
        if (retourLigne == '\n')
            choixLigneRandom--;
    }

    // 3. Lecture du mot a la bonne ligne

    if (dictionnaire != NULL)
    {
        fgets(motMagique, TAILLE_MAX, dictionnaire);
        longueurMot = strlen(motMagique);

            // Remplacer le saut de ligne lu par la fonction (\n) par un 0

                if( motMagique[longueurMot-1] == '\n' )
                motMagique[longueurMot-1] = 0;

        fclose(dictionnaire);
    }

    return 1;
}
