#include <stddef.h>
#include <stdio.h>

/* Cette file contient toutes les fonctions servant
a faire fonctionner le jeu du pendu */

// Fonction permettant de trigger un mode 1 ou 2 joueurs

int modeJoueurs(char *motMagique)
{
    int choixUser = 0; int longueurMot = 0; int modeChoisi = 0;
    int i;

    printf("Quel mode de jeu souhaitez-vous ?\n 1. Solo\n 2. 2 Joueurs\n");
    scanf("%d", &choixUser);

    if (choixUser == 1)
    {
        printf("\nMode Solo, c'est parti !\n\n");
        modeChoisi = 0;
    }
    else
    {
        printf("\nMode 2 joueurs : Un des deux joueurs choisit un mot secret : ");
        lire(motMagique, 100);
        longueurMot = strlen(motMagique);

            for (i = 0 ; i < longueurMot ; i++)
            {
                motMagique[i] = toupper(motMagique[i]);
            }

        modeChoisi = 1;
    }

    return modeChoisi;
}

// Fonction permettant d'afficher le mot, en etoile, ou en texte

void afficherMot(char motMagique[], int lettreTrouvee[], int nombreDeLettres)
{
   int i;

    for (i = 0 ; i < nombreDeLettres ; i++)
    {
        if (lettreTrouvee[i])
            printf("%c", motMagique[i]);
        else
            printf("*");
    }
}

// Fonction de recherche de la lettre dans mot

int rechercheLettreUser(char lettreProposee, char motMagique[], int lettreTrouvee[])
{

    int i;
    int rechercheLettre = 0;

    for (i = 0 ; motMagique[i] != '\0' ; i++)
    {
        if (lettreProposee == motMagique[i])
        {
            rechercheLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return rechercheLettre;
}

// Fonction de lecture et renvoie du caractere choisi par le user

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n') ;

    return caractere;
}

// Fonction servant a renvoyer si le user est gagnant ou pas

int victoire(int lettreTrouvee[], int nombreDeLettres)
{
    int i;
    int victoire = 1;

    for (i = 0 ; i < nombreDeLettres ; i++)
    {
        if (lettreTrouvee[i] == 0)
            victoire = 0;
    }

    return victoire;
}

// Fonction de lecture et gestion buffer, pour eviter le scanf

int lire(char *chaine, int longueur)
{

    char *positionEntree = NULL;

    if (fgets(chaine, sizeof(chaine), stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

// Fonction en lien avec lire() afin de pouvoir toujours vider le buffer

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

