#ifndef DEF_HEADERS
#define DEF_HEADERS

#include "headers.h"
#include "dico.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#endif // DEF_HEADERS

int main()
{

    char* motMagique[100] = {0}; char lettreProposee = 0;
    int *lettreTrouvee = NULL; int tries = 10; int nombreDeLettres = 0; int i; int rejouerPartie = 1;

    // Regles du jeu

    printf("Bienvenue dans le jeu du pendu\n\n");
    printf("Les regles sont simples :\n\n");
    printf("- Vous avez 10 essais pour trouver le mot, lettre par lettre.\n");
    printf("- Chaque bonne lettre trouvee se revele et vous rapproche de la victoire...\n");
    printf("- Une erreur et c'est un pas de plus vers... la pendaison !\n\n");
    printf("A vous de jouer !!\n\n");

    // Si dictionnaire fonctionnel, choisir un mot et le mettre dans motMagique.

while (rejouerPartie = 1)
{

    if (!modeJoueurs(motMagique)) // Demande de mode de jeu, solo ou 2 joueurs
    {
        if (!choixDuMot(motMagique))
        exit(0);
    }

    nombreDeLettres = strlen(motMagique);
    lettreTrouvee = malloc(nombreDeLettres * sizeof(int));

    if (lettreTrouvee == NULL)
        exit(0);

    for (i = 0 ; i < nombreDeLettres ; i++)
        lettreTrouvee[i] = 0;

    // Une fois le motMagique defini, la partie se lance

    while (tries > 0 && !victoire(lettreTrouvee, nombreDeLettres))
    {
        printf("Il vous reste %d coups a jouer\n", tries);
        printf("Quel est le mot secret ? ");

        afficherMot(motMagique, lettreTrouvee, nombreDeLettres);

        printf("\nChoisissez une lettre : ");
        lettreProposee = lireCaractere();

        if (rechercheLettreUser(lettreProposee, motMagique, lettreTrouvee))
        {
            printf("\nBonne reponse !\n\n");
        }
        else
        {
            printf("\nMauvaise reponse ! Un coup en moins...\n\n");
            tries--;
        }
    }

    if (victoire(lettreTrouvee, nombreDeLettres))
        printf("Gagne ! Le mot secret etait bien : %s\n\n", motMagique);
    else
        printf("Perdu ! Le mot secret etait : %s\n\n", motMagique);

        printf("Voulez-vous rejouer ? 1. Oui 2. Non\n");
        scanf("%d", &rejouerPartie);

        if (rejouerPartie != 1)
        {
            printf("\nMerci bien l'ami, a une prochaine !\n");
            break;
        }
        else
        {
            printf("\nVous etes joueur ! On est reparti alors !\n\n");
            tries = 10; // Il faut reset les coups restants
        }
}
    return 0;
}
