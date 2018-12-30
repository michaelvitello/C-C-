/* Cette file contient tous les headers lies
aux fonctions du jeu du pendu */

// Fonction pour mode Solo / 2 joueurs
int modeJoueurs(char *motMagique);
// Fonction afficher mots ou etoiles
void afficherMot(char motMagique[], int lettreTrouvee[], int nombreDeLettres);
// Fonction recherche de lettre dans mot
int rechercheLettreUser(char lettreProposee, char motMagique[], int lettreTrouvee[]);
// Fonction de lecture de caractere
char lireCaractere();
// Fonction pour définir si gagnant ou non
int victoire(int lettreTrouvee[], int nombreDeLettres);
// Fonction de lecture sans scanf
int lire(char *chaine, int longueur);
// Fonction pour vider le buffer dans lire()
void viderBuffer();
